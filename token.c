#include "token.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int tokenize(char *input, Token tokens[])
{
    int count = 0;
    char *p = input;

    while (*p) {
        if (isspace(*p)) {
            p++;
            continue;
        }

        int i = 0;
        while (*p && !isspace(*p) && *p != '(' && *p != ')' && *p != ',' && *p != ';') {
            tokens[count].text[i++] = *p++;
        }
        tokens[count].text[i] = '\0';
        count++;

        if (*p == '(' || *p == ')' || *p == ',' || *p == ';') {
            tokens[count].text[0] = *p++;
            tokens[count].text[1] = '\0';
            count++;
        }
    }
    return count;
}

void create_table(const char *query)
{
    Token tokens[MAX_TOKENS];
    char buffer[256];

    strcpy(buffer, query);   // tokenize modifies input
    int count = tokenize(buffer, tokens);

    if (count < 3)
    {
        printf("Syntax error\n");
        return;
    }

    if (strcmp(tokens[0].text, "CREATE") != 0 ||
        strcmp(tokens[1].text, "TABLE") != 0)
    {
        printf("Not a CREATE TABLE statement\n");
        return;
    }

    printf("Table name: %s\n", tokens[2].text);
}