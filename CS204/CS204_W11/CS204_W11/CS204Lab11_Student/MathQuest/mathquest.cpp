#include <iostream>
#include <iomanip>
using namespace std; 

#include "mathquest.h"
#include "strutils.h"
#include "stdlib.h"

//Return random int between low and high range
int RandInt(int low, int max)
{   
  return rand() % (max - low + 1) + low; 
}

MathQuestion::MathQuestion()
   : myNum1(0),
     myNum2(0)
{
    // nothing to initialize
}

void MathQuestion::Create()
{
    // generate random numbers until there is no carry
    do
    {
        myNum1 = RandInt(10,49);
        myNum2 = RandInt(10,49);
    } while ( (myNum1 % 10) + (myNum2 % 10) >= 10);
       
    myAnswer = tostring(myNum1 + myNum2);
}

void MathQuestion::Ask() const
{
    const int WIDTH = 7;
    cout << setw(WIDTH) << myNum1 << endl;
    cout << "+" << setw(WIDTH-1) << myNum2 << endl;
    cout << "-------" << endl;
    cout << setw(WIDTH-myAnswer.length()) << " ";
}


string MathQuestion::Description() const
{
    return "addition of two-digit numbers with NO carry";
}


////////////////////////////////////////////////////////

CarryMathQuestion::CarryMathQuestion()
  : MathQuestion()
{
  // all done in base class constructor
}

void CarryMathQuestion::Create()
{

    // generate random numbers until there IS a carry
    do
    {
        myNum1 =RandInt(10,49);
        myNum2 = RandInt(10,49);
    } while ( (myNum1 % 10) + (myNum2 % 10) < 10);
    
    myAnswer = tostring(myNum1 + myNum2);
}

string CarryMathQuestion::Description() const
{
    return "addition of two-digit numbers with a carry";
}


////////////////////////////////////////////////////////
HardMathQuestion::HardMathQuestion()
 : MathQuestion()
{
  // all done in base class constructor
}

void HardMathQuestion::Create()
{
    myNum1 = RandInt(100,200);
    myNum2 = RandInt(100,200);
    myAnswer = tostring(myNum1 + myNum2);
}

string HardMathQuestion::Description() const
{
    return "addition of three-digit numbers";
}
