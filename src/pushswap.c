/*
** EPITECH PROJECT, 2022
** is_sorted_list.c
** File description:
** is_sorted_list
*/

#include "linked_list.h"

int is_sorted_list(linked_list_t *l_a)
{
    while (l_a->next) {
        if (l_a->data > l_a->next->data)
            return 0;
        l_a = l_a->next;
    }
    write(1, "\n", 1);
    return 1;
}

void free_list(linked_list_t *l_a, linked_list_t *l_b, int *argv)
{
    linked_list_t *ptr = NULL;

    free(l_b);
    l_b = NULL;
    while (l_a) {
        ptr = l_a;
        l_a = l_a->next;
        free(ptr);
        ptr = NULL;
    }
    free(argv);
    argv = NULL;
    l_a = NULL;
}

int *replace_with_position(int argc, char **argv)
{
    int *new_argv = malloc(sizeof(int) * (argc - 1));
    int *array = malloc(sizeof(int) * argc);

    for (int i = 0; i < argc; i++)
        array[i] = my_getnbr(argv[i]);
    for (int i = 0; i < argc - 1; i++) {
        int nbr = 0;
        for (int j = 0; j < argc - 1; j++)
            nbr += array[j + 1] < array[i + 1] ? 1 : 0;
        new_argv[i] = nbr;
    }
    return new_argv;
}
