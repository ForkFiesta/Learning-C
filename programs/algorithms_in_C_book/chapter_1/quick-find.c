#include <stdio.h>

#define N 10000

int main(){
    int i, p, q, t, id[N];

    for (i = 0; i < N; i++){
        id[i] = i; //assign each index value it's index.,id[1] =1, id[2] = 2
    }
    
    while (scanf("%d %d\n", &p, &q) == 2){
        if (id[p] == id[q]){
            continue;
        }
        for (t = id[p], i = 0; i < N; i++){
            if (id[i] == t){
                id[i] = id[q];
            }
        } 
        printf(" %d %d\n", p, q);
    }

    return 0;
}