#include "iostream"
#include "map"
#include <stdexcept>

using namespace std;

template <typename Key, typename Value>
Value &GetRefStrict(map<Key, Value> &mymap, Key key) {

  if (mymap.count(key) == 0) {
    throw runtime_error("Not Found");
  }

  return mymap.at(key);
}
int main() {
  map<int, string> m = {{0, "value"}};
  string &item = GetRefStrict(m, 0);
  item = "newvalue";
  cout << m[0] << endl; // выведет newvalue

  return 0;
}