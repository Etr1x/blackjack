#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include "stack.h"

typedef struct player   //структура игрока
{
    card *hand;
} player;

//функция суммы значений карт:
int sum(player a, int count) {   
    int summ = 0;
    for (int i = 1; i <= count; i++) {
        if (strchr(a.hand[i].num, '2') != NULL) {
            summ = summ + 2;
        }
        if (strchr(a.hand[i].num, '3') != NULL) {
            summ = summ + 3;
        }
        if (strchr(a.hand[i].num, '4') != NULL) {
            summ = summ + 4;
        }
        if (strchr(a.hand[i].num, '5') != NULL) {
            summ = summ + 5;
        }
        if (strchr(a.hand[i].num, '6') != NULL) {
            summ = summ + 6;
        }
        if (strchr(a.hand[i].num, '7') != NULL) {
            summ = summ + 7;
        }
        if (strchr(a.hand[i].num, '8') != NULL) {
            summ = summ + 8;
        }
        if (strchr(a.hand[i].num, '9') != NULL) {
            summ = summ + 9;
        }
        if (strchr(a.hand[i].num, '10') != NULL) {
            summ = summ + 10;
        }
        if (strchr(a.hand[i].num, 'В') != NULL) {
            summ = summ + 10;
        }
        if (strchr(a.hand[i].num, 'Д') != NULL) {
            summ = summ + 10;
        }
        if (strchr(a.hand[i].num, 'К') != NULL) {
            summ = summ + 10;
        }
        if ((strchr(a.hand[i].num, 'Т') != NULL) && (summ <= 21))  {
            summ = summ + 11;
        }
        if ((strchr(a.hand[i].num, 'Т') != NULL) && (summ > 21)) {
            summ = summ + 1;
        }
    }
    return summ;
}   


