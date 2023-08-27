#include <stdio.h>
#include <math.h>

int main(){
    float A,s,a,b,c;
    scanf("%f %f %f",&a,&b,&c);
    s=(a+b+c)*0.5;
    A=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("the area is %.02f",A);
}