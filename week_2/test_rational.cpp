#include <iostream>
#include <map>
#include <ostream>
#include <random>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream &operator<<(ostream &os, const vector<T> &s) {
  os << "{";
  bool first = true;
  for (const auto &x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream &operator<<(ostream &os, const set<T> &s) {
  os << "{";
  bool first = true;
  for (const auto &x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream &operator<<(ostream &os, const map<K, V> &m) {
  os << "{";
  bool first = true;
  for (const auto &kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template <class T, class U>
void AssertEqual(const T &t, const U &u, const string &hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string &hint) { AssertEqual(b, true, hint); }

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string &test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception &e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};



void TestConstructor() {

    Rational default_rational;
    AssertEqual(default_rational.Numerator(), 0, "Wrong default numerator");
    AssertEqual(default_rational.Denominator(), 1, "Wrong default denumerator");

    Rational rational(1, 2);

    AssertEqual(rational.Numerator(), 1, "Wrong set numenator");
    AssertEqual(rational.Denominator(), 2, "Wrong set denumenator");

    Rational reduced_rational(5, 10);
    
    AssertEqual(reduced_rational.Numerator(), 1, "Wrong numenator reduction");
    AssertEqual(reduced_rational.Denominator(), 2, "Wrong denominator reduction");

    Rational negative_rational_numenator(-1, 2);
 
    AssertEqual(negative_rational_numenator.Numerator(), -1, "Wrong negative numenator");
    AssertEqual(negative_rational_numenator.Denominator(), 2, "Wrong negative denominator");

    Rational negative_rational_denominator(1, -2);
 
    AssertEqual(negative_rational_denominator.Numerator(), -1, "Wrong negative numenator");
    AssertEqual(negative_rational_denominator.Denominator(), 2, "Wrong negative denominator");

    Rational positive_rational(-1, -2);

    AssertEqual(positive_rational.Numerator(), 1, "Wrong double negative numenator");
    AssertEqual(positive_rational.Denominator(), 2, "Wrong double negative denominator");

    Rational zero_numenator(0, 25);

    AssertEqual(zero_numenator.Numerator(), 0, "Wrong zero numenator");
    AssertEqual(zero_numenator.Denominator(), 1, "Wrong zero numenator");


}


int main(){ 

    TestRunner runner;
    runner.RunTest(TestConstructor, "Test Constructor");
    return 0;

}
