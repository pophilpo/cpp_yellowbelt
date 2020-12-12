#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

int main()
{
    size_t size;
    cin >> size;
    vector<int> permutation(size);

    iota(permutation.begin(), permutation.end(), 1);
    reverse(permutation.begin(), permutation.end());

    do 
    {
        copy(permutation.begin(), permutation.end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    } 
    while (prev_permutation(permutation.begin(), permutation.end()));
    return 0;
}
