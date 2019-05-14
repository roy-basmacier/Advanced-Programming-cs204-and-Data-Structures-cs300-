#ifndef _MATHQUEST_H
#define _MATHQUEST_H

// quiz questions involving arithmetic (addition)
// see comments in quest.h for the naming conventions
// used in quiz classes
//
// MathQuestion()      -- no carry involved, two-digit numbers
// CarryMathQuestion() -- does have carry, two-digit numbers
// HardMathQuestion()  -- three digit addition
//
// these classes add method Description() to the question hierarchy

#include "quest.h"

//TODO: The descriptions are wrong in the output. Please fix that problem. 
class MathQuestion : public Question
{
  public:
    MathQuestion();

    virtual void   Ask()           const;   
    virtual string Description()           const;
    virtual void Create();  
             
  protected:
    int myNum1;       // numbers used in question
    int myNum2;
};

class CarryMathQuestion : public MathQuestion
{
  public:
    CarryMathQuestion();
    string Description()  const;
    virtual void   Create(); 
};

class HardMathQuestion : public MathQuestion
{
  public:
    HardMathQuestion();
    string Description()  const;
    virtual void   Create();   
};

#endif
