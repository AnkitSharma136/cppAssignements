#include<iostream>
using namespace std;

int *concat_arrays(int arr1[], int n1, int arr2[], int n2){
    int * resultantArray = new int[n1 + n2];

    int j = 0;
    for(int i=0 ; i<n1; i++){
        resultantArray[j++]=arr1[i];
    }

    for(int i=0 ; i<n2 ;i++){
        resultantArray[j++]=arr2[i];
    }

    return resultantArray;
}

int *concat_arrays2(int arr1[], int n1, int arr2[], int n2){
    int * resultantArray = new int[n1 + n2];

    for(int i=0 ; i<n1; i++){
        *(resultantArray + i)=arr1[i];
    }

    for(int i=0 ; i<n2 ;i++){
        *(resultantArray + n1 + i)=arr2[i];
    }

    return resultantArray;
}

int main(){
    cout<<endl;
    
    int n1;
    cout<<"Enter size of first array : ";
    cin>>n1;
    cout<<endl;

    int arr1[n1];
    cout<<"Enter elements of first array : ";
    for(int i=0; i<n1; i++){
        int temp;
        cin>>temp;
        arr1[i]=temp;
    }
    cout<<endl;

    int n2;
    cout<<"Enter size of second array : ";
    cin>>n2;
    cout<<endl;

    int arr2[n2];
    cout<<"Enter elements of second array : ";
    for(int i=0; i<n2; i++){
        int temp;
        cin>>temp;
        arr2[i]=temp;
    }
    cout<<endl;

    int * ans = concat_arrays(arr1,n1,arr2,n2);
    cout<<"Resultant array is :  ";
    for(int i=0 ; i<n1 + n2 ; i++){
        cout<<ans[i]<<" ";
    }

    delete [] ans;
    cout<<endl;
}