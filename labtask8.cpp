#include <iostream>
using namespace std;

string input;
int pos = 0;

bool X();

bool A() {
    if (pos < input.length() && input[pos] == 'a') {
        pos++;
        if (X()) {
            if (pos < input.length() && input[pos] == 'd') {
                pos++;
                return true;
            }
        }
    }
    return false;
}

bool X() {
    int startPos = pos;

    if (pos + 1 < input.length() && input[pos] == 'b' && input[pos + 1] == 'b') {
        pos += 2;
        if (X()) return true;
        pos = startPos;
    }

    if (pos + 1 < input.length() && input[pos] == 'b' && input[pos + 1] == 'c') {
        pos += 2;
        if (X()) return true;
        pos = startPos;
    }

    return true;
}

int main() {
    cout << "Enter a string: ";
    cin >> input;
    pos = 0;

    if (A() && pos == input.length()) {
        cout << "Accepted" << endl;
    } else {
        cout << "Rejected" << endl;
    }

    return 0;
}
