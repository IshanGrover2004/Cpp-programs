#include <stdio.h>
#include <math.h>

int main(){
    int a,b,result;
    char operator;
    
    printf("Enter the values of operands: ");
    scanf("%d %d",&a,&b);
    printf("Enter the OPERATOR: ");
    scanf("%ch",&operator);

    switch(operator){
        case '+':
            result=a+b;
            printf("%d",result);
            break;
        case '-':
            result=a-b;
            printf("%d %ch %d = %d",a,operator,b,result);
            break;
        case '%':
            result=a%b;
            printf("%d %ch %d = %d",a,operator,b,result);
            break;
        case '*':
            result=a*b;
            printf("%d %ch %d = %d",a,operator,b,result);
            break;
        case '^':
            result=pow(a,b);
            printf("%d %ch %d = %d",a,operator,b,result);
            break;
        
    }
    return 0;
}
