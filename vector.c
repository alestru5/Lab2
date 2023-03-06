#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vector.h"
Answer *create_stack(int l){
	Answer *ans = malloc(sizeof(Answer) * l);
        ans->len = 0;
	ans->m_len = l;
        ans->formula = NULL;
	return ans;
}
void push(Answer **ans, char* data, int a) {
    if ((*ans)->len == (*ans)->m_len - 1){
	printf("STACK_OVERFLOW, выделяю дополнительную память на %d\n", (*ans)->m_len);
	(*ans)->formula = realloc((*ans)->formula, sizeof(Elements) * ((*ans)->m_len) * 2);
	(*ans)->m_len *= 2;
    }else{
    	(*ans)->formula = realloc((*ans)->formula, sizeof(Elements) * ((*ans)->len + 1));
    }
    (*ans)->len +=1;
    (*ans)->formula[(*ans)->len-1].arr = data;
    (*ans)->formula[(*ans)->len-1].type = a;
}
void pop(Answer **ans, char **arr1, int *type1) {
    (*ans)->len -= 1;
    (*arr1) = (*ans)->formula[(*ans)->len].arr;
    (*type1) = (*ans)->formula[(*ans)->len].type;
    (*ans)->formula = realloc((*ans)->formula, sizeof(Elements) * ((*ans)->len));
}
char *string(char a){
    char *res = malloc(sizeof(char)*2);
    res[0] = a;
    res[1] = '\0';
    return res;
}
void clear(Answer **ans){
    for (int i = 0; i < (*ans)->len; i++){
        free((*ans)->formula[i].arr);
    }
    free((*ans)->formula);
    free(*ans);
}
void output(Answer *ans) {
    char *tmp = malloc(sizeof(char));
    int len = 0;
    for (int i = 0; i < ans->len; i++){
        int k = strlen(ans->formula[i].arr);
        for (int j = 0; j < k; j++){
            tmp = realloc(tmp, sizeof(char) * (len + 2));
            tmp[len] = ans->formula[i].arr[j];
            len += 1;
        }
    }
    tmp[len] = '\0';
    char *res = malloc(sizeof(char) * (len+1));
    for(int i = 0; i < len; i++){
        res[i] = tmp[len - i - 1];
    }
    res[len] = '\0';
    printf("%s\n", res);
    free(tmp);
    free(res);
}
