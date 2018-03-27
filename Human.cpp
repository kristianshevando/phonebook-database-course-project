//
// Created by kristianshevando on 12/19/17.
//

#include "Human.h"

Human::Human(const Human &human) : NaturalPerson(human) {
    this->nationality_ = human.nationality_;
}

void Human::setData() {
    NaturalPerson::setData();
    std::cout << "Гражданство: ";
    getline(std::cin, nationality_);
}

void Human::head() {
    std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
    NaturalPerson::head();
    std::cout << std::setw(15) << "Nation" << "|" << std::endl;
    std::cout << "--------------------------------------------------------------------------------------------------------" << std::endl;
}

void Human::showData() {
    NaturalPerson::showData();
    std::cout << std::setw(15) << nationality_ << "|";
}

void Human::editData() {
    int choice;
    Protect protect;
    Human::editMode();
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
            std::cout << "Текущее значение: " << NaturalPerson::getName() << std::endl;
            NaturalPerson::setName();
            break;
        case 8:
            std::cout << "Текущее значение: " << NaturalPerson::getSurname() << std::endl;
            NaturalPerson::setSurname();
            break;
        case 9:
            std::cout << "Текущее значение: " << Human::getNationality() << std::endl;
            Human::setNationality();
            break;
        default:
            break;
    }

}

void Human::editMode() {
    NaturalPerson::editMode();
    std::cout << "9.Изменить гражданство" << std::endl;
    std::cout << "0.НАЗАД"                << std::endl;
    std::cout << ">>> ";
}

void Human::sortingData() {
    NaturalPerson::sortingData();
    std::cout << "9.Сортировать по гражданству" << std::endl;
    std::cout << "0.НАЗАД"                      << std::endl;
    std::cout << ">>> ";
}

std::istream &operator>>(std::istream & input, Human & human){

    input >> dynamic_cast<NaturalPerson&>(human);
    std::cout << "Гражданство: ";
    input >> human.nationality_;
    return input;
}

std::ostream & operator<<(std::ostream & output, Human & human) {
    output << dynamic_cast<NaturalPerson&>(human);
    output << std::setw(15) << human.nationality_ << "|";
    std::cout << "\n--------------------------------------------------------------------------------------------------------";
    return output;
}

std::ifstream & operator>>(std::ifstream & fin, Human & human){
    fin >> dynamic_cast<NaturalPerson&>(human);
    fin >> human.nationality_;
    return fin;
}

std::ofstream & operator<<(std::ofstream & fout, Human & human) {
    fout << dynamic_cast<NaturalPerson&>(human);
    fout << human.nationality_ << "\n";
    return fout;
}

Human Human::operator=(const Human & human) {
    NaturalPerson::operator=(human);
    this->nationality_ = human.nationality_;
    return *this;
}

bool Human::operator==(const Human & human) {
    bool temp = NaturalPerson::operator==(human);
    if (human.nationality_ != "") {
        if (this->nationality_ == human.nationality_) {
            temp = true;
        }
        else {
            return false;
        }
    }
    return temp;
}

void Human::setNationality() {
    std::cout << "Гражданство: ";
    getline(std::cin, nationality_);
}

std::string Human::getNationality() {
    return nationality_;
}

Human::~Human() {
}

bool compareNationality(const Human *object1, const Human *object2, int temp) {
    switch (temp)
    {
        case 1:
            return object1->nationality_ < object2->nationality_;
            break;
        case 2:
            return object1->nationality_ > object2->nationality_;
            break;
    }
    return false;
}

Human::Human(int id, std::string cityName, std::string streetName, int houseNumber, int apartmentNumber,
             int phoneNumber, std::string name, std::string surname, std::string nationality) :
        NaturalPerson(id, cityName, streetName, houseNumber,
                      apartmentNumber, phoneNumber, name, surname)
{
    nationality_ = nationality;
}




