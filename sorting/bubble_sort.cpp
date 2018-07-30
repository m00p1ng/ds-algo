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

void bubble_sort() {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(data[j] > data[j+1]) {
                swap(&data[j], &data[j+1]);
                print_data();
            }
        }
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
    
    puts("Bubble sort:");
    bubble_sort();
    puts("");

    puts("Result:");
    print_data();
}
