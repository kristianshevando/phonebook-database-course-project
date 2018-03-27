//
// Created by kristianshevando on 12/10/17.
//

#include "Session.h"

Session::Session() {
    this->readAccountsDB();
}

void Session::readAccountsDB() {
    std::ifstream fin;
    fin.open(ACCOUNTS);
    if(!fin.is_open()){
        this->createAccountsDB();
        this->createFirstAccount();
        this->readAccountsDB();
    }
    std::string buffer = "";
    while(fin.peek() != EOF){
        getline(fin, buffer);
        this->accounts.push_back(this->parseString(buffer));
    }
    if(this->accounts.size() == 0){
        this->createFirstAccount();
    }
}

Account Session::parseString(std::string buffer) {
    Account account;
    std::string note = "";
    std::vector<std::string> strings;
    for(int i = 0; i < buffer.size(); i++) {
        if(buffer[i] == '\"') {
            i++;
            while(true) {
                note += buffer[i];
                i++;
                if(buffer[i] == '\"') {
                    strings.push_back(note);
                    note = "";
                    break;
                }
            }
        }
    }
    account.setID(stoul(strings[ID]));
    account.setUsername(strings[USERNAME]);
    account.setPassword(strings[PASSWORD]);
    return account;
}

void Session::createAccountsDB() {
    std::ofstream fout;
    fout.open(ACCOUNTS);
    fout.close();
}

void Session::createFirstAccount() {
    std::cout << "Создайте аккаунт" << std::endl;
    this->createAccount();
}

void Session::createAccount() {
    Account account;
    std::string username;
    std::string password;
    std::string confirmPassword;

    std::cin.ignore();

    std::cout << "Имя пользователя: ";
    getline(std::cin, username);
    std::cout << "Пароль: ";
    getline(std::cin, password);
    std::cout << "Повторите пароль: ";
    getline(std::cin, confirmPassword);

    if(this->lookingForAccount(username) > -1) {
        std::cout << "Данное имя пользователя занято.\n";
        std::cout << "Попробуйте придумать другое имя.\n\n";
        this->createAccount();
    }

    if(password == confirmPassword)
    {
        account.setID(this->accounts.size());
        account.setUsername(username);
        account.setPassword(password);
    }
    else {
        std::cout << "Пароли не совпадают" << std::endl;
        this->createAccount();
    }
    this->accounts.push_back(account);
    this->saveAccountsDB();
}

void Session::saveAccountsDB() {
    std::ofstream fout;
    fout.open(ACCOUNTS);
    for(int i = 0; i < this->accounts.size(); i++) {
        fout << "\"" << this->accounts[i].getID()       << "\" ";
        fout << "\"" << this->accounts[i].getUsername() << "\" ";
        fout << "\"" << this->accounts[i].getPassword() << "\"\n";
    }
    fout.close();
}

int Session::lookingForAccount(std::string username) {
    for(int i = 0; i < this->accounts.size(); i++) {
        if(this->accounts[i].getUsername() == username) {
            return i;
        }
    }
    return -1;
}

std::string Session::signIn() {
    std::string username = "";
    std::string password = "";
    bool isSignedIn = true;

    std::cin.ignore();
    std::cout << "Имя пользователя: ";
    getline(std::cin, username);
    if(username == "exit") {
        return "exit";
    }
    std::cout << "Пароль: ";
    getline(std::cin, password);

    for(int i = 0; i < this->accounts.size(); i++) {
        if(this->accounts[i].getUsername() == username) {
            if(this->accounts[i].getPassword() == password) {
                return "success";
            }
            else {
                isSignedIn = false;
            }
        }
        else{
            isSignedIn = false;
        }
    }
    if(!isSignedIn)
    {
        system("clear");
        std::cout << "Неверное имя пользователя или пароль." << std::endl;
        return this->signIn();
    }

}

void Session::showAccounts() {
    TablePrinter tablePrinter(&std::cout);
    this->head(tablePrinter);
    tablePrinter.PrintHeader();
    for(int i = 0; i < this->accounts.size(); i++)
    {
        tablePrinter << this->accounts[i].getID() << this->accounts[i].getUsername();
    }
    tablePrinter.PrintFooter();
}

void Session::head(TablePrinter &tablePrinter) {
    tablePrinter.AddColumn("ID", 4);
    tablePrinter.AddColumn("Username", 20);
}

void Session::changeAccount() {
    Account account;
    int index;
    int choice;
    std::string newUsername;
    std::string newPassword;
    std::string confirmNewPassword;

    std::cout << "Введите номер записи: ";
    std::cin >> index;
    std::cout << "Ваша запись:\n";
    checkAccount(index);
    while(true) {
        std::cin.ignore();
        std::cout << "1.Изменить имя пользователя" << std::endl;
        std::cout << "2.Изменить пароль" << std::endl;
        std::cout << "0.Выйти" << std::endl;
        std::cout << ">>> ";
        std::cin >> choice;
        switch (choice) {
            case CHANGE_USERNAME:
                std::cout << "Новое имя пользователя: ";
                getline(std::cin, newUsername);
                this->accounts[index].setUsername(newUsername);
                break;
            case CHANGE_PASSWORD:
                std::cout << "Новый пароль: ";
                getline(std::cin, newPassword);
                std::cout << "Подтвердите пароль: ";
                getline(std::cin, confirmNewPassword);
                if (newPassword == confirmNewPassword) {
                    this->accounts[index].setPassword(newPassword);
                } else {
                    std::cout << "Пароли не совпадают: ";
                }
                break;
            default:
                break;
        }
        break;
    }

    this->saveAccountsDB();
    std::cout << "Ваша учетная запись после изменения" << std::endl;
    this->checkAccount(index);
}

void Session::showAccount(int i)
{
    TablePrinter tablePrinter(&std::cout);
    this->head(tablePrinter);
    tablePrinter << this->accounts[i].getID()
                 << this->accounts[i].getUsername();
}

void Session::checkAccount(int index)
{
    TablePrinter tablePrinter(&std::cout);
    this->head(tablePrinter);
    tablePrinter.PrintHeader();
    this->showAccount(index);
    tablePrinter.PrintFooter();
}

void Session::deleteAccount() {

}
