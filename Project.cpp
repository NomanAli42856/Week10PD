#include<iostream>
#include<conio.h>
using namespace std;

void topHeader();
void signInterface();
void signup();
string signin();
int mainInterface();

void managerInterface();
void addDish();
void updatePrice();
void deleteDish();
void addDeal();
void updateDeal();
void deleteDeal();
void addColdDrink();
void updateColdDrinkPrice();
void viewComents();

void customerInterface();
void dishesMenu();
void giveOrder();
void viewDeals();
void orderDeal();
void orderColdDrink();
int viewbill();
void feedback();

bool dishvalidation(string dish);

string names[10] = {"Noman" , "Ali"};
string passwords[10] = {"1234" , "123"};
string roles[10] = {"Manager" , "Customer"};

string dishes[10] = { "Burger", "Pizza" , "Shuwarma" , "Biryani" , "Fries" , "Pepsi" , "Coke" , "Sprite","1","2"};
int prices[10] = { 120 , 500 , 120 , 160 , 100 , 130 , 140 , 150, 700,1050}; 
string deals[10] = {"Burger + Fries" , "Pizza + Burger + Coke"};
int dealsPrices[10] = {700,1050};
string comments[10] = {};
string order[10];
int quantities[10] = {0};


main()
{

    system("cls");

    topHeader();
    int choice;
    while(choice !=3)
    {
        signInterface();
        cout << "Enter your choice : ";
        cin >> choice;
        
        if(choice == 1)
        {
            cout << "     Signup Menu" << endl << "-----------------------"<< endl;
            signup();
        }
        else if(choice == 2)
        {

            cout << "     Signin Menu" << endl << "-----------------------"<< endl;
            string role = signin();
            if(role == "Manager")
            {
                int mchoice = 0;
                while(mchoice != 11)
                {
                    managerInterface();
                    cout << "Enter your choice : ";
                    cin >> mchoice;
                    if(mchoice == 1)
                    {
                        addDish();
                    }
                    else if(mchoice == 2)
                    {
                        deleteDish();
                    }
                    else if(mchoice == 3)
                    {
                        updatePrice();
                    }
                    else if(mchoice == 4)
                    {
                        addDeal();
                    }
                    else if(mchoice == 5)
                    {
                        updateDeal();
                    }
                    else if(mchoice == 6)
                    {
                        deleteDeal();
                        
                    }
                    else if(mchoice == 7)
                    {
                        addColdDrink();
                    }
                    else if(mchoice == 8)
                    {
                        updateColdDrinkPrice();
                    }
                    else if(mchoice == 9)
                    {
                        viewComents();
                        cout << "Enter any key to go back >> ";
                        getch();
                        
                        
                    }
                    else if(mchoice == 10)
                    {
                        cout << "The bill of current customer : " <<  viewbill() << endl;
                        cout << "Enter any key to go back >> ";
                        getch();
                        
                    }
                    
                }
            }
            else if(role == "Customer")
            {
                int cchoice = 0;
                while(cchoice != 8)
                {
                    customerInterface();
                    cout << "Enter your choice : ";
                    cin >> cchoice;
                    if(cchoice == 1)
                    {
                        dishesMenu();
                        cout << "Enter any key to go back >> ";
                        getch();
                    }
                    else if(cchoice == 2)
                    {
                        giveOrder();
                    }
                    else if(cchoice == 3)
                    {
                        viewDeals();
                        cout << "Enter any key to go back >> ";
                        getch();
                    }
                    else if(cchoice == 4)
                    {       
                        orderDeal();
                    }
                    else if(cchoice == 5)
                    {
                        orderColdDrink();  
                    }
                    else if(cchoice == 6)
                    {               
                        cout << "Your bill is : " <<  viewbill() << endl;
                        cout << "Enter any key to go back >> ";
                        getch();
                    }
                    else if(cchoice == 7)
                    {
                        feedback();
                    }
                }
            }
            else
            {
                cout << "You have entered wrong username or password!" << endl;
            }
        }
    }
    
    

}


