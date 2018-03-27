//
// Created by kristianshevando on 12/16/17.
//

#include "Interface.h"

template<class T>
Interface<T>::Interface()
{
}

template <class T>
Interface<T>::Interface(const T& object) {
    this->object = object.object;
}

template<class T>
void Interface<T>::mainMode() {
    int choice;
    int call;
    std::string file;
    while(true) {

        std::cout << "1.Физическое лицо"  << std::endl;
        std::cout << "2.Юридическое лицо" << std::endl;
        std::cout << "0.ВЫЙТИ" << std::endl;
        std::cout << ">>> ";
        choice = protect.protect();
        switch (choice) {
            case 1: {
                Interface<Human> person;
                file = "humanbook.txt";
                call = 1;
                system("clear");
                person.objectMode(call, file);
                break;
            }
            case 2:{
                Interface<Company> company;
                file = "companybook.txt";
                call = 2;
                company.objectMode(call, file);
                break;
            }
            default: break;
        }
        break;
    }
}

template<class T>
void Interface<T>::objectMode(int call, std::string file) {
    List<T> list;
    list.readFile(file);
    T value;
    int choice;
    int index;
    bool temp = true;
    while (temp) {
        std::cout << "1.Добавить" << std::endl;
        std::cout << "2.Удалить" << std::endl;
        std::cout << "3.Поиск" << std::endl;
        std::cout << "4.Просмотреть" << std::endl;
        std::cout << "5.Редактирование" << std::endl;
        std::cout << "6.Сортировка" << std::endl;
        std::cout << "7.Сохранить" << std::endl;
        std::cout << "0.ВЫЙТИ" << std::endl;
        std::cout << ">>> ";
        choice = protect.protect();
        switch (choice) {
            case 1:
                system("clear");
                std::cout << "1.Добавить в начало" << std::endl;
                std::cout << "2.Добавить в конец" << std::endl;
                std::cout << "0.ВЫЙТИ" << std::endl;
                std::cout << ">>> ";
                std::cin >> choice;
                switch (choice) {
                    case 1:
                        system("clear");
                        value.setData();
                        list.pushFront(value);
                        break;
                    case 2:
                        system("clear");
                        value.setData();
                        list.pushBack(value);
                        break;
                    default:
                        break;
                }
                break;
            case 2:
                system("clear");
                std::cout << "1.Удалить с начала" << std::endl;
                std::cout << "2.Удалить с конца" << std::endl;
                std::cout << "3.Удалить по индексу" << std::endl;
                std::cout << "0.НАЗАД" << std::endl;
                std::cout << ">>> ";
                std::cin >> choice;
                if (list.getSize() == 0) {
                    system("clear");
                    std::cout << "Список пуст" << std::endl;
                } else {
                    switch (choice) {
                        case 1:
                            list.removeFront();
                            system("clear");
                            std::cout << "Удалено" << std::endl;
                            break;
                        case 2:
                            list.removeBack();
                            system("clear");
                            std::cout << "Удалено" << std::endl;
                            break;
                        case 3:
                            system("clear");
                            list.showFront();
                            std::cout << "Номер элемента: ";
                            std::cin >> index;
                            list.remove(list[index]);
                            system("clear");
                            std::cout << "Удалено" << std::endl;
                            break;
                        default:
                            system("clear");
                            break;
                    }
                }
                break;
            case 3:
                system("clear");
                std::cout << "1.Поиск по ID" << std::endl;
                std::cout << "2.Поиск по названию улицы и по номеру дома" << std::endl;
                std::cout << "3.Поиск по номеру телефона" << std::endl;
                std::cout << ">>> ";
                std::cin >> choice;
                if (list.getSize() == 0) {
                    system("clear");
                    std::cout << "Список пуст" << std::endl;
                } else {
                    int idKey;
                    std::string streetKey;
                    int houseNumberKey;
                    int phoneNumberKey;

                    switch (choice) {
                        case 1:
                            std::cout << "Введите ID элемента: ";
                            std::cin >> idKey;
                            list.searchByID(idKey);
                            break;
                        case 2:
                            std::cin.ignore();
                            std::cout << "Введите улицу: ";
                            getline(std::cin, streetKey);
                            std::cout << "Введите номер дома: ";
                            std::cin >> houseNumberKey;
                            list.searchByStreetAndHouseNumber(streetKey, houseNumberKey);
                            break;
                        case 3:
                            std::cout << "Введите номер телефона: ";
                            std::cin >> phoneNumberKey;
                            list.searchByPhoneNumber(phoneNumberKey);
                            break;
                        default:
                            system("clear");
                            break;
                    }
                }
                break;
            case 4:
                system("clear");
                std::cout << "1.Просмотреть с начала" << std::endl;
                std::cout << "2.Просмотреть с конца" << std::endl;
                std::cout << "0.НАЗАД" << std::endl;
                std::cout << ">>> ";
                std::cin >> choice;
                if (list.getSize() == 0) {
                    system("clear");
                    std::cout << "Список пуст" << std::endl;
                } else {
                    switch (choice) {
                        case 1:
                            system("clear");
                            value.head();
                            list.showFront();
                            break;
                        case 2:
                            system("clear");
                            value.head();
                            list.showBack();
                            break;
                        default:
                            system("clear");
                            break;
                    }
                }
                break;
            case 5:
                if (list.getSize() == 0) {
                    system("clear");
                    cout << "Список пуст" << endl;
                } else {
                    system("cls");
                    value.head();
                    list.showFront();
                    cout << "Введите номер элемента для редактирования: ";
                    cin >> index;
                    list[index]->object.editData();
                    cout << "Редактирование выполнено" << endl;
                }
                break;
            case 6:
                if (list.getSize() == 0) {
                    system("clear");
                    std::cout << "Список пуст" << std::endl;
                } else {
                    std::cout << "Выберите способ сортировки" << std::endl;
                    std::cout << "1.По убыванию" << std::endl;
                    std::cout << "2.По возрастанию" << std::endl;
                    std::cout << ">>> ";
                    std::cin >> choice;
                    switch (choice) {
                        case 1:
                            switch (call) {
                                case 1: {
                                    std::cout << "Сортировать по: " << std::endl;
                                    value.sortingData();
                                    std::cin >> choice;
                                    switch (choice) {
                                        case 1:
                                            list.sort(1, compareID<>);
                                            break;
                                        case 2:
                                            list.sort(1, compareCityName<>);
                                            break;
                                        case 3:
                                            list.sort(1, compareStreetName<>);
                                            break;
                                        case 4:
                                            list.sort(1, compareHouseNumber<>);
                                            break;
                                        case 5:
                                            list.sort(1, compareApartmentNumber<>);
                                            break;
                                        case 6:
                                            list.sort(1, comparePhoneNumber<>);
                                            break;
                                        case 7:
                                            list.sort(1, compareName<>);
                                            break;
                                        case 8:
                                            list.sort(1, compareSurname<>);
                                            break;
                                        case 9:
                                            list.sort(1, compareNationality<>);
                                            break;
                                        default:
                                            //return;
                                            break;
                                    }
                                }
                                case 2: {
                                    std::cout << "Сортировать по: " << std::endl;
                                    value.sortingData();
                                    std::cin >> choice;
                                    switch (choice) {
                                        case 1:
                                            list.sort(1, compareID<>);
                                            break;
                                        case 2:
                                            list.sort(1, compareCityName<>);
                                            break;
                                        case 3:
                                            list.sort(1, compareStreetName<>);
                                            break;
                                        case 4:
                                            list.sort(1, compareHouseNumber<>);
                                            break;
                                        case 5:
                                            list.sort(1, compareApartmentNumber<>);
                                            break;
                                        case 6:
                                            list.sort(1, comparePhoneNumber<>);
                                            break;
                                        case 7:
                                            list.sort(1, compareCompanyName<>);
                                            break;
                                        case 8:
                                            list.sort(1, compareFax<>);
                                            break;
                                        default:
                                            break;
                                    }
                                }
                            }
                            break;
                        case 2:
                            switch (call) {
                                case 1: {
                                    std::cout << "Сортировать по: " << std::endl;
                                    value.sortingData();
                                    std::cin >> choice;
                                    switch (choice) {
                                        case 1:
                                            list.sort(1, compareID<>);
                                            break;
                                        case 2:
                                            list.sort(1, compareCityName<>);
                                            break;
                                        case 3:
                                            list.sort(1, compareStreetName<>);
                                            break;
                                        case 4:
                                            list.sort(1, compareHouseNumber<>);
                                            break;
                                        case 5:
                                            list.sort(1, compareApartmentNumber<>);
                                            break;
                                        case 6:
                                            list.sort(1, comparePhoneNumber<>);
                                            break;
                                        case 7:
                                            list.sort(1, compareName<>);
                                            break;
                                        case 8:
                                            list.sort(1, compareSurname<>);
                                            break;
                                        case 9:
                                            list.sort(1, compareNationality<>);
                                            break;
                                        default:
                                            break;
                                    }
                                }
                                case 2: {
                                    std::cout << "Сортировать по: " << std::endl;
                                    value.sortingData();
                                    std::cin >> choice;
                                    switch (choice) {
                                        case 1:
                                            list.sort(1, compareID<>);
                                            break;
                                        case 2:
                                            list.sort(1, compareCityName<>);
                                            break;
                                        case 3:
                                            list.sort(1, compareStreetName<>);
                                            break;
                                        case 4:
                                            list.sort(1, compareHouseNumber<>);
                                            break;
                                        case 5:
                                            list.sort(1, compareApartmentNumber<>);
                                            break;
                                        case 6:
                                            list.sort(1, comparePhoneNumber<>);
                                            break;
                                        case 7:
                                            list.sort(1, compareCompanyName<>);
                                            break;
                                        case 8:
                                            list.sort(1, compareFax<>);
                                            break;
                                        default:
                                            break;
                                    }
                                }
                            }

                    }

                }
            case 7:
                list.writeFile(file);
                system("clear");
                break;
            case 0:
                system("clear");
                temp = false;
            default:
                system("clear");
                break;


        }
    }
}

template<class T>
Interface<T>::~Interface() = default;

