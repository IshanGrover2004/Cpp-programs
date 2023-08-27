//Leetcode 1480 -->  https://leetcode.com/problems/running-sum-of-1d-array/

#include<iostream>
#include <vector>
using namespace std;

int main(){
    int arr[]={1,2,3,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    vector<int> ans;
    int sum=0;
    for(int i:arr){
        sum+=i;
        ans.push_back(sum);
    }
    for(int j:ans){
        cout<<j<<" ";
    }
}