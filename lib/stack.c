#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

//структура карты
typedef struct card 
{
    char suit[15];
    char num[20];
} card;

//структура элемента в списке
typedef struct deck {
    card card_in_deck;
    struct deck *next_card;
} deck;

//добавление элемента 
void push(deck **head, card card_to_add) {
    deck *tmp = (deck*) malloc(sizeof(deck));
    tmp->card_in_deck = card_to_add;
    tmp->next_card = (*head);
    (*head) = tmp;
}

//удаление элемента(с возвращением элемента)
card pop(deck **head) {
    deck* prev = NULL;
    card val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->card_in_deck;
    (*head) = (*head)->next_card;
    free(prev);
    return val;
}

//переход к n элементу списка
deck* getNth(deck* head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next_card;
        counter++;
    }
    return head;
}

//переход к последнему элементу списка
deck* getLast(deck *head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next_card) {
        head = head->next_card;
    }
    return head;
}

//добавление в конец списка
void pushBack(deck *head, card value) {
    deck *last = getLast(head);
    deck *tmp = (deck*) malloc(sizeof(deck));
    tmp->card_in_deck = value;
    tmp->next_card = NULL;
    last->next_card = tmp;
}

//удаление последнего элемента
int popBack(deck **head) {
    deck *pFwd = NULL;
    deck *pBwd = NULL;
    if (!head) {
        exit(-1);
    }
    if (!(*head)) {
        exit(-1);
    }
     
    pFwd = *head; 
    while (pFwd->next_card) { 
        pBwd = pFwd;
        pFwd = pFwd->next_card;
    }
 
    if (pBwd == NULL) {
        free(*head);
        *head = NULL;
    } else {
        free(pFwd->next_card);
        pBwd->next_card = NULL;
    }
}

//добавление элемента в n место в списке
void insert(deck *head, unsigned n, card val) {
    unsigned i = 0;
    deck *tmp = NULL;
    while (i < n && head->next_card) {
        head = head->next_card;
        i++;
    }
    tmp = (deck*) malloc(sizeof(deck));
    tmp->card_in_deck = val;
    if (head->next_card) {
        tmp->next_card = head->next_card;
    } else {
        tmp->next_card = NULL;
    }
    head->next_card = tmp;
}

//удаление n элемента(с возвращением значения)
card deleteNth(deck **head, int n) {
    if (n == 0) {
        return pop(head);
    } else {
        deck *prev = getNth(*head, n-1);
        deck *elm  = prev->next_card;
        card val = elm->card_in_deck;
 
        prev->next_card = elm->next_card;
        free(elm);
        return val;
    }
}

//cоздание списка из массива(поэлементно берет карту из списка и втыкает в стек)
void fromArray(deck **head, card *arr, size_t size) {
    size_t i = size - 1;
    if (arr == NULL || size == 0) {
        return;
    }
    do {
        push(head, arr[i]);
    } while(i--!=0);
}

//Печатает список
void printLinkedList(const deck *head) {
    while (head) {
        printf("%s %s  ", head->card_in_deck, head->card_in_deck.num);
        head = head->next_card;
    }
    printf("\n");
}
