#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(){
    LinkedList<string> lista;
    lista.addFirst("hola");
    lista.addLast("mundo!");

    lista.deleteAll();
    return 0;
}