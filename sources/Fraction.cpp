#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "Fraction.hpp"
using namespace std ;

namespace ariel{
    

    Fraction::Fraction(int mon, int mec):mone(mon),mechna(mec){
       
    }   

    Fraction Fraction::operator+(const Fraction& frac){
        return Fraction (1,1);
    }
    Fraction Fraction::operator+(float frac){
       
        return  Fraction (1,1);
    }

    Fraction Fraction::operator-( const Fraction& frac){
        return frac;
    }
    Fraction Fraction::operator-(float frac){
         return  Fraction (1,1);
    }

    Fraction Fraction::operator/(const Fraction& frac){
        return frac;
    }
    Fraction Fraction::operator/(float frac){
         return  Fraction (1,1);
    }

    Fraction Fraction::operator*(const Fraction& frac){
        return frac;
    }
    Fraction Fraction::operator*(float frac){
        return  Fraction (1,1);
    }

    Fraction Fraction::operator++(int n){
         return  Fraction (1,1);
    }
    Fraction& Fraction::operator++(){
         return *this;
    }
    
    Fraction Fraction::operator--(int n){
        return  Fraction (1,1);
    }
    Fraction &Fraction::operator--(){
         return *this;
    }
    Fraction &Fraction::operator-(){
         return *this;
    }

    bool operator==(const Fraction& frac1,float frac2){
        return true;
    }
    bool operator==(const Fraction& frac1,const Fraction& frac2) {
        return true;
    }


    bool Fraction::operator>=(const Fraction& frac){
        return true;
    }
    bool Fraction::operator<=(const Fraction& frac){
        return true;
    }
    bool Fraction::operator>=(float){
        return true;
    }
    bool Fraction::operator<=(float){
        return true;
    }
    bool Fraction::operator>(float){
        return true;
    }
    bool Fraction::operator<(float){
        return true;
    }
    bool Fraction::operator>(const Fraction& frac){
        return true;
    }
    bool Fraction::operator<(const Fraction& frac){
        return true;
    }


    Fraction operator+(float num, const Fraction& frac){
        return frac;
    }
    Fraction operator-(float num, const Fraction& frac){
        
        return frac;
    }
    Fraction operator/(float num, const Fraction& frac){
        return frac;
    }
    Fraction operator*(float num, const Fraction& frac){
        return frac;
    }
    std::ostream &operator<<(std::ostream &os, const Fraction& frac){
        return std::cout;
    }
    std::ostream &operator>>(std::ostream &os, const Fraction& frac){
        return std::cout;
    }


}