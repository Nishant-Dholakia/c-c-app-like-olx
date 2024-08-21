#include <iostream>
#include <windows.h>//clear screen
#include "allclasses.cpp"
#include <string>
#include <iomanip>//setw
#include <conio.h>//for getch
using namespace std;
user u[100];
unsigned int count = 0;
int car_count = 0;
int bike_count = 0;
int book_count = 0;
int watch_count = 0;
int electric_count = 0;
int mobile_count = 0;
car car1[100];
bike bike1[100];
book book1[100];
mobile mobile1[100];
electricappliances electric1[100];
wristwatch watch1[100];

inline void hr()
{
    for(int i=0;i<10;i++)
        cout<<" ";
    for(int i=0;i<135;i++)
        cout<<"*";
    cout<<endl<<endl;
}
inline void company_name()
{
     cout<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t[ BOSSAA ] <--Buy Or Sell Supplies Anytime Anywhere-->" <<endl;
    cout<< "\t\t\t\t\t    ... ______________________________________________________________________ ...";
    cout<<endl;
    cout<<endl<<endl;
}

int cin_validate(int s,int e)
{
    int choice;
    while(1)
    {
        if(!(cin>>choice))
        {
            cin.clear();
            cin.ignore(100,'\n');
            cout<<"\t\t\tEnter valid input : ";
            continue;
        }
        if(choice >= s && choice <= e)
            break;
        else
           cout<<"\t\t\tEnter valid input : ";
    }
    return choice;
}
int revenue_page()
{
    company_name();
    cout<<endl<<endl;
    cout<< "\t\t\t\tFor the product you sell , the brokerage of minimum amount from 3% of the total cost of your product"
        <<endl<< "\t\t\t\t or Rs. 30,000 will be deducted from your account";
    cout<<endl<<endl<<endl<< "\t\t\t\tPress 1. if you are interested "
        <<endl<< "\t\t\t\tPress 2. to go back"
        <<endl<<endl<< "\t\t\t\tEnter your choice : ";
        int choice;
    choice = cin_validate(1,2);
    getchar();
    system("cls");
    return choice;
}

string hidepass()
{
    string password;
    char ch;
    while ((ch = getch()) != 13)
    { // Read characters until Enter (ASCII 13) is pressed
        if (ch == '\b')
        { // Handle backspace
            if (!password.empty())
            {
                cout << "\b \b";     // Erase the last character from console
                password.pop_back(); // Remove the last character from the password
            }
        }
        else
        {
            password.push_back(ch); // Append the character to the password
            cout << '*';            // Print asterisks () instead of the actual characters
        }
    }
    cout << endl; // Print newline after password input
    if(password.length() != 8)
    {
        cout<<endl<< "\t\t\tEnter an 8-character valid password : ";
        password = hidepass();
    }
    else
    {
        for(int i=0;i<password.length();i++)
        {
            if(password[i] == ' ')
            {
                cout<<endl<< "\t\t\tPassword cannot contain blankspace"
                    <<endl<< "\t\t\tEnter valid password : ";
                password = hidepass();
                break;
            }
        }
    }
    return password;
}

void signup_login_page();
unsigned int signup();
unsigned int login();
void category(int user_no);
void display_userinfo(int user_no);
void buy_or_sell(int choice,int buy_sell,int user_no);
void allinfo();

void file_save()
{
    admin :: file_save(adm1);
    user :: file_save(u,count);
    car :: file_save(car1,car_count);
    bike :: file_save(bike1,bike_count);
    book :: file_save(book1,book_count);
    electricappliances :: file_save(electric1,electric_count);
    mobile :: file_save(mobile1,mobile_count);
    wristwatch :: file_save(watch1,watch_count);
    return;
}

void take_file()
{
    adm1.take_file();
    count = u->take_file(u);
    car_count = car1->take_file(car1);
    bike_count = bike1->take_file(bike1);
    book_count = book1->take_file(book1);
    mobile_count = mobile1->take_file(mobile1);
    electric_count = electric1->take_file(electric1);
    watch_count = watch1->take_file(watch1);
    return;
}

