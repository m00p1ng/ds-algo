#include <cstdio>
#include "utils.cpp"
#define MAX 1000000

int n;
int data[MAX];

void insertion_sort(int s) {
    if(s == n) return;

    for(int j = s-1; j >= 0 && data[j+1] < data[j]; j--) {
        swap(&data[j+1], &data[j]);
    }
    print_array(data, n);

    insertion_sort(s+1);
}

int main() {
    input_data(data, &n);
    
    puts("Insertion sort:");
    insertion_sort(1);
    puts("");

    print_result(data, n);
}
