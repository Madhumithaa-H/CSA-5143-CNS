#include <stdio.h>
#include <string.h>
void encryptRailFence(char *plaintext, char *ciphertext, int depth) {
    int len = strlen(plaintext);
    int k = 0;
    char rail[depth][len];
    for (int i = 0; i < depth; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';
    int row = 0, dir_down = 0; 
    for (int i = 0; i < len; i++) {
        if (row == 0 || row == depth - 1) 
            dir_down = !dir_down; 
        rail[row][i] = plaintext[i];
        row += dir_down ? 1 : -1;
    }
    for (int i = 0; i < depth; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != '\n')
                ciphertext[k++] = rail[i][j];
    ciphertext[k] = '\0';
}
void decryptRailFence(char *ciphertext, char *plaintext, int depth) {
    int len = strlen(ciphertext);
    int k = 0;
    char rail[depth][len];
    for (int i = 0; i < depth; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = '\n';
    int row = 0, dir_down = 0; 
    for (int i = 0; i < len; i++) {
        if (row == 0 || row == depth - 1)
            dir_down = !dir_down; 
        rail[row][i] = '*';
        row += dir_down ? 1 : -1;
    }
    for (int i = 0; i < depth; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] == '*' && k < len)
                rail[i][j] = ciphertext[k++];
    row = 0, dir_down = 0;
    for (int i = 0; i < len; i++) {
        if (row == 0 || row == depth - 1)
            dir_down = !dir_down; 
        plaintext[i] = rail[row][i];
        row += dir_down ? 1 : -1;
    }
    plaintext[len] = '\0';
}
int main() {
    char text[100];
    char result[100];
    int depth, choice;
    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  
    printf("Enter depth: ");
    scanf("%d", &depth);
    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);
    if (choice == 1) {
        encryptRailFence(text, result, depth);
        printf("Ciphertext: %s\n", result);
    } else if (choice == 2) {
        decryptRailFence(text, result, depth);
        printf("Decrypted text: %s\n", result);
    } else {
        printf("Invalid choice\n");
    }
    return 0;
}

