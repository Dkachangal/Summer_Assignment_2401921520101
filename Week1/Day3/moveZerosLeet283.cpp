#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int prevZero = 0;

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[prevZero], nums[i]);
                prevZero++;

            }   
        }

    }
};

int main() {
    Solution solver;
    
    vector<int> nums = {0,1,0,3,12};
    
    solver.moveZeroes(nums);
    
    cout << "Array after moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl; 
    
    return 0;
}