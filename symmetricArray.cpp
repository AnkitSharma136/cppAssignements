#include<iostream>
using namespace std;

int **alloc_n_init(int n){
    int **matrix;
    matrix = new int*[n];

    for(int i=0; i<n; i++){
        matrix[i]=new int[n];

        for(int j=0;j<n;j++){
            matrix[i][j] = i + j;
        }
    }
    return matrix;
}

int **add_matrices(int **matrix1,int **matrix2,int n){
    int **newMatrix;
    newMatrix = new int*[n];

    for(int i=0; i<n; i++){
        newMatrix[i] = new int[n];

        for(int j=0 ;j<n ;j++){
            newMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

return newMatrix;
}

void display_matrix(int **matrix,int n){
    for(int i=0 ; i<n ; i++){
        for(int j=0 ;j<n ;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void free_matrix(int **matrix , int n){
    for(int i=0; i<n ;i++){

        delete []matrix[i];
    }
    delete []matrix;
}

int main(){
    int n = 3;

    int **matrix1;
    matrix1 = alloc_n_init(n);
    display_matrix(matrix1,n);

    int **matrix2;
    matrix2 = alloc_n_init(n);
    display_matrix(matrix2,n);

    int **matrix3;
    matrix3 = add_matrices(matrix1,matrix2,n);
    display_matrix(matrix3,n);

    free_matrix(matrix1,n);
    free_matrix(matrix2,n);
    free_matrix(matrix3,n);
}