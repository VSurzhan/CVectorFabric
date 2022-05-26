//
//  CVector1.h
//  CVector
//
//  Created by Вася Суржан on 18.05.2022.
//

#ifndef CVector1_h
#define CVector1_h

#include "CVector.h"

class CVector1: public CVector
{
public:

    CVector1();
    
    CVector1(int size) : CVector (size){};
    
    CVector1(int size, const char* f) : CVector(size, f){};
    
    CVector1(const CVector &x) : CVector(x){};
    
    CVector1(char* str);
    
    using CVector :: operator=;

    int output(const char *f = NULL);
    
    ~CVector1(){}
};


#endif /* CVector1_h */
