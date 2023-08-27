//Reverse the string using recursion only
// Created by Ishan grover on 09-04-2023.

#include <iostream>
using namespace std;

void reverse(string& str,int s,int e){     // & is applied for the string will change in main function also
    if (s>e){
        return ;
    }
    swap(str[s],str[e]);
    s++; 
    e--;
    
    reverse(str,s,e);     //Recursive call
}

int main() {
    string str="hello";
    reverse(str,0,str.length()-1);
    cout<<str<<endl;
    return 0;
}
