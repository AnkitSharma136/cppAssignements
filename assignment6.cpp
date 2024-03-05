#include<iostream>
using namespace std;

struct refCount{
    int count;
    int *arr;
};

class myArray{
public:
    int n;
    refCount * refPtr;

public:

    myArray(int size) : n(size){
        refPtr = new refCount;
        refPtr->arr = new int[n];
        refPtr->count = 1;
    }

    myArray (const myArray &other){
        cout<<"Shallow Copy Constructor Called"<<endl;
        refPtr = other.refPtr;
        other.refPtr->count++;
        n = other.n;
    }

    myArray(myArray &other , int x){
        cout<<"Deep copy constructor called"<<endl;
        refPtr = new refCount;
        refPtr->arr = new int[other.n];

        for(int i=0;i<other.n;i++){
            refPtr->arr[i] = other.refPtr->arr[i];
        }

        refPtr->count=1;
        n = other.n;
    }

    myArray& operator=(const myArray &other){

        if(&other == this) return *this;

        refPtr->count--;
        if(refPtr->count<=0){
            delete []refPtr->arr;
            delete refPtr;
        }

        refPtr = other.refPtr;
        refPtr->count++;
        n = other.n;
        
        return *this;
    }

    void display(){
        for(int i=0;i<n;i++){
            cout<<refPtr->arr[i]<<" ";
        }
        cout<<endl;
    }

    int& operator[](const int& i){
        return refPtr->arr[i];
    }

    void fillArray(){
        cout<<"Enter "<<n<<" space seperated integers to fill the array"<<endl;

        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            refPtr->arr[i]=temp;
        }
    }
    
    void setSingEle(const int& i,int& element){
        refPtr->arr[i] = element;
    }

    myArray& operator++(){
        cout<<"Prefix"<<endl;
        for(int i=0;i<n;i++){
            refPtr->arr[i]++;
        }
        return *this;
    }

    myArray operator++(int){
        cout<<"Postfix"<<endl;
        myArray result(*this,1);

        for(int i=0;i<n;i++){
            refPtr->arr[i]++;
        }
        return result;
    }

    myArray operator-(myArray&other){
        myArray result(other.n); 

        for(int i=0 ; i<other.n;i++){
            result.refPtr->arr[i] = refPtr->arr[i] - other.refPtr->arr[i];
        }
        return result;
    }

    friend myArray operator+(const myArray&a , const myArray&b);

    int getSize(){
        return n;
    }
    ~myArray(){
        cout<<"Destructor called"<<endl;
        refPtr->count--;
        if(refPtr->count<=0){
            cout<<"Destructor freed referenced memory"<<endl;
            delete []refPtr->arr;
            delete refPtr;
        }
        else{
            cout<<"Destructor didn't freed the memory as more references exist"<<endl;
        }
    }
};

myArray operator+( const myArray&a , const myArray&b){
    myArray result(a.n);

    for(int i=0 ; i<a.n;i++){
        result.refPtr->arr[i] = a.refPtr->arr[i] + b.refPtr->arr[i];
    }
    return result;
}

int main(){
    myArray arr(4);
    arr.fillArray();

    arr.display();
    myArray arr2 = ++arr;

    arr2.display();

    myArray arr5 = arr;
    
    myArray arr3(arr.n);

    arr3 = arr + arr2;

    arr3.display();

   // myArray arr4(arr.n);

    myArray arr4 = arr3 - arr;

    arr4.display();
}