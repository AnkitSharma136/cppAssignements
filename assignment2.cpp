#include<iostream>
using namespace std;

class matrix{
    private:
    int n;
    int **ptr;

    public:
    matrix(int size) :n(size){  
        ptr = new int*[n];
        for (int i = 0; i < n; ++i) {
            ptr[i] = new int[n];
        }
    }

    void fillMatrix(int factor){
        for(int i=0 ; i<n; i++){
            for(int j=0 ; j<n ;j++){
                ptr[i][j]=i+j+factor;
            }
        }
    }

    void display(){
        for(int i=0 ; i<n ;i++){
            for(int j=0 ; j<n ;j++){
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    matrix operator+(const matrix& matrix2){
        if(matrix2.n != n){
            throw runtime_error("Both matrix are not of same dimension");
        }
        matrix result(n);
        for(int i=0 ;i<n ;i++){
            for(int j=0 ;j<n ;j++){
                result.ptr[i][j] = ptr[i][j] + matrix2.ptr[i][j];
            }
        }
        return result;
    }
    
    ~matrix(){
        cout<<"Destructor called"<<endl;
        for(int i=0;i<n;i++){
            delete[] ptr[i];
        }
        delete [] ptr;
    } 
};

int main(){
    matrix m1(3);
    matrix m2(3);

    m1.fillMatrix(4);
    m1.display();

    m2.fillMatrix(3);
    m2.display();

    matrix m3 = m1 + m2;
    m3.display();

    return 0;
}
