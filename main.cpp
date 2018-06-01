//
//  main.cpp
//  ZFraction
//
//  Created by Michaël on 31/05/2018.
//  Copyright © 2018 Mickahell. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

#include "ZFraction.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    ZFraction a(-6,5), ra(4,9), neg(-7,8), pui(5,8);
    ZFraction b(8);
    ZFraction c,d,e,f,h,i,j;
    int expNum = 3, expDenom = 4;
    
    int num = a.numerateur();
    cout << "Numérateur de " << a << " est : " << num << endl;
    int denom = a.denominateur();
    cout << "Numérateur de " << a << " est : " << denom << endl;
    
    c = a+b;
    d = a-b;
    e = a*b;
    f = a/b;
    h = neg.absolue();
    i = ra.racine();
    j = pui.puissance(expNum, expDenom);
    
    cout << a << " + " << b << " = " << c << endl;
    cout << a << " - " << b << " = " << d << endl;
    cout << a << " * " << b << " = " << e << endl;
    cout << a << " / " << b << " = " << f << endl;
    cout << "Reel de " << a << " = " << a.nombreReel() << endl;
    cout << "|" << neg << "| = " << h << endl;
    cout << "Racine de 4/9" << " = " << i << endl;
    cout << "5^" << expNum << "/8^" << expDenom << " = " << j << endl;
    
    if(a > b)
        cout << a << " est plus grand que " << b << endl;
    else if(a==b)
        cout << a << " est egal à " << b << endl;
    else
        cout << a << " est plus petit que " << b << endl;
    
    
    return 0;
}
