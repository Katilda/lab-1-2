#include <conio.h>
#include <iostream>
#include <math.h>
#include <list>

using namespace std;

class listalke
{
    int length;  //кол-во страниц между стрелками НАЗАД и ВПЕРЁД
    int currentPage; //текущая страница
    int totalPages; //общее число страниц
    list<int> listPages; //массив номеров страниц
    protected:
        void list_pages();  //возвращает массив страниц
        void print_listalke(); //возвращает текст страницы
    public:
        listalke();  //конструктор по умолчанию
        listalke(int length); //конструктор с заданной длиной
        ~listalke() {}; //деструктор
        void start();
        void create_listalke(); //ввод исходных данных

};

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
    list_pages();
    print_listalke();
}

void listalke::create_listalke() //описание функции ввода данных
{
    cout<<"Enter values:"<<endl;
    cout<<"Length listalke - ";
    cin>>length;
    cout<<"Total pages - ";
    cin>>totalPages;
    cout<<"Current page - ";
    cin>>currentPage;
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


    if (currentPage==totalPages)  //текущая - последняя страница
    {
        for(int i=0; i<length-1; i++)
        {
            listPages.push_front(currentPage-i-1);
        }
    }

    else
    {
        if (currentPage==1)  //текущая - первая страница
        {
            for(int i=0; i<length-1; i++)
            {
                listPages.push_back(currentPage+i+1);
            }
        }

        else
        {
            if((totalPages-currentPage)<=(length/2)) //текущая страница ближе к концу
            {
                int c=1;
                for (int i=currentPage; i<totalPages-1;i++)
                {
                    listPages.push_front(currentPage-c);
                    listPages.push_back(currentPage+c);
                    c++;
                }
                            //дописываем недостающие страницы в начало
                int b=length-(c-1)*2+1;

                for (int i=0; i<b; i++)
                {
                    listPages.push_front(currentPage-c-i);
                }
            }

            if((currentPage-1)<=(length/2)) //текущая страница ближе к началу
            {
                int c=1;
                for (int i=currentPage-1; i>1;i--)
                {
                    listPages.push_front(currentPage-c);
                    listPages.push_back(currentPage+c);
                    c++;
                }
                            //дописываем недостающие страницы в конец
                int b=length-(c-1)*2+1;
                for (int i=0; i<b; i++)
                {
                    listPages.push_back(currentPage+c+i);
                }
            }
            else
            {
                if(length % 2 == 0)
                {
                //четное число выводимых страниц

                    for (int i=0; i<((length/2)-1);i++)
                    {
                        listPages.push_front(currentPage-i-1);
                        listPages.push_back(currentPage+i+1);
                    }
                    listPages.push_back(currentPage+(length/2)+1);
                }
                else
                {
                    //не четное число выводимых страниц

                    for (int i=0; i<round(length/2);i++)
                    {
                        listPages.push_front(currentPage-i-1);
                        listPages.push_back(currentPage+i+1);
                    }
                }
            }
        }
    }
}


void listalke::print_listalke() //описание функции возврата текста страницы
{
    //cout<<"Length: "<<this->length<<endl;
    //cout<<"Total pages: "<<this->totalPages<<endl;
    //cout<<"Current page: "<<this->currentPage<<endl;


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

