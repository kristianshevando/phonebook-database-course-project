//
// Created by kristianshevando on 12/19/17.
//

#include "LegalPerson.h"


LegalPerson::LegalPerson() : Person(){
    companyName_ = "";
}

LegalPerson::LegalPerson(const LegalPerson &legalPerson) : Person(legalPerson) {
    this->companyName_ = legalPerson.companyName_;
}

LegalPerson::LegalPerson(int id, std::string cityName, std::string streetName,
                             int houseNumber, int apartmentNumber, int phoneNumber, std::string companyName) :
        Person(id, cityName, streetName, houseNumber, apartmentNumber, phoneNumber)
{
    companyName_ = companyName;
}

void LegalPerson::setData() {
    Person::setData();
    std::cin.ignore();
    std::cout << "Название компании: ";
    getline(std::cin, companyName_);
}

void LegalPerson::head() {
    Person::head();
    std::cout << std::setw(15) << "Company" <<  "|";
}

void LegalPerson::showData() {
    Person::showData();
    std::cout << std::setw(15) << companyName_ << "|";
}

void LegalPerson::editMode() {
    Person::editMode();
    std::cout << "7.Изменить название компании"     << std::endl;
}

void LegalPerson::sortingData() {
    Person::sortingData();
    std::cout << "7.Сортировать по названию компании"   << std::endl;
}

std::istream &operator>>(std::istream &input, LegalPerson &legalPerson){

    input >> dynamic_cast<Person&>(legalPerson);
    std::cout << "Название компании: ";
    getline(input, legalPerson.companyName_);
    return input;
}

std::ostream &operator<<(std::ostream &output, LegalPerson &legalPerson) {
    output << dynamic_cast<Person&>(legalPerson);
    output << std::setw(15) << legalPerson.companyName_ << "|";
    return output;
}

std::ifstream &operator>>(std::ifstream &fin, LegalPerson &legalPerson){
    fin >> dynamic_cast<Person&>(legalPerson);
    fin >> legalPerson.companyName_;
    return fin;
}

std::ofstream &operator<<(std::ofstream &fout, LegalPerson &legalPerson) {
    fout << dynamic_cast<Person&>(legalPerson);
    fout << legalPerson.companyName_ << " ";
    return fout;
}

LegalPerson LegalPerson::operator=(const LegalPerson &legalPerson) {
    Person::operator=(legalPerson);
    this->companyName_ = legalPerson.companyName_;
    return *this;
}

bool LegalPerson::operator==(const LegalPerson &legalPerson) {
    bool temp = Person::operator==(legalPerson);
    if (legalPerson.companyName_ != "") {
        if (this->companyName_ == legalPerson.companyName_) {
            temp = true;
        }
        else {
            return false;
        }
    }
    return temp;
}

void LegalPerson::setCompanyname() {
    std::cout << "Название компании: ";
    getline(std::cin, companyName_);
}

std::string LegalPerson::getCompanyName() {
    return companyName_;
}

LegalPerson::~LegalPerson() {
}

bool compareCompanyName(const LegalPerson *object1, const LegalPerson *object2, int temp) {
    switch (temp)
    {
        case 1:
            return object1->companyName_ < object2->companyName_;
            break;
        case 2:
            return object1->companyName_ > object2->companyName_;
            break;
    }
    return false;
}


