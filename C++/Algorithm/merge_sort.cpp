#include <iostream>
using namespace std;

//MERGE Function
void merge(int *arr, int start, int mid, int end){
    int i=start,j=mid+1,k=0;
    int* res= new int[end-start+1];

    while(i<=mid && j<=end){          //this is the condition of start<end for 2 broken array to be sorted
        if (arr[i]<arr[j]){
            res[k]=arr[i];       // "i"th element is smaller so added in res arr
            i++;
            k++;
        }
        else{
            res[k]=arr[j];
            j++;
            k++;
        }
    }
   
//if arr1 elements are exhausted but arr2 elements are still available to put in res array then.........
    if(i>mid){
        while(j<=end){
            res[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
            res[k]=arr[i];
            i++;
            k++;
        }
    }
    // Copy the sorted elements back to arr
    for (int x=0;x<k;x++){
        arr[start+x]=res[x];
    }
   
    delete [] res; // deallocate the memory
}
 
//MERGE_SORT Function
void merge_sort(int *arr,int start, int end){
    if(start>=end){
        return ;
    }
    
    int mid = start + (end-start)/2;
 
    //Recursion broke the array from mid point
    merge_sort(arr,start,mid);       //Left side
    merge_sort(arr,mid+1,end);      //Right side
 
    //Merge the above broken sorted array
    merge(arr,start,mid,end);
 
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
    merge_sort(arr,0,n-1);
    cout<<"sorted array is :  "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}