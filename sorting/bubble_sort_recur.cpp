#include <cstdio>
#include "utils.cpp"
#define MAX 1000000

int n;
int data[MAX];

void bubble_sort(int s) {
    if(s == 1) return;
    
    for(int i = 0; i < s-1; i++) {
        if(data[i] > data[i+1]) {
            swap(&data[i], &data[i+1]);
            print_array(data, n);
        }
    }
    bubble_sort(s-1);
}

int main() {
    input_data(data, &n);
    
    puts("Bubble sort:");
    bubble_sort(n);
    puts("");

    print_result(data, n);
}
