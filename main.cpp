//
//  main.cpp
//  CVector
//
//  Created by Вася Суржан on 21.02.2022.
//

#include "CVector.h"
#include "CVector0.h"
#include "CVector1.h"
#include "Fabric.h"

#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <functional>
#include <string>


using namespace std;

int main() {

    setlocale(LC_ALL, "rus");

    vector <CVector*> CVectorList;
    map <string, Fabric*> mapCVector;
    mapCVector["Hori"] = new Fabric0;
    mapCVector["hori"] = new Fabric0;
    mapCVector["Vert"] = new Fabric1;
    mapCVector["vert"] = new Fabric1;
    
    
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
        string t;
        string f;
        string data;
        in >> t;
        in >> f;
        getline(in, data);
        auto item = mapCVector.find(t);
        if (item != mapCVector.end())
            CVectorList.push_back(mapCVector[t]->createCVector(data, f));
        else
        {
            cout<< "Error! Invalid input data!\n";
            return-1;
        }
    }
    for (auto& i : CVectorList)
    {
        i->output();
        delete i;
    }
    in.close();
    return 0;
    
}
