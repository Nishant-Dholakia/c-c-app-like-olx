#include <iostream>
#include <fstream>
using namespace std;

class admin
{
    unsigned int revenue;
    string admin_name;
    string admin_password;
public:
    admin()
    {
        admin_name = "CEA3";
        admin_password="CEA3_123";
        revenue = 0;
    }
    unsigned int get_revenue()
    {
        return revenue;
    }
    string get_admin_name()
    {
        return admin_name;
    }
    string get_admin_password()
    {
        return admin_password;
    }
    void incr_revenue(int price)
    {
        if(price < 1000000)
            revenue += unsigned(price * 0.03);
        else
            revenue += 30000;
    }
    static void file_save(admin &a)
    {
        ofstream in;
        in.open("admin.txt");
        in<<a.revenue;
        in.close();
    }
    void take_file()
    {
        ifstream take;
        take.open("admin.txt");
        take>>revenue;
        take.close();
    }
}adm1;

class user
{
    string username;
    string mobilenumber;
    string emailid;
    string password;
    unsigned buy_count;
    unsigned sell_count;
public:
    user()
    {
        buy_count = 0;
        sell_count = 0;
    }
    string get_username()
    {
        return username;
    }
    void set_username(string b)
    {
        username=b;
    }
    string get_mobilenumber()
    {
        return mobilenumber;
    }
    void set_mobilenumber(string b)
    {
        mobilenumber=b;
    }
    string get_emailid()
    {
        return emailid;
    }
    void set_emailid(string b)
    {
        emailid=b;
    }
    string get_password()
    {
        return password;
    }
    void set_password(string b)
    {
        password=b;
    }
    void incr_sell_count()
    {
        sell_count++;
    }
    void incr_buy_count()
    {
        buy_count++;
    }
    unsigned int get_buy_count()
    {
        return buy_count;
    }
    unsigned int get_sell_count()
    {
        return sell_count;
    }
    static void file_save(user *u,int count)
    {
        ofstream save;
        save.open("user.txt");
        save<<count<<endl;

        int i=0;
        for(i=0;i<count;i++)
        {
            save<<u[i].buy_count<<endl
                <<u[i].sell_count
                <<u[i].username<<endl
                <<u[i].mobilenumber<<endl
                <<u[i].emailid<<endl
                <<u[i].password<<endl;
        }
        save.close();
    }
    int take_file(user *u)
    {
        ifstream take;
        take.open("user.txt");
        int count;
        take>>count;

       // u = new user[count];
        int i=0;
        while(!take.eof())
        {
            take>>u[i].buy_count;
            take>>u[i].sell_count;
            getline(take,u[i].username);
            getline(take,u[i].mobilenumber);
            getline(take,u[i].emailid);
            getline(take,u[i].password);
            i++;
        }
        return count;
    }
};

class all_items
{
protected:
    string owner_name;
    int owner_index;//the index of owner as per user class
    int buy_year;
    unsigned long int price;
    string description;
    int owner_num;//which number of owner of product
    bool sold = false;
public:
    virtual void display() = 0;
    virtual void get_data() = 0;
    void set_owner_name(string i)
    {
        owner_name = i;
    }
    string get_owner_name()
    {
        return owner_name;
    }

    void set_sold(bool i)
    {
        sold = i;
    }
    bool get_sold()
    {
        return sold;
    }

    void set_owner_index(unsigned int i)
    {
        owner_index = i;
    }
    unsigned int get_owner_index()
    {
        return owner_index;
    }

     void set_description(string i)
    {
        description = i;
    }
    string get_description()
    {
        return description;
    }

    void set_buy_year(int i)
    {
        buy_year = i;
    }
    int get_buy_year()
    {
        return buy_year;
    }

    void set_price(unsigned int i)
    {
        price = i;
    }
    unsigned int get_price()
    {
        return price;
    }

    void set_owner_num(int i)
    {
        owner_num = i;
    }
    int get_owner_num()
    {
        return owner_num;
    }

     void display_owner_num()
    {
        cout << endl<< "\tNumber of previous owners\t:\t" << owner_num << endl;
    }
    void display_owner_name()
    {
        cout<<endl<< "\tOwner Name\t:\t"<<owner_name<<endl;
    }
    void display_buy_year()
    {
        cout<<endl<< "\tYear of Buying\t:\t"<<buy_year<<endl;
    }
    void display_price()
    {
        cout<<endl<< "\tPrice\t\t:\t"<<price<<endl;
    }
    void display_description()
    {
        cout<<endl<<"\tDescription\t:\t"<<description<<endl;
    }
};

