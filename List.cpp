//
// Created by kristianshevando on 12/22/17.
//

#include "List.h"

template<class Type>
List<Type>::List() {
    size = 0;
    begin = NULL;
    end = NULL;
}

template<class Type>
List<Type>::List(const List<Type>& object){}

template<class Type>
List<Type>::~List() {
    Line<Type> * temp = nullptr;
    if (begin != NULL) {
        while (begin != NULL) {
            temp = begin->next;
            delete begin;
            begin = temp;
        }
    }
}

template<class Type>
void List<Type>::pushFront(const Type & object) {
    Line<Type> *temp = new Line<Type>;
    temp->next = NULL;
    Line<Type> *current = nullptr;
    temp->object = object;
    size++;
    if (begin != NULL) {
        temp->previous = end;
        end->next = temp;
        end = temp;
        current = end;
    } else {
        temp->previous = NULL;
        begin = end = temp;
    }
}

template<class Type>
void List<Type>::pushBack(const Type& obj) {
    Line<Type> *current = nullptr;
    Line<Type> *temp = new Line<Type>;
    temp->previous = NULL;
    current = NULL;
    temp->object = obj;
    size++;
    if (begin != NULL) {
        begin->previous = temp;
        temp->next = begin;
        begin = temp;
        current = begin;
    } else {
        temp->next = NULL;
        begin = end = temp;
    }
}
template<class Type>
void List<Type>::showFront() {
    Line<Type> *current = nullptr;
    current = end;
    std::cout << current->object << std::endl;
    while (current->previous != NULL) {
        current = current->previous;
        std::cout << current->object << std::endl;
    }
}
template<class Type>
void List<Type>::showBack() {
    Line<Type> *current = nullptr;
    current = begin;
    std::cout << current->object << std::endl;
    while (current->next != NULL) {
        current = current->next;
        std::cout << current->object << std::endl;
    }
}
template<class Type>
Type List<Type>::remove(Line<Type>* obj) {
    size--;
    Line<Type> *temp, *tempn, data;
    if (obj == begin && obj != end) {
        tempn = obj->next;
        tempn->previous = NULL;
        begin = tempn;
        data.object = obj->object;
        delete obj;
        return data.object;
    } 
    else if (obj == end && obj != begin) {
        temp = obj->previous;
        temp->next = obj->next;
        end = temp;
        data.object = obj->object;
        delete obj;
        return data.object;
    }
    else if (obj == end && obj == begin)
    {
        temp = obj;
        data.object = obj->object;
        delete end;
        end = begin = NULL;
        return data.object;
    } else {
        temp = obj->previous;
        tempn = obj->next;
        temp->next = tempn;
        tempn->previous = temp;
        data.object = obj->object;
        delete obj;
        return data.object;
    }
}

template<class Type>
Type List<Type>::removeFront() {
    if (end == begin) {
        size--;
        Line<Type> data;
        data.object = end->object;
        delete end;
        end = begin = NULL;
        return data.object;
    } else {
        Line<Type> *current = nullptr;
        size--;
        Line<Type> data;
        current = end->previous;
        current->next = NULL;
        data.object = end->object;
        delete end;
        end = current;
        return data.object;
    }
}

template<class Type>
Type List<Type>::removeBack() {
    if (end == begin) {
        size--;
        Line<Type> data;
        data.object = end->object;
        delete end;
        end = begin = NULL;
        return data.object;
    } else {
        Line<Type> *current = nullptr;
        Line<Type> data;
        size--;
        current = begin->next;
        current->previous = NULL;
        data.object = end->object;
        delete begin;
        begin = current;
        return data.object;
    }
}

template<class Type>
bool List<Type>::isEmpty() {
    if (begin != NULL) {
        return true;
    } else {
        return false;
    }
}

template<class Type>
void List<Type>::searchByID(int idKey) {
    int index = 0;
    Line<Type> *current = nullptr;
    current = end->previous;
    while (current != NULL) {
        if (current->object.getID() == idKey) {
            index++;
            if (index == 1) {
                current->object.head();
                std::cout << current->object << std::endl;
                break;
            }
        }

        if (current->previous != NULL) {
            current = current->previous;
        }

        if (index == 0) {
            std::cout << "Не найдено" << std::endl;
            break;
        }
    }

}
template<class Type>
void List<Type>::searchByStreetAndHouseNumber(std::string streetKey, int houseNumberKey) {
    int index = 0;
    Line<Type> *current = nullptr;
    current = end;
    while (current != NULL) {
        if (current->object.getStreetName() == streetKey && current->object.getHouseNumber() == houseNumberKey) {
            index++;
            if (index > 0) {
                current->object.head();
                std::cout << current->object << std::endl;
                break;
            }
        }

        if (current->previous != NULL) {
            current = current->previous;
        }

        if (index == 0) {
            std::cout << "Не найдено" << std::endl;
            break;
        }
    }

}

template<class Type>
void List<Type>::searchByPhoneNumber(int phoneNumber) {
    int index = 0;
    Line<Type> *current = nullptr;
    current = end;
    while (current != NULL) {
        if (current->object.getPhoneNumber() == phoneNumber) {
            index++;
            if (index > 0) {
                current->object.head();
                std::cout << current->object << std::endl;
                break;
            }
        }

        if (current->previous != NULL) {
            current = current->previous;
        }

        if (index == 0) {
            std::cout << "Не найдено" << std::endl;
            break;
        }
    }
}

template<class Type>
Line<Type>* List<Type>::operator[] (int id) {
    Line<Type> *current = nullptr;
    current = end;
    int index = 1;
    while (id != index) {
        if (current->previous != NULL) {
            current = current->previous;
        }
        index++;
    }
    return current;
}

template<class Type>
void List<Type>::readFile(std::string file) {
    std::ifstream fin(file, std::ios::in);
    Type temp;
    while (fin >> temp) {
        this->pushBack(temp);
    }

    fin.close();
}

template<class Type>
void List<Type>::writeFile(std::string file) {
    std::ofstream fout(file, std::ios::trunc);
    Line<Type> *current = begin;
    while (current != NULL) {
        fout << current->object;
        current = current->next;
    }
    fout.close();
}

template<class Type>
void List<Type>::sort(int trigger, bool(*Compare)(Type*, Type*,int) ) {
    Line<Type> *current = end;
    Line<Type> *temp = nullptr;
    for (current; current != NULL; current = current->previous) {
        for (temp = end; temp != NULL; temp = temp->previous) {
            if (Compare(&current->object,&temp->object,trigger)) {
                std::swap(current->object, temp->object);
            }
        }
    }
}

template<class Type>
void List<Type>::removeAll() {
    Line<Type> * tmp = nullptr;
    if (begin != NULL) {
        while (begin != NULL) {
            tmp = begin->next;
            delete begin;
            begin = tmp;
        }
    }
}

template<class Type>
int List<Type>::getSize() {
    return this->size;
}