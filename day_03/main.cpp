#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> prepare_comination(const string& num_str) {
    const auto slen = num_str.length();
    vector<int> temp;

    for(auto i = 0; i < slen -1; ++i) {
        auto n1 = (int)num_str[i] - (int)'0';
        for(auto j = i+1; j < slen; ++j) {
            auto n2 = (int)num_str[j] - (int)'0';
            auto x = (n1 * 10) + n2;
            temp.push_back(x);
        }
    }

    sort(temp.begin(), temp.end());

    return temp;
}

int main() {
    string input;
    auto sum{0l};

    while(cin >> input) {
        auto res_list = prepare_comination(input);
        sum += res_list[res_list.size() - 1];
    }

    cout << sum;
}