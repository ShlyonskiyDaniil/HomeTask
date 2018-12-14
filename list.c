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
// создание нового списка
slist * new_list(void) {
    slist *lt = malloc(sizeof(slist));
    lt->size = 0;
    lt->head = NULL;
    lt->tail = lt->head;
    return lt;
}
// удаление списка
void delete_list(list ** head) {
    list* prev = NULL;
    while ((*head)->next) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
}
//вставка элемента
struct list * insert(list *lst, int number)
{
    struct list *tmp, *p;
    tmp = (struct list*)malloc(sizeof(list));
    p = lst->next; 
    lst->next = tmp;
    tmp->value = number; 
    tmp->next = p; 
    return(tmp);
}
// печатаем список
void print_list(const struct list* head) {
    while (head) {
        printf("%d",head->value);
        head = head->next;
    }
    printf("\n");
}
int main () {
    return 0;
}
