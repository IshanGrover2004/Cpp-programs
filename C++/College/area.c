#include <stdio.h>

int main() {
    int choice, length, width, radius, base, height;
    float area;

    printf("Select a geometrical figure to calculate its area:\n");
    printf("1. Square\n");
    printf("2. Rectangle\n");
    printf("3. Circle\n");
    printf("4. Triangle\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter the length of a side of the square: ");
            scanf("%d", &length);
            area = length * length;
            printf("The area of the square is: %.2f", area);
            break;
        case 2:
            printf("Enter the length of the rectangle: ");
            scanf("%d", &length);
            printf("Enter the width of the rectangle: ");
            scanf("%d", &width);
            area = length * width;
            printf("The area of the rectangle is: %.2f", area);
            break;
        case 3:
            printf("Enter the radius of the circle: ");
            scanf("%d", &radius);
            area = 3.14 * radius * radius;
            printf("The area of the circle is: %.2f", area);
            break;
        case 4:
            printf("Enter the base of the triangle: ");
            scanf("%d", &base);
            printf("Enter the height of the triangle: ");
            scanf("%d", &height);
            area = 0.5 * base * height;
            printf("The area of the triangle is: %.2f", area);
            break;
        default:
            printf("Invalid choice!");
            break;
    }

    return 0;
}
