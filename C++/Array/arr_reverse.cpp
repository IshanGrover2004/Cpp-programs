#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    //Declaring and input array
    int arr[n];
    cout<<"Input the array elements: ";
    for (int &ele:arr){
        cin>>ele;
    }

    int rev_arr[n];
    for (int i=n-1;i>=0;i--){
        rev_arr[n-i-1]=arr[i];
    }
    
    for(int j:rev_arr){
        cout<<j<<" ";
    }
}