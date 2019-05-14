#include <iostream>
#include <string>
using namespace std;

#include "mathquest.h"

int RandInt(int low, int high);

// prototype quiz program for demonstrating inheritance

void GiveQuestion(MathQuestion & quest) {
  // post: quest is asked once, correct response is given
  string answer;
  cout << endl << quest.Description() << endl;
  cout << "type answer after the question" << endl;
  
  quest.Create();
  quest.Ask();
  
  cin >> answer;
  if (quest.IsCorrect(answer)) {    
    cout << "Excellent!, well done" << endl;
  } else {    
    cout << "I'm sorry, the answer is " << quest.Answer() << endl;
  }
}

int main() {
  MathQuestion * questions[3];       // fill with questions
  
  //Just some demo ----------------------------------------
  MathQuestion m;
  CarryMathQuestion cm1, cm2;
  m = cm1;
  //cm1=m; not possible since m is not a CarryMath question!
  cout << m.Description() << endl << endl;//calls base class' function; not an acceptable polymorphic behavior
  
  questions[0] = new MathQuestion();
  questions[1] = new CarryMathQuestion();
  questions[2] = new HardMathQuestion(); 
  
  int qCount;
  cout << "how many questions? ";
  cin >> qCount;
  
  for(int k=0; k < qCount; k++) {    
    int index = RandInt(0,2);
    GiveQuestion(*questions[index]);
  } 
  
  for(int k=0; k < 2; k++) {   
    delete questions[k];
  }
  
  return 0;   
}
