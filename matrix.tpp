/*
    Include the necessary libraries for the program. 

    NOTE: chatGPT was used to cross verify code in multiple areas and will be marked as such

    NOTE: in the process of rewriting code into a templated format to better handle doubles, some libraries from Lab 8 were deemed unnecessary and as such, were removed.
*/

#include "matrix.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

//declare templated function
template <typename T>
//declare our matrix
Matrix<T>::Matrix(size_t N) {
    //ensure the size of our matrix is valid
    if (N <= 0) {
        //return an error if size is invalid
        throw out_of_range("Matrix cannot have a size smaller than zero");
    }
    //declare an empty vector to store our data later 
    data.resize(N, vector<T>(N, 0));
}

//declare templated function
template <typename T>
Matrix<T>::Matrix(vector<vector<T>> nums) {
    data = nums; 
}

//declare templated function
template <typename T>
//overload operator to allow addition of two matrices
Matrix<T> Matrix<T>::operator+(const Matrix &rhs) const {
    //retieve the size of our matrix
    int N = get_size();

    //create an empty matrix of size N
    Matrix result(N);
    //loop to parse every element of the matrix and add each value
    for (int i = 0; i < N; i++){ 
        for (int j = 0; j < N; j++){
            result.data[i][j] = data[i][j] + rhs.data[i][j];
        }
    }
    //return the result
    return result; 
}

//declare templated function
template <typename T>
//overload operator to allow the multiplication of two matrices
Matrix<T> Matrix<T>::operator*(const Matrix &rhs) const {
    //retrieve the size of our matrix
    int N = get_size();

    //create matrix of size N
    Matrix result(N);
    //loop to parse every element of the matrix and multiply the values
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                result.data[i][j] += data[i][k] * rhs.data[k][j];
            }
        }
    }
    //return the result
    return result;
}

//declare templated function
template <typename T>
//declare the values inside our matrices
void Matrix<T>::set_value(size_t i, size_t j, T n){
    //ensure the size of our matrices is valid
    if (i >= get_size() || j >= get_size()) {
        //throw an error if size is invalid
        throw out_of_range("Index out of bounds");
    }
    //update values with the ones the user provided
    data[i][j] = n;
}

//declare templated function
template <typename T>
//retrieve values at certain inputs
T Matrix<T>::get_value(size_t i, size_t j) const{
    //ensure our index is valid
    if (i >= get_size() || j >= get_size()) {
        //throw an error if index is invalid
        throw out_of_range("Index out of bounds");
    }
    //return the value at specified index
    return data[i][j];
}

//declare templated function
template <typename T>
//return the size of our matrix
int Matrix<T>::get_size() const{
    return data.size();
}

//declare templated function
template <typename T>
//add the top left and bottom right (major) diagonal values in our matrix
T Matrix<T>::sum_diagonal_major() const {
    //declare needed variables
    int sum = 0;
    int N = get_size();
    //loop through matrix in order to add the diagonals
    for (int i = 0; i < N; i++) {
        sum += data[i][i];
    }
    //return sum
    return sum;
};

//declare templated function
template <typename T>
//add the top right and bottom left (minor) diagonal values in our matrix
T Matrix<T>::sum_diagonal_minor() const {
    //declare needed variables
    int sum = 0;
    int N = get_size();
    //loop through matrix in order th eadd the diagonals
    for (int i = 0; i < N; i++) {
        sum += data[i][N - i - 1];
    }
    //return sum
    return sum;
};

/*
    NOTE: chatGPT was used as reference when testing the swap functions. all variables are my own and code is heavily modified to fit this specific assignment
*/
//declare templated function
template <typename T>
//take two inputs and swap the rows
void Matrix<T>::swap_rows(size_t r1, size_t r2){
    //store the size of the matrix
    int N = get_size();
    //ensure the index is valid
    if (r1 >= N || r2 >= N) {
        //throw an error if index is invalid
        throw out_of_range("Row index out of bounds.");
    }
    //swap the two specified rows
    swap(data[r1], data[r2]);
};

//declare templated function
template <typename T>
//take two inputs and swap the columns    
void Matrix<T>::swap_cols(size_t c1, size_t c2){
    //store the size of the matrix
    int N = get_size();
    //ensure our index is valid
    if (c1 >= N || c2 >= N) {
        //throw an error if index is invalid
        throw out_of_range("Column index out of bounds.");
    }
    //loop through matrices in order to swap needed values
    for (int i = 0; i < N; i++) {
        //swap values
        swap(data[i][c1], data[i][c2]);
    }
};

//declare templated function
template <typename T>
//print matrix to terminal
void Matrix<T>::print_matrix() const {
    /*
        NOTE: chatGPT was used as reverence for the below code. code is again, modified to fit this specific assignment
    */
    //parse each row in our matrix, ensuring data is not modified in any way
    for (const auto &row : data) {
        //parse the values in each row
        for (const T& val : row) {
            //print the value to terminal
            cout << val << " ";
        }
        //help format our matrices by printing each row to a new line
        cout << "\n";
    }
}