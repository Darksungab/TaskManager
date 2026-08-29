#include <stdio.h>
#include <string.h>
#include "Model.h"

struct Task MyTask[MAX_TASKS];
int RecordedTasks;
int NextId;

int HasSpace(){
     int Total = MAX_TASKS;
     if (RecordedTasks == Total)
     {
          return CAN_NOT;
     }
     if (RecordedTasks < Total)
     {
          return SUCCESS;
     }
     else 
     {
          return UNEXPEC_ERROR;
     }
}

int RegisterTask(char Title[], char Desc[]){
     int Space = HasSpace();
     if (Space == SUCCESS)
     {
          MyTask[RecordedTasks].Id = NextId++;
          strcpy(MyTask[RecordedTasks].Title, Title);
          strcpy(MyTask[RecordedTasks].Desc, Desc);
          RecordedTasks++;

          return SUCCESS;
     }
     if (Space == CAN_NOT)
     {
          return CAN_NOT;
     }
     else
     {
          return UNEXPEC_ERROR;
     }
     

}

struct Task* ListTask(){
     if (RecordedTasks != 0)
     {
          return MyTask;             
     }
     else
     {
          return NULL;
     }     
}

int TaskIndex (int Id){
     int i;
     for (i = 0; i < RecordedTasks;){
               if (MyTask[i].Id == Id){
                    return i;
               }
               else{
                    i++;
               }                    
          }
     return NOT_FOUND;
}

int TaskExists(int Id){
     int Index = TaskIndex(Id);
     if (RecordedTasks == 0){
          return CAN_NOT;
     }
     if (RecordedTasks != 0) {
          if (Index == NOT_FOUND)
          {
               return NOT_FOUND;
          }
          else{
               return SUCCESS;
          }           
     }
     else {
          return NOT_FOUND;
     }
}

int ChangeTaskStatus(int Id, enum St NewStatus){
     int Index = TaskIndex(Id);
     if (Index== NOT_FOUND)
     {
          return NOT_FOUND;
     }
     MyTask[Index].Status = NewStatus;
     return SUCCESS;
}

int TaskStatus(int Id){
     int Index = TaskIndex(Id);
     if (Index == NOT_FOUND){
          return NOT_FOUND;
     }
     else {
          return MyTask[Index].Status;
     }
     
}

struct Task* SearchById(int Id){
    int Index = TaskIndex(Id);

    if (Index == NOT_FOUND){
     return NULL;
    }
    else{
     return &MyTask[Index];
    }
}

struct Task* SearchByDesc(char Desc[101]){
     int i;
     int DescText;
     for (i = 0; i < RecordedTasks; i++)
     {
          DescText = strcmp(Desc, MyTask[i].Desc);
          if (DescText ==  0)
          {
               return &MyTask[i];
          }         
     }
     return NULL;
}

struct Task* SearchByTitle(char Title[51]){
     int i;
     int TitleText;
     for (i = 0; i < RecordedTasks; i++)
     {
          TitleText = strcmp(Title, MyTask[i].Title);
          if (TitleText ==  0)
          {
               return &MyTask[i];
          }         
     }
     return NULL;
}

struct Task* SearchTask(int Id, char Desc[101], char Title[51], int Select){
     
switch (Select)
     {
     case 1:
          return SearchById(Id);
     case 2:
          struct Task* ByDesc = SearchByDesc(Desc);
          if (ByDesc == NULL){
               return SearchByTitle(Title);
          }
          else{
               return ByDesc;
          }
     default:
          return NULL;
     }
}

void DeleteTask(int Id){
     int i;
     int Index = TaskIndex(Id);
     for (i = Index; i < RecordedTasks -1; i++)
     {
          MyTask[i] = MyTask[i+1];
     }
     RecordedTasks--; 
}