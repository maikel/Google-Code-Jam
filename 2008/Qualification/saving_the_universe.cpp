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

#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <class Iter, class T>
size_t series(Iter begin, Iter end, T const& x) noexcept
{
  return distance(begin, find(begin, end, x));
}

size_t count_switches(vector<string> const& engines, vector<string> const& queries)
{
  if (queries.size() == 0)
    return 0;
  size_t switches = 0;
  for (size_t i = 0; i < queries.size();) {
    size_t max_series = 0;
    for (string engine: engines)
      max_series = max(max_series, series(begin(queries)+i, end(queries), engine));
    i += max_series;
    ++switches;
  }
  return switches-1;
}

int main()
{
  size_t cases;
  cin >> cases;

  for (size_t c = 1; c <= cases; ++c) {

    size_t num_engines;
    cin >> num_engines; while (cin.get() != '\n'); // clear line
    vector<string> engines(num_engines);
    for (size_t i = 0; i < num_engines; ++i) {
      string engine;
      getline(cin, engine);
      engines[i] = engine;
    }

    size_t num_queries;
    cin >> num_queries; while (cin.get() != '\n'); // clear line
    vector<string> queries(num_queries);
    for (size_t i = 0; i < num_queries; ++i) {
      string query;
      getline(cin, query);
      queries[i] = query;
    }

    cout << "Case #" << c << ": " << count_switches(engines, queries) << endl;
  }
}


