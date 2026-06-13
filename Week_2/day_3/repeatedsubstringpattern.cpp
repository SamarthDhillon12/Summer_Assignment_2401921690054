#include <iostream>
using namespace std;

bool repeatedSubstringPattern(string s) {
    int n = s.size();

    for (int len = 1; len <= n / 2; len++) {
        if (n % len != 0) continue;

        string pattern = s.substr(0, len);
        string built = "";

        for (int i = 0; i < n / len; i++) {
            built += pattern;
        }

        if (built == s) return true;
    }

    return false;
}

int main() {
    string s;

    cout << "Enter string: ";
    cin >> s;

    if (repeatedSubstringPattern(s)) {
        cout << "True (Repeated pattern exists)" << endl;
    } else {
        cout << "False (No repeated pattern)" << endl;
    }

    return 0;
}