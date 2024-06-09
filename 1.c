#include <stdio.h>
#include <string.h>

// Function to calculate the checksum of the license key
int checkLicense(const char *key) {
    int checksum = 0;
    int length = strlen(key);

    for (int i = 0; i < length; i++) {
        checksum += key[i];
    }

    // Simple checksum: valid if divisible by 7
    return (checksum % 7) == 0;
}

int main() {
    char key[256];

    // Ask the user for the license key
    printf("Enter the license key: ");
    if (fgets(key, sizeof(key), stdin) != NULL) {
        // Remove the newline character if present
        key[strcspn(key, "\n")] = '\0';

        // Check the license key
        if (checkLicense(key)) {
            printf("ok\n");
        } else {
            printf("not ok\n");
        }
    } else {
        printf("Error reading input\n");
    }

    return 0;
}


