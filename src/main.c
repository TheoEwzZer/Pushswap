/*
** EPITECH PROJECT, 2022
** main.c
** File description:
** main
*/

#include "linked_list.h"

linked_list_t *my_params_to_list(int argc, int *argv)
{
    linked_list_t *linked_list = malloc(sizeof(linked_list_t));
    linked_list_t *linked_list_next = linked_list;

    if (!linked_list)
        return NULL;
    linked_list->data = argv[0];
    linked_list->next = NULL;
    linked_list->prev = NULL;
    for (int i = 1; i < argc; i++) {
        linked_list_next->next = malloc(sizeof(linked_list_t));
        linked_list_next->next->data = argv[i];
        linked_list_next->next->prev = linked_list_next;
        linked_list_next = linked_list_next->next;
    }
    linked_list_next->next = NULL;
    return linked_list;
}

void action(linked_list_t **l_a, linked_list_t **l_b, int i)
{
    int top = (*l_a)->data;

    if ((top >> i) & 1)
        rotate_a(*l_a);
    else
        push_b(l_a, l_b);
}

void radix_sort(linked_list_t **l_a, linked_list_t **l_b, int argc)
{
    int len = 0;
    int end = 0;

    while ((argc - 1) >> len)
        len++;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < argc; j++)
            action(l_a, l_b, i);
        end = (i == len - 1) ? 1 : 0;
        while ((*l_b)->next)
            push_a(l_a, l_b, 0);
        push_a(l_a, l_b, end);
    }
    write(1, "\n", 1);
}

int check_error(int argc, char **argv)
{
    if (argc < 3)
        return 1;
    for (int i = 1; i < argc; i++) {
        if (!my_str_isnum(argv[i]))
            return 84;
    }
    return 0;
}

int main(int argc, char **argv)
{
    int *new_argv = NULL;
    linked_list_t *l_a = NULL;
    linked_list_t *l_b = NULL;
    int error = check_error(argc, argv);
    if (error == 1) {
        write(1, "\n", 1);
        return 0;
    }
    if (error == 84)
        return 84;
    new_argv = replace_with_position(argc, argv);
    l_a = my_params_to_list(argc - 1, new_argv);
    if (is_sorted_list(l_a))
        return 0;
    if (argc == 3)
        swap_a(l_a);
    else
        radix_sort(&l_a, &l_b, argc - 1);
    free_list(l_a, l_b, new_argv);
    return 0;
}
