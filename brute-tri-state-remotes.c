#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// originally trit_inc.c.
// Increment a ternary number stored in a 32-bit unsigned integer.
// This example can hold up to 16 trits (16 * 2 = 32 bits).
bool increment_packed_ternary(uint32_t *ternary_num) {
    uint32_t carry = 1;
    for (int i = 0; i < 16 && carry > 0; i++) {
        // Isolate the current trit and add the carry
        uint32_t trit_shift = i * 2;
        uint32_t trit = (*ternary_num >> trit_shift) & 0x3;
        uint32_t temp = trit + carry;
        
        // Update the trit and the carry-over
        uint32_t new_trit = temp % 3;
        carry = temp / 3;

        // Clear the old trit and set the new one
        *ternary_num &= ~(0x3 << trit_shift);
        *ternary_num |= (new_trit << trit_shift);
    }
    return carry > 0;
}

// Helper function to print the packed ternary number
void print_packed_ternary(uint32_t packed_num, int num_trits) {
    for (int i = num_trits - 1; i >= 0; i--) {
        uint32_t trit = (packed_num >> (i * 2)) & 0x3;
        if (trit==2)
            printf("F");
        else
            printf("%u", trit);
    }
    printf("\n");
}

int main() {
    uint32_t t_num = 0; // Starts at 0
    int num_trits = 8;

    // Set initial value to 102_3
    // 2 * 3^0 = 2 (10)
    // 0 * 3^1 = 0 (01)
    // 1 * 3^2 = 9 (01)
    // 102_3 is 010110 in binary (packed 2 bits/trit)
    // Binary: ...00010110 -> 0x16
//    t_num = 0x16;
    printf("    ");
    print_packed_ternary(t_num, num_trits); // Prints 00102

    for (int k = 0; k <= 7000; k++) {
        // Increment 102_3 (11) to 110_3 (12)
        increment_packed_ternary(&t_num);
        printf("++: ");
        print_packed_ternary(t_num, num_trits); // Prints 00110
    }
    return 0;
}
