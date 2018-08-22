#include <iostream>

using namespace std;

#include "node.h"
#include "Stack.h"
#include "Queue.h"



int main(){
    Stack<string> miPila;
    miPila.push("HOLA");
    miPila.push("CRAYOLA");
    miPila.push("ITESM");

    cout << "En el tope esta: " << miPila.peek() << endl;
    cout << endl << "La pila: " << endl;

    while(!miPila.isEmpty()){
        cout << miPila.pop() << endl;
    }

    cout << "FIN DE PILA" << endl;

    cout << endl << endl;

    Queue<string> miCola;
    miCola.push("HOLA");
    miCola.push("CRAYOLA");
    miCola.push("ITESM");

    cout << "En el tope esta: " << miCola.peek() << endl;
    cout << endl << "La cola: " << endl;

    while(!miCola.isEmpty()){
        cout << miCola.pop() << endl;
    }

    cout << "FIN DE COLA" << endl;


    return 0;
}
