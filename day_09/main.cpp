#include <iostream>
#include <vector>
#include <compare>
#include <algorithm>

using namespace std;

using point_t = pair<long, long>;

struct rect {
    point_t a;
    point_t b;
    long area;
    
    constexpr std::strong_ordering operator<=>(const rect& other) const noexcept {
        return area <=> other.area;
    }

    constexpr bool operator==(const rect& other) const noexcept {
        return area == other.area;
    }
};

long find_area(const point_t& a, const point_t& b) {
    return (abs(b.first - a.first) + 1) * (abs(b.second - a.second) + 1);
}

int main() {
    string input;

    vector<point_t> points;

    vector<rect> rects;

    while(cin >> input) {
        long x{}, y{};

        sscanf(input.c_str(), "%ld,%ld", &x, &y);

        auto temp_p = make_pair(x, y);

        if(points.size() > 1) {
            for(auto i{0l}; i < points.size()-1; ++i) {
                auto prev_p = points[i];

                rects.push_back({prev_p, temp_p, find_area(prev_p, temp_p)});
            }
        }
        points.push_back(temp_p);
    }

    sort(rects.begin(), rects.end(), [](const rect& a, const rect& b){ return b.area < a.area; });

    // for(const auto& r: rects) {
        // cout << r.area << endl;
    // }

    cout << rects[0].area << endl;
}