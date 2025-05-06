#include <iostream>
#include <string>
using namespace std;

bool endsWithAB(const string& input) {
    int len = input.length();
    if (len < 2) return false;
    return input[len - 2] == 'a' && input[len - 1] == 'b';
}


bool hasEvenNumberOfAs(const string& input) {
    int count = 0;
    for (char ch : input) {
        if (ch == 'a') count++;
    }
    return count % 2 == 0;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    bool condition1 = endsWithAB(input);
    bool condition2 = hasEvenNumberOfAs(input);

    if (condition1 && condition2) {
        cout << "The string ends with 'ab' AND has an even number of 'a's." << endl;
    } else {
        cout << "The string does not meet the required conditions." << endl;
        if (!condition1) cout << "It does not end with 'ab'" << endl;
        if (!condition2) cout << "It does not have an even number of 'a's" << endl;
    }

    return 0;
}
