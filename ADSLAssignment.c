// Q1. Print "Hello, World!"
#include<stdio.h>

int main() {
    printf("Hello,World!");

    return 0;
}
// Q2. Swap Two Numbers
#include<stdio.h>

int main(){
    int a,b,temp;
    printf("Enter the value of a :");
    scanf("%d",&a);
    printf("Enter the value of b :");
    scanf("%d",&b);
    temp = a;
    a = b;
    b = temp;
    printf("Value after swap of numbers a = %d , b =%d" ,a,b);
}

//Q3. Check Even or Odd
#include <stdio.h>

int main() {
    printf("Enter the value of number :");
    int a;
    scanf("%d",&a);
    if (a % 2 == 0){
        printf("The value is even");
    }
    else{
        printf("The value is odd");
    }
        
    return 0;
}

//Q4. Find Largest of Three Numbers
#include <stdio.h>

int main() {
    int a,b,c;
    printf("Enter the value of a :");
    scanf("%d",&a);
    printf("Enter the value of b :");
    scanf("%d",&b);
    printf("Enter the value of c :");
    scanf("%d",&c);
    if(a > b && a>c){
        printf("a is largest");
    }
    else if (b > c && b > a) {
        printf("b is largest");
    }
    else{
        printf("c is largest");
    }

    return 0;
}
//Q5. Simple Calculator (switch case)
#include <stdio.h>

int main() {
    char operation;
    double n1, n2;

    printf("Enter an operator (+, -, *, /): ");
    scanf("%c", &operation);
    printf("Enter two operands: ");
    scanf("%lf %lf",&n1, &n2);

    switch(operation)
    {
        case '+':
            printf("%.1lf + %.1lf = %.1lf",n1, n2, n1+n2);
            break;

        case '-':
            printf("%.1lf - %.1lf = %.1lf",n1, n2, n1-n2);
            break;

        case '*':
            printf("%.1lf * %.1lf = %.1lf",n1, n2, n1*n2);
            break;

        case '/':
            printf("%.1lf / %.1lf = %.1lf",n1, n2, n1/n2);
            break;

        // operator doesn't match any case constant +, -, *, /
        default:
            printf("Error! operator is not correct");
    }

    return 0;
}
//Q6. Factorial of a Number
#include <stdio.h>
int main() {
    int fact = 1, n;
    printf("Enter the value of number: ");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        fact = fact * i;
    }
    printf("The value of factorial is : %d\n", fact);
    return 0;
}
//Q7. Fibonacci Series (first n terms)
#include <stdio.h>
int main() {
    int n, t1 = 0, t2 = 1, nextTerm;
    printf("Enter the number of Fibonacci terms: ");
    scanf("%d", &n);

    printf("First %d Fibonacci numbers are: ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");

    return 0;
}
//Q8. Reverse a Number
#include <stdio.h>

int main() {
    int number;
    int reverse = 0;
    int remainder;
    printf("Enter the number : ");
    scanf("%d",&number);
    while (number > 0){
        remainder = number %10;
        reverse = reverse * 10 + remainder;
        number = number /10;
    }
    printf("The reverse number is reverse = %d",reverse);
    return 0;
}
//Q9. Palindrome Number Check
#include <stdio.h>

int main() {
    printf("Enter the number : ");
    int number,reversed = 0,original,remainder;
    scanf("%d",&number);
    original = number;
    while (number > 0){
        remainder = number %10;
        reversed = reversed * 10 + remainder;
        number = number /10;
    }
    if(original == reversed){
        printf("The number is palingdrome");
    }
    else{
        printf("The number is not palingdrome");
    }
    

    return 0;
}
//Q10. Count Digits in a Number
#include <stdio.h>

int main() {
    int number,digits = 0;
    printf("Enter the value of number : ");
    scanf("%d",&number);
    while(number > 0){
        number  = number /10;
        digits ++;
    }
    printf("The number of digits is  %d: ",digits);

    return 0;
}

