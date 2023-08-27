#include <stdio.h>

// Factorial
int factorial(int n) {
  if (n == 0 || n == 1)
    return 1;
  else
    return n * factorial(n - 1);
}

// Fibonacci
int fibonacci(int n) {
  if (n == 1)
    return 0;
  else if (n == 2)
    return 1;
  else
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  int n = 5;

  // Factorial
  printf("factorial of 5 is : %d\n", factorial(n));
  // Fibonacci
  printf("5th term of Fibonacci series is : %d\n", fibonacci(n));
}