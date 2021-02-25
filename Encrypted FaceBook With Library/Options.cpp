#include "Options.h"
#include "UserInfo.h"
#include "Crypto.h"
#include "Control.h"
#include "Storage.h"
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


// Applies Title in every window after Sign In
void Title2(UserInfo info);

// Home Window
void Home(UserInfo info);

// Profile Window
void Profile(UserInfo info);

// Friend Request Window
void FriendRequest(UserInfo info);

// Message Thread Window
void MessageThreads(UserInfo info);

// Message Window
void Message(UserInfo info, string e);

// Friend List Window
void FriendList(UserInfo info);

// User List Window
void UserList(UserInfo info);

// Primary Navigation Tab between windows
void optionTab(UserInfo info, int x);

// Prints Primary Navigation Tab
void optionTab();

// Profile window Navigation Tab
void profileOptionTab(UserInfo info, int x);

// Friend Request window Navigation Tab
void FriendRequestOptionTab(vector<string> pend, UserInfo info, int x);

// Message Thread window Navigation Tab
void MessageThreadOptionTab(vector< stack<string> > messagethread, UserInfo info, int x);

// Friend List window Navigation Tab
void FriendListOptionTab(vector<string> friends, UserInfo info, int x);

// User List window Navigation Tab
void UserListOptionTab(queue<string> user, UserInfo info, int x);

// Prints Status in Home window
void getUpdate(UserInfo info);

// Stores new Status if needed
void setUpdate(UserInfo info);

Options::Options(UserInfo info)
{
    Home(info);
}

Options::~Options()
{
    //dtor
}

// This function loads the title for all new windows
void Title2(UserInfo info)
{
    for(int i=0 ; i<50 ; i++){
        cout << "\n\n\n\n\n\n\n\n\n\n\n" << "\t\t\t\tLoading";
        for(int j=0 ; j<i ; j++){
            cout << "." ;
        }
        system("CLS");
    }

    cout << "Logged In As : " << info.getName() << endl;
    cout << "\t\t\t\t\t\t" << ">>>>>>> " << "KMHJ SOCIAL" << " <<<<<<<" << endl;
    cout << "\t\t\t\t\t\t\t" << "***********" << endl;

}

void optionTab(UserInfo info, int x)
{
    switch(x){
        case 1:
            {
                Home(info);
            }
            break;
        case 2:
            {
                Profile(info);
            }
            break;
        case 3:
            {
                FriendRequest(info);
            }
            break;
        case 4:
            {
                MessageThreads(info);
            }
            break;
        case 5:
            {
                FriendList(info);
            }
            break;
        case 6:
            {
                UserList(info);
            }
            break;
        case 7:
            {
                Control c;
            }
            break;
        default:
            {
                Home(info);
            }
            break;
    }
}

