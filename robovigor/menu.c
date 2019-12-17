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
    sprintf(msg, "共计消费%.2f元，您pay吗？", cost);
}

void callHuman() { strcpy(msg, "嗯嗯，亲，好的呢，亲！"); }

void complain() { strcpy(msg, "好的！我知道了！"); }

int main() {
    setlocale(LC_ALL, "");
    // set
    MenuItem mainMenu[4] = {{"炫酷点菜", NULL, NULL, NULL},
                            {"我来买单", NULL, pay, NULL},
                            {"性感人工", NULL, callHuman, NULL},
                            {"在线投诉", NULL, complain, NULL}};
    MenuItem subMenu[4] = {{"￥3.14 糖醋硬币", NULL, NULL, orders},
                           {"￥1.59 水煮纸片", NULL, NULL, orders + 1},
                           {"￥2.65 随机菜肴", NULL, NULL, orders + 2},
                           {"下了个单！", NULL, NULL, NULL}};
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
        printf("\n  超?好吃食品有限公司\n\n");
        printf("\n  ********************\n\n");
        for (i = 0; i < 4; i++) {
            printf("    ");
            renderingItem = &((*currentMenu)[i]);
            printf(i == currentIndex ? "> " : "  ");
            printf("%s", renderingItem->title);
            if (renderingItem->value) {
                printf(" ×%d", *renderingItem->value);
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
