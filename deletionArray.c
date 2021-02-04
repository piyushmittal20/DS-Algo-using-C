#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int deletionArray(int arr[], int n, int index) {
    for(int i = index; i < n; i++) {
        arr[i] = arr[i+1];
    }
}

int main()
{
    int arr[100] = {1, 2, 4, 6, 5};
    int index = 3, size = 5;
    display(arr, size);
    deletionArray(arr, size, index);
    size -= 1;
    display(arr, size);

    return 0;
}
