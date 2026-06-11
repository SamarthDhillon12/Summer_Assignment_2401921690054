#include <iostream>
#include <vector>
using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += mat[i][i];          // Primary diagonal
        sum += mat[i][n - 1 - i];  // Secondary diagonal
    }

    if (n % 2 == 1) {
        int mid = n / 2;
        sum -= mat[mid][mid];      // Remove duplicate middle element
    }

    return sum;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Diagonal Sum = " << diagonalSum(mat);

    return 0;
}