#include "DataLog.h"

DataLog::DataLog(){
    logList.push_front(0);
    currentState = logList.begin();
}

DataLog::DataLog(const int &data)
{
    logList.push_front(data);
    currentState = logList.begin();
    
}

void DataLog::addCurrentState(int number)
{
    *currentState += number; 
}

void DataLog::subtractCurrentState(int number)
{
    *currentState -= number;
}

void DataLog::save()
{
     currentState++;
     if(currentState != logList.end()){
         list<int>::iterator curr = currentState;
         list<int>::iterator prev = currentState;
        while(curr != logList.end()){
            curr++;
            logList.erase(prev);
            prev = curr;
        }
        currentState = logList.end();
       
    }
    currentState--;
  
    logList.push_back(*currentState);
    currentState++;

}

void DataLog::undo()
{
    if(currentState != logList.begin())
        --currentState;
}
void DataLog::redo()
{
     ++currentState;
    if(currentState == logList.end()) --currentState;
}