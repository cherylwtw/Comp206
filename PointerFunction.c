#include<stdio.h>

void add(int a, int b) {
    printf("%d\n", (a+b));
}

int compare_strings(void* a, void* b) {
    return strcmp((char*)a, (char*)b);
} 

int compare_ints(void* a, void* b) {
    return a == b;
}


int main(void) {
    // example 1
    void (*p)(int, int);
    
    p = &add;
    p(5, 5);
    
    // example 2
    int (*comparison)(void*, void*);
    
    int* ptr_a;
    int* ptr_b;
    int a = 1;
    int b = 2;
    ptr_a = &a;
    ptr_b = &b;
    
    comparison = &compare_ints;
    int equal_int =comparison(a, b);
    printf("%d\n", equal_int);
    
    char* ptr_a_str = "aaa";
    char* ptr_b_str = "abc";
    comparison = &compare_strings;
    int equal_str =comparison(ptr_a_str, ptr_b_str);
    printf("%d\n", equal_str);
    return 0;
}