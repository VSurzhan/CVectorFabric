//
//  Cvector.cpp
//  CVector
//
//  Created by Вася Суржан on 18.05.2022.
//

#include "CVector.h"
#include "CVector0.h"
#include "CVector1.h"

using namespace std;


CVector:: CVector()
{
    this->t = 0;
    this->coords = NULL;
}

CVector:: CVector(int size)
{
    this->t = size;
    this->coords = new double [size];
    for (int i = 0; i < size; ++i) {
        coords[i] = i;
    }
}

CVector:: CVector(int size, const char* f)
{
    this->t = size;
    this->coords = new double[size];
    ifstream in;
    in.open(f);
    if (!in.is_open())
        return;
    for (int i = 0; i < size; ++i)
        in >> this->coords[i];
}

CVector:: CVector(const CVector &x)
{
    this->t = x.t;
    this->coords = new double[x.t];
    for (int i = 0; i < x.t; ++i)
    {
        this->coords[i] = x.coords[i];
    }

}

CVector& CVector:: operator=(const CVector &x)
{
    if (this == &x)
        return *this;
    this->t = x.t;
    delete[] coords;
    this->coords = new double[x.t];
    for (int i = 0; i < x.t; ++i)
    {
        this->coords[i] = x.coords[i];
    }
    return *this;
}

double& CVector:: operator[](int i){
    if (i >= this->t)
    {
        int N;
        N = this->t;
        double *mas;
        mas = new double[N];
        for (int j = 0; j < N; ++j)
        {
            mas[j] = this->coords[j];
        }
        delete [] coords;
        this->coords = new double[i+1];
        this->t = i+1;
        for (int j = 0; j < i+1; ++j)
        {
            if(j < N)
                this->coords[j] = mas[j];
            else
                this->coords[j] = 0;
        }
        delete [] mas;
    }
    return coords[i];
}

const double& CVector:: operator[](int i)const
{
    return coords[i];
}



CVector0 operator+(const CVector &a, const CVector &b)
{
    if (a.size() != b.size())
    {
        cout << "Error! In operator+: different size of vectors!" << endl;
        exit(1);
    }
    CVector0 c(a.size());
    for (int i = 0; i < a.size(); ++i)
        c.coords[i] = a.coords[i] + b.coords[i];
    return c;
}



CVector0 operator-(const CVector &a, const CVector &b)
{
    if (a.size() != b.size())
    {
        cout << "Error! In operator-: different size of vectors!" << endl;
        exit(1);
    }
    CVector0 c(a.size());
    for (int i = 0; i < a.size(); ++i)
        c.coords[i] = a.coords[i] - b.coords[i];
    return c;
}

CVector& CVector:: operator+=(const CVector &x)
{
    *this = *this + x;
    return *this;
}

CVector& CVector:: operator-=(const CVector &x)
{
    *this = *this - x;
    return *this;
}

CVector::  ~CVector() {
    delete[] coords;
}

CVector0:: CVector0()
{
    this->t = 0;
    this->coords = NULL;
}

CVector0:: CVector0(char *str)
{
    this->t = 0;
    for (int i = 0; str[i] != 0; ++i)
        if (str[i] == ' ')
            t++;
    this->coords = new double[this->t];
    int k = 0;
    char *D = strtok(str, " ");
    while (D != NULL)
    {
        this->coords[k] = atof(D);
        k++;
        D = strtok(NULL, " ");
    }
}

int CVector0::output(const char *f)
{
    ofstream out;
    out.open(f, fstream::out|fstream::app);
    if(!out.is_open())
        return -1;
    for(int i = 0; i < this->t; ++i)
        out << this->coords[i] << ' ';
    out << endl;
    out.close();
    return 0;
}


CVector1:: CVector1()
{
    this->t = 0;
    this->coords = NULL;
}

CVector1:: CVector1(char *str)
{
    this->t = 0;
    for (int i = 0; str[i] != 0; ++i)
        if (str[i] == ' ')
            t++;
    this->coords = new double[this->t];
    int k = 0;
    char *D = strtok(str, " ");
    while (D != NULL)
    {
        this->coords[k] = atof(D);
        k++;
        D = strtok(NULL, " ");
    }
}

int CVector1::output(const char *f)
{
    ofstream out;
    out.open(f, fstream::out|fstream::app);
    if(!out.is_open())
        return -1;
    for(int i = 0; i < this->t; ++i)
        out << this->coords[i] << '\n';
    out << endl;
    out.close();
    return 0;
}

ostream &operator<<(ostream &out, const CVector &x)
{
    for (int i = 0; i < x.t; ++i)
        cout << x.coords[i] << "\t";
    cout << endl << endl;
    return out;
}
