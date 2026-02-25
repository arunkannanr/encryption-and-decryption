#include <stdio.h>
#include <string.h>

void encrypt_mode(char *key) {
    char text[200];
    int key_len = strlen(key);

    printf("Enter plain text to encrypt: ");
    getchar(); // Clear the buffer
    fgets(text, sizeof(text), stdin);

    printf("Encrypted (Hex Code): ");
    for (int i = 0; text[i] != '\n' && text[i] != '\0'; i++) {
        // Perform XOR and print as 2-digit Hex
        printf("%02x ", (unsigned char)(text[i] ^ key[i % key_len]));
    }
    printf("\n");
}

void decrypt_mode(char *key) {
    unsigned int hex_val;
    int key_len = strlen(key);
    int i = 0;

    printf("Enter Hex codes (e.g., 1a 0f 22) and type '00' to finish:\n");
    
    printf("Decrypted Text: ");
    while (scanf("%x", &hex_val) && hex_val != 0) {
        // Perform XOR on the hex value and print as character
        printf("%c", (char)(hex_val ^ key[i % key_len]));
        i++;
    }
    printf("\n");
}

int main() {
    int choice;
    char key[50];

    printf("--- Text Vault: Hex Edition ---\n");
    printf("Enter secret password: ");
    scanf("%s", key);

    printf("1. Encrypt Text -> Hex\n");
    printf("2. Decrypt Hex -> Text\n");
    printf("Choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt_mode(key);
    } else if (choice == 2) {
        decrypt_mode(key);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}