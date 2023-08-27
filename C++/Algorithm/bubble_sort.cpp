//take first two elements campare their value and swap if needed,go on the next 2 elements==> this result the lvl 1 made the max value reach to rightmost

// Time complexity = O(n2)    ||    Space complexity = O(1)
// Created by Ishan grover on 03-04-2023.
#include <iostream>
using namespace std;

int main(){
    int n=6, arr[]={5,3,4,2,1,6};
    for (int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout<<"Sorted array by BUBBLE SORT is-:"<<endl;
    for (int ele:arr){cout<<ele<<" ";}
}
