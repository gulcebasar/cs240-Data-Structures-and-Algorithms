#include<cstring>
#include<iostream>
#include<cstdlib>
#include<utility>
#include<vector>
#include<cctype>
#include"map.h"

using namespace std;

void addPairToMap( Map& map ); // Function to add a pair to map
void menu( Map& map ); // Function to display menu
void logOn( Map& map ); // Function for log on option
void changePassword( Map& map ); // Function for change password option
bool checkStrenght(string password); // Function to check if the password is strong enough
void loggedOn( Map& map ); // Function for logged on option
void logOff( Map& map ); // Function for log off option

int main()
{
    Map map1; // create a Map to store items
    addPairToMap(map1); // add to the Map 234 key-value pairs
    menu(map1);
    return 0;
}

void addPairToMap( Map& map )
{
    string num[]={"1","2","3","4","5","6","7","8","9"};
    string alphabet[]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
    valueType value("ChangeMe",false); // value is the same for all users
    
    for (int i=0; i<9; i++) // user number
    {
        for (int j=0; j<26; j++) // user number + a...z
            map.addPair( ("user"+num[i]+alphabet[j]), value); // adds the user name and value ( username = usera1 .... userz9
    }
}

void menu( Map& map )
{
    cout << endl << "(1)Log-on   (2)Change Password   (3)Logged-On   (4)Log-Off   (0)Exit" << endl; // display menu
    int option=-1;
    
    do{
        cout << endl << "-Please enter the option number: "; // asks for option
        cin >> option;
        
        if(option == 1) // log on option
            logOn(map);
        
        else if(option == 2) // change password option
            changePassword(map);
        
        else if(option == 3) // logged on option
            loggedOn(map);
        
        else if(option == 4) // log off option
            logOff(map);
        
        else if(option == 0) // exit option
            cout << "-Exiting the menu" << endl;
        
        else // if something else is entered
        {
            cout << "-You entered something wrong please enter again" << endl // error message
                 << "(1)Log-on   (2)Change Password   (3)Logged-On   (4)Log-Off   (0)Exit" << endl; // display menu again
        }
        
    }while(option != 0); // loops until exit is choosen
}

void logOn( Map& map )
{
    string id;
    cout << " Please enter your user id: "; // asks for user id
    cin >> id;
    
    if(map.findPair(id)) // checks if the map has the user id
    {
        valueType *userInfo = map.getValue(id); // gets the user info (value)
        
        string password;
        cout << " Please enter your password: "; // asks for password
        cin >> password;
        
        if( password == userInfo->password ) // if the password is correct
            userInfo->si = true; // changes status to true
            
        else
            cout << "-Wrong password" << endl; // error message for password
    }
    else
    cout << "-Wrong user id" << endl; // error message for user id
}

void changePassword( Map& map )
{
    string id;
    cout << " Please enter your user id: "; // asks for user id
    cin >> id;
    
    if(map.findPair(id)) // checks if the map has the user id
    {
        valueType *userInfo = map.getValue(id); // gets the user info (value)
        
        string password;
        cout << " Please enter your old password: "; // asks for old password
        cin >> password;
        
        if( password == userInfo->password ) // if the password is correct
        {
            string newPassword;
            
            do{
                cout << " Please enter your new password: "; // asks for new password
                cin >> newPassword;
            
                if(!checkStrenght(newPassword)) // if new password is not strong enough
                {
                    cout << "-Password must have at least 6 characters, including at least one lower case and one upper case character" << endl;
                }
            }while(!checkStrenght(newPassword)); // loops untill the password is strong enough
                            
            userInfo->password = newPassword; // sets password to new password
        }
        
        else
            cout << "-Wrong password" << endl; // error message for password
    }
    
    else
        cout << "-Wrong user id" << endl; // error message for user id
}
                   
bool checkStrenght(string password) // function to check passwords strenght
{
    if (password.length() <6) // if passwords lenght is smaller than 6 returns false
        return false;
    
    bool upper=false, lower=false; // upper and lower are false
    
    for(int i=0; i<password.length(); i++) // loop of passwords lenght
    {
        if (isupper(password[i])) // if an uppercase character is found
            upper=true; // changes upper to true
        
        if (islower(password[i])) // if a lowercase character is found
            lower=true; // changes lower to true
    }
            
    if( upper && lower ) // if both upper and lower is true
        return true; // returns true
    
    return false; // if not returns false
}

void loggedOn( Map& map )
{
    string id;
    cout << " Please enter your user id: "; // asks for user id
    cin >> id;
    
    if(map.findPair(id)) // checks if the map has the user id
    {
        valueType *userInfo = map.getValue(id); // gets the user info (value)
        
        if( userInfo->si ) // if status is true
            cout << " * Logged On *" << endl;
        else // if status is false
            cout << " * Not Logged On *" << endl;
    }
    
    else
        cout << "-Wrong user id" << endl; // error message for user id
}

void logOff( Map& map )
{
    string id;
    cout << " Please enter your user id: "; // asks for user id
    cin >> id;
    
    if(map.findPair(id)) // checks if the map has the user id
    {
        valueType *userInfo = map.getValue(id); // gets the user info (value)
        userInfo->si = false; // changes status to false
    }
    
    else
        cout << "-Wrong user id" << endl; // error message for user id
}












