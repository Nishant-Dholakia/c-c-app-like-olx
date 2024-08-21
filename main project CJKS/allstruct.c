#include <stdio.h>
#include <string.h>
#include <ctype.h>
typedef struct//admin
{
    unsigned int revenue;
    char admin_name[5];
    char admin_password[9];
}admin;
admin a1 = {0,"CEA3","CEA3_123"};
//    printf("%d,%s,%s",a1.revenue,a1.admin_name,a1.admin_password);
void incr_revenue(int price)
{
    if(price < 1000000)
        a1.revenue += (unsigned)price * 0.03;
    else
        a1.revenue += 30000;
}

typedef struct//user class
{
    char username[20];
    char mobilenumber[11];
    char emailid[30];
    char password[9];
    unsigned buy_count;
    unsigned sell_count;
}user;
user u[100];
int user_count = 0;
void display_userinfo(int user_no)
{
    printf("\n\n\t Username\t:\t %s \n", u[user_no].username);
    printf("\n\t Mobile Number\t:\t%s\n",u[user_no].mobilenumber);
    printf("\n\t email id\t:\t%s\n",u[user_no].emailid);
    return;
}

typedef struct//allitems
{
    char owner_name[200];
    int owner_index;//the index of owner as per user class
    int buy_year;
    unsigned long int price;
    char description[500];
    int owner_num;//which number of owner of product
    short sold;
}all_items;

typedef struct//books
{
    all_items ai;
    char book_name[100];
    char author[100];
    char content_type[50];
    int num_pages;
    int publish_year;
}book;
book book1[100];
int book_count = 0;
    book get_data_book(book tbook)
    {
        printf("\n\t\tBook :-\n\n");
        printf("\n\tEnter Book name\t\t:\t");
        gets(tbook.book_name);
        printf("\n\tEnter Author name\t:\t");
        gets(tbook.author);
        printf("\n\tEnter Content type\t:\t");
        gets(tbook.content_type);
        printf("\n\tEnter Publish year\t:\t");
        scanf("%d",&tbook.publish_year);
        printf("\n\tEnter buying year of book\t:\t");
        scanf("%d",&tbook.ai.buy_year);
        printf("\n\tEnter Number of pages\t:\t");
        scanf("%d",&tbook.num_pages);
        printf("\n\tEnter price of the book\t:\t");
        scanf("%lu",&tbook.ai.price);
        printf("\n\tEnter number of Owners (previous owners including you)\t:\t");
        scanf("%d",&tbook.ai.owner_num);
        getchar();
        printf("\n\tAdd description about your book\t:\t");
        gets(tbook.ai.description);
        return tbook;
    }
    void display_book(book tbook)
    {
        printf("\n\tOwner name\t:\t%s",tbook.ai.owner_name);
        printf("\n\tBook name\t:\t%s",tbook.book_name);
        printf("\n\tAuthor\t\t:\t%s",tbook.author);
        printf("\n\tContent type\t:\t%s",tbook.content_type);
        printf("\n\tPublishing year\t:\t%d",tbook.publish_year);
        printf("\n\tBuying year\t:\t%d",tbook.ai.buy_year);
        printf("\n\tTotal pages\t:\t%d",tbook.num_pages);
        printf("\n\tPrice\t\t:\t%lu",tbook.ai.price);
        printf("\n\tOwner number\t:\t%d",tbook.ai.owner_num);
        printf("\n\tDescription\t:\t%s",tbook.ai.description);
    }

typedef struct//tech_class
{
    all_items ai;
    char company_name[50];
    char model_name[50];
    char color[20];
}tech;