void admin_login()
{
    int i,go;
    bool choice = false;
    while(1)
    {
        company_name();
        string uname,password;
        cout<<endl<<endl<<"\t\t\t\t\t\t\t\t\tADMIN PORTAL"<<endl<<endl<<endl;
        cout<<"\t\t\t\t\tEnter username\t:  ";
        getline(cin>>ws,uname);
        cout<<endl<<"\t\t\t\t\tEnter Password\t:  ";
        //getline(cin>>ws,password);
        password = hidepass();
        bool result=false ;
        if(password == adm1.get_admin_password() && uname == adm1.get_admin_name())
        {
            result = true;
        }

        if(result)
        {
            cout<<endl<<"\t\t\t\t\tLogin Successful .\n\n\t\t\t\t\tPress 'Enter' to continue...";
            getchar();
            system("cls");
            break;
        }
        cout<<endl<<"\t\t\t\t\tYour Login Details Incorrect. Please try again..."<<endl;
        cout<< "\t\t\t\t\t Press 1. to go back"<<endl
            << "\t\t\t\t\t Press 2. to try again"<<endl
            << "\t\t\t\t\t Enter your choice : ";
        int temp;
        temp = cin_validate(1,2);
        getchar();
        switch(temp)
        {
        case 1:
            system("cls");
            signup_login_page();
            return;
            break;
        case 2:
            system("cls");
            continue;
        }
    }
    system("cls");
    allinfo();
}
void allinfo()//for admin portal to see all records
{
        int total_buy=0,total_sell=0;
        company_name();
        cout<<"\t\t"
            <<setw(20)<<"Sr.No."
            <<setw(30)<<"User name"
            <<setw(20)<<"Num. of buy item"
            <<setw(20)<<"Num. of sell item"
            <<"\n\n";
        for(int i=0;i<count;i++)
        {
            total_buy += u[i].get_buy_count();
            total_sell +=  u[i].get_sell_count();
            cout<<"\t\t"
                <<setw(20)<<i+1<<"."
                <<setw(30)<<u[i].get_username()
                <<setw(10)<<u[i].get_buy_count()
                <<setw(20)<<u[i].get_sell_count()
                << "\n\n";
        }
        cout<<endl<<endl<<endl<<"\t\tTotal Revenue\t\t\t:\tRs. "<<adm1.get_revenue()
            <<"\n\t\tTotal of sell items\t\t:\t"<<total_sell
            <<"\n\t\tTotal of buy items\t\t:\t"<<total_buy
            <<"\n\t\tTotal of available items\t:\t"<<(total_sell - total_buy);
        cout<<endl<<endl<<"\t\tPress 'ENTER' to continue......";
        getchar();
        system("cls");
        signup_login_page();
        return;
}

void welcomepage()
{
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t\tWell-Come To [ BOSSAA ] -Buy Or Sell Supplies Anytime Anywhere" <<endl;
    cout<< "\t\t\t\t\t    ... ________________________________________________________________ ...";
    cout<<endl;
    cout<<endl<<endl;
    cout<<"\t\t\t-> This Application Is Made For Fulfilling The Customer to Customer (C-C) Services.\n\n\t\t\t-> This Application Is Made By DDU CE Students"
        <<"As Their Project Of First Year -> Second Semester.\n\n\t\t\t-> The Contributors Of The Project Are : "<<endl;
    cout<<endl;
    cout<<endl
        <<endl<<"\t\t\tSr.No.\t\t\tFull Name\t\t\tEnrollment No.\t\t\tRoll.No."<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"\t\t\t  1.\t          DHOLAKIA NISHANT ASHIT\t\t 23CEUOS037\t\t\tCE071"<<endl<<endl;
    cout<<"\t\t\t  2.\t          DALSANIYA OMKUMAR BHAVESHBHAI\t\t 23CEUOZ029\t\t\tCE066"<<endl<<endl;
    cout<<"\t\t\t  3.\t          DHORAJIYA GOPAL SANJAYBHAI\t\t 23CEUOF038\t\t\tCE072"<<endl<<endl;
    cout<<endl<<endl<<endl<<"\t\t\tNote :  Please make sure to maximize the terminal";
    cout<<endl<<endl<<endl<< "\t\t\tPress 'Enter' to continue ...";
    getchar();
    system("cls");
    signup_login_page();
    return;
}

void signup_login_page()
{
    int choice;
    company_name();
    int user_no;
    cout<<"\t\t\t\tPress 1 If you are new user [sign up]\n\n";
    cout<<"\t\t\t\tPress 2 If you are old user [login]\n\n";
    cout<<"\t\t\t\tPress 3 for Admin portal\n\n";
    cout<< "\t\t\t\tPress 4 to Exit\n\n";
    cout<<endl<<endl<<"\t\t\t\tEnter your choice number\t:  ";
    choice = cin_validate(1,4);
    getchar();
    cout<<"\n\n\t\t\t\tPress 'Enter' to continue....";
    getchar();
    system("cls");
    switch(choice)
    {
    case 1:
        user_no = signup();
        count++;
        break;
    case 2:
        user_no = login();
        break;
    case 3:
        admin_login();
        break;
    case 4:
        company_name();
        cout<<endl<< "\t\t\tDo you want to save your data ?"
            <<endl<< "\t\t\t\tPress 1. if yes"
            <<endl<< "\t\t\t\tPress 2. if no"
            <<endl<< "\t\t\tEnter your choice\t:\t";
        int choice;
        choice = cin_validate(1,2);
        if(choice == 1)
            file_save();
        exit(1);
    }
    short go;
    company_name();
    cout<<endl<<endl<<"\tPress 1 to move to signup/login page\n\n\tPress 2 to continue category page\t:  ";
    go = cin_validate(1,2);
    getchar();
    system("cls");
    switch(go)
    {
    case 1:
        signup_login_page();
        break;
    case 2:
        category(user_no);
        break;
    }
}

