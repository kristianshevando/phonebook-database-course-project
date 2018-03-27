//
// Created by kristianshevando on 12/10/17.
//

#include "Protect.h"

int Protect::protect() {
    while(true) {
        try {
            std::cin >> buffer_;
            normal_ = stoi(buffer_);
            break;
        }
        catch (...) {
            std::cout << "Ошибка! Попробуйте еще раз" << std::endl;
            std::cout << ">>> ";
        }
    }
    return normal_;
}