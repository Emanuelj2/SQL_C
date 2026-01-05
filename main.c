#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "token.h"

int main(int argc, char **argv)
{
    char cmd[128];
    int running = 1;

    while (running)
    {
        printf("SQL> ");
        if (!fgets(cmd, sizeof(cmd), stdin))
            break;

        // remove newline
        cmd[strcspn(cmd, "\n")] = 0;

        if (strcmp(cmd, "exit") == 0)
        {
            running = 0;
        }
        else if (strcmp(cmd, "CREATE TABLE") == 0)
        {
            create_table(cmd);
        }
        else
        {
            printf("invalid: %s\n", cmd);
        }
    }

    return 0;
}