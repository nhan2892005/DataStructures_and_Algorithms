#include <iostream>
#include <list>
using namespace std;

class DataLog
{
private:
    list<int> logList;
    list<int>::iterator currentState;

public:
    DataLog();
    DataLog(const int &data);
    void addCurrentState(int number);
    void subtractCurrentState(int number);
    void save();
    void undo();
    void redo();

    int getCurrentStateData()
    {
        return *currentState;
    }
    
    void printLog()
    {      
        for (auto i = logList.begin(); i != logList.end(); i++) {
            if(i == currentState) cout << "Current state: ";
            cout << "[ " << *i << " ] => ";
        }
        cout << "END_LOG";
    }
};

/*
In this exercise, we will use Standard Template Library List (click open in other tab to show more) to implement a Data Log. 

This is a simple implementation in applications using undo and redo. For example in Microsoft Word, you must have nodes to store states when Ctrl Z or Ctrl Shift Z to go back or forward.

DataLog has a doubly linked list to store the states of data (an integer) and iterator to mark the current state. Each state is stored in a node, the transition of states is depicted in the figure below. 
*/

DataLog::DataLog()
{
     logList.push_back(0);
     currentState = logList.begin();
}

DataLog::DataLog(const int &data)
{
    currentState = logList.begin();
    logList.push_back(data);
}

void DataLog::addCurrentState(int number)
{
    currentState = logList.insert(next(currentState), number);
}

void DataLog::subtractCurrentState(int number)
{
    currentState = logList.insert(currentState, number);
}

void DataLog::save()
{
    /*
     * TODO: This function will create a new state, copy the data of the currentState
     *       and move the currentState Iterator to this new state. If there are other states behind the 
     *       currentState Iterator, we delete them all before creating a new state.
     */
    logList.erase(next(currentState), logList.end());
    logList.push_back(*currentState);
    currentState++;
}

void DataLog::undo()
{
    if (currentState != logList.begin())
    {
        currentState--;
    }
}

void DataLog::redo()
{
    if (currentState != prev(logList.end()))
    {
        currentState++;
    }
}

