#include <stdio.h>
// Function to calculate sum of digits
int sum_of_digits(int n) {
    int sum = 0;
    while(n>0){
        sum+= n % 10;
        n /= 10;
    }
    return sum;
}
void main() {
    int n;
    printf("Enter a number to calculate the sum of its digits: ");
    scanf("%d", &n);
    int result = sum_of_digits(n);
    printf("Sum of digits of %d is %d", n, result);
}