#include <stdio.h>

int factorial(int n){
    int fact=1;
    while (n>0){
        fact*=n;
        n--;
    }
    return fact;
}

int main(){
    int n;
    printf("\nEnter the no. of terms : ");
    scanf("%d",&n);
    
    int sum = 0;
    while(n>0){
        sum+=factorial(n);
        n--;
    }
    printf("sum is: %d\n\n",sum);
    return 0;
}