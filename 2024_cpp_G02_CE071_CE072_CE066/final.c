#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include "allstruct.c"
void signup_login_page();
unsigned int signup();
unsigned int login();
void category(int user_no);
void display_userinfo(int user_no);
void buy_or_sell(int choice,int buy_sell,int user_no);
void allinfo();



void hr()
{
    for(int i=0;i<10;i++)
        printf(" ");
    for(int i=0;i<135;i++)
        printf("*");
        printf("\n\n");
}
void company_name()
{
    printf("\n\n");
    printf("\t\t\t\t\t\t\t [ BOSSAA ] -Buy Or Sell Supplies Anytime Anywhere\n");
    printf("\t\t\t\t\t    ... ________________________________________________________________ ...");
    printf("\n");
    printf("\n\n");
}

void welcomepage(void)
{
    printf("\n\n");
    printf("\t\t\t\t\t\tWell-Come To [ BOSSAA ] -Buy Or Sell Supplies Anytime Anywhere\n");
    printf("\t\t\t\t\t    ... ________________________________________________________________ ...");
    printf("\n");
    printf("\n\n");
    printf("\t\t\t-> This Website Is Made For Fulfilling The Customer to Customer (C-C) Services.");
    printf("\n\n\t\t\t-> This Website Is Made By DDU CE Students As Their Project Of First Year -> Second Semester.");
    printf("\n\n\t\t\t-> The Contributors Of The Project Are : \n");
    printf("\n");
    printf("\n\n\t\t\tSr.No.\t\t\tFull Name\t\t\tEnrollment No.\t\t\tRoll.No.\n");
    printf("\n\n");
    printf("\t\t\t  1.\t          DHOLAKIA NISHANT ASHIT\t\t 23CEUOS037\t\t\tCE071\n\n");
    printf("\t\t\t  2.\t          DALSANIYA OMKUMAR BHAVESHBHAI\t\t 23CEUOZ029\t\t\tCE066\n\n");
    printf("\t\t\t  3.\t          DHORAJIYA GOPAL SANJAYBHAI\t\t 23CEUOF038\t\t\tCE072\n\n");
    printf("\n\n\n\t\t\tNote :  Please make sure to maximize the terminal");
    printf("\n\n\n\t\t\tPress 'Enter' to continue ...");
    getchar();
    system("cls");
    signup_login_page();
    return;
}


int cin_validate(int s, int e)
{
    int choice;
    while (1) {
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("\n\t\t\tEnter valid input : ");
            continue;
        }
        if (choice >= s && choice <= e)
            break;
        else
            printf("\n\t\t\tEnter valid input : ");
    }
    return choice;
}

void hidepass(char* password)
{
    char ch;
    int i = 0;

    while ((ch = getch()) != 13)
    { // Read characters until Enter (ASCII 13) is pressed
        if (ch == '\b')
        { // Handle backspace
            if (i > 0)
            {
                printf("\b \b");    // Erase the last character from console
                password[--i] = '\0'; // Remove the last character from the password
            }
        }
        else
        {
            if (i < 8)
            { // password length doesn't exceed 8 characters
                password[i++] = ch; // put the character to the password
                printf("*"); // Print asterisks (*) instead of the actual characters
            }
        }
    }
    printf("\n");

    if (i != 8)
    {
        printf("\n\t\t\tEnter an 8-character valid password : ");
        return ;
    }
    else
    {
        for (int j = 0; j < i; j++)
        {
            if (password[j] == ' ')
            {
                printf("\n\t\t\tPassword cannot contain blank space");
                printf("\n\t\t\tEnter valid password : ");
            }
        }
    }
    password[8]='\0';
}

int revenue_page()
{
    company_name();
    printf("\n\n");
    printf("\t\t\t\tFor the product you sell , the brokerage of minimum amount from 3%c of the total cost of your product",'%');
    printf("\n\t\t\t\t or Rs. 30,000 will be deducted from your account");
    printf("\n\n\n\t\t\t\tPress 1. if you are interested \n\t\t\t\tPress 2. to go back\n\n\t\t\t\tEnter your choice : ");
        int choice;
        choice = cin_validate(1,2);
        getchar();
    system("cls");
    return choice;
}

