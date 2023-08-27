// Created by Ishan grover on 08-04-2023.
//Search a particular value of key in array

#include <iostream>
using namespace std;

int binary_search(int *arr, int start, int end ,int key){
    //Base case condition
    if(start>end){
        return -1;
    }

    int mid = start + (end-start)/2;

    if (arr[mid]==key){     //can say another base case condition
        return mid;
    }
    if (key>arr[mid]){
        return binary_search( arr, mid+1 , end , key);          //In B.S --> for key value greater than mid, it means key lies in right side =>  start = mid+1 & end = end
    }
    else{
        return binary_search(arr , start , mid-1 , key);
    }
}

int main() {
    int n,key;
    cout<<"enter the size of array and key to be found"<<endl;
    cin>>n>>key;
    int* arr= new int[n];          //for variable type array --> using concept of dynamic array
    cout<<"enter the elements in array: "<<endl;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int start=0,end=n-1;
    if(binary_search(arr,start,end,key)==-1){
        cout<<"Key not found!!"<<endl;
    }
    else{
        cout<<"Key found at index "<<binary_search(arr,start,end,key)<<endl;
    }
    return 0;
}