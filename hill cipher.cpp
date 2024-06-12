#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}
void matrixMultiply(int result[], int keyMatrix[][3], int textVector[], int size) {
    for (int i = 0; i < size; i++) {
        result[i] = 0;
        for (int j = 0; j < size; j++) {
            result[i] += keyMatrix[i][j] * textVector[j];
        }
        result[i] %= 26;
    }
}
void hillCipherEncrypt(char *plaintext, char *ciphertext, int keyMatrix[][3], int size) {
    int textVector[size];
    int result[size];   
    int length = strlen(plaintext);
    int index = 0;
    for (int i = 0; i < length; i += size) {
        for (int j = 0; j < size; j++) {
            if (index < length) {
                textVector[j] = plaintext[index++] - 'A';
            } else {
                textVector[j] = 'X' - 'A'; 
            }
        }
        matrixMultiply(result, keyMatrix, textVector, size);
        for (int j = 0; j < size; j++) {
            *ciphertext++ = result[j] + 'A';
        }
    }
    *ciphertext = '\0';
}
int main() {
    int keyMatrix[3][3] = {
        {6, 24, 1},
        {13, 16, 10},
        {20, 17, 15}
    };
    char plaintext[100];
    char ciphertext[100];
    printf("Enter plaintext (uppercase letters only): ");
    scanf("%s", plaintext);
    hillCipherEncrypt(plaintext, ciphertext, keyMatrix, 3);
    printf("Ciphertext: %s\n", ciphertext);
    return 0;
}

