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

        auto itr_part_1 = elements.begin() + elements.size() / 3;
        auto itr_part_2 = itr_part_1 + elements.size() / 3;

        MergeSort(elements.begin(), itr_part_1);
        MergeSort(itr_part_1, itr_part_2);
        MergeSort(itr_part_2, elements.end());

        vector<typename RandomIt::value_type> temp;

        merge(elements.begin(), itr_part_1, itr_part_1, itr_part_2, back_inserter(temp));
        merge(temp.begin(), temp.end(), itr_part_2, elements.end(), range_begin);
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