typedef struct//bike
{
    tech t;
    double  travel_km;
    char numberplate[20];
    char drive_type[15];
}bike;
bike bike1[100];
int bike_count=0;
    bike get_data_bike(bike tbike)
    {
        printf("\n\t\tBike :-\n");
        printf("\n\tEnter Company name\t:\t");
        gets(tbike.t.company_name);
        printf("\n\tEnter bike name\t:\t") ;
        gets(tbike.t.model_name);
        printf("\n\tYear of buying\t:\t");
        scanf("%d",&tbike.t.ai.buy_year);
        printf("\n\tK.M. traveled\t:\t") ;
        scanf("%d",&tbike.travel_km);
        getchar();
        printf("\n\tEnter number plate\t:\t") ;
        while(1)
        {
            gets(tbike.numberplate);
            if(isdigit(tbike.numberplate[0]) || isdigit(tbike.numberplate[1]))
                printf("\n\tEnter valid numberplate\t:\t");
            else
                break;
        }
        printf("\n\tDrive type (electric or fuel)\t:\t") ;
        while(1)// to validate drive type
        {
            gets(tbike.drive_type);
            if(!strcmp(tbike.drive_type,"electric") || !strcmp(tbike.drive_type,"fuel"))
                break;
            printf("\n\tEnter valid drive type\t:\t");
        }
        printf("\n\tWhich owner are you? [1/2/...]\t:\t");
       while(1)// number of owners cannot be negative
       {
            scanf("%d",&tbike.t.ai.owner_num);
            if(tbike.t.ai.owner_num<1)
            {
                printf("\n\tEnter valid owner number\t:\t");
                continue;
            }
            break;
       }
       getchar();
        printf("\n\tEnter color\t:\t");
        gets(tbike.t.color);
        printf("\n\tEnter your vehicle's price\t:\t") ;
        scanf("%lu",&tbike.t.ai.price);
        getchar();
        printf("\n\tWould you like to give any other description about your vehicle\t:\t") ;
        gets(tbike.t.ai.description);
        return tbike;
    }
    void display_bike (bike tbike)
    {
        printf("\n\n\tOwner name\t\t:\t%s\n",tbike.t.ai.owner_name);
        printf("\n\tCompany name\t\t:\t%s\n",tbike.t.company_name);
        printf("\n\tModel name\t\t:\t%s\n",tbike.t.model_name);
        printf("\n\tBuy year\t\t:\t%d\n",tbike.t.ai.buy_year);
        printf("\n\tPrice\t\t\t:\t%d\n",tbike.t.ai.price);
        printf("\n\tTravel(Km)\t\t:\t%d\n",tbike.travel_km);
        printf("\n\tNumber Plate\t\t:\t%s\n",tbike.numberplate);
        printf("\n\tDrive type\t\t:\t%s\n",tbike.drive_type);
        printf("\n\tOwner number\t\t:\t%d\n",tbike.t.ai.owner_num);
        printf("\n\tColor\t\t\t:\t%s\n",tbike.t.color);
        printf("\n\tDescription\t\t:\t%s\n",tbike.t.ai.description);
    }

typedef struct//car class
{
    bike bike1;
    char fuel_type[15];
}car;
car car1[100];
int car_count = 0;
    car get_data_car(car tcar)
    {
        printf("\n\t\tCar :-\n");
        printf("\n\tCompany name\t:\t");
        gets(tcar.bike1.t.company_name);
        printf("\n\tCar name\t:\t") ;
        gets(tcar.bike1.t.model_name);
        printf("\n\tYear of buying\t:\t");
        scanf("%d",&tcar.bike1.t.ai.buy_year);
        printf("\n\tK.M. traveled\t:\t") ;
        scanf("%d",&tcar.bike1.travel_km);
        getchar();
        printf("\n\tEnter number plate\t:\t") ;
        while(1)
        {
            gets(tcar.bike1.numberplate);
            if(isdigit(tcar.bike1.numberplate[0]) || isdigit(tcar.bike1.numberplate[1]))
                printf("\n\tEnter valid numberplate\t:\t");
            else
                break;
        }
        while(1)// to check if drive type and fuel type are matching or not
        {
            printf("\n\tDrive type (electric or fuel)\t:\t") ;
            while(1)// to validate drive type
            {
                gets(tcar.bike1.drive_type);
                if(!strcmp(tcar.bike1.drive_type,"electric") || !strcmp(tcar.bike1.drive_type,"fuel"))
                    break;
                printf("\n\tEnter valid drive type\t:\t");
            }
            printf("\n\tFuel  type (Enter battery if electric / petrol/diesel/cng)\t:\t") ;
            while(1)// to validate fuel type
            {
                gets(tcar.fuel_type);
            if(!strcmp(tcar.fuel_type,"battery") || !strcmp(tcar.fuel_type,"petrol") || !strcmp(tcar.fuel_type,"diesel")
                || !strcmp(tcar.fuel_type,"cng"))
                    break;
                printf("\n\tEnter valid fuel type\t:\t");
            }
            // to check the matching
            if((!strcmp(tcar.bike1.drive_type,"electric") && strcmp(tcar.fuel_type,"battery")) ||
               (!strcmp(tcar.bike1.drive_type,"fuel") && !strcmp(tcar.fuel_type,"battery")))
            {
                printf("\n\tPlease enter valid entry in fuel section...");
            }
            else
                break;
        }
        printf("\n\tWhich owner are you? [1/2/...]\t:\t");
       while(1)// number of owners cannot be negative
       {
            scanf("%d",&tcar.bike1.t.ai.owner_num);
            if(tcar.bike1.t.ai.owner_num<1)
            {
                printf("\n\tEnter valid owner number\t:\t");
                continue;
            }
            break;
       }
       getchar();
        printf("\n\tEnter color\t:\t");
        gets(tcar.bike1.t.color);
        printf("\n\tEnter your vehicle's price\t:\t") ;
        scanf("%lu",&tcar.bike1.t.ai.price);
        getchar();
        printf("\n\tWould you like to give any other description about your vehicle\t:\t") ;
        gets(tcar.bike1.t.ai.description);
        return tcar;
    }
    void display_car (car tcar)
    {
        printf("\n\n\tOwner name\t\t:\t%s\n",tcar.bike1.t.ai.owner_name);
        printf("\n\tCompany name\t\t:\t%s\n",tcar.bike1.t.company_name);
        printf("\n\tModel name\t\t:\t%s\n",tcar.bike1.t.model_name);
        printf("\n\tBuy year\t\t:\t%d\n",tcar.bike1.t.ai.buy_year);
        printf("\n\tPrice\t\t\t:\t%d\n",tcar.bike1.t.ai.price);
        printf("\n\tTravel(Km)\t\t:\t%d\n",tcar.bike1.travel_km);
        printf("\n\tNumber Plate\t\t:\t%s\n",tcar.bike1.numberplate);
        printf("\n\tDrive type\t\t:\t%s\n",tcar.bike1.drive_type);
        printf("\n\tFuel type\t\t:\t%s\n",tcar.fuel_type);
        printf("\n\tOwner number\t\t:\t%d\n",tcar.bike1.t.ai.owner_num);
        printf("\n\tColor\t\t\t:\t%s\n",tcar.bike1.t.color);
        printf("\n\tDescription\t\t:\t%s\n",tcar.bike1.t.ai.description);
    }

    typedef struct//electricappliances
    {
        tech t;
        char product_name[50];
    }electricappliances;
