#include <iostream>
#include <string>
using namespace std;
bool A(string& str, int& index) {
    if (index < str.length() && str[index] == 'a') {
        index++;
        return A(str, index);
    }
    return true;
}
bool B(string& str, int& index) {
    if (index < str.length() && str[index] == 'b') {
        index++;
        return B(str, index);
    }
    return true;
}
bool C(string& str, int& index) {
    if (index < str.length() && str[index] == 'c') {
        index++;
        return C(str, index);
    }
    return true;
}

bool D(string& str, int& index) {
    if (index < str.length() && str[index] == 'd') {
        index++;
        return D(str, index);
    }
    return true;
}
bool S(string& str) {
    int index = 0;
    return A(str, index) && B(str, index) && C(str, index) && D(str, index) && index == str.length();
}
int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    if (S(input)) {
        cout << "Accepted" << endl;
    } else {
        cout << "Rejected" << endl;
    }
    return 0;
}