#include <stdio.h>

int main() {
    int a,b;

	scanf("%d %d",&a,&b);

	int x=a;

	a=b;

	b=x;

	printf("%d %d",a,b);
    return 0;
}
