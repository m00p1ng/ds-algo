#include <cstdio>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *arr, int size) {
    printf("   ");
    for(int i = 0; i < size; i++) {
        printf("%2d ", arr[i]);
    }
    puts("");
}

void print_original(int *arr, int size) {
    puts("Original:");
    print_array(arr, size);
    puts("");
}

void print_result(int *arr, int size) {
    puts("Result:");
    print_array(arr, size);
}

void input_data(int *arr, int* size) {
    freopen("data/in", "r", stdin);

    scanf("%d", size);
    for(int i = 0; i < *size; i++) {
        scanf("%d", &arr[i]);
    }

    print_original(arr, *size);
}