class book : public all_items
{
    string book_name;
    string author;
    string content_type;
    int num_pages;
    int publish_year;
    public:
    void set_book_name(string i)
    {
        book_name = i;
    }
    string get_book_name()
    {
        return book_name;
    }
    void set_author(string i)
    {
        author = i;
    }
    string get_author()
    {
        return author;
    }
    void set_content_type(string i)
    {
        content_type = i;
    }
    string get_content_type()
    {
        return content_type;
    }
    void set_num_pages(int i)
    {
        num_pages = i;
    }
    int get_num_pages()
    {
        return num_pages;
    }
    void set_publish_year(int i)
    {
        publish_year = i;
    }
    int get_publish_year()
    {
        return publish_year;
    }

    static void file_save(book *b,int book_count)
    {
        ofstream save;
        save.open("book.txt");
        save<<book_count;
        int i=0;
        for(i=0;i<book_count;i++)
        {
            save<<b[i].owner_name<<endl
                <<b[i].owner_index
                <<b[i].book_name<<endl
                <<b[i].sold
                <<b[i].author<<endl
                <<b[i].content_type<<endl
                <<b[i].publish_year<<endl
                <<b[i].buy_year<<endl
                <<b[i].num_pages<<endl
                <<b[i].price<<endl
                <<b[i].owner_num
                <<b[i].description<<endl;
        }
        save.close();
    }
    int take_file(book *b)
    {
        ifstream take;
        take.open("book.txt");
        int book_count;
        take>>book_count;
        int i=0;
        while(!take.eof())
        {
            getline(take,b[i].owner_name);
            take>>b[i].owner_index;
            getline(take,b[i].book_name);
            take>>b[i].sold;
            getline(take,b[i].author);
            getline(take,b[i].content_type);
            take>>b[i].publish_year;
            take>>b[i].buy_year;
            take>>b[i].num_pages;
            take>>b[i].price;
            take>>b[i].owner_num;
            getline(take,b[i].description);
            i++;
        }
        return book_count;
    }


    void get_data()
    {
        cout<<endl << "\t\tBook :-"<<endl<<endl;
        cout << endl<< "\tEnter Book name\t:\t";
        getline(cin>>ws,book_name);
        cout << endl<< "\tEnter Author name\t:\t";
        getline(cin>>ws,author);
        cout << endl<< "\tEnter Content type\t:\t";
        getline(cin>>ws,content_type);
        cout << endl<< "\tEnter Publish year\t:\t";
        cin>>publish_year;
        cout << endl<< "\tEnter buying year of book\t:\t";
        cin>>buy_year;
        cout << endl<< "\tEnter Number of pages\t:\t";
        cin>>num_pages;
        cout << endl<< "\tEnter price of the book\t:\t";
        cin>>price;
        cout << endl<< "\tEnter number of Owners (previous owners including you)\t:\t";
        cin>>owner_num;
        cout << endl<< "\tAdd description about your book\t:\t";
        getline(cin>>ws,description);
    }
    void display()
    {
        display_owner_name();
        cout << endl<< "\tBook name\t:\t" << book_name << endl;
        cout << endl<< "\tAuthor\t\t:\t" << author << endl;
        cout << endl<< "\tContent type\t:\t" << content_type << endl;
        cout << endl<< "\tPublishing year\t:\t" << publish_year<< endl;
        display_buy_year();
        cout << endl<< "\tTotal pages\t:\t" << num_pages << endl;
        display_price();
        display_owner_num();
        display_description();
    }
};

class tech_class
{
protected:
    string company_name;
    string model_name;
    string color;
public:
    void set_company_name(string i)
    {
        company_name = i;
    }
    string get_company_name()
    {
        return company_name;
    }
    void set_model_name(string i)
    {
        model_name = i;
    }
    string get_model_name()
    {
        return model_name;
    }
    void set_color(string i)
    {
        color = i;
    }
    string get_color()
    {
        return color;
    }
    void display_company_name()
    {

      cout << endl<< "\tCompany\t\t:\t" << company_name << endl;
    }
    void display_model_name()
    {
        cout << endl;
      cout << "\tModel name\t:\t" << model_name << endl;
    }
    void display_color()
    {
        cout << endl;
      cout << "\tColor\t\t:\t" << color << endl;
    }

};

