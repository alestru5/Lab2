#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"
Answer *create_stack(int l){
    Answer *ans = malloc(sizeof(Answer));
    ans->m_len = l;
    ans->head = NULL;
    return ans;
}
void push(Answer **ans, char* data, int a) {
    Elements *tmp = malloc(sizeof(Elements));
    if (tmp == NULL) {
	printf("Ошибка выделения памяти");
        exit(-100);
    }
    tmp->next = (*ans)->head;
    tmp->arr = data;
    tmp->type = a;
    (*ans)->head = tmp;
}
void pop(Answer **ans, char **arr1, int *type1) {
    Elements *tmp;
    int value;
    if ((*ans) == NULL) {
        printf("Segment");
    }
    tmp = (*ans)->head;
    (*ans)->head = (*ans)->head->next;
    (*arr1) = tmp->arr;
    (*type1) = tmp->type;
    free(tmp);
}
char *string(char a){
    char *res = malloc(sizeof(char)*2);
    res[0] = a;
    res[1] = '\0';
    return res;
}
void clear(Answer **ans){
    Elements *ptr = (*ans)->head, *ptr2;
    while (ptr){
	ptr2 = ptr;
	free(ptr->arr);
	ptr = ptr->next;
	free(ptr2);
    }
    free(*ans);
}
void output(Answer *ans) {
    char *tmp = malloc(sizeof(char));
    int len = 0;
    Elements *ptr = ans->head;
    while (ptr) {
        for(int i = 0; i < strlen(ptr->arr); i++){
            tmp = realloc(tmp, sizeof(char) * (len + 2));
            tmp[len] = (ptr->arr)[i];
            len += 1;
        }
        ptr = ptr->next;
    }
    char *res = malloc(sizeof(char) * (len+1));
    for(int i = 0; i < len; i++){
        res[i] = tmp[len - i - 1];
    }
    res[len] = '\0';
    printf("%s\n", res);
    free(tmp);
    free(res);
}

