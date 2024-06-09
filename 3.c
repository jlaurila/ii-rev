#include <stdio.h>
#include <string.h>

// Function to de-obfuscate the password
void deobfuscate_password(char *obfuscated, char *password, char *keys) {
    for (int i = 0; i < 10; i++) {
        password[i] = obfuscated[i] ^ keys[i];
    }
    password[10] = '\0'; // Null-terminate the string
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    // Obfuscated password and keys used for obfuscation
    char obfuscated_password[10] = {0x4F, 0x75, 0x79, 0x6F, 0x5B, 0x69, 0x6F, 0x4C, 0x2C, 0x59};
    char keys[10] = {0x2C, 0x1A, 0x0B, 0x1D, 0x3E, 0x0A, 0x1B, 0x3C, 0x4D, 0x2A};
    char actual_password[11];

    // De-obfuscate the password
    deobfuscate_password(obfuscated_password, actual_password, keys);

    // Compare the provided password with the actual password
    if (strcmp(argv[1], actual_password) == 0) {
        printf("Password is correct.\n");
    } else {
        printf("Password is incorrect.\n");
    }

    return 0;
}

