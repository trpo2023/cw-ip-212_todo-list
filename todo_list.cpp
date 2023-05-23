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
  
          cout << "Task is edited." << endl;
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

int main() 
{
    ToDoList todo;

    // Переменная для выбора в меню
    int choice = 0;

    while (true) 
  {
        // Выводим меню
        cout << "Menu:" << endl;
        cout << "1. Add task" << endl;
        cout << "2. Notice task completed" << endl;
        cout << "3. Output a list of tasks" << endl;
        cout << "4. Edit task" << endl;
        cout << "5. Undone for marks 'completed'" << endl;
        cout << "6. Remove of tasks" << endl;
        cout << "7. Exit" << endl;

        // Читаем выбор пользователя
        cout << "Select an action: ";
        cin >> choice;
switch (choice) 
    {
            case 1: 
      {
                // Добавление задачи в список
                string task_name;
                cout << "Enter title of task: ";
                cin.ignore(); // очищаем буфер потока ввода перед использованием getline()
                getline(cin, task_name);
                todo.add_task(Task(task_name));
                cout << "Task is added." << endl;
                cout << endl;
                break;
            }
            case 2: 
      {
                // Отмечаем задачу выполненной
                int task_index;
                cout << "Enter number of task for mark completed: ";
                cin >> task_index;
                if (task_index < 0 || task_index >= todo.tasks.size()) 
        {
                    cout << "False number of task." << endl;
                    cout << endl;
                } 
        else 
        {
                    todo.mark_task_done(task_index);
                    cout << "Task is marked completed." << endl;
                    cout << endl;
                }
                break;
            }
            case 3: 
      {
                // Выводим список задач на экран
                todo.print_tasks();
                cout << endl;
                break;
            }
            case 4: 
      {
          // Изменяем название задачи
          int task_index;
          string new_name;
          cout << "Enter number of task for edit: ";
          cin >> task_index;
          if (task_index < 0 || task_index >= todo.tasks.size()) 
        {
              cout << "False number of task." << endl;
              cout << endl;
          } 
        else 
        {
              cout << "Enter new name of task: ";
              cin.ignore();
              getline(cin, new_name);
              todo.edit_task_name(task_index, new_name);
              cout << endl;
          }
          break;
      }
      case 5:
      {
          // Отменяем выполнение задачи
          int task_index;
          cout << "Enter number of task for mark undone: ";
          cin >> task_index;
          if (task_index < 0 || task_index >= todo.tasks.size()) 
          {
              cout << "False number of task." << endl;
              cout << endl;
          } 
          else 
          {
              todo.mark_task_undone(task_index);
              cout << "Task is marked undone." << endl;
              cout << endl;
          }
          break;
      }
      case 6: 
      {
          // Удаляем задачу из списка
          int task_index;
          cout << "Enter number of task for remove: ";
          cin >> task_index;
          if (task_index < 0 || task_index >= todo.tasks.size()) 
          {
              cout << "False number of task." << endl;
              cout << endl;
          } 
          else 
          {
              todo.remove_task(task_index);
              cout << endl;

          }
          break;
      }
      
            case 7: 
      {
                // Выход из программы
                cout << "Goodbye!" << endl;
                return 0;
            }
            default: 
      {
                // Неверный выбор
                cout << "Select False. Try again." << endl;
                cout << endl;
                break;
            }
        }
  }
  return 0;
}
