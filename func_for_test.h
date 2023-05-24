#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;  

// Класс задачи
class Task 
{
public:
	string name;
    	bool is_done;

    	Task(string task_name) 
  	{
        	name = task_name;
        	is_done = false;
    	}
};

// Класс списка задач
class ToDoList 
{
public:
    	vector<Task> tasks;

    	// Добавить задачу в список
    	void add_task(Task task) 
  	{
      	  tasks.push_back(task);
    	}

	// Отметить задачу выполненной
	void mark_task_done(int task_index) 
	{
		tasks[task_index].is_done = true;
	}

    	// Вывести список задач на экран
    	void print_tasks() 
  	{
		if (tasks.empty()) 
	   	{
		    cout << "List of tasks is empty." << endl;
		} 
    		else 
    		{
            		cout << "List of tasks:" << endl;
            		for (int i = 0; i < tasks.size(); i++) 
      			{
				string status = tasks[i].is_done ? " (Completed)" : "";
				cout << i << ". " << tasks[i].name << status << endl;
            		}
        }
    }

  void edit_task_name(int task_index, string new_name) 
  {
      if (task_index < 0 || task_index >= tasks.size()) 
    {
          cout << "False number of task." << endl;
      } 
    else 
    {
          // Сохраняем старый статус задачи
          bool is_done = tasks[task_index].is_done;
  
          // Обновляем название задачи
          tasks[task_index].name = new_name;
  
          // Обновляем статус задачи
          tasks[task_index].is_done = is_done;
  
//          cout << "Task is edited." << endl;
      }
  }
  // Отменить выполнение задачи
  void mark_task_undone(int task_index) 
  {
      	tasks[task_index].is_done = false;
  }
  
  // Удалить задачу из списка
void remove_task(int task_index)
  {
      	if (task_index < 0 || task_index >= tasks.size())
      {
          cout << "False number of task." << endl;
      }
	else
      {
          auto it = tasks.begin() + task_index;
          if (tasks.erase(it) != tasks.end())
          {
              cout << "Task is removed." << endl;
          }
      }
  }
};