class bike : public all_items , public tech_class
{
    protected:
    double  travel_km;
    string numberplate;
    string drive_type;
    public:
    void set_numberplate(string i)
    {
        numberplate = i;
    }
    string get_numberplate()
    {
        return numberplate;
    }
    void set_drive_type(string i)
    {
        drive_type = i;
    }
    string get_drive_type()
    {
        return drive_type;
    }
    void set_travel_km(double i)
    {
        travel_km = i;
    }
    double get_travel_km()
    {
        return travel_km;
    }

     static void file_save(bike *b,int bike_count)
    {
        ofstream save;
        save.open("bike.txt");
        save<<bike_count;
        int i=0;
        for(i=0;i<bike_count;i++)
        {
            save<<b[i].owner_name<<endl
                <<b[i].owner_index
                <<b[i].company_name<<endl
                <<b[i].sold
                <<b[i].model_name<<endl
                <<b[i].buy_year<<endl
                <<b[i].travel_km
                <<b[i].numberplate<<endl
                <<b[i].drive_type<<endl
                <<b[i].owner_num
                <<b[i].color<<endl
                <<b[i].price
                <<b[i].description<<endl;
        }
        save.close();
    }
    int take_file(bike *b)
    {
        ifstream take;
        take.open("bike.txt");
        int bike_count;
        take>>bike_count;
        int i=0;
        while(!take.eof())
        {
            getline(take,b[i].owner_name);
            take>>b[i].owner_index;
            getline(take,b[i].company_name);
            take>>b[i].sold;
            getline(take,b[i].model_name);
            take>>b[i].buy_year;
            take>>b[i].travel_km;
            getline(take,b[i].numberplate);
            getline(take,b[i].drive_type);
            take>>b[i].owner_num;
            getline(take,b[i].color);
            take>>b[i].price;
            getline(take,b[i].description);
            i++;
        }
        return bike_count;
    }

    void get_data()
    {
        cout<<endl << "\t\tBike :-"<<endl<<endl;
        cout << endl<< "\tEnter Company name\t:\t" ;
        getline(cin>>ws,company_name);
        cout << endl<< "\tEnter bike name\t:\t" ;
        getline(cin>>ws,model_name);
        cout << endl<< "\tYear of buying\t:\t" ;
        cin>>buy_year;
        cout << endl<< "\tK.M. traveled\t:\t" ;
        cin>>travel_km;
        cout << endl<< "\tEnter number plate\t:\t" ;
        while(1)
        {
            cin>>numberplate;
            if(isdigit(numberplate[0]) || isdigit(numberplate[1]))
                cout<<endl<< "\tEnter valid numberplate\t:\t";
            else
                break;
        }
        cout << endl<< "\tDrive type (electric or fuel)\t:\t" ;
        while(1)// to validate drive type
        {
            getline(cin>>ws,drive_type);
            if(drive_type == "electric" || drive_type == "fuel")
            break;
            cout<<endl<< "\tEnter valid drive type\t:\t";
        }
        cout<<endl<< "\tWhich owner are you? [1/2/...]\t:\t";
       while(1)// number of owners cannot be negative
       {
        cin>>owner_num;
        if(owner_num<1)
        {
            cout<<endl<< "\tEnter valid owner number\t:\t";
            continue;
        }
        break;
       }
        cout << endl<< "\tEnter color\t:\t" ;
        getline(cin>>ws,color);
        cout << endl<< "\tEnter your vehicle's price\t:\t" ;
        cin>>price;
        cout << endl<< "\tWould you like to give any other description about your vehicle\t:\t" ;
        getline(cin>>ws,description);

    }
    void display ()
    {
        display_owner_name();
        display_company_name();
        display_model_name();
        display_buy_year();
        display_price();
        cout << endl<< "\tTravel(Km)\t\t:\t" << get_travel_km() << endl;
        cout << endl<< "\tNumber plate\t:\t" << get_numberplate() << endl;
        cout << endl<< "\tDrive type\t:\t" << get_drive_type() << endl;
        display_owner_num();
        display_color();
        display_description();
    }
};

class car : public bike
{
    string fuel_type;
public:
    void set_fuel_type(string i)
    {
        fuel_type = i;
    }
    string get_fuel_type()
    {
        return fuel_type;
    }

