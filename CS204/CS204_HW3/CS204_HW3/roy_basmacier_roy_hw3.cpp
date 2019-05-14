#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

/*	Roy Basmacier
	roy@sabanciuniv.edu
	24813
	 __          
	 )_) _       
	/ \ (_) (_(  
			  _) 
*/
/*

	This program takes two xml files as input
	and checks if the xml format is valid if 
	so it adds the the tags and their values 
	in a stack one for each file. then it 
	removes them from the stack to a queue.
	After that it assigns students to their
	lectures if its valid

*/

void reverse(queueNode** myhead) // reverses a linked list using recursion
{
	queueNode* front, *ptr;

	// when the list is empty
	if (*myhead == nullptr)
		return;

	// seperating the front node with the rest of the linked list
	front = *myhead;
	ptr  = front->next;

	// when the list has only one node
	if (ptr == nullptr)
		return;

	// reverse the ptr and thenbut front in the end
	reverse(&ptr);
	front->next->next = front;
	front->next = nullptr;

	*myhead = ptr;
}

void add2End (queueNode *head, queueNode *nnode) // adds a node to the end of a linked list
{
	
	queueNode *prv = nullptr, *ptr = head;
	while(ptr)
	{
		prv = ptr;
		ptr = ptr->next;
	}

	prv->next = nnode;
	nnode->next = nullptr;
}

int INT(const char * s)	//converts string into int
{
	int num = 0;
	for(int i = 0; s[i] != NULL; ++i)
	{
		num = num*10 + s[i] - '0';
	}
	return num;
}

bool isXML(Stack s, string tag, Queue *qptr) // This is a recursive function that checks if the given xml is valid or not
											 // It also puts the data into a queue took me too long to write :|
{
	// gets the next tag from stack
	string newTag;
	s.pop(newTag);

	// checks if the given stack is for stu.txt
	if(tag == "</student>")		
	{
		queueNode *qnptr = new queueNode();
		qptr->enqueue(qnptr);
	}
	// creates a dummy node to store lectures from lec.txt
	else if (qptr->isEmpty())	
	{
		queueNode *qnptr = new queueNode("inLectures");
		qptr->enqueue(qnptr);
	}

	// the base condition to store recursion
	if(s.isEmpty())	
		return true;
	// if the newTag is </X>  call function and search for is coresponding <>
	if(newTag.find('/')!= string::npos)
		return isXML(s, newTag, qptr);
	// if the newTag is not a <> or </> but is between them then add to queue accordingly
	else if(newTag.find('<') == string::npos)
	{
		if(tag == "</lecture>")
		{
			//cout << qptr->front->name << " is taking "<<  newTag << endl;
			qptr->addToBeg(newTag);
		}
		else if (tag == "</name>")
		{
			// if the name is students name or lectures name
			if(qptr->front->name == "inLectures")
				qptr->front->lectures->lectureName = newTag;
			else
				qptr->end->name = newTag;
		}
		else if (tag == "</id>")
			qptr->end->id = INT(newTag.c_str());
		else if (tag == "</capacity>")
			qptr->addToBeg(INT(newTag.c_str()));

		//cout << "from " << tag << " == " << newTag << endl;
		return isXML(s, tag, qptr);
	}
	// if X = Y ( <X> </Y> )
	else if (newTag.substr(1) == tag.substr(2))
	{
		//cout << tag << "|" << newTag <<  endl;
		s.pop(newTag);
		return isXML(s,newTag, qptr);
	}
	// if they dont match
	else
	{
		//cout << "THESE DONT MATCH    " << tag << "|" << newTag <<  endl;
		return false;
	}

}

