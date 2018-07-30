#include <cstdio>
#define MAX 1000000

int n;
int data[MAX];
int temp[MAX];

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

void merge_proc(int left, int mid, int right) {
    int l = left;
    int r = mid+1;
    int i = left;
    while(l <= mid && r <= right) {
        if(data[l] < data[r]) {
            temp[i] = data[l++];
        } else {
            temp[i] = data[r++];
        }
        i++;
    }

    while(l <= mid) {
        temp[i++] = data[l++];
    }

    while(r <= right) {
        temp[i++] = data[r++];
    }

    for(int i = left; i <= right; i++) {
        data[i] = temp[i];
    }
}

void merge_sort(int left, int right) {
    if(left >= right) return;

    int mid = (left + right)/2;
    merge_sort(left, mid);
    merge_sort(mid+1, right);

    merge_proc(left, mid, right);
    
    print_data();
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
    
    puts("Merge sort:");
    merge_sort(0, n-1);
    puts("");

    puts("Result:");
    print_data();
}
