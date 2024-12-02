#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define p(...) printf(__VA_ARGS__)
#define DEL " "

void cell_split_line(char *line)
{
    char *tokens[6] = {0};
    int position;

    for (char *token = strtok(line,
                              DEL);
         token; token = strtok(NULL, DEL))
    {
        tokens[position++] = token;
    }

    position = 0;
    while (tokens[position])
    {
        p("%s\n", tokens[position++]);
    }
}

int main()
{
    char s[] = {"ls -la file.tx | cat"};
    cell_split_line(s);

    return EXIT_SUCCESS;
}