electricappliances electric1[100];
int electric_count = 0;
    electricappliances get_data_electric(electricappliances telectric)
    {
        printf("\n\n\t\tElectric Appliance :-\n\n");
        printf("\n\tEnter product name\t:\t") ;
        gets(telectric.product_name);
        printf("\n\tEnter Company name\t:\t") ;
        gets(telectric.t.company_name);
        printf("\n\tEnter model name\t:\t") ;
        gets(telectric.t.model_name);
        printf("\n\tYear of buying\t\t:\t") ;
        scanf("%d",&telectric.t.ai.buy_year);
        printf("\n\tWhich owner are you? [1/2/...]\t:\t");
       while(1)
       {
        scanf("%d",&telectric.t.ai.owner_num);
        if(telectric.t.ai.owner_num<1)
        {
            printf("\n\tEnter valid owner number\t:\t");
            continue;
        }
        break;
       }
        printf("\n\tEnter your product's price\t:\t") ;
        scanf("%lu",&telectric.t.ai.price);
        getchar();
        printf("\n\tWould you like to give any other description about your product\t:\t") ;
        gets(telectric.t.ai.description);
        return telectric;
    }

    void display_electric(electricappliances telectric)
    {
        printf("\n\n\tOwner name\t:\t%s\n",telectric.t.ai.owner_name);
        printf("\n\tProduct Name\t:\t%s\n",telectric.product_name);
        printf("\n\tCompany Name\t:\t%s\n",telectric.t.company_name);
        printf("\n\tModel Name\t:\t%s\n",telectric.t.model_name);
        printf("\n\tPrice\t\t:\t%lu\n",telectric.t.ai.price);
        printf("\n\tBuy Year\t:\t%d\n",telectric.t.ai.buy_year);
        printf("\n\tOwner number\t:\t%d\n",telectric.t.ai.owner_num);
        printf("\n\tDescription\t:\t%s\n",telectric.t.ai.description);
    }

