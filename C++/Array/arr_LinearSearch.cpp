#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    //Inputing array
    int arr[n];
    cout<<"Input the array elements: ";
    for (int &ele:arr){
        cin>>ele;
    }

    int key;
    cout<<"Enter a no. you want to find in array: ";
    cin>>key;

    bool found=false;
    for (int i:arr){
        if (key==i){
            found=true;
            break;
        }
    }

    if (found){
        cout<<"no. found";
    }
    else{
        cout<<"no. not found";
    }
}