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

void selection_sort() {
    for(int i = 0; i < n; i++) {
        int min_idx = i;
        for(int j = i+1; j < n; j++) {
            if(data[min_idx] > data[j]) {
                min_idx = j;
            }
        }
        if(min_idx != i) {
            swap(&data[min_idx], &data[i]);
            print_data();
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
    
    puts("Selection sort:");
    selection_sort();
    puts("");

    puts("Result:");
    print_data();
}
