#include <iostream>
using namespace std;

string input;
int pos = 0;

bool S();
bool A();
bool B();

bool S() {
    if (input[pos] == 'b') 
    {
        pos++;
        return true;
    } 
    else 
    {
        int startPos = pos;
        if (A() && B()) 
        {
            return true;
        }
        pos = startPos;
        return false;
    }
}

bool A() 
{
    if (input[pos] == 'a') 
    {
        pos++;
        if (pos < input.length() && input[pos] == 'a') 
        {
            return A();
        }
        return true;
    }
    return false;
}

bool B()
{
    if (input[pos] == 'b') 
    {
        pos++;
        return true;
    }
    return false;
}

int main() {
    cout << "Enter a string: ";
    cin >> input;
    pos = 0;

    if (S() && pos == input.length()) {
        cout << "Accepted" << endl;
    } else {
        cout << "Rejected" << endl;
    }

    return 0;
}
