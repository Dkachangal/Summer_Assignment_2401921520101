#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0;
        for (int i=0; i<k; i++) {
            currSum += nums[i];
        }
        double maxSum = currSum; 

        for (int i=k; i<nums.size(); i++) {
         
            double newSum = currSum + nums[i] - nums[i-k]; 
            currSum = newSum;
            maxSum = max(currSum, maxSum);
        }
        
        return maxSum / k; 
    }
};

int main() {
    Solution solver;
    
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    
    double maxAvg = solver.findMaxAverage(nums, k);
    
    cout << "Max Average: " << maxAvg << endl; 
    
    return 0;
}