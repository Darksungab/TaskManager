#ifndef MODEL_H
#define MODEL_H
#define MAX_TASKS 20
#define CAN_NOT 0
#define SUCCESS 1
#define UNEXPEC_ERROR -1
struct Task
{
    char Desc[101];
    int Id;
    char Title[51];
    enum St{Done,To_do} (Status);
};
extern struct Task MyTask[MAX_TASKS];

int RegisterTask(char Title[], char Desc[]);

void ListTask();

void TaskStatus();

int SearchTask();

void DeleteTask(int Id);

int CloseManager();

#endif