#include <stdio.h>

int main(){
    int a,b,c;
    printf("Enter the values: ");
    scanf("%d %d %d",&a,&b,&c);

    int greatest;
    if(a>b){
        if (a>c){
            greatest=a;
        }
        else{
            greatest=c;
        }
    }
    else{
        if(b>c){
            greatest=b;
        }
        else{
            greatest=c;
        }
    }
    printf("Greatest value is %d",greatest);
    return 0;
}