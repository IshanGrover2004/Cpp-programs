// Created by grove on 01-04-2023.
// Leetcode 852 question using binary search concept
//https://leetcode.com/problems/peak-index-in-a-mountain-array/

#include <iostream>
#include <array>
using namespace std;

int main(){
    int n;
    cout<<"enter the size of array"<<endl;
    cin>>n;

    int arr[n];
    cout<<"Input the array elements: ";
    for (int &ele:arr){
        cin>>ele;
    }
    int s=0 , e=n-1;
    int mid = s + (e-s)/2;

    while(s<e){
        if (arr[mid] < arr[mid+1]){
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    cout<<"The peak index & element is: "<<s<<","<<arr[s];
}