void profileOptionTab(UserInfo info, int x)
{
    Storage S;
    string q;
    if(strcmpi(info.getGender().c_str(), "male") == 0){
        q = "His";
    }
    else{
        q = "Her";
    }
    switch(x){
        case 21:
            {
                string k;
                getline(cin, k);
                cout << endl << "\t\t\t\t\t" << "Your New Name : ";
                getline(cin, k);
                string a = info.getName() + " >>> Changed " + q + " Name.";
                S.storeUpdates(a,info);
                info.setName(k);
                S.storeUserData(info);
                Profile(info);
            }
            break;
        case 22:
            {
                string k;
                getline(cin, k);
                cout << endl << "\t\t\t\t\t" << "Your New Password : ";
                getline(cin, k);
                info.setPassword(k);
                S.storeUserData(info);
                Profile(info);
            }
            break;
        case 23:
            {
                string k;
                getline(cin, k);
                cout << endl << "\t\t\t\t\t" << "Your Gender : ";
                getline(cin, k);
                string a = info.getName() + " >>> Changed " + q + " Gender.";
                S.storeUpdates(a,info);
                info.setGender(k);
                S.storeUserData(info);
                Profile(info);
            }
            break;
        case 24:
            {
                string k;
                getline(cin, k);
                cout << endl << "\t\t\t\t\t" << "Your Date of Birth : ";
                getline(cin, k);
                string a = info.getName() + " >>> Changed " + q + " Date of Birth.";
                S.storeUpdates(a,info);
                info.setDateOfBirth(k);
                S.storeUserData(info);
                Profile(info);
            }
            break;
        case 25:
            {
                string k;
                getline(cin, k);
                cout << endl << "\t\t\t\t\t" << "Your Phone Number : ";
                getline(cin, k);
                string a = info.getName() + " >>> Changed " + q + " Phone Number.";
                S.storeUpdates(a,info);
                info.setPhoneNumber(k);
                S.storeUserData(info);
                Profile(info);
            }
            break;
        case 26:
            {
                string k;
                getline(cin, k);
                cout << endl << "\t\t\t\t\t" << "Are You Sure You Wish to Deactivate Your Account? (Yes / No) : ";
                getline(cin, k);
                if(strcmpi(k.c_str(), "yes") == 0){
                    string a = info.getName() + " >>> Deactivated " + q + " Account.";
                    S.storeUpdates(a,info);
                    S.removeUserFromList(info.getEmail());
                    S.deleteUserData(info.getEmail());
                    Control c;
                }
                else{
                    Profile(info);
                }
            }
            break;
        default:
            {
                Home(info);
            }
            break;
    }
}

void FriendRequestOptionTab(vector<string> pend, UserInfo info, int x)
{
    Storage S;
    switch(x){
        case 31:
            {
                S.deleteAllFriendRequest(info.getEmail());
                for(int i=0 ; i<pend.size() ; i++){
                    S.addToFriendList(info.getEmail(), pend[i]);
                    UserInfo x = S.retrieveUserData(pend[i]);
                    string a = info.getName() + ">>>" + "I have Become Friends With " + x.getName();
                    string b = x.getName() + ">>>" + "I have Become Friends With " + info.getName();
                    S.storeUpdates(a,info);
                    S.storeUpdates(b,x);
                }
                FriendRequest(info);
            }
            break;
        case 32:
            {
                S.deleteAllFriendRequest(info.getEmail());
                int k;
                cout << endl << "\t\t\t\t" << "Enter SL. No. of the Request to be Accepted : ";
                cin >> k;
                k--;
                if(k < pend.size()){
                    S.addToFriendList(info.getEmail(), pend[k]);
                    UserInfo x = S.retrieveUserData(pend[k]);
                    string a = info.getName() + ">>>" + "I have Become Friends With " + x.getName();
                    string b = x.getName() + ">>>" + "I have Become Friends With " + info.getName();
                    S.storeUpdates(a,info);
                    S.storeUpdates(b,x);

                    pend.erase(pend.begin()+k);
                }
                for(int i=0 ; i<pend.size() ; i++){
                    S.sendFriendRequest(pend[i], info.getEmail());
                }
                FriendRequest(info);
            }
            break;
        case 33:
            {
                S.deleteAllFriendRequest(info.getEmail());
                int k;
                cout << endl << "\t\t\t\t" << "Enter SL. No. of the Request to be Deleted : ";
                cin >> k;
                k--;
                if(k < pend.size()){
                    pend.erase(pend.begin()+k);
                }
                for(int i=0 ; i<pend.size() ; i++){
                    S.sendFriendRequest(pend[i], info.getEmail());
                }
                FriendRequest(info);
            }
            break;
        case 34:
            {
                S.deleteAllFriendRequest(info.getEmail());
                FriendRequest(info);
            }
            break;
        default:
            {
                FriendRequest(info);
            }
            break;
    }
}

void MessageThreadOptionTab(vector< stack<string> > messagethread, UserInfo info, int x)
{
    Storage S;
    switch(x){
        case 41:
            {
                int k;
                cout << endl << "\t\t\t\t" << "Enter SL. No. of the Conversation you wish to see : ";
                cin >> k;
                k--;
                if(k < messagethread.size()){
                    Message(info, messagethread[k].top());
                }
                else{
                    MessageThreads(info);
                }
            }
            break;
        case 42:
            {
                int k;
                cout << endl << "\t\t\t\t" << "Enter SL. No. of the Conversation you wish to Delete : ";
                cin >> k;
                k--;
                if(k < messagethread.size()){
                    S.deleteMessageThreads(messagethread[k].top(), info);
                    MessageThreads(info);
                }
                else{
                    MessageThreads(info);
                }
            }
            break;
        default:
            {
                MessageThreads(info);
            }
            break;
    }
}

