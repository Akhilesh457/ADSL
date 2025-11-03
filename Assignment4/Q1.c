/*Write a program to swap two complex numbers using a struct.*/
#include <stdio.h>

struct Complex {
    float real;
    float imag;
};

int main() {
    struct Complex num1, num2, temp;

    printf("Enter real and imaginary parts of first complex number: ");
    scanf("%f %f", &num1.real, &num1.imag);

    printf("Enter real and imaginary parts of second complex number: ");
    scanf("%f %f", &num2.real, &num2.imag);

    temp = num1;
    num1 = num2;
    num2 = temp;

    printf("After swapping:\n");
    printf("First complex number: %.2f + %.2fi\n", num1.real, num1.imag);
    printf("Second complex number: %.2f + %.2fi\n", num2.real, num2.imag);

    return 0;
}
