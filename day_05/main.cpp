#include <iostream>
#include <vector>

using namespace std;

using range_t = pair<long, long>;

range_t parseRangePair(string& rangeStr) {
    auto delimLoc =  rangeStr.find('-');
    return make_pair(
        stol(rangeStr.substr(0, delimLoc)),
        stol(rangeStr.substr(1 + delimLoc))
    );
}

void add_range(vector<range_t>& ranges, range_t range) {
    ranges.push_back(range);
}

int main() {
    string input;
    vector<range_t> ranges;

    while(getline(cin, input)) {
        if(input.empty())
            break;
        
        auto p = parseRangePair(input);
        add_range(ranges, p);
    }

    cout << "Total ranges " << ranges.size() << endl;
    auto count {0l};

    while(getline(cin, input)) {
        auto num = stol(input);

        for(const auto& range : ranges) {
            if(num >= range.first && num <= range.second) {
                count++;
                break;
            }
        }
    }

    cout << "Spoiled count " << count << endl;
}