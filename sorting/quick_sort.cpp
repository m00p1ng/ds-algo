#include <cstdio>
#include "utils.cpp"
#define MAX 1000000

int n;
int data[MAX];

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

    print_array(data, n);

    quick_sort(left, mid-1);
    quick_sort(mid+1, right);
}

int main() {
    input_data(data, &n);

    puts("Quick sort:");
    quick_sort(0, n-1);
    puts("");

    print_resuilt(data, &n);
}
