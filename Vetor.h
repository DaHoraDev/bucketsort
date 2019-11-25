#include <iostream>
#include <cstdlib> // srand(),rand().
#include <iomanip> // setw().
#include <time.h> //time(), clock().


#define max 1000000

int tam = max;

/*Espaços padrões:*/
using std::cin;
using std::cout;
using std::setw;
using std::endl;

/*Funções:*/
void vCrescente(int *v){
    for(int x = 0; x < tam; x++){
        v[x] = x;
    }
}

void vDecrescente(int *v){
    for(int x = tam; x > 0; x--){
        v[x] = x;
    }
}

void vAleatorio(int *v){
    srand(time(NULL));
    for(int x = 0; x < tam; x++){
        v[x] = rand()%max;
    }
}

void vMostrar(int *v){
    int c = 0;
    for(int x = 0; x < tam; x++) {
        cout<<setw(10)<<x<<"º->"<<setw(7)<<v[x]<<setw(10);
        c++;
        if (c == 6){ // Quebra de linha a cada 6 posições.
            cout<<endl;
            c = 0;
        }
    }
}