    static void file_save(car *c,int car_count)
    {
        ofstream save;
        save.open("car.txt");
        save<<car_count;
        int i=0;
        for(i=0;i<car_count;i++)
        {
            save<<c[i].owner_name<<endl
                <<c[i].owner_index
                <<c[i].company_name<<endl
                <<c[i].sold
                <<c[i].model_name<<endl
                <<c[i].buy_year<<endl
                <<c[i].travel_km
                <<c[i].numberplate<<endl
                <<c[i].drive_type<<endl
                <<c[i].fuel_type<<endl
                <<c[i].owner_num
                <<c[i].color<<endl
                <<c[i].price
                <<c[i].description<<endl;
        }
        save.close();
    }
    int take_file(car *c)
    {
        ifstream take;
        take.open("car.txt");
        int car_count;
        take>>car_count;
        int i=0;
        while(!take.eof())
        {
            getline(take,c[i].owner_name);
            take>>c[i].owner_index;
            getline(take,c[i].company_name);
            take>>c[i].sold;
            getline(take,c[i].model_name);
            take>>c[i].buy_year;
            take>>c[i].travel_km;
            getline(take,c[i].numberplate);
            getline(take,c[i].drive_type);
            getline(take,c[i].fuel_type);
            take>>c[i].owner_num;
            getline(take,c[i].color);
            take>>c[i].price;
            getline(take,c[i].description);
            i++;
        }
        return car_count;
    }

     void get_data()
    {
        cout<<endl << "\t\tCar :-"<<endl<<endl;
        cout << endl<< "\tEnter Company name\t:\t" ;
        getline(cin>>ws,company_name);
        cout << endl<< "\tEnter car name\t:\t" ;
        getline(cin>>ws,model_name);
        cout << endl<< "\tYear of buying\t:\t" ;
        cin>>buy_year;
        cout << endl<< "\tK.M. traveled\t:\t" ;
        cin>>travel_km;
        cout << endl<< "\tEnter number plate\t:\t" ;
       while(1)
        {
            cin>>numberplate;
            if(isdigit(numberplate[0]) || isdigit(numberplate[1] ))
                cout<<endl<< "\tEnter valid numberplate\t:\t";
            else
                break;
        }
        while(1)// to check if drive type and fuel type are matching or not
        {
            cout << endl<< "\tDrive type (electric or fuel)\t:\t" ;
            while(1)// to validate drive type
            {
                getline(cin>>ws,drive_type);
                if(drive_type == "electric" || drive_type == "fuel")
                    break;
                cout<<endl<< "\tEnter valid drive type\t:\t";
            }
            cout << endl<< "\tFuel  type (Enter battery if electric / petrol/diesel/cng)\t:\t" ;
            while(1)// to validate fuel type
            {
                getline(cin>>ws,fuel_type);
                if(fuel_type == "battery" || fuel_type == "petrol" || fuel_type == "diesel" || fuel_type == "cng")
                    break;
                cout<<endl<< "\tEnter valid fuel type\t:\t";
            }
            // to check the matching
            if((drive_type == "electric" && fuel_type != "battery") || (drive_type != "electric" && fuel_type == "battery"))
            {
                cout<<endl<< "\tPlease enter valid entry in fuel section...";
            }
            else
                break;
        }
       cout<<endl<< "\tWhich owner are you? [1/2/...]\t:\t";
       while(1)// number of owners cannot be negative
       {
        cin>>owner_num;
        if(owner_num<1)
        {
            cout<<endl<< "\tEnter valid owner number\t:\t";
            continue;
        }
        break;
       }
        cout << endl<< "\tEnter color\t:\t" ;
        getline(cin>>ws,color);
        cout << endl<< "\tEnter your vehicle's price\t:\t" ;
        cin>>price;
        cout << endl<< "\tWould you like to give any other description about your vehicle\t:\t" ;
        getline(cin>>ws,description);

    }
    void display ()
    {
        display_owner_name();
        display_company_name();
        display_model_name();
        display_buy_year();
        display_price();
        cout << endl;
        cout << "\tTravel(Km)\t:\t" << get_travel_km() << endl;
        cout << endl;
        cout << "\tNumber plate\t:\t" << get_numberplate() << endl;
        display_owner_num();
        cout<<endl;
        cout << "\tFuel type\t:\t" << get_fuel_type() << endl;
        cout << endl;
        cout << "\tDrive type\t:\t" << get_drive_type() << endl;
        display_color();
        display_description();
     }

};

class electricappliances: public all_items , public tech_class
{
    string product_name;
public:
    string get_product_name()
    {
        return product_name;
    }
    void set_product_name(string b)
    {
        product_name = b;
    }

