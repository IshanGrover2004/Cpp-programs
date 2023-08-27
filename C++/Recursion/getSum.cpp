// Created by Ishan grover on 07-04-2023.
// Get the sum of all elements in array by using recursion

#include <iostream>
using namespace std;

int getSum(int *arr,int n){
    if(n==0){return 0;}                  //Base case condition
    int sum;
    sum=getSum(arr,n-1) + arr[n-1];     //Recursive condition
    return sum;
}

int main() {
    int n;
    cin>>n;
    int* arr= new int[n];          //for variable type array --> using concept of dynamic array
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout<<getSum(arr,n);
    return 0;
}