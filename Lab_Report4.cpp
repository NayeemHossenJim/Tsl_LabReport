#include <iostream>
#include <ctype.h>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
unordered_set<string> keywords = {"int", "float", "double", "char", "if", "else", "for", "while", "return", "void", "main"};
unordered_set<char> operators = {'+', '-', '*', '/', '=', '<', '>', '!', '&', '|', '%', ';'};
bool isKeyword(const string &str) {
    return keywords.find(str) != keywords.end();
}
bool isNumber(const string &str) {
    for (char c : str) {
        if (!isdigit(c) && c != '.') return false;
    }
    return true;
}
bool isOperator(char c) {
    return operators.find(c) != operators.end();
}
void lexicalAnalyzer(const string &code) {
    vector<string> tokens;
    string token = "";
    
    for (size_t i = 0; i < code.length(); i++) {
        char c = code[i];
        
        if (isspace(c) || isOperator(c) || c == '(' || c == ')' || c == ',' || c == ';') {
            if (!token.empty()) {
                tokens.push_back(token);
                token = "";
            }
            
            if (isOperator(c)) {
                string op(1, c);
                tokens.push_back(op);
            } else if (c == '(' || c == ')' || c == ',' || c == ';') {
                tokens.push_back(string(1, c));
            }
        } else {
            token += c;
        }
    }
    
    if (!token.empty()) tokens.push_back(token);
    cout << "Token Type" << endl;
    cout << "--------------------------" << endl;
    for (const string &tok : tokens) {
        if (isKeyword(tok)) {
            cout << tok << " : Keyword" << endl;
        } else if (isNumber(tok)) {
            cout << tok << " : Number" << endl;
        } else if (tok.length() == 1 && isOperator(tok[0])) {
            cout << tok << " : Operator" << endl;
        } else if (tok == "(" || tok == ")" || tok == ";" || tok == ",") {
            cout << tok << " : Punctuation" << endl;
        } else {
            cout << tok << " : Identifier" << endl;
        }
    }
}
int main() {
    string code;
    cout << "Enter a line: ";
    getline(cin, code);
    lexicalAnalyzer(code);
    return 0;
}