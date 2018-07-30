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

void bubble_sort(int n) {
    if(n == 1) return;
    
    for(int i = 0; i < n-1; i++) {
        if(data[i] > data[i+1]) {
            swap(&data[i], &data[i+1]);
            print_data();
        }
    }
    bubble_sort(n-1);
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
    
    puts("Bubble sort:");
    bubble_sort(n);
    puts("");

    puts("Result:");
    print_data();
}
