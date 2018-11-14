#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void pointer_example1() {
    int i = 3;
    int *p = &i;
    printf("The value of i = %d\n", i);
    printf("The value of i = %d\n", *p);
    printf("The address of i = %p\n", &i);
    printf("The address of i = %p\n", p);
    printf("The address of p = %p\n", &p);
}


void pointer_example2() {
    char letter = 'b';
    char sentence[100] = "2 words.";
    char *c_ptr1 = &letter;
    char *c_ptr2 = sentence;
    sentence[3] = 'i';
    c_ptr2[2] = *c_ptr1;
    
    printf("sentence = %s\n",sentence);
//    printf("c_ptr1 = %s\n",c_ptr1);
    printf("c_ptr2 = %s\n",c_ptr2);
}

void pointer_example3() {
    int number = 42;
    int lotto_picks[7] = {8, 18, 28, 38, 48, 58, 68};
    int *i_ptr1 = &number;
    int *i_ptr2 = lotto_picks;
    lotto_picks[3] = number;
    i_ptr1 = i_ptr2;
    i_ptr2[1] = *i_ptr1;
    
    for(int i = 0; i < 7; i++) {
        printf("%d ", lotto_picks[i]);
    } 
    printf("\n");
    
    for(int i = 0; i < 7; i++) {
        printf("%d ", i_ptr1[i]);
    } 
    printf("\n");
  
    for(int i = 0; i < 7; i++) {
        printf("%d ", i_ptr2[i]);
    } 
}

void swap_fail(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int swap_example() {
    printf("test 3:\n");
    int i2 = 1, j2 = 2;
    printf("%d %d\n", i2, j2);
//    swap(&i2, &j2);
    swap_fail(i2, j2);
    printf("%d %d\n", i2, j2);
    return 0;
}

int ArrayDemo1(char array[3][3]) {
    printf("ArrayDemo1\n");
    return 0;
}

int ArrayDemo2(char array[][3]) {
    printf("ArrayDemo2\n");
    return 0;
}

int ArrayDemo3(char (*array)[3]) {
    printf("ArrayDemo3\n");
    return 0;
}


int ArrayDemo4(char *array[4]) {
    printf("ArrayDemo4\n");
    return 0;
}

int ArrayDemo5(char *array[]) {
    printf("ArrayDemo5\n");
    return 0;
}

int ArrayDemo6(char **array) {
    printf("ArrayDemo6\n");
    return 0;
}

void PrintRow(int row, int height,int level) {
    if (level == 1) {
        int row_item_count = 2*height-1;
        char array[row_item_count+1];
        int star_count = 2*row+1;
        int space_around_count = (row_item_count - star_count)/2;
            
        for (int i =0; i< row_item_count; i++) {
            if (i<space_around_count) {
                array[i] = '-';
            }
            else if ( i > row_item_count-space_around_count-1) {
                array[i] = '-';
            }
            else
                array[i] = '*';
        }
        array[row_item_count] = '\0';
        printf("%s", array);
        return;
    }
    else if (row < height/2) {
        char space_arrary[height/2+1];
        for (int i = 0; i< height/2; i++) {
            space_arrary[i] = '-';
        }
        space_arrary[height/2] = '\0';
        printf("%s", space_arrary);
        PrintRow(row, height/2, level-1);
        printf("%s", space_arrary);
    }
    else {
        PrintRow(row-height/2, height/2, level-1);
        printf("-");
        PrintRow(row-height/2, height/2, level-1);
    }
    return;
}


int main (int argc, char** argv) {
//    char hello[3][3] = {"hi", "hi", "hi"};
//    pointer_example1();
//    pointer_example2();
//    pointer_example3();
//    swap_example();
//    
//    char hellos1[3][3] = {"hi", "yo", "ha"};
//    ArrayDemo1(hellos1);
//    ArrayDemo2(hellos1);
//    ArrayDemo3(hellos1);
    
    // sizeof return number of bytes
//    //char *array[3] is arrary of pointers
//    char *array1[3];
//    printf("%lu\n", sizeof(array1));
//    printf("%lu\n", sizeof(*array1));
//    char test_string1[4] = "hey";
//    array1[0] = test_string1;
//    
//    printf("---------\n");
////
////     char (*array)[3] pointer to data of type 3-length char array
//    char (*array2)[3];
//    printf("%lu\n", sizeof(array2));
//    printf("%lu\n", sizeof(*array2));
//    char test_string2[3] = "hi";
//    array2 = &test_string2;
//    return 0;
//    
//    char* hellos2[4] = {"hi", "yo", "bonjour", "hello"};
//    ArrayDemo4(hellos2);
//    ArrayDemo5(hellos2);
//    ArrayDemo6(hellos2);
    
    
//    int a[3] = {1, 2, 3};
////    int a = 123;
//    int* p = a;
//    printf("%d, %d, %d\n", p[0], *p, *a);
//    printf("%d, %d, %d\n", p[1], *(p+1), *(a+1));
//    printf("%d, %d\n", p[2], *(p+2));
//    printf("%d, %d\n", p[3], *(p+3));
//  
    
    // pointer_conversion
//    int* p;
//    int a = 257;
//    p = &a;
    
//    int i = 3;
//    float j = 3.14;
//    int* p;
////    p = &j; // no - need to cast
//    p = (int*)&j; // yes
//    printf("%d\n", *(int*)(p));
   
//    int* p;
//    char a[4];
//    memset(a, '\0', 4);
//    printf("a = %s", a);
//    p = (int*) a;
    
//    // my computer is little endian
//    char *p;
//    int a = 257;
//    p = (char*)&a;
//    printf( "The value at p is %d.\n", *p );
//    printf( "The value at p+1 is %d.\n", *(p+1) );
//    printf( "The value at p+2 is %d.\n", *(p+2) );
//    printf( "The value at p+3 is %d.\n", *(p+3) );
    
    
    
    int arr[]  = {10, 20, 30, 40, 50, 60};
    int *ptr1 = arr;
    int *ptr2 = arr + 5;
    printf("Number of elements between two pointers are %d\n", (ptr2 - ptr1));
    printf("Number of bytes between two pointers are %d\n", (char*)ptr2 - (char*)ptr1);
    printf("Value difference is %d, %d\n", (*ptr2), (*ptr1));
    return  0;
}