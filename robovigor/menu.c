#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

typedef void (*MenuFunction)();
typedef struct s{
    char title[20];
    struct s *next;
    MenuFunction func;
    int *value;
} MenuItem;

char msg[20];
int orders[3] = {0, 0, 0};

void pay() {
    float cost = orders[0] * 3.14 + orders[1] * 1.59 + orders[2] * 2.65;
    sprintf(msg, "��������%.2fԪ����pay��", cost);
}

void callHuman() { strcpy(msg, "���ţ��ף��õ��أ��ף�"); }

void complain() { strcpy(msg, "�õģ���֪���ˣ�"); }

int main() {
    setlocale(LC_ALL, "");
    // set
    MenuItem mainMenu[4] = {{"�ſ���", NULL, NULL, NULL},
                            {"������", NULL, pay, NULL},
                            {"�Ը��˹�", NULL, callHuman, NULL},
                            {"����Ͷ��", NULL, complain, NULL}};
    MenuItem subMenu[4] = {{"��3.14 �Ǵ�Ӳ��", NULL, NULL, orders},
                           {"��1.59 ˮ��ֽƬ", NULL, NULL, orders + 1},
                           {"��2.65 �������", NULL, NULL, orders + 2},
                           {"���˸�����", NULL, NULL, NULL}};
    mainMenu[0].next = &subMenu;
    subMenu[3].next = &mainMenu;
    // update
    MenuItem(*currentMenu)[4] = mainMenu;
    int currentIndex = 0;
    MenuItem *currentItem;
    MenuItem *renderingItem;
    while (1) {
        currentItem = &((*currentMenu)[currentIndex]);
        // render
        system("cls");
        int i, j;
        printf("\n  ��?�ó�ʳƷ���޹�˾\n\n");
        printf("\n  ********************\n\n");
        for (i = 0; i < 4; i++) {
            printf("    ");
            renderingItem = &((*currentMenu)[i]);
            printf(i == currentIndex ? "> " : "  ");
            printf("%s", renderingItem->title);
            if (renderingItem->value) {
                printf(" ��%d", *renderingItem->value);
            }
            printf("\n");
        }
        printf("\n  ********************\n\n");
        printf("  %s", msg);
        // control
        int control;
        while ((control = getch()) == 224) {
        }

        switch (control) {
        case 13:
            // Enter
            if (currentItem->next) {
                currentMenu = currentItem->next;
                currentIndex = 0;
            }
            if (currentItem->func) {
                currentItem->func();
            }
            break;
        case 72:
            // Up
            currentIndex = currentIndex > 0 ? currentIndex - 1 : 0;
            break;
        case 80:
            // Down
            currentIndex = currentIndex < 3 ? currentIndex + 1 : 3;
            break;
        case 75:
            // Left
            if (currentItem->value) {
                (*currentItem->value)--;
            }
            break;
        case 77:
            // Right
            if (currentItem->value) {
                (*currentItem->value)++;
            }
            break;
        default:
            printf("%d\n", control);
        }
    }
    return 0;
}
