#include <stdio.h>

void bubbleSort(int arr[], int n, int *totalSwaps) {
    int temp;
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                (*totalSwaps)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int *totalSwaps) {
    int minIndex, temp;
    for(int i=0;i<n-1;i++) {
        minIndex=i;
        for(int j=i+1;j<n;j++) {
            if(arr[j]<arr[minIndex]) {
                minIndex=j;
            }
        }
        if(minIndex!=i) {
            temp=arr[minIndex];
            arr[minIndex]=arr[i];
            arr[i]=temp;
            (*totalSwaps)++;
        }
    }
}

int main() {
    int array1[]={97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[]={90, 80, 70, 60, 50, 40, 30, 20, 10};
    int a1= sizeof(array1)/sizeof(array1[0]);
    int a2= sizeof(array2)/sizeof(array2[0]);
    int totalSwaps1=0;
    int totalSwaps2= 0;

    printf("array1:\n");
    for(int i=0;i<a1;i++) {
        int swaps=0;
        bubbleSort(array1,a1, &swaps);
        printf("%d: %d\n",array1[i], swaps);
        totalSwaps1+=swaps;
    }
    printf("total swaps: %d\n", totalSwaps1);

    printf("\narray2:\n");
    for(int i=0;i<a2;i++) {
        int swaps=0;
        selectionSort(array2,a2, &swaps);
        printf("%d: %d\n", array2[i], swaps);
        totalSwaps2+=swaps;
    }
    printf("total swaps: %d\n", totalSwaps2);

    return 0;
}