// Bubble sort
#include <stdio.h>

void swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void display(int n,int arr[]){
    for (int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int n=6,arr[]={1,6,3,7,2,9};
    printf("Unsorted array is : ");
    display(n,arr);
    
    // Bubble sort algorithm
    for (int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if (arr[j]>arr[j+1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    printf("Sorted array is : ");
    display(n,arr);
}