int main(void) {
    //создание карт
    card c2 = {"Пики", "2"};
    card p2 = {"Червы", "2"};
    card k2 = {"Трефы", "2"};
    card b2 = {"Бубны", "2"};
    card c3 = {"Пики", "3"};
    card p3 = {"Червы", "3"};
    card k3 = {"Трефы", "3"};
    card b3 = {"Бубны", "3"};
    card c4 = {"Пики", "4"};
    card p4 = {"Червы", "4"};
    card k4 = {"Трефы", "4"};
    card b4 = {"Бубны", "4"};
    card c5 = {"Пики", "5"};
    card p5 = {"Червы", "5"};
    card k5 = {"Трефы", "5"};
    card b5 = {"Бубны", "5"};
    card c6 = {"Пики", "6"};
    card p6 = {"Червы", "6"};
    card k6 = {"Трефы", "6"};
    card b6 = {"Бубны", "6"};
    card c7 = {"Пики", "7"};
    card p7 = {"Червы", "7"};
    card k7 = {"Трефы", "7"};
    card b7 = {"Бубны", "7"};
    card c8 = {"Пики", "8"};
    card p8 = {"Червы", "8"};
    card k8 = {"Трефы", "8"};
    card b8 = {"Бубны", "8"};
    card c9 = {"Пики", "9"};
    card p9 = {"Червы", "9"};
    card k9 = {"Трефы", "9"};
    card b9 = {"Бубны", "9"};
    card c10 = {"Пики", "10"};
    card p10 = {"Червы", "10"};
    card k10 = {"Трефы", "10"};
    card b10 = {"Бубны", "10"};
    card cV = {"Пики", "Валет"};
    card pV = {"Червы", "Валет"};
    card kV = {"Трефы", "Валет"};
    card bV = {"Бубны", "Валет"};
    card cD = {"Пики", "Дама"};
    card pD = {"Червы", "Дама"};
    card kD = {"Трефы", "Дама"};
    card bD = {"Бубны", "Дама"};
    card cK = {"Пики", "Король"};
    card pK = {"Червы", "Король"};
    card kK = {"Трефы", "Король"};
    card bK = {"Бубны", "Король"};
    card cT = {"Пики", "Туз"};
    card pT = {"Червы", "Туз"};
    card kT = {"Трефы", "Туз"};
    card bT = {"Бубны", "Туз"};

    //сбор упорядоченного массива карт:
    card deck_list[52] = {c2, p2, k2, b2, c3, p3, k3, b3, c4, p4, k4, b4, c5, p5, k5, b5, c6, p6, k6, b6, c7, p7, k7, b7, c8, p8, k8, b8, c9, p9, k9, b9, c10, p10, k10, b10, cV, pV, kV, bV, cD, pD, kD, bD, cK, pK, kK, bK, cT, pT, kT, bT};
    deck* head = NULL;

    unsigned t = time(0);
    srand(t);
    
    //перетасовка карт в массиве:
    for (unsigned i = 0; i < 52; ++i){
        unsigned j = rand() % ((52 - i) + i);
        card t = deck_list[j];
        deck_list[j] = deck_list[i];
        deck_list[i] = t;
    }
    
    //чтоб русские буковки печатались:
    system("chcp 65001>NULL");
    setlocale(LC_ALL, NULL);
    
    //Сбор стека:
    fromArray(&head, deck_list, 52);
    
    //Печать стека(дебаг):
    //printLinkedList(head);
    //printf("\n");

    printf("Перетасовка карт...\n");
    printf("Начало игры:\n");
    player dealer;  //обьявление дилера
    player me;  //обьявление игрока
    dealer.hand = (card*)malloc(10 * sizeof(card)); //освобождение памяти под карты
    me.hand = (card*)malloc(10 * sizeof(card)); //освобождение памяти под карты

    dealer.hand[1] = pop(&head); //взятие 1 карты из списка для дилера
    printf("В руке у дилера: ");
    printf("%s %s           Сумма: %d\n", dealer.hand[1].num, dealer.hand[1].suit, sum(dealer, 1));  //печать карты и суммы
    printf("\n");

    me.hand[1] = pop(&head); //взятие 1 карты из списка для игрока
    me.hand[2] = pop(&head); //взятие 2 карты из списка для игрока
    printf("Ваша рука: ");
    printf("%s %s, %s %s           Сумма: %d\n", me.hand[1].num, me.hand[1].suit, me.hand[2].num, me.hand[2].suit, sum(me, 2)); //печать карт и суммы


    //проверка на блекджек с первого хода:
    if (sum(me, 2) == 21) {
        printf("Блекджек!");
        exit(0);
    }

    //игрок берет карты:
    int count1 = 2;
    int i = 1;
    while (sum(me, count1) < 21){
        char ch;
        count1 = count1 + i;

        printf("Брать?\n");
        printf("1.Да 2.Нет\n");

        ch = _getch();
        switch (ch) {
        case '1':
            me.hand[count1] = pop(&head); // взятие 2+i карты

            printf("Вы взяли: %s %s             Новая сумма: %d\n", me.hand[count1].num, me.hand[count1].suit, sum(me, count1)); //печать карты и суммы

            //проверка на блекджек:
            if (sum(me, count1) == 21){
                printf("Блекджек!\n");
                printf("Вы выиграли!!\n");
                exit(0);
            }

            //проверка на перебор:
            if (sum(me, count1) > 21){
                printf("Перебор!\n");
                printf("Вы проиграли :(\n");
                exit(0);
            }
            break;

        case '2':
            printf("Хватит\n");
            printf("\n");
            break;
        default:
            printf("Введен неправильный символ!\n");
            break;
        }
        if (ch == '2'){
            break;
        }
    }

    //дилер берет карты:
    printf("Дилер:\n");
    printf("1-я Карта дилера: %s %s\n", dealer.hand[1].num, dealer.hand[1].suit); //печать карты
    int j = 1;
    int count = 1;
    while(sum(dealer, count) <= 17) {
        count = count + j;
        dealer.hand[count] = pop(&head); //взятие 1+j карты
        printf("Дилер взял карту %d: %s %s\n", count, dealer.hand[count].num, dealer.hand[count].suit); //печать карты
        printf("Сумма у дилера: %d\n", sum(dealer, count)); //печать суммы

        if (sum(dealer, count) == 21){          //проверка на блекджек у дилера
                printf("Блекджек у дилера!\n");
                printf("Вы проиграли :(\n");
                exit(0);
        }
        if (sum(dealer, count) > 21){    //проверка на перебор у дилера
            printf("Перебор у дилера\n");
            printf("Вы выиграли!!\n");
            exit(0);
        }
    
    }
    //Финал:
    printf("Ваша сумма: %d\n", sum(me, count1)); // вывод моей суммы для удобства
    //Проверка на ничью:
    if (sum(me, count1) == sum(dealer, count)) {
        printf("Ничья!");
        exit(0);
    }

    //Проверка на выигрыш игрока:
    if (sum(me, count1) > sum(dealer, count)) {
        printf("Вы выиграли!!\n");
        exit(0);
    }

    //Проверка на проигрыш игрока:
    if (sum(me, count1) < sum(dealer, count)) {
        printf("Вы проиграли :(\n");
        exit(0);
    }

    return 0;
}