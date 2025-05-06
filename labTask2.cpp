#include <iostream>
#include <string>
using namespace std;

bool isAStar(const string& s) {
    for (char c : s) {
        if (c != 'a') return false;
    }
    return true;
}

bool isAStarBPlus(const string& s) {
    int i = 0;
    int n = s.length();

    while (i < n && s[i] == 'a') {
        i++;
    }

    int bCount = 0;
    while (i < n && s[i] == 'b') {
        i++;
        bCount++;
    }

    return (i == n && bCount > 0);
}

bool isABB(const string& s) {
    return s == "abb";
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isABB(input)) {
        cout << "The string matches 'abb'" << endl;
    } else if (isAStar(input)) {
        cout << "The string matches 'a*'" << endl;
    } else if (isAStarBPlus(input)) {
        cout << "The string matches 'a*b+'" << endl;
    } else {
        cout << "The string does not match any of the patterns." << endl;
    }

    return 0;
}
