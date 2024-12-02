#ifndef __CELL__H__
#define __CELL__H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/**
 * ANSI Color for terminal output formating
 * y - yellow
 * g - green
 * c - cyan
 * RED - red
 * RST - reset to default color
 */
#define Y "\033[1;33m"
#define G "\033[1;32m"
#define C "\033[1;36m"
#define RED "\033[1;31m"
#define RST "\033[0m"

// redefine printf
#define p(...)  printf(__VA_ARGS__)
#define DEL "\n\t \v\f\r"

/**
 * @brief struct representing the builtin command inside the machine shell
 */
typedef struct s_builtin
{
    const char *builtin_name;
    int (*foo)(char **);
} t_builtin;

#endif
