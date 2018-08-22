#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <queue>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <vector>
#define PI 3.141592653589793

using namespace std;

#include "nodeT.h"
#include "BST.h"

int main(){
    BST miArbol,A,vacio;

    A.add(56);
    A.add(47);
    A.add(22);
    A.add(11);
    A.add(29);
    A.add(49);
    A.add(50);
    A.add(69);
    A.add(59);
    A.add(72);
    A.add(70);

    cout << A.height() << endl;


    A.ancestors(3);A.ancestors(70);
    cout << A.wherelevelIam(22) << endl;
    cout << A.maxwitdh() << endl;
    A.print(5);
    cout << A.isBST() << endl;

    cout << endl << endl;

    cout << vacio.height() << endl;
    vacio.ancestors(70);
    cout << vacio.wherelevelIam(22) << endl;
    cout << vacio.maxwitdh() << endl;
    vacio.print(5);


    /*
    cout << A.nearestParent(56,56) << " " << endl;
    cout << A.nearestParent(47,22) << " " << endl;
    cout << A.nearestParent(59,69) << " " << endl;
    cout << A.nearestParent(70,70) << " " << endl;
    cout << A.nearestParent(-2,4) << " " << endl;
    cout << A.nearestParent(47,49) << " " << endl;
    cout << A.nearestParent(11,29) << " " << endl;
    */
    //cout << A.count() << endl;
    //A.printLeaf();

    /*
    miArbol.add(56);
    miArbol.add(34);
    miArbol.add(37);
    miArbol.add(10);
    miArbol.add(18);
    miArbol.add(15);
    miArbol.add(22);
    miArbol.add(75);
    miArbol.add(60);
    miArbol.add(58);
    miArbol.add(65);
    miArbol.add(64);

    cout << miArbol.height() << endl;
    miArbol.ancestors(64);
    cout << miArbol.wherelevelIam(18) << endl;
    cout << miArbol.maxwitdh() << endl;
    miArbol.print(5);
    /*
    /*
    cout << miArbol.height() << endl;
    miArbol.ancestors(64);
    cout << miArbol.wherelevelIam(58) << endl;
    cout << miArbol.maxwitdh() << endl;
    miArbol.print(5);
    */
    //cout << miArbol.count() << endl;
    //miArbol.printLeaf();



    /*
    cout << "Preorden: ";
    miArbol.print(1);

    cout << "Inorden: ";
    miArbol.print(2);

    cout << "Posorden: ";
    miArbol.print(3);

    cout << endl << endl << "Borrando el 58 "<< endl;
    miArbol.del(58);
    cout << "Preorden: ";
    miArbol.print(1);

    cout << "Inorden: ";
    miArbol.print(2);

    cout << "Posorden: ";
    miArbol.print(3);
    */

    return 0;
}
