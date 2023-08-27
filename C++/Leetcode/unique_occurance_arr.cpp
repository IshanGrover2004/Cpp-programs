//Leetcode problem --> 1207
// Given an array of integers arr, return true if the number of occurrences of each value
// in the array is unique or false otherwise.

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    vector<int> ans;
    sort(arr.begin(),arr.end());

    for (int i=0;i<arr.size();i+=0){
        int count=1;
        for(int j=i+1;j<arr.size();j++){
            if (arr[i]==arr[j]){
                count++;
            }
            else{
                break;
            }
        }
        ans.push_back(count);
        i+=count;
    }

    sort(ans.begin(),ans.end());
    for (int x=1;x<ans.size();x++){
        if (ans[x]==ans[x-1]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> v;
    v = {1,2,2,1,1,3};
    cout<< uniqueOccurrences(v);
    return 0;
}