
#include "cell.h"
#include "utils.h"
#include "builtin.h"

t_builtin g_builtin[] = {
    // {.builtin_name = "echo", .foo = cell_echo},
    // {.builtin_name = "env", .foo = cell_env},
    {.builtin_name = "exit", .foo = cell_exit},
    {.builtin_name = "NULL"}};

void cell_exec(char **tokens)
{
    int i;
    const char *curr;

    i = 0;
    while ((curr = g_builtin[i].builtin_name))
    {
        if (!(strcmp(curr, tokens[0])))
        {
            g_builtin[i].foo(tokens);
            return;
        }
        i++;
    }

    cell_launch(tokens); // fork -> exec
}

/**
 * @brief split the line into tokens
 * @param line
 * @return an array containing the tokens
 */
char **cell_split_line(char *line)
{
    char **tokens;
    tokens = Malloc(BUFSIZ * sizeof *tokens);
    int position;
    size_t bufsize = BUFSIZ;

    for (
        char *token = strtok(line, DEL);
        token;
        token = strtok(NULL, DEL))
    {
        tokens[position++] = token;
        if (position >= bufsize)
        {
            bufsize *= 2;
            tokens = Realloc(tokens, bufsize * sizeof(*tokens));
        }
    }

    tokens[position] = NULL; // sentinal value
    return tokens;
}

/**
 * @brief read a line from the command line
 * @param  none
 * @return return a buffer containing the line read
 */
char *cell_read_line(void)
{
    char *buffer;
    size_t size;
    char cwd[BUFSIZ]; // BUFSIZ -> 1024

    buffer = NULL;
    Getcwd(cwd, sizeof(cwd));
    p(C "%s " RST "$>", cwd);
    if (getline(&buffer, &size, stdin) == -1)
    {
        free(buffer);
        buffer = NULL;
        if (feof(stdin))
        {
            p(RED "[EOF]" RST);
        }
        else
        {
            p(RED "getline failed" RST);
        }
    }

    return buffer;
}

int main(int ac, char **av)
{
    char *line;
    char **args;

    /**
     * REPL
     * READ -> EVALUATE -> PRINT/EXECUTE -> LOOP
     * */
    while (line = cell_read_line())
    {
        // 1 - get line
        // p("%s\n", line);

        // 2 - get tokens gettok
        //      -> lexing->parsing EVALUATION
        args = cell_split_line(line);

        // 3 - Exec
        cell_exec(args);

        // 4 - free
        free(line);
        free(args);
    }

    return EXIT_SUCCESS;
}