void FriendListOptionTab(vector<string> friends, UserInfo info, int x)
{
    Storage S;
    switch(x){
        case 51:
            {
                int k;
                cout << endl << "\t\t\t\t" << "Enter SL. No. of the Friend whose Profile you Wish to Visit : ";
                cin >> k;
                k--;
                if(k < friends.size()){
                    UserInfo u = S.retrieveUserData(friends[k]);
                    Title2(info);
                    cout << "\t\t\t\t\t\t       " << "|Friend List|" << "\n\n\n";
                    cout << "\n\t\t\t\t" << "Profile of " <<  u.getName() << " >>> \n\n";
                    cout << "\t\t\t\t\t\t" << "Name           : " << u.getName() << endl;
                    cout << "\t\t\t\t\t\t" << "Email          : " << u.getEmail() << endl;
                    cout << "\t\t\t\t\t\t" << "Gender         : " << u.getGender() << endl;
                    cout << "\t\t\t\t\t\t" << "Date of Birth  : " << u.getDateOfBirth() << endl;
                    cout << "\t\t\t\t\t\t" << "Phone Number   : " << u.getPhoneNumber() << endl;
                }
                optionTab();
                int x;
                cout << endl << "\t\t\t\t\t\t\t" << "Choice : ";

                if(!(cin >> x)){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    UserList(info);
                }
                optionTab(info,x);
            }
            break;
        case 52:
            {
                UserInfo u;
                int k;
                cout << endl << "\t\t\t\t" << "Enter SL. No. of the Friend you wish to Message : ";
                cin >> k;
                k--;
                if(k < friends.size()){
                    u  = S.retrieveUserData(friends[k]);
                }
                else{
                    FriendList(info);
                }

                string m = info.getName() + " : ", l;
                getline(cin, l);
                cout << endl << "\t\t\t" << "Message : ";
                getline(cin, l);
                m += l;

                S.sendMessages(info.getEmail(), u.getEmail(), m);
                S.sendMessages(u.getEmail(), info.getEmail(), m);
                FriendList(info);
            }
            break;
        case 53:
            {
                int k;
                cout << endl << "\t\t\t\t" << "Enter SL. No. of the Person you want to Unfriend : ";
                cin >> k;
                k--;
                if(k < friends.size()){
                    UserInfo u = S.retrieveUserData(friends[k]);
                    S.removeFromFriendList(info, friends[k]);
                    S.removeFromFriendList(u, info.getEmail());
                }
                FriendList(info);
            }
            break;
        default:
            {
                FriendList(info);
            }
            break;
    }
}

void UserListOptionTab(queue<string> user, UserInfo info, int x)
{
    Storage S;
    switch(x){
        case 61:
            {
                int k, l=0;
                string to;
                bool f = true;

                cout << endl << "\t\t\t\t\t" << "Enter Number : ";
                cin >> k;
                while(l != k){
                    l++;
                    to = user.front();
                    user.pop();
                }

                vector<string> friends = S.getFriendList(info);
                for(int i=0 ; i<friends.size() ; i++){
                    if(strcmp(friends[i].c_str(),to.c_str()) == 0){
                        f = false;
                    }
                }

                vector<string> requests1 = S.getFriendRequestList(to);
                for(int i=0 ; i<requests1.size() ; i++){
                    if(strcmp(requests1[i].c_str(),info.getEmail().c_str()) == 0){
                        f = false;
                    }
                }

                vector<string> requests2 = S.getFriendRequestList(info.getEmail());
                for(int i=0 ; i<requests2.size() ; i++){
                    if(strcmp(requests2[i].c_str(),to.c_str()) == 0){
                        f = false;
                    }
                }

                if((strcmp(info.getEmail().c_str(),to.c_str()) != 0) && f){
                    S.sendFriendRequest(info.getEmail(),to);
                }
                UserList(info);
            }
            break;
        default:
            {
                UserList(info);
            }
            break;
    }
}

