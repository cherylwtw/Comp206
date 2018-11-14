#include <stdlib.h>
#include <stdio.h>


void print_int_in_binary(int num) {
    printf("decimal number: %d\n", num);
    // big-endian representation for easy human read
    for( int bit_number=31; bit_number>=0; bit_number-- ) {
        // have number 00000001 shift bit_number to the left, then do a bit-wise AND with C
	int bit_contribution = num & (1<<bit_number );
        
        if( bit_contribution > 0 )
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

void print_in_binary(char c) {
    printf("decimal number: %d\n", c);
    // big-endian representation for easy human read
    for( int bit_number=7; bit_number>=0; bit_number-- ) {
        // have number 00000001 shift bit_number to the left, then do a bit-wise AND with C
	int bit_contribution = c & (1<<bit_number );
        
        if( bit_contribution > 0 )
            printf("1");
        else
            printf("0");
    }
    printf("\n");
}

void bitwise_shift_1() {
    char c = 10;
    char c_shift_right = c >> 4;
    char c_shift_left = c << 2;
    
    printf("c\n");
    print_in_binary(c);
    printf("c_shift_right\n");
    print_in_binary(c_shift_right);
    printf("c_shift_left\n");
    print_in_binary(c_shift_left);
    
}

void bitwise_operation_1() {
    char c  = 85;
    if ((c&(1<<2))> 0) {
        printf("bit 3 of c is a 1!\n");
    }
    else {
        printf("bit 3 of c is a 0!\n");
    }
}

void bitwise_operation_2() {
    unsigned char c = 42;
    int bit_number;
    int bit_contribution;
    int total_value = 0;

    printf( "Considering the one-byte integer %d.\n", c );
    
    for( bit_number=0; bit_number<8; bit_number++ ) {
        // have number 00000001 shift bit_number to the left, then do a bit-wise AND with C
	bit_contribution = c & (1<<bit_number );

	if( bit_contribution > 0 )
            printf( "Bit number %d was 1.\n", bit_number );
        else
            printf( "Bit number %d was 0.\n", bit_number );

        printf( "bit %d of c contributes %d.\n", bit_number, bit_contribution );

	total_value += bit_contribution;
    }

    printf( "The total value of c was %d\n.", total_value );
}

int main() {
    printf("----- bitwise_shift example -----\n");
    bitwise_shift_1();
    printf("----- bitwise_operation_1 example -----\n");
    bitwise_operation_1();
    printf("----- bitwise_operation_2 example -----\n");
    bitwise_operation_2();
    printf("----- print_int_in_binary example -----\n");
    print_int_in_binary(256);
    return 0;
   
}

