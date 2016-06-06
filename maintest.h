#include <iostream>
#include <math.h>
#include <list>
#include <ctype.h>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <sstream>


using namespace std;

class listalke
{
    int length;  //кол-во страниц между стрелками НАЗАД и ВПЕРЁД
    int currentPage; //текущая страница
    int totalPages; //общее число страниц
    string arrayPage;
    list<int> listPages; //массив номеров страниц
    protected:
        void list_pages();  //функция возвращающая массив страниц
        void print_listalke(); //функция возвращающая текст страницы
    public:
        listalke();  //конструктор по умолчанию
        listalke(int length1, int totalPages1, int currentPage1); //конструктор с заданной длиной
        ~listalke() {}; //деструктор
        string start(int length1, int totalPages1, int currentPage1); //функция запуска листалки
        void create_listalke(); //функция ввода исходных данных

};


