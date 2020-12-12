#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
#include <sstream>

using namespace std;

vector<string> SplitIntoWords(const string& s)
{
    vector<std::string> result;

    istringstream i_stream(s);
    string tmp;

    while (i_stream >> tmp)
    {
        result.push_back(tmp);
    }
    return result;
}

