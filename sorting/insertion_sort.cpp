#include <cstdio>
#define MAX 1000000

int n;
int data[MAX];

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_data() {
    printf("   ");
    for(int i = 0; i < n; i++) {
        printf("%2d ", data[i]);
    }
    puts("");
}

void insertion_sort() {
    for(int i = 1; i < n; i++) {
        for(int j = i-1; j >= 0 && data[j+1] < data[j]; j--) {
            swap(&data[j+1], &data[j]);
        }
        print_data();
    }
}

int main() {
    freopen("data/in", "r", stdin);

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    puts("Original:");
    print_data();
    puts("");
    
    puts("Insertion sort:");
    insertion_sort();
    puts("");

    puts("Result:");
    print_data();
}
