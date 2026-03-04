# Basic multiplier example
#include <iostream>
#include <vector>

using namespace std;

// Function to multiply two matrices
// Matrix A: R1 x C1, Matrix B: R2 x C2
// Note: C1 must equal R2 for multiplication to be possible
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, 
                                     const vector<vector<int>>& B, 
                                     int R1, int C1, int R2, int C2) {
    
    // Initialize the result matrix with zeros (Size: R1 x C2)
    vector<vector<int>> result(R1, vector<int>(C2, 0));

    for (int i = 0; i < R1; ++i) {      // Loop through rows of A
        for (int j = 0; j < C2; ++j) {  // Loop through columns of B
            for (int k = 0; k < C1; ++k) { // Dot product calculation
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Defining two simple 2x2 matrices
    vector<vector<int>> A = {{1, 2}, {3, 4}};
    vector<vector<int>> B = {{5, 6}, {7, 8}};

    int R1 = 2, C1 = 2, R2 = 2, C2 = 2;

    if (C1 != R2) {
        cout << "Error: Matrices cannot be multiplied!" << endl;
        return 1;
    }

    vector<vector<int>> result = multiplyMatrices(A, B, R1, C1, R2, C2);

    cout << "Resultant Matrix:" << endl;
    printMatrix(result);

    return 0;
}
