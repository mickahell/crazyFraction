//
//  ZFraction.hpp
//  ZFraction
//
//  Created by Michaël on 31/05/2018.
//  Copyright © 2018 Mickahell. All rights reserved.
//

#ifndef ZFraction_hpp
#define ZFraction_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

class ZFraction{
public:
    ZFraction(int numerateur = 0, int denominateur = 1);
    
    void afficher();
    void afficher(std::ostream &flux) const;
    int numerateur();
    int denominateur();
    void simplification();
    double nombreReel() const;
    ZFraction& absolue();
    bool estEgal(ZFraction const& b) const;
    bool estPlusPetitQue(ZFraction const& b) const;
    bool estPlusPetitOuEgal(ZFraction const& b) const;
    
    ZFraction& operator+=(ZFraction const& b);
    ZFraction& operator-=(ZFraction const& b);
    ZFraction& operator*=(ZFraction const& b);
    ZFraction& operator/=(ZFraction const& b);
    ZFraction& racine();
    ZFraction& puissance(int expNum = 1, int expDenom = 1, int exp = 1);
    
    
private:
    int m_numerateur;
    int m_denominateur;
};

int pgcd(int a, int b);
void simplification(int numerateur, int denominateur);

std::ostream &operator<<(std::ostream &flux, ZFraction const& zfraction);

bool operator==(ZFraction const& a, ZFraction const& b);
bool operator!=(ZFraction const& a, ZFraction const& b);
bool operator<(ZFraction const &a, ZFraction const& b);
bool operator<=(ZFraction const &a, ZFraction const& b);
bool operator>(ZFraction const &a, ZFraction const& b);
bool operator>=(ZFraction const &a, ZFraction const& b);

ZFraction operator+(ZFraction const& a, ZFraction const& b);
ZFraction operator-(ZFraction const& a, ZFraction const& b);
ZFraction operator*(ZFraction const& a, ZFraction const& b);
ZFraction operator/(ZFraction const& a, ZFraction const& b);
ZFraction operator-(ZFraction const& a); //Operateur "moins unaire"

#endif /* ZFraction_hpp */
