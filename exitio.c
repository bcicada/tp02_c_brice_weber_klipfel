/**
 * \file exitio.c
 * \brief System & process calls.
 * \author Brice W. K. <b.cicada@protonmail.com>
 * \version 0.1
 * \date 22 sept. 2022
 *
 * System & process calls in c file.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <mot>\n", argv[0]);
        return 1;
    }

    printf("Message: %s\n", argv[1]);
    return 0;
}
