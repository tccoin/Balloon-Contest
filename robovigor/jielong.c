#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define WORDLEN 102

typedef struct {
    void *prev;
    void *next;
    void *value;
    void *ref;
} node;

int vlen;
char start[WORDLEN], dest[WORDLEN], v[WORDLEN][50];

node *newNode(void *prev, void *value) {
    node *n = (node *) malloc(sizeof(node));
    n->prev = prev;
    n->next = NULL;
    n->value = value;
    n->ref = NULL;
    if (prev != NULL) {
        node *prevnode = prev;
        prevnode->next = n;
    }
    return n;
}

node *removeNode(node* n){
    if(n->prev&&n->next){
        ((node*)n->prev)->next = n->next;
        ((node*)n->next)->prev = n->prev;
        return n->next;
    }else if(n->prev){
        ((node*)n->prev)->next = NULL;
        return NULL;
    }else if(n->next){
        ((node*)n->next)->prev = NULL;
        return n->next;
    }else if(n->next){
        return NULL;
    }
}

int diff(char *a, char *b) {
    int i, sum = 0;
    for (i = 0; i < strlen(a); i++)
        if (a[i] != b[i])
            sum++;
    return sum;
}

node *bfs(node *map) {
    node *result = NULL;
    node *queueFront = newNode(NULL, start);
    queueFront->ref = map;
    node *queueBack = queueFront;
    while(1){
        int found = 0;
        while (1) {
            if (diff(queueFront->value, map->value) == 1) {
                queueBack = newNode(queueBack, map->value);
                queueBack->prev = queueFront; // [1]记录上一路过的节点 
                queueBack->ref = map; // [2]标记路过的节点（可能和其它路径共用，暂时不删除） 
                if (diff(map->value, dest) == 1) { // [3]找到最短路径！ 
                    found = 1;
                    result = newNode(result, queueBack); // [4]记录结果 
                }
            }
            if(map&&map->next){
                map = map->next;
            } else{
                break;
            }
        }
        queueBack = newNode(queueBack, "step"); // [3]标记步数 
        removeNode(queueFront->ref); // [2]删除路过的节点 
        queueFront = queueFront->next;
        if(strcmp(queueFront->value,"step")==0){ // [3]如果这步走完了且发现最短路径则结束查找
            if(found) break; // [3]如果这步走完了且发现最短路径则结束查找 
            queueFront = queueFront->next; // 不然继续查找这一步的路径 
        }
        while(map->prev!=NULL) map = map->prev;
    }
    return result;
}

int main() {
    int i;
    node *map = NULL;
    // input
    scanf("%s %s", start, dest);
    scanf("%d", &vlen);
    for (i = 0; i < vlen; i++) {
        char *str = malloc(WORDLEN * sizeof(char));
        scanf("%s", str);
        map = newNode(map, str);
    }
    // search
    while (map->prev!=NULL)
        map = map->prev;
    node *result = bfs(map);
    // output
    while (result!=NULL) {
        node *queue = result->value;
        printf("%s", dest);
        while (queue!=NULL) {
            printf("<-%s", queue->value);
            queue = queue->prev; // [1]输出上一节点 
        }
        printf("\n");
        result = result->prev;
    }
    return 0;
}
