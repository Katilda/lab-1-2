#include <conio.h>
#include <iostream>
#include <math.h>
#include <list>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

class listalke
{
    int length;  //кол-во страниц между стрелками НАЗАД и ВПЕРЁД
    int currentPage; //текущая страница
    int totalPages; //общее число страниц
    list<int> listPages; //массив номеров страниц
    protected:
        void list_pages();  //функция возвращающая массив страниц
        void print_listalke(); //функция возвращающая текст страницы
    public:
        listalke();  //конструктор по умолчанию
        listalke(int length); //конструктор с заданной длиной
        ~listalke() {}; //деструктор
        void start(); //функция запуска листалки
        void create_listalke(); //функция ввода исходных данных

};

bool IsValidInt(char* x){
    bool Checked = true;
    int i = 0;
    do
    {
        //valid digit?
        if (isdigit(x[i]))
        {
            //to the next character
            i++;
            Checked = true;
        }
        else
        {
            //to the next character
            i++;
            Checked = false;
            break;
        }
    } while (x[i] != '\0');

    return Checked;
}



listalke::listalke() //описание конструктора по умолчанию
{
    currentPage =0;
    totalPages =0;
    length =1;
    listPages.push_back (0);
    cout<<"Object created!"<<endl;
}

listalke::listalke(int length1)  //описание конструктора с заданной длиной
{
    currentPage =0;
    totalPages =0;
    length = length1;
    listPages.push_back (0);
    cout<<"Object created!"<<endl;
}


void listalke::start()
{
    create_listalke();
    if ((currentPage==0) || (length==0) || (totalPages==0))
    {
        cout <<"Error! Incorrect values!"<<endl;
        cout <<"0"<<endl;
    }
    else
    {
        if ((currentPage==1) || (length==1) || (totalPages==1))
        {
            cout <<currentPage<<endl;
        }
        else
        {
            list_pages();
            print_listalke();
        }
    }
 }

void listalke::create_listalke() //описание функции ввода данных
{
    cout<<"Enter values:"<<endl;
    bool correctInput=0;
    while (correctInput==0) {
        char str[]="";
        cout<<"Length lister - ";
        cin>>str;
        if (IsValidInt(str)){
            length=atoi(str);
            correctInput=1;
        }
        else {
            cout<<"Incorrect input! Lenght lister should be decimal! Please, repeat correct input!"<<endl;
        }
    }
    correctInput=0;
    while (correctInput==0) {
        char str[]="";
        cout<<"Total pages - ";
        cin>>str;
        if (IsValidInt(str)){
            totalPages=atoi(str);
            correctInput=1;
        }
        else {
            cout<<"Incorrect input! Total pages should be decimal! Please, repeat correct input!"<<endl;
        }
    }
    correctInput=0;
    while (correctInput==0) {
        char str[]="";
        cout<<"Current page - ";
        cin>>str;
        if (IsValidInt(str)){
            currentPage=atoi(str);
            correctInput=1;
        }
        else {
            cout<<"Incorrect input! Current page should be decimal! Please, repeat correct input!"<<endl;
        }
    }

    if (currentPage>totalPages)
    {
        cout<<"Incorrect values! Current page large total pages."<<endl;
        create_listalke();   //рекурсивное обращение к функции
    }
    if (length>totalPages)
    {
        cout<<"Incorrect values! Length listalke large total pages."<<endl;
        create_listalke();   //рекурсивное обращение к функции
    }

}

void listalke::list_pages()  //описание функции возврата массива страниц
{
    listPages.clear();  //очищаем список выводимых страниц
    listPages.push_back(currentPage); //добавляем текущую страницу
    int a=0;
    int c=1;
    int b=0;

            if (currentPage==totalPages) a =1;  //текущая - последняя страница
            else {
                if (currentPage==1)  a =2;  //текущая - первая страница
                else {
                    if((totalPages-currentPage)<=(length/2)) a =3; //текущая страница ближе к концу
                    else {
                        if((currentPage-1)<=(length/2)) a =4;//текущая страница ближе к началу
                        else {
                            if (length % 2 == 0)  a =5;  //четное число выводимых страниц
                        }
                    }
                }
            }




    switch (a)
    {
    case (1):
        for(int i=0; i<length-1; i++)
        {
            listPages.push_front(currentPage-i-1);
        }
        break;
    case (2):
        for(int i=0; i<length-1; i++)
        {
            listPages.push_back(currentPage+i+1);
        }
        break;
    case (3):
        c=1;
        for (int i=currentPage; i<totalPages-1;i++)
        {
            listPages.push_front(currentPage-c);
            listPages.push_back(currentPage+c);
            c++;
        }
                    //дописываем недостающие страницы в начало
        b=length-(c-1)*2+1;

        for (int i=0; i<b; i++)
        {
            listPages.push_front(currentPage-c-i);
        }
        break;
    case (4):
        c=1;
        for (int i=currentPage-1; i>1;i--)
        {
            listPages.push_front(currentPage-c);
            listPages.push_back(currentPage+c);
            c++;
        }
                    //дописываем недостающие страницы в конец
        b=length-(c-1)*2+1;
        for (int i=0; i<b; i++)
        {
            listPages.push_back(currentPage+c+i);
        }
        break;
    case (5):
        for (int i=0; i<((length/2)-1);i++)
        {
            listPages.push_front(currentPage-i-1);
            listPages.push_back(currentPage+i+1);
        }
        listPages.push_back(currentPage+(length/2)+1);
        break;
    default:
        //не четное число выводимых страниц

        for (int i=0; i<round(length/2);i++)
        {
            listPages.push_front(currentPage-i-1);
            listPages.push_back(currentPage+i+1);
        }
        break;
    }
}


void listalke::print_listalke() //описание функции возврата текста страницы
{
    cout << "1" << " << ";
    for ( list<int>::iterator it = listPages.begin(); it != listPages.end(); ++it  )
    {
        if(*it==currentPage)
        {
        cout<<"["<< *it << "]"<<' ';
    }
    else
          {
            cout << *it << ' ';
        }
    }
    cout<< ">> " << totalPages;
}



int main()
{
    listalke Listalke1; //создание объекта класса
    Listalke1.start();
    return 0;
}

