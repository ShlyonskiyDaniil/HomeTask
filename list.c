// реализация односвязного списка
#include <stdio.h>
#include <stdlib.h>
typedef struct list{
    int value;
    struct list *next;
} list;
typedef struct slist{
    int size;
    list *head;
    list *tail;
} slist;

slist * new_list(void) {
    slist *lt = malloc(sizeof(slist));
    lt->size = 0;
    lt->head = NULL;
    lt->tail = lt->head;
    return lt;
}
void delete_list(list ** head) {
    list* prev = NULL;
    while ((*head)->next) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
}
<<<<<<< HEAD
struct list * insert(list *lst, int number)
{
    struct list *tmp, *p;
    tmp = (struct list*)malloc(sizeof(list));
    p = lst->next; // сохранение указателя на следующий узел
    lst->next = tmp; // предыдущий узел указывает на создаваемый
    tmp->value = number; // сохранение поля данных добавляемого узла
    tmp->next = p; // созданный узел указывает на следующий элемент
    return(tmp);
}

void print_list(const struct list* head) {
    while (head) {
        printf("%d",head->value);
        head = head->next;
    }
    printf("\n");
}
int main ()
{
    // list* first_list = new_list();
    // insert(first_list, 2, 7);
    // print_list(first_list);
    // Печать происходит без пробелов.

    // list* second_list = new_list();
    // insert(NULL, 2, 7);
    // Segmentation fault, если положить NULL в функцию insert.

    // list* third_list = new_list();
    // insert(third_list, 2, 7);
    // print_list(NULL);
    // Ничего не печатает, если положить NULL. Программа завершается без ошибок.

    // list* first_list = new_list();
    // insert(first_list, -1, 7);
    // insert(first_list, 9999999, 8);
    // insert(first_list, 0, 9);
    // insert(first_list, 1, 5);
    // print_list(first_list);
    // Если подавать номер места для вставки неккоректно(номер больше размера списка/отрицаетльное число),
    // то программа завершается без ошибок, вставка происходит в конец списка.
    // Но если подавать 0 и 1, то место вставки неочевидно.

    // list* first_list = new_list();
    // insert(first_list, 2, 7);
    // insert(first_list, 2, 7);
    // insert(first_list, 2, 7);
    // print_list(first_list);
    // delete_list(&first_list);
    // print_list(first_list);
    // При удалении списка последний узел не удалаяется.

    // list* first_list = new_list();
    // insert(first_list, 2, 7);
    // print_list(first_list);
    // delete_list(NULL);
    // print_list(first_list);
    // При подаче NULL в delete возникает Segmentation fault.

    // list* first_list = new_list();
    // insert(first_list, 2, 7);
    // insert(first_list, 2, 7);
    // print_list(first_list);
    // delete_list(3);
    // При случайной подаче неверных данных в delete возникает Segmentation fault. В

    list* first_list = new_list();
    insert(first_list, 2, 7);
    insert(first_list, 2, 8);
    insert(first_list, 1234, 4);
    insert(first_list, 0, 3);
    print_list(first_list);
    delete_list(&first_list);

    return 0;
}
