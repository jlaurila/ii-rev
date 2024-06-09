#include <stdio.h>
#include <string.h>

char *password="InstaLupaLuottaa!!";

int main() {
    char input[100];
    printf("Anna salasana: ");
    fgets(input,100,stdin);
    if(strcmp(input, password) == 0) {
        printf("Oikein!\n");
    } else {
        printf("Väärin!\n");
        return 0;
    }
    printf("Salaisuus:  Rosebud\n");
    return 0;
}
