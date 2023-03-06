#ifndef VECTOR_H
#define VECTOR_H
typedef struct Elements {
    int type;
    char *arr;
} Elements;
typedef struct Answer{
    int len;
    int m_len;
    Elements *formula;
} Answer;
Answer *create_stack(int l);
void push(Answer **ans, char* data, int a);
void pop(Answer **ans, char **arr1, int *type1);
char *string(char a);
void clear(Answer **ans);
#endif
