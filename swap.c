#include<stdio.h>
 
// method 1 (no good): swap values in a separate function
void swap_fail_1(int x_val, int y_val) {
    int temp;
    temp = x_val;
    x_val = y_val;
    y_val = temp;
}

// method 2 (no good): swap pointer values in a separate function
void swap_fail_2 (int *x, int *y)
{
    printf("before: pointer x and y values: (%d, %d)\n", x, y);
    printf("before: pointer x and y point-to values: (%d, %d)\n", *x, *y);
    int *t = x;
    x = y;
    y = t;
    printf("after: pointer x and y values: (%d, %d)\n", x, y);
    printf("after: pointer x and y point-to values: (%d, %d)\n", *x, *y); 
}

// method 3: swap pointer point-to values
void swap (int *x, int *y)
{
    printf("before: pointer x and y values: (%d, %d)\n", x, y);
    printf("before: pointer x and y point-to values: (%d, %d)\n", *x, *y);
    int t = *x;
    *x = *y;
    *y = t;
    printf("after: pointer x and y values: (%d, %d)\n", x, y);
    printf("after: pointer x and y point-to values: (%d, %d)\n", *x, *y);
}
 
int main()
{   int x_val = 1;
    int y_val = 2;
    int *x = &x_val;
    int *y = &y_val;
    printf("----- method 1 (no good): swap pointer values -----\n");
    printf("before in main: pointer x_val and y_val values: (%d, %d)\n", x_val, y_val);
    swap_fail_1(x_val, y_val);
    printf("after in main: pointer x_val and y_val values: (%d, %d)\n", x_val, y_val);
    
    printf("\n");
    printf("----- method 2 (no good): swap pointer values -----\n");
    printf("before in main: pointer x and y values: (%d, %d)\n", x, y);
    swap_fail_2(x, y);
    printf("after in main: pointer x and y values: (%d, %d)\n", x, y);
    printf("after in main: pointer x and y point-to values: (%d, %d)\n", *x, *y);
    
    printf("\n");
    printf("----- method 3: swap pointer point-to values -----\n");
    printf("before in main: pointer x and y values: (%d, %d)\n", x, y);
    swap(x, y);
    printf("after in main: pointer x and y values: (%d, %d)\n", x, y);
    printf("after in main: pointer x and y point-to values: (%d, %d)\n", *x, *y);
    
    printf("\n");
    printf("----- method 3: swap pointer point-to values in main -----\n");
    printf("before in main: pointer x and y values: (%d, %d)\n", x, y);
    int *t;
    t = x;
    x = y;
    y = t;
    printf("after in main: pointer x and y values: (%d, %d)\n", x, y);
    printf("after in main: pointer x and y point-to values: (%d, %d)\n", *x, *y);
    return 0;
}