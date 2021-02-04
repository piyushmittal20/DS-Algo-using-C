#include <stdio.h>
#include <stdlib.h>

int linearSearch(int arr[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}

// Applicable only  for sorted array

int binarySearch(int arr[], int size, int element){
    int low, mid, high;
    low = 0;
    high = size-1;
    // Keep searching until low <= high
    while(low<=high){
        mid = (low + high)/2;
        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid]<element){
            low = mid+1;
        }
        else{
            high = mid -1;
        }
    } 
    return -1;
    
}


int main()
{
    int arr[] = {1, 2, 34, 56, 78};
    int element = 56;
    // int index = linearSearch(arr, 5, element);
    int size = (sizeof(arr) / sizeof(int));
    int index = binarySearch(arr, size, element);
    printf("%d ", index);

    return 0;
}
