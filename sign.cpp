#include<iostream>
using namespace std;

void signup();
void topHeader();
void signInterface();
bool signin();


string names[10] = {"Noman" , "Ali"};
string passwords[10] = {"1234" , "123"};
string roles[10] = {"Manager" , "Customer"};

main()
{

    system("cls");
    int mchoice = 4;
    int cchoice = 4;
    topHeader();
            if(mchoice == 1)
            {
            }
            else if(mchoice == 2)
            {
                
            }
            if(mchoice == 3)
            {
                
            }

            
        }
        else if(choice == 2)
        {
            signin();
            if(cchoice == 1)
            {
                
            }
        }
    
    }
    

}


void signInterface()
{

    cout << "1-       Signup" << endl ;
    cout << "2-       Signin" << endl; 
    cout << "3-       Exit" << endl;

}

void signup()
{
    string name,password,yrrole;
    cout << "Enter your name : ";
    cin >> name;
    cout << "Enter password : ";
    cin >> password;
    cout << "Enter your role : ";
    cin >> yrrole;
    for(int i=0;i<10;i++)
    {
        if(names[i]=="")
        {
            names[i]=name;
            passwords[i] = password;
            roles[i]= yrrole;
            break;
        }
    }
}
bool signin()
{
    bool flag = 0;
    string name,password,yrrole;
        cout << "Enter your name : ";
        cin >> name;
        cout << "Enter password : ";
        cin >> password;
    for(int i=0;i<10;i++)
    {
        if(names[i]==name && passwords[i] == password)
        {
            cout << roles[i];
            flag = 1;
        }
    }
    return flag;
}

void topHeader()
{
    cout << "##########################################" << endl;
    cout << "####                                  ####" << endl;
    cout << "####    RESTAURANT MANAGMENT SYSTEM   ####" << endl;
    cout << "####                                  ####" << endl;
    cout << "##########################################" << endl;
}