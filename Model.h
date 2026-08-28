#ifndef MODEL_H
#define MODEL_H
#define MAX_TASKS 20
#define CAN_NOT 0
#define SUCCESS 1
#define UNEXPEC_ERROR -1
#define NOT_FOUND -1
struct Task
{
    char Desc[101];
    int Id;
    char Title[51];
    enum St{Done,To_do, Doing} (Status);
};
extern struct Task MyTask[MAX_TASKS];

int RegisterTask(char Title[], char Desc[]);

struct Task* ListTask();

int TaskStatus(int Id);

int TaskIndex(int Id);

int TaskExists(int Id);

int ChangeTaskStatus(int Id, enum St NewStatus);

void SearchTask(int Id, char Desc[101], char Title[51]);

void DeleteTask(int Id);

int CloseManager();

#endif