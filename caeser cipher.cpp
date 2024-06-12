#include <stdio.h>
#include <string.h>
#include<conio.h>
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
void encrypt(char message[], int shift);
void decrypt(char message[], int shift);
int main() 
{
    char message[MAX_SIZE];
    int shift;
    printf("Enter message to encrypt: ");
    fgets(message, MAX_SIZE, stdin);
    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);
    if (shift < 1 || shift > 25)
    {
        printf("Shift value must be between 1 and 25.\n");
        return 1;
    }
    printf("\nOriginal message: %s", message);
    encrypt(message, shift);
    printf("Encrypted message: %s", message);
    decrypt(message, shift);
    printf("Decrypted message: %s", message);
    return 0;
}
void encrypt(char message[], int shift)
 {
    int i;
    for (i = 0; i < strlen(message); i++) 
	{
        char c = message[i];
        if (c >= 'A' && c <= 'Z')
            message[i] = (c - 'A' + shift) % 26 + 'A';
        else if (c >= 'a' && c <= 'z')
            message[i] = (c - 'a' + shift) % 26 + 'a';
    }
}

void decrypt(char message[], int shift) 
{

    encrypt(message, 26 - shift);
}