//Q11. Sum of Digits
#include <stdio.h>
int main() {
    int number, sum = 0, temp;
    printf("Enter the number: ");
    scanf("%d", &number);
    temp = number;  // Keep original number safe if needed

    while(temp > 0) {
        sum += temp % 10;  // Add last digit
        temp = temp / 10;  // Remove last digit
    }
    printf("The sum of digits is %d\n", number, sum);
    return 0;
}
//Q12. Check Prime Number
#include <stdio.h>

int main() {
    int number,count = 0;
    printf("Enter the value of number : ");
    scanf("%d",&number);
    for(int i = 1;i<=number;i++){
        if(number % i == 0){
            count++;
        }
    }
    if(count == 2){
        printf("The number is prime");
    }
    else{
        printf("The number is not prime");
    }

    return 0;
}
//Q13. Array – Find Maximum Element
#include <stdio.h>

int main() {
    int numbers[] = {10,30,40,20,90,70};
     int largest = numbers[0];
    int length = sizeof(numbers) / sizeof(numbers[0]);
    for(int i = 0;i<length;i++){
        if (numbers[i] > largest){
            largest = numbers[i];
        }
    }
    printf("The largest number in array is %d",largest);
    return 0;
}
//Q14. String – Count Vowels
#include <stdio.h>

int main() {
    char str[100];
    int count = 0;
    printf("Enter string : ");
    fgets(str,sizeof(str),stdin);
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            count++;
        }
    }
    printf("Number of vowels %d",count);

    return 0;
}
//Q15. Scenario – Electricity Bill Calculation
#include <stdio.h>

int main() {
    printf("Enter the number of units : ");
    int unit,bill = 0;
    scanf("%d",&unit);
    if (unit < 100){
        bill = unit * 5;
    }
    else if(unit > 100 && unit <= 200){
        bill = 100 * 5 + (unit - 100)*7;
    }
    else{
        bill = 100 * 5 + 100 * 7 + (unit - 200) *10;
    }
    printf("The total electricity bill is %d",bill);

    return 0;
}
//Q16. Factorial using Recursion
#include <stdio.h>

long factorial(int n){
    if (n == 0){
        return 1;
    }
    else{
        n * factorial(n-1);
    }
    
}
int main() {
    int num;
    printf("Enter a positive integer: ");
    scanf("%d", &num);

    if (num < 0)
        printf("Factorial of a negative number doesn't exist.\n");
    else
        printf("Factorial of %d is %ld\n", num, factorial(num));

    return 0;

    return 0;
}
//Q17. Fibonacci Series using Recursion
#include <stdio.h>
int fibbonacci(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    else{
        return fibbonacci(n-1) + fibbonacci(n-2);
    }
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci series: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibbonacci(i));
    }
    printf("\n");
    return 0;
}
//Q18. GCD (Greatest Common Divisor) using Recursion
#include <stdio.h>

// Recursive function to calculate GCD
int gcd(int a, int b) {
    if (b == 0)
        return a;               // Base case: when second number is 0, return the first
    return gcd(b, a % b);       // Recursive call: gcd(b, remainder of a divided by b)
}

int main() {
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    printf("GCD of %d and %d is %d\n", num1, num2, gcd(num1, num2));
    return 0;
}
//Q19. Sum of Digits using Recursion
#include <stdio.h>

// Recursive function to calculate sum of digits
int sumOfDigits(int n) {
    if (n == 0)
        return 0;  // Base case: no digits left
    return (n % 10) + sumOfDigits(n / 10);  // Add last digit + sum of remaining digits
}

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    // Handle negative numbers (optional)
    if (number < 0) number = -number;

    printf("Sum of digits: %d\n", sumOfDigits(number));
    return 0;
}
//Q20. Recursive Binary Search
#include <stdio.h>

// Recursive function to perform binary search
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high)
        return -1;  // Base case: target not found

    int mid = low + (high - low) / 2;

    if (arr[mid] == target)
        return mid;  // Target found at mid

    else if (arr[mid] < target)
        return binarySearch(arr, mid + 1, high, target); // Search right half

    else
        return binarySearch(arr, low, mid - 1, target);  // Search left half
}

int main() {
    int arr[] = {2, 4, 7, 10, 15, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target;

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, size - 1, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in the array\n");

    return 0;
}

