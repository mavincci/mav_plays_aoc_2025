#include <iostream>
#include <vector>

using namespace std;

int main() {
    string input;
    vector<string> lines;

    while(cin >> input) {
        lines.push_back(input);
    }

    auto si = lines[0].find('S');

    lines[1][si] = '|';

    auto total{0};

    for(auto i{2}; i < lines.size(); ++i) {
        const auto& lprev = lines[i-1];
        auto& lcurr = lines[i];

        for(auto pos{0}; pos < lprev.size(); ++pos) {
            if(lprev[pos] == '|') {
                if(lcurr[pos] == '.') {
                    lcurr[pos] = '|';
                }
                else if(lcurr[pos] == '^') {
                    lcurr[pos-1] = '|';
                    lcurr[pos+1] = '|';
                    total++;
                }
            }
        }
    }

    cout << "-------------------------" << endl;

    for(const auto& l: lines)
        cout << l << endl;

    cout << "Total: " << total << endl;
}