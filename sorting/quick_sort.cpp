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

int partition(int left, int right) {
    int pivot_val = data[left];
    int i = left;
    int j = right + 1;

    while(i < j) {
        while(data[++i] < pivot_val && i != right);
        while(data[--j] > pivot_val);
        if(i < j) {
            swap(&data[i], &data[j]);
        }
    }
    swap(&data[left], &data[j]);

    return j;
}

void quick_sort(int left, int right) {
    if(left >= right) return;

    int mid = partition(left, right);

    print_data();

    quick_sort(left, mid-1);
    quick_sort(mid+1, right);
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
    
    puts("Quick sort:");
    quick_sort(0, n-1);
    puts("");

    puts("Result:");
    print_data();
}
