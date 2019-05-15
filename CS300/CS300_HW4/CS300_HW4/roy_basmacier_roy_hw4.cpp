#include <iostream>
#include "MinHeap.h"
#include "Queue.h"
#include <fstream>
#include <sstream>
using namespace std;

int INT(string s)	//converts string into int
{
	int num = 0;
	for(int i = 0; s[i] != NULL; ++i)
	{
		num = num*10 + s[i] - '0';
	}
	return num;
}

struct Job
{
	int jobID;
	int duration;

	//constructor
	Job(int id = -1, int dur = -1) : jobID(id), duration(dur){}

	bool operator<(const Job & j) { return duration < j.duration; }
	bool operator>(const Job & j) { return duration > j.duration; }
};

int GLOBAL_ID = 0;
struct Worker
{
	int workerID;
	Job* jptr;

	//constructor
	Worker(int wid = GLOBAL_ID++, Job* j = nullptr) : workerID(wid), jptr(j) {}

	bool operator<(const Worker & w) 
	{
		if(!jptr || !w.jptr)
			return workerID < w.workerID;

		if (jptr->duration == w.jptr->duration)
			return workerID < w.workerID;
		return jptr->duration < w.jptr->duration;
	}
	bool operator>(const Worker & w) 
	{
		if(!jptr || !w.jptr)
			return workerID < w.workerID;

		if (jptr->duration == w.jptr->duration)
			return workerID > w.workerID;
		return jptr->duration > w.jptr->duration;
	}
	void operator-(const int & d) {if(jptr){jptr->duration -= d;}};
};

void print(MinHeap<Worker> &mh)
{
	for (int i = 1; i < mh.size; i++)
	{
		cout << mh.arr[i].workerID << "<id-dur>" << mh.arr[i].jptr->duration <<"\n";
	}cout <<"~~~~~\n";
}


int main()
{
	ifstream input;
	ofstream output;
	string filename;
	cout << "Enter filename: ";
	cin >> filename;
	filename +=".txt"; // adding .txt to the end
	input.open(filename.c_str());
	filename += ".out"; // adding .out to the end
	output.open(filename.c_str());
	string line;

	// first line number of workers
	getline(input, line); 
	const int numOfWorkers = INT(line)+1; // +1 for it to fit in the heap

	// second line number of jobs
	getline(input, line); 
	const int numOfJobs = INT(line);

	// reading jobs into queue
	Queue<Job> jobs;
	int tempID, tempDur;
	while(getline(input, line))
	{
		if (line != "")
		{
			istringstream iss(line);
			iss >> tempID >> tempDur;
			//cout << tempID << " " << tempDur << ". ";
			Job j(tempID, tempDur);
			jobs.enqueue(j);
		}
	}

	int time = 0;
	Worker *w;
	Worker *heapArr = new Worker[numOfWorkers];

	for(int i = 1; i < numOfWorkers && !jobs.isEmpty(); i++)
	{
		Job *j = new Job;
		jobs.dequeue(*j);
		heapArr[i].jptr = j;
		output << "Job-" << j->jobID << "->Worker-" << heapArr[i].workerID << " (Day: "<< time << ")\n"; 
	}

	MinHeap<Worker> workers(heapArr, numOfWorkers);
	
	while(!jobs.isEmpty())
	{
		w = &workers.getMin();
		workers.deleteMin();

		time += w->jptr->duration;
		workers.decreaseElements(w->jptr->duration);

		Job *j = new Job;
		jobs.dequeue(*j);
		output << "Job-" << j->jobID << "->Worker-" << w->workerID << " (Day: "<< time << ")\n"; 
		w->jptr = j;
		workers.insert(*w);
	}
	while (workers.isEmpty())
	{
		w = &workers.getMin();
		workers.deleteMin();
		if (w->jptr)
		{
			time += w->jptr->duration;
			workers.decreaseElements(w->jptr->duration);
		}

	}

	output << "All jobs are completed in "<< time << " days.\n";
	return 0;
}