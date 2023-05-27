/*
** EPITECH PROJECT, 2022
** push.c
** File description:
** push
*/

#include <stdlib.h>
#include "linked_list.h"

void add_node_head(linked_list_t **list, int data)
{
    linked_list_t *linked_list_next = malloc(sizeof(linked_list_t));

    linked_list_next->data = data;
    linked_list_next->next = *list;
    linked_list_next->prev = NULL;
    if (*list) {
        (*list)->prev = linked_list_next;
        *list = (*list)->prev;
    } else {
        *list = linked_list_next;
    }
}

void remove_head(linked_list_t **list)
{
    linked_list_t *linked_list_next = NULL;

    if (*list && (*list)->next) {
        linked_list_next = (*list)->next;
        linked_list_next->prev = NULL;
        *list = linked_list_next;
    } else {
        *list = NULL;
    }
}

void push_a(linked_list_t **l_a, linked_list_t **l_b, int end)
{
    int data = (*l_b)->data;

    if (*l_b) {
        add_node_head(l_a, data);
        remove_head(l_b);
        if (end)
            write(1, "pa", 2);
        else
            write(1, "pa ", 3);
    }
}

void push_b(linked_list_t **l_a, linked_list_t **l_b)
{
    int data = (*l_a)->data;

    if (*l_a) {
        add_node_head(l_b, data);
        remove_head(l_a);
        write(1, "pb ", 3);
    }
}
