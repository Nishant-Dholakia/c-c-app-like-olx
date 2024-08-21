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

void incr_revenue(int price)
{
    if(price < 1000000)
        a1.revenue += (unsigned)price * 0.03;
    else
        a1.revenue += 30000;
}

void admin_file_save(admin a)
{
    FILE *fptr;
    fptr = fopen("admin.txt","w");
    fprintf(fptr,"%d",a.revenue);
    fclose(fptr);
}
admin admin_take_file(admin a)
{
    FILE *fptr;
    fptr = fopen("admin.txt","r");
    fscanf(fptr,"%d",&a.revenue);
    fclose(fptr);
    return a;
}

typedef struct//user class
{
    char username[50];
    char mobilenumber[11];
    char emailid[50];
    char password[10];
    unsigned buy_count;
    unsigned sell_count;
}user;
user u[100];
int count = 0;

void user_file_save(user *u,int count)
    {
        FILE *fptr;
        fptr = fopen("user.txt","w");
        fprintf(fptr,"%d\n",count);
        int i=0;
        for(i=0;i<count;i++)
        {
            fprintf(fptr,"%d\n%d%s\n%s\n%s\n%s\n",u[i].buy_count,u[i].sell_count,u[i].username,u[i].mobilenumber,
                   u[i].emailid,u[i].password);
        }
        fclose(fptr);
    }
    int user_take_file(user *u)
    {
        FILE *fptr;
        fptr = fopen("user.txt","r");
        int count;
        fscanf(fptr,"%d",&count);
        int i=0;
        while(i < count)
        {
        fscanf(fptr,"%d%*c%d",&u[i].buy_count,&u[i].sell_count);
          fgets(u[i].username  ,sizeof(u[i].username) , fptr);
          fgets(u[i].mobilenumber  ,sizeof(u[i].mobilenumber) , fptr);
         fscanf(fptr,"%*c");
          fgets(u[i].emailid  ,sizeof(u[i].emailid) , fptr);
          fgets(u[i].password  ,sizeof(u[i].password) , fptr);

          u[i].username[strlen(u[i].username) - 1] = '\0';
          u[i].mobilenumber[strlen(u[i].mobilenumber) - 1] = '\0';
          u[i].emailid[strlen(u[i].emailid) - 1] = '\0';
          u[i].password[strlen(u[i].password) - 1] = '\0';
          printf("buy - %d\n\nsell - %d\n\nuser - %s\n\nmobile - %s\n\nemailid - %s\n\npass - %s\n\n\n\n" ,
                   u[i].buy_count,u[i].sell_count,u[i].username,u[i].mobilenumber,u[i].emailid,u[i].password );
            i++;
        }
        getchar();
        system("cls");
        return count;
    }

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


