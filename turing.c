#include <stdio.h>
#include <string.h>

int main() {
    char question[100];

    printf("Ask a question: ");
    fgets(question, sizeof(question), stdin);

    if(strstr(question, "hello") != NULL)
        printf("AI: Hello! How are you?\n");

    else if(strstr(question, "name") != NULL)
        printf("AI: I am an AI agent.\n");

    else if(strstr(question, "weather") != NULL)
        printf("AI: It looks like a good day!\n");

    else
        printf("AI: I am still learning to answer that.\n");

    return 0;
}