void getUpdate(UserInfo info)
{
    Storage S;
    stack<string> u = S.retrieveUpdates(info.getEmail());

    cout << "\t\t\t" << "Your TimeLine >>> " << "\n\n";

    if(u.empty()){
        cout << "\t\t\t\t\t" << "You Haven't Posted an Update yet...!";
    }

    while(!u.empty()){
        int i=0;
        string line = u.top();
        u.pop();
        int f = line.find_first_of(">>>");
        cout << "\t\t\t\t" << line.substr(0,f) << " >>>"<< endl;
        line = line.substr(f+3);
        while(i < line.length()){
            int m=0;
            cout << "\t\t\t\t\t";
            for(int j=i ; j<i+65 ; j++){
                m++;
                if(!line[j]){
                    m = 65;
                    break;
                }
                if(j > i+50 && line[j] == ' '){
                    break;
                }
                cout << line[j];
            }
            cout << endl;
            i = i + m;
        }
        cout << endl;
    }
}

void setUpdate(UserInfo info)
{
    Storage S;
    string k = info.getName() + ">>>", l;
    getline(cin, l);
    cout << endl << "\t\t\t" << "Your Thoughts for Today : ";
    getline(cin, l);
    k += l;
    S.storeUpdates(k,info);
}

void optionTab()
{
    cout << endl;
    cout << "\t\t\t\t\t\t\t" << "1 . Home" << endl;
    cout << "\t\t\t\t\t\t\t" << "2 . Profile" << endl;
    cout << "\t\t\t\t\t\t\t" << "3 . Friend Requests" << endl;
    cout << "\t\t\t\t\t\t\t" << "4 . Message" << endl;
    cout << "\t\t\t\t\t\t\t" << "5 . Friend List" << endl;
    cout << "\t\t\t\t\t\t\t" << "6 . User List" << endl;
    cout << "\t\t\t\t\t\t\t" << "7 . Logout" << endl;
}

void Home(UserInfo info)
{
    Title2(info);
    cout << "\t\t\t\t\t\t\t" << "|   Home  |" << "\n\n\n";
    Storage S;

    getUpdate(info);
    cout << endl << endl;
    cout << "\t\t\t\t\t\t\t" << "11. Add New Update" << endl;
    cout << "\t\t\t\t\t\t\t" << "12. Delete Update History" << endl;
    optionTab();

    int x;
    cout << endl << "\t\t\t\t\t\t\t" << "Choice : ";

    // A Good way to avoid type mismatch for int and string
    if(!(cin >> x)){
        cin.clear();
        cin.ignore(1000, '\n');
        Home(info);
    }

    if(x == 11){
        setUpdate(info);
        Home(info);
    }
    else if(x == 12){
        S.deleteUpdates(info);
        Home(info);
    }
    else{
        optionTab(info,x);
    }

}

void Profile(UserInfo info)
{
    Title2(info);
    cout << "\t\t\t\t\t\t\t" << "| Profile |" << "\n\n\n";
    cout << "\t\t\t\t\t" << "Your Profile" << " >>> \n\n";
    cout << "\t\t\t\t\t\t" << "Name           : " << info.getName() << endl;
    cout << "\t\t\t\t\t\t" << "Email          : " << info.getEmail() << endl;
    cout << "\t\t\t\t\t\t" << "Gender         : " << info.getGender() << endl;
    cout << "\t\t\t\t\t\t" << "Date of Birth  : " << info.getDateOfBirth() << endl;
    cout << "\t\t\t\t\t\t" << "Phone Number   : " << info.getPhoneNumber() << endl;

    cout << endl << endl;
    cout << "\t\t\t\t\t\t\t" << "21. Change Name" << endl;
    cout << "\t\t\t\t\t\t\t" << "22. Change Password" << endl;
    cout << "\t\t\t\t\t\t\t" << "23. Change Gender" << endl;
    cout << "\t\t\t\t\t\t\t" << "24. Change Date of Birth" << endl;
    cout << "\t\t\t\t\t\t\t" << "25. Change Phone Number" << endl;
    cout << "\t\t\t\t\t\t\t" << "26. Deactivate Account" << endl;
    optionTab();

    int x;
    cout << endl << "\t\t\t\t\t\t\t" << "Choice : ";

    if(!(cin >> x)){
        cin.clear();
        cin.ignore(1000, '\n');
        Profile(info);
    }

    if(x > 20){
        profileOptionTab(info,x);
    }

    else{
        optionTab(info,x);
    }

}

