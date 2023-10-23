/*
Creator: Aryamann Zutshi
Id Number: 3023609
Lab: Software Engineering Lab 6
Date: October 22, 2023
Sources used:
    - https://www.geeksforgeeks.org/cpp-program-for-addition-of-two-matrices/
    - https://stackoverflow.com/questions/7868936/read-file-line-by-line-using-ifstream-in-c
    - https://www.geeksforgeeks.org/c-program-multiply-two-matrices/ 
*/

// Including necessary header files
#include <iostream>    // For standard I/O operations
#include <fstream>     // For file operations
#include <vector>      // For using vector data structure
#include <sstream>     // For string stream operations

// Constant for the file name that contains matrix data
const std::string FILENAME = "/Users/mannz/workspaces/ku/software engineering/Lab6_Zutshi/matrix_input.txt";

// Function to read the matrix from a file
std::vector<std::vector<int>> readMatrix(std::ifstream& file, int size) {
    // Initialize a square matrix of given size with default values
    std::vector<std::vector<int>> matrix(size, std::vector<int>(size));

    // Nested loop to iterate over each element of the matrix and read from the file
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            file >> matrix[i][j];
            // Debug info to see which matrix element is being read
            std::cout << "Reading matrix[" << i << "][" << j << "]: " << matrix[i][j] << std::endl; 
        }
    }

    // Return the read matrix
    return matrix;
}

// Function to print a matrix to the console
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl; // New line after each row
    }
}

// Function to add two matrices
// used the geeks for geeks article above to help me with this part
std::vector<std::vector<int>> matrixAdd(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
    int size = a.size();
    std::vector<std::vector<int>> result(size, std::vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = a[i][j] + b[i][j]; // Element-wise addition
        }
    }
    return result;
}

// Function to subtract one matrix from another
//same logic as adding, but subtracting
std::vector<std::vector<int>> matrixDifference(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
    int size = a.size();
    std::vector<std::vector<int>> result(size, std::vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = a[i][j] - b[i][j]; // Element-wise subtraction
        }
    }
    return result;
}

// Function to multiply two matrices
//the geeks for geeks source of matrix multiplication was used here
std::vector<std::vector<int>> matrixProduct(const std::vector<std::vector<int>>& a, const std::vector<std::vector<int>>& b) {
    int size = a.size();
    std::vector<std::vector<int>> result(size, std::vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result[i][j] += a[i][k] * b[k][j]; // Standard matrix multiplication
            }
        }
    }
    return result;
}

// Main function to execute the program
int main() {
    // Open the file with the specified filename for reading
    std::ifstream file(FILENAME);

    // Check if the file is open, if not, print an error and exit
    if (!file.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
        return 1;
    }

    int size;
    // Read the size of the matrices
    file >> size;
    // Clear the buffer and move to the next line in the file
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    // Display matrix size for debugging
    //i was having a lot of issues with the reading of the file so i thought I would add this in to help me out
    //i also used geeks for geeks a lot to figure out how to do this
    std::cout << "Matrix size read: " << size << std::endl; 
    // Display the state of the file for debugging
    std::cout << "File state before reading matrices: " << file.good() << std::endl; 

    // Read the two matrices from the file
    std::vector<std::vector<int>> matrixA = readMatrix(file, size);
    std::vector<std::vector<int>> matrixB = readMatrix(file, size);

    // Display the read matrices
    std::cout << "\nMatrix A:" << std::endl;
    printMatrix(matrixA);
    
    std::cout << "\nMatrix B:" << std::endl;
    printMatrix(matrixB);

    // Display the sum of the matrices
    std::cout << "\nMatrix Sum (A + B):" << std::endl;
    printMatrix(matrixAdd(matrixA, matrixB));

    // Display the difference of the matrices
    std::cout << "\nMatrix Difference (A - B):" << std::endl;
    printMatrix(matrixDifference(matrixA, matrixB));

    // Display the product of the matrices
    std::cout << "\nMatrix Product (A * B):" << std::endl;
    printMatrix(matrixProduct(matrixA, matrixB));

    // Close the file after reading
    // just good practice
    file.close();

    // Return 0 indicating successful completion
    return 0;
}
