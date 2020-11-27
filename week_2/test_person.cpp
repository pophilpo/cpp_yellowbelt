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
		}
		catch (exception &e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		}
		catch (...) {
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


void TestIncognito()
{
    Person person_test;
    person_test.ChangeFirstName(1965, "test_first_name1");
    person_test.ChangeLastName(1967, "test_last_name1");
    assert_equal(person_test.GetFullName(1900), "Incognito", "test_1_incog");
}

void TestUnknownFirstName()
{
    Person person_test;
    person_test.ChangeLastName(1900, "test_last_name1");
    person_test.ChangeFirstName(1905, "test_first_name1");
    assert_equal(person_test.GetFullName(1903), "test_last_name1 with unknown first name", "test_1_unknown_fn");
}

void TestChangeFirstName()
{
    Person person_test;
    person_test.ChangeFirstName(1900, "test_first_name1");
    person_test.ChangeFirstName(1902, "test_first_name2");

    assert_equal(person_test.GetFullName(1899),"Incognito", "test_1");
    assert_equal(person_test.GetFullName(1900),"test_first_name1 with unknown last name", "test_1_first_name");
    assert_equal(person_test.GetFullName(1901),"test_first_name1 with unknown last name", "test_1_first_name");
    assert_equal(person_test.GetFullName(1902),"test_first_name2 with unknown last name", "test_1_first_name");
}
void TestUnknownLastName()
{
    Person person_test;
    person_test.ChangeFirstName(1900, "test_first_name1");
    person_test.ChangeLastName(1905, "test_last_name1");
    assert_equal(person_test.GetFullName(1903), "test_first_name1 with unknown last name", "test_1_unknown_fn");
}
void TestChangeLastName()
{
    Person person_test;
    person_test.ChangeLastName(1900, "test_last_name1");
    person_test.ChangeLastName(1902, "test_last_name2");

    assert_equal(person_test.GetFullName(1899), "Incognito", "test_1");
    assert_equal(person_test.GetFullName(1900), "test_last_name1 with unknown first name", "test_1_last_name");
    assert_equal(person_test.GetFullName(1901), "test_last_name1 with unknown first name", "test_2_last_name");
    assert_equal(person_test.GetFullName(1902), "test_last_name2 with unknown first name", "test_3_last_name");
}

void TestBothName()
{
    Person person_test;
    person_test.ChangeFirstName(1900, "test_first_name1");
    person_test.ChangeLastName(1902, "test_last_name1");

    assert_equal(person_test.GetFullName(1903), "test_first_name1 test_last_name1", "test_1_both");
}

void TestChangeBothName()
{
    Person person_test;
    person_test.ChangeFirstName(1900, "test_first_name1");
    person_test.ChangeLastName(1902, "test_last_name1");
    person_test.ChangeFirstName(1904, "test_first_name2");
    person_test.ChangeLastName(1905, "test_last_name2");

    assert_equal(person_test.GetFullName(1906), "test_first_name2 test_last_name2", "test_1_both");
}

void SaveFirstName()

{
    Person person_test;
    person_test.ChangeFirstName(1900, "test_first_name1");
    person_test.ChangeLastName(1902, "test_last_name1");
    person_test.ChangeFirstName(1905, "test_first_name2");

    assert_equal(person_test.GetFullName(1903), "test_first_name1 test_last_name1", "test_1_save");
}

void SaveLastName()
{
    Person person_test;
    person_test.ChangeLastName(1900, "test_last_name1");
    person_test.ChangeFirstName(1902, "test_first_name1");
    person_test.ChangeLastName(1905, "test_last_name2");

    assert_equal(person_test.GetFullName(1903), "test_first_name1 test_last_name1", "test_1_save");
}

int main() {
    int main() 
{
    test_runner runner;
    runner.run_test(TestIncognito, "test_incognito");
    runner.run_test(TestUnknownFirstName, "test_unknown_first_name");
    runner.run_test(TestChangeFirstName, "test_change_first_name");
    runner.run_test(TestUnknownLastName, "test_unknown_last_name");
    runner.run_test(TestChangeLastName, "test_change_last_name");
    runner.run_test(TestBothName, "test_both_name");
    runner.run_test(TestChangeBothName, "test_change_both_name");
    runner.run_test(SaveFirstName, "save_first_name");
    runner.run_test(SaveLastName, "save_last_name");
}



