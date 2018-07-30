#include <cstdio>
#include "utils.cpp"
#define MAX 1000000

int n;
int data[MAX];

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
            print_array(data, n);
        }
    }
}

int main() {
    input_data(data, &n);
    
    puts("Selection sort:");
    selection_sort();
    puts("");

    print_result(data, n);
}
