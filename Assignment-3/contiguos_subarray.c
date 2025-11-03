#include<stdio.h>
#include<conio.h>
#include<limits.h>
#include<math.h>


int max(int a, int b){
    return (a>b)?a:b;
}

int main(){
    int arr[9]={-2,1,-3,4,-1,2,1,-5,4};
    int res = 6;
    int j=0;
    int maxi=INT_MIN, sum=0;
    for(int i=0; i<9; i++){
        if(sum == res){
            printf("%d %d", j, i-1);
            break;
        }
        else{
        sum=max(arr[i],sum+arr[i]);
        if(sum==arr[i]){
            j=i;
        }
        maxi=max(maxi,sum);
        }
    }
    


        return 0;
}