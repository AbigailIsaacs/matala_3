#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <stdio.h>

namespace ariel
{
    class Fraction
    {
    private:
        int mone;
        int mechna;
        int gcd(int mone, int mechane);
        void reduct ();
        float fromFracTtoFloat(Fraction frac);
        static Fraction fromFloaTtofrac(float frac);
    public:
        Fraction();
        Fraction(float frac);
        Fraction(int mon, int mec);
        int getNumerator ();
        int getDenominator ();
        Fraction operator+(const Fraction& frac);
        Fraction operator+(float frac);
        Fraction operator-(const Fraction& frac);
        Fraction operator-(float frac);
        Fraction operator/(const Fraction& frac);
        Fraction operator/(float frac);
        Fraction operator*(const Fraction& frac);
        Fraction operator*(float frac);
        Fraction operator++(int n);
        Fraction &operator++();
        Fraction operator--(int n);
        Fraction &operator--();
        Fraction &operator-();
        bool operator>=(const Fraction& frac);
        bool operator<=(const Fraction& frac);
        bool operator>=(float frac);
        bool operator<=(float frac);
        bool operator>(float frac);
        bool operator<(float frac);
        bool operator>(const Fraction& frac);
        bool operator<(const Fraction& frac);
        friend Fraction operator+(float num, const Fraction& frac);
        friend Fraction operator-(float num, const Fraction& frac);
        friend Fraction operator/(float num, const Fraction& frac);
        friend Fraction operator*(float num, const Fraction& frac);
        friend std::ostream &operator<<(std::ostream &output, const Fraction& frac);
        friend std::istream &operator>>(std::istream &input, Fraction& frac);
        friend bool operator==(const Fraction& frac1,float frac2);
        friend bool operator==(const Fraction& frac1,const Fraction& frac2);
        friend bool operator<(float frac1,const Fraction& frac2);
        friend bool operator>(float frac1,const Fraction& frac2);
        friend bool operator>=(float frac1, const Fraction& frac2);
        friend bool operator<=(float frac1, const Fraction& frac2);
        friend bool operator>=(const Fraction& frac1,const Fraction& frac2);
        friend bool operator<=(const Fraction& frac1,const Fraction& frac2);
        friend bool operator<(const Fraction& frac1,const Fraction& frac2);
        friend bool operator>(const Fraction& frac1,const Fraction& frac2);
    };
}