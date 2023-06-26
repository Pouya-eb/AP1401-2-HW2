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