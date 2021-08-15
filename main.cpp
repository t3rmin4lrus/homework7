#include "mylib.h"
#include <fstream>

#define IN_RANGE(num, range) (num >= 0 && num < range)

#define ONE_ARR_SIZE 5

#define SWAP(a, b) \
    a ^= b;        \
    b ^= a;        \
    a ^= b

#pragma pack(push, 2)
struct myEmployee {
    unsigned int age;
    float salary;
    int id;
};
#pragma pack(pop)

void initial_user_array(int* const array, size_t const array_size);
void sorted_myarray(int* const array, size_t const array_size);
void printed_myarray(int const* const array, size_t const array_size);
void print_struct_my_employee(myEmployee const* const employee);
void struct_to_file(myEmployee const* const employee);

int main()
{
    // task 1: Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции: для инициализации массива (типа float), печати его на экран и подсчета количества отрицательных и положительных элементов. Вызывайте эти 3-и функции из main для работы с массивом.
    //task 5: * Сделайте задание 1 добавив свой неймспейс во втором модуле (первое задание тогда можно не делать).
    {
        setlocale(LC_ALL, "Russian");

        size_t const ARR_SIZE = 20;
        float array[ARR_SIZE];

        MyLib::ArrayStructure array_structure { 0, 0 };
        std::cout << "tasks 1, 5:\n";
        MyLib::init_array(array, ARR_SIZE);
        MyLib::print_array(array, ARR_SIZE);
        MyLib::fill_array_structure(array, ARR_SIZE, &array_structure);
        std::cout << "Положительное число в массиве: " << array_structure.pos_nums << '\n';
        std::cout << "Отрицательное число в массиве: " << array_structure.neg_nums << '\n';
    }

    // task 2: Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры) в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно) и возвращает true или false, вывести на экран «true» или «false».
    {
       
        size_t const RANGE = 50;
        int num;

        std::cout << "\ntask 2:\n";
        std::cout << "Введите число для проверки, что оно входит в диапазон чисел: [0; " << RANGE << "):\n";
        std::cin >> num;
        std::cout << (IN_RANGE(num, RANGE) ? "true" : "false") << '\n';
    }

    // task 3: Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. Инициализируйте его через ввод с клавиатуры. Напишите для него свою функцию сортировки (например Пузырьком). Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки.
    {
        int array[ONE_ARR_SIZE];

        std::cout << "\ntask 3:\n";
        initial_user_array(array, ONE_ARR_SIZE);

        sorted_myarray(array, ONE_ARR_SIZE);
        std::cout << "Отсортированный массив чисел:\n";

        printed_myarray(array, ONE_ARR_SIZE);
    }

    // task 4:* Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack. Выделите динамически переменную этого типа. Инициализируйте ее. Выведите ее на экран и ее размер с помощью sizeof. Сохраните эту структуру в текстовый файл. 
    {
        myEmployee* employee = new myEmployee;

        employee->age = 25;
        employee->id = 101;
        employee->salary = 50.6;

        std::cout << "\ntask 4:\n";
        print_struct_my_employee(employee);

        std::cout << "Размер структуры сотрудника: " << sizeof(*employee) << '\n';
        struct_to_file(employee);

        delete employee;
    }
}

void initial_user_array(int* const array, size_t const array_size)
{
    std::cout << "Введите размер массива" << array_size << '\n';
    for (size_t i = 0; i < array_size; i++) {
        std::cin >> array[i];
    }
}

void sorted_myarray(int* const array, size_t const array_size)
{
    for (size_t i = 0; i < array_size - 1; i++) {
        for (size_t j = 0; j < array_size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                SWAP(array[j], array[j + 1]);
            }
        }
    }
}

void printed_myarray(int const* const array, size_t const array_size)
{
    for (size_t i = 0; i < array_size; i++) {
        std::cout << array[i] << ' ';
    }
    std::cout << '\n';
}

void print_struct_my_employee(myEmployee const* const employee)
{
    std::cout << "Age: " << employee->age << '\n'
        << "ID: " << employee->id << '\n'
        << "Salary: " << employee->salary << '\n';
}

void struct_to_file(myEmployee const* const employee)
{
    std::string const filename = "employee.txt";
    std::ofstream employee_file(filename);

    employee_file << "Age: " << employee->age << '\n'
        << "ID: " << employee->id << '\n'
        << "Salary: " << employee->salary << '\n';

    employee_file.close();

    std::cout << "Файл сохранен в документ: " << filename << '\n';
}