#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct range_t {
    long start;
    long end;
};

range_t parseRangePair(string& rangeStr) {
    auto delimLoc =  rangeStr.find('-');
    return {
        stol(rangeStr.substr(0, delimLoc)),
        stol(rangeStr.substr(1 + delimLoc))
    };
}

vector<range_t> merge_ranges(const  range_t& p1, const range_t& p2) {
    vector<range_t> result;
    if(p1.end < p2.start) {
        result.push_back(p1);
        result.push_back(p2);
    } else {
        result.push_back({p1.start, max(p1.end, p2.end)});
    }
    return result;
}

int main() {
    string input;
    vector<range_t> ranges;
    

    while(getline(cin, input)) {
        auto p = parseRangePair(input);
        ranges.push_back(p);   
    }

    std::sort(ranges.begin(), ranges.end(),
          [](const range_t& a, const range_t& b) {
              return (a.start < b.start) ||
                     (a.start == b.start && a.end < b.end);
          });

    cout << "Sorted ranges " << ranges.size() << endl;
    vector<range_t> merged{ranges[0]};
    auto point{0l};

    for(auto i = 1; i < ranges.size(); ++i) {
        auto temp = merge_ranges(merged[point], ranges[i]);

        if(temp.size() == 1) {
            merged[point] = temp[0];
        } else {
            merged.push_back(temp[1]);
            ++point;
        }
    }

    cout << "Merged raanges " << merged.size() << endl;

    auto dce{0l};
    for(const auto& r : merged) {
        dce += (r.end - r.start + 1);
    }

    cout << "Difference count " << dce << endl;
}