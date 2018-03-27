//
// Created by kristianshevando on 12/10/17.
//

#ifndef PHONEBOOK_SESSION_H
#define PHONEBOOK_SESSION_H

#include "Account/Account.h"
#include "bprinter-master/include/bprinter/table_printer.h"
#include <vector>
#include <fstream>

using namespace bprinter;

const std::string ACCOUNTS  = "accounts.txt";

const int ID              = 0;
const int USERNAME        = 1;
const int PASSWORD        = 2;

const int CHANGE_USERNAME = 1;
const int CHANGE_PASSWORD = 2;

class Session {
private:
    std::vector<Account> accounts;

    void        readAccountsDB();
    Account     parseString(std::string);
    void        createAccountsDB();
    void        createFirstAccount();
    void        saveAccountsDB();
    int         lookingForAccount(std::string);
    void        head(TablePrinter&);
    void        checkAccount(int);
    void        showAccount(int);
public:
    Session();
    std::string signIn();
    void        createAccount();
    void        changeAccount();
    void        showAccounts();
    void        deleteAccount();
};


#endif //PHONEBOOK_SESSION_H
