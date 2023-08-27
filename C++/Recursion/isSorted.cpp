// Created by Ishan grover on 07-04-2023.

#include <iostream>
using namespace std;

bool isSorted(int *arr,int n){
    if (n<=1){                  //Base condition checking size of array is 0,1,-ve no. then it is sorted
        return true;
    }
    return (arr[n]>=arr[n-1]) && isSorted(arr,n-1);
    /* 1st condition checks arr[n]>=arr[n-1] or not but this checks once..........
    for checking other elements in array either we need loop or recursive condition
    for checking for other values in array --> isSorted(arr,n-1) */
}

int main() {
    int n;
    cin>>n;
    int* arr= new int[n];        //for variable type array --> using concept of dynamic array & pointers
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    // printing array is sorted or not
    (isSorted(arr,n)==true)?(cout<<"Array is sorted"):(cout<<"Array is not sorted");
    return 0;
}