void file_save()
{
    admin_file_save(a1);
    user_file_save(u,count);
    book_file_save(book1,book_count);
    bike_file_save(bike1,bike_count);
    car_file_save(car1,car_count);
    electric_file_save(electric1,electric_count);
    mobile_file_save(mobile1,mobile_count);
    watch_file_save(watch1,watch_count);
    /*
    */
    return;
}

void take_file()
{
    a1 = admin_take_file(a1);
    count = user_take_file(u);
    book_count = book_take_file(book1);
    bike_count = bike_take_file(bike1);
    car_count = car_take_file(car1);
    electric_count = electric_take_file(electric1);
    mobile_count = mobile_take_file(mobile1);
    watch_count = watch_take_file(watch1);
    /*
    */
    return;
}

void admin_login()
{
    int i,go;
    short choice = 0;
    while(1)
    {
        company_name();
        char uname[20],password[9];
        printf("\t\t\t\t\t\t\t\t\tADMIN PORTAL\n\n\n");
        printf("\t\t\t\t\tEnter username\t:  ");
        gets(uname);
        printf("\n\t\t\t\t\tEnter Password\t:  ");
        hidepass(password);
        short result=0 ;
        if(!strcmp(password,a1.admin_password) && !strcmp(uname,a1.admin_name))
        {
            result = 1;
        }

        if(result)
        {
            printf("\n\t\t\t\t\tLogin Successful .\n\n\t\t\t\t\tPress 'Enter' to continue...");
            getchar();
            system("cls");
            break;
        }
        printf("\n\t\t\t\t\tYour Login Details Incorrect. Please try again...\n");
        printf("\t\t\t\t\t Press 1. to go back\n\t\t\t\t\t Press 2. to try again\n\t\t\t\t\t Enter your choice : ");
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
        printf("\t\t%-20s %-30s %-20s %-20s\n\n","Sr.No.","User name","Num. of buy item","Num. of sell item");
        for(int i=0;i<count;i++)
        {
            total_buy += u[i].buy_count;
            total_sell +=  u[i].sell_count;
            printf("\t\t%-20d %-30s %-20u %-20u\n\n",i+1,u[i].username,u[i].buy_count,u[i].sell_count);

        }
        printf("\n\n\n\t\tTotal Revenue\t\t\t:\tRs. %u",a1.revenue);
        printf("\n\t\tTotal of sell items\t\t:\t%d",total_sell);
        printf("\n\t\tTotal of buy items\t\t:\t%d",total_buy);
        printf("\n\t\tTotal of available items\t:\t%d",(total_sell - total_buy));
        printf("\n\n\t\tPress 'ENTER' to continue......");
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
    printf("\t\t\t\t 1. for new user [sign up]\n\n");
    printf("\t\t\t\t 2. for old user [login]\n\n");
    printf("\t\t\t\t 3. for Admin portal\n\n");
    printf("\t\t\t\t 4. to Exit\n");
    printf("\n\n\t\t\t\tEnter your choice number\t:  ");

    choice = cin_validate(1,4);

    printf("\n\n\t\t\t\tPress 'Enter' to continue....");
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
        admin_login();//here we have to divert to admin portal after it is made
        break;
     case 4:
        company_name();
        printf("\t\t\tDo you want to save your data ?\n\t\t\t\t1. if yes\n\t\t\t\t2. if no\n\t\t\tEnter your choice\t:\t");
        int choice;
        choice = cin_validate(1,2);
        if(choice == 1)
            file_save();
        getchar();
        exit(1);
    }
    short go;
    printf("\n\n\tPress 1 to move to signup/login page\n\n\tPress 2 to continue category page\t:  ");
        scanf("%d",&go);

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
    return;
}
unsigned int signup()
{
    company_name();
    char mobile_number[11];
    char input[30];
        printf("\n\n\t\tEnter your details to create a new account : \n\n");
        while(1)//loop for validating username
        {
            printf("\n\tEnter your User Name\t:\t");
            gets(input);
            int i;
            for(i=0;i<count;i++)
            {
                if(!strcmp(input,u[i].username))
                {
                    i = -1;
                    break;
                }
            }
            if(i != -1)
            {
                strcpy(u[count].username,input);
                break;
            }
            else
            {
                printf("\n\t\t\tThis username already exists , please enter a new username...");
            }
        }
        while(1) // loop for validating mobile numbet
        {
            printf("\n\tEnter your mobile number\t:  ");
            gets(mobile_number);

            if(strlen(mobile_number) == 10)//checking if mobile number is of 10 digits
            {
                int i;
                for(i=0;i<10;i++)//checking if all letters are digits only
                {
                    if(!isdigit(mobile_number[i]))
                    {
                         printf("\n\tEnter valid mobile number ...");
                        break;
                    }
                }
                if(i == 10)
                {
                    strcpy(u[count].mobilenumber,mobile_number);
                    break;
                }
            }
            else
                printf("\n\tEnter valid 10-digit mobile number ...");
        }


         while(1) // loop for validating email
        {
            printf("\n\tEnter your email-id\t:\t");
            gets(input);
            int i;
            for(i=0;i<count;i++)
            {
                if(!strcmp(input,u[i].emailid))
                {
                    i = -1;
                    break;
                }
            }
            if(i != -1)
            {
                strcpy(u[count].emailid,input);
                break;
            }
            else
            {
                printf("\n\t\t\tThis email-id already exists , please enter a new email...");
            }
        }
        while(1)//for validating password
        {
            char pass[9];
            printf("\n\tThe password you enter must be of exactly 8 [character/digit]");
            printf("\n\tCreate your Password\t:  ");
            hidepass(pass);
            char temp[9];
            printf("\n\tConfirm Password\t:  ");
            hidepass(temp);
            if(!strcmp(pass ,temp))
            {
                strcpy(u[count].password,pass);
                break;
            }
            printf("\n\tPassword not matching, please enter valid Password...\n");
        }
        printf("\n\n\t\tPlease 'Enter' to continue....");
        getchar();
        system("cls");
        company_name();
        printf("\n\tYour Account Details :\n");
        display_userinfo(count);
        printf("\n\t\t\tPress 'Enter' to continue...");
        getchar();
        system("cls");
        return count;
}
unsigned int login()
{
    int i,go,choice = 0;
    while(1)
    {
        company_name();
        char uname[30],pass[9];
        printf("\n\n\t\t\t\t\t\t\t\t\tLOGIN PAGE\n\n\n");
        printf("\t\t\t\t\tEnter your username\t:  ");
        gets(uname);
        printf("\n\tThe password you enter must be of exactly 8 [character/digit]");
        printf("\n\t\t\t\t\tEnter your Password\t:  ");
        hidepass(pass);
        int result=0 ;
        for(i=0;i<count;i++)
        {
            if(!strcmp(pass,u[i].password) && !strcmp(uname,u[i].username))
            {
               result = 1;
               break;
            }
        }
        if(result)
        {
            printf("\n\t\t\t\t\tLogin Successfully 'Enter' to continue...");
            getchar();
            system("cls");
            break;
        }
        printf("\t\t\t\t\tYour Login Details Incorrect. Please try again...");
        printf("\n\t\t\t\t\t 1. to go back\n\t\t\t\t\t 2. to try again\n\t\t\t\t\t Enter your choice : ");
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
    printf("\tYour Account Details :\n");
    display_userinfo(i);
    printf("\n\n\t\tPlease 'Enter' to continue....");
    getchar();
    system("cls");
    return i;//returning the user number
}

void car_category(int user_no)
{
    company_name();
    int car_index;
    printf("\n\t\tCategory : Car :-\n\n");
    printf("\t\t%-20s   %-30s%-30s%s\n\n","Sr.no","Company","Model","Price");

    int i,index=0;
    short flag = 1;
    for(i=0;i<car_count;i++)
    {
        if(!car1[i].bike1.t.ai.sold)
        {
            flag = 0;
            printf("\n\t\t  %-20d%-30s%-30s%d\n\n",index+1,car1[i].bike1.t.company_name,car1[i].bike1.t.model_name,
                   car1[i].bike1.t.ai.price);
            index++;
        }
    }
    if(flag)
    {
        printf("\n\t\t\tOOPS!!! Cars are out of stock. Please visit again later...");
    }
    printf("\n\t\t  %-20d%-30s\n\n",index+1,"Go back");
    printf("\n\n\n\t\tEnter your choice\t:\t");
    car_index = cin_validate(1,index+1);
    int count=0;
    for(i=0;i<car_count;i++)
    {
        if(!car1[i].bike1.t.ai.sold)
        {
            count++;
        }
        if(count == car_index)
        {
            car_index = i;
            break;
        }
    }
    getchar();
    system("cls");
    if(car_index==index+1)
    {
        category(user_no);
    }
    if(car1[car_index].bike1.t.ai.owner_index == user_no)
    {
        company_name();
        printf("\n\t\t\t\tYou have kept this product for sale so you cannot buy this product. ");
        printf("\n\t\t\t\tPlease try again for a new product.");
        printf("\n\t\t\t\tPress 'Enter' to continue...");
        getchar();
        system("cls");
        car_category(user_no);
    }
    else
    {
        int choice;
        display_car(car1[car_index]);
        printf("\n\n\n\t\t\tPress 1 to confirm buying\n\t\t\tPress 2 to go back\n\n");
        printf("\n\t\t\tEnter your choice\t:   ");
        choice = cin_validate(1,2);
        getchar();
        printf("\nPress 'Enter' to continue.....");
        getchar();
        system("cls");
        if(choice==1)
        {
            car1[car_index].bike1.t.ai.sold = 1;
            int ownerindex = car1[car_index].bike1.t.ai.owner_index;
            company_name();
            printf("\n\t\tOwner details : ");
            display_userinfo(ownerindex);
            u[user_no].buy_count++;
            printf("\n\t\tFor further processes, you may contact the owner of this car and ");
            printf("complete all required procedures...");
            printf("\n\t\tThankyou for visiting our application and purchasing. Hope you had a smooth experience.");
            printf("\n\t\tHope you visit again !!");
            printf("\n\t\tPress 'Enter' to continue...");
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
     printf("\n\t\tCategory : Bike :-\n\n");
    printf("\t\t%-20s   %-30s%-30s%s\n\n","Sr.no","Company","Model","Price");
    int i,index=0;
    short flag = 1;
    for(i=0;i<bike_count;i++)
    {
        if(!bike1[i].t.ai.sold)
        {
            flag = 0;
            printf("\n\t\t  %-20d%-30s%-30s%d\n\n",index+1,bike1[i].t.company_name,bike1[i].t.model_name,
                   bike1[i].t.ai.price);
            index++;
        }
    }
    if(flag)
    {
        printf("\n\t\t\tOOPS!!! Bikes are out of stock. Please visit again later...");
    }
    printf("\n\t\t  %-20d%-30s",index+1,"Go back");
    printf("\n\n\n\t\tEnter your choice\t:\t");
    bike_index = cin_validate(1,index+1);
    getchar();
    int count=0;
    for(i=0;i<bike_count;i++)
    {
        if(!bike1[i].t.ai.sold)
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
    if(bike1[bike_index].t.ai.owner_index == user_no)
    {
        company_name();
        printf("\n\t\t\t\tYou have kept this product for sale so you cannot buy this product. ");
        printf("\n\t\t\t\tPlease try again for a new product.");
        printf("\n\t\t\t\tPress 'Enter' to continue...");
        getchar();
        system("cls");
        bike_category(user_no);
    }
    else
    {
        int choice;
        display_bike(bike1[bike_index]);
        printf("\n\n\n\t\t\tPress 1 to confirm buying\n\t\t\tPress 2 to go back\n\n");
        printf("\t\t\tEnter your choice\t:   ");
        choice = cin_validate(1,2);
        getchar();
        printf("\nPress 'Enter' to continue.....");
        getchar();
        system("cls");
        if(choice==1)
        {
            bike1[bike_index].t.ai.sold = 1;
            int ownerindex = bike1[bike_index].t.ai.owner_index;
            company_name();
            printf("\n\t\tOwner details : ");
            display_userinfo(ownerindex);
            u[user_no].buy_count++;
            printf("\n\n\t\tFor further processes, you may contact the owner of this bike and ");
            printf("complete all required procedures...");
            printf("\n\t\tThankyou for visiting our application and purchasing. Hope you had a smooth experience.");
            printf("\n\t\tHope you visit again !!");
            printf("\n\t\tPress 'Enter' to continue...");
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
    printf("\n\t\tCategory : Mobile :-\n\n");
    printf("\t\t%-20s   %-30s%-30s%s\n\n","Sr.no","Company","Model","Price");

    int i,index=0;
    short flag = 1;
    for(i=0;i<mobile_count;i++)
    {
        if(!bike1[i].t.ai.sold)
        {
            flag = 0;
            printf("\n\t\t  %-20d%-30s%-30s%d\n\n",index+1,mobile1[i].t.company_name,mobile1[i].t.model_name,
                   mobile1[i].t.ai.price);
            index++;
        }
    }
    if(flag)
    {
        printf("\n\t\t\tOOPS!!! Mobiles are out of stock. Please visit again later...");
    }
    printf("\n\t\t  %-20d%-30s \n\n",index+1,"Go back");
    printf("\n\n\n\t\tEnter your choice\t:\t");
    mobile_index = cin_validate(1,index+1);
    getchar();
    int count=0;
    for(i=0;i<mobile_count;i++)
    {
        if(!mobile1[i].t.ai.sold)
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
    if(mobile1[mobile_index].t.ai.owner_index == user_no)
    {
        company_name();
        printf("\n\t\t\t\tYou have kept this product for sale so you cannot buy this product. ");
        printf("\n\t\t\t\tPlease try again for a new product.");
        printf("\n\t\t\t\tPress 'Enter' to continue...");
        getchar();
        system("cls");
        mobile_category(user_no);
    }
    else
    {
        int choice;
        display_mobile(mobile1[mobile_index]);
        printf("\n\n\n\t\t\tPress 1 to confirm buying\n\t\t\tPress 2 to go back\n\n");
        printf("\t\t\tEnter your choice\t:   ");
        choice = cin_validate(1,2);

        printf("Press 'Enter' to continue.....");
        getchar();
        system("cls");
        if(choice==1)
        {
            mobile1[mobile_index].t.ai.sold = 1;
            int ownerindex = mobile1[mobile_index].t.ai.owner_index;
            company_name();
            printf("\t\tOwner details : ");
            display_userinfo(ownerindex);
            u[user_no].buy_count++;
            printf("\n\t\tFor further processes, you may contact the owner of this mobile and ");
            printf("complete all required procedures...");
            printf("\n\t\tThank you for visiting our application and purchasing. Hope you had a smooth experience.");
            printf("\n\t\tHope you visit again !!");
            printf("\n\t\tPress 'Enter' to continue...");
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


void watch_category(int user_no)
{
    company_name();
    int watch_index;
    printf("\n\t\tCategory : Watch :-\n\n");
    printf("\t\t%-20s   %-30s%-30s%s\n\n","Sr.no","Company","Model","Price");

    int i,index=0;
    short flag = 1;
    for(i=0;i<watch_count;i++)
    {
        if(!watch1[i].t.ai.sold)
        {
            flag = 0;
            printf("\n\t\t  %-20d%-30s%-30s%d\n\n",index+1,watch1[i].t.company_name,watch1[i].t.model_name,
                   watch1[i].t.ai.price);
            index++;
        }
    }
    if(flag)
    {
        printf("\n\t\t\tOOPS!!! Watchs are out of stock. Please visit again later...");
    }
    printf("\n\t\t  %-20d%-30s\n\n",index+1,"Go back");
    printf("\n\n\n\t\tEnter your choice\t:\t");
    watch_index = cin_validate(1,index+1);
    getchar();
    int count=0;
    for(i=0;i<watch_count;i++)
    {
        if(!watch1[i].t.ai.sold)
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
    if(watch1[watch_index].t.ai.owner_index == user_no)
    {
        company_name();
        printf("\n\t\t\t\tYou have kept this product for sale so you cannot buy this product. ");
        printf("\n\t\t\t\tPlease try again for a new product.");
        printf("\n\t\t\t\tPress 'Enter' to continue...");
        getchar();
        system("cls");
        watch_category(user_no);
    }
    else
    {
        int choice;
        display_watch(watch1[watch_index]);
        printf("\n\n\n\t\t\tPress 1 to confirm buying\n\t\t\tPress 2 to go back\n\n");
        printf("\t\t\tEnter your choice\t:   ");
        choice = cin_validate(1,2);

        printf("Press 'Enter' to continue.....");
        getchar();
        system("cls");
        if(choice==1)
        {
            watch1[watch_index].t.ai.sold = 1;
            int ownerindex = watch1[watch_index].t.ai.owner_index;
            company_name();
            printf("\t\tOwner details : ");
            display_userinfo(ownerindex);
            u[user_no].buy_count++;
            printf("\n\t\tFor further processes, you may contact the owner of this mobile and ");
            printf("complete all required procedures...");
            printf("\n\t\tThank you for visiting our application and purchasing. Hope you had a smooth experience.");
            printf("\n\t\tHope you visit again !!");
            printf("\n\t\tPress 'Enter' to continue...");
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

void electric_category(int user_no)
{
    company_name();
    int electric_index;
    printf("\n\t\tCategory : Electric :-\n\n");
    printf("\t\t%-20s   %-30s%-30s%-30s%s\n\n","Sr.no","Product","Company","Model","Price");

    int i,index=0;
    short flag = 1;
    for(i=0;i<electric_count;i++)
    {
        if(!electric1[i].t.ai.sold)
        {
            flag = 0;
            printf("\n\t\t  %-20d%-30s%-30s%-30s%d\n\n",index+1,electric1[i].product_name,electric1[i].t.company_name,
                   electric1[i].t.model_name,electric1[i].t.ai.price);
            index++;
        }
    }
    if(flag)
    {
        printf("\n\t\t\tOOPS!!! Electric products are out of stock. Please visit again later...");
    }
    printf("\n\t\t  %-20d%-30s\n\n",index+1,"Go back");
    printf("\n\n\n\t\tEnter your choice\t:\t");
    electric_index = cin_validate(1,index+1);
    getchar();
    int count=0;
    for(i=0;i<electric_count;i++)
    {
        if(!electric1[i].t.ai.sold)
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
    if(electric1[electric_index].t.ai.owner_index == user_no)
    {
        company_name();
        printf("\n\t\t\t\tYou have kept this product for sale so you cannot buy this product. ");
        printf("\n\t\t\t\tPlease try again for a new product.");
        printf("\n\t\t\t\tPress 'Enter' to continue...");
        getchar();
        system("cls");
        electric_category(user_no);
    }
    else
    {
        int choice;
        display_electric(electric1[electric_index]);
        printf("\n\n\n\t\t\tPress 1 to confirm buying\n\t\t\tPress 2 to go back\n\n");
        printf("\t\t\tEnter your choice\t:   ");
        choice = cin_validate(1,2);

        printf("Press 'Enter' to continue.....");
        getchar();
        system("cls");
        if(choice==1)
        {
            electric1[electric_index].t.ai.sold = 1;
            int ownerindex = electric1[electric_index].t.ai.owner_index;
            company_name();
            printf("\t\tOwner details : ");
            display_userinfo(ownerindex);
            u[user_no].buy_count++;
            printf("\n\t\tFor further processes, you may contact the owner of this mobile and ");
            printf("complete all required procedures...");
            printf("\n\t\tThank you for visiting our application and purchasing. Hope you had a smooth experience.");
            printf("\n\t\tHope you visit again !!");
            printf("\n\t\tPress 'Enter' to continue...");
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

void book_category(int user_no)
{
    company_name();
    int book_index;
    printf("\n\t\tCategory : Book :-\n\n");
    printf("\t\t%-20s   %-30s%-30s%s\n\n","Sr.no","Book Name","Author","Price");

    int i,index=0;
    short flag = 1;
    for(i=0;i<book_count;i++)
    {
        if(!book1[i].ai.sold)
        {
            flag = 0;
            printf("\n\t\t  %-20d%-30s%-30s%d\n\n",index+1,book1[i].book_name,book1[i].author,
                   book1[i].ai.price);
            index++;
        }
    }
    if(flag)
    {
        printf("\n\t\t\tOOPS!!! Books are out of stock. Please visit again later...");
    }
    printf("\n\t\t  %-20d%-30s\n\n",index+1,"Go back");
    printf("\n\n\n\t\tEnter your choice\t:\t");
    book_index = cin_validate(1,index+1);
    getchar();
    int count=0;
    for(i=0;i<book_count;i++)
    {
        if(!book1[i].ai.sold)
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
    if(book1[book_index].ai.owner_index == user_no)
    {
        company_name();
        printf("\n\t\t\t\tYou have kept this product for sale so you cannot buy this product. ");
        printf("\n\t\t\t\tPlease try again for a new product.");
        printf("\n\t\t\t\tPress 'Enter' to continue...");
        getchar();
        system("cls");
        book_category(user_no);
    }
    else
    {
        int choice;
        display_book(book1[book_index]);
        printf("\n\n\n\t\t\t1 to confirm buying\n\t\t\t 2 go back\n\n");
        printf("\t\t\tEnter your choice\t:   ");
        choice = cin_validate(1,2);

        printf("Press 'Enter' to continue.....");
        getchar();
        system("cls");
        if(choice==1)
        {
            mobile1[book_index].t.ai.sold = 1;
            int ownerindex = book1[book_index].ai.owner_index;
            company_name();
            printf("\t\tOwner details : ");
            display_userinfo(ownerindex);
            u[user_no].buy_count++;
            printf("\n\t\tFor further processes, you may contact the owner of this mobile and ");
            printf("complete all required procedures...");
            printf("\n\t\tThank you for visiting our application and purchasing. Hope you had a smooth experience.");
            printf("\n\t\tHope you visit again !!");
            printf("\n\t\tPress 'Enter' to continue...");
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

     int temp;
    switch(buy_sell)
    {
    case 1://buy
        switch(choice)
        {
             case 1://car

                if(!car_count)
                {
                    printf("\n\n\n\t\t\tNo data found\n\n");
                    printf("Press 'Enter' to continue.....");
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
                    printf("\n\n\n\t\t\tNo data found\n\n");
                    printf("Press 'Enter' to continue.....");
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
                    printf("\n\n\n\t\t\tNo data found\n\n");
                    printf("Press 'Enter' to continue.....");
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
                    printf("\n\n\n\t\t\tNo data found\n\n");
                    printf("Press 'Enter' to continue.....");
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
                    printf("\n\n\n\t\t\tNo data found\n\n");
                    printf("Press 'Enter' to continue.....");
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
                    printf("\n\n\n\t\t\tNo data found\n\n");
                    printf("Press 'Enter' to continue.....");
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

        switch(choice)
        {
        case 1://car
            strcpy(car1[car_count].bike1.t.ai.owner_name,u[user_no].username);
            car1[car_count].bike1.t.ai.owner_index = user_no;
            temp = revenue_page();
            if(temp != 2)
            {
                company_name();
                 car1[car_count]=get_data_car(car1[car_count]);
                incr_revenue(car1[car_count].bike1.t.ai.price);
                u[user_no].sell_count++;
                system("cls");
                display_car(car1[car_count]);
                car_count++;
            }
            break;

        case 2://bike

            strcpy(bike1[bike_count].t.ai.owner_name,u[user_no].username);
            bike1[bike_count].t.ai.owner_index = user_no;
            temp = revenue_page();
            if(temp == 2)
                break;
            company_name();
            bike1[bike_count]=get_data_bike(bike1[bike_count]);
            incr_revenue(bike1[bike_count].t.ai.price);
            u[user_no].sell_count++;
            system("cls");
            display_bike(bike1[bike_count]);
            bike_count++;
            break;

        case 3://mobile
            strcpy(bike1[bike_count].t.ai.owner_name,u[user_no].username);
            mobile1[mobile_count].t.ai.owner_index = user_no;
            temp = revenue_page();
            if(temp == 2)
                break;
            company_name();
            mobile1[mobile_count]=get_data_mobile(mobile1[mobile_count]);
            incr_revenue(mobile1[mobile_count].t.ai.price);
            u[user_no].sell_count++;
            system("cls");
            display_mobile(mobile1[mobile_count]);
            mobile_count++;
            break;

        case 4://electrical appliances

            strcpy(electric1[electric_count].t.ai.owner_name,u[user_no].username);
            electric1[electric_count].t.ai.owner_index = user_no;
            temp = revenue_page();
            if(temp == 2)
                break;
            company_name();
            electric1[electric_count]=get_data_electric(electric1[electric_count]);
            incr_revenue(electric1[electric_count].t.ai.price);
            u[user_no].sell_count++;
            system("cls");
            display_electric(electric1[electric_count]);
            electric_count++;
            break;

        case 5://wrist watch

             strcpy(watch1[watch_count].t.ai.owner_name,u[user_no].username);
             watch1[watch_count].t.ai.owner_index = user_no;
            temp = revenue_page();
            if(temp == 2)
                break;
            company_name();
            watch1[watch_count]=get_data_watch(watch1[watch_count]);
            incr_revenue(watch1[watch_count].t.ai.price);
            u[user_no].sell_count++;
            system("cls");

            display_watch(watch1[watch_count]);
            watch_count++;
            break;

        case 6://book

            strcpy(book1[book_count].ai.owner_name,u[user_no].username);
            book1[book_count].ai.owner_index = user_no;
            temp = revenue_page();
            if(temp == 2)
                break;
            company_name();
            book1[book_count]=get_data_book(book1[book_count]);
            incr_revenue(book1[book_count].ai.price);
            u[user_no].sell_count++;
            system("cls");
            display_book(book1[book_count]);
            book_count++;
            break;
        }
        printf("\nThank you , Your response is recorded ...");
        printf("\nPress 'Enter' to continue");
        getchar();
        system("cls");
        category(user_no);
    }
}


   void category(int user_no)
{
    int choice;
   company_name();
    printf("\n\t\t\t\t\t\t\t\tALL Categories\n\n");
    hr();
    printf("\n\n\t\t\tUSER\t: %d\n",user_no+1);//here we can do count+1 for no. of user
    printf("\n\t\t\t 1. Cars\n");
    printf("\n\t\t\t 2. Bikes\n");
    printf("\n\t\t\t 3. Mobile\n");
    printf("\n\t\t\t 4. Electrical appliances\n");
    printf("\n\t\t\t 5. Wrist watch\n");
    printf("\n\t\t\t 6. Books\n");
    printf("\n\t\t\t 7. Go back\n\n");

    printf("\n\t\t\tChoose the appropriate Category in which you want to buy or sell item\t:  ");

    choice = cin_validate(1,7);
    if(choice == 7)
    {
        system("cls");
        signup_login_page();
    }
    int buy_sell;
    printf("\n\t\t\t You want to buy an item or sell an item ?\n");
    printf("\n\t\t\t 1. Buy item");
    printf("\n\t\t\t 2. Sell item");
    printf("\n\t\t\t Select your choice : ");
    buy_sell = cin_validate(1,2);
    getchar();
    printf("\npress 'Enter' to continue...");
    getchar();
    system("cls");
    buy_or_sell(choice,buy_sell,user_no);
}

int main()
{
    int choice;
    printf("\n\t\t\tDo you want to retrieve your past data ?");
    printf("\n\t\t\t\tPress 1. if yes");
    printf("\n\t\t\t\tPress 2. if no");
    printf("\n\t\t\tSelect your choice : ");
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
