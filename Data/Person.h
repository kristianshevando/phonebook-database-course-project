//
// Created by kristianshevando on 12/19/17.
//

#ifndef PHONEBOOK_PERSON_H
#define PHONEBOOK_PERSON_H
#include "Protect.h"
#include "Types.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

class Person
{
    Protect protect;
protected:
    int    ID_;                           //ID элемента
    string cityName_;                     //Название города
    string streetName_;                   //Название улицы
    int    houseNumber_;                  //Номер дома
    int    apartmentNumber_;              //Номер квартиры
    int    phoneNumber_;                  //Номер телефона
public:
    Person() {                            //Конструктор без параметров
        ID_              = 0;
        cityName_        = "";
        streetName_      = "";
        houseNumber_     = 0;
        apartmentNumber_ = 0;
        phoneNumber_     = 0;
    };
    Person(int ID, string cityName, string streetName,
                   int houseNumber, int apartmentNumber, int phoneNumber)  //Конструктор с параметрами
    {
        ID_              = ID;
        cityName_        = cityName;
        streetName_      = streetName;
        houseNumber_     = houseNumber;
        apartmentNumber_ = apartmentNumber;
        phoneNumber_     = phoneNumber;
    };

    Person(const Person&);       //Конструктор копирования

    ~Person(){}                  //Деструктор

    virtual void setData();      //Метод, определяющий поля
    virtual void head();         //Метод, показывающий загловки
    virtual void showData();     //Метод, выводящий данные
    virtual void editMode();     //Метод, изменяющий данные полей
    virtual void sortingData();  //Метод, вызывающий меню сортировки

    friend istream&  operator >>(istream&, Person&); //Перегрузка ввода
    friend ostream&  operator <<(ostream&, Person&); //Перегрузка вывода
    friend ifstream& operator >>(ifstream&, Person&); //Перегрузка ввода
    friend ofstream& operator <<(ofstream&, Person&); //Перегрузка вывода
    Person operator =(const Person&);  //Перегрузка оператора присваивания
    bool operator ==(const Person&);   //Перегрузка оператора сравнения

    virtual void setID();         //Метод, определяющий ID элемента
    virtual void setCityName();   //Метод, определяющий название города
    virtual void setStreetName(); //Метод, определяющий название улицы
    virtual void setHouseNumber(); //Метод, определяющий номер дома
    virtual void setApartmentNumber(); //Метод, определяющий номер квартиры
    virtual void setPhoneNumber(); //Метод, определяющий номер телефона

    virtual int         getID();  //Метод, возвращающий значение ID элемента
    virtual std::string getCityName();  //Метод, возвращающий значение поля cityName
    virtual std::string getStreetName(); //Метод, возвращающий значение поля streetName
    virtual int         getHouseNumber(); //Метод, возвращающий значение поля houseNumber
    virtual int         getApartmentNumber(); //Метод, возвращающий значение поля apartmentNumber
    virtual int         getPhoneNumber(); //Метод, возвращающий значение поля phoneNumber

    friend bool compareID(const Person *, const Person *, int); //Метод, сравнивающий поле ID
    friend bool compareCityName(const Person *, const Person *, int); //Метод, сравнивающий поле cityName
    friend bool compareStreetName(const Person *, const Person *, int); //Метод, сравнивающий поле streetName
    friend bool compareHouseNumber(const Person *, const Person *, int); //Метод, сравнивающий поле houseNumber
    friend bool compareApartmentNumber(const Person *, const Person *, int); //Метод, сравнивающий поле apaertmentNumber
    friend bool comparePhoneNumber(const Person *, const Person *, int); //Метод, сравнивающий поле phoneNumber
};


#endif //PHONEBOOK_PERSON_H
