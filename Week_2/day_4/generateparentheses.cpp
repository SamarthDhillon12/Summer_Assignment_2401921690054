#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> result;

void backtrack(string current, int open, int close, int n) {
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    if (open < n) {
        backtrack(current + "(", open + 1, close, n);
    }

    if (close < open) {
        backtrack(current + ")", open, close + 1, n);
    }
}

vector<string> generateParenthesis(int n) {
    result.clear();
    backtrack("", 0, 0, n);
    return result;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<string> ans = generateParenthesis(n);

    cout << "Valid Parentheses:\n";
    for (string s : ans) {
        cout << s << endl;
    }

    return 0;
}