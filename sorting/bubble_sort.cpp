#include <cstdio>
#include "utils.cpp"
#define MAX 1000000

int n;
int data[MAX];

void bubble_sort() {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(data[j] > data[j+1]) {
                swap(&data[j], &data[j+1]);
                print_array(data, n);
            }
        }
    }
}

int main() {
    input_data(data, &n);
    
    puts("Bubble sort:");
    bubble_sort();
    puts("");

    print_result(data, n);
}
