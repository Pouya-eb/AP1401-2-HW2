#include "../include/hw2.h"

//********** User **********//

User::User(std::string name, std::string pass, std::string mail)
    : username { name } // Initializing
    , email { mail }
    , password { pass }

{
}

User::~User()
{
}

//********** Login **********//

Login::Login() { }
Login::~Login() { }

void Login::readFile(std::string path)
{
    std::string name, pass, mail, login;
    int cnt { -1 };
    std::ifstream file { "users.txt" };
    if (file.fail())
        std::cout << "There is a problem reading the file" << std::endl;

    std::string line;
    if (file.is_open()) {
        for (;;) {
            cnt++;
            if (!getline(file, line))
                break;
            if (cnt == 0)
                continue;
            std::stringstream tmp(line);
            tmp >> name >> pass >> mail >> login;
            User* usr = new User { name, pass, mail };
            users.push_back(usr);
            if (login == "yes") {
                LoginedUsers.push_back(usr);
            }
        }
    }
}
