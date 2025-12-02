#include <iostream>

using namespace std;

pair<long, long> parseRangePair(string& rangeStr) {
    auto delimLoc =  rangeStr.find('-');
    return make_pair(
        stol(rangeStr.substr(0, delimLoc)),
        stol(rangeStr.substr(1 + delimLoc))
    );
}

long findNAddInvalids(long start, long end) {
     long sum{};

     for(auto i = start; i <= end; ++i) {
        auto istr = to_string(i);
        auto ilen = istr.length();

        if(ilen & 1 == 1) continue;

        auto halfl = ilen / 2;

        if(istr.substr(0, halfl) != istr.substr(halfl)) continue;

        sum += i;
     }

     return sum;
}

int main() {
    string input;

    long total{};

    while(getline(cin, input, ',')) {
        auto tempP = parseRangePair(input);
        total += findNAddInvalids(tempP.first, tempP.second);
    }

    cout << total;
}