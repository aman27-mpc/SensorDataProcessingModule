#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct st{
    int rollno;
    char name[10];
    float marks;
    struct ST *next;
}ST;

