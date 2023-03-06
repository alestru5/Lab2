#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "translate.h"
#if defined USE_VECTOR
#include "vector.h"
#elif defined USE_LIST
#include "list.h"
#endif

void translate(char *line, Answer **ans){
    char *arr1, *arr2;
    for (int i = 0; i < strlen(line); i++){
        char *tmp = string(line[i]);
        if (line[i] != '+' && line[i] != '-' && line[i] != '*' && line[i] != '/'){
	    push(ans, tmp, 0);
        } else{
            int type1, type2;
            pop(ans, &arr1, &type1);
            pop(ans, &arr2, &type2);
            int len1 = strlen(arr1), len2 = strlen(arr2);
            if (((line[i] == '*' || line[i] == '/') && type1 >= 1) || (line[i] == '-' && type1 == 2)){
                arr1 = realloc(arr1, sizeof(char) * (len1 + 3));
                arr1[len1] = '(';
                for (int j = len1+1; j>0; j--){
                    arr1[j] = arr1[j-1];
                }
                arr1[0] = ')';
                arr1[len1 + 2] = '\0';
                len1 += 2;
            }
            if (((line[i] == '*' || line[i] == '/') && type2 >= 1) || (line[i] == '-' && type2 == 2)){
                arr2 = realloc(arr2, sizeof(char) * (len2 + 3));
                arr2[len2] = '(';
                for (int j = len2+1; j>0; j--){
                    arr2[j] = arr2[j-1];
                }
                arr2[0] = ')';
                arr2[len2 + 2] = '\0';
                len2 += 2;
            }
            arr1 = realloc(arr1, sizeof(char) * (len1 + 1));
            arr1[len1] = line[i];
            len1 += 1;
            for (int j = 0; j < len2; j++){
                arr1 = realloc(arr1, sizeof(char) * (len1 + 2));
                arr1[len1] = arr2[j];
                len1 += 1;
            }
            arr1[len1] = '\0';
            if (line[i] == '*' || line[i] == '/'){
                push(ans, arr1, 3);
            }
            else if ('-' == line[i]){
                push(ans, arr1, 2);
            }
            else{
                push(ans, arr1, 1);
            }
            free(arr2);
            free(tmp);
        }
    }
}
