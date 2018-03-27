//
// Created by kristianshevando on 12/19/17.
//

#ifndef PHONEBOOK_NATURALPERSON_H
#define PHONEBOOK_NATURALPERSON_H

#include "Person.h"

class NaturalPerson : virtual public Person
{
protected:
    std::string name_;     //Имя
    std::string surname_;  //Фамилия
public:
    NaturalPerson();       //Конструктор без параметров
    NaturalPerson(const NaturalPerson &);  //Конструктор копирования
    NaturalPerson(int, std::string, std::string, int, int, int, std::string, std::string);  //Конструктор с параметрами
    ~NaturalPerson(){}  //Деструктор

    virtual void setData(); //Метод определяющий поля элемента
    virtual void head();    //Метод, выводящий заголовки
    virtual void showData(); //Метод, выводящий данные полей
    virtual void editMode(); //Метод, вызывающий меню изменения данных
    virtual void sortingData(); //Метод, вызывающий меню сортировки

    friend std::istream&  operator >>(std::istream&, NaturalPerson&); //Перегрузка ввода
    friend std::ostream&  operator <<(std::ostream&, NaturalPerson&); //Перегрузка вывода
    friend std::ifstream& operator >>(std::ifstream&, NaturalPerson&); //Перегрузка ввода
    friend std::ofstream& operator <<(std::ofstream&, NaturalPerson&); //Перегрузка вывода
    NaturalPerson operator =(const NaturalPerson&); //Перегрузка оператора присваивания
    bool operator ==(const NaturalPerson&); //Перегрузка оператора сравнения

    virtual void setName(); //Метод, определяющий значение поля name_
    virtual void setSurname(); //Метод, определяющий значение поля surname_

    virtual std::string getName(); //Метод, возвращающий значение поля name_
    virtual std::string getSurname();//Метод, возвращающий значение поля surname_

    friend bool compareName(const NaturalPerson *,const NaturalPerson *, int); //Метод, сравнивающий значение поля name_
    friend bool compareSurname(const NaturalPerson *,const NaturalPerson *, int); //Метод, сравнивающий значение поля surname_
};


#endif //PHONEBOOK_NATURALPERSON_H
