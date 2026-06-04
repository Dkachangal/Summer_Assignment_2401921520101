#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        // as given square matrix
        int diagSum = 0;
        // for (int i=0; i<mat.size(); i++) {
        //     for (int j=0; j<mat.size(); j++) {
        //         if (i == j || i == mat.size()-j-1) diagSum += mat[i][j];
        //     }
        // }
        for (int i=0; i<mat.size(); i++) {
            diagSum += mat[i][i];
            diagSum += mat[i][mat.size()-i-1];
        }
        // done this, so that in odd size matrix, the center element does not add twice while traversing diagonals
        if (mat.size() % 2 != 0) diagSum -= mat[mat.size()/2][mat.size()/2];
        
        
        return diagSum;
    }
};

int main() {
    Solution solver;
    
    vector<vector<int>> mat = {{1,2,3},
                               {4,5,6},
                               {7,8,9}};
    
    int result = solver.diagonalSum(mat);
    
    cout << "Diagonal Sum: " << result << endl; 
    
    return 0;
}