#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        int srow = 0, scol =0, erow = m-1, ecol = n-1;
        vector <int> ans;

        while (srow <= erow && scol <=ecol) {
            //top

            for (int i=scol; i<= ecol; i++) {
                // if (srow == erow) {
                //     break;
                // }
                ans.push_back(matrix[srow][i]);
            }

            //right

            for (int j=srow+1; j<= erow; j++) {
                // if (scol == ecol) {
                //     break;
                // }
                ans.push_back(matrix[j][ecol]);
            }

            //bottom

            for (int i=ecol-1; i>= scol; i--) {
                if (srow == erow) {
                    break;
                }
                ans.push_back(matrix[erow][i]);
            }

            //left

            for (int j=erow-1; j >= srow+1; j--) {
                if (scol == ecol) {
                    break;
                }
                ans.push_back(matrix[j][scol]);
            }
            srow++;scol++;erow--;ecol--;
        }
        return ans;
    }
};

int main() {
    Solution solver;
    
    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};
    
    vector<int> result = solver.spiralOrder(matrix);
    
    cout << "Spiral Order: " << endl; 
    for (const auto& val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}