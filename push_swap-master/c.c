#include <stdio.h>

typedef struct s {
    enum { INT, CHAR} type;
    union {
        int integer;
        char *string;
    };
}               t_st;

int main() {
    t_st obj;

    obj.type = INT;
    obj.integer = 123;
    
}