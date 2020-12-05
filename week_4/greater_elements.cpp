#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {

	auto greater = find_if(elements.begin(), elements.end(), [border](const T& value){
		return value > border;
	});

	vector<T> result;

	for (auto i = greater; i != elements.end(); ++i){

		result.push_back(*i);
	}

	return result;


}
