//BINARY SEARCH PROGRAM
//Created by Ishan on 29-03-2023.
//Binary search --> search a element in array by using key reference but by different method
/*How it works?   1. find first the mid value of array by (begin + end index)/2
                  2. mid value make 2 parts(left & right), then both parts value compare with key value and take decision to go to which part(left or right).
                  3. take all element of that part and then find the mid element again and apply all step again till the mid value == key. */
#include <iostream>
using namespace std;

int binary_search(int size,int key){
    int arr[size];
    cout<<"Enter the elements of array"<<endl;
    for (int &ele:arr){
        cin>>ele;
    }
    int start=0, end=size-1;

    while (start<end){
        int mid=(start+end)/2;
        if (key==arr[mid]){
            return mid;
        }
        else if (key<arr[mid]){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return -1;
}

int main() {
    int size,key;
    cout<<"what's the size of array: "<<endl;
    cin>>size;
    cout<<"Enter the key value: "<<endl;
    cin>>key;

    int ans=binary_search(size,key);
    if (ans==-1){
        cout<<"Key not found"<<endl;
    }
    else{
        cout<<"key is at index: "<<ans;
    }
    return 0;
}