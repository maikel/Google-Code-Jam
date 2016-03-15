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


#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <fstream>

using namespace std;

size_t find_mapped_num(char c, vector<string> t9_map)
{
  return distance(t9_map.begin(), find_if(t9_map.begin(), t9_map.end(),
      [c](string const& s){
          return s.find(c) != string::npos;
      }));
}

int main(int argc, char** argv)
{
  if (argc < 2) {
    cerr << "Usage: " << argv[0] << " <input>\n";
    terminate();
  }
  ifstream input(argv[1]);
  string line;
  getline(input, line);
  size_t test_cases = stoul(line);

  vector<string> t9_map {
    " ", ""    , "abc", "def",
         "ghi" , "jkl", "mno",
         "pqrs", "tuv", "wxyz"
  };

  size_t counter = 0;
  while (counter < test_cases && getline(input, line)) {
    size_t last_num = 0;
    cout << "Case #" << ++counter << ": ";
    for (char c : line) {
      assert(c == ' ' || islower(c));
      size_t mapped_num = find_mapped_num(c, t9_map);
      size_t multiplicity = t9_map[mapped_num].find(c) + 1;
      if (last_num == mapped_num)
        cout << " ";
      while (multiplicity-- > 0)
        cout << mapped_num;
      last_num = mapped_num;
    }
    cout << "\n";
  }

  return 0;
}

