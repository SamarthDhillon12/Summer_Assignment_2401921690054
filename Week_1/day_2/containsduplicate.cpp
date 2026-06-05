#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;

        for (int num : nums) {
            if (s.count(num))
                return true;
            s.insert(num);
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 1};

    cout << (sol.containsDuplicate(nums) ? "true" : "false") << endl;

    return 0;
}