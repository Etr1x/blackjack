#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

typedef struct card 
{
    char suit;
    char num;
} card;


typedef struct deck {
    card card_in_deck;
    struct deck *next_card;
} deck;

card create_card(char suit, char num) {
    card a;
    a.suit = suit;
    a.num = num;

    return a;
}

// int rand_deck_list(card deck_list) {
    
//     card random_deck_list[51];

// }

void push(deck **head, card card_to_add) {
    deck *tmp = (deck*) malloc(sizeof(deck));
    tmp->card_in_deck = card_to_add;
    tmp->next_card = (*head);
    (*head) = tmp;
}

void fromArray(deck **head, card *arr, size_t size) {
    size_t i = size - 1;
    if (arr == NULL || size == 0) {
        return;
    }
    do {
        push(head, arr[i]);
    } while(i--!=0);
}

void printLinkedList(const deck *head) {
    while (head) {
        printf("%c %c\n", head->card_in_deck, head->card_in_deck.num);
        head = head->next_card;
    }
    printf("\n");
}


int main(void) {
    card c2 = {'c', '2'};
    card p2 = {'p', '2'};
    card k2 = {'k', '2'};
    card b2 = {'b', '2'};

    card c3 = {'c', '3'};
    card p3 = {'p', '3'};
    card k3 = {'k', '3'};
    card b3 = {'b', '3'};

    card c4 = {'c', '4'};
    card p4 = {'p', '4'};
    card k4 = {'k', '4'};
    card b4 = {'b', '4'};

    card c5 = {'c', '5'};
    card p5 = {'p', '5'};
    card k5 = {'k', '5'};
    card b5 = {'b', '5'};

    card c6 = {'c', '6'};
    card p6 = {'p', '6'};
    card k6 = {'k', '6'};
    card b6 = {'b', '6'};

    card c7 = {'c', '7'};
    card p7 = {'p', '7'};
    card k7 = {'k', '7'};
    card b7 = {'b', '7'};

    card c8 = {'c', '8'};
    card p8 = {'p', '8'};
    card k8 = {'k', '8'};
    card b8 = {'b', '8'};

    card c9 = {'c', '9'};
    card p9 = {'p', '9'};
    card k9 = {'k', '9'};
    card b9 = {'b', '9'};

    card c10 = {'c', '10'};
    card p10 = {'p', '10'};
    card k10 = {'k', '10'};
    card b10 = {'b', '10'};

    card cV = {'c', 'v'};
    card pV = {'p', 'v'};
    card kV = {'k', 'v'};
    card bV = {'b', 'v'};

    card cD = {'c', 'd'};
    card pD = {'p', 'd'};
    card kD = {'k', 'd'};
    card bD = {'b', 'd'};

    card cK = {'c', 'k'};
    card pK = {'p', 'k'};
    card kK = {'k', 'k'};
    card bK = {'b', 'k'};

    card cT = {'c', 't'};
    card pT = {'p', 't'};
    card kT = {'k', 't'};
    card bT = {'b', 't'};


    card deck_list[52] = {c2, p2, k2, b2, c3, p3, k3, b3, c4, p4, k4, b4, c5, p5, k5, b5, c6, p6, k6, b6, c7, p7, k7, b7, c8, p8, k8, b8, c9, p9, k9, b9, c10, p10, k10, b10, cV, pV, kV, bV, cD, pD, kD, bD, cK, pK, kK, bK, cT, pT, kT, bT};
    // for (int i = 0; i <= 51; i++) {
    //     printf("%c %c\n", deck_list[i].num, deck_list[i].suit); 
    // }   
    deck* head = NULL;
    int mf = time(0);
    printf("%d", mf);
    fromArray(&head, deck_list, 52);
    printLinkedList(head);
    //printf("%c", (int)98);
    return 0;
}