void FriendRequest(UserInfo info)
{
    Title2(info);
    cout << "\t\t\t\t\t\t\t" << "| Pending |" << "\n\n\n";
    cout << "\t\t\t" << "Pending Friend Requests >>>" << "\n\n";

    Storage S;
    vector<string> pending = S.getFriendRequestList(info.getEmail());

    if(pending.empty()){
        cout << "\t\t\t\t\t\t" << " No Pending Friend Request." << endl;
    }

    for(int i=0 ; i<pending.size() ; i++){
        UserInfo u = S.retrieveUserData(pending[i]);
        cout << "\t\t\t\t\t" << i+1 << " . " << u.getName() << " Has Sent you a Friend Request." << endl;
    }

    cout << endl << endl;
    cout << "\t\t\t\t\t\t\t" << "31. Accept All Requests" << endl;
    cout << "\t\t\t\t\t\t\t" << "32. Accept One Request" << endl;
    cout << "\t\t\t\t\t\t\t" << "33. Reject All Requests" << endl;
    cout << "\t\t\t\t\t\t\t" << "34. Reject One Request" << endl;
    optionTab();

    int x;
    cout << endl << "\t\t\t\t\t\t\t" << "Choice : ";

    if(!(cin >> x)){
        cin.clear();
        cin.ignore(1000, '\n');
        Profile(info);
    }

    if(x > 30){
        FriendRequestOptionTab(pending,info,x);
    }

    else{
        optionTab(info,x);
    }
}

void Message(UserInfo info, string e)
{
    Title2(info);
    Storage S;
    stack<string> message = S.getMessages(info, e);
    UserInfo u = S.retrieveUserData(e);

    cout << "\t\t\t\t\t\t\t" << "| Message |" << "\n\n\n";
    cout << "\t\t\t" << "Conversation between You and " << u.getName() << " >>> \n\n";

    while(!message.empty()){
        int i=0;
        string line = message.top();
        message.pop();
        int f = line.find_first_of(":");
        cout << "\t\t\t\t" << line.substr(0,f) << " :"<< endl;
        line = line.substr(f+1);
        while(i < line.length()){
            int m=0;
            cout << "\t\t\t\t\t";
            for(int j=i ; j<i+65 ; j++){
                m++;
                if(!line[j]){
                    m = 65;
                    break;
                }
                if(j > i+50 && line[j] == ' '){
                    break;
                }
                cout << line[j];
            }
            cout << endl;
            i = i + m;
        }
        cout << endl;
    }

    cout << endl << endl;
    cout << "\t\t\t\t\t\t\t" << "71. Reply to this Message Thread" << endl;
    cout << "\t\t\t\t\t\t\t" << "72. Return to Messages" << endl;

    int x;
    cout << endl << "\t\t\t\t\t\t\t" << "Choice : ";

    if(!(cin >> x)){
        cin.clear();
        cin.ignore(1000, '\n');
        MessageThreads(info);
    }

    if(x == 71){
        string m = info.getName() + " : ", l;
        getline(cin, l);
        cout << endl << "\t\t\t" << "Message : ";
        getline(cin, l);
        m += l;

        S.sendMessages(info.getEmail(), u.getEmail(), m);
        S.sendMessages(u.getEmail(), info.getEmail(), m);
        Message(info, e);
    }
    else if(x == 72){
        MessageThreads(info);
    }
    else{
        MessageThreads(info);
    }
}

