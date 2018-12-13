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
void insert(list*head, unsigned n,int value) {
    unsigned i = 0;
    list *tmp = NULL;
    // Находим нужный элемент, если вышли за пределы списка, то выходим из цикла   
    while (i<n && head->next) {
        head = head->next;
        i++;
    }
    tmp = (list*)malloc(sizeof(list));
    tmp->value = value;
    // если єто не послдений элемент, то next  перекидываем на следущий узел
    if (head->next) {
        tmp->next = head->next;
    } 
    // иначе на NULL
    else {
        tmp->next = NULL;
    }
    head->next = tmp;
}

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
