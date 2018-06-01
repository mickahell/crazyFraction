//
//  ZFraction.cpp
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
// *******************************************CONSTRUCTEUR************************************************************
ZFraction::ZFraction(int numerateur , int denominateur) : m_numerateur(numerateur),m_denominateur(denominateur){
    simplification();
}

// *********************************************METHODE****************************************************************
void ZFraction::afficher(){
    if (m_denominateur == 1)
        cout << m_numerateur << endl;
    else
        cout << m_numerateur << "/" << m_denominateur << endl;
}
void ZFraction::afficher(ostream &flux) const{
    if(m_denominateur == 1)
        flux << m_numerateur;
    else
        flux << m_numerateur << "/" << m_denominateur;
}
int ZFraction::numerateur(){
    return m_numerateur;
}
int ZFraction::denominateur(){
    return m_denominateur;
}

int pgcd(int a, int b){
    while (b != 0){
        const int t = b;
        b = a%b;
        a = t;
    }
    return a;
}
void ZFraction::simplification(){
    int divCom = pgcd(m_numerateur, m_denominateur);
    if(divCom < 0){
        m_numerateur /= (divCom * -1);
        m_denominateur /= (divCom * -1);
    }
    else{
        m_numerateur /= divCom;
        m_denominateur /= divCom;
    }
}
double ZFraction::nombreReel()const{
    double reel = 0;
    reel = static_cast<double>(m_numerateur) / static_cast<double>(m_denominateur);
    return reel;
}
ZFraction& ZFraction::absolue(){
    m_numerateur = abs(m_numerateur);
    return *this;
}

// *********************************************Comparaison
bool ZFraction::estEgal(ZFraction const& b) const{
    int divcomA = pgcd(m_numerateur, m_denominateur);
    int numA = m_numerateur / divcomA;
    int denomA = m_denominateur / divcomA;
    int divcomB = pgcd(b.m_numerateur, b.m_denominateur);
    int numB = b.m_numerateur / divcomB;
    int denomB = b.m_denominateur / divcomB;
    
    if (numA == numB && denomA == denomB)
        return true;
    else
        return false;
}
bool ZFraction::estPlusPetitQue(ZFraction const& b) const{
    int divcomA = pgcd(m_numerateur, m_denominateur);
    int numA = m_numerateur / divcomA;
    int denomA = m_denominateur / divcomA;
    int divcomB = pgcd(b.m_numerateur, b.m_denominateur);
    int numB = b.m_numerateur / divcomB;
    int denomB = b.m_denominateur / divcomB;
    
    if (numA%denomA > numB%denomB)
        return true;
    else
        return false;
}
bool ZFraction::estPlusPetitOuEgal(ZFraction const& b) const{
    int divcomA = pgcd(m_numerateur, m_denominateur);
    int numA = m_numerateur / divcomA;
    int denomA = m_denominateur / divcomA;
    int divcomB = pgcd(b.m_numerateur, b.m_denominateur);
    int numB = b.m_numerateur / divcomB;
    int denomB = b.m_denominateur / divcomB;
    
    if (numA%denomA > numB%denomB)
        return true;
    else if (numA == numB && denomA == denomB)
        return true;
    else
        return false;
}
// *********************************************Calcule
ZFraction& ZFraction::operator-=(ZFraction const& b){
    int denomCom = m_denominateur * b.m_denominateur;
    int numA = m_numerateur * b.m_denominateur;
    int numB = b.m_numerateur * m_denominateur;
    m_numerateur = numA - numB;
    m_denominateur = denomCom;
    
    simplification();
    
    return *this;
}
ZFraction& ZFraction::operator+=(ZFraction const& b){
    int denomCom = m_denominateur * b.m_denominateur;
    int numA = m_numerateur * b.m_denominateur;
    int numB = b.m_numerateur * m_denominateur;
    m_numerateur = numA + numB;
    m_denominateur = denomCom;
    
    simplification();
    
    return *this;
}
ZFraction& ZFraction::operator*=(ZFraction const& b){
    m_numerateur *= b.m_numerateur;
    m_denominateur *= b.m_denominateur;
    
    simplification();
    
    return *this;
}
ZFraction& ZFraction::operator/=(ZFraction const& b){
    m_numerateur *= b.m_denominateur;
    m_denominateur *= b.m_numerateur;
    
    simplification();
    
    return *this;
}
ZFraction& ZFraction::racine(){
    m_numerateur = sqrt(static_cast<double>(m_numerateur));
    m_denominateur = sqrt(static_cast<double>(m_denominateur));
    
    return *this;
}
ZFraction& ZFraction::puissance(int expNum, int expDenum, int exp){
    if (expNum != 0) {
        m_numerateur = pow(m_numerateur, expNum);
    }
    if (expDenum != 0) {
        m_denominateur = pow(m_denominateur, expDenum);
    }
    m_numerateur = pow(m_numerateur, exp);
    m_denominateur = pow(m_denominateur, exp);
    
    simplification();
    
    return *this;
}

// ************************************************OPERATEUR*********************************************************
ostream &operator<<(ostream &flux, ZFraction const& zfraction){
    zfraction.afficher(flux);
    return flux;
}
// **************************************************Comparaison
bool operator==(ZFraction const& a, ZFraction const& b){
    return a.estEgal(b);
}
bool operator!=(ZFraction const& a, ZFraction const& b){
    return !(a == b);
}
bool operator<(ZFraction const &a, ZFraction const& b){
    return a.estPlusPetitQue(b);
}
bool operator<=(ZFraction const &a, ZFraction const& b){
    return a.estPlusPetitOuEgal(b);
}
bool operator>(ZFraction const &a, ZFraction const& b){
    return b.estPlusPetitQue(a);
}
bool operator>=(ZFraction const &a, ZFraction const& b){
    return b.estPlusPetitOuEgal(a);
}
// **********************************************************Calcul
ZFraction operator+(ZFraction const& a, ZFraction const& b){
    ZFraction copie(a);
    copie += b;
    return copie;
}
ZFraction operator-(ZFraction const& a, ZFraction const& b){
    ZFraction copie(a);
    copie -= b;
    return copie;
}
ZFraction operator*(ZFraction const& a, ZFraction const& b){
    ZFraction copie(a);
    copie *= b;
    return copie;
}
ZFraction operator/(ZFraction const& a, ZFraction const& b){
    ZFraction copie(a);
    copie /= b;
    return copie;
}
ZFraction operator-(ZFraction const& a){
    ZFraction copie(a);
    copie = a * -1;
    return copie;
}
