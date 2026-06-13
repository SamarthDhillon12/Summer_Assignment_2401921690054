#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size())
        return false;

    vector<int> freq(26, 0);

    for (int i = 0; i < s.size(); i++) {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for (int count : freq) {
        if (count != 0)
            return false;
    }

    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    if (isAnagram(s, t))
        cout << "true";
    else
        cout << "false";

    return 0;
}