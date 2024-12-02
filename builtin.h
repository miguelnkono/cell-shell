#ifndef __BUILTIN_H__
#define __BUILTIN_H__

#include "cell.h"
#include "utils.h"

int cell_exit(char **args)
{
    (void)args;
    dbzSpinnerLoading();
    exit(EXIT_SUCCESS);
}

int cell_env(char **args)
{

}

int cell_echo(char **args)
{

}


#endif 