unsigned int signup()
{
    company_name();
    string mobile_number;
    string input;
        cout<<endl<<endl<< "\t\tEnter your details to create a new account : "<<endl;
        cout<<endl;
        while(1)//loop for validating username
        {
            cout<<endl<< "\tEnter your User Name\t:\t";
            getline(cin>>ws,input);
            int i;
            for(i=0;i<count;i++)
            {
                if(input == u[i].get_username())
                {
                    i = -1;
                    break;
                }
            }
            if(i != -1)
            {
                u[count].set_username(input);
                break;
            }
            else
            {
                cout<<endl<< "\t\t\tThis username already exists , please enter a new username...";
            }
        }
        while(1) // loop for validating mobile numbet
        {
            cout<<endl<< "\tEnter your mobile number\t:  ";
            cin>>mobile_number;

            if(mobile_number.length() == 10)//checking if mobile number is of 10 digits
            {
                int i;
                for(i=0;i<10;i++)//checking if all letters are digits only
                {
                    if(!isdigit(mobile_number[i]))
                    {
                         cout<<endl<< "\tEnter valid mobile number ...";
                        break;
                    }
                }
                if(i == 10)
                {
                    u[count].set_mobilenumber(mobile_number);
                    break;
                }
            }
            else
                cout<<endl<< "\tEnter valid 10-digit mobile number ...";
        }


         while(1) // loop for validating email
        {
            cout<<endl<< "\tEnter your email-id\t:\t";
            getline(cin>>ws,input);
            int i;
            for(i=0;i<count;i++)
            {
                if(input == u[i].get_emailid())
                {
                    i = -1;
                    break;
                }
            }
            if(i != -1)
            {
                u[count].set_emailid(input);
                break;
            }
            else
            {
                cout<<endl<< "\t\t\tThis email-id already exists , please enter a new email...";
            }
        }
        while(1)
        {
            cout<<endl<< "\tThe password you enter must be of exactly 8 [character/digit]";
            cout<<endl<< "\tCreate your Password\t:  ";
            //getline(cin,input);
            input = hidepass();
            string temp;
            cout<<endl<< "\tConfirm Password\t:  ";
            //getline(cin,temp);
            temp = hidepass();
            if(input == temp)
            {
                u[count].set_password(input);//code execution fast
                break;
            }
            cout<<endl<< "\tPassword not matching, please enter valid Password...\n";
        }
        cout<<"\n\n\t\tPlease 'Enter' to continue....";
        getchar();
        system("cls");
        company_name();
        cout<<endl<<"\tYour Account Details :\n";
        display_userinfo(count);
        cout<<endl<< "\t\t\tPress 'Enter' to continue...";
        getchar();
        system("cls");
        return count;
}

unsigned int login()
{
    int i,go;
    bool choice = false;
    while(1)
    {
        company_name();
        string uname,pass;
        cout<<endl<<endl<<"\t\t\t\t\t\t\t\t\tLOGIN PAGE"<<endl<<endl<<endl;
        cout<<"\t\t\t\t\tEnter your username\t:  ";
        getline(cin>>ws,uname);
        cout<<endl<< "\tThe password you enter must be of exactly 8 [character/digit]";
        cout<<endl<<"\t\t\t\t\tEnter your Password\t:  ";
        //getline(cin>>ws,pass);
        pass = hidepass();
        bool result=false ;
        for(i=0;i<count;i++)
        {
            if(pass == u[i].get_password() && uname == u[i].get_username())
            {
               result = true;
               break;
            }
        }
        if(result)
        {
            cout<<endl<<"\t\t\t\t\tLogin Successfully 'Enter' to continue...";
            getchar();
            system("cls");
            break;
        }
        cout<<endl<<"\t\t\t\t\tYour Login Details Incorrect. Please try again..."<<endl;
        cout<< "\t\t\t\t\t Press 1. to go back"<<endl
            << "\t\t\t\t\t Press 2. to try again"<<endl
            << "\t\t\t\t\t Enter your choice : ";
        int temp;
        temp = cin_validate(1,2);
        getchar();
        system("cls");
        switch(temp)
        {
        case 1:
            system("cls");
            signup_login_page();
            break;
        case 2:
            system("cls");
            continue;
        }

    }

    company_name();
    cout<<endl<<"\tYour Account Details :\n";
    display_userinfo(i);
    cout<<"\n\n\t\tPlease 'Enter' to continue....";
    getchar();
    system("cls");
    return i;//returning the user number
}

