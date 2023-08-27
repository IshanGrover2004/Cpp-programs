// Created by grove on 17-04-2023.
// Time complexity = O(n.logn) [Average or Best case]   ||    Space complexity = O()
//                   O(n^2)    [Worst case]

#include <iostream>
using namespace std;

int partition(int arr[], int low, int high){
    // Choosing the pivot
    int pivot = arr[high];
 
    // Index of smaller element and indicates the right position of pivot found so far
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;         // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

//Quick sort funcn --> 
void quick_sort(int *arr,int s,int e){
    //Base case
    if(s>=e){
        return ;
    }

    //partition in arr b/w s & e about any pivot index
    int p = partition(arr,s,e);       //return pivot index where this element is in right place

    //recursion applying quicksort in 2 partition made
    quick_sort(arr,s,p-1);    //left side
    quick_sort(arr,p+1,e);   //right side
}

int main(){
    cout<<"enter size of arr: ";
    int n;
    cin>>n;
    cout<<"Enter elements of array: "<<endl;
    int* arr= new int[n];        //for variable type array --> using concept of dynamic array & pointers
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    quick_sort(arr,0,4);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}