void book_file_save(book *b,int count)
    {
        FILE *fptr;
        fptr = fopen("book.txt","w");
        fprintf(fptr,"%d",count);
        int i=0;
        for(i=0;i<count;i++)
        {
            fprintf(fptr,"%s\n%d%s\n%d%s\n%s\n%d\n%d\n%d\n%u\n%d%s\n",b[i].ai.owner_name,b[i].ai.owner_index,
                    b[i].book_name,b[i].ai.sold,b[i].author,b[i].content_type,
                   b[i].publish_year,b[i].ai.buy_year,b[i].num_pages,b[i].ai.price,b[i].ai.owner_num,b[i].ai.description);
        }
        fclose(fptr);
    }

    int book_take_file(book *b)
    {
        FILE *fptr;
        fptr = fopen("book.txt","r");
        int count;
        fscanf(fptr,"%d",&count);
        int i=0;
        while(i < count)
        {
            fgets(b[i].ai.owner_name,sizeof(b[i].ai.owner_name) , fptr);
            fscanf(fptr,"%d",&b[i].ai.owner_index);
            fgets(b[i].book_name,sizeof(b[i].book_name) , fptr);
            fscanf(fptr,"%d",&b[i].ai.sold);
            fgets(b[i].author,sizeof(b[i].author) , fptr);
            fgets(b[i].content_type,sizeof(b[i].content_type) , fptr);
            fscanf(fptr,"%d",&b[i].publish_year);
            fscanf(fptr,"%d",&b[i].ai.buy_year);
            fscanf(fptr,"%d",&b[i].num_pages);
            fscanf(fptr,"%u",&b[i].ai.price);
            fscanf(fptr,"%d",&b[i].ai.owner_num);
            fgets(b[i].ai.description,sizeof(b[i].ai.description) , fptr);

            b[i].ai.owner_name[strlen(b[i].ai.owner_name) - 1] = '\0';
            b[i].book_name[strlen(b[i].book_name) - 1] = '\0';
            b[i].author[strlen(b[i].author) - 1] = '\0';
            b[i].content_type[strlen(b[i].content_type) - 1] = '\0';
            b[i].ai.description[strlen(b[i].ai.description) - 1] = '\0';
            //  printf("buy - %d\n\nsell - %d\n\nuser - %s\n\nmobile - %s\n\nemailid - %s\n\npass - %s\n\n\n\n" ,
            //   u[i].buy_count,u[i].sell_count,u[i].username,u[i].mobilenumber,u[i].emailid,u[i].password );
            i++;
        }

        return count;
    }

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


void bike_file_save(bike *b,int count)
    {
        FILE *fptr;
        fptr = fopen("bike.txt","w");
        fprintf(fptr,"%d",count);
        int i=0;
        for(i=0;i<count;i++)
        {
            fprintf(fptr,"%s\n%d%s\n%d%s\n%d\n%d%s\n%s\n%d%s\n%u%s\n",b[i].t.ai.owner_name,b[i].t.ai.owner_index,
                    b[i].t.company_name,b[i].t.ai.sold,b[i].t.model_name,b[i].t.ai.buy_year,
                   b[i].travel_km,b[i].numberplate,b[i].drive_type,b[i].t.ai.owner_num,b[i].t.color,
                   b[i].t.ai.price,b[i].t.ai.description);
        }
        fclose(fptr);
    }

    int bike_take_file(bike *b)
    {
        FILE *fptr;
        fptr = fopen("bike.txt","r");
        int count;
        fscanf(fptr,"%d",&count);
        int i=0;
        while(i < count)
        {
            fgets(b[i].t.ai.owner_name,sizeof(b[i].t.ai.owner_name) , fptr);
            fscanf(fptr,"%d",&b[i].t.ai.owner_index);
            fgets(b[i].t.company_name,sizeof(b[i].t.company_name) , fptr);
            fscanf(fptr,"%d",&b[i].t.ai.sold);
            fgets(b[i].t.model_name,sizeof(b[i].t.model_name) , fptr);
            fscanf(fptr,"%d",&b[i].t.ai.buy_year);
            fscanf(fptr,"%d",&b[i].travel_km);
            fgets(b[i].numberplate,sizeof(b[i].numberplate) , fptr);
            fgets(b[i].drive_type,sizeof(b[i].drive_type) , fptr);
            fscanf(fptr,"%d",&b[i].t.ai.owner_num);
            fgets(b[i].t.color,sizeof(b[i].t.color) , fptr);
            fscanf(fptr,"%u",&b[i].t.ai.price);
            fgets(b[i].t.ai.description,sizeof(b[i].t.ai.description) , fptr);

            b[i].t.ai.owner_name[strlen(b[i].t.ai.owner_name) - 1] = '\0';
            b[i].t.company_name[strlen(b[i].t.company_name) - 1] = '\0';
            b[i].t.model_name[strlen(b[i].t.model_name) - 1] = '\0';
            b[i].numberplate[strlen(b[i].numberplate) - 1] = '\0';
            b[i].drive_type[strlen(b[i].drive_type) - 1] = '\0';
            b[i].t.color[strlen(b[i].t.color) - 1] = '\0';
            b[i].t.ai.description[strlen(b[i].t.ai.description) - 1] = '\0';
            //  printf("buy - %d\n\nsell - %d\n\nuser - %s\n\nmobile - %s\n\nemailid - %s\n\npass - %s\n\n\n\n" ,
            //   u[i].buy_count,u[i].sell_count,u[i].username,u[i].mobilenumber,u[i].emailid,u[i].password );
            i++;
        }
        return count;
    }
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


