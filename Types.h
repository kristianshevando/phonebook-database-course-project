//
// Created by kristianshevando on 12/20/17.
//

#ifndef PHONEBOOK_TYPES_H
#define PHONEBOOK_TYPES_H

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <fstream>
#include <functional>

template <class T>
bool compare(T * a, T *b, int t);

template<class T>
bool compareID(T *t1, T *t2, int ord);
template<class T>
bool compareCityName(T *t1, T *t2, int ord);
template<class T>
bool compareStreetName(T *t1, T *t2, int ord);
template<class T>
bool compareHouseNumber(T *t1, T *t2, int ord);
template<class T>
bool compareApartmentNumber(T *t1, T *t2, int ord);
template<class T>
bool comparePhoneNumber(T *t1, T *t2, int ord);
template<class T>
bool compareName(T *t1, T *t2, int ord);
template<class T>
bool compareSurname(T *t1, T *t2, int ord);
template<class T>
bool compareCompanyName(T *t1, T *t2, int ord);
template<class T>
bool compareNationality(T *t1, T *t2, int ord);
template<class T>
bool compareFax(T *t1, T *t2, int ord);

#endif //PHONEBOOK_TYPES_H
