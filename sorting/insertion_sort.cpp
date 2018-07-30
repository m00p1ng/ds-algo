#include <cstdio>
#include "utils.cpp"
#define MAX 1000000

int n;
int data[MAX];

void insertion_sort() {
    for(int i = 1; i < n; i++) {
        for(int j = i-1; j >= 0 && data[j+1] < data[j]; j--) {
            swap(&data[j+1], &data[j]);
        }
        print_array(data, n);
    }
}

int main() {
    input_data(data, &n);
    
    puts("Insertion sort:");
    insertion_sort();
    puts("");

    print_result(data, n);
}
