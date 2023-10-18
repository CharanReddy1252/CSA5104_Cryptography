#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>


#define SHA1_BLOCK_SIZE 64
#define SHA1_HASH_SIZE 20


#define LEFT_ROTATE(x, n) (((x) << (n)) | ((x) >> (32 - (n)))

#define CH(x, y, z) (((x) & (y)) ^ ((~(x)) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
static const uint32_t k[64] = {
    0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5,
    // Add the rest of the 64 SHA-1 constants here
};

void sha1(const uint8_t *message, size_t message_len, uint8_t *digest) {
   
}

int main() {
    char input[100];
    int i;
    printf("Enter the string: ");
    fgets(input, sizeof(input), stdin);
    uint8_t hash[SHA1_HASH_SIZE]; // SHA-1 hash will be stored here

    // Calculate the SHA-1 hash
    sha1((const uint8_t *)input, strlen(input), hash);

    // Print the SHA-1 hash
    printf("SHA-1 Hash: ");
    for ( i = 0; i < SHA1_HASH_SIZE; i++) {
        printf("%02x", hash[i]);
   }
    printf("\n");

}
