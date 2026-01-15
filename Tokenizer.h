#ifndef TOKENIZER_H
#define TOKENIZER_H


#define MAX_TOKENS 124
#define MAX_TEXT 64

typedef enum
{
    TOK_CREATE, TOK_TABLE, TOK_INSERT, TOK_INTO,
    TOK_SELECT, TOK_FROM, TOK_WHERE,
    TOK_INT, TOK_STRING,
    TOK_IDENTIFIER, TOK_NUMBER, TOK_STRING_LITERAL,
    TOK_STAR, TOK_COMMA, TOK_LPAREN, TOK_RPAREN,
    TOK_OPERATOR, TOK_SEMICOLEN, TOK_EOF
}TokenType;

typedef struct
{
    TokenType type;
    char text[MAX_TEXT];
}Token;

int tokenize(const char* input, Token tokens[]);

#endif