#include "Storage.h"
#include "UserInfo.h"
#include "Crypto.h"
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <string.h>
#include <fstream>
using namespace std;

// Global variable declaration
Crypto C;

Storage::Storage()
{

}

Storage::~Storage()
{
    //dtor
}

bool Storage::checkEmail(string e)
{
    e = "Data\\Profiles\\" + C.FileNameEncrypt(e) + ".txt";
    ifstream file(e.c_str());

    if(!file){
        return false;
    }

    else{
        return true;
    }
}

// This Function Verifies User's email and password before letting them
// Sign into their Account
bool Storage::verifyUserData(string e, string p)
{
    string line, pass, f;
    f = "Data\\Profiles\\" + C.FileNameEncrypt(e) + ".txt";
    ifstream file(f.c_str());

    if(!file){
        return false;
    }

    else{
        getline(file,line);
        getline(file,line);
        getline(file,pass);

        if(pass.compare(C.Encrypted(p)) == 0){
            return true;
        }
        else{
            return false;
        }
    }
}

// This Function stores an User's full information into an
// external file after encrypting all the info
void Storage::storeUserData(UserInfo data)
{
    string filename = "Data\\Profiles\\" + C.FileNameEncrypt(data.getEmail()) + ".txt";
    ofstream file(filename.c_str());

    file << C.Encrypted(data.getName()) << endl;
    file << C.Encrypted(data.getEmail()) << endl;
    file << C.Encrypted(data.getPassword()) << endl;
    file << C.Encrypted(data.getGender()) << endl;
    file << C.Encrypted(data.getDateOfBirth()) << endl;
    file << C.Encrypted(data.getPhoneNumber()) << endl;
    file.close();
}

// This Function returns a User's full information after
// reading from an external file and Decrypting them
UserInfo Storage::retrieveUserData(string f)
{
    string name, pass, email, gender, dob, phone;
    f = "Data\\Profiles\\" + C.FileNameEncrypt(f) + ".txt";
    UserInfo info;
    ifstream file(f.c_str());

    getline(file,name);
    getline(file,email);
    getline(file,pass);
    getline(file,gender);
    getline(file,dob);
    getline(file,phone);

    info.setName(C.Decrypted(name));
    info.setEmail(C.Decrypted(email));
    info.setPassword(C.Decrypted(pass));
    info.setGender(C.Decrypted(gender));
    info.setDateOfBirth(C.Decrypted(dob));
    info.setPhoneNumber(C.Decrypted(phone));
    file.close();

    return info;
}

// Delete's the external file containing a User's full information
// this function is called when user deactivates it's account
void Storage::deleteUserData(string f)
{
    f = "Data\\Profiles\\" + C.FileNameEncrypt(f) + ".txt";
    remove(f.c_str());
}

// This Function stores every updates to the end of the external file
void Storage::storeUpdates(string s, UserInfo info)
{
    vector<string> friendlist = getFriendList(info);
    string filename = "Data\\Updates\\" + C.FileNameEncrypt(info.getEmail() + "Updates") + ".txt";
    ofstream file(filename.c_str(), ios::app);
    file << C.Encrypted(s) << endl;
    file.close();

    for(int i=0 ; i<friendlist.size() ; i++){
        UserInfo u = retrieveUserData(friendlist[i]);
        string fname = "Data\\Updates\\" + C.FileNameEncrypt(u.getEmail() + "Updates") + ".txt";
        ofstream file2(fname.c_str(), ios::app);
        file2 << C.Encrypted(s) << endl;
        file2.close();
    }
}

// This Function returns a stack of update's after reading
// them from an external file
stack<string> Storage::retrieveUpdates(string f)
{
    string line, filename = "Data\\Updates\\" + C.FileNameEncrypt(f + "Updates") + ".txt";
    ifstream file(filename.c_str());
    stack<string> update;

    if(!file){
        return update;
    }

    else{
        while(!file.eof()){
            getline(file,line);
            if(line != ""){
                line = C.Decrypted(line);
                update.push(line);
            }
        }
    }
    file.close();
    return update;
}

void Storage::deleteUpdates(UserInfo info)
{
    string filename = "Data\\Updates\\" + C.FileNameEncrypt(info.getEmail() + "Updates") + ".txt";
    remove(filename.c_str());
}

// This Function Adds every User who sign up to an external file called User list
void Storage::addUserToList(UserInfo info)
{
    string line, filename = "Data\\Extras\\" + C.FileNameEncrypt("User List") + ".txt";
    ofstream file(filename.c_str(), ios::app);

    file << C.Encrypted(info.getEmail()) << endl;
    file.close();
}

// This Function returns a queue of User's name after reading
// the names from the external file
queue<string> Storage::getUserList()
{
    string line, filename = "Data\\Extras\\" + C.FileNameEncrypt("User List") + ".txt";
    ifstream file(filename.c_str());
    queue<string> userlist;

    if(!file){
        return userlist;
    }

    else{
        while(!file.eof()){
            getline(file,line);
            if(line != ""){
                line = C.Decrypted(line);
                userlist.push(line);
            }
        }
    }
    file.close();
    return userlist;
}

// This Function reads the names from an external file and inserts
// them into a queue except for the name of the User to be removed
// and recreates the file with remaining names
void Storage::removeUserFromList(string s)
{
    string filename = "Data\\Extras\\" + C.FileNameEncrypt("User List") + ".txt";
    queue<string> userlist = getUserList();
    ofstream file(filename.c_str());

    while(!userlist.empty()){
        if(s.compare(userlist.front()) != 0){
            file << C.Encrypted(userlist.front()) << endl;
        }
        userlist.pop();
    }
    file.close();
}

