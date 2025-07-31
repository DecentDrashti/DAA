#include <stdio.h>
// Function to calculate power of a number
double power(double base, int exponent) {
    if (exponent < 0) {
        printf("Exponent should be a non-negative integer.\n");
        return 0;
    }
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
void main() {
    double base;
    int exponent;
    printf("Enter the base number: ");
    scanf("%lf", &base);
    printf("Enter the exponent (non-negative integer): ");
    scanf("%d", &exponent);
    
    double result = power(base, exponent);
    if (exponent >= 0) {
        printf("%.2lf raised to the power of %d is %.2lf\n", base, exponent, result);
    }
}
