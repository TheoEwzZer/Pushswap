/*
** EPITECH PROJECT, 2022
** linked_list.h
** File description:
** linked_list
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

#ifndef LISTED_LIST_H_

    #define LISTED_LIST_H_

typedef struct linked_list {
    struct linked_list *next;
    int data;
    struct linked_list *prev;
} linked_list_t;

int *replace_with_position(int argc, char **argv);
int is_sorted_list(linked_list_t *l_a);
void add_node_head(linked_list_t **list, int data);
void free_list(linked_list_t *l_a, linked_list_t *l_b, int *argv);
void push_a(linked_list_t **l_a, linked_list_t **l_b, int end);
void push_b(linked_list_t **l_a, linked_list_t **l_b);
void remove_head(linked_list_t **list);
void rotate_a(linked_list_t *l_a);
void swap_a(linked_list_t *l_a);

#endif /* LISTED_LIST_H_ */