void category(int user_no)
{
    int choice;
   company_name();
    cout<<endl<<"\t\t\t\t\t\t\t\tALL Categories\n"<<endl;
    hr();
    cout<<endl<<endl<<"\t\t\tUSER\t: "<<user_no+1<<endl;//here we can do count+1 for no. of user
    cout<<endl<<"\t\t\t 1. Cars"<<endl;
    cout<<endl<<"\t\t\t 2. Bikes"<<endl;
    cout<<endl<<"\t\t\t 3. Mobile"<<endl;
    cout<<endl<<"\t\t\t 4. Electrical Appliances"<<endl;
    cout<<endl<<"\t\t\t 5. Wrist Watch"<<endl;
    cout<<endl<<"\t\t\t 6. Books"<<endl;
    cout<<endl<<"\t\t\t 7. Go back"<<endl<<endl;
    cout<<endl<<"\t\t\tChoose the appropriate Category in which you want to buy or sell item\t:  ";

    choice = cin_validate(1,7);
    if(choice == 7)
    {
        system("cls");
        signup_login_page();
    }
    int buy_sell;
    cout<<endl<< "\t\t\t You want to buy an item or sell an item ?"<<endl
        <<endl<< "\t\t\t 1. Buy item"
        <<endl<< "\t\t\t 2. Sell item"
        <<endl<< "\t\t\t Select your choice : ";
    buy_sell = cin_validate(1,2);
    getchar();
    cout<< "press 'Enter' to continue...";
    getchar();
    system("cls");
    buy_or_sell(choice,buy_sell,user_no);
}

void car_category(int user_no)
{
    company_name();
    int car_index;
    cout<<"\t\tCategory : Car :-"<<endl<<endl;
    cout<<"\t\t"
        <<setw(-20)<<"Sr.No."
        <<setw(20)<<"Company"
        <<setw(20)<<"Model"
        <<setw(20)<<"Price"
        <<"\n\n";
    int i,index=0;
    bool flag = true;
    for(i=0;i<car_count;i++)
    {
        if(!car1[i].get_sold())
        {
            flag = false;
            cout<<"\t\t"
            <<setw(-20)<<index+1<<"."
            <<setw(20)<<car1[i].get_company_name()
            <<setw(20)<<car1[i].get_model_name()
            <<setw(20)<<car1[i].get_price()<<endl<<endl;
            index++;
        }
    }
    if(flag)
    {
        cout<<endl<< "\t\t\tOOPS!!! Cars are out of stock. Please visit again later...";
    }
    cout<<endl<< "\t\t"<<setw(-20)<<index+1<<"."<<setw(20)<< "Go back";
    cout<<endl<<endl<<endl<< "\t\tEnter your choice\t:\t";
    car_index = cin_validate(1,index+1);
    int count=0;
    for(i=0;i<car_count;i++)
    {
        if(!car1[i].get_sold())
        {
            count++;
        }
        if(count == car_index)
        {
            car_index = i;
            break;
        }
    }
    system("cls");
    if(car_index==index+1)
    {
        category(user_no);
    }
    if(car1[car_index].get_owner_index() == user_no)
    {
        company_name();
        cout<<endl<< "\t\t\t\tYou have kept this product for sale so you cannot buy this product. "
            <<endl<< "\t\t\t\tPlease try again for a new product."
            <<endl<<endl<< "\t\t\t\tPress 'Enter' to continue...";
        getchar();
        system("cls");
        car_category(user_no);
    }
    else
    {
        int choice;
        car1[car_index].display();
        cout<<"\n\n\n\t\t\tPress 1 to confirm buying\n\t\t\tPress 2 to go back"<<endl<<endl;
        cout<<"\t\t\tEnter your choice\t:   ";
        choice = cin_validate(1,2);
        getchar();
        cout<<"Press 'Enter' to continue.....";
        getchar();
        system("cls");
        if(choice==1)
        {
            car1[car_index].set_sold(true);
            int ownerindex = car1[car_index].get_owner_index();
            company_name();
            cout<<endl<< "\t\tOwner details : ";
            display_userinfo(ownerindex);
            u[user_no].incr_buy_count();
            cout<<endl<< "\t\tFor further processes, you may contact the owner of this car and complete all required procedures...";
            cout<<endl<< "\t\tThankyou for visiting our application and purchasing. Hope you had a smooth experience."
                <<endl<< "\t\tHope you visit again !!"
                <<endl<<endl<< "\t\tPress 'Enter' to continue...";
            getchar();
            system("cls");
            category(user_no);
        }
        else
        {
            car_category(user_no);
        }
    }
    return;
}
void bike_category(int user_no)
{
    company_name();
    int bike_index;
    cout<<"\t\tCategory : Bike :-"<<endl<<endl;
    cout<<"\t\t"
        <<setw(-20)<<"Sr.No."
        <<setw(20)<<"Company"
        <<setw(20)<<"Model"
        <<setw(20)<<"Price"
        <<"\n\n";
    int i,index=0;
    bool flag = true;
    for(i=0;i<bike_count;i++)
    {
        if(!bike1[i].get_sold())
        {
            flag = false;
            cout<<"\t\t"
            <<setw(-20)<<index+1<<"."
            <<setw(20)<<bike1[i].get_company_name()
            <<setw(20)<<bike1[i].get_model_name()
            <<setw(20)<<bike1[i].get_price()<<endl<<endl;
            index++;
        }
    }
    if(flag)
    {
        cout<<endl<< "\t\t\tOOPS!!! Bikes are out of stock. Please visit again later...";
    }
    cout<<endl<< "\t\t"<<setw(-20)<<index+1<<"."<<setw(20)<< "Go back";
    cout<<endl<<endl<<endl<< "\t\tEnter your choice\t:\t";
    bike_index = cin_validate(1,index+1);
    getchar();
    int count=0;
    for(i=0;i<bike_count;i++)
    {
        if(!bike1[i].get_sold())
        {
            count++;
        }
        if(count == bike_index)
        {
            bike_index = i;
            break;
        }
    }
    system("cls");
    if(bike_index==index+1)
    {
        category(user_no);
    }
    if(bike1[bike_index].get_owner_index() == user_no)
    {
        company_name();
        cout<<endl<< "\t\t\t\tYou have kept this product for sale so you cannot buy this product. "
            <<endl<< "\t\t\t\tPlease try again for a new product."
            <<endl<<endl<< "\t\t\t\tPress 'Enter' to continue...";
        getchar();
        system("cls");
        bike_category(user_no);
    }
    else
    {
        int choice;
        bike1[bike_index].display();
        cout<<"\n\n\n\t\t\tPress 1 to confirm buying\n\t\t\tPress 2 to go back"<<endl<<endl;
        cout<<"\t\t\tEnter your choice\t:   ";
        choice = cin_validate(1,2);
        getchar();
        cout<<"Press 'Enter' to continue.....";
        getchar();
        system("cls");
        if(choice==1)
        {
            bike1[bike_index].set_sold(true);
            int ownerindex = bike1[bike_index].get_owner_index();
            company_name();
            cout<<endl<< "\t\tOwner details : ";
            display_userinfo(ownerindex);
            u[user_no].incr_buy_count();
            cout<<endl<< "\t\tFor further processes, you may contact the owner of this bike and complete all required procedures...";
            cout<<endl<< "\t\tThankyou for visiting our application and purchasing. Hope you had a smooth experience."
                <<endl<< "\t\tHope you visit again !!"
                <<endl<<endl<< "\t\tPress 'Enter' to continue...";
            getchar();
            system("cls");
            category(user_no);
        }
        else
        {
            bike_category(user_no);
        }
    }
    return;
}

