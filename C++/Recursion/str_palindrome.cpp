//Checks the string is palindrome or not
// Created by Ishan grover on 09-04-2023.

#include <iostream>
using namespace std;

bool isPalindrome(string str,int s,int e){
    if (s>e){             //this is the case --. jab e-- or s++ hote hue s>e ho jae to tb humko loop ya recursion khtm krna ha ==> return palindrome kuki bich tak pahucha ha to sare operation me true hi rha hoga
        return true;         //Base condition
    }

    if(str[s] != str[e]){      //Always find all the false cases and write it down --> to prove there is no false left that's why its true
        return false;
    }
    else{
        return isPalindrome(str,s+1,e-1);
    }
}

int main() {
    string str="dhd";
    if (isPalindrome(str , 0 , str.length() - 1)){
        cout<<"It is Palindrome"<<endl;
    }
    else{
        cout<<"Not Palindrome"<<endl;
    }
    return 0;
}
