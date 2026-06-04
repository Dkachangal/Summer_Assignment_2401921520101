#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> newMat(r, vector<int> (c));
        if (mat.size() * mat[0].size() != r*c) return mat; 

        int original_i=0;
        int original_j=0;

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {

                
                if (original_j >= mat[0].size()) {
                    original_i++;
                    original_j = 0;
                }
                if (original_i >= mat.size()) return mat;

                newMat[i][j] = mat[original_i][original_j++];
            }
        }
        return newMat;
    }
};

int main() {
    Solution solver;
    
    vector<vector<int>> mat = {{1,2},
                               {3,4}};
    int r = 1;
    int c = 4;
    
    vector<vector<int>> reshapedMat = solver.matrixReshape(mat, r, c);
    
    cout << "Reshaped Matrix: " << endl; 
    for (const auto& row : reshapedMat) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}