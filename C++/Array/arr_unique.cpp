/* Problem --> array contain a pair of same elements and a single unique elemnt, we need to find out
   and print that no. 
   eg. {1,1,2,2,3,3,4} =>  O/P - 4 
*/

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

    int unique=0;
    for (int i:arr){
        unique^=i;    //Logic is same as (1-1+2-2+3-3+4) = (1^1^2^2^3^3^4) = 4
    }                    // Bcs x^x=0 and 0^x=x   =>  1^1=0 and 0^4=4 
    cout<<unique;
}