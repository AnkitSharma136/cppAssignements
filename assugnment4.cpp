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

    myArray (myArray &other){
        cout<<"Shallow Copy Constructor Called"<<endl;
        refPtr = other.refPtr;
        other.refPtr->count++;
        n = other.n;
    }

    // myArray(myArray &other){
    //     cout<<"Deep copy constructor called"<<endl;
    //     refPtr = new refCount;
    //     refPtr->arr = new int[other.n];

    //     for(int i=0;i<n;i++){
    //         refPtr->arr[i] = other.refPtr->arr[i];
    //     }

    //     refPtr->count=1;
    // }

    myArray& operator=(const myArray &other){
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

int main(){
    myArray arr(4);
    arr.fillArray();
    //arr[1]=8;
    myArray arr2 = arr;
    arr.display();
    arr2.display();
    //cout<<&arr.refPtr<<endl;
    //cout<<&arr2.refPtr<<endl;
    //cout<<&arr.refPtr->arr<<endl;
    //cout<<&arr.refPtr->arr<<endl;
}