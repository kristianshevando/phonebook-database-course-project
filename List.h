//
// Created by kristianshevando on 12/22/17.
//

#ifndef PHONEBOOK_LIST_H
#define PHONEBOOK_LIST_H

#include "Header.h"

template<class Type>
struct Line {
    Type object; //Элемент
    Line<Type> *next; //Указатель на следующий элемент
    Line<Type> *previous; //Указатель на предыдущий элемент
};

template<class Type>
class List {
private:
    Line<Type> *begin;  //Указатель на начало списка
    Line<Type> *end;    //Указатель на конец списка
    int size;           //Размер списка
public:
    List();             //Конструктор без параметров
    List(const List<Type>&); //Конструктор копирования
    void pushFront(const Type&); //Добавление элемента в начало
    void pushBack(const Type&); //Добавление элемента в конец
    Type removeFront(); //Удаление из начала
    Type removeBack(); //Удаление из конца
    void removeAll(); //Удаление всех элементов
    int  getSize();   //Метод, возвращающий размер списка
    Type remove(Line<Type>*); //Удаление по индексу
    void showFront(); //Вывод всех элементов с начала списка
    void showBack();  //Вывод всех элементов с конца списка
    Line<Type>* operator [] (int); //Перегрузка оператора []
    void readFile(std::string); //Чтение из файла
    void writeFile(std::string); //Запись в файл
    bool isEmpty(); //Проверка списка на пустоту
    void searchByID(int); //Поиск по ID
    void searchByStreetAndHouseNumber(std::string, int); // Поиск по названию улицы и по номеру дома
    void searchByPhoneNumber(int); //Поиск по номеру телефона

    void sort(int, bool(*Compare)(Type*, Type*,int)); //Сортировка
    ~List(); //Деструктор
};


#endif //PHONEBOOK_LIST_H
