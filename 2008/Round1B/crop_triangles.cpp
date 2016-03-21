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
#include <array>
#include <vector>
#include <iostream>
#include <iterator>
#include <cassert>

using namespace std;

struct Point {
  size_t x;
  size_t y;
};

size_t operator%(Point const& p, size_t M)
{
  return (p.x%M)*M + (p.y%M);
}

vector<Point> generate_trees(size_t n, size_t A, size_t B, size_t C, size_t D, size_t x0, size_t y0, size_t M) {
  vector<Point> trees(n);
  trees[0] = {x0, y0};
  for (size_t i = 1; i < n; ++i) {
    trees[i].x = (A*trees[i-1].x + B) % M;
    trees[i].y = (C*trees[i-1].y + D) % M;
  }
  return trees;
}

array<size_t, 9> counts_by_mod_3(vector<Point> const& trees) {
  array<size_t, 9> counts {};
  for (Point const& tree : trees)
    ++counts[tree%3];
  return counts;
}

size_t index_to_zero(size_t i, size_t j)
{
  size_t xi = i/3 ,xj = j/3;
  size_t yi = i%3 ,yj = j%3;
  size_t xz = (3-(xi+xj)%3)%3;
  size_t yz = (3-(yi+yj)%3)%3;
  return xz*3 + yz;
}

size_t count_triangles(array<size_t,9> counts)
{
  size_t triangles = 0;
  for (size_t i=0; i < 9; ++i)
    for (size_t j=i; j < 9; ++j) {
      size_t k = index_to_zero(i,j);
      size_t count = 0;
      if (j <= k) {
        count = counts[i];

        if (i == j)
          count = (counts[i]*(counts[i]-1))/2;
        else
          count *= counts[j];

        if (j == k && i == j)
          count = counts[i]*(counts[i]-1)*(counts[i]-2)/6;
        else if (j == k)
          count = counts[i]*(counts[j]*(counts[j]-1))/2;
        else
          count *= counts[k];

        triangles += count;
      }
    }
  return triangles;
}

int main()
{
  size_t tests;
  cin >> tests;
  for (size_t test=1; test <= tests; ++test) {
    size_t n, A, B, C, D, x0, y0, M;
    cin >> n >> A >> B >> C >> D >> x0 >> y0 >> M;

    vector<Point> trees = generate_trees(n, A, B, C, D, x0, y0, M);
    array<size_t,9> counts = counts_by_mod_3(trees);
    cout << "Case #" << test << ": " << count_triangles(counts) << "\n";
  }
}
