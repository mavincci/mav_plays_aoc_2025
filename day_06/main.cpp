#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

long sum(const vector<vector<long>>& params, size_t i) {
    auto temp{0l};

    for(const auto& v: params)
        temp += v[i];

    return temp;
}

long product(const vector<vector<long>>& params, size_t i) {
    auto temp{1l};

    for(const auto& v: params)
        temp *= v[i];

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

    vector<vector<long>> num_list;
    size_t idx{};

    vector<char> ops;

    while(getline(cin, input, '\n')) {
        istringstream ss {input};

        if(input[0] == '+' || input[0] == '*') {
            string temp;
            for(istringstream ss{input}; ss >> temp;) {
                ops.push_back(temp[0]);
            }
            ++idx;
            continue;
        }

        num_list.push_back({});
        long num;
        for(istringstream ss{input}; ss >> num;) {
            num_list[idx].push_back(num);
        }

        ++idx;
    }

    cout << "total: " << process_all(num_list, ops) << endl;
}