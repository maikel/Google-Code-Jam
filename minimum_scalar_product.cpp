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
#include <iterator>

using namespace std;

long long minimum_scalar_product(vector<int>& v, vector<int>& w)
{
  assert(v.size() == w.size());
  sort(v.begin(), v.end());
  sort(w.begin(), w.end(), greater<int>());
  long long total = 0;
  for (size_t i = 0; i < v.size(); ++i)
    total += static_cast<long long>(v[i])*w[i];
  return total;
}

int main(int argc, char** argv)
{
  size_t N;
  cin >> N;
  for (size_t testcase = 1; testcase <= N; ++testcase) {
    size_t vector_length;
    cin >> vector_length;
    vector<int> v(vector_length), w(vector_length);
    copy_n(istream_iterator<int>(cin), vector_length, v.begin());
    copy_n(istream_iterator<int>(cin), vector_length, w.begin());
    cout << "Case #" << testcase << ": " << minimum_scalar_product(v, w) << endl;
  }
  return 0;
}
