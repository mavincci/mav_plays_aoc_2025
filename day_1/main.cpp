#include <iostream>

using namespace std;
int main() {
    int dial = 50, count = 0;

    string input;

    while(cin >> input) {
        const int change = stoi(input.substr(1)) % 100;
        switch(input[0]) {
            case 'R':
                dial = (dial + change) % 100;
                break;
            case 'L':
                dial = (100 + dial - change) % 100;
                break;
        }

        if(dial == 0) ++count;
    }

    cout << count << endl;
}