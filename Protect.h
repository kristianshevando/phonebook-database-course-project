//
// Created by kristianshevando on 12/10/17.
//

#ifndef PHONEBOOK_PROTECT_H
#define PHONEBOOK_PROTECT_H

#include <iostream>

class Protect {
private:
    int normal_;   //возвращвемое значение
    std::string buffer_; //принимаемое значение
public:
    int protect();  //Метод, реализующий защиту от некорректного ввода
};



#endif //PHONEBOOK_PROTECT_H
