#include <iostream>

using namespace std;

pair<long, long> parseRangePair(string& rangeStr) {
    auto delimLoc =  rangeStr.find('-');
    return make_pair(
        stol(rangeStr.substr(0, delimLoc)),
        stol(rangeStr.substr(1 + delimLoc))
    );
}

bool checkChunck(const string& str, int chunkSize) {
    auto slen = str.length();

    if(slen % chunkSize != 0)
        return false;

    const auto reference = str.substr(0, chunkSize);

    for(auto i = 0; i + chunkSize <= slen ; i += chunkSize)
        if(reference != str.substr(i, chunkSize))
            return false;

    return true;
}


bool isInvalid(long num) {
    auto istr = to_string(num);
    auto halfl = istr.length() / 2;

    for(auto i = 1; i <= halfl; ++i)
        if(checkChunck(to_string(num), i))
            return true;

    return false;
}

long findNAddInvalids(long start, long end) {
    long sum{};

    for(auto i = start; i <= end; ++i)
        if(isInvalid(i))
            sum += i;

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