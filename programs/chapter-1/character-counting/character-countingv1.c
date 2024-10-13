#include <stdio.h>

int main()
{
    int nc;

    nc = 0;
    while (getchar() != EOF){
        ++nc;
        printf("%1d\n", nc);
    }
}

/* 

can also be a for loop
int main()
{
    int nc;

    for (nc = 0; getchar() != EOF; ++nc){
    ;}
    printf("%.0f\n", nc)
} */

//the body of this for loop is emptty because all the work is done in the terst and increment parts abd C requires a for statement have a boy.