void car_file_save(car *c,int count)
    {
        FILE *fptr;
        fptr = fopen("car.txt","w");
        fprintf(fptr,"%d",count);
        int i=0;
        for(i=0;i<count;i++)
        {
            fprintf(fptr,"%s\n%d%s\n%d%s\n%d\n%d%s\n%s\n%s\n%d%s\n%u%s\n",c[i].bike1.t.ai.owner_name,c[i].bike1.t.ai.owner_index,
                    c[i].bike1.t.company_name,c[i].bike1.t.ai.sold,c[i].bike1.t.model_name,c[i].bike1.t.ai.buy_year,
                   c[i].bike1.travel_km,c[i].bike1.numberplate,c[i].bike1.drive_type,c[i].fuel_type,c[i].bike1.t.ai.owner_num,
                   c[i].bike1.t.color,c[i].bike1.t.ai.price,c[i].bike1.t.ai.description);
        }
        fclose(fptr);
    }

    int car_take_file(car *c)
    {
        FILE *fptr;
        fptr = fopen("car.txt","r");
        int count;
        fscanf(fptr,"%d",&count);
        int i=0;
        while(i < count)
        {
            fgets(c[i].bike1.t.ai.owner_name,sizeof(c[i].bike1.t.ai.owner_name) , fptr);
            fscanf(fptr,"%d",&c[i].bike1.t.ai.owner_index);
            fgets(c[i].bike1.t.company_name,sizeof(c[i].bike1.t.company_name) , fptr);
            fscanf(fptr,"%d",&c[i].bike1.t.ai.sold);
            fgets(c[i].bike1.t.model_name,sizeof(c[i].bike1.t.model_name) , fptr);
            fscanf(fptr,"%d",&c[i].bike1.t.ai.buy_year);
            fscanf(fptr,"%d",&c[i].bike1.travel_km);
            fgets(c[i].bike1.numberplate,sizeof(c[i].bike1.numberplate) , fptr);
            fgets(c[i].bike1.drive_type,sizeof(c[i].bike1.drive_type) , fptr);
            fgets(c[i].fuel_type,sizeof(c[i].fuel_type) , fptr);
            fscanf(fptr,"%d",&c[i].bike1.t.ai.owner_num);
            fgets(c[i].bike1.t.color,sizeof(c[i].bike1.t.color) , fptr);
            fscanf(fptr,"%u",&c[i].bike1.t.ai.price);
            fgets(c[i].bike1.t.ai.description,sizeof(c[i].bike1.t.ai.description) , fptr);

            c[i].bike1.t.ai.owner_name[strlen(c[i].bike1.t.ai.owner_name) - 1] = '\0';
            c[i].bike1.t.company_name[strlen(c[i].bike1.t.company_name) - 1] = '\0';
            c[i].bike1.t.model_name[strlen(c[i].bike1.t.model_name) - 1] = '\0';
            c[i].bike1.numberplate[strlen(c[i].bike1.numberplate) - 1] = '\0';
            c[i].bike1.drive_type[strlen(c[i].bike1.drive_type) - 1] = '\0';
            c[i].fuel_type[strlen(c[i].fuel_type) - 1] = '\0';
            c[i].bike1.t.color[strlen(c[i].bike1.t.color) - 1] = '\0';
            c[i].bike1.t.ai.description[strlen(c[i].bike1.t.ai.description) - 1] = '\0';
            //  printf("buy - %d\n\nsell - %d\n\nuser - %s\n\nmobile - %s\n\nemailid - %s\n\npass - %s\n\n\n\n" ,
            //   u[i].buy_count,u[i].sell_count,u[i].username,u[i].mobilenumber,u[i].emailid,u[i].password );
            i++;
        }
        return count;
    }
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


