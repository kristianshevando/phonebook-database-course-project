//
// Created by kristianshevando on 12/19/17.
//

#ifndef PHONEBOOK_HUMAN_H
#define PHONEBOOK_HUMAN_H


#include "NaturalPerson.h"

class Human : public NaturalPerson{
protected:
    std::string nationality_;  //Гражданство
public:
    Human()  //Конструктор без параметров
    {
        nationality_ = "";
    };
    Human(const Human&); //Конструктор копирования
    Human(int id, std::string cityName, std::string streetName,
                 int houseNumber, int apartmentNumber, int phoneNumber,
                 std::string name, std::string surname, std::string nationality); //Конструктор с параметрами
    ~Human();   //Деструктор

    void setData() override; // Метод определяющий поля
    void head() override; //Метод, выводящий заголовки
    void showData() override; //Метод, выводящий поля
    void editMode() override; //Метод, выводящий меню изменения полей
    void editData(); //Метод, изменяющий данные
    void sortingData() override; //Метод, выводящий меню сортировки полей

    friend std::istream& operator >>(std::istream&, Human&);  //Перегрузка ввода
    friend std::ostream& operator <<(std::ostream&, Human&);  //Перегрузка вывода
    friend std::ifstream& operator >>(std::ifstream&, Human&); //Перегрузка ввода
    friend std::ofstream& operator <<(std::ofstream&, Human&); //Перегрузка вывода
    Human operator =(const Human&); //Перегрузка оператора присваивания
    bool operator ==(const Human&); //Перегрузка оператора сравнения

    virtual void setNationality();  //Метод, определяющий значение nationality_
    virtual std::string getNationality(); //Метод, возвращающий значение nationality_

    friend bool compareNationality(const Human *,const Human *, int); //Метод, сравнивающий значение nationality_
};


#endif //PHONEBOOK_HUMAN_H
