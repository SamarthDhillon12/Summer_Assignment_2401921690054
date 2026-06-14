#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string str : strs) {
        string key = str;
        sort(key.begin(), key.end());

        mp[key].push_back(str);
    }

    vector<vector<string>> result;

    for (auto &it : mp) {
        result.push_back(it.second);
    }

    return result;
}

int main() {
    int n;

    cout << "Enter number of strings: ";
    cin >> n;

    vector<string> strs(n);

    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }

    vector<vector<string>> ans = groupAnagrams(strs);

    cout << "\nGrouped Anagrams:\n";

    for (auto &group : ans) {
        cout << "[ ";
        for (string s : group) {
            cout << s << " ";
        }
        cout << "]\n";
    }

    return 0;
}