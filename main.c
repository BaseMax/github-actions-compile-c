#include <stdio.h>

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

int main() {
    printf("Hello, GitHub Actions!\n");

    int num = 5;
    printf("Factorial of %d is %d\n", num, factorial(num));
    
    return 0;
}
