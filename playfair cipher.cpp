#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 5
void generateKeyTable(char key[], char keyTable[SIZE][SIZE]) {
    int dicty[26] = {0};
    int i, j, k, len = strlen(key);
    char c;
    for (i = 0, j = 0, k = 0; i < len; i++) {
        c = toupper(key[i]);
        if (c == 'J') {
            c = 'I';
        }
        if (dicty[c - 'A'] == 0) {
            keyTable[j][k++] = c;
            dicty[c - 'A'] = 1;
            if (k == SIZE) {
                k = 0;
                j++;
            }
        }
    }
    for (c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue; 
        if (dicty[c - 'A'] == 0) {
            keyTable[j][k++] = c;
            dicty[c - 'A'] = 1;
            if (k == SIZE) {
                k = 0;
                j++;
            }
        }
    }
}
void printKeyTable(char keyTable[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", keyTable[i][j]);
        }
        printf("\n");
    }
}
void search(char keyTable[SIZE][SIZE], char a, char b, int arr[]) {
    int i, j;
    if (a == 'J') a = 'I';
    if (b == 'J') b = 'I';
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (keyTable[i][j] == a) {
                arr[0] = i;
                arr[1] = j;
            } else if (keyTable[i][j] == b) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}
void encrypt(char str[], char keyTable[SIZE][SIZE]) {
    int i, a[4];
    for (i = 0; i < strlen(str); i += 2) {
        if (str[i] == str[i + 1]) {
            for (int j = strlen(str) + 1; j > i + 1; j--) {
                str[j] = str[j - 1];
            }
            str[i + 1] = 'X';
        }
        search(keyTable, toupper(str[i]), toupper(str[i + 1]), a);
        if (a[0] == a[2]) {
            str[i] = keyTable[a[0]][(a[1] + 1) % SIZE];
            str[i + 1] = keyTable[a[0]][(a[3] + 1) % SIZE];
        } else if (a[1] == a[3]) {
            str[i] = keyTable[(a[0] + 1) % SIZE][a[1]];
            str[i + 1] = keyTable[(a[2] + 1) % SIZE][a[1]];
        } else {
            str[i] = keyTable[a[0]][a[3]];
            str[i + 1] = keyTable[a[2]][a[1]];
        }
    }
}
void decrypt(char str[], char keyTable[SIZE][SIZE]) {
    int i, a[4];
    for (i = 0; i < strlen(str); i += 2) {
        search(keyTable, toupper(str[i]), toupper(str[i + 1]), a);

        if (a[0] == a[2]) {
            str[i] = keyTable[a[0]][(a[1] - 1 + SIZE) % SIZE];
            str[i + 1] = keyTable[a[0]][(a[3] - 1 + SIZE) % SIZE];
        } else if (a[1] == a[3]) {
            str[i] = keyTable[(a[0] - 1 + SIZE) % SIZE][a[1]];
            str[i + 1] = keyTable[(a[2] - 1 + SIZE) % SIZE][a[1]];
        } else {
            str[i] = keyTable[a[0]][a[3]];
            str[i + 1] = keyTable[a[2]][a[1]];
        }
    }
}
void prepareText(char str[], int len) {
    int i, j;
    for (i = 0; i < len; i++) {
        if (str[i] == 'J') {
            str[i] = 'I';
        }
    }
    for (i = 0; i < len; i += 2) {
        if (str[i] == str[i + 1]) {
            for (j = len + 1; j > i + 1; j--) {
                str[j] = str[j - 1];
            }
            str[i + 1] = 'X';
            len++;
        }
    }
    if (len % 2 != 0) {
        str[len++] = 'X';
    }
    str[len] = '\0';
}
int main() {
    char key[30], str[100];
    char keyTable[SIZE][SIZE];
    printf("Enter key: ");
    gets(key);
    printf("Enter text: ");
    gets(str);
    generateKeyTable(key, keyTable);
    printf("\nGenerated Key Table:\n");
    printKeyTable(keyTable);
    prepareText(str, strlen(str));
    printf("\nPrepared Text: %s\n", str);
    encrypt(str, keyTable);
    printf("\nEncrypted Text: %s\n", str);
    decrypt(str, keyTable);
    printf("\nDecrypted Text: %s\n", str);
    return 0;
}

