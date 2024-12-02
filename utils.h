#ifndef __UTILS__H__
#define __UTILS__H__

#include "cell.h"

// wrappers

/**
 * @brief optain the pathname of the current working directory
 * @param buff
 * @param buf_size
 * @return void
 */
void Getcwd(char *buff, size_t buf_size)
{
    if ((NULL == getcwd(buff, buf_size)))
        perror(RED "getcwd FAILED" RST);
}

// TODO :
/**
 * @brief print a banner at the begining of the shell
 * @param  none
 */
void printBanner(void)
{
}

/**
 * @brief alloc a [size] byte from the memory
 * @param size
 * @return the allocated size
 */
void *Malloc(size_t size)
{
    void *ptr;
    if (size == 0)
        return (NULL);

    ptr = malloc(size);
    if (!ptr)
    {
        fprintf(stderr, RED "Malloc failed" RST);
        exit(EXIT_FAILURE);
    }
    return (ptr);
}

/**
 * @brief realloc a memory for the buffer
 * @param buf
 * @param size
 * @return a void pointer to a new location of memory
 */
void *Realloc(void *buf, size_t size)
{
    void *new_ptr;

    new_ptr = realloc(buf, size);
    if (new_ptr == NULL)
    {
        fprintf(stderr, "Realloc failed\n");
        exit(EXIT_FAILURE);
    }
    return new_ptr;
}

void dbzSpinnerLoading()
{
    const char *charging[] = {
        "[                  ]",
        "[=                 ]",
        "[==                ]",
        "[===               ]",
        "[====              ]",
        "[=====             ]",
        "[======            ]",
        "[=======           ]",
        "[========          ]",
        "[=========         ]",
        "[==========        ]",
        "[===========       ]",
        "[============      ]",
        "[=============     ]",
        "[==============    ]",
        "[===============   ]",
        "[================  ]",
        "[================= ]",
        "[==================]"};
    const int frame = sizeof(charging) / sizeof(charging[0]);

    p(RED "Shutting down...\n" RST);
    for (int i = 0; i < frame; i++)
    {
        p("\r" Y "%s" RST, charging[i]);
        fflush(stdout);
        usleep(421337);
    }
    p(C "\n[*]EXIT[*]\n" RST);
}

#endif