#include <iostream>
using namespace std;

bool isSubsequence(string s, string t) {
    int i = 0;
    int j = 0;

    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }

    return i == s.size();
}

int main() {
    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    if (isSubsequence(s, t)) {
        cout << "True (s is a subsequence of t)" << endl;
    } else {
        cout << "False (s is NOT a subsequence of t)" << endl;
    }

    return 0;
}