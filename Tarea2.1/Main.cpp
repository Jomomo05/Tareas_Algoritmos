
//Actividad 2.1 Estructura de datos y algoritmos fundamentales
//Hecho por: Jose Miguel Beltran Cinco A00227714
//A 30 de septiembre del 2021
//El presente codigo creara una Linked List y aplicara las diferentes palabras de CRUD.
#include <iostream>
#include "LinkedList.h"
#include <string>
#include <fstream>

using namespace std;

//Para las clases, con el proposito de no formar la dependencia como un metodo, decidi funciones que pasaran los respectivos metodos para su procedimiento.
//Vease LinkedList.h para ver mas detalles de su funcionamiento
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
void read(LinkedList<T> lista, T dato); //Funcion que busca en que posicion (iniciando desde 0) se encuentra el elemento provisto

template <class T>
void read(LinkedList<T> lista, T dato){
    lista.search(dato);
}

template <class T>
void update(LinkedList<T> lista, int posicion, T dato); //Funcion que busca un dato por posicion y lo sustituye por otro. Error si posicion > tamaño del LinkedList

template <class T>
void update(LinkedList<T> lista, int posicion, T dato){
    lista.update(posicion, dato);
    lista.printAll(); //Revisar el cambio
}

template <class T>
void del(LinkedList<T> lista, int posicion);

template <class T>
void del(LinkedList<T> lista, int posicion){
    lista.dele(posicion);
    lista.printAll();
}

int main(){
    LinkedList<int> lista; //Creacion de LinkedList lista
    
    //Lectura de elementos
    ifstream in("caso1.txt"); // Primer valor del archivo es el tamaño del arreglo
    string s;
    getline(in, s);
    int n = stoi(s);
    int *arreglo = new int[n];
    int i = 0;
    while(getline(in, s)){
        lista.addLast(stoi(s));
        i++;
    }
    in.close();
    imprimir(lista);
    cout << " " << endl;

    create(lista, 8);//Creacion de un nuevo elemento al final de lista
    cout << " " << endl;
    read(lista, 5); //Busqueda del numero, devuelve cuantas veces se encuentra en la lista y en que posicion
    cout << " " << endl;
    update(lista, 3, 5); //Modificar el cuarto elemento de la lista (3 porque inicia en 0) de la lista, si el eelemento de posicion es mas grande: Error.
    cout << " " << endl;
    del(lista, 2); //Eliminar el tercer elemento de la lista 

    return 0;
}