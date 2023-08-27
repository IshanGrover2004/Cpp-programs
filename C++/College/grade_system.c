#include <stdio.h>

int main(){
    int a,b,c,d,e;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
    int marks=(a+b+c+d+e)*0.2;
    if (((a>100) || (a<0)) || ((b>100) || (b<0)) || ((c>100) || (c<0)) || ((d>100) || (d<0)) || ((e>100) || (e<0)))
    {
        printf("Invalid Score");
    }
    else
    {
        if(marks<60)
        {
            printf("D");
        }
        else if(marks>=60 && marks<80)
        {
            printf("C");
        }
        else if(marks>=80 && marks<90)
        {
            printf("B");
        }
        else
        {
            printf("A");
        }
    }
    return 0;
}