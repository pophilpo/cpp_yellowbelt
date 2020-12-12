#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
    if (distance(range_begin, range_end) < 2)
    {
        return;
    }
    else
    {
        vector<typename RandomIt::value_type> elements(range_begin, range_end);

        auto itr_part_1 = elements.begin() + elements.size() / 2;

        MergeSort(elements.begin(), itr_part_1);
        MergeSort(itr_part_1, elements.end());

        merge(elements.begin(), itr_part_1, itr_part_1, elements.end(), range_begin);
    }
}
int main()
{
    vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1, 5};
    MergeSort(begin(v), end(v));
    for (int x : v) 
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
