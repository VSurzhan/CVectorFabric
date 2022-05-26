//
//  main.cpp
//  CVector
//
//  Created by Вася Суржан on 21.02.2022.
//

#include "CVector.h"
#include "CVector0.h"
#include "CVector1.h"

#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>

using namespace std;

int main() {

    setlocale(LC_ALL, "rus");

    CVector0 a0(2);
    CVector1 b1(2);
    CVector0 c0(2);
    CVector0 d0(2);
    
    a0[0]= 1.1; a0[1]= 2.2;
    b1[0]= 1.0; b1[1]= 1.0;
    cout << "a0: "<<a0;
    cout << "b1: "<<b1;
   
    c0 = a0 + b1;
    cout << "c0: "<<c0;
    if ((c0[0]==2.1) && (c0[1]==3.2))
    cout << "Test1 Ok"<< endl;

    
    d0 = a0 - c0;
    cout << "d0: "<<d0;
    if ((d0[0]==-1.0) && (d0[1]==-1.0))
    cout << "Test2 Ok"<< endl;


   
    ifstream in;
    in.open("input.txt");
    if (!in.is_open())
        return 1;
    while (!in.eof())
    {
        CVector* vec;
        int x;
        in >> x;
        char f[255];
        in >> f;
        char data[500];
        in.getline(data, 500);
        if ((x!=0)&&(x!=1))
        {
            cout << "Error! Invalid input data!" << endl;
            exit(1);
        }
        else
        {
            if (x==0)
                vec = new CVector0(data);
            else
                vec = new CVector1(data);
            vec->output(f);
            delete vec;
        }
    }
    return 0;
}







