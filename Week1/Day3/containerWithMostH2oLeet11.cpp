#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int maxArea = 0;
        int left = 0; 
        int right = height.size()-1;
        while (left < right) {

            int hei = min(height[left], height[right]);
            int weight = right - left; 
            int water = weight*hei;
            maxArea = max(maxArea,water);

            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        return maxArea;
    }
};

int main() {
    Solution solver;
    
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    
    int result = solver.maxArea(height);
    
    cout << "Maximum Area of Water: " << result << endl; 
    
    return 0;
}