//
// Created by kristianshevando on 12/12/17.
//

#ifndef PHONEBOOK_INTERFACE_H
#define PHONEBOOK_INTERFACE_H

#include <iostream>

class Intface
{
public:
    virtual void mode() = 0;
    virtual void searchMode() = 0;
};

class MainModeInterface : public Intface
{
public:
    virtual void mode() override
    {

    }
};

class AdministratorInterface : public Intface
{
public:
    void mode() override
    {
        std::cout << "1.Работа с аккаунтом"    << std::endl;
        std::cout << "2.Работа с базой данных" << std::endl;
        std::cout << "0.ВЫЙТИ"                 << std::endl;
        std::cout << ">>> ";
    }

    void databaseMode()
    {
        std::cout << "1.Просмотреть все записи" << std::endl;
        std::cout << "2.Добавить запись"        << std::endl;
        std::cout << "3.Удалить запись"         << std::endl;
        std::cout << "4.Редактировать запись"   << std::endl;
        std::cout << "5.Поиск записи"           << std::endl;
        std::cout << "0.ВЫЙТИ"                  << std::endl;
        std::cout << ">>> ";
    }

    void accountsMode()
    {
        std::cout << "1.Просмотреть аккаунты" << std::endl;
        std::cout << "2.Добавить аккаунт"     << std::endl;
        std::cout << "3.Изменить аккаунт"     << std::endl;
        std::cout << "4.Удалить аккаунт"      << std::endl;
        std::cout << "0.ВЫЙТИ"                << std::endl;
        std::cout << ">>> ";
    }

    void changeDatabaseMode()
    {
        std::cout << "1.Изменить имя"             << std::endl;
        std::cout << "2.Изменить фамилию"         << std::endl;
        std::cout << "3.Изменить отчество"        << std::endl;
        std::cout << "4.Изменить номер телефона"  << std::endl;
        std::cout << "5.Изменить название города" << std::endl;
        std::cout << "6.Изменить название улицы"  << std::endl;
        std::cout << "7.Изменить номер дома"      << std::endl;
        std::cout << "8.Изменить номер корпуса"   << std::endl;
        std::cout << "9.Изменить номер квартиры"  << std::endl;
        std::cout << "0.ВЫЙТИ"                    << std::endl;
        std::cout << ">>> ";
    }

    void changeAccountMode()
    {
        std::cout << "1.Изменить имя пользователя" << std::endl;
        std::cout << "2.Изменить пароль"           << std::endl;
        std::cout << "0.ВЫЙТИ"                     << std::endl;
        std::cout << ">>> ";
    }

    void searchMode() override
    {
        std::cout << "1.Поиск по имени"           << std::endl;
        std::cout << "2.Поиск по фамилии"         << std::endl;
        std::cout << "3.Поиск по отчеству"        << std::endl;
        std::cout << "4.Поиск по номеру телефона" << std::endl;
        std::cout << "5.Поиск по названию города" << std::endl;
        std::cout << "6.Поиск по названию улицы"  << std::endl;
        std::cout << "7.Поиск по номеру дома"     << std::endl;
        std::cout << "8.Поиск по номеру корпуса"  << std::endl;
        std::cout << "9.Поиск по номеру квартиры" << std::endl;
        std::cout << "0.ВЫЙТИ"                    << std::endl;
        std::cout << ">>> ";
    }
};

class UserInterface : public Intface
{
public:
    void searchMode() override
    {
        std::cout << "1.Поиск по имени"           << std::endl;
        std::cout << "2.Поиск по фамилии"         << std::endl;
        std::cout << "3.Поиск по отчеству"        << std::endl;
        std::cout << "4.Поиск по номеру телефона" << std::endl;
        std::cout << "5.Поиск по названию города" << std::endl;
        std::cout << "6.Поиск по названию улицы"  << std::endl;
        std::cout << "7.Поиск по номеру дома"     << std::endl;
        std::cout << "8.Поиск по номеру корпуса"  << std::endl;
        std::cout << "9.Поиск по номеру квартиры" << std::endl;
        std::cout << "0.ВЫЙТИ"                    << std::endl;
        std::cout << ">>> ";
    }
};

class Human
{
};

#endif //PHONEBOOK_INTERFACE_H
