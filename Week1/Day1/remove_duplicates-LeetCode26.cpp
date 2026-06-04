#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // vector <int> expectedNums;
        vector <int> numsCpy;
        for (int i = 0; i <nums.size(); i++) {
            numsCpy.push_back(nums[i]);
        }
        nums.clear();
        int temp = 101;
        int k;

        for (int i=0; i<numsCpy.size(); i++) {
            if (temp == numsCpy[i]) {
                continue;
            } else {
                nums.push_back(numsCpy[i]);
                temp = nums[i];
            }
        }
        k = nums.size();
        return k;
    }
};

int main() {
    Solution solver;
    
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    
    int k = solver.removeDuplicates(nums);
    
    cout << "k: " << k << endl; 
    cout << "Modified nums: ";
    for (int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}