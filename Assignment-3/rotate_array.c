#include<stdio.h>
#include<conio.h>

int main(){
    int arr[5]={1, 2, 3, 4, 5};
    int k =1;
    for(int i=1; i<=5-k; i++){
        int temp = arr[0];
        for(int j=0; j<5-1; j++){
            arr[j]=arr[j+1];
        }
        arr[5-1]=temp;
        
    }

    for(int i=0; i<5; i++){
        printf("%d ", arr[i]);
    }
   


        return 0;
}