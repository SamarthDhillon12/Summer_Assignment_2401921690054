#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findAnagrams(string s, string p) {
    vector<int> result;

    int n = s.length();
    int m = p.length();

    if (m > n) return result;

    vector<int> freqP(26, 0);
    vector<int> freqW(26, 0);

    // Count frequency of pattern
    for (char ch : p) {
        freqP[ch - 'a']++;
    }

    // First window
    for (int i = 0; i < m; i++) {
        freqW[s[i] - 'a']++;
    }

    if (freqP == freqW) {
        result.push_back(0);
    }

    // Sliding window
    for (int i = m; i < n; i++) {
        freqW[s[i] - 'a']++;       // add new character
        freqW[s[i - m] - 'a']--;   // remove old character

        if (freqP == freqW) {
            result.push_back(i - m + 1);
        }
    }

    return result;
}

int main() {
    string s, p;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter pattern p: ";
    cin >> p;

    vector<int> ans = findAnagrams(s, p);

    cout << "Starting indices: ";
    for (int idx : ans) {
        cout << idx << " ";
    }

    cout << endl;
    return 0;
}