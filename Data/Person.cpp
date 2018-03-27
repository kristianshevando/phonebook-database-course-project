//
// Created by kristianshevando on 12/19/17.
//

#include "Person.h"


Person::Person(const Person &person) {
    this->ID_              = person.ID_;
    this->cityName_        = person.cityName_;
    this->streetName_      = person.streetName_;
    this->houseNumber_     = person.houseNumber_;
    this->apartmentNumber_ = person.apartmentNumber_;
    this->phoneNumber_     = person.phoneNumber_;
}

void Person::setData() {
    cout << "ID: ";
    ID_ = protect.protect();
    cout << "Город: ";
    cin >> cityName_;
    cout << "Улица: ";
    cin >> streetName_;
    cout << "Дом: ";
    houseNumber_ = protect.protect();
    cout << "Квартира: ";
    apartmentNumber_ = protect.protect();
    cout << "Номер телефона: ";
    phoneNumber_ = protect.protect();

}

void Person::head() {
    cout << "|" << left << setw(6) << "ID" << "|" << setw(10)
              << "City" << "|" << setw(10) << "Street" << "|" << setw(5)
              << "House" << "|" << setw(8) << "Apart" << "|" << setw(10) << "Phone" << "|";
}

void Person::showData() {
    cout << "|" << left << setw(6) << ID_ << "|" << setw(10)
              << cityName_ << "|" << setw(10) << streetName_ << "|" << setw(5)
              << houseNumber_ << "|" << setw(8) << apartmentNumber_ << "|" << setw(10) << phoneNumber_ << "|";
}

void Person::editMode() {
    std::cout << "1.Изменить ID"              << std::endl;
    std::cout << "2.Изменить название города" << std::endl;
    std::cout << "3.Изменить название улицы"  << std::endl;
    std::cout << "4.Изменить номер дома"      << std::endl;
    std::cout << "5.Изменить номер квартиры"  << std::endl;
    std::cout << "6.Изменить номер телефона"  << std::endl;
}

void Person::sortingData() {
    std::cout << "1.Сортировать по ID"              << std::endl;
    std::cout << "2.Сортировать по названию города" << std::endl;
    std::cout << "3.Сортировать по названию улицы"  << std::endl;
    std::cout << "4.Сортировать по номеру дома"     << std::endl;
    std::cout << "5.Сортировать по номеру квартиры" << std::endl;
    std::cout << "6.Сортировать по номеру телефона" << std::endl;
}

istream &operator>>(istream & input, Person & person) {
    cout << "ID: ";
    input >> person.ID_;
    cout << "Город: ";
    input >> person.cityName_;
    cout << "Улица: ";
    input >> person.streetName_;
    cout << "Дом: ";
    input >> person.houseNumber_;
    cout << "Квартира: ";
    input >> person.apartmentNumber_;
    cout << "Телефон: ";
    input >> person.phoneNumber_;

    return input;
}

ostream &operator<<(ostream & output, Person & person) {
              output << "|" << left << setw(6) << person.ID_ << "|" << setw(10)
              << person.cityName_ << "|" << setw(10) << person.streetName_ << "|" << setw(5)
              << person.houseNumber_ << "|" << setw(8) << person.apartmentNumber_ << "|"
              << setw(10) << person.phoneNumber_ << "|";
    return output;
}

ifstream &operator>>(ifstream & fin, Person & person) {
    fin >> person.ID_;
    fin >> person.cityName_;
    fin >> person.streetName_;
    fin >> person.houseNumber_;
    fin >> person.apartmentNumber_;
    fin >> person.phoneNumber_;
    return fin;
}

ofstream &operator<<(ofstream & fout, Person & person) {
    fout << person.ID_ << " " << person.cityName_ << " " << person.streetName_ << " "
         << person.houseNumber_ << " " << person.apartmentNumber_ << " " << person.phoneNumber_ << " ";
    return fout;
}


