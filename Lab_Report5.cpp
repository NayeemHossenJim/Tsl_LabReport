#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string input;
    cout << "Enter a line of code: ";
    getline(cin, input);
    int i = 0;
    while (i < input.length()) {
        if (isalpha(input[i])) {
            string id = "";
            while (isalnum(input[i])) {
                id += input[i++];
            }
            cout << "Identifier: " << id << endl;
        }
        else if (isdigit(input[i])) {
            string num = "";
            while (isdigit(input[i])) {
                num += input[i++];
            }
            cout << "Number: " << num << endl;
        }
        else {
            i++;
        }
    }
    return 0;
}