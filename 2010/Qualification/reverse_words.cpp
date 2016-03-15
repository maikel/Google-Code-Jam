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

#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
  if (argc < 2) {
    cerr << "Not enough arguments given. Usage: " << argv[0] << " <filename>\n";
    terminate();
  }

  // read the first line and save number of lines
  ifstream input(argv[1]);
  string line;
  getline(input, line);
  size_t test_cases = stoul(line);

  // read line and write it to output in reversed order
  size_t count_case = 0;
  while (getline(input, line) && count_case < test_cases) {
    istringstream wstream(line);
    vector<string> words;
    copy(istream_iterator<string>(wstream), istream_iterator<string>(), back_inserter(words));
    cout << "Case #" << ++count_case << ": ";
    copy(words.rbegin(), words.rend(), ostream_iterator<string>(cout, " "));
    cout << endl;
  }
}

