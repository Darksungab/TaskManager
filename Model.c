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
int main(){
     return 0;
}