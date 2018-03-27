//
// Created by kristianshevando on 12/21/17.
//
//

#ifndef PHONEBOOK_TYPE_H
#define PHONEBOOK_TYPE_H
#include <iostream>
#include <functional>
#include "Human.h"
#include "Company.h"

template<class T>
bool compareID(T *t1, T *t2, int ord) {
    return compareID(dynamic_cast<const Person *>(t1), dynamic_cast<const Person *>(t2), ord);
}

template<class T>
bool compareCityName(T *t1, T *t2, int ord) {
    return compareCityName(dynamic_cast<const Person *>(t1), dynamic_cast<const Person *>(t2), ord);
}

template<class T>
bool compareStreetName(T *t1, T *t2, int ord) {
    return compareStreetName(dynamic_cast<const Person *>(t1), dynamic_cast<const Person *>(t2), ord);
}

template<class T>
bool compareHouseNumber(T *t1, T *t2, int ord) {
    return compareHouseNumber(dynamic_cast<const Person *>(t1), dynamic_cast<const Person *>(t2), ord);
}

template<class T>
bool compareApartmentNumber(T *t1, T *t2, int ord) {
    return compareApartmentNumber(dynamic_cast<const Person *>(t1), dynamic_cast<const Person *>(t2), ord);
}

template<class T>
bool comparePhoneNumber(T *t1, T *t2, int ord) {
    return comparePhoneNumber(dynamic_cast<const Person *>(t1), dynamic_cast<const Person *>(t2), ord);
}

template<class T>
bool compareName(T *t1, T *t2, int ord) {
    return compareName(dynamic_cast<const NaturalPerson *>(t1), dynamic_cast< NaturalPerson *>(t2), ord);
}

template<class T>
bool compareSurname(T *t1, T *t2, int ord) {
    return compareSurname(dynamic_cast<NaturalPerson *>(t1), dynamic_cast< NaturalPerson *>(t2), ord);
}

template<class T>
bool compareCompanyName(T *t1, T *t2, int ord) {
    return compareCompanyName(dynamic_cast< LegalPerson *>(t1), dynamic_cast< LegalPerson *>(t2), ord);
}

template<class T>
bool compareNationality(T *t1, T *t2, int ord) {
    return compareNationality(dynamic_cast< Human *>(t1), dynamic_cast< Human *>(t2), ord);
}

template<class T>
bool compareFax(T *t1, T *t2, int ord) {
    return compareFax(dynamic_cast< Human *>(t1), dynamic_cast< Human *>(t2), ord);
}



#endif //PHONEBOOK_TYPE_H
