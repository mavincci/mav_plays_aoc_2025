#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

vector<long> process_nums(const vector<string>& lines, size_t starti, size_t endi) {
    const auto numlines = lines.size();

    vector<long> params;

    auto temp{0l};
    auto pown = 0;

    for(auto i = starti; i <= endi; ++i) {
        pown = 0;
        temp = 0l;
        for(auto it = lines.rbegin(); it != lines.rend(); ++it) {
            const auto l = *it;
            const auto ch = l[i];

            if(ch == (char)32) 
                continue;

            const auto n = (long)ch - (long)'0';
            temp += n * pow(10, pown++);
        }
        params.push_back(temp);
    }

    return params;
}

long sum(const vector<vector<long>>& params, size_t i) {
    auto temp{0l};

    for(const auto& v: params[i])
        temp += v;

    return temp;
}

long product(const vector<vector<long>>& params, size_t i) {
    auto temp{1l};

    for(const auto& v: params[i])
        temp *= v;

    return temp;
}


long process_all(const vector<vector<long>>& params, vector<char> ops) {
    const auto items = ops.size();
    auto total{0l};

    for(auto i{0l}; i < items; ++i)
        total += (ops[i] == '+') ? sum(params, i) : product(params, i);
    
    return total;    
}

int main() {
    string input;

    vector<string> lines;
    string ops;

    while(getline(cin, input, '\n')) {
        if(input[0] == '*' || input[0] == '+') {
            ops = input;
            continue;
        }

        lines.push_back(input);
    }

    vector<vector<long>> params;
    vector<char> opss;

    size_t starti{0};
    size_t endi{0};

    for(auto i{2}; i < ops.size(); ++i) {
        if(ops[i] == '+' || ops[i] == '*') {
            endi = i - 2;
            params.push_back(process_nums(lines, starti, endi));
            starti = i;
            continue;
        }

        if(i == ops.size() - 1)
            params.push_back(process_nums(lines, starti, i));
    }

    string temp;
    for(istringstream ss{ops}; ss >> temp;) {
        opss.push_back(temp[0]);
    }

    cout << "total: " << process_all(params, opss) << endl;
}