// This Function Adds an 2 users to each others Friend list which is in an external file
void Storage::addToFriendList(string f1, string f2)
{
    string filename1 = "Data\\Friend Lists\\" + C.FileNameEncrypt("friend" + f1 + "list") + ".txt";
    string filename2 = "Data\\Friend Lists\\" + C.FileNameEncrypt("friend" + f2 + "list") + ".txt";

    ofstream file1(filename1.c_str(), ios::app);
    file1 << C.Encrypted(f2) << endl;
    file1.close();

    ofstream file2(filename2.c_str(), ios::app);
    file2 << C.Encrypted(f1) << endl;
    file2.close();
}

// This Function returns a queue of friends name of an User after
// reading the names from the external file
vector<string> Storage::getFriendList(UserInfo info)
{
    string line, filename = "Data\\Friend Lists\\" + C.FileNameEncrypt("friend" + info.getEmail() + "list") + ".txt";
    ifstream file(filename.c_str());
    vector<string> friendlist;

    if(!file){
        return friendlist;
    }

    else{
        while(!file.eof()){
            getline(file,line);
            if(line != ""){
                line = C.Decrypted(line);
                friendlist.push_back(line);
            }
        }
    }
    file.close();
    return friendlist;
}

// This Function reads the names from an external file and inserts
// them into a queue except for the name of the friend to be removed
// and recreates the file with remaining names
void Storage::removeFromFriendList(UserInfo info, string s)
{
    string filename = "Data\\Friend Lists\\" + C.FileNameEncrypt("friend" + info.getEmail() + "list") + ".txt";
    vector<string> friendlist = getFriendList(info);

    ofstream file(filename.c_str());

    while(!friendlist.empty()){
        if(s.compare(friendlist.back()) != 0){
            file << C.Encrypted(friendlist.back()) << endl;
        }
        friendlist.pop_back();
    }
    file.close();
}

void Storage::sendFriendRequest(string from, string to)
{
    string filename = "Data\\Friend Requests\\" + C.FileNameEncrypt("Friend" + to + "Request") + ".txt";
    ofstream file(filename.c_str(), ios::app);

    file << C.Encrypted(from) << endl;
    file.close();
}

vector<string> Storage::getFriendRequestList(string e)
{
    string line, filename = "Data\\Friend Requests\\" + C.FileNameEncrypt("Friend" + e + "Request") + ".txt";
    ifstream file(filename.c_str());
    vector<string> requestlist;

    if(!file){
        return requestlist;
    }

    else{
        while(!file.eof()){
            getline(file,line);
            if(line != ""){
                line = C.Decrypted(line);
                requestlist.push_back(line);
            }
        }
    }
    file.close();
    return requestlist;
}

void Storage::deleteAllFriendRequest(string e)
{
    e = "Data\\Friend Requests\\" + C.FileNameEncrypt("Friend" + e + "Request") + ".txt";
    remove(e.c_str());
}

void Storage::sendMessages(string from, string to, string message)
{
    string filename = "Data\\Messages\\" + C.FileNameEncrypt("Message" + to + "Threads") + ".txt";
    string line = from + ">>>" + message;
    ofstream file(filename.c_str(), ios::app);

    file << C.Encrypted(line) << endl;
    file.close();
}

stack<string> Storage::getMessages(UserInfo info, string e)
{
    string line, filename = "Data\\Messages\\" + C.FileNameEncrypt("Message" + info.getEmail() + "Threads") + ".txt";
    ifstream file(filename.c_str());
    stack<string> message;

    if(!file){
        return message;
    }
    else{
        while(!file.eof()){
            getline(file,line);
            if(line != ""){
                line = C.Decrypted(line);
                int l = line.find_first_of(">>>");
                string sender = line.substr(0,l);
                if(strcmp(sender.c_str(), e.c_str()) == 0){
                    message.push(line.substr(l+3));
                }
            }
        }
    }
    file.close();
    return message;
}

vector< stack<string> > Storage::getMessagesThreads(UserInfo info)
{
    vector<string> friends = getFriendList(info);
    vector< stack<string> > thread;

    for(int i=0 ; i<friends.size() ; i++){
        stack<string> message = getMessages(info, friends[i]);
        if(!message.empty()){
            message.push(friends[i]);
            thread.push_back(message);
        }
    }

    return thread;
}

void Storage::deleteMessageThreads(string email, UserInfo info)
{
    string line, filename = "Data\\Messages\\" + C.FileNameEncrypt("Message" + info.getEmail() + "Threads") + ".txt";
    ifstream file(filename.c_str());
    vector<string> message;

    if(file){
        while(!file.eof()){
            getline(file,line);
            if(line != ""){
                line = C.Decrypted(line);
                int l = line.find_first_of(">>>");
                string sender = line.substr(0,l);
                if(strcmp(sender.c_str(), email.c_str()) != 0){
                    message.push_back(line);
                }
            }
        }
    }
    file.close();

    if(!message.empty()){
        ofstream file2(filename.c_str());
        for(int i=0 ; i<message.size() ; i++){
            file2 << C.Encrypted(message[i]) << endl;
        }
        file2.close();
    }
}
