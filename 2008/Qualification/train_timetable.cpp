#include <iostream> // cin, cout
#include <set>      // multiset

using namespace std;

struct Time {
    int hours;
    int minutes;
};

bool operator<(Time const& t, Time const& s) noexcept
{
  return (t.hours < s.hours) || (t.hours == s.hours && t.minutes < s.minutes);
}

istream& operator>>(istream& in, Time& t)
{
  in >> t.hours;
  in.ignore(1, ':');
  in >> t.minutes;
  return in;
}

Time operator+(Time const& t, Time const& s) noexcept
{
  int hours = t.hours + s.hours;
  int minutes = t.minutes + s.minutes;
  if (59 < minutes)
    hours += 1;
  return {hours /* %24 */, minutes%60};
  // if hours exceeds 24 its the next day
  // dont use modulo to mirror that
}

/** Look for a time entry in `arrivals` before given time `t`.
 * If no such entry was found return end(arrivals).*/
multiset<Time>::iterator find_available_train(Time const& t, multiset<Time> const& arrivals)
{
  if (arrivals.empty() || t < *begin(arrivals))
    return end(arrivals);
  return begin(arrivals);
}

/** Count how many trains needs to start to satisfy all departures.
 * 
 * Check for every departure if there is a train in `arrivals` which
 * we can use to do the route. Remove the entry from arrivals on autosuccess
 * to indicate this entry is not available for further departures.*/
int satisfy_time_table(multiset<Time> const& departures, multiset<Time> arrivals)
{
  using iterator = multiset<Time>::iterator;
  int start_trains = 0;
  for (Time departure : departures) {
    iterator available_train = find_available_train(departure, arrivals);
    if (available_train == end(arrivals))
      ++start_trains;
    else
      arrivals.erase(available_train);
  }
  return start_trains;
}

int main()
{
  size_t N;
  cin >> N; // number test cases

  for (size_t n = 0; n < N; ++n) {
    int T;
    cin >> T; // turnaround time in minutes
    Time turnaround { T / 60, T % 60 };
    int NA, NB;
    cin >> NA >> NB;
    multiset<Time> departures_A, arrivals_B;
    Time t;
    for (int a = 0; a < NA; ++a) {
      cin >> t;
      departures_A.insert(t);
      cin >> t;
      arrivals_B.insert(t + turnaround);
    }
    multiset<Time> departures_B, arrivals_A;
    for (int b = 0; b < NB; ++b) {
      cin >> t;
      departures_B.insert(t);
      cin >> t;
      arrivals_A.insert(t + turnaround);
    }
    int start_A = satisfy_time_table(departures_A, arrivals_A);
    int start_B = satisfy_time_table(departures_B, arrivals_B);
    cout << "Case #" << n + 1 << ": " << start_A << " " << start_B << endl;
  }
}
