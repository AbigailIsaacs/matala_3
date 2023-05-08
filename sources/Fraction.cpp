#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include "Fraction.hpp"
#include <limits>
using namespace std ;

namespace ariel{
    // defalt constructor
    Fraction::Fraction(){
        this->mone = 0;
        this->mechna = 1;
    }
    
    // float constructor
    Fraction::Fraction(float frac){
       this->mone = frac*1000;
       this->mechna = 1000 ;
       reduct();
    }  
    // two integers constructor
    Fraction::Fraction(int mon, int mec):mone(mon),mechna(mec){
        if(mec==0){
            throw invalid_argument("Division by zero exception");
        }
        if (mec<0){
            mone = mon*(-1);
            mechna = mec*(-1);
        }
        reduct();
    }  

    //get Numerator
    int Fraction::getNumerator (){
        return this->mone;
    }

    //get Denominator
     int Fraction::getDenominator (){
        return this->mechna;
    }

    //cast from float to a fraction
    Fraction Fraction::fromFloaTtofrac( float frac){
        Fraction f (frac*1000, 1000);
        return f;
    }

    //cast from a fraction to a float 
    float Fraction::fromFracTtoFloat(Fraction frac){
    float newfrac = static_cast<float>(frac.mone) / static_cast<float>(frac.mechna);
    return newfrac;
    }

    //reducting the fraction by deviding the gcd 
    void Fraction::reduct (){
        int div = gcd(this->mone,this->mechna);
        if(div<0){
           div=div*(-1); 
        }
        this->mone = this->mone /div;
        this->mechna  = this->mechna/ div;
    }

    //finding the gcd of two fractions
    int Fraction::gcd(int mone, int mechane) {
        if (mechane == 0) {
            return mone;
        } 
        else {
            return gcd(mechane, mone % mechane);
        }
    } 

    //fraction + fraction
    Fraction Fraction::operator+(const Fraction& frac){
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min(); 
            // Compute the least common multiple of the denominators
        long lcm = (this->mechna * frac.mechna) / gcd(this->mechna, frac.mechna);
            // Compute the numerators of the new fractions based on the least common multiple
        long newNum1 = this->mone * (lcm / this->mechna );
        long newNum2 = frac.mone * (lcm / frac.mechna);
            // Add the numerators and simplify the resulting fraction
        long newmone = newNum1 + newNum2;
        long newmechane = lcm;
        long div = gcd(newmone, newmechane);
        newmone = newmone / div;
        newmechane = newmechane / div;
        if(max_int <(newmone/newmechane)||max_int <(newmone)||max_int <(newmechane)){
            throw overflow_error("more then max int error");
        }
        else if( min_int> (newmone/newmechane)||min_int> (newmone)||min_int> (newmechane)){
            throw overflow_error("less then min int error");
        } 
        return Fraction (int(newmone),int(newmechane));
    }

    //Fraction + float
    Fraction Fraction::operator+(float frac){
        Fraction newfrac = fromFloaTtofrac(frac);
        
        return  *this + newfrac; 
    }

    //Fraction - Fraction
    Fraction Fraction::operator-( const Fraction& frac){
        if(frac.mone ==-2147483648){ // MIN INT
            throw overflow_error("more then max int error");
        } 
        Fraction newfrac(-(frac.mone),frac.mechna) ;
        return  *this + newfrac; 
    }

    //Fraction - float
    Fraction Fraction::operator-(float frac){
        Fraction newfrac = fromFloaTtofrac(frac);
        newfrac.mone = (-1)*newfrac.mone;
        return  *this + newfrac; 
    }

    // Fraction / Fraction
    Fraction Fraction::operator/(const Fraction& frac){
        if(frac.mone==0){
            throw runtime_error("Division by zero exception");
        }
        Fraction newfrac(frac.mechna, frac.mone);
        return newfrac* (*this);
    }

    // Fraction / float
    Fraction Fraction::operator/(float frac){
        Fraction newfrac = fromFloaTtofrac(frac);
         return  (*this)/newfrac;
    }

    //Fraction * Fraction
    Fraction Fraction::operator*(const Fraction& frac){
        long mul = (long((*this).mone)* long(frac.mone))/ (long((*this).mechna)* long(frac.mechna));
        int max_int = std::numeric_limits<int>::max();
        int min_int = std::numeric_limits<int>::min();
        if(max_int <mul||max_int <(long((*this).mone)* long(frac.mone))||max_int <(long((*this).mechna)* long(frac.mechna))){
            throw overflow_error("more then max int error");
        }
        else if( min_int> mul || min_int>(long((*this).mone)* long(frac.mone))||min_int> (long((*this).mechna)* long(frac.mechna))){
            throw overflow_error("less then min int error");
        } 
        Fraction newfrac(frac.mone *(this->mone), frac.mechna *(this->mechna));
        return newfrac;
    }

    //Fraction * float
    Fraction Fraction::operator*(float frac){
        Fraction newfrac = fromFloaTtofrac(frac);
        return newfrac*(*this);
    }

    // Fraction++
    Fraction Fraction::operator++(int n){ 
        Fraction copy (this->mone,this->mechna) ;
        Fraction frac(1,1);
        (*this) = (*this) + frac ;
        return copy;
    }

    // ++Fraction
    Fraction& Fraction::operator++(){
        Fraction frac(1,1);
        *this = *this + frac ;
         return *this;
    }

