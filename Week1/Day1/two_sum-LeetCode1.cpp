#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // DONE BY DIVYANSH KACHANGAL -- COMMENTS WRITTEN BY SELF !!!

        // making copy of the vector
        vector<int> cpy;
        for (int x: nums) cpy.push_back(x);

        sort(nums.begin(), nums.end());

        vector<int> ans;

        // i am using two pointer 
        int i = 0;
        int j = nums.size() - 1;

        while (i < j) {
            if (nums[i] + nums[j] == target) {
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                break;
            }
            else if (nums[i] + nums[j] < target) {
                i++;
            } else {
                j--;
            }
        }

        int idx1 = -1;
        int idx2 = -1;

        for (int x = 0; x < cpy.size(); x++) {
            if (cpy[x] == ans[0] && idx1 == -1) {
                idx1 = x;
            } else if (cpy[x] == ans[1] && idx2 == -1) {
                idx2 = x;
            }
        }

        ans[0] = idx1;
        ans[1] = idx2;
        
        return ans;
    }
};


int main() {
    Solution solver;
    
    vector<int> nums = {3, 2, 4};
    int target = 6;
    
    vector<int> result = solver.twoSum(nums, target);
    

    cout << "[" << result[0] << ", " << result[1] << "]" << endl; 
    
    return 0;
}
