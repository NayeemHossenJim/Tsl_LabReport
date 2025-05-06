#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;

    cout << "Enter a line of code: ";
    getline(cin, line);

    size_t firstChar = line.find_first_not_of(" \t");

    if (firstChar != string::npos) {
        string trimmedLine = line.substr(firstChar);

        if (trimmedLine.substr(0, 2) == "//") {
            cout << "It is a single-line comment." << endl;
        } else if (trimmedLine.substr(0, 2) == "/*") {
            cout << "It is a multi-line comment start." << endl;
        } else {
            cout << "It is NOT a comment." << endl;
        }
    } else {
        cout << "Empty or whitespace-only line." << endl;
    }

    return 0;
}