void electric_file_save(electricappliances *e,int count)
    {
        FILE *fptr;
        fptr = fopen("electric.txt","w");
        fprintf(fptr,"%d",count);
        int i=0;
        for(i=0;i<count;i++)
        {
            fprintf(fptr,"%s\n%d%s\n%d%s\n%s\n%d\n%d\n%u%s\n",e[i].t.ai.owner_name,e[i].t.ai.owner_index,
                    e[i].product_name,e[i].t.ai.sold,e[i].t.company_name,e[i].t.model_name,e[i].t.ai.buy_year,
                   e[i].t.ai.owner_num,e[i].t.ai.price,e[i].t.ai.description);
        }
        fclose(fptr);
    }

    int electric_take_file(electricappliances *e)
    {
        FILE *fptr;
        fptr = fopen("electric.txt","r");
        int count;
        fscanf(fptr,"%d",&count);
        int i=0;
        while(i < count)
        {
            fgets(e[i].t.ai.owner_name,sizeof(e[i].t.ai.owner_name) , fptr);
            fscanf(fptr,"%d",&e[i].t.ai.owner_index);
            fgets(e[i].product_name,sizeof(e[i].product_name) , fptr);
            fscanf(fptr,"%d",&e[i].t.ai.sold);
            fgets(e[i].t.company_name,sizeof(e[i].t.company_name) , fptr);
            fgets(e[i].t.model_name,sizeof(e[i].t.model_name) , fptr);
            fscanf(fptr,"%d",&e[i].t.ai.buy_year);
            fscanf(fptr,"%d",&e[i].t.ai.owner_num);
            fscanf(fptr,"%u",&e[i].t.ai.price);
            fgets(e[i].t.ai.description,sizeof(e[i].t.ai.description) , fptr);

            e[i].t.ai.owner_name[strlen(e[i].t.ai.owner_name) - 1] = '\0';
            e[i].product_name[strlen(e[i].product_name) - 1] = '\0';
            e[i].t.company_name[strlen(e[i].t.company_name) - 1] = '\0';
            e[i].t.model_name[strlen(e[i].t.model_name) - 1] = '\0';
            e[i].t.ai.description[strlen(e[i].t.ai.description) - 1] = '\0';
            //  printf("buy - %d\n\nsell - %d\n\nuser - %s\n\nmobile - %s\n\nemailid - %s\n\npass - %s\n\n\n\n" ,
            //   u[i].buy_count,u[i].sell_count,u[i].username,u[i].mobilenumber,u[i].emailid,u[i].password );
            i++;
        }
        return count;
    }

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
        printf("\n\tPrice\t\t:\t%u\n",telectric.t.ai.price);
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


