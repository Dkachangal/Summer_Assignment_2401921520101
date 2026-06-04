#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        int sqIdx = nums.size()-1;
        vector<int> sq(nums.size());

        while (left <= right) {
            int leftVal = nums[left] * nums[left];
            int rightVal = nums[right] * nums[right];

            if (leftVal > rightVal) {
                sq[sqIdx] = leftVal;
                left++;
            } else {
                sq[sqIdx] = rightVal;
                right--;
            }
            sqIdx--;
        }
        return sq;
    }
};

int main() {
    Solution solver;
    
    vector<int> nums = {-4,-1,0,3,10};
    
    vector<int> result = solver.sortedSquares(nums);
    
    cout << "Sorted Squares: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl; 
    
    return 0;
}