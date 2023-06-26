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

bool Login::checkUsername(std::string& new_username)
{
    // iterating whole users, if not exist add it to users
    // exist : true, not exist : false
    for (size_t i {}; i < users.size(); i++) {
        if (users[i]->username == new_username) {
            std::cout << "username already taken" << std::endl;
            return true;
        }
    }
    return false;
}

bool Login::checkEmail(std::string& new_email)
{
    // iterating whole users, if email exists return true else false
    for (size_t i {}; users.size(); i++) {
        if (users[i]->email == new_email)
            return true;
    }
    return false;
}

void Login::changeUsername(std::string username, std::string newUsername)
{
    // finding the current username and replacing it with newUsername
    for (size_t i {}; i < users.size(); i++) {
        if (users[i]->username == username)
            users[i]->username = newUsername;
    }
}

void Login::changePassword(std::string username, std::string newPassword)
{
    // finding the current username and changinf its password
    for (size_t i {}; i < users.size(); i++) {
        if (users[i]->username == username)
            users[i]->password = newPassword;
    }
}

void Login::changeMail(std::string username, std::string newMail)
{
    // finding the current username and changing its email
    for (size_t i {}; i < users.size(); i++) {
        if (users[i]->username == username)
            users[i]->email = newMail;
    }
}