void mobile_file_save(mobile *m,int count)
    {
        FILE *fptr;
        fptr = fopen("mobile.txt","w");
        fprintf(fptr,"%d",count);
        int i=0;
        for(i=0;i<count;i++)
        {
            fprintf(fptr,"%s\n%d%s\n%d%s\n%d\n%d\n%d\n%d\n%d\n%u%s\n",m[i].t.ai.owner_name,m[i].t.ai.owner_index,
                    m[i].t.company_name,m[i].t.ai.sold,m[i].t.model_name,m[i].t.ai.buy_year,
                   m[i].t.ai.owner_num,m[i].ram,m[i].rom,m[i].mahbattery,m[i].t.ai.price,m[i].t.ai.description);
        }
        fclose(fptr);
    }


    int mobile_take_file(mobile *m)
    {
        FILE *fptr;
        fptr = fopen("mobile.txt","r");
        int count;
        fscanf(fptr,"%d",&count);
        int i=0;
        while(i < count)
        {
            fgets(m[i].t.ai.owner_name,sizeof(m[i].t.ai.owner_name) , fptr);
            fscanf(fptr,"%d",&m[i].t.ai.owner_index);
            fgets(m[i].t.company_name,sizeof(m[i].t.company_name) , fptr);
            fscanf(fptr,"%d",&m[i].t.ai.sold);
            fgets(m[i].t.model_name,sizeof(m[i].t.model_name) , fptr);
            fscanf(fptr,"%d",&m[i].t.ai.buy_year);
            fscanf(fptr,"%d",&m[i].t.ai.owner_num);
            fscanf(fptr,"%d",&m[i].ram);
            fscanf(fptr,"%d",&m[i].rom);
            fscanf(fptr,"%d",&m[i].mahbattery);
            fscanf(fptr,"%u",&m[i].t.ai.price);
            fgets(m[i].t.ai.description,sizeof(m[i].t.ai.description) , fptr);

            m[i].t.ai.owner_name[strlen(m[i].t.ai.owner_name) - 1] = '\0';
            m[i].t.company_name[strlen(m[i].t.company_name) - 1] = '\0';
            m[i].t.model_name[strlen(m[i].t.model_name) - 1] = '\0';
            m[i].t.ai.description[strlen(m[i].t.ai.description) - 1] = '\0';
            //  printf("buy - %d\n\nsell - %d\n\nuser - %s\n\nmobile - %s\n\nemailid - %s\n\npass - %s\n\n\n\n" ,
            //   u[i].buy_count,u[i].sell_count,u[i].username,u[i].mobilenumber,u[i].emailid,u[i].password );
            i++;
        }
        return count;
    }

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


void watch_file_save(watch *w,int count)
    {
        FILE *fptr;
        fptr = fopen("watch.txt","w");
        fprintf(fptr,"%d",count);
        int i=0;
        for(i=0;i<count;i++)
        {
            fprintf(fptr,"%s\n%d%s\n%d%s\n%d%s\n%u%s\n",w[i].t.ai.owner_name,w[i].t.ai.owner_index,
                    w[i].t.company_name,w[i].t.ai.sold,w[i].t.model_name,w[i].t.ai.buy_year,
                   w[i].digital_analog,w[i].t.ai.price,w[i].t.ai.description);
        }
        fclose(fptr);
    }

    int watch_take_file(watch *w)
    {
        FILE *fptr;
        fptr = fopen("watch.txt","r");
        int count;
        fscanf(fptr,"%d",&count);
        int i=0;
        while(i < count)
        {
            fgets(w[i].t.ai.owner_name,sizeof(w[i].t.ai.owner_name) , fptr);
            fscanf(fptr,"%d",&w[i].t.ai.owner_index);
            fgets(w[i].t.company_name,sizeof(w[i].t.company_name) , fptr);
            fscanf(fptr,"%d",&w[i].t.ai.sold);
            fgets(w[i].t.model_name,sizeof(w[i].t.model_name) , fptr);
            fscanf(fptr,"%d",&w[i].t.ai.buy_year);
            fgets(w[i].digital_analog,sizeof(w[i].digital_analog) , fptr);
            fscanf(fptr,"%u",&w[i].t.ai.price);
            fgets(w[i].t.ai.description,sizeof(w[i].t.ai.description) , fptr);

            w[i].t.ai.owner_name[strlen(w[i].t.ai.owner_name) - 1] = '\0';
            w[i].t.company_name[strlen(w[i].t.company_name) - 1] = '\0';
            w[i].t.model_name[strlen(w[i].t.model_name) - 1] = '\0';
            w[i].t.ai.description[strlen(w[i].t.ai.description) - 1] = '\0';
            w[i].digital_analog[strlen(w[i].digital_analog) - 1] = '\0';
            //  printf("buy - %d\n\nsell - %d\n\nuser - %s\n\nmobile - %s\n\nemailid - %s\n\npass - %s\n\n\n\n" ,
            //   u[i].buy_count,u[i].sell_count,u[i].username,u[i].mobilenumber,u[i].emailid,u[i].password );
            i++;
        }
        return count;
    }

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


