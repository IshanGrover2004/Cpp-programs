#include <stdio.h>


void display(int n,int arr[]){
    for (int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int arr[100];
    int key = 5,n;

    // Inputing the array
    printf("Enter the n: ");
    scanf("%d",&n);
    for (int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    // Linear search
    for (int i = 0; i<n;i++){
        if(arr[i] == key){
            printf("%d\n",i);
        }
    }
    return 0;
}