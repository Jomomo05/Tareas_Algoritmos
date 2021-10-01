#include <iostream>

using namespace std;
//Creacion clase nodo
template<class T>
class Node{
    private:
        T data; //Valor
        Node<T> *next; //Sigueinte vector
    public:
        Node(T data);
        Node(T data, Node<T> *next);
        T getData();
        Node<T>* getNext();
        void setData(T data);
        void setNext(Node<T>* next);
        void printNode();
};

template <class T>
Node<T>::Node(T data){ //asignacion de datos y nuevo nullptr
    this->data = data;
    this->next = nullptr; // NULL 
}

template <class T>
Node<T>::Node(T data, Node<T> *next){ //Asignacion de datos (Ambos)
    this->data = data;
    this->next = next;
}

template <class T> //Return data
T Node<T>::getData(){
    return data;
}

template <class T> //Return el siguiente valor (puntero)
Node<T>* Node<T>::getNext(){
    return this->next;
}

template <class T> //Actualizar la data
void Node<T>::setData(T data){
    this->data = data;
}

template <class T> //Actualizar la direccion
void Node<T>::setNext(Node<T>* next){
    this->next = next;
}

template <class T> //Imprimir el valor en pantalla
void Node<T>::printNode(){
    cout << data << endl;
}
