#include <stdio.h>

void __attribute__((constructor)) run_me_first() {
    puts("You have been pwnd by Insta Intruders!!\n");
}

int strcmp(const char *s1, const char *s2) {
  // Always return 0.
  return 0;
}