typedef struct//mobile
{
    tech t;
    int ram;
    int rom;
    int mahbattery;
}mobile;
mobile mobile1[100];
int mobile_count = 0;
mobile get_data_mobile(mobile tmobile)
     {
        printf("\n\n\t\tMobile :-\n\n");
        printf("\n\tEnter Company name\t:\t") ;
        gets(tmobile.t.company_name);
        printf("\n\tEnter model name\t:\t") ;
        gets(tmobile.t.model_name);
        printf("\n\tYear of buying\t\t:\t") ;
        scanf("%d",&tmobile.t.ai.buy_year);
        printf("\n\tWhich owner are you? [1/2/...]\t:\t");
       while(1)
       {
        scanf("%d",&tmobile.t.ai.owner_num);
        if(tmobile.t.ai.owner_num>0)
        {
        break;
        }
        printf("\n\tEnter valid owner number\t:\t");
       }
       printf("\n\tEnter RAM[in GB] of your phone\t:\t") ;
       while(1)
       {
       scanf("%d",&tmobile.ram);
            if(tmobile.ram>0)
            {
                break;
            }
           printf("\n\tPlease enter valid ram\t:\t");
       }
       printf("\n\tEnter ROM[in GB] of your phone\t:\t") ;
         while(1)
       {
        scanf("%d",&tmobile.rom);
            if(tmobile.rom>0)
           {
               break;
           }
           printf("\n\tPlease enter valid ROM\t:\t");
       }
       printf("\n\tEnter Battery[in mah] of your phone\t:\t") ;
         while(1)
       {
        scanf("%d",&tmobile.mahbattery);
            if(tmobile.mahbattery>0)
           {
               break;
           }
           printf("\n\tPlease enter valid Battery size\t:\t");
       }
        printf("\n\tEnter your product's price\t:\t") ;
        scanf("%lu",&tmobile.t.ai.price);
        getchar();
        printf("\n\tWould you like to give any other description about your mobile phone\t:\t") ;
        gets(tmobile.t.ai.description);
        return tmobile;
     }
      void display_mobile(mobile tmobile)
     {
        printf("\n\tOwner name\t\t:\t%s\n",tmobile.t.ai.owner_name);
        printf("\n\tCompany name\t\t:\t%s\n",tmobile.t.company_name);
        printf("\n\tModel name\t\t:\t%s\n",tmobile.t.model_name);
        printf("\n\tBuy year\t\t:\t%d\n",tmobile.t.ai.buy_year);
        printf("\n\tRAM\t\t\t:\t%d GB\n",tmobile.ram);
        printf("\n\tROM\t\t\t:\t%d GB\n",tmobile.rom);
        printf("\n\tBattery [in mah]\t:\t%d MAH\n",tmobile.mahbattery);
        printf("\n\tOwner number\t\t:\t%d",tmobile.t.ai.owner_num);
        printf("\n\tPrice\t\t\t:\t%lu\n",tmobile.t.ai.price);
        printf("\n\tDescription\t\t:\t%s\n",tmobile.t.ai.description);
     }

typedef struct//Writs watch
{
    tech t;
    char digital_analog[8];
}watch;
watch watch1[100];
int watch_count = 0;
watch get_data_watch(watch twatch)
     {
        printf("\n\n\t\tWrist Watch :-\n\n");
        printf("\n\tEnter Company name\t:\t") ;
        gets(twatch.t.company_name);
        printf("\n\tEnter model name\t:\t") ;
        gets(twatch.t.model_name);
        printf("\n\tYear of buying\t\t:\t") ;
        scanf("%d",&twatch.t.ai.buy_year);
        getchar();
        printf("\n\tWatch type[digital or analog]\t:\t");
        while(1)
        {
            gets(twatch.digital_analog);
            puts(twatch.digital_analog);
            if(!strcmp(twatch.digital_analog,"digital") || !strcmp(twatch.digital_analog,"analog"))
            {
                break;
            }
            printf("\n\tEnter valid input\t:\t");
        }
        printf("\n\tEnter your product's price\t:\t") ;
        scanf("%lu",&twatch.t.ai.price);
        getchar();
        printf("\n\tWould you like to give any other description about your Watch\t:\t") ;
        gets(twatch.t.ai.description);
        return twatch;
     }
     void display_watch(watch twatch)
     {
        printf("\n\tOwner name\t:\t%s\n",twatch.t.ai.owner_name);
        printf("\n\tCompany name\t:\t%s\n",twatch.t.company_name);
        printf("\n\tModel name\t:\t%s\n",twatch.t.model_name);
        printf("\n\tBuy Year\t:\t%d\n",twatch.t.ai.buy_year);
        printf("\n\tWatch type\t:\t%s\n",twatch.digital_analog);
        printf("\n\tPrice\t\t:\t%lu\n",twatch.t.ai.price);
        printf("\n\tDescription\t:\t%s\n",twatch.t.ai.description);
     }

    /*

int main()
{
    printf("Done bro\n");
    book1[0] = get_data_book(book1[0]);
    display_book(book1[0]);
    watch1[0] = get_data_watch(watch1[0]);
    display_watch(watch1[0]);
    car1[0] = get_data_car(car1[0]);
    display_car(car1[0]);
    bike1[0] = get_data_bike(bike1[0]);
    display_bike(bike1[0]);
    electric1[0] = get_data_electric(electric1[0]);
    display_electric(electric1[0]);
    mobile1[0] = get_data_mobile(mobile1[0]);
    display_mobile(mobile1[0]);
    return 0;
}
    */


