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

    int maximum=arr[0],minimum=arr[0];
    for (int i:arr){
        maximum = max(i,maximum);
        minimum = min(i,minimum);
    }
    cout<<"Max value is "<<maximum<<endl<<"Min value is "<<minimum<<endl;
}