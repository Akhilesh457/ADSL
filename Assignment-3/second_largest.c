#include<stdio.h>
#include<conio.h>

int main(){
    int arr[6]={2, 4, 6, 5, 6, 8};
    int largest=arr[0], second_largest=-1;
    for(int i=1; i<6; i++){
        if(arr[i]>largest){
            second_largest = largest;
            largest= arr[i];
        }

    }
    printf("%d", second_largest);


        return 0;
}