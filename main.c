#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN  10
#include "input.h"
#include "translate.h"
#if defined USE_VECTOR
#include "vector.h"
#elif defined USE_LIST
#include "list.h"
#endif
int main() {
    int f = 1;
    while (f == 1){
	Answer *ans = create_stack(MAX_LEN);
        char *line = malloc(sizeof(char));
        f = input(&line);
        if (f == 1) {
            translate(line, &ans);
	    output(ans);
        } else{
            printf("End\n");
        }
	clear(&ans);
        free(line);
    }
    return 0;
}

