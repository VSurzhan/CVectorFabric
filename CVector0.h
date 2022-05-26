//
//  CVector0.h
//  CVector
//
//  Created by Вася Суржан on 18.05.2022.
//

#ifndef CVector0_h
#define CVector0_h

#include "CVector.h"

class CVector0: public CVector
{
public:

    CVector0();
    
    CVector0(int size) : CVector(size){};

    CVector0(int size, const char* f) : CVector(size, f){};

    CVector0(const CVector0 &x) : CVector(x){};
    
    CVector0(char* str);

    using CVector::operator=;

    int output(const char *f = NULL);
    
    ~CVector0(){}
};

CVector0 operator+(const CVector &, const CVector &);

CVector0 operator-(const CVector &, const CVector &);

#endif /* CVector0_h */
