#ifndef _QUEST_H
#define _QUEST_H

// abstract base class for quiz questions
// derived classes MUST implement four functions:
//
// void Ask()        to ask the question
// string Answer()   to return the answer
// bool IsCorrect(s) to tell if an answer s is correct
// void Create()     to create a new question
//
// This class conforms to the naming conventions
// of quiz questions in "A Computer Science Tapestry" 2e

#include <string>
using namespace std;

class Question
{
  public:
    virtual ~Question() { }   // subclasses must implement destructor
    
    // accessor functions
	bool IsCorrect(const string & answer) const
	{	
		return (answer == myAnswer);
	}

	string  Answer()const
	{	
		return myAnswer;
	}

    //subclasses should override these
    //TODO: Fix these statements. Hint the class Question is an abstract clas
     virtual void Ask() const = 0;
     virtual void Create() = 0;

    //TODO:Fix the statement below
protected:
	string myAnswer;
};

#endif
