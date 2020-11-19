#include "iostream"
#include "vector"
#include <vector>
using namespace std;

int main() {

  size_t size;
  cin >> size;

  int sum = 0;

  vector<int> records(size);

  for (int &record : records) {
    cin >> record;
    sum = sum + record;
  }

  int avg = sum / static_cast<int>(size);

  vector<int> result;

  for (size_t i = 0; i < size; i++) {

    if (records[i] > avg) {
      result.push_back(i);
    }
  }

  cout << result.size() << endl;

  for (int &record : result) {
    cout << record << " ";
  }

  return 0;
}