void mobile_category(int user_no)
{
    company_name();
    int mobile_index;
    cout<<"\t\tCategory : Mobile :-"<<endl<<endl;
    cout<<"\t\t"
        <<setw(-20)<<"Sr.No."
        <<setw(20)<<"Company"
        <<setw(20)<<"Model"
        <<setw(20)<<"Price"
        <<"\n\n";
    int i,index=0;
    bool flag = true;
    for(i=0;i<mobile_count;i++)
    {
        if(!bike1[i].get_sold())
        {
            flag = false;
            cout<<"\t\t"
            <<setw(-20)<<index+1<<"."
            <<setw(20)<<mobile1[i].get_company_name()
            <<setw(20)<<mobile1[i].get_model_name()
            <<setw(20)<<mobile1[i].get_price()<<endl<<endl;
            index++;
        }
    }
    if(flag)
    {
        cout<<endl<< "\t\t\tOOPS!!! Mobiles are out of stock. Please visit again later...";
    }
    cout<<endl<< "\t\t"<<setw(-20)<<index+1<<"."<<setw(20)<< "Go back";
    cout<<endl<<endl<<endl<< "\t\tEnter your choice\t:\t";
    mobile_index = cin_validate(1,index+1);
    getchar();
    int count=0;
    for(i=0;i<mobile_count;i++)
    {
        if(!mobile1[i].get_sold())
        {
            count++;
        }
        if(count == mobile_index)
        {
            mobile_index = i;
            break;
        }
    }
    system("cls");
    if(mobile_index==index+1)
    {
        category(user_no);
    }
    if(mobile1[mobile_index].get_owner_index() == user_no)
    {
        company_name();
        cout<<endl<< "\t\t\t\tYou have kept this product for sale so you cannot buy this product. "
            <<endl<< "\t\t\t\tPlease try again for a new product."
            <<endl<<endl<< "\t\t\t\tPress 'Enter' to continue...";
        getchar();
        system("cls");
        mobile_category(user_no);
    }
    else
    {
        int choice;
        mobile1[mobile_index].display();
        cout<<"\n\n\n\t\t\tPress 1 to confirm buying\n\t\t\tPress 2 to go back"<<endl<<endl;
        cout<<"\t\t\tEnter your choice\t:   ";
        choice = cin_validate(1,2);

        cout<<"Press 'Enter' to continue.....";
        getchar();
        system("cls");
        if(choice==1)
        {
            mobile1[mobile_index].set_sold(true);
            int ownerindex = mobile1[mobile_index].get_owner_index();
            company_name();
            cout<<endl<< "\t\tOwner details : ";
            display_userinfo(ownerindex);
            u[user_no].incr_buy_count();
            cout<<endl<< "\t\tFor further processes, you may contact the owner of this  and mobile complete all required procedures...";
            cout<<endl<< "\t\tThank you for visiting our application and purchasing. Hope you had a smooth experience."
                <<endl<< "\t\tHope you visit again !!"
                <<endl<<endl<< "\t\tPress 'Enter' to continue...";
            getchar();
            system("cls");
            category(user_no);
        }
        else
        {
            mobile_category(user_no);
        }
    }
    return;
}
void electric_category(int user_no)
{
    company_name();
    int electric_index;
    cout<<"\t\tCategory : Electric :-"<<endl<<endl;
    cout<<"\t\t"
        <<setw(-20)<<"Sr.No."
        <<setw(20)<<"Product"
        <<setw(20)<<"Company"
        <<setw(20)<<"Model"
        <<setw(20)<<"Price"
        <<"\n\n";
    int i,index=0;
    bool flag = true;
    for(i=0;i<electric_count;i++)
    {
        if(!electric1[i].get_sold())
        {
            flag = false;
            cout<<"\t\t"
            <<setw(-20)<<index+1<<"."
            <<setw(20)<<electric1[i].get_product_name()
            <<setw(20)<<electric1[i].get_company_name()
            <<setw(20)<<electric1[i].get_model_name()
            <<setw(20)<<electric1[i].get_price()<<endl<<endl;
            index++;
        }
    }
    if(flag)
    {
        cout<<endl<< "\t\t\tOOPS!!! Electric products are out of stock. Please visit again later...";
    }
    cout<<endl<< "\t\t"<<setw(-20)<<index+1<<"."<<setw(20)<< "Go back";
    cout<<endl<<endl<<endl<< "\t\tEnter your choice\t:\t";
    electric_index = cin_validate(1,index+1);
    int count=0;
    for(i=0;i<electric_count;i++)
    {
        if(!electric1[i].get_sold())
        {
            count++;
        }
        if(count == electric_index)
        {
            electric_index = i;
            break;
        }
    }
    system("cls");
    if(electric_index==index+1)
    {
        category(user_no);
    }
    if(electric1[electric_index].get_owner_index() == user_no)
    {
        company_name();
        cout<<endl<< "\t\t\t\tYou have kept this product for sale so you cannot buy this product. "
            <<endl<< "\t\t\t\tPlease try again for a new product."
            <<endl<<endl<< "\t\t\t\tPress 'Enter' to continue...";
        getchar();
        system("cls");
        electric_category(user_no);
    }
    else
    {
        int choice;
        electric1[electric_index].display();
        cout<<"\n\n\n\t\t\tPress 1 to confirm buying\n\t\t\tPress 2 to go back"<<endl<<endl;
        cout<<"\t\t\tEnter your choice\t:   ";
        choice = cin_validate(1,2);
        cout<<"Press 'Enter' to continue.....";
        getchar();
        system("cls");
        if(choice==1)
        {
            electric1[electric_index].set_sold(true);
            int ownerindex = electric1[electric_index].get_owner_index();
            company_name();
            cout<<endl<< "\t\tOwner details : ";
            display_userinfo(ownerindex);
            u[user_no].incr_buy_count();
            cout<<endl<< "\t\tFor further processes, you may contact the owner of this bike and complete all required procedures...";
            cout<<endl<< "\t\tThank you for visiting our application and purchasing. Hope you had a smooth experience."
                <<endl<< "\t\tHope you visit again !!"
                <<endl<<endl<< "\t\tPress 'Enter' to continue...";
            getchar();
            system("cls");
            category(user_no);
        }
        else
        {
            electric_category(user_no);
        }
    }
    return;
}
void watch_category(int user_no)
{
    company_name();
    int watch_index;
    cout<<"\t\tCategory : Watch :-"<<endl<<endl;
    cout<<"\t\t"
        <<setw(-20)<<"Sr.No."
        <<setw(20)<<"Company"
        <<setw(20)<<"Model"
        <<setw(20)<<"Price"
        <<"\n\n";
    int i,index=0;
    bool flag = true;
    for(i=0;i<watch_count;i++)
    {
        if(!watch1[i].get_sold())
        {
            flag = false;
            cout<<"\t\t"
            <<setw(-20)<<index+1<<"."
            <<setw(20)<<watch1[i].get_company_name()
            <<setw(20)<<watch1[i].get_model_name()
            <<setw(20)<<watch1[i].get_price()<<endl<<endl;
            index++;
        }
    }
    if(flag)
    {
        cout<<endl<< "\t\t\tOOPS!!! Watch products are out of stock. Please visit again later...";
    }
    cout<<endl<< "\t\t"<<setw(-20)<<index+1<<"."<<setw(20)<< "Go back";
    cout<<endl<<endl<<endl<< "\t\tEnter your choice\t:\t";
    watch_index = cin_validate(1,index+1);
    int count=0;
    for(i=0;i<watch_count;i++)
    {
        if(!watch1[i].get_sold())
        {
            count++;
        }
        if(count == watch_index)
        {
            watch_index = i;
            break;
        }
    }
    system("cls");
    if(watch_index==index+1)
    {
        category(user_no);
    }
    if(watch1[watch_index].get_owner_index() == user_no)
    {
        company_name();
        cout<<endl<< "\t\t\t\tYou have kept this product for sale so you cannot buy this product. "
            <<endl<< "\t\t\t\tPlease try again for a new product."
            <<endl<<endl<< "\t\t\t\tPress 'Enter' to continue...";
        getchar();
        system("cls");
        watch_category(user_no);
    }
    else
    {
        int choice;
        watch1[watch_index].display();
        cout<<"\n\n\n\t\t\tPress 1 to confirm buying\n\t\t\tPress 2 to go back"<<endl<<endl;
        cout<<"\t\t\tEnter your choice\t:   ";
        choice = cin_validate(1,2);
        cout<<"Press 'Enter' to continue.....";
        getchar();
        system("cls");
        if(choice==1)
        {
            watch1[watch_index].set_sold(true);
            int ownerindex = watch1[watch_index].get_owner_index();
            company_name();
            cout<<endl<< "\t\tOwner details : ";
            display_userinfo(ownerindex);
            u[user_no].incr_buy_count();
            cout<<endl<< "\t\tFor further processes, you may contact the owner of this bike and complete all required procedures...";
            cout<<endl<< "\t\tThank you for visiting our application and purchasing. Hope you had a smooth experience."
                <<endl<< "\t\tHope you visit again !!"
                <<endl<<endl<< "\t\tPress 'Enter' to continue...";
            getchar();
            system("cls");
            category(user_no);
        }
        else
        {
            watch_category(user_no);
        }
    }
    return;
}

