#include <iostream>
#include <vector>

#include <random>   // For better random numbers
#include <chrono>   // For timing
#include <fstream>

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
    // Set the dimensions for a heavy workload
    int size=1024;
    int R1 = size, C1 = size;
    int R2 = size, C2 = size;
    
    int iterations = 100; // You can increase this for more stress testing


    cout << "Initializing " << R1 << "x" << C1 << " matrices with random data..." << endl;

    // Use modern C++ random number generation
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10); // Small numbers to avoid integer overflow

    // Initialize Matrix A
    vector<vector<int>> A(R1, vector<int>(C1));
    for (int i = 0; i < R1; ++i)
        for (int j = 0; j < C1; ++j)
            A[i][j] = dis(gen);

    // Initialize Matrix B
    vector<vector<int>> B(R2, vector<int>(C2));
    for (int i = 0; i < R2; ++i)
        for (int j = 0; j < C2; ++j)
            B[i][j] = dis(gen);

    cout << "Starting multiplication..." << endl;

    // Start the stopwatch
    auto start = chrono::high_resolution_clock::now();

    vector<vector<int>> result = multiplyMatrices(A, B, R1, C1, R2, C2);

    // Stop the stopwatch
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    //cout << "Multiplication complete!" << endl;
    //cout << "Time taken: " << elapsed.count() << " seconds." << endl;

    // Create and open a CSV file
    ofstream outFile("timing_1024x1024.csv");
    outFile << "Run_Number,Time_Seconds\n"; // CSV Header

    cout << "Starting benchmark for " << iterations << " iterations..." << endl;

    for (int i = 1; i <= iterations; ++i) {
        auto start = chrono::high_resolution_clock::now();

        // Perform the multiplication
        vector<vector<int>> result = multiplyMatrices(A, B, R1, C1, R2, C2);

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;

        // Write to terminal AND the file
        cout << "Run " << i << ": " << elapsed.count() << "s" << endl;
        outFile << i << "," << elapsed.count() << "\n";
    }

    outFile.close();
    cout << "Results saved to timing_32x32.csv" << endl;

    // Note: Don't use printMatrix for 1000x1000 unless you want 1 million lines in your terminal!
    return 0;
}
