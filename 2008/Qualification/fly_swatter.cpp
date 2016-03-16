/*
 * Copyright 2016 Maikel Nadolski
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
#include <tuple>
#include <cassert>

using namespace std;

struct Point {
  float x;
  float y;
};

struct Fly {
  Point coordinate;
  float radius;
};

struct Ring {
  float radius;
  float thickness;
};

struct Grid {
  vector<float> x;
  vector<float> y;
  float thickness;
};

float distance(Point p, Point q)
{
  return sqrt((p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y));
}

pair<Point, Point> find_cell(Fly fly, Grid const& grid) noexcept
{
  using iterator = vector<float>::const_iterator;
  iterator upper_x = upper_bound(begin(grid.x), end(grid.x), fly.coordinate.x); // log(N)
  iterator upper_y = upper_bound(begin(grid.y), end(grid.y), fly.coordinate.y); // log(N)
  assert(upper_x != end(grid.x) && upper_x != begin(grid.x));
  assert(upper_y != end(grid.y) && upper_y != begin(grid.y));
  Point upper = { *upper_x--, *upper_y-- };
  Point lower = { *upper_x  , *upper_y   };
  return { lower, upper };
}

/** Check if the fly gets hit by the ring. */
inline bool is_in_inner_ring(Fly fly, Ring ring) noexcept
{
  return distance(fly.coordinate,{0,0})+fly.radius < ring.radius-ring.thickness;
}

inline bool is_in_outer_ring(Fly fly, Ring ring) noexcept
{
  return distance(fly.coordinate,{0,0}) < ring.radius;
}

bool intersects_grid(Fly fly, Grid const& grid) noexcept
{
  Point lower, upper;
  tie(lower, upper) = find_cell(fly, grid);
  if (   fly.coordinate.x + fly.radius < upper.x - grid.thickness
      && fly.coordinate.y + fly.radius < upper.y - grid.thickness
      && fly.coordinate.x - fly.radius > lower.x + grid.thickness
      && fly.coordinate.y - fly.radius > lower.y + grid.thickness)
    return false;
  else
    return true;
}

float relative_count_hits(Grid const& string_grid, Ring ring, float h, float f)
{
  size_t count_hit {};
  size_t in_outer_ring {};
  for (float x = string_grid.x.front(); x < string_grid.x.back(); x += h)
    for (float y = string_grid.y.front(); y < string_grid.y.back(); y += h) {
      Fly fly { {x,y}, f };
      if (is_in_inner_ring(fly, ring) && intersects_grid(fly, string_grid))
        ++count_hit;
      if (is_in_outer_ring(fly, ring))
        ++in_outer_ring;
    }
  return static_cast<float>(count_hit) / in_outer_ring;
}

Grid make_string_grid(float R, float r, float g)
{
  float width = 2*r + g;  // string grid width
  size_t num_strings = static_cast<size_t>(R/width); // grid size in one dir
  vector<float> grid_x( 2*num_strings+3 );
  iota(begin(grid_x), end(grid_x), -static_cast<float>(num_strings+1));
  transform(begin(grid_x), end(grid_x), begin(grid_x), bind1st(multiplies<float>(), width));
  return { grid_x, grid_x, r };
}

int main()
{
  const float relative_area_width = 0.001;
  size_t number_cases {};
  cin >> number_cases;
  cin.ignore(numeric_limits<size_t>::max(), '\n');

  while (number_cases--) {
    float f, R, t, r, g;
    cin >> f >> R >> t >> r >> g;
    Grid string_grid = make_string_grid(R, r, g);
    Ring ring { R, t };

    float area_width = relative_area_width*(string_grid.x.back() - string_grid.x.front()); // scale width
    cout << relative_count_hits(string_grid, ring, area_width, f) << endl;
  }
}

