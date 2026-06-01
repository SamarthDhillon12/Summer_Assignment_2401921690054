#include <iostream>
#include <vector> 
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i,j;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){

                

                return{i,j};
            }

        }
        
        
    } return{};
}
}; 
int main(){
    vector<int>nums = {2,7,11,15};
    int target= 9;
    Solution s;
    vector<int> ans=s.twoSum(nums,target);
    cout<<ans[0]<<"  "<<ans[1];
    return 0;


}
