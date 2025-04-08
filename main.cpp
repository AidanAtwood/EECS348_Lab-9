/*
    Include the necessary libraries for the program. 

    NOTE: chatGPT was used to cross verify code in multiple areas and will be marked as such

    NOTE: in the process of rewriting code to better handle doubles, some libraries from Lab 8 were deemed unnecessary and as such, were removed.
*/

#include <iostream>
#include <fstream>
#include "matrix.hpp" 

//declare main
int main() {
    //declare needed variable filename
    std::string filename;
    //prompt the user for their input file
    std::cout << "Enter the filename: ";
    //save user specified file as filename
    std::cin >> filename;

    //open our input file
    std::ifstream file(filename);
    //ensure our file is valid / exists
    if (!file) {
        //return error and end program if file is invalid
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }

    //declare needed variable for later
    int N;
    //retrieve N from input file
    file >> N;
    //declare needed variable
    int C;
    //retrieve the value that specifies our value type
    file >> C;
    //print matrices to terminal
    std::cout << "Matrix size: " << N << std::endl;
    if (C == 0){
        //declare empty matrix for our user variables
        std::vector<std::vector<int>> matrix_data_1(N, std::vector<int>(N));
        //loop that parses through matrices and adds our values variable by variable
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                //save our data
                file >> matrix_data_1[i][j];
            }
        }

        //repeat for the second matrix

        //declare empty matrix for our user variables
        std::vector<std::vector<int>> matrix_data_2(N, std::vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                //save our data
                file >> matrix_data_2[i][j];
            }
        }
        
        //create matrices with the data we retrieved from our input file
        Matrix matrix1(matrix_data_1);
        Matrix matrix2(matrix_data_2);

        //print matrix1
        std::cout << "\nMatrix 1:" << std::endl;
        matrix1.print_matrix();
        
        //print matrix2
        std::cout << "\nMatrix 2:" << std::endl;
        matrix2.print_matrix();

        //add our two matrices
        Matrix result = matrix1 + matrix2;
        //print our added matrices to terminal
        std::cout << "\nMatrix 1 + Matrix 2:" << std::endl;
        result.print_matrix();

        //multiply our two matrices
        result = matrix1 * matrix2;
        //print our multiplied matrices to terminal
        std::cout << "\nMatrix 1 * Matrix 2:" << std::endl;
        result.print_matrix();

        //declare our row variables
        size_t row1, row2;
        //prompt the user to enter the two rows they'd like to swap
        std::cout << "\nEnter two row indices to swap (index starts at zero): ";
        //store the user inputted rows
        std::cin >> row1 >> row2;
        
        //ensure our row index is valid
        if (row1 < N && row2 < N) {
            //swap rows
            matrix1.swap_rows(row1, row2);
            //print the rows that we swap
            std::cout << "\nMatrix after swapping rows " << row1 << " and " << row2 << ":" << std::endl;
            //print the new matrix to terminal
            matrix1.print_matrix();

        }
        //run if row index is invalid 
        else {
            //throw error
            std::cerr << "The provided row indices are invalid" << std::endl;
        }

        //declare our column variables
        size_t col1, col2;
        //prompt user for the columns they'd like to swap
        std::cout << "\nEnter two column indices to swap (index starts at zero): ";
        //store the user inputted columns
        std::cin >> col1 >> col2;

        //ensure column indices are valid
        if (col1 < N && col2 < N) {
            //swap columns
            matrix1.swap_cols(col1, col2);
            //print the swapped columns
            std::cout << "\nMatrix after swapping columns " << col1 << " and " << col2 << ":" << std::endl;
            //print final matrix to terminal
            matrix1.print_matrix();
        }
        //run if column index is invalid 
        else {
            //throw error
            std::cerr << "The provided column indices are invalid" << std::endl;
        }

        //declare needed variables
        size_t row, col;
        int new_value;
        //prompt user for their inputs
        std::cout << "\nEnter row, column, and new value to update the matrix (row and column indices begin at zero): ";
        //save our inputs
        std::cin >> row >> col >> new_value;
        
        //ensure user provided values are valid
        if (row < N && col < N) {
            //update matrix using user defined values
            matrix1.set_value(row, col, new_value);
            //print what user changed to terminal
            std::cout << "\nMatrix after updating element at (" << row << ", " << col << "):" << std::endl;
            //print new matrix to terminal
            matrix1.print_matrix();
        }
        //run if user provided input is invalid 
        else {
            //throw error
            std::cerr << "The provided row or column index is invalid" << std::endl;
        }

    }
    
    /* EVERYTHING BELOW THIS POINT IS FOR MATRICES USING DOUBLES. DUE TO TEMPLATE IMPLIMENTATION, IT IS NEAR IDENTICAL TO THE ABOVE CODE */

    else if (C == 1) {
        //declare empty matrix for our user variables
        std::vector<std::vector<double>> matrix_data_1(N, std::vector<double>(N));
        //loop that parses through matrices and adds our values variable by variable
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                //save our data
                file >> matrix_data_1[i][j];
            }
        }

        //declare empty matrix for our user variables
        std::vector<std::vector<double>> matrix_data_2(N, std::vector<double>(N)); //declares a new 2d matrix with vectors of size N
        //loop that parses through matrices and adds our values variable by variable
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                //save our data
                file >> matrix_data_2[i][j];
            }
        }
        
        //create matrices with the data we retrieved from our input file
        Matrix<double> matrix1(matrix_data_1);
        Matrix<double> matrix2(matrix_data_2);

        //print matrix1 to terminal
        std::cout << "\nMatrix 1:" << std::endl;
        matrix1.print_matrix();
        
        //print matrix2 to terminal
        std::cout << "\nMatrix 2:" << std::endl;
        matrix2.print_matrix();

        //add our two matrices
        Matrix<double> result = matrix1 + matrix2;
        //print our two matrices added together
        std::cout << "\nMatrix 1 + Matrix 2:" << std::endl;
        result.print_matrix();

        //multiply our two matrices
        result = matrix1 * matrix2;
        //print our two matrices multiplied together
        std::cout << "\nMatrix 1 * Matrix 2:" << std::endl;
        result.print_matrix();

        //declare needed variables
        size_t row1, row2;
        //prompt user for the row values they'd like to swap
        std::cout << "\nEnter two row indices to swap (row index starts at zero): ";
        //save our inputs
        std::cin >> row1 >> row2;
        
        //ensure our index is valie
        if (row1 < N && row2 < N) {
            //swap rows
            matrix1.swap_rows(row1, row2);
            //print swapped rows to terminal
            std::cout << "\nMatrix after swapping rows " << row1 << " and " << row2 << ":" << std::endl;
            //print updated matrix to terminal
            matrix1.print_matrix();
        } 
        //run if user provided index is invalid
        else {
            //throw error
            std::cerr << "The provided row indices are invalid" << std::endl;
        }

        //declare needed variables
        size_t col1, col2;
        //prompt user for the columns theyd like to swap
        std::cout << "\nEnter two column indices to swap (column index starts at zero): ";
        //save our input
        std::cin >> col1 >> col2;

        //ensure our column index is valid
        if (col1 < N && col2 < N) {
            //swap columns
            matrix1.swap_cols(col1, col2);
            //print swapped columns to terminal
            std::cout << "\nMatrix after swapping columns " << col1 << " and " << col2 << ":" << std::endl;
            //print updated matrix to terminal
            matrix1.print_matrix();
        } 
        //run if user provided index is invalid
        else {
            //throw error
            std::cerr << "Invalid column indices!" << std::endl;
        }

        //declare needed variables
        size_t row, col;
        double new_value;
        //prompt user for their inputs
        std::cout << "\nEnter row, column, and new value to update the matrix (row and column indices begin at zero): ";
        //save our inputs
        std::cin >> row >> col >> new_value;
        
        //ensure user input is valid
        if (row < N && col < N) {
            //update our matrix
            matrix1.set_value(row, col, new_value);
            //print what we updated to terminal
            std::cout << "\nMatrix after updating element at (" << row << ", " << col << "):" << std::endl;
            //print updated matrix to terminal
            matrix1.print_matrix();
        } 
        //run if user input is invalid
        else {
            //throw error
            std::cerr << "Invalid row or column index" << std::endl;
        }
    }
    
    return 0;
}