#ifndef STORAGE_H
#define STORAGE_H
#include "UserInfo.h"
#include "Crypto.h"
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Storage
{
    public:
        Storage();
        virtual ~Storage();

        //For verifying User Existence
        bool checkEmail(string e);
        bool verifyUserData(string e, string p);

        //For Storing, Retrieving and Deleting User Data
        void storeUserData(UserInfo data);
        UserInfo retrieveUserData(string f);
        void deleteUserData(string f);

        //For Storing, Retrieving and Deleting Status
        void storeUpdates(string s, UserInfo info);
        stack<string> retrieveUpdates(string f);
        void deleteUpdates(UserInfo info);

        //For Storing, Retrieving and Deleting User List
        void addUserToList(UserInfo info);
        void removeUserFromList(string s);
        queue<string> getUserList();

        //For Storing, Retrieving and Deleting Friend List
        void addToFriendList(string f1, string f2);
        vector<string> getFriendList(UserInfo info);
        void removeFromFriendList(UserInfo info, string s);

        //For Storing, Retrieving and Deleting Request List
        void sendFriendRequest(string from, string to);
        vector<string>getFriendRequestList(string e);
        void deleteAllFriendRequest(string e);

        //For Storing and Retrieving Messages
        void sendMessages(string from, string to, string message);
        stack<string> getMessages(UserInfo info, string e);

        //For Retrieving and Deleting Messages Threads
        vector< stack<string> > getMessagesThreads(UserInfo info);
        void deleteMessageThreads(string email, UserInfo info);

    protected:
    private:

};

#endif // STORAGE_H
