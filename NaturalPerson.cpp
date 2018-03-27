//
// Created by kristianshevando on 12/19/17.
//

#include "NaturalPerson.h"

NaturalPerson::NaturalPerson(){
    name_    = "";
    surname_ = "";
};

NaturalPerson::NaturalPerson(const NaturalPerson & naturalPerson) : Person(naturalPerson) {
    this->name_ = naturalPerson.name_;
    this->surname_ = naturalPerson.surname_;
};

NaturalPerson::NaturalPerson(int id, std::string cityName, std::string streetName,
                             int houseNumber, int apartmentNumber, int phoneNumber, std::string name, std::string surname) :
        Person(id, cityName, streetName, houseNumber, apartmentNumber, phoneNumber)
{
    name_    = name;
    surname_ = surname;
};

void NaturalPerson::setData() {
    Person::setData();
    std::cin.ignore();
    std::cout << "Имя: ";
    getline(std::cin, name_);
    std::cout << "Фамилия: ";
    getline(std::cin, surname_);
}

void NaturalPerson::head() {
    Person::head();
    std::cout << std::setw(15) << "Name" << "|" << std::setw(15) << "Surname" << "|";
}

void NaturalPerson::showData() {
    Person::showData();
    std::cout << std::setw(15) << name_ << "|" << std::setw(15) << surname_ << "|";
}

void NaturalPerson::editMode() {
    Person::editMode();
    std::cout << "7.Изменить имя"     << std::endl;
    std::cout << "8.Изменить фамилию" << std::endl;
}

void NaturalPerson::sortingData() {
    Person::sortingData();
    std::cout << "7.Сортировать по имени"   << std::endl;
    std::cout << "8.Сортировать по фамилии" << std::endl;
}

std::istream & operator>>(std::istream & input, NaturalPerson & naturalPerson) {

    input >> dynamic_cast<Person&>(naturalPerson);
    std::cout << "Имя: ";
    getline(input, naturalPerson.name_);
    std::cout << "Фамилия: ";
    getline(input, naturalPerson.surname_);

    return input;
}

std::ostream & operator<<(std::ostream &output, NaturalPerson & naturalPerson) {
    output << dynamic_cast<Person&>(naturalPerson);
    output << std::setw(15) << naturalPerson.name_ << "|" << std::setw(15) << naturalPerson.surname_ << "|";
    return output;
}

std::ifstream & operator>>(std::ifstream & fin, NaturalPerson & naturalPerson) {
    fin >> dynamic_cast<Person&>(naturalPerson);
    fin >> naturalPerson.name_;
    fin >> naturalPerson.surname_;
    return fin;
}

std::ofstream & operator<<(std::ofstream & fout, NaturalPerson & naturalPerson) {
    fout << dynamic_cast<Person&>(naturalPerson);
    fout << naturalPerson.name_ << " " << naturalPerson.surname_ << " ";
    return fout;
}

NaturalPerson NaturalPerson::operator=(const NaturalPerson & naturalPerson) {
    Person::operator=(naturalPerson);
    this->name_    = naturalPerson.name_;
    this->surname_ = naturalPerson.surname_;
    return *this;
}

bool NaturalPerson::operator==(const NaturalPerson & naturalPerson) {
    bool temp = Person::operator==(naturalPerson);
    if (naturalPerson.name_ != "") {
        if (this->name_ == naturalPerson.name_) {
            temp = true;
        }
        else {
            return false;
        }
    }
    if (naturalPerson.surname_ != "") {
        if (this->surname_ == naturalPerson.surname_) {
            temp = true;
        }
        else {
            return false;
        }
    }
    return temp;
}

void NaturalPerson::setName() {
    std::cout << "Имя: ";
    getline(std::cin, name_);
}

void NaturalPerson::setSurname() {
    std::cout << "Фамилия: ";
    getline(std::cin, surname_);
}

std::string NaturalPerson::getName() {
    return name_;
}

std::string NaturalPerson::getSurname() {
    return surname_;
}

bool compareName(const NaturalPerson *object1, const NaturalPerson *object2, int temp) {
    switch (temp) {
        case 1:
            return object1->name_ < object2->name_;
            break;
        case 2:
            return object1->name_ > object2->name_;
            break;
    }
    return false;
}

bool compareSurname(const NaturalPerson *object1,const NaturalPerson *object2, int temp) {
    switch (temp) {
        case 1:
            return object1->surname_ < object2->surname_;
            break;
        case 2:
            return object1->surname_ > object2->surname_;
            break;
    }
    return false;
}

















