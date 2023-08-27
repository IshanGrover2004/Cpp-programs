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

    int sum=0;
    for (int i:arr){
        sum += i;
    }
    cout<<"Sum of all elements in array is: "<<sum;
}