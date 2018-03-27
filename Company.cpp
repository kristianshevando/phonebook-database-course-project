//
// Created by kristianshevando on 12/19/17.
//

#include "Company.h"

Company::Company() : LegalPerson(){
    fax_ = 0;
}

Company::Company(const Company &company) : LegalPerson(company) {
    this->fax_ = company.fax_;
}

Company::Company(int id, std::string cityName, std::string streetName,
                         int houseNumber, int apartmentNumber, int phoneNumber, std::string companyName, int fax) :
        LegalPerson(id, cityName, streetName, houseNumber, apartmentNumber, phoneNumber, companyName)
{
    fax_ = fax;
}

void Company::setData() {
    LegalPerson::setData();
    std::cout << "Факс: ";
    std::cin >> fax_;
}

void Company::head() {
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
    LegalPerson::head();
    std::cout << std::setw(10) << "Fax" << "|" << std::endl;
    std::cout << "-----------------------------------------------------------------------------------" << std::endl;
}

void Company::showData() {
    LegalPerson::showData();
    std::cout << std::setw(10) << fax_ << "|";
}

void Company::editMode() {
    LegalPerson::editMode();
    std::cout << "8.Изменить факс" << std::endl;
    std::cout << "0.НАЗАД"         << std::endl;
    std::cout << ">>> ";
}

void Company::editData() {
    int choice;
    Protect protect;
    Company::editMode();
    choice = protect.protect();
    switch(choice)
    {
        case 1:
            std::cout << "Текущее значение: "<< Person::getID() << std::endl;
            Person::setID();
            break;
        case 2:
            std::cout << "Текущее значение: " << Person::getCityName() << std::endl;
            Person::setCityName();
            break;
        case 3:
            std::cout << "Текущее значение: " << Person::getStreetName() << std::endl;
            Person::setStreetName();
            break;
        case 4:
            std::cout << "Текущее значение: " << Person::getHouseNumber() << std::endl;
            Person::setHouseNumber();
            break;
        case 5:
            std::cout << "Текущее значение: " << Person::getApartmentNumber() << std::endl;
            Person::setApartmentNumber();
            break;
        case 6:
            std::cout << "Текущее значение: " << Person::getPhoneNumber() << std::endl;
            Person::setPhoneNumber();
            break;
        case 7:
            std::cout << "Текущее значение: " << LegalPerson::getCompanyName() << std::endl;
            LegalPerson::setCompanyname();
            break;
        case 8:
            std::cout << "Текущее значение: " << Company::getFax() << std::endl;
            Company::setFax();
            break;
        default:
            break;
    }
}

void Company::sortingData() {
    LegalPerson::sortingData();
    std::cout << "8.Сортировать по факсу" << std::endl;
    std::cout << "0.НАЗАД"                << std::endl;
    std::cout << ">>> ";
}

std::istream &operator>>(std::istream &input, Company &company){

    input >> dynamic_cast<LegalPerson&>(company);
    std::cout << "Факс: ";
    input >> company.fax_;
    return input;
}

std::ostream &operator<<(std::ostream &output, Company &company) {
    output << dynamic_cast<LegalPerson&>(company);
    output << std::setw(10) << company.fax_ << "|";
    std::cout << "\n-----------------------------------------------------------------------------------";
    return output;
}

std::ifstream &operator>>(std::ifstream &fin, Company &company){
    fin >> dynamic_cast<LegalPerson&>(company);
    fin >> company.fax_;
    return fin;
}

std::ofstream &operator<<(std::ofstream &fout, Company &company) {
    fout << dynamic_cast<LegalPerson&>(company);
    fout << company.fax_ << "\n";
    return fout;
}

Company Company::operator=(const Company &company) {
    LegalPerson::operator=(company);
    this->fax_ = company.fax_;
    return *this;
}

bool Company::operator==(const Company &company) {
    bool temp = LegalPerson::operator==(company);
    if (company.fax_ != 0) {
        if (this->fax_ == company.fax_) {
            temp = true;
        }
        else {
            return false;
        }
    }
    return temp;
}

void Company::setFax() {
    std::cout << "Факс: ";
    std::cin >> fax_;
}

int Company::getFax() {
    return fax_;
}

Company::~Company() {
}

bool compareFax(const Company *object1, const Company *object2, int temp) {
    switch (temp)
    {
        case 1:
            return object1->fax_ < object2->fax_;
            break;
        case 2:
            return object1->fax_ > object2->fax_;
            break;
    }
    return false;
}




