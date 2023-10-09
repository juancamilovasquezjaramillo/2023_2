#include <iostream>
#include "lista.h"

using namespace std;

int imprimirLista(Lista &l){

    for(int i; i<= l.longLista(); i++){
        cout << l.infoLista(i) << ",";
    }

    cout << "\n";

    return 0
}

int main(){
    Lista l;

    l.anxLista(11);
    l.anxLista(23);
    l.anxLista(17);
    l.anxLista(94);
    l.anxLista(45);
    l.anxLista(33);
    l.anxLista(38);
    l.anxLista(16);

    return 0;
}