//Question 1 sum of elements in an array
#include <stdio.h>

int main() {
    int arr[] = {2,3,5,8,7,3};
    int sum = 0;
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0;i<n;i++){
        sum += arr[i];
    }
    printf("THe value of sum is %d: ",sum);

    return 0;
}
//recursive version
#include <stdio.h>
int recursivesum(int arr[],int n){
    if (n == 0){
        return n;
    }
    return arr[0] + recursivesum(arr+1,n-1);
}
int main() {
    int arr[] = {2,3,5,8,7,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = recursivesum(arr,n);
    printf("The value of sum is %d",sum);

    return 0;
}
//Question 2 find maximum element in an array
#include <stdio.h>

int main() {
    int arr[] = {5,3,1,9,6,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maximum = arr[0];
    for(int i = 1;i<n;i++){
        if (arr[i] > maximum){
            maximum = arr[i];
        }
        
    }
    printf("the maximum value is %d",maximum);

    return 0;
}
//b) Can you find it by first sorting the array and taking the last element?
#include <stdio.h>

void selectionsort(int arr[],int n){
    for(int i = 0;i<n-1;i++){
        int minindex = i;
        //Find the minimum element in unsorted array
        for (int j = i+1;j<n;j++){
            if (arr[j] < arr[minindex]){
                minindex = j;
            }
        }
        // Swap the found minimum element with the first element
        int temp = arr[minindex];
        arr[minindex] = arr[i];
        arr[i] = temp;
        
    }
}
int main() {
    int arr[] = {5,3,1,9,6,4};
    int n = sizeof(arr) /sizeof(arr[0]);
    selectionsort(arr,n);
    int maximum = arr[n-1];
    printf("The maximum value is %d",maximum);

    return 0;
}
//Question 3 Reverse a String
#include <stdio.h>
#include <string.h>

int main() {
    char name[20] = "Akhilesh";
    int left = 0;
    int right = strlen(name) - 1;
    while (left < right){
        char temp = name[left];
        name[left] = name[right];
        name[right] = temp;
        left++;
        right--;
    }
    printf("The value of name is %s",name);
    return 0;
}
//Reverse by creating a new array (O(n), O(n))
#include <stdio.h>
#include <string.h>
int main() {
    char name[20] = "Akhilesh";
    int n = strlen(name);
    char reverse_name[20];
    for (int i = 0;i<n;i++){
        reverse_name[i] = name[n-i-1];
    }
    reverse_name[n] = '\0';
    printf("Thr reverse name is %s ",reverse_name);
    return 0;
}
//Question 4 

//a) Using modulo operator (O(1))
#include <stdio.h>

int main() {
    int n;
    printf("Enter the value of a number");
    scanf("%d",&n);
    if (n%2 == 0){
        printf("The number is even");
    }
    else{
        printf("The number is odd ");
    }
    return 0;
}
//b Using bitwise AND (n & 1) (O (1)).
#include<stdio.h>

int main(){
    int n;
    printf("Enter the value of number :");
    scanf("%d",&n);
    if((n&1) == 0){
        printf("The number is even");
    }
    else{
        printf("The number is odd");
    }
    return 0;
}
//Question 5 Factorial of a Number
//Iterative method (O(n), O(1))
#include <stdio.h>

int main() {
    int fact = 1;
    int n;
    printf("Enter the number for factorial : ");
    scanf("%d",&n);
    for(int i =1;i<=n;i++){
        fact = fact* i;
    }
    printf("the factorial of a number is %d :", fact);

    return 0;
}
//Recursive method (O(n), O(n) for call stack)
#include <stdio.h>
int factorial(int n){
    if (n == 0 || n == 1){
        return 1;
    }
    return n * factorial(n-1);
}
int main() {
   int n;
   printf("The number for factorial is : ");
   scanf("%d",&n);
   factorial(n);
   printf("THe factorial of %d is %d: ",n,factorial(n));

    return 0;
}
//Question 6 Implement basic linear search
#include <stdio.h>

int main() {
    int customer_id[] = {1,5,8,9,4,7,6};
    int n = sizeof(customer_id) / sizeof(customer_id[0]);
    int found = 0;
    int id;
    printf("Enter the customer id : ");
    scanf("%d",&id);
    for (int i = 0;i < n;i++ ){
        if (id == customer_id[i]){
            found = 1;
            break;
        }
    }
    if (found){
        printf("Customer id found");
    }else{
        printf("Customer id not found");
    }

    return 0;
}
// Optimize by using sentinel method to reduce comparisons (still O(n), but fewer operations
#include <stdio.h>

int linearSearchWithSentinel(int arr[], int n, int target) {
    int last = arr[n - 1];
    arr[n - 1] = target;  // Set sentinel

    int i = 0;
    while (arr[i] != target) {
        i++;
    }

    arr[n - 1] = last;  // Restore last element

    if (i < n - 1 || arr[n - 1] == target) {
        return i;  // Target found
    }
    return -1;  // Target not found
}

int main() {
    int arr[] = {4, 2, 3, 7, 8, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int index = linearSearchWithSentinel(arr, n, target);
    if (index != -1) {
        printf("Element %d found at index: %d\n", target, index);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}

//Question 7 
//Using a simple for loop (O(n), O(1))
#include <stdio.h>

int main() {
    int n ;
    printf("Enter the first n natural number : ");
    scanf("%d",&n);
    for (int i = 1;i<n;i++){
        printf("%d",i);
    }
    

    return 0;
}
//Using recursion (O(n), O(n))
#include <stdio.h>
void natural_numbers(int n){
    if(n == 0){
        return;
    }
    natural_numbers(n-1);
    printf("%d",n);
}
int main() {
    int n;
    printf("Enter the number of natural numbers to print: ");
    scanf("%d", &n);
    
    natural_numbers(n);  // Start recursion
    
    printf("\n");

    return 0;
}
//Question 8 count vowels in a string
#include <stdio.h>

int main() {
    char str[20] = "countvowelsinthis";
    int vowel_count = 0;

    for (int i = 0; str[i] != '\0'; i++) {  // iterate till null terminator
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' ||
            str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
            vowel_count++;
        }
    }

    printf("The number of vowels is %d\n", vowel_count);

    return 0;
}
//b
#include <stdio.h>
#include <string.h>

int countVowels(const char *str) {
    // Lookup table to mark vowels
    int vowelLookup[256] = {0};
    vowelLookup['a'] = 1;
    vowelLookup['e'] = 1;
    vowelLookup['i'] = 1;
    vowelLookup['o'] = 1;
    vowelLookup['u'] = 1;
    vowelLookup['A'] = 1;
    vowelLookup['E'] = 1;
    vowelLookup['I'] = 1;
    vowelLookup['O'] = 1;
    vowelLookup['U'] = 1;

    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (vowelLookup[(unsigned char)str[i]]) {
            count++;
        }
    }
    return count;
}

int main() {
    const char *text = "Hello, World! This is an example string.";
    int vowelCount = countVowels(text);
    printf("Number of vowels in the string: %d\n", vowelCount);
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countVowelsLookup(const char *str) {
    int lookup[256] = {0};
    
    // Mark vowels in lookup table
    lookup['a'] = lookup['A'] = 1;
    lookup['e'] = lookup['E'] = 1;
    lookup['i'] = lookup['I'] = 1;
    lookup['o'] = lookup['O'] = 1;
    lookup['u'] = lookup['U'] = 1;

    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (lookup[(unsigned char)str[i]]) {
            count++;
        }
    }
    return count;
}

int main() {
    char text[] = "countvowelsinthis";
    printf("Count (Lookup Table): %d\n", countVowelsLookup(text));
    return 0;
}

//Question 9
//a) Using arithmetic (a = a + b; b = a - b; a = a - b)
#include <stdio.h>

int main() {
    int a = 5, b = 10;

    // Swap using addition and subtraction
    a = a + b;  // a now becomes 15
    b = a - b;  // b becomes 15 - 10 = 5
    a = a - b;  // a becomes 15 - 5 = 10

    printf("After swapping: a = %d, b = %d\n", a, b);
    return 0;
}
//Using bitwise XOR (a = a ^ b; b = a ^ b; a = a ^ b)

#include <stdio.h>

int main() {
    int a = 5, b = 9;
    
    printf("Before swap: a = %d, b = %d\n", a, b);
    
    // Swap using XOR
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    
    printf("After swap: a = %d, b = %d\n", a, b);
    
    return 0;
}


//Question 10
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Method a) Using string conversion
bool is_palindrome_str(int num) {
    char str[20]; // large enough to hold int
    sprintf(str, "%d", num);
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i])
            return false;
    }
    return true;
}

// Method b) Mathematical method without string conversion
bool is_palindrome_math(int num) {
    if (num < 0) return false;
    int original_num = num;
    int reversed_num = 0;
    while (num > 0) {
        reversed_num = reversed_num * 10 + num % 10;
        num /= 10;
    }
    return original_num == reversed_num;
}

int main() {
    int test_numbers[] = {121, 12321, 123, 10, 989, 0, -121};
    int n = sizeof(test_numbers) / sizeof(test_numbers[0]);

    printf("Checking palindrome numbers with string method:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %s\n", test_numbers[i], is_palindrome_str(test_numbers[i]) ? "True" : "False");
    }

    printf("\nChecking palindrome numbers with mathematical method:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %s\n", test_numbers[i], is_palindrome_math(test_numbers[i]) ? "True" : "False");
    }

    return 0;
}
