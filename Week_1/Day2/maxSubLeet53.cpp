#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size()==1) return nums[0];

        int maxSum = nums[0];
        int currSum = nums[0];

        for (int i=1; i<nums.size(); i++) {
            currSum = max(nums[i], nums[i] + currSum);
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};

int main() {
    Solution solver;
    
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    
    int maxSum = solver.maxSubArray(nums);
    
    cout << "Max Subarray Sum: " << maxSum << endl; 
    
    return 0;
}