void book_category(int user_no)
{
    company_name();
    int book_index;
    cout<<"\t\tCategory : Book :-"<<endl<<endl;
    cout<<"\t\t"
        <<setw(-20)<<"Sr.No."
        <<setw(20)<<"Book Name"
        <<setw(20)<<"Author"
        <<setw(20)<<"Price"
        <<"\n\n";
    int i,index=0;
    bool flag = true;
    for(i=0;i<book_count;i++)
    {
        if(!book1[i].get_sold())
        {
            flag = false;
            cout<<"\t\t"
            <<setw(-20)<<index+1<<"."
            <<setw(20)<<book1[i].get_book_name()
            <<setw(20)<<book1[i].get_author()
            <<setw(20)<<book1[i].get_price()<<endl<<endl;
            index++;
        }
    }
    if(flag)
    {
        cout<<endl<< "\t\t\tOOPS!!! Bikes are out of stock. Please visit again later...";
    }
    cout<<endl<< "\t\t"<<setw(-20)<<index+1<<"."<<setw(20)<< "Go back";
    cout<<endl<<endl<<endl<< "\t\tEnter your choice\t:\t";
    book_index = cin_validate(1,index+1);
    int count=0;
    for(i=0;i<book_count;i++)
    {
        if(!book1[i].get_sold())
        {
            count++;
        }
        if(count == book_index)
        {
            book_index = i;
            break;
        }
    }
    system("cls");
    if(book_index==index+1)
    {
        category(user_no);
    }
    if(book1[book_index].get_owner_index() == user_no)
    {
        company_name();
        cout<<endl<< "\t\t\t\tYou have kept this product for sale so you cannot buy this product. "
            <<endl<< "\t\t\t\tPlease try again for a new product."
            <<endl<<endl<< "\t\t\t\tPress 'Enter' to continue...";
        getchar();
        system("cls");
        book_category(user_no);
    }
    else
    {
        int choice;
        book1[book_index].display();
        cout<<"\n\n\n\t\t\tPress 1 to confirm buying\n\t\t\tPress 2 to go back"<<endl<<endl;
        cout<<"\t\t\tEnter your choice\t:   ";
        choice = cin_validate(1,2);
        cout<<"Press 'Enter' to continue.....";
        getchar();
        system("cls");
        if(choice==1)
        {
            book1[book_index].set_sold(true);
            int ownerindex = book1[book_index].get_owner_index();
            company_name();
            cout<<endl<< "\t\tOwner details : ";
            display_userinfo(ownerindex);
            u[user_no].incr_buy_count();
            cout<<endl<< "\t\tFor further processes, you may contact the owner of this bike and complete all required procedures...";
            cout<<endl<< "\t\tThank you for visiting our application and purchasing. Hope you had a smooth experience."
                <<endl<< "\t\tHope you visit again !!"
                <<endl<<endl<< "\t\tPress 'Enter' to continue...";
            getchar();
            system("cls");
            category(user_no);
        }
        else
        {
            book_category(user_no);
        }
    }
    return;
}

