#include <cstdio>
#include "utils.cpp"
#define MAX 1000000

int n;
int data[MAX];
int temp[MAX];

void merge(int left, int mid, int right) {
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
    
    print_array(data, n);
}

int main() {
    input_data(data, &n);
    
    puts("Merge sort:");
    merge_sort(0, n-1);
    puts("");

    print_result(data, n);
}
