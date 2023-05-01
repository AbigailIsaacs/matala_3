#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
#include "sources/Fraction.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("constructor"){
    CHECK_THROWS_AS(Fraction a(5,0), std::exception); 
    CHECK_THROWS_AS(Fraction a(5,0.0), std::exception); 
}

TEST_CASE("plus"){
    Fraction a(5,3), b(14,21);
    CHECK_EQ(a+b,7/3.0); 
    CHECK_EQ(b+a,7/3.0);
    CHECK_EQ(b+a,a+b); 
    CHECK_EQ(b+b,4/3.0); 
    CHECK_EQ(3.6+ b +2.5,203/30.0);//chaining
    CHECK_EQ(b++,5/3.0); 
    CHECK_EQ(++b,13/3.0); 
    CHECK_EQ(3.6+ b +2.5,203/30.0);
}

TEST_CASE("mines"){
    Fraction a(5,3), b(14,21);
    CHECK_EQ(a-b,1);
    CHECK_EQ(b-a,-1);
    CHECK_EQ(b-b,0.0); 
    CHECK_EQ(3.6-b-2.5,13/30.0);//chaining
    CHECK_EQ(b--,(-1/3.0)); 
    CHECK_EQ(--b,(-4/3.0)); 
    
    
}

TEST_CASE("devision"){
    Fraction a(5,3), b(14,21);
    CHECK_EQ(a/b,5/2.0); 
    CHECK_EQ(b/a,2/5.0);
    CHECK_EQ(b/1.2,5/9); 
    CHECK_EQ(b/1.2,0.555);
    CHECK_EQ(1.2/b,1.8); 
    CHECK_EQ(1.2/b,9/5); 
    CHECK_EQ(a/b/4.0,5/8); 
    CHECK_EQ(a/b/4.0,0.625); 
    CHECK_THROWS_AS(b/0,std::exception);  
    CHECK_THROWS_AS(b/0.0,std::exception);  
}

TEST_CASE("multiplication"){
    Fraction a(5,3), b(14,21);
    CHECK_EQ(a*b,1.111); 
    CHECK_EQ(a*b,10/9); 
    CHECK_EQ(b*a,a*b);
    CHECK_EQ(b*0,0.0);
}

TEST_CASE("equlzation"){
    Fraction a(5,3), b(14,-21), c(10,6), d(-14,21);
    CHECK_EQ(a,5/3.0); 
    CHECK_EQ(b,2/3.0);
    CHECK_EQ(b,d); 
    CHECK_EQ(a,c); 
    CHECK_EQ(-a,-c); 
   
}

TEST_CASE("<,>,<=,>= operators"){
    Fraction a(5,3), b(14,-21), c(10,6), d(-14,21);
    CHECK_EQ(a<5/3.0,false); 
    CHECK_EQ(a<4,true); 
    CHECK_EQ(a<=5/3.0,true); 
    CHECK_EQ(b>0,false);
    CHECK_EQ(b<=d,true); 
    CHECK_EQ(a>=c,true); 
    CHECK_EQ(a>b,true); 
    CHECK_EQ(a<b,false);    
}

TEST_CASE("<<, >> operators"){
    Fraction a(5,3), b(14,-21), c(10,6), d(-14,21);
    CHECK_NOTHROW(
        cout << "a: " << a << "b: " << b << endl;
        cout << "a+b" << a+b << endl; 
        cout << "a-b" << a-b << endl; 
        cout << "a/b" << a/b << endl; 
    );
   
      
}