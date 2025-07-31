#include <stdio.h>
#include <stdlib.h>  // Required for abs()
// Function to count number of digits in a number
int count_digits(int n) {
    n = abs(n);  // to handle negative numbers
    if(n==0){
        return 1;
    }
    int count = 0;
    // printf("%d\n", count);
    while(n > 0) {
            count++;
             n /= 10; 
        
    }
    return count;
}
void main() {
    int n;
    printf("Enter a number to count its digits: ");
    scanf("%d", &n);
    int result = count_digits(n);
    printf("Number of digits in %d is %d\n", n, result);
}