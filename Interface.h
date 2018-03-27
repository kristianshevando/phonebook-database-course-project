//
// Created by kristianshevando on 12/16/17.
//

#ifndef PHONEBOOK_INTERFACE_H
#define PHONEBOOK_INTERFACE_H

#include "List.cpp"
#include "Protect.h"
#include "Human.h"
#include "Company.h"

template<class T>
class Interface {
private:
    Protect protect;
    T object;  //Шаблонная переменная
public:
    Interface(); //Коонструктор без параметров
    Interface(const T&); //Конструктор копирования
    void mainMode(); //Главное меню
    void objectMode(int, std::string);  //Меню работы с данными
    ~Interface(); //Деструктор
};

#endif //PHONEBOOK_INTERFACE_H