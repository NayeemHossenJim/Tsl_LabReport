#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ifstream file("Jim.txt");

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int charCount = 0, wordCount = 0, lineCount = 0;
    string line, word;

    while (getline(file, line)) {
        lineCount++;
        charCount += line.length();

        istringstream stream(line);
        while (stream >> word) {
            wordCount++;
        }
    }

    file.close();

    cout << "Characters: " << charCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Lines: " << lineCount << endl;

    return 0;
}