void MessageThreads(UserInfo info)
{
    Title2(info);
    cout << "\t\t\t\t\t\t\t" << "| Message |" << "\n\n\n";
    cout << "\t\t\t" << "List of Message Threads" << " >>> \n\n";

    Storage S;
    vector< stack<string> > messageThreads = S.getMessagesThreads(info);

    if(messageThreads.empty()){
        cout << "\t\t\t\t\t\t" << "No Message Threads to show ..!" << endl;
    }

    else{
        for(int j=0 ; j<messageThreads.size() ; j++){
            stack<string> message = messageThreads[j];
            UserInfo u = S.retrieveUserData(message.top());
            message.pop();
            cout << "\t\t\t\t\t" << j+1 << " . " << u.getName() << " >> " << endl;
            if(message.top().length() > 40){
                cout << "\t\t\t\t\t\t" << message.top().substr(0,40) << " ..." << endl;
            }
            else{
                cout << "\t\t\t\t\t\t" << message.top() << " ..." << endl;
            }
        }
    }

    cout << endl << endl;
    cout << "\t\t\t\t\t\t\t" << "41. View Full Conversation" << endl;
    cout << "\t\t\t\t\t\t\t" << "42. Delete Message Thread" << endl;
    optionTab();

    int x;
    cout << endl << "\t\t\t\t\t\t\t" << "Choice : ";

    if(!(cin >> x)){
        cin.clear();
        cin.ignore(1000, '\n');
        MessageThreads(info);
    }

    if(x > 40){
        MessageThreadOptionTab(messageThreads, info, x);
    }

    else{
        optionTab(info,x);
    }
}

void FriendList(UserInfo info)
{
    Title2(info);
    cout << "\t\t\t\t\t\t       " << "|Friend List|" << "\n\n\n";
    cout << "\t\t\t" << "List of Your Friends" << " >>> \n\n";

    Storage S;
    vector<string> friends = S.getFriendList(info);

    if(friends.empty()){
        cout << "\t\t\t\t\t" << "You Haven't Made any Friends Yet..!" << endl;
    }

    for(int j=0 ; j<friends.size() ; j++){
        UserInfo u = S.retrieveUserData(friends[j]);
        cout << "\t\t\t\t\t" << j+1 << " . " << u.getName() << endl;
    }

    cout << endl << endl;
    cout << "\t\t\t\t\t\t\t" << "51. View Friends Profile" << endl;
    cout << "\t\t\t\t\t\t\t" << "52. Message a Friend" << endl;
    cout << "\t\t\t\t\t\t\t" << "53. Unfriend Someone" << endl;
    optionTab();

    int x;
    cout << endl << "\t\t\t\t\t\t\t" << "Choice : ";

    if(!(cin >> x)){
        cin.clear();
        cin.ignore(1000, '\n');
        FriendList(info);
    }

    if(x > 50){
        FriendListOptionTab(friends, info, x);
    }

    else{
        optionTab(info,x);
    }
}

void UserList(UserInfo info)
{
    Title2(info);
    cout << "\t\t\t\t\t\t\t" << "|User List|" << "\n\n\n";
    cout << "\t\t\t" << "List of KMHJ Encrypto Users" << " >>> \n\n";

    Storage S;
    queue<string> user = S.getUserList();
    queue<string> u = user;
    int i=0;

    while(!user.empty()){
        UserInfo u = S.retrieveUserData(user.front());
        i++;
        cout << "\t\t\t\t\t" << i << " . " << u.getName() << endl;
        user.pop();
    }

    cout << endl << endl;
    cout << "\t\t\t\t\t\t\t" << "61. Send Friend Request" << endl;
    optionTab();

    int x;
    cout << endl << "\t\t\t\t\t\t\t" << "Choice : ";

    if(!(cin >> x)){
        cin.clear();
        cin.ignore(1000, '\n');
        UserList(info);
    }

    if(x > 60){
        UserListOptionTab(u,info,x);
    }

    else{
        optionTab(info,x);
    }
}
