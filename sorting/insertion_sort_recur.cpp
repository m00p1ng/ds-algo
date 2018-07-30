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

void insertion_sort(int s) {
    if(s == n) return;

    for(int j = s-1; j >= 0 && data[j+1] < data[j]; j--) {
        swap(&data[j+1], &data[j]);
    }
    print_data();

    insertion_sort(s+1);
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
    insertion_sort(1);
    puts("");

    puts("Result:");
    print_data();
}
