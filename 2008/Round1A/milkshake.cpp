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
#include <utility>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cassert>

using namespace std;

enum prep {
  malted = 1,
  unmalted = 0
};

struct impossible: public runtime_error {
    impossible(): runtime_error("IMPOSSIBLE") {}
};

inline bool is_malted(pair<size_t, int> p) noexcept
{
  return p.second == malted;
}

inline bool satisfied(map<size_t,int> const& pref, vector<int> const& flavors) noexcept
{
  for (auto&& p : pref)
    if (flavors[p.first-1] == p.second)
      return true;
  return false;
}

vector<int> milkshakes(size_t num_flavors, vector<map<size_t,int>>& preferences)
{
  vector<int> flavors(num_flavors, unmalted);

  while (any_of(begin(preferences), end(preferences),
      [&](map<size_t,int>& pref) { return !satisfied(pref, flavors); }))
    for (map<size_t,int>& pref : preferences) {
      if (!satisfied(pref, flavors)) {
        auto pos = find_if(begin(pref), end(pref), is_malted);
        if (pos == end(pref))
          throw impossible();
        flavors[pos->first-1] = malted;
      }
    }

  return flavors;
}

int main()
{
  size_t C;
  cin >> C;
  for (size_t c = 0; c < C; ++c) {
    size_t N, M;
    cin >> N >> M;
    vector<map<size_t,int>> preferences(M);
    for (size_t m = 0; m < M; ++m) {
      size_t T;
      cin >> T;
      for (size_t t = 0; t < T; ++t) {
        pair<size_t,int> flavor;
        cin >> flavor.first >> flavor.second;
        preferences[m].insert(flavor);
      }
    }
    cout << "Case #" << c+1 << ": ";
    try {
      vector<int> flavors = milkshakes(N, preferences);
      copy(flavors.begin(), flavors.end(), ostream_iterator<int>(cout, " "));
    } catch (impossible& error) {
      cout << "IMPOSSIBLE";
    }
    cout << endl;
  }
}
