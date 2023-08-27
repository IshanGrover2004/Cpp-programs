#include <stdio.h>

int power(int num, int pow) {
  if (pow == 0) { // base condition
    return 1;
  }
  return num * power(num, pow - 1); // recursive call
}

int main() {
  printf("Power of 2 to the power 10 is : %d\n", power(2,10));
}