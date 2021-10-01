#ifndef __LinkedList_h__
#define __LinkedList_h__

#include "Node.h"
#include <iostream>

using namespace std;
//Creacion de Clase LinkedList
template <class T>
class LinkedList{
    private:
        Node<T> *head;
        int size;
    public:
        LinkedList();
        ~LinkedList();
        void deleteAll();

        void addFirst(T data);
        void addLast(T data);
        void printAll(); //Funcion para print de toda la linked list linea por linea
        void search(T dato); //Funcion que busca un dato y devuelve cuando lo encuentra, y que tantas veces
        void update(int posicion, T dato); //Actualizar un dato segun su posicion
        void dele(int posicion); //Borrar un dato segun su posicion
};

//Plantilla base, siempre hay uno que sea nullptr esperando instrucciones
template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    size = 0;
}
//Para borrar todo
template <class T>
LinkedList<T>::~LinkedList(){
    deleteAll();
}
//Funcion para borrar todos los nodos de la linked list
//COmplejidad: O(n) solo depende de la longitud del la lista
template <class T>
void LinkedList<T>::deleteAll(){
    Node<T> *current = head;
    while(head != nullptr){
        head = head->getNext();
        delete current;
        current = head;
    }
    size = 0;
}

//Funcion para anadir al inicio un elemento
//Complejidad O(1), es constante, siempre se toma en cuenta la head y el valor antes de ella (se mueve)
template <class T>
void LinkedList<T>::addFirst(T data){
    head = new Node<T>(data, head);
    size++;
}
//Funcion para anadir al final un elemento
//Complejidad O(n), recorre la lista hasta el final.
//Si tuvieramos uan funcion tail, seria constante como addFirst
template <class T>
void LinkedList<T>::addLast(T data){
    Node<T> *current = head;
    if(size == 0){
        addFirst(data);
        return;
    }
    while(current->getNext() != nullptr){
        current = current->getNext();
    }

    current->setNext(new Node<T>(data));
    size++;
}

//Funcion para mostrar todos los elementos
//Analisis: O(n) debido a que el ciclo while avanza de 1 en 1 y no solo depende de la longitud de la LinkedList
template <class T>
void LinkedList<T>::printAll(){
    Node<T> *current = head; //Elemento inicial (head)
    current->printNode(); //Imprimir el elemento inicial

    while(current->getNext() != nullptr){ //Hasta llegar al Nullptr, es decir, el final de la LL.
        //current->printNode();
        current = current->getNext();
        current->printNode(); //Imprimir la informacion del Nodo
    }
}
//Funcion para buscar un elemento en la LinkedList
//Analisis de complejidad: O(n). Revisa todos los elementos uno por uno en caso de hayar incosistencias, el mejor caso sigue siendo O(n) debido a esto
//Solo depende de la longitud de la LL.
template <class T>
void LinkedList<T>::search(T dato){
    Node<T> *current = head;
    //current->printNode();

    int contador = 0; //Contaodr de iteraciones
    int elementos = 0; //Elementos iguales contados

    cout << "Se busco el elemento " << dato << endl; //Senalizar el elemento

    while(current != nullptr){ //Del inicio hasta el final (head hasta nullptr o tail)
        if (current->getData() == dato){
            elementos++;
            cout << "Se encontro en el lugar: " << contador << endl; //Marcar si encuentran un elemento
        }
        current = current->getNext(); //Obtener el siguiete elemento
        //current->printNode();
        contador++;
    }

    if (elementos == 0){ 
        cout << "No se encontraron coincidencias" << endl; //Mensaje si no se encontro
    }else {
        cout << "Se encontraron " << elementos << " Coincidencias" << endl; //Mensaje si se encontraron y cuantos elementos
    }
}

//Funcion para cambiar el valor de un dato, depende de la posicion del dato que se da(que puede ser error)
//Complejidad: O(n). El mejor caso es que la posicion sea la primera, el peor caso es que sea la final
//Como solo es un ciclo while que dependee de los turnos hasta llegar al final (nullptr), no hay otros factores o bucles que interfieran.
template <class T>
void LinkedList<T>::update(int posicion, T dato){
    Node<T> *current = head; //Datos de head
    //current->printNode();

    int contador = 0;
    if (posicion <= size){ //Asegurar que la posicion sea viable, si no, error.
        while(current != nullptr){ //Bucle hasta el final
        if (contador == posicion){
            current->setData(dato); //Cambiar el valor del nodo en la iteracion(posicion) solicitada.
        }
        current = current->getNext(); //Siguiente
        //current->printNode();
        contador++; //Aumento contador
        }
    }else{
        cout << "Posicion demasiado grande, ingrese de nuevo" << endl; //Mensaje de error
    }
}

//Funcion para cambiar el valor de un dato, depende de la posicion del dato que se va a eliminar (solamente de esto)
//Complejidad: O(n). Solo hay un bucle while y en el peor de los casos va a  ir hasta el final.
template <class T>
void LinkedList<T>::dele(int posicion){
    Node<T> *current = head;
    int contador = 0;
    while(contador < size){ //Que el contador recorra todo el tamaño de la lista
        if (contador == posicion){
            head = head->getNext(); //Obtener el valor e intercambiarlo
            delete current; //Eliminar elemento
            current = head; //Acutalizar el siguiente elemento
            size--; //Ajustar tamaño
        }
        contador++; //Aumentar contador de iteraciones
    }
}



#endif