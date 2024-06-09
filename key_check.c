#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ptrace.h>

// Function to detect if the program is being debugged
void anti_debug() {
    if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1) {
        printf("Debugger detected! Exiting...\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <key>\n", argv[0]);
        return 1;
    }

    // Anti-debugging technique
    anti_debug();

    // Obfuscated key check
    char key[] = {0x47, 0x44, 0x42, 0x49, 0x53, 0x46, 0x55, 0x4E, 0x00}; // XORed "gdbisfun" with 0x10
    for (int i = 0; i < 8; i++) {
        key[i] ^= 0x10;  // De-obfuscate by XORing with 0x10 again
    }

    // Check the provided key
    if (strcmp(argv[1], key) == 0) {
        printf("Correct key!\n");
    } else {
        printf("Incorrect key.\n");
    }

    return 0;
}
