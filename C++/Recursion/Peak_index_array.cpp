// Created by Ishan grover on 09-04-2023.
//Search the peak element in array but by recursion

#include <iostream>
using namespace std;

int findpeak(int* nums,int s,int e){
    //base case
    if(s>e){
        return -1;
    }
    int mid=s+(e-s)/2;
    if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1]){
        return mid;
    }
    if(nums[mid]<nums[mid+1]){
        return findpeak(nums,mid+1,e);
    }
    else{
        return findpeak(nums,s,mid);
    }
    return -1;
}


int main() {
    int n;
    cin>>n;
    int* arr= new int[n];          //for variable type array --> using concept of dynamic array
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int ans=findpeak(arr,0,n-1);
    if(ans==-1){
        cout<<"Peak not found"<<endl;
    }
    else{
        cout<<"Peak found at index "<<ans<<" and value is "<<arr[ans]<<endl;
    }
    return 0;
}