    static void file_save(electricappliances *e,int electric_count)
    {
        ofstream save;
        save.open("electric.txt");
        save<<electric_count;
        int i=0;
        for(i=0;i<electric_count;i++)
        {
            save<<e[i].owner_name<<endl
                <<e[i].owner_index
                <<e[i].product_name<<endl
                <<e[i].sold
                <<e[i].company_name<<endl
                <<e[i].model_name<<endl
                <<e[i].buy_year<<endl
                <<e[i].owner_num<<endl
                <<e[i].price
                <<e[i].description<<endl;
        }
        save.close();
    }
    int take_file(electricappliances *e)
    {
        ifstream take;
        take.open("electric.txt");
        int electric_count;
        take>>electric_count;
       // u = new user[count];
        int i=0;
        while(!take.eof())
        {
            getline(take,e[i].owner_name);
            take>>e[i].owner_index;
            getline(take,e[i].product_name);
            take>>e[i].sold;
            getline(take,e[i].company_name);
            getline(take,e[i].model_name);
            take>>e[i].buy_year;
            take>>e[i].owner_num;
            take>>e[i].price;
            getline(take,e[i].description);
            i++;
        }
        return electric_count;
    }

    void get_data()
    {
        cout<<endl << "\t\tElectric Appliance :-"<<endl<<endl;
        cout << endl<< "\tEnter product name\t:\t" ;
        getline(cin>>ws,product_name);
        cout << endl<< "\tEnter Company name\t:\t" ;
        getline(cin>>ws,company_name);
        cout << endl<< "\tEnter model name\t:\t" ;
        getline(cin>>ws,model_name);
        cout << endl<< "\tYear of buying\t:\t" ;
        cin>>buy_year;
        cout<<endl<< "\tWhich owner are you? [1/2/...]\t:\t";
       while(1)
       {
        cin>>owner_num;
        if(owner_num<1)
        {
            cout<<endl<< "\tEnter valid owner number\t:\t";
            continue;
        }
        break;
       }
        cout << endl<< "\tEnter your product's price\t:\t" ;
        cin>>price;
        cout << endl<< "\tWould you like to give any other description about your product\t:\t" ;
        getline(cin>>ws,description);
    }
    void display()
    {
        display_owner_name();
        cout<<endl<< "\tProduct Name\t:\t"<<product_name<<endl;
        display_company_name();
       display_model_name();
        display_price();
        display_buy_year();
        display_owner_num();
        display_description();
    }
};

class mobile: public all_items , public tech_class
{
int ram;
int rom;
int mahbattery;
 public:
      int get_ram()
     {
        return ram;
     }
   void set_ram(int b)
     {
        ram = b;
     }
    int get_rom()
     {
        return rom;
     }
   void set_rom(int b)
     {
       rom = b;
     }
    int get_mahbattery()
     {
        return mahbattery;
     }
   void set_mahbattery(int b)
     {
       mahbattery = b;
     }
    static void file_save(mobile *m,int mobile_count)
    {
        ofstream save;
        save.open("mobile.txt");
        save<<mobile_count;
        int i=0;
        for(i=0;i<mobile_count;i++)
        {
            save<<m[i].owner_name<<endl
                <<m[i].owner_index
                <<m[i].company_name<<endl
                <<m[i].sold
                <<m[i].model_name<<endl
                <<m[i].buy_year<<endl
                <<m[i].owner_num<<endl
                <<m[i].ram<<endl
                <<m[i].rom<<endl
                <<m[i].mahbattery<<endl
                <<m[i].price
                <<m[i].description<<endl;
        }
        save.close();
    }

    int take_file(mobile *m)
    {
        ifstream take;
        take.open("mobile.txt");
        int mobile_count;
        take>>mobile_count;
        int i=0;
        while(!take.eof())
        {
            getline(take,m[i].owner_name);
            take>>m[i].owner_index;
            getline(take,m[i].company_name);
            take>>sold;
            getline(take,m[i].model_name);
            take>>m[i].buy_year;
            take>>m[i].owner_num;
            take>>m[i].ram;
            take>>m[i].rom;
            take>>m[i].mahbattery;
            take>>m[i].price;
            getline(take,m[i].description);
            i++;
        }
        return mobile_count;
    }

