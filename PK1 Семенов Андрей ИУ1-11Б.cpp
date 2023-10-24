#include <iostream>
#include <string>
#include <iomanip>

//вариант 5. Семенов Андрей. ИУ1-11Б. РК1(24.10.23)

struct TASK //создание структуры для хранения названия задачи и срока её выполнения
{
    std::string name; //создание переменной, которая будет хранить название задачи
    int priority;
    std::string deadline; //создание переменной, которая будет хранить срок сдачи данной задачи
};

int main() 
{
    int vm = 1; //vm - вместимость массива
    TASK* tasks = new TASK[vm]; //создание динамического массива tasks
    int count = 0; //количество добавленных задач, которые вводит пользователь
    std::string yesornot; //yesornot - переменная, которая считывает ответ пользователя на вопрос о добавлении новой задачи
    do //цикл для добавления задач 
    {
        std::cout << "Введите название задачи: ";
        std::string name;
        std::getline(std::cin >> std::ws, name);

        std::cout << "Введите приоритет задачи (от 1 до 10): ";
        int priority;
        std::cin >> priority;

        std::cout << "Введите срок выполнения задачи (например, \"10 октября\"): ";
        std::string deadline;
        std::getline(std::cin >> std::ws, deadline);

        if (count == vm) 
        {
            vm *= 2;
            TASK* newtasks = new TASK[vm];
            for (int i=0; i < count; i++) 
            {
                newtasks[i] = tasks[i];
            }
            delete[] tasks; //освобождение памяти путём удаления ненужных строк
            tasks = newtasks;
        }

        tasks[count].name = name;
        tasks[count].priority = priority;
        tasks[count].deadline = deadline;

        std::cout << "Задача добавлена!" << std::endl;

        count++;

        std::cout << "Хотите добавить еще одну задачу? (да/нет): ";
        std::cin >> yesornot;
    } while (yesornot == "да");

    for (int i=0; i < count - 1; i++)  //сортировка по убыванию приоритета
    {
        for (int j=0; j < count - i - 1; j++)
        {
            if (tasks[j].priority < tasks[j + 1].priority) 
            {
                TASK temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }

    std::cout << "Список задач (по убыванию приоритета):" << std::endl;
    for (int i=0; i < count; i++) 
    {
        std::cout << i + 1 << ". Задача: " << tasks[i].name << ", Приоритет: " << tasks[i].priority 
                  << ", Срок выполнения: " << tasks[i].deadline << std::endl;
    }

    delete[] tasks; //освобождение памяти путём удаления ненужных строк
    return 0;
}