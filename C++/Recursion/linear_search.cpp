// Created by Ishan grover on 08-04-2023.
//Search a particular value of key in array

#include <iostream>
using namespace std;

bool search(int *arr,int n, int key){
    if(n<=0){                        //base case condition
        return false;
    }

    if (arr[0]==key){
        return true;
    }
    else{
        return search(arr+1,n-1,key);
    }
}

int main() {
    int n,key;
    cin>>n>>key;
    int* arr= new int[n];          //for variable type array --> using concept of dynamic array
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    if(search(arr,n,key)){
        cout<<"Key found"<<endl;
    }
    else{
        cout<<"Key not found"<<endl;
    }
    return 0;
}