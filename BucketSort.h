#include <stdlib.h> //usar o malloc
#define L 1000000 //tive que colocar o tamanho do vetor do balde do tamanho do "tam" #bug?

/*Estrututa do balde:*/
typedef struct balde{
    int quant;
    int val[L];
}balde;

/*Funções*/
void CountingSort(int *v, int t){
    int balde[t];
    for(int i = 0; i < t; i++){
        balde[i] = 0;
    }
    for(int i = 0; i < t; i++){
        balde[v[i]]++;
    }
    for(int i = 0, j = 0; j < t; j++){
        for(int k = balde[j]; k > 0; k-- ){
            v[i++] = j;
        }
    }
}

void BucketSort(int *v, int t){
    int ma,me,nbaldes,pos;
    balde *bd;
    ma = me = v[0];
    for(int i = 1; i < t; i ++){
        if(v[i] > ma){
            ma = v[i];
        }
        if(v[i]< me){
            me = v[i];
        }
    }
    nbaldes = (ma - me) / L + 1;
    bd = (balde*)malloc(nbaldes*sizeof(balde));

    for(int i = 0; i < nbaldes; i ++){
        bd[i].quant = 0;
    }

    for(int i = 0; i < t; i ++){
        pos = (v[i] - me) / L;
        bd[pos].val[bd[pos].quant] = v[i];
        bd[pos].quant++;
    }

    pos = 0;
    for(int i = 0; i < nbaldes; i++){
       CountingSort(bd[i].val, bd[i].quant);
       for(int j = 0; j < bd[i].quant; j++){
           v[pos] = bd[i].val[j];
           pos++;
       }
    }
    free(bd);
}

