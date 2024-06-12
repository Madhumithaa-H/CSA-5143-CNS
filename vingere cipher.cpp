#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void vigenereEncrypt(char* plaintext, char* key, char* ciphertext) {
    int textLen = strlen(plaintext);
    int keyLen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < textLen; i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = (plaintext[i] + key[j % keyLen] - 2 * base) % 26 + base;
            j++;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[textLen] = '\0';
}
void vigenereDecrypt(char* ciphertext, char* key, char* plaintext) {
    int textLen = strlen(ciphertext);
    int keyLen = strlen(key);
    int i, j;

    for (i = 0, j = 0; i < textLen; i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            plaintext[i] = (ciphertext[i] - key[j % keyLen] + 26) % 26 + base;
            j++;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[textLen] = '\0';
}
int main() {
    char plaintext[100];
    char key[100];
    char ciphertext[100];
    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';  
    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';  
    for (int i = 0; key[i]; i++) {
        key[i] = toupper(key[i]);
}
    vigenereEncrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);
    vigenereDecrypt(ciphertext, key, plaintext);
    printf("Decrypted text: %s\n", plaintext);
    return 0;
}

