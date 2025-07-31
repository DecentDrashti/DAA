#include <stdio.h>
// Function to calculate factorial
unsigned long long factorial(int n)
{
    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 0;
    }
    else if( n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
    // Alternatively, you can use an iterative approach:
    // unsigned long long result = 1;
    // for (int i = 1; i <= n; i++) {
    //     result *= i;
    // }
    // return result;
}
void main()
{
    int n;
    printf("Enter the number of which you need the factorial: ");
    scanf("%d", &n);
    unsigned long long result = factorial(n);
    printf("Factorial of %d is %llu", n, result);
    // Note: %llu is used for unsigned long long in printf
}