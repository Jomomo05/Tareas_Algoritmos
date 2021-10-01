#include <iostream>
#include "LinkedList.h"

using namespace std;

template <class T>
void imprimir(LinkedList<T>); //Funcion que imprime todos los valores de la LinkedList

template <class T>
void imprimir(LinkedList<T> lista){
    lista.printAll();
}

template <class T>
void create(LinkedList<T> lista, T dato); //Funcion que inserta un dato al final de la LinkedList y muestra la lista despues del cambio

template <class T>
void create(LinkedList<T> lista, T dato){
    lista.addLast(dato);
    lista.printAll();
}

template <class T>
void search(LinkedList<T> lista, T dato);

template <class T>
void search(LinkedList<T> lista, T dato){
    lista.search(dato);
}






int main(){
    LinkedList<int> lista;
    lista.addFirst(5);
    lista.addLast(6);
    imprimir(lista);
    lista.addLast(7);
    imprimir(lista);

    create(lista, 8);
    imprimir(lista);

    search(lista, 7);

    

    //search(lista, "Jupiter");
    //lista.deleteAll();


    
    return 0;
}