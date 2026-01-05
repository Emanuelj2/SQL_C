#ifndef TOKEN_H
#define TOKEN_H

#define MAX_TOKEN_LEN 64
#define MAX_TOKENS 100

typedef struct
{
    char text[MAX_TOKEN_LEN];
}Token;

int tokenize(char *input, Token tokens[]);
void create_table(const char *query);

#endif