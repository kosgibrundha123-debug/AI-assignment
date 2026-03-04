#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    char captcha[6];
    char input[6];
    int i;

    srand(time(0));

    // Generate random captcha
    for(i = 0; i < 5; i++) {
        captcha[i] = 'A' + rand() % 26;
    }
    captcha[5] = '\0';

    printf("CAPTCHA: %s\n", captcha);

    printf("Enter CAPTCHA: ");
    scanf("%s", input);

    if(strcmp(captcha, input) == 0)
        printf("Access Granted! You are human.\n");
    else
        printf("Access Denied! CAPTCHA incorrect.\n");

    return 0;
}