Person Person::operator=(const Person & person) {
    this->ID_              = person.ID_;
    this->cityName_        = person.cityName_;
    this->streetName_      = person.streetName_;
    this->houseNumber_     = person.houseNumber_;
    this->apartmentNumber_ = person.apartmentNumber_;
    this->phoneNumber_     = person.phoneNumber_;
    return *this;
}

bool Person::operator==(const Person & person) {
    bool temp = true;
    if (person.ID_ != 0) {
        if (this->ID_ == person.ID_) {
            temp = true;
        }
        else {
            return false;
        }
    }
    if (person.cityName_ != "") {
        if (this->cityName_ == person.cityName_) {
            temp = true;
        }
        else {
            return false;
        }
    }
    if (person.streetName_ != "") {
        if (this->streetName_ == person.streetName_) {
            temp = true;
        }
        else {
            return false;
        }
    }
    if (person.houseNumber_ != 0) {
        if (this->houseNumber_ == person.houseNumber_) {
            temp = true;
        }
        else {
            return false;
        }
    }
    if (person.apartmentNumber_ != 0) {
        if (this->apartmentNumber_ == person.apartmentNumber_) {
            temp = true;
        }
        else {
            return false;
        }
    }
    if (person.phoneNumber_ != 0) {
        if (this->phoneNumber_ == person.phoneNumber_) {
            temp = true;
        }
        else {
            return false;
        }
    }
    return temp;
}

void Person::setID() {
    std::cout << "ID: ";
    std::cin >> ID_;
}

void Person::setCityName() {
    std::cout << "Город: ";
    std::cin >> cityName_;
}

void Person::setStreetName() {
    std::cout << "Улица: ";
    std::cin >> streetName_;
}

void Person::setHouseNumber() {
    std::cout << "Дом: ";
    std::cin >> houseNumber_;
}

void Person::setApartmentNumber() {
    std::cout << "Квартира: ";
    std::cin >> apartmentNumber_;
}

void Person::setPhoneNumber() {
    std::cout << "Номер телефона: ";
    std::cin >> phoneNumber_;
}

int Person::getID() {
    return ID_;
}

string Person::getCityName() {
    return cityName_;
}

string Person::getStreetName() {
    return streetName_;
}

int Person::getHouseNumber() {
    return houseNumber_;
}

int Person::getApartmentNumber() {
    return apartmentNumber_;
}

int Person::getPhoneNumber() {
    return phoneNumber_;
}

bool compareID(const Person *object1, const Person *object2, int temp) {
    switch (temp)
    {
        case 1:
            return object1->ID_ < object2->ID_;
            break;
        case 2:
            return object1->ID_ > object2->ID_;
            break;
    }
    return false;
}

bool compareCityName(const Person *object1, const Person *object2, int temp) {
    switch (temp)
    {
        case 1:
            return object1->cityName_ < object2->cityName_;
            break;
        case 2:
            return object1->cityName_ > object2->cityName_;
            break;
    }
    return false;
}

bool compareStreetName(const Person *object1, const Person *object2, int temp) {
    switch (temp)
    {
        case 1:
            return object1->streetName_ < object2->streetName_;
            break;
        case 2:
            return object1->streetName_ > object2->streetName_;
            break;
    }
    return false;
}

bool compareHouseNumber(const Person *object1, const Person *object2, int temp) {
    switch (temp)
    {
        case 1:
            return object1->houseNumber_ < object2->houseNumber_;
            break;
        case 2:
            return object1->houseNumber_ > object2->houseNumber_;
            break;
    }
    return false;
}

bool compareApartmentNumber(const Person *object1, const Person *object2, int temp) {
    switch (temp)
    {
        case 1:
            return object1->apartmentNumber_ < object2->apartmentNumber_;
            break;
        case 2:
            return object1->apartmentNumber_ > object2->apartmentNumber_;
            break;
    }
    return false;
}

bool comparePhoneNumber(const Person *object1, const Person *object2, int temp) {
    switch (temp)
    {
        case 1:
            return object1->phoneNumber_ < object2->phoneNumber_;
            break;
        case 2:
            return object1->phoneNumber_ > object2->phoneNumber_;
            break;
    }
    return false;
}



















