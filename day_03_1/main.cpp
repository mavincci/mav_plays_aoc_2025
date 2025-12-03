#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int nx(const string& num_str, size_t i) {
    return (int)num_str[i] - (int)'0';
}

long xx(const string& num_str, size_t starti, size_t win_size) {
    const auto slen = num_str.length();

    if(win_size == 2) {
        long max{0l};
        for(auto i = starti; i < slen -1; ++i) {
            auto n1 = nx(num_str, i) * 10;
            for(auto j = i+1; j < slen; ++j) {
                auto n2 =  nx(num_str, j);
                auto x = n1 + n2;

                if(x > max) max = x;
            }
        }
        return max;
    }

    long max{};

    for(auto i = starti; i + win_size <= slen; ++i) {
        auto current_num = nx(num_str, i) * pow(10, win_size -1);
        auto res = xx(num_str, i + 1, win_size-1);

        auto new_num = current_num + res;
        if(new_num > max) max = new_num;
    }
    return max;
}
 
int main() {
    string input;
    auto sum{0l};

    while(cin >> input) {
        cout << input << "\n";
        sum +=  xx(input, 0, 12);
    }

    cout << sum;
}