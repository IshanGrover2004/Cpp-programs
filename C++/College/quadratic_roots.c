#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c, D;

    printf("Enter coefficients a, b and c: ");
    scanf("%f %f %f", &a, &b, &c);

    D = b*b - 4*a*c;

    float x1, x2;
    float real, imaginary;

    if (D > 0) {
        x1 = (-b + sqrt(D)) / (2*a);
        x2 = (-b - sqrt(D)) / (2*a);
        printf("Roots are real and distinct\n");
        printf("x1 = %.2f and x2 = %.2f\n",x1, x2);
    }
    else if (D == 0) {
        x1 = x2 = -b / (2*a);
        printf("Roots are real and equal\n");
        printf("x1 = x2 = %.2f\n", x1);
    }
    else {
        real = -b / (2*a);
        imaginary = sqrt(-D) / (2*a);
        printf("Roots are imaginary\n");
        printf("x1 = %.2f + %.2fi and x2 = %.2f - %.2fi\n", real, imaginary, real, imaginary);
    }

    return 0;
}
