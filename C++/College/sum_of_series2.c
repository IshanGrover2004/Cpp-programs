#include <math.h>
#include <stdio.h>

int factorial(int n) {
  int fact = 1;
  while (n > 0) {
    fact *= n;
    n--;
  }
  return fact;
}

int main() {
  int n, x;
  printf("\nEnter the no. of terms & value of x: ");
  scanf("%d %d", &n, &x);

  int sum = 1, count = 1;
  for (int i = 1; i <= n; i++) {
    int power = pow(x, i);
    if (count % 2 == 0)
      sum -= (power / factorial(i));
    else
      sum += (power / factorial(i));
    count++;
  }
  printf("%d", sum);
  return 0;
}