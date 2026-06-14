#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

string decodeString(string s) {
    stack<int> countStack;
    stack<string> stringStack;

    string currentString = "";
    int k = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            k = k * 10 + (ch - '0');
        }
        else if (ch == '[') {
            countStack.push(k);
            stringStack.push(currentString);

            k = 0;
            currentString = "";
        }
        else if (ch == ']') {
            int repeatTimes = countStack.top();
            countStack.pop();

            string decoded = stringStack.top();
            stringStack.pop();

            while (repeatTimes--) {
                decoded += currentString;
            }

            currentString = decoded;
        }
        else {
            currentString += ch;
        }
    }

    return currentString;
}

int main() {
    string s;

    cout << "Enter encoded string: ";
    cin >> s;

    cout << "Decoded string: " << decodeString(s) << endl;

    return 0;
}