void buy_or_sell(int choice,int buy_sell,int user_no)//to redirect to either buy page or get data in sell page
{


    switch(buy_sell)
    {
    case 1://buy
        switch(choice)
        {
             case 1://car

                if(!car_count)
                {
                    cout<<"\n\n\n\t\t\tNo data found\n\n";
                    cout<<"Press 'Enter' to continue.....";
                    getchar();
                    system("cls");
                    category(user_no);
                }
                else
                {
                    car_category(user_no);
                }
                break;

             case 2://bike

                if(!bike_count)
                {
                    cout<<"\n\n\n\t\t\tNo data found\n\n";
                    cout<<"Press 'Enter' to continue.....";
                    getchar();
                    system("cls");
                    category(user_no);
                }
                else
                {
                    bike_category(user_no);
                }
                break;

                case 3://mobile

                if(!mobile_count)
                {
                    cout<<"\n\n\n\t\t\tNo data found\n\n";
                    cout<<"Press 'Enter' to continue.....";
                    getchar();
                    system("cls");
                    category(user_no);
                }
                else
                {
                    mobile_category(user_no);
                }
                break;

                case 4://electric

                if(!electric_count)
                {
                    cout<<"\n\n\n\t\t\tNo data found\n\n";
                    cout<<"Press 'Enter' to continue.....";
                    getchar();
                    system("cls");
                    category(user_no);
                }
                else
                {
                    electric_category(user_no);
                }
                break;

                case 5://watch

                if(!watch_count)
                {
                    cout<<"\n\n\n\t\t\tNo data found\n\n";
                    cout<<"Press 'Enter' to continue.....";
                    getchar();
                    system("cls");
                    category(user_no);
                }
                else
                {
                    watch_category(user_no);
                }
                break;

             case 6://book

                if(!book_count)
                {
                    cout<<"\n\n\n\t\t\tNo data found\n\n";
                    cout<<"Press 'Enter' to continue.....";
                    getchar();
                    system("cls");
                    category(user_no);
                }
                else
                {
                    book_category(user_no);
                }
                break;
        }
            break;
    case 2://sell
        int temp;
        switch(choice)
        {
        case 1://car

            car1[car_count].set_owner_name(u[user_no].get_username());
            car1[car_count].set_owner_index(user_no);
            temp = revenue_page();
            if(temp != 2)
            {
                company_name();
                car1[car_count].get_data();
                adm1.incr_revenue(car1[car_count].get_price());
                u[user_no].incr_sell_count();
                system("cls");
                car1[car_count].display();
                car_count++;
            }
            break;

        case 2://bike

            bike1[bike_count].set_owner_name(u[user_no].get_username());
            bike1[bike_count].set_owner_index(user_no);
            temp = revenue_page();
            if(temp == 2)
                break;
            company_name();
            bike1[bike_count].get_data();
            adm1.incr_revenue(bike1[bike_count].get_price());
            u[user_no].incr_sell_count();
            system("cls");
            bike1[bike_count].display();
            bike_count++;
            break;

        case 3://mobile

            mobile1[mobile_count].set_owner_name(u[user_no].get_username());
            mobile1[mobile_count].set_owner_index(user_no);
            temp = revenue_page();
            if(temp == 2)
                break;
            company_name();
            mobile1[mobile_count].get_data();
            adm1.incr_revenue(mobile1[mobile_count].get_price());
            u[user_no].incr_sell_count();
            system("cls");
            mobile1[mobile_count].display();
            mobile_count++;
            break;

        case 4://electrical appliances

            electric1[electric_count].set_owner_name(u[user_no].get_username());
            electric1[electric_count].set_owner_index(user_no);
            temp = revenue_page();
            if(temp == 2)
                break;
            company_name();
            electric1[electric_count].get_data();
            adm1.incr_revenue(electric1[electric_count].get_price());
            u[user_no].incr_sell_count();
            system("cls");
            electric1[electric_count].display();
            electric_count++;
            break;

        case 5://wrist watch

            watch1[watch_count].set_owner_name(u[user_no].get_username());
            watch1[watch_count].set_owner_index(user_no);
            temp = revenue_page();
            if(temp == 2)
                break;
            company_name();
            watch1[watch_count].get_data();
            adm1.incr_revenue(watch1[watch_count].get_price());
            u[user_no].incr_sell_count();
            system("cls");
            watch1[watch_count].display();
            watch_count++;
            break;

        case 6://book

            book1[book_count].set_owner_name(u[user_no].get_username());
            book1[book_count].set_owner_index(user_no);
            temp = revenue_page();
            if(temp == 2)
                break;
            company_name();
            book1[book_count].get_data();
            adm1.incr_revenue(book1[book_count].get_price());
            u[user_no].incr_sell_count();
            system("cls");
            book1[book_count].display();
            book_count++;
            break;
        }
        cout<<endl<< "Thank you , Your response is recorded ...";
        cout<<endl<< "Press 'Enter' to continue";
        getchar();
        system("cls");
        category(user_no);
    }
}

void display_userinfo(int user_no)
{
    cout<<endl;
    cout<<endl<< "\t Username\t:\t"<<u[user_no].get_username()<<endl;
    cout<<endl<< "\t Mobile Number\t:\t"<<u[user_no].get_mobilenumber()<<endl;
    cout<<endl<< "\t email id\t:\t"<<u[user_no].get_emailid()<<endl;
    return;
}

int main()
{
    int choice;
    cout<<endl<< "\t\t\tDo you want to retrieve your past data ?"
        <<endl<< "\t\t\t\tPress 1. if yes"
        <<endl<< "\t\t\t\tPress 2. if no";
    cout<<endl<< "\t\t\tSelect your choice : ";
    choice = cin_validate(1,2);
    getchar();
    if(choice == 1)
    {
        take_file();
    }
    system("cls");
     welcomepage();
     return 0;
}
