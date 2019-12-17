#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

enum direction { UP = 0, DOWN, LEFT, RIGHT };
enum state { PLAY, WIN, LOSE };

typedef struct {
    int x;
    int y;
    void *next;
} node;

struct {
    int width;
    int height;
    int snakeMoveInterval;
    int appleRefreshInterval;
    int detectInputInterval;
    int intervalms;
} gameSetting;

struct {
    int state;
    int tick;
    int direction;
    int score;
    node *head;
    node *tail;
    node *apple;
} gameState;

int IsSnake(int x, int y) {
    node *temp = gameState.head;
    while (1) {
        if (x == temp->x && y == temp->y)
            return 1;
        if (temp->next != NULL) {
            temp = (node *)temp->next;
        } else {
            break;
        }
    }
    return 0;
}

int IsWin() {
    return gameState.score ==
           (gameSetting.width - 2) * (gameSetting.height - 2) - 3;
}

int IsFruit(int x, int y) {
    return x == gameState.apple->x && y == gameState.apple->y;
}

int IsWall(int x, int y) {
    return y == 0 || y == gameSetting.height - 1 || x == 0 ||
           x == gameSetting.width - 1;
}

node *CreateNode(int x, int y) {
    node *newNode = (node *)malloc(sizeof(node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void HeadMove(int x, int y) {
    node *newBody = CreateNode(x, y);
    newBody->next = gameState.head;
    gameState.head = newBody;
}

void BodyPop() {
    node *newtail = gameState.head;
    while (((node *)newtail->next)->next != NULL) {
        newtail = (node *)newtail->next;
    }
    free(gameState.tail);
    newtail->next = NULL;
    gameState.tail = newtail;
}

void FreeQueue(node *head) {
    node *temp = head;
    node *tempnext = head;
    while (1) {
        if (temp->next != NULL) {
            tempnext = (node *)temp->next;
            free(temp);
            temp = tempnext;
        } else {
            free(temp);
            break;
        }
    }
}

void SnakeInit() {
    node *snake[3];
    int i;
    for (i = 0; i < 3; i++) {
        snake[i] =
            CreateNode(gameSetting.width / 2, gameSetting.height / 2 + i);
    }
    snake[0]->next = snake[1];
    snake[1]->next = snake[2];
    gameState.head = snake[0];
    gameState.tail = snake[2];
}

void AppleUpdate() {
    node *apple = gameState.apple;
    do {
        srand(time(0));
        apple->x = rand() % (gameSetting.width - 2) + 1;
        apple->y = rand() % (gameSetting.height - 2) + 1;
    } while (IsSnake(apple->x, apple->y));
}

void AppleInit() {
    gameState.apple = CreateNode(1, 1);
    AppleUpdate();
}

void InputUpdate() {
    if (GetKeyState(VK_UP) < 0 && gameState.direction >= 2)
        gameState.direction = UP;
    if (GetKeyState(VK_DOWN) < 0 && gameState.direction >= 2)
        gameState.direction = DOWN;
    if (GetKeyState(VK_LEFT) < 0 && gameState.direction < 2)
        gameState.direction = LEFT;
    if (GetKeyState(VK_RIGHT) < 0 && gameState.direction < 2)
        gameState.direction = RIGHT;
}

int moveTableX[4] = {0, 0, -1, 1};
int moveTableY[4] = {-1, 1, 0, 0};

void SnakeUpdate() {
    node *head = gameState.head;
    node *body = (node *)head->next;
    node *tail = gameState.tail;
    // move forward
    int newX = head->x + moveTableX[gameState.direction];
    int newY = head->y + moveTableY[gameState.direction];
    if (newX == gameState.apple->x && newY == gameState.apple->y) {
        gameState.score += 10;
        if (IsWin()) {
            gameState.state = WIN;
        } else {
            AppleUpdate();
        }
    } else {
        BodyPop();
    }
    if (IsWall(newX, newY) || IsSnake(newX, newY)) {
        gameState.state = LOSE;
    } else {
        HeadMove(newX, newY);
    }
}

void ClockUpdate() { gameState.tick = (gameState.tick % 100) + 1; }

void RendererUpdate() {
    int x, y;
    system("cls");
    for (int y = 0; y < gameSetting.height; y++) {
        for (int x = 0; x < gameSetting.width; x++) {
            if (IsWall(x, y)) {
                printf("□");
            } else if (IsSnake(x, y)) {
                printf("■");
            } else if (IsFruit(x, y)) {
                printf("●");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("分数：%d\n", gameState.score);
}

void RunGame() {
    SnakeInit();
    AppleInit();
    RendererUpdate();
    while (1) {
        ClockUpdate();
        if (gameState.tick % gameSetting.detectInputInterval == 0) {
            InputUpdate();
        }
        if (gameState.tick % gameSetting.snakeMoveInterval == 0) {
            SnakeUpdate();
        }
        if (gameState.tick % gameSetting.appleRefreshInterval == 0) {
            // AppleUpdate();
        }
        if (gameState.state == LOSE || gameState.state == WIN) {
            system("cls");
            printf(gameState.state == LOSE ? "游戏结束！"
                                           : "游戏结束，你赢啦！");
            printf("你的得分是%d。\n\n按任意键重来，按q退出。",
                   gameState.score);
            return;
        } else {
            if (gameState.tick % gameSetting.snakeMoveInterval == 0) {
                RendererUpdate();
            }
        }
        Sleep(gameSetting.intervalms);
    }
}

int main() {
    gameSetting.width = 19;
    gameSetting.height = 19;
    gameSetting.snakeMoveInterval = 1;
    gameSetting.appleRefreshInterval = gameSetting.snakeMoveInterval * 50;
    gameSetting.detectInputInterval = 1;
    gameSetting.intervalms = 50;
    do {
        gameState.state = PLAY;
        gameState.tick = 0;
        gameState.direction = UP;
        gameState.score = 0;
        RunGame();
        FreeQueue(gameState.head);
        FreeQueue(gameState.apple);
    } while (getchar() != 'q');
    return 0;
}
