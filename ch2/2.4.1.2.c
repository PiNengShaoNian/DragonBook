#include <stdio.h>

// S -> S ( S ) S | ε
//上面的生成式存在左递归，可以将其转换成等价的生成式:
// S -> R
// R -> ( S ) R | ε

/* The lookahead symbol */
int token;

int gettoken(void) {
    return token = getchar();
}

void r(void);
void s(void) {
    r();
}

void r(void) {
    if(token !== "(") {
        /* R -> ε */
        return;
    }
    gettoken();
    s();
    if(token != ")") {
        fprintf(stderr, "Syntax error\n");
        return;
    }

    gettoken();
    s();
}

int main(void) {
    printf("Please enter expressions according to the following grammar:\n");
    printf("S -> S '(' S ')' S | ε\n");

    while(1) {
        printf("> ");
        fflush(stdout);
        gettoken();
        s();
    }
}