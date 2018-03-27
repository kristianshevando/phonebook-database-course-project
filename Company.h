//
// Created by kristianshevando on 12/19/17.
//

#ifndef PHONEBOOK_COMPANY_H
#define PHONEBOOK_COMPANY_H


#include "LegalPerson.h"

class Company : public LegalPerson{
private:
    int fax_;  //Факс
public:
    Company(); //Конструктор без параметров
    Company(const Company&); //Конструктор копирования
    Company(int, std::string, std::string, int, int, int, std::string, int); //Конструктор с параметрами
    ~Company(); //Деструктор

    void setData();  //Метод, задающий значения полей
    void head();  //Метод, выводящий заголовки
    void showData(); //Метод, выводящий данные
    void editMode(); //Метод, выводящий меню изменения данных
    void editData(); //Метод, изменяющий данные
    void sortingData(); //Метод, выводящий меню сортировки

    friend std::istream&  operator >>(std::istream&, Company&); //Перегрузка ввода
    friend std::ostream&  operator <<(std::ostream&, Company&); //Перегрузка вывода
    friend std::ifstream& operator >>(std::ifstream&, Company&); //Перегрузка ввода
    friend std::ofstream& operator <<(std::ofstream&, Company&); //Перегрузка вывода
    Company operator =(const Company&); //Перегрузка оператора присваивания
    bool operator ==(const Company&); //Перегрузка оператора сравнения

    virtual void setFax(); //Метод, определяющий поле fax_
    virtual int getFax(); //Метод, возвращающий значение поля fax_

    friend bool compareFax(const Company *, const Company *, int); //Метод, сравниавющий поле fax
};


#endif //PHONEBOOK_COMPANY_H
