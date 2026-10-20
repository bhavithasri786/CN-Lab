#include <stdio.h>
#include <string.h>

unsigned int modPow(unsigned int base, unsigned int exp, unsigned int mod) {
    unsigned long long result = 1;
    unsigned long long b = base % mod;

    while (exp > 0) {
        if (exp & 1)
            result = (result * b) % mod;
        b = (b * b) % mod;
        exp >>= 1;
    }
    return (unsigned int) result;
}

int main(void) {
    char message[100];
    unsigned int plaintext[100], ciphertext[100];
    const unsigned int n = 253;   
    const unsigned int e = 13;  
    const unsigned int d = 17; 

    printf("Enter the plain text: ");
    if (fgets(message, sizeof(message), stdin) == NULL) {
        printf("No input.\n");
        return 1;
    }

    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n')
        message[--len] = '\0';

    for (size_t i = 0; i < len; i++) {
        plaintext[i] = (unsigned char) message[i];
        if (plaintext[i] >= n) {
            printf("Character '%c' (code %u) is too large for n = %u.\n",
                   message[i], plaintext[i], n);
            return 1;
        }
    }

    printf("\nEncrypted Cipher Text (Numeric): ");
    for (size_t i = 0; i < len; i++) {
        ciphertext[i] = modPow(plaintext[i], e, n);
        printf("%u ", ciphertext[i]);
    }

    printf("\nOriginal Plain Text: %s", message);

    printf("\nDecrypted Plain Text: ");
    for (size_t i = 0; i < len; i++) {
        unsigned int pt = modPow(ciphertext[i], d, n);
        printf("%c", (char) pt);
    }

    printf("\n");
    return 0;
}