#include "gtest/gtest.h"
#include "../include/hw2.h"


TEST(APHW2TEST, checkRegistery)
    {
        Login l;
        l.registerUser("rasoul", "123456", "rasoul.kh41@gmail.com");
        l.getUser("rasoul")->password = "124";
        EXPECT_EQ(l.getUser("rasoul")->password, "124");   
        l.changePassword("rasoul", "125");
        EXPECT_EQ(l.getUser("rasoul")->password, "125");   
        EXPECT_EQ(l.getUser("test"), nullptr);      
    }

TEST(APHW2TEST, checkSameMail)
{
    Login l;
    l.registerUser("rasoul", "123456", "rasoul.kh41@gmail.com");
    l.registerUser("rasoul", "123456", "rasoul2.kh41@gmail.com");
    l.registerUser("rasoul2", "123456", "rasoul.kh41@gmail.com");
    l.registerUser("rasoul", "123456", "rasoul.kh41@gmail.com");

    EXPECT_EQ(l.users.size(), 1);
}

TEST(APHW2TEST, checkremove)
{
    Login l;
    l.registerUser("ali", "123456", "ali@gmail.com");
    
    l.registerUser("rasoul", "123456", "rasoul.kh41@gmail.com");
    l.removeUser("rasool");
    EXPECT_EQ(l.users.size(), 1);
    EXPECT_EQ(l.getUser("rasoul"), nullptr);
}

TEST(APHW2TEST, checkLogin)
{
    Login l;
    l.registerUser("rasoul", "123456", "rasoul@gmail.com");
    
    l.loginUser("rasoul", "123456");
    EXPECT_EQ(l.LoginedUsers.size(), 1);
    l.removeUser("rasoul");
    EXPECT_EQ(l.getUser("rasoul"), nullptr);
    EXPECT_EQ(l.users.size(), 0);
    EXPECT_EQ(l.LoginedUsers.size(), 0);
}

TEST(APHW2TEST, checkPointer)
{
    Login l;
    l.registerUser("rasoul", "123456", "rasoul@gmail.com");
    
    l.loginUser("rasoul", "123456");
    l.changeUsername("rasoul", "ali");
    EXPECT_EQ(l.LoginedUsers[0]->username, "ali");
}

