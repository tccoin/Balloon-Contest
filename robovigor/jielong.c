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
                queueBack->prev = queueFront; // [1]��¼��һ·���Ľڵ� 
                queueBack->ref = map; // [2]���·���Ľڵ㣨���ܺ�����·�����ã���ʱ��ɾ���� 
                if (diff(map->value, dest) == 1) { // [3]�ҵ����·���� 
                    found = 1;
                    result = newNode(result, queueBack); // [4]��¼��� 
                }
            }
            if(map&&map->next){
                map = map->next;
            } else{
                break;
            }
        }
        queueBack = newNode(queueBack, "step"); // [3]��ǲ��� 
        removeNode(queueFront->ref); // [2]ɾ��·���Ľڵ� 
        queueFront = queueFront->next;
        if(strcmp(queueFront->value,"step")==0){ // [3]����ⲽ�������ҷ������·�����������
            if(found) break; // [3]����ⲽ�������ҷ������·����������� 
            queueFront = queueFront->next; // ��Ȼ����������һ����·�� 
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
            queue = queue->prev; // [1]�����һ�ڵ� 
        }
        printf("\n");
        result = result->prev;
    }
    return 0;
}
