// Created by Ishan grover on 06-04-2023.
//creating recursive function for powering any number
#include <iostream>
using namespace std;

int power(int num,int pow){
    if (pow==0){       //base condition
        return 1;
    }
    return num*power(num,pow-1);        //recursive call
}
/* Optimised soln--> first check power is odd or even for " pow(a,b)=a^b "
    even --> return a^(b/2) * a^(b/2)  
    odd --> rteurn a * odd ans*/

int main() {

    int n,pow;
    cin>>n>>pow;
    cout<<power(n,pow)<<endl;
}