     void get_data()
     {
        cout<<endl << "\t\tMobile :-"<<endl<<endl;
        cout << endl<< "\tEnter Company name\t:\t" ;
        getline(cin>>ws,company_name);
        cout << endl<< "\tEnter model name\t:\t" ;
        getline(cin>>ws,model_name);
        cout << endl<< "\tYear of buying\t:\t" ;
        cin>>buy_year;
        cout<<endl<< "\tWhich owner are you? [1/2/...]\t:\t";
       while(1)
       {
        cin>>owner_num;
        if(owner_num>0)
        {
        break;
        }
        cout<<endl<< "\tEnter valid owner number\t:\t";
       }
       cout << endl<< "\tEnter RAM[in GB] of your phone\t:\t" ;
       while(1)
       {
        cin>>ram;
            if(ram>0)
            {
                break;
            }
           cout<<endl<< "\tPlease enter valid ram\t:\t";
       }
       cout << endl<< "\tEnter ROM[in GB] of your phone\t:\t" ;
         while(1)
       {
        cin>>rom;
            if(rom>0)
           {
               break;
           }
           cout<<endl<< "\tPlease enter valid rom\t:\t";
       }
       cout << endl<< "\tEnter Battery[in mah] of your phone\t:\t" ;
         while(1)
       {
        cin>>mahbattery;
            if(mahbattery>0)
           {
               break;
           }
           cout<<endl<< "\tPlease enter valid Battery size\t:\t";
       }
        cout << endl<< "\tEnter your product's price\t:\t" ;
        cin>>price;
        cout << endl<< "\tWould you like to give any other description about your mobile phone\t:\t" ;
        getline(cin>>ws,description);
     }
      void display ()
     {
        display_owner_name();
        display_company_name();
        display_model_name();
        display_buy_year();
        display_owner_num();
        cout << endl;
        cout << "\tRAM\t\t:\t" << get_ram() << " GB"<< endl;
        cout << endl;
        cout << "\tROM\t\t:\t" << get_rom() << " GB"<< endl;
        cout << endl;
        cout << "\tBattery\t\t:\t" << get_mahbattery() << " mah"<< endl;
        display_price();
        display_description();
     }
};

class wristwatch : public all_items , public tech_class
{
    string  digital_analog;
 public:
     string get_digital_analog()
     {
        return digital_analog;
     }
    void set_digital_analog(string b)
     {
        digital_analog = b;
     }

    static void file_save(wristwatch *w,int watch_count)
    {
        ofstream save;
        save.open("watch.txt");
        save<<watch_count;
        int i=0;
        for(i=0;i<watch_count;i++)
        {
            save<<w[i].owner_name<<endl
                <<w[i].owner_index
                <<w[i].company_name<<endl
                <<w[i].sold
                <<w[i].model_name<<endl
                <<w[i].buy_year
                <<w[i].digital_analog<<endl
                <<w[i].price
                <<w[i].description<<endl;
        }
        save.close();
    }

    int take_file(wristwatch *w)
    {
        ifstream take;
        take.open("watch.txt");
        int watch_count;
        take>>watch_count;
       // u = new user[count];
        int i=0;
        while(!take.eof())
        {
            getline(take,w[i].owner_name);
            take>>w[i].owner_index;
            getline(take,w[i].company_name);
            take>>w[i].sold;
            getline(take,w[i].model_name);
            take>>w[i].buy_year;
            getline(take,w[i].digital_analog);
            take>>w[i].price;
            getline(take,w[i].description);
            i++;
        }
        return watch_count;
    }

     void get_data()
     {
        cout<<endl << "\t\tWrist Watch :-"<<endl<<endl;
        cout << endl<< "\tEnter Company name\t:\t" ;
        getline(cin>>ws,company_name);
        cout << endl<< "\tEnter model name\t:\t" ;
        getline(cin>>ws,model_name);
        cout << endl<< "\tYear of buying\t:\t" ;
        cin>>buy_year;
        cout<<endl<< "\t[digital or analog]\t:\t";
        while(1)
        {
            getline(cin>>ws,digital_analog);
            if(digital_analog == "digital" || digital_analog == "analog")
            {
                break;
            }
            cout<<endl<< "\tEnter valid input\t:\t";
        }
        cout << endl<< "\tEnter your product's price\t:\t" ;
        cin>>price;
        cout << endl<< "\tWould you like to give any other description about your Watch\t:\t" ;
        getline(cin>>ws,description);
     }
     void display ()
     {
        display_owner_name();
        display_company_name();
        display_model_name();
        display_buy_year();
        cout <<endl<< "\t Watch type\t:\t"<<digital_analog<< endl;
        display_price();
        display_description();
     }
};