int main()
{
	string fileNameStudent, fileNameLectures, line;
	ifstream inStudent, inLectures;

	do
	{
		cout << "Please enter the name of the Student XML file: ";
		cin >> fileNameStudent;
		inStudent.open(fileNameStudent.c_str());
	}while(inStudent.fail());

	do
	{
		cout << "Please enter the name of the Lectures XML file: ";
		cin >> fileNameLectures;
		inLectures.open(fileNameLectures.c_str());
	}while(inLectures.fail());


	Stack stuStack, lecStack;

	// parsing stu.txt and pushing into a stack
	while(getline(inStudent, line))
	{
		if(line.find('<') == line.rfind('<'))
		{
			stuStack.push(line);
		}
		else
		{
			// adding first string between < and >
			stuStack.push(line.substr(line.find('<'), line.find('>')));
			// adding string between > and <
			stuStack.push(line.substr(line.find('>')+1,  line.rfind('<') - line.find('>')-1));
			// adding last string between < and >
			stuStack.push(line.substr(line.rfind('<')));
		}

	}

	// parsing lec.txt and pushing into a stack
	while(getline(inLectures, line))
	{
		if(line.find('<') == line.rfind('<'))
		{
			lecStack.push(line);
		}
		else
		{
			lecStack.push(line.substr(line.find('<'), line.find('>')));
			lecStack.push(line.substr(line.find('>')+1,  line.rfind('<') - line.find('>')-1));
			lecStack.push(line.substr(line.rfind('<')));
		}

	}
	//making two queues for each input file
	Queue *stuQueue = new Queue();
	Queue *lecQueue = new Queue();

	// checking if the xml is given correctly and generating the queue
	string firstTag;
	stuStack.pop(firstTag);
	if (!isXML(stuStack, firstTag, stuQueue))
	{
		cout << "Invalid XML format! ... Exiting\n";
		exit(0);
	}


	lecStack.pop(firstTag);
	if(!isXML(lecStack, firstTag, lecQueue))
	{
		cout << "Invalid XML format! ... Exiting\n";
		exit(0);
	}

	// pointer to pointer to return the the pointer to the nodes
	queueNode **STUptp = nullptr;
	queueNode *stmp,
		*shead = new queueNode("stull"), //student linked list 
		*Sptr = shead;
	STUptp = &stmp;

	// dequeuing all students and adding them to a linked list starting with the node (stull)
	while(!stuQueue->isEmpty())
	{
		stuQueue->dequeue(*STUptp);
		add2End(shead, stmp);
		
	}

	// reverses the linked list
	queueNode **PTP;
	PTP = &shead;
	reverse(PTP);

	// getting lecture linked list from queue
	queueNode **LECptp = nullptr;
	queueNode *ltmp,
		*lhead = new queueNode("lecll"), //lectre linked list
		*Lptr = lhead;
	LECptp = &ltmp;
	lecQueue->dequeue(*LECptp);

	// pointer to the lecture linked list
	node *lecptr = ltmp->lectures;

	// pointer to the students lectures
	node *slptr = nullptr;

	// counts the total amount of classes amongst students
	int cnt = 0;
	Sptr = shead;
	while(Sptr)
	{
		slptr = Sptr->lectures;
		while(slptr)
		{
			cnt++;
			slptr = slptr->next;
		}
		Sptr = Sptr->next;
	}


	bool classFound;
	Sptr = shead;
	
	// main loop for printing the output
	// iterates through the amount of classes amongst 
	for(int i = 0; i < cnt; i++)
	{
		// if the student pointer points to the end of the list or the temp node made to initialize the list
		if(Sptr == nullptr || Sptr->name == "stull")
			Sptr = shead;

		lecptr = ltmp->lectures; // lecture pointer points at the lectures in the lec.txt
		slptr = Sptr->lectures;  // student lecture pointer points to the student's lecture

		classFound = false;
		
		if (slptr) // if the student has any remaining lectures
		{
			while(lecptr) // iterates through all the lectures in lec.txt
			{
				// when the student has the same lecture that is available in the lec.txt
				if(slptr->lectureName == lecptr->lectureName) 
				{
					classFound = true;
					break;
				}

				lecptr = lecptr->next;
			}
			
			// if the students lecture is in the lec.txt
			if(classFound)
			{
				if(lecptr->cap > 0) // if that lecture has remaining capacity
				{
					cout << slptr->lectureName << " is assigned to " << Sptr->name
						 << "(" << Sptr->id << ")" << endl;
					lecptr->cap--;
				}
				else 
				{
					cout << slptr->lectureName << " can not be assigned to " << Sptr->name
						 << "(" << Sptr->id << ")" << endl;
				}

			}
			else // if the lec.txt doesnt have the student's lecture
			{
				cout << slptr->lectureName << " can not be assigned to " << Sptr->name
					 << "(" << Sptr->id << ")" << endl;
			}
		// makes the student's lecture head point to the next node in there
		Sptr->lectures = Sptr->lectures->next;
		}
		else // if the student doesnt have any remaining lectures then go to the next student
			i--; // decrease i because this did not print out anything

		Sptr = Sptr->next;
	}

	return 0;
}
