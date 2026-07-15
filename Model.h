struct Task
{
    char Desc[101];
    int Id;
    char Title[51];
    enum St{Done,To_do} (Status);
};
struct Task MyTask[20];

void RegisterTask();

void ListTask();

void TaskStatus();

int SearchTask();

void DeleteTask(int Id);

int CloseManager();