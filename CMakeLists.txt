cmake_minimum_required(VERSION 3.9)
project(phonebook)

set(CMAKE_CXX_STANDARD 17)

add_executable(phonebook main.cpp
        Protect.cpp Protect.h
        Intface.h
        Interface.cpp Interface.h
        Person.cpp Person.h
        NaturalPerson.cpp NaturalPerson.h
        LegalPerson.cpp LegalPerson.h
        Company.cpp Company.h
        Human.cpp Human.h Types.h Types.cpp Header.cpp Header.h List.cpp List.h)