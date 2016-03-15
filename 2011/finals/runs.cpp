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
#include <vector>
#include <iostream>
#include <iterator>
#include <cassert>

using namespace std;

vector<string> tokenize_runs(string const& str)
{
  vector<string> runs;
  for (size_t i = 0; i < str.size();) {
    size_t s = str.find_first_not_of(str[i],i);
    runs.push_back(str.substr(i, s-i));
    i = s;
  }
  return runs;
}

size_t count_runs(string const& str)
{
  size_t total = 0;
  for (size_t i = 0; i < str.size(); i = str.find_first_not_of(str[i],i))
    ++total;
  return total;
}

template <class T>
struct by_size {
    inline bool operator()(T const& x, T const& y) noexcept { return x.size() > y.size(); }
};

namespace std {
  template<>
  struct is_empty<string> {
      size_t operator()(string const& s) { return s.size() == 0; }
  };
}

size_t count_permutations(size_t goal, vector<string>& buckets, char last = 0)
{
  size_t empty_buckets = count_if(begin(buckets), end(buckets), is_empty<string>());
  size_t nonempty_buckets = buckets.size()-empty_buckets;
  if (goal < nonempty_buckets)
    return 0;
  if (goal == 0 && nonempty_buckets == 0) {
    return 1;
  }
  assert(goal >= nonempty_buckets && goal > 0);

  size_t total = 0;
  for (size_t i = 0; i < buckets.size(); ++i) {
    // count for each buckets permutations dynamically
    for (size_t j = 1; j <= buckets[i].size() && last != buckets[i][0]; ++j) {
      char tmp = buckets[i][0];
      buckets[i].erase(0,j); // erase character j times from bucket
      total += count_permutations(goal-1, buckets, tmp);
      buckets[i] += string(j, tmp); // repeat character j times and add back to bucket
    }
  }
  return total;
}

int main()
{
  size_t T;
  cin >> T;

  for (size_t test = 1; test <= T; ++test) {
    string str;
    cin >> str;
    size_t goal = count_runs(str);
    sort(begin(str), end(str));
    cout << str << endl;
    vector<string> runs = tokenize_runs(str);
    cout << "Case #" << test << ": " << count_permutations(goal, runs) << endl;
  }
}

