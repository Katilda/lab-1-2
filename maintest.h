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
    length =0;
    listPages.push_back (0);
    arrayPage="";
    //cout<<"Object created!"<<endl;
}

listalke::listalke(int length1, int totalPages1, int currentPage1)  //описание конструктора с заданной длиной
{
    currentPage =currentPage1;
    totalPages =totalPages1;
    length = length1;
    listPages.push_back (0);
    arrayPage="";
    //cout<<"Object created!"<<endl;
}


string listalke::start(int length1, int totalPages1, int currentPage1)
{
    currentPage =currentPage1;
    totalPages =totalPages1;
    length = length1;
    //arrayPage=arrayPage1;


    create_listalke();
    if ((currentPage==0) || (length==0) || (totalPages==0))
    {
//        cout <<"Error! Incorrect values!"<<endl;
        arrayPage="0";
//        cout <<arrayPage<<endl;
    }
    else if ((currentPage==1) && (length==1) && (totalPages==1))
    {
//        cout <<"One page."<<endl;
        arrayPage="1";
//        cout <<arrayPage<<endl;
    }

    else if (currentPage>totalPages)
    {
//        cout<<"Incorrect values! Current page large total pages."<<endl;
        arrayPage="0";
    }
    else if (length>totalPages)
    {
//        cout<<"Incorrect values! Length listalke large total pages."<<endl;
        arrayPage="0";
    }

    else
    {
      list_pages();
      print_listalke();
    }
    //cout<<"Result: "<<arrayPage<<endl;
    return arrayPage;
 }

void listalke::create_listalke() //описание функции ввода данных
{
    bool correctInput=0;
    while (correctInput==0) {
        char str[255]="";
        //cout<<"Length lister - ";

       //itoa(length,str,10);
        sprintf(str,"%d",length);

        //str = length;
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
        char str[255]="";
        //cout<<"Total pages - ";
        //cin>>str;
        //itoa(totalPages,str,10);
        sprintf(str,"%d",totalPages);
        //str = totalPages;
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
        char str[255]="";
        //cout<<"Current page - ";
        //cin>>str;
        //itoa(currentPage,str,10);
        sprintf(str,"%d",currentPage);
        //str = currentPage;
        if (IsValidInt(str)){
            currentPage=atoi(str);
            correctInput=1;
        }
        else {
            cout<<"Incorrect input! Current page should be decimal! Please, repeat correct input!"<<endl;
        }
    }

 return;
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
        c=0;
        for (int i=0; i<totalPages-currentPage;i++)
        {
	 if(currentPage+i+1!=totalPages)
		{
            	listPages.push_back(currentPage+(i+1));
		c++;
		}
          listPages.push_front(currentPage-i-1);
          c++;
        }
                    //дописываем недостающие страницы в начало
        b=length-(c+1);

        for (int i=0; i<b; i++)
        {
            listPages.push_front(currentPage-c-i-1);
        }
        break;
    case (4):
        c=0;
        for (int i=0; i<currentPage-1;i++)
        {
            if (currentPage-(i+1)!=1)
            {
            listPages.push_front(currentPage-i-1);
            c++;
            }
            listPages.push_back(currentPage+i+1);
            c++;
        }
                    //дописываем недостающие страницы в конец
        b=length-c-1;//потому что потом мы вычтем 1 из b
        for (int i=0; i<b; i++)
        {
            listPages.push_back(currentPage+c+i+1);
        }
        break;
    case (5):
        for (int i=0; i<((length/2)-1);i++)
        {
            listPages.push_front(currentPage-i-1);
            listPages.push_back(currentPage+i+1);
        }
        listPages.push_back(currentPage+(length/2));
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
    string buffer;
//    int counter=1;

    if (currentPage!=1)
    {
       arrayPage="1 << ";
    }
    for ( list<int>::iterator it = listPages.begin(); it != listPages.end(); ++it  )
    {
        if(*it==currentPage)
        {
        //cout<<"["<< *it << "]"<<' ';
        arrayPage=arrayPage+"[";
        //itoa(*it,buffer,10);
        stringstream ss;
        ss << *it;
        buffer = ss.str();
        arrayPage=arrayPage+buffer;
        arrayPage=arrayPage+"]";
        if (currentPage!=totalPages) {
        arrayPage=arrayPage+" ";
        }
    }
    else
          {
            //cout << *it << ' ';
            //itoa(*it,buffer,10);
            stringstream ss;
            ss << *it;
            buffer = ss.str();
            arrayPage=arrayPage+buffer;
            arrayPage=arrayPage+" ";
        }
//            counter++;
    }
    if (currentPage!=totalPages)
    {
    arrayPage=arrayPage+">> ";
    stringstream ss;
    ss << totalPages;
    buffer = ss.str();
    arrayPage=arrayPage+buffer;
    }

}
