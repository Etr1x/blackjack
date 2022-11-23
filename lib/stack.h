typedef struct card 
{
    char suit[15];
    char num[20];
} card;

typedef struct deck {
    card card_in_deck;
    struct deck *next_card;
} deck;

void push(deck **head, card card_to_add);
card pop(deck **head);
deck* getNth(deck* head, int n);
deck* getLast(deck *head);
void pushBack(deck *head, card value);
int popBack(deck **head);
void insert(deck *head, unsigned n, card val);
card deleteNth(deck **head, int n);
void fromArray(deck **head, card *arr, size_t size);
void printLinkedList(const deck *head);
