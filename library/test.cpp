#include "stdio.h"

int main() {
    int arr[10];
    printf("%x %x\n", &arr, (&arr) + 1);
    printf("%x %x\n", arr, arr + 1);
    printf("%x %x\n", &arr[0], &arr[1]);
    getchar();
    return 0;
}