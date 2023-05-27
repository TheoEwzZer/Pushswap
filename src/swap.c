/*
** EPITECH PROJECT, 2022
** swap.c
** File description:
** swap
*/

#include <stdlib.h>
#include "linked_list.h"

void swap_a(linked_list_t *l_a)
{
    int tmp = l_a->data;

    if (l_a && l_a->next) {
        l_a->data = l_a->next->data;
        l_a->next->data = tmp;
    }
    write(1, "sa\n", 3);
}