    // Fraction--
    Fraction Fraction::operator--(int n){
        Fraction copy (this->mone,this->mechna) ;
        Fraction frac(1,1);
        (*this) = (*this) - frac;
        return copy;
    }

    // --Fraction
    Fraction &Fraction::operator--(){
        Fraction frac(1,1);
        *this = *this -frac ;
         return *this;
    }

    // -Fraction
    Fraction &Fraction::operator-(){
        *this = *this *(-1) ;
         return *this;
    }

    //Fraction==float
    bool operator==(const Fraction& frac1,float frac2){
        Fraction newfrac = Fraction::fromFloaTtofrac(frac2);
        
        return frac1 == newfrac;
    }

    //Fraction==Fraction
    bool operator==(const Fraction& frac1,const Fraction& frac2) {
        if((frac1.mone==frac2.mone) && (frac1.mone==0)){
            return true;
        }
        if (frac1.mechna == frac2.mechna && frac1.mone==frac2.mone){
            return true;
        }
        return false;
    }

    //Fraction<Fraction
    bool operator<(const Fraction& frac1,const Fraction& frac2){
        return ((frac1).mone * frac2.mechna) <((frac1).mechna * frac2.mone);
    }

    //Fraction>Fraction
    bool operator>(const Fraction& frac1,const Fraction& frac2){
        return ((frac1).mone * frac2.mechna) >((frac1).mechna * frac2.mone);
    }

    //Fraction>=Fraction
    bool Fraction::operator>=(const Fraction& frac){
        return ((*this).mone * frac.mechna) >=((*this).mechna * frac.mone);
    }

    //Fraction<=Fraction
    bool Fraction::operator<=(const Fraction& frac){
        return ((*this).mone * frac.mechna) <=((*this).mechna * frac.mone);
    }

    //Fraction>=Fraction
    bool operator>=(const Fraction& frac1,const Fraction& frac2){
        return ((frac1).mone * frac2.mechna) >=((frac1).mechna * frac2.mone);
    }

    //Fraction<=Fraction
    bool operator<=(const Fraction& frac1,const Fraction& frac2){
        return ((frac1).mone * frac2.mechna) <=((frac1).mechna * frac2.mone);
    }

    //Fraction>=float
    bool Fraction::operator>=(float frac){
        float f1 = fromFracTtoFloat(*this);
        return f1>=frac;
    }

    //Fraction<=float
    bool Fraction::operator<=(float frac){
        float f1 = fromFracTtoFloat(*this);
        return f1<=frac;
    }

    //Fraction>float
    bool Fraction::operator>(float frac){
        float f1 = fromFracTtoFloat(*this);
        return f1>frac;
    }

    //Fraction<float
    bool Fraction::operator<(float frac){
        float f1 = fromFracTtoFloat(*this);
        return f1<frac;
    }
    //Fraction>Fraction
    bool Fraction::operator>(const Fraction& frac){
        float f1 = fromFracTtoFloat(*this);
        float f2 = fromFracTtoFloat(frac);
        return f1>f2;
    }

    //Fraction<Fraction
    bool Fraction::operator<(const Fraction& frac){
        float f1 = fromFracTtoFloat(*this);
        float f2 = fromFracTtoFloat(frac);
        return f1<f2;
    }

    //float+Fraction
    Fraction operator+(float num, const Fraction& frac){
        
        Fraction newfrac= Fraction::fromFloaTtofrac(num);
        return newfrac+frac;
    }

    //float-Fraction
    Fraction operator-(float num, const Fraction& frac){
        Fraction newfrac= Fraction::fromFloaTtofrac(num);
        return newfrac-frac;
    }

    //float/Fraction
    Fraction operator/(float num, const Fraction& frac){
        Fraction newfrac= Fraction::fromFloaTtofrac(num);
        return newfrac/frac;
    }

    //float*Fraction
    Fraction operator*(float num, const Fraction& frac){
        Fraction newfrac= Fraction::fromFloaTtofrac(num);
        return newfrac*frac;
    }

    //float<Fraction
    bool operator<(float frac1,const Fraction& frac2){
        Fraction newfrac= Fraction::fromFloaTtofrac(frac1);
        return newfrac<frac2;
    }
    
    //float>=Fraction
    bool operator>=(float frac1, const Fraction& frac2){
        Fraction newfrac= Fraction::fromFloaTtofrac(frac1);
        return newfrac>=frac2;
    }

    //float>Fraction
    bool operator>(float frac1,const Fraction& frac2){
        Fraction newfrac= Fraction::fromFloaTtofrac(frac1);
        return newfrac>frac2;
    }

    //float<=Fraction
    bool operator<=(float frac1, const Fraction& frac2){
        Fraction newfrac= Fraction::fromFloaTtofrac(frac1);
        return newfrac<=frac2;
    }

    // cout <<
    std::ostream &operator<<(std::ostream &output, const Fraction& frac){
        output << frac.mone << "/" << frac.mechna;
        return output;
    }

    // cin >>
    std::istream& operator>>(std::istream& input, Fraction& frac) {
        char slash;
        int mone ;
        int mechane ;
        input >> mone  >> mechane;
        if(!input){ //if is is false
            throw runtime_error("Enter two numbers to create a fraction")  ;
        }
        if (mechane == 0) {
            throw runtime_error("Division by zero exception")  ;
            
        } else {
            if (mechane<0){
                frac.mone =mone*(-1);
                frac.mechna =mechane*(-1);
            }
            else{
                frac.mone =mone;
                frac.mechna =mechane;
            }
        }   
       return input;     
    }  
}

