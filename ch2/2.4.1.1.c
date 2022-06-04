#include <stdio.h>

/* The lookahead symbol */
int token;

int gettoken(void) {
    return token = getchar();
}

void s(void) {
    if(token == 'a') {
        gettoken();
    }
    else if(token == '+' || token == '-') {
        gettoken();
        s();
        s();
    }
    else {
        fprintf(stderr, "Syntax error\n");
    }
}

int main(void) {
    printf("Please enter expressions according to the following grammar:\n");
    printf("S -> '+' S S | '-' S S | 'a'\n");
    while(1) {
        printf("> ");
        fflush(stdout);
        gettoken();
        s();
    }

    return 0;
}