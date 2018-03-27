//
// Created by kristianshevando on 12/19/17.
//

#ifndef PHONEBOOK_LEGALPERSON_H
#define PHONEBOOK_LEGALPERSON_H
#include "Person.h"

class LegalPerson : public Person
{
protected:
    std::string companyName_; //Название компании
public:
    LegalPerson();   //Конструктор без параметров
    LegalPerson(const LegalPerson&);  //Конструктор копирования
    LegalPerson(int, std::string, std::string, int, int, int, std::string); //Конструктор с параметрами
    ~LegalPerson();  //Деструктор

    void setData();  //Метод, определяющий данные полей
    void head();  //Метод, выводящий заголовки
    void showData(); //Метод, выводящий поля
    void editMode(); //Метод, выводящий меню изменения данных
    void sortingData(); //Метод, вызывающий меню сортировки данных

    friend std::istream&  operator >>(std::istream&, LegalPerson&);  //Перегрузка ввода
    friend std::ostream&  operator <<(std::ostream&, LegalPerson&);  //Перегрузка вывода
    friend std::ifstream& operator >>(std::ifstream&, LegalPerson&); //Перегрузка ввода
    friend std::ofstream& operator <<(std::ofstream&, LegalPerson&); //Перегрузка вывода
    LegalPerson operator =(const LegalPerson&); //Перегрузка оператора присваивания
    bool operator ==(const LegalPerson&); //Перегрузка оператора сравнения

    virtual void setCompanyname();  //Метод определяющий поле companyName_
    virtual std::string getCompanyName(); //Метод, возвращающий значение поля companyName_

    friend bool compareCompanyName(const LegalPerson *,const LegalPerson *, int);
};


#endif //PHONEBOOK_LEGALPERSON_H
