#include <iostream>
#include <string>
using namespace std;

//TODO: Use Inheritance as much as possible and make the code shorter

class Person {
public:
  Person(string name = "", int age = 0) : name(name), age(age) {}

  string getName() {return name;}

  int getAge() {return age;}
  void aging() {age++;}

  virtual void printInfo() {cout << "Person: " << name << " - " << age << endl;}

protected:
  string name;
  int age;
};

class Student : public Person {
public:
  Student(string name = "", int age = 0, double GPA = 0.0) : Person(name, age), GPA(GPA) {}



  double getGPA() {return GPA;}

  virtual void printInfo() {cout << "Student: " << name << " - " << age << " - " << GPA << endl;}

protected:
  double GPA;
};

class GradStudent : public Student{
public:
  GradStudent(string name = "", int age = 0, double GPA = 0.0, string supervisorName = "") : 
	  Student(name, age, GPA), supervisorName(supervisorName) {}

  string getSupervisorName() {return supervisorName;}
  void setSupervisorName() {supervisorName = supervisorName;}

  virtual void printInfo() {cout << "Grad student: " << name << " - " << age << " - " << GPA << " - " << supervisorName << endl;}

private:
  string supervisorName;
};

double averageAge(Person* people, int n) {
  double sum = 0;
  for(int i = 0; i < n; i++) {
    sum += people[i].getAge();
  }
  return sum / n;
}

//TODO: When you use inheritance, do you need two methods
//Since a student is also a gradStudent why cannot we delete the 
//second function below and keep only the first one. 
double averageGPA(Student* students, int n) {
  double sum = 0;
  for(int i = 0; i < n; i++) {
    sum += students[i].getGPA();
  }
  return sum / n;
}

//TODO: After you are done with inheritance, 
//delete this function and see if it compiles, if it runs, and runs correctly 


double averageGPA(GradStudent* students, int n) {
  double sum = 0;
  for(int i = 0; i < n; i++) {
    sum += students[i].getGPA();
  }
  return sum / n;
}



int main() {

  Person p("atos", 30);
  cout << "Generated " << p.getName() << endl;
  p.printInfo(); p.aging(); p.printInfo();
  cout << endl;

  Student s("portos", 18, 3.22);
  cout << "Generated " << s.getName() << endl;
  s.printInfo(); s.aging(); s.printInfo();
  cout << endl;

  GradStudent g("aramis", 18, 3.22, "veli");
  cout << "Generated " << g.getName() << endl;
  g.printInfo(); g.aging(); g.printInfo();
  cout << endl;

  int n = 3;
  Person* people =  new Person[n]{{"atos", 20}, {"portos", 30}, {"aramis", 40}};
  cout << "Avg. age of the people: " << averageAge(people, n) << endl;

  Student* students =  new Student[n]{{"atos", 20, 3.02}, {"portos", 30, 2.57}, {"aramis", 40, 3.97}};
  cout << "Avg. GPA of the students: " << averageGPA(students, n) << endl;

  GradStudent* gradStudents =  new GradStudent[n]{{"atos", 20, 3.31, "leonardo"}, {"portos", 30, 3.91, "donatello"}, {"aramis", 40, 3.84, "raphael"}};
  cout << "Avg. GPA of the grad students: " << averageGPA(gradStudents, n) << endl;
  
  return 0;
}
  