void topHeader()
{
    cout << "##########################################" << endl;
    cout << "####                                  ####" << endl;
    cout << "####    RESTAURANT MANAGMENT SYSTEM   ####" << endl;
    cout << "####                                  ####" << endl;
    cout << "##########################################" << endl;
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
string signin()
{
    string role;
    string name,password,yrrole;
        cout << "Enter your name : ";
        cin >> name;
        cout << "Enter password : ";
        cin >> password;
    for(int i=0;i<10;i++)
    {
        if(names[i]==name && passwords[i] == password)
        {
            role = roles[i];
        }
    }
    return role;
}

int mainInterface()
{
    int choice;
    cout << "1-       Manager" << endl ;
    cout << "2-       Customer" << endl; 
    cout << "3-       Exit" << endl;
    cout << "ENTER YOUR CHOICE : ";
    cin >> choice;
    return choice;
}

void managerInterface()
{
    system("cls");
    topHeader();
    cout << "   Manager Interface  " << endl << "-----------------------"<< endl;
    cout << "1-       Add new dish" << endl ;
    cout << "2-       Delete dish" << endl; 
    cout << "3-       Update price" << endl;
    cout << "4-       Add deal" << endl ;
    cout << "5-       Update deal" << endl; 
    cout << "6-       Delete deal" << endl;
    cout << "7-       Add cold drink" << endl ;
    cout << "8-       Update cold drink price" << endl; 
    cout << "9-       View comments" << endl;
    cout << "10-      View bill" << endl ;
    cout << "11-      Back" << endl; 
}

void customerInterface()
{
    system("cls");
    topHeader();
    cout << "   Customer Interface  " << endl << "-----------------------"<< endl;
    cout << "1-       View Menu" << endl ;
    cout << "2-       Give order" << endl; 
    cout << "3-       View deals" << endl;
    cout << "4-       Order deals" << endl ;
    cout << "5-       Enter cold drink" << endl; 
    cout << "6-       View bill" << endl;
    cout << "7-       Feedback" << endl;
    cout << "8-       Back" << endl;

}

void addDish()
{
        string newdish;
        int price;
        cout << "Enter the new dish : ";
        cin >> newdish;
        cout << "Enter the price of new dish : ";
        cin >> price;
        for (int i = 0 ; i < 10 ; i++)
        {
            if(dishes[i] == "")
            {
                dishes[i] = newdish;
                prices[i] = price;
                break;
            }
        }
}


void searchDish()
{
    string nm;
    cout << "Enter the name : ";
    cin >> nm;
    for (int i = 0 ; i < 10 ; i++)
    {
        if(nm == dishes[i])
        {
            cout << "     " << dishes[i] << "    " << "\t\t" << prices[i] << endl;
        }
    }
}



void updatePrice()
{
    string dish;
    int price;
    cout << "Enter the dish : ";
    cin >> dish;
    cout << "Enter the new price : ";
    cin >> price;
    for (int i = 0 ; i < 10 ; i++)
    {
        if(dish == dishes[i])
        {
            prices[i] = price;
        }
    }
}

void deleteDish()
{
    string dish;
    cout << "Enter the name : ";
    cin >> dish;
    for (int i = 0 ; i < 10 ; i++)
    {
        if(dish == dishes[i])
        {
            dishes[i] = "";
            prices[i] = 0;
        }
    }
}

void addDeal()
{
        string newdeal;
        int price;
        cout << "Enter the new deal : ";
        getline(cin,newdeal);
        cout << "Enter the price of new deal : ";
        cin >> price;
        for (int i = 0 ; i < 10 ; i++)
        {
            if(deals[i] == "")
            {
                deals[i] = newdeal;
                prices[i] = price;
                break;
            }
        }
}

void updateDeal()
{
        string deal;
        int price;
        cout << "Enter the deal : ";
        cin >> deal;
        cout << "Enter the updated price of deal : ";
        cin >> price;
        for (int i = 0 ; i < 10 ; i++)
        {
            if(deals[i] == deal)
            {
                prices[i] = price;
                break;
            }
        }
}

void deleteDeal()
{
        string deal;
        int price;
        cout << "Enter the deal : ";
        cin >> deal;
        for (int i = 0 ; i < 10 ; i++)
        {
            if(deals[i] == deal)
            {
                deals[i]="";
                prices[i] = 0;
                break;
            }
        }
}


void addColdDrink()
{
    string newColdDrink;
    int price;
    cout << "Enter the new cold drink : ";
    cin >> newColdDrink;
    cout << "Enter the price of new cold drink : ";
    cin >> price;
    for (int i = 0 ; i < 10 ; i++)
    {
        if(dishes[i] == "")
        {
            dishes[i] = newColdDrink;
            prices[i] = price;
            break;
        }
    }

}

void updateColdDrinkPrice()
{
    string coldDrink;
    int price;
    cout << "Enter the Cold Drink : ";
    cin >> coldDrink;
    cout << "Enter the new price : ";
    cin >> price;
    for (int i = 0 ; i < 10 ; i++)
    {
        if(coldDrink == dishes[i])
        {
            prices[i] = price;
        }
    }
}

void viewComents()
{
    cout << "  -----------Comments-------------  " << endl;
    for(int i = 0; i < 10 ; i++)
    {
        if(comments[i] == "")
            cout <<"";
        else
            cout << "  " << comments[i] << endl;
    }
}


void dishesMenu()
{
    cout << "  Dishes  " << "   " << "  Prices  " << endl;
    for(int i = 0; i < 10 ; i++)
    {
        if(dishes[i] == "")
            cout <<"";
        else
            cout << "  " << dishes[i] << "    " << "\t" << prices[i] << endl;
    }

}

void giveOrder()
{
    string dish;
    int quantity;
    int i = 0;
    string option = "Y";
    while(option == "Y")
    {  
        cout << "Enter dish you wanna order : ";
        cin >> dish;
        if(dishvalidation(dish))
        {
            cout << "Enter the number of quantity : ";
            cin >> quantity;
            cout << "Enter Y if you wanna add more dish : ";
            cin >> option;
            order[i] = dish;
            quantities[i] = quantity;
            i++;
        }
        else
            cout << "You have ordered an invalid dish." << endl;
    }

}

void viewDeals()
{
    for(int i = 0 ; i < 10 ; i++)
    {
        cout << "Deal   " << i+1 << endl;
        cout << deals[i] << endl;
    }
}

void orderDeal()
{
    string dealno;
    int quantity;
    cout << "Enter deal number to order : ";
    cin >> dealno;
    cout << "Enter the number of quantity : ";
    cin >> quantity;
    for (int i = 0 ; i < 10 ; i++)
    {
        if(order[i] == "")
        {
            order[i] = dealno;
            quantities[i] = quantity;
            break;
        }
    }
}

void orderColdDrink()
{
    string colddrink;
    int quantity;
    cout << "Enter the cold drink : ";
    cin >> colddrink;
    if(dishvalidation(colddrink))
        {
            cout << "Enter the number of quantity : ";
            cin >> quantity;
            for (int i = 0 ; i < 10 ; i++)
            {
                if(order[i] == "")
                {
                    order[i] = colddrink;
                    quantities[i] = quantity;
                    break;
                }
            }
            
        }
    else
        cout << "You have ordered an invalid cold drink." << endl;
    
}

int viewbill()
{
    int bill = 0;
    int pro = 1;
    int j = 0;
    for (int i = 0 ; i < 10 ; i++)
    {
        for (int k = 0 ; k < 10 ; k++)
        {
            if(order[i]==dishes[k])
            {
                pro = prices[k]*quantities[j];
                bill = bill + pro;
                j++; 

            }
        }
        

    }
    return bill;

}

void feedback()
{
    string comment;
    cout << "Enter the comment : ";
    cin.ignore();
    getline(cin,comment);
    for (int i = 0 ; i < 10 ; i++)
    {
        if(comments[i] == "")
        {
            comments[i] = comment;
            break;
        }
    }
}


bool dishvalidation(string dish)
{
    for (int j = 0 ; j < 10 ; j++)
        {
            if(dish == dishes[j])
            {
                return true;
            }
            
        }
    return false;
        
}