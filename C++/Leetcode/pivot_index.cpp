// Created by grove on 01-04-2023.
// 724. Find Pivot Index Leetcode question
/* The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
if array is {1,7,3,6,5,6} then pivot_index = 3 bcs 1+7+3=5+6 */

#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int sum_left=0,sum_right=0,sum_total=0;
    int s=0 , e=nums.size()-1;
    int mid=s+(e-s)/2;
    for (int ele:nums){
        sum_total+=ele;
    }
    for (int i=0;i<nums.size();i++){
        sum_left += nums[i];
        sum_right = sum_total - sum_left + nums[i];
        if ( sum_left == sum_right ){ 
            return i;
        }
        
    }
    return -1;
}

int main(){
    vector<int> v = {1,7,3,6,5,6};
    cout<< pivotIndex(v) <<endl;
}