/*Author: Zeynep Dogmus
 *Date: April 2013
 *Complex Numbers and Operator Overloading
*/
#include<iostream>
#include<iomanip>

#include"ComplexNumber.h"

using namespace std;

//TODO: Implement all the methods here.

//********************************
// Constructor                   *
//********************************
ComplexNumber::ComplexNumber(){
    real = new double;
	imaginary = new double;
}

//Sets the real number part of this complex number
void ComplexNumber::setReal(double newReal) {
    *real = newReal;
}

//Sets the imaginary number part of this complex number
void ComplexNumber::setImaginary(double newImaginary){
    *imaginary = newImaginary;
}

//Returns the real number part of this complex number
double ComplexNumber::getReal() const {
    return *real;
}

//Returns the imaginary number part of this complex number
double ComplexNumber::getImaginary() const {
    return *imaginary;
}

//********************************
// Deep Copy Constructor         *
//********************************
ComplexNumber::ComplexNumber(const ComplexNumber &copy) {
	real = new double;
	imaginary = new double;
	*real = copy.getReal();
	*imaginary = copy.getImaginary();
}

//********************************
// Assignment operator           *                                    
//********************************
const ComplexNumber & ComplexNumber::operator = (const ComplexNumber & rhs) {
	if(this != &rhs)
	{
		*real = *rhs.real;
		*imaginary = *rhs.imaginary;
	}

	return *this;
}

//*********************************************
// Operator overloading                       *
// Subtract rhs from this complex number      *
//*********************************************
const ComplexNumber & ComplexNumber::operator-=(ComplexNumber &rhs) {
    *real -= rhs.getReal();
	*imaginary -= rhs.getImaginary();
	return *this;
}

//*******************************************************************
// Operator overloading for multiplication                          *  
// Multiply this complex number with rhs and return the new result  *
// (a+bi)*(c+di) = ac-bd + (ad+bc)i   (Keep in mind that i^2=-1)    *
//*******************************************************************
ComplexNumber ComplexNumber::operator*(const ComplexNumber &rhs)
{
	ComplexNumber res;
	double newReal, newImaginary;
    newReal = *real * rhs.getReal() - (*imaginary * rhs.getImaginary() *-1);
	newImaginary = *imaginary * rhs.getImaginary() * -1;
	res.setImaginary(newImaginary);
	res.setReal(newReal);
	return res;

}

//********************************
// Destructor                    *                                    
//********************************
ComplexNumber::~ComplexNumber() {
    delete real;
	delete imaginary;
}
