#include <stdio.h>

unsigned char reverseBits(unsigned char num) {
    int numOfBits = 8; // Number of bits in an integer
    int reversed = 0;

    for (int i = 0; i < numOfBits; i++) {
        if ((num & (1 << i)) != 0) {
            reversed |= (1 << ((numOfBits - 1) - i));
        }
    }

    return reversed;
}

int main() {
    unsigned char originalValue = 5; // Example value
    unsigned char reversedValue = reverseBits(originalValue);

    printf("Original value: %d\n", originalValue);
    printf("Reversed value: %d\n", reversedValue);

    return 0;
}
