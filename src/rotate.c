/*
** EPITECH PROJECT, 2022
** rotate.c
** File description:
** rotate
*/

#include <stdlib.h>
#include "linked_list.h"

void rotate_a(linked_list_t *l_a)
{
    int tmp = l_a->data;

    if (l_a && l_a->next) {
        while (l_a->next) {
            l_a->data = l_a->next->data;
            l_a = l_a->next;
        }
        l_a->data = tmp;
    }
    write(1, "ra ", 3);
}
