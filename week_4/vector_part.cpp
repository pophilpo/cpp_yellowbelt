#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void PrintVectorPart(const vector<int>& numbers){

	auto first_negative = find_if(numbers.begin(), numbers.end(), [](const int& value){
		if (value < 0)
			return true;
		return false;
	});


	auto it = first_negative;
	while (it != numbers.begin()){
		--it;
		cout << *it << " ";
	}

}

int main() {

	PrintVectorPart({6, 1, 8, -5, 4});
	cout << endl;
	PrintVectorPart({-6, 1, 8, -5, 4});
	cout << endl;
	PrintVectorPart({6, 1, 8, 5, 4});

}
