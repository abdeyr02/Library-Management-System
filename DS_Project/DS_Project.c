#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct User_node{

     int id;
     char name[40];
     char user_name[40];
     char password[40];
     char number[12];
     char borrowed_book1[40];
     char borrowed_book2[40];

     struct User_node *link;

}user_node;
user_node *head1 = NULL,*loggedIn=NULL;


typedef struct Books_node{

     char serial_num[20];
     char book_name[40];
    // char marked_usr[40];

     struct books_node *link;

}books_node;
books_node *head2 = NULL;


typedef struct Stack{

    char serial_num[20];
    char book_name[40];

    struct stack *link;

}stack;
stack *top=NULL;

//char loggedUsername[40] = "";
int loggedIn_user=0;
//char serial1[20]="",serial2[20]="";


void user_login();
void user_data();
//void print_users();
void librarian_login();
//void user_login();
void librarian_menu();
void View_All_Books();
void view_defected_books();
void load_defected_books();
void save_to_defected_database();
//void save_to_book();
void view_all_users();
void search_users();
void search_by_id();
void search_by_name();
void search_by_number();
void search_by_id();
void add_book();
void save_book();
void add_user();
void save_user();
int users_node_delete(char Username[],int id);
int books_node_delete(char type[]);
void borrow_book();
void add_book();



int main()
{
   user_data();
   load_all_books();
   load_defected_books();



   while (1)
    {
        system("cls");
        fflush(stdin);
        char choice;

        //printf("\n");
        printf("\t\t\t     =====================================\n");
        printf("\t\t\t     |      Library Management System    |\n");
        printf("\t\t\t     =====================================\n\n\n\n");

        printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
        printf("\n\n");
        printf("\t\t\t[1] Librarian Login\n");
        printf("\t\t\t[2] User Login\n");
        printf("\t\t\t[3] Exit\n\n\n");
        printf("\t\t\tEnter your choice: ");

        scanf("%c",&choice);


        while(choice!= '1' && choice!= '2' && choice!= '3')
        {
            printf("\t\t\tPlease enter a valid choice: ");
            fflush(stdin);
            scanf("%c",&choice);
        }

        switch (choice)
        {
        case '1':
            librarian_login();
            break;
        case '2':
            user_login();
            break;
        case '3':
            system("cls");
            printf("\n\n\n\t\t\t\t\tSystem Closed!!!!\n\n\n");
            getch();
            exit(0);

        }


    }

    getch( );

}

void push(stack **newNode)
{
    stack *temp = *newNode;
    temp->link = top;
    top = temp;
}

char pop()
{

   char name[40];
   stack *temp = top;

   if(top==NULL)
   {
       printf("\t\t\tThere is no Defected Book!!!!");
       printf("\t\t\tPress any key to return Dashboard....\n");
       getch();
       librarian_menu();
   }

   top=top->link;
   temp->link=NULL;
   free( temp );

    strcpy(name,top->book_name);

    return name;


}


void search_by_name()
{
    system("cls");
    fflush(stdin);

    char name[40];
    user_node *temp = head1;
    int count=0;


    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SEARCH BY NAME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n");
    printf("\t\t\tEnter Name :");
    fflush(stdin);
    scanf("%[^\n]",name);

    while(temp!=NULL)
    {

        if(strcmp(temp->name,name)==0)
        {
            count=1;

             printf("\n\n\t\t\t\tUser Found !!!\n\n");
             printf("\t\t\tID = %d\n",temp->id);
             printf("\t\t\tName = %s\n",temp->name);
             printf("\t\t\tUsername = %s\n",temp->user_name);
             printf("\t\t\tPassword = %s\n",temp->password);
             printf("\t\t\tMobile Number = %s\n",temp->number);
             printf("\t\t\tBorrowed Books = %s\n",temp->borrowed_book1);


             if(strcmp(temp->borrowed_book2,",")==0)
                printf("\n\n");

             else
             printf("\t\t\t               = %s\n\n\n",temp->borrowed_book2);

             break;

        }

        temp=temp->link;

    }

    if(count==0)
    {
        printf("\n\n\t\t\t\tUser Not Found !!!\n\n\n");
        printf("\t\t\tPress Any Key To Back Search Menu....");
        getch();
        search_users();

    }
    else
        {

    printf("\t\t\tPress Any Key To Return Library Menu....");
    getch();
    librarian_menu();

        }

}

void search_by_id()
{
    system("cls");
    fflush(stdin);

    int id;
    user_node *temp = head1;
    int count=0;


    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SEARCH BY NAME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n");
    printf("\t\t\tEnter ID :");
    scanf("%d",&id);

    while(temp!=NULL)
    {

        if(temp->id == id)
        {
            count=1;

             printf("\n\n\t\t\t\tUser Found !!!\n\n");
             printf("\t\t\tID = %d\n",temp->id);
             printf("\t\t\tName = %s\n",temp->name);
             printf("\t\t\tUsername = %s\n",temp->user_name);
             printf("\t\t\tPassword = %s\n",temp->password);
             printf("\t\t\tMobile Number = %s\n",temp->number);
             printf("\t\t\tBorrowed Books = %s\n",temp->borrowed_book1);


             if(strcmp(temp->borrowed_book2,",")==0)
                printf("\n\n");

             else
             printf("\t\t\t               = %s\n\n\n",temp->borrowed_book2);

             break;

        }

        temp=temp->link;

    }

    if(count==0)
    {
        printf("\n\n\t\t\t\tUser Not Found !!!\n\n\n");
        printf("\t\t\tPress Any Key To Back Search Menu....");
        getch();
        search_users();

    }
    else
        {

    printf("\t\t\tPress Any Key To Return Library Menu....");
    getch();
    librarian_menu();

        }

}

void search_by_number()
{
    system("cls");
    fflush(stdin);

    char number[40];
    user_node *temp = head1;
    int count=0;


    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SEARCH BY NAME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n");
    printf("\t\t\tEnter Number :");
    fflush(stdin);
    scanf("%[^\n]",number);

    while(temp!=NULL)
    {

        if(strcmp(temp->number,number)==0)
        {
            count=1;

             printf("\n\n\t\t\t\tUser Found !!!\n\n");
             printf("\t\t\tID = %d\n",temp->id);
             printf("\t\t\tName = %s\n",temp->name);
             printf("\t\t\tUsername = %s\n",temp->user_name);
             printf("\t\t\tPassword = %s\n",temp->password);
             printf("\t\t\tMobile Number = %s\n",temp->number);
             printf("\t\t\tBorrowed Books = %s\n",temp->borrowed_book1);


             if(strcmp(temp->borrowed_book2,",")==0)
                printf("\n\n");

             else
             printf("\t\t\t               = %s\n\n\n",temp->borrowed_book2);

             break;

        }

        temp=temp->link;

    }

    if(count==0)
    {
        printf("\n\n\t\t\t\tUser Not Found !!!\n\n\n");
        printf("\t\t\tPress Any Key To Back Search Menu....");
        getch();
        search_users();

    }
    else
        {

    printf("\t\t\tPress Any Key To Return Library Menu....");
    getch();
    librarian_menu();

        }

}


void save_to_defected_database()
{
    stack *temp = top;

    FILE *file;
    file = fopen("database/defected_books" , "w");

    if (file == NULL)
    {
        printf("\t\t\tFile din't found for writing.\n");
    }

    while(temp != NULL)
    {

        fprintf(file, "Serial Number = %[^\n]\n",temp->serial_num);
        fprintf(file, "Name = %[^\n]\n\n",temp->book_name);

        temp=temp->link;

    }
    fclose(file);

}

void save_book()
{
    books_node *temp = head2;

    FILE *file;
    file = fopen("database/all_books.txt" , "w");

    if (file == NULL)
    {
        printf("\t\t\tFile didn't found for writing.\n");
    }

    while(temp != NULL)
    {

        fprintf(file, "Serial Number = %s\n",temp->serial_num);
        fprintf(file, "Name = %s\n\n",temp->book_name);

        temp=temp->link;

    }
    fclose(file);
}

void save_user()
{

    user_node *temp = head1;

    FILE *file;

    file = fopen("database/users.txt" , "w");

    if (file == NULL)
    {
        printf("\t\t\tFile didn't found for writing.\n");
    }

    while(temp!=NULL)
    {

        fprintf(file,"ID = %d\n",temp->id);
        fprintf(file,"Name = %s\n",temp->name);
        fprintf(file,"Username = %s\n",temp->user_name);
        fprintf(file,"Password = %s\n",temp->password);
        fprintf(file,"Mobile Number = %s\n",temp->number);
        fprintf(file,"Borrowed Books = %s\n",temp->borrowed_book1);
        fprintf(file,"               = %s\n\n",temp->borrowed_book2);
        //fprintf(file,"Borrowed Books = none,\n\n");


        temp=temp->link;

    }

    fclose(file);


}
//void save_to_book_database()
//{
//
//}

void user_data()
{

    FILE* file;
    file = fopen("database/users.txt", "r");

    if (file == NULL)
    {
        printf("Error!! File not found ....\n");
        return;
    }



    while(1)
    {
        user_node *newNode;
        newNode = (user_node *)malloc(sizeof(user_node));
        newNode->link = NULL;

        if(fscanf(file,"ID = %d\n",&newNode->id) == EOF)
            break;

        fscanf(file,"Name = %[^\n]\n",newNode->name);
        fscanf(file,"Username = %[^\n]\n",newNode->user_name);
        fscanf(file,"Password = %[^\n]\n",newNode->password);
        fflush(stdin);
        fscanf(file,"Mobile Number = %s\n",newNode->number);
        fscanf(file,"Borrowed Books = %[^\n]\n",newNode->borrowed_book1);
        fscanf(file,"               = %[^\n]\n\n",newNode->borrowed_book2);


        if(head1 == NULL)
            {
              head1 = newNode;
            }
        else
        {
            newNode->link = head1;
            head1 = newNode;
        }


    }

    fclose(file);

}

void load_all_books()
{
    FILE* file;
    file = fopen("database/all_books.txt", "r");

    if (file == NULL)
    {
        printf("\t\t\tError!! File not found ....\n");
        return;
    }

    while(1)
    {
        books_node *newNode;
        newNode = (books_node *)malloc(sizeof(books_node));
        newNode->link = NULL;


        if(fscanf(file,"Serial Number = %[^\n]\n",newNode->serial_num) == EOF)
            break;

        fscanf(file,"Name = %[^\n]\n\n",newNode->book_name);


        if(head2 == NULL)
            {
              head2 = newNode;
            }

        else
        {
            newNode->link = head2;
            head2 = newNode;
        }

    }

    fclose(file);

}
void load_defected_books()
{

    FILE *file;
    file = fopen("database/defected_books.txt" , "r");

    if (file == NULL)
    {
        printf("\t\t\tError!! File not found ....\n");
        return;
    }

    while(1)
    {
        stack *newNode;
        newNode = (stack *)malloc(sizeof(stack));
        newNode->link = NULL;


        if(fscanf(file,"Serial Number = %[^\n]\n",newNode->serial_num) == EOF)
            break;

        fscanf(file,"Name = %[^\n]\n",newNode->book_name);

        if(top==NULL)
        {
            top = newNode;
        }
        else
        {
            push( &newNode );
        }
    }

    fclose(file);


}

void librarian_login()
{

    char librarian_username[20], librarian_password[20];

    FILE *file;
    file = fopen("database/librarian.txt" , "r");

    if (file == NULL)
    {
        printf("Error!! File not found ....\n");
        return;
    }
    fscanf(file,"username = %[^\n]\n",librarian_username);
    fscanf(file,"password = %[^\n]\n",librarian_password);

    fclose(file);


    while(1)
    {
        fflush(stdin);
        system("cls");
        char username[20],password[20];

            printf("\n\n");
            printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOG-IN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
            printf("\n\n");
            printf("\t\t\t**Enter Username: ");
            scanf("%[^\n]", username);
            fflush(stdin);
            printf("\t\t\t**Enter Password: ");
            scanf("%[^\n]", password);


        if( strcmp(username,librarian_username)==0 && strcmp(password,librarian_password)==0 )
        {
                printf("\n\t\t\tLogin Successful!!!  Press any key to continue....");
                getch();
                librarian_menu();
                break;
        }
        else
        {
            printf("\n\t\t\tLogin Failed!!!  Wrong Username or Password....\n");
            printf("\n\t\t\tPress any key to try again....");
            getch();
        }

    }

}


void librarian_menu()
{
    int choice;
    fflush(stdin);
    system("cls");

    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LIBRARIAN DASHBOARD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n");

    printf("\t\t\t[1] View All Books\n");
    printf("\t\t\t[2] View Defected Books\n");
    printf("\t\t\t[3] View All Users\n");
    printf("\t\t\t[4] Search User\n");
    printf("\t\t\t[5] Add Book\n");
    printf("\t\t\t[6] Add User\n");
    printf("\t\t\t[7] Delete Book\n");
    printf("\t\t\t[8] Remove User\n");
    printf("\t\t\t[9] Remove Defected Book\n");
    printf("\t\t\t[10] Add Defected Book\n");
    printf("\t\t\t[11] Logout\n\n");
    printf("\t\t\tEnter your choice: ");

    scanf("%d", &choice);

    while (choice < 1 || choice > 11)
    {
        printf("\t\t\tPlease enter a valid choice: ");
        //fflush(stdin);
        scanf("%d", &choice);
    }

    switch (choice)
    {
    case 1:
        View_All_Books();
        break;
    case 2:
        view_defected_books();
        break;
    case 3:
        view_all_users();
        break;
    case 4:
        search_users();
        break;
    case 5:
        add_book();
        break;
    case 6:
        add_user();
        break;
    case 7:
         delete_book();
         break;
    case 8:
         remove_user();
         break;
    case 9:
        remove_deflected_book();
        break;
    case 10:
        add_defected_book();
        break;
    case 11:
        break;
    }
}

void View_All_Books()
{

    system("cls");
    books_node *temp = head2;

            printf("\n\n");
            printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ALL BOOK'S \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
            printf("\n\n");
            printf("\t\t\t Serial Number        Name   \n");
            printf(" \t\t\t==============      =========\n\n");


     if(temp == NULL)
        {
                printf("\t\t\tThere is no book to show!!!\n\n");
        }

    else
        {

    while(temp!=NULL)
    {

         printf("\t\t\t%s  ---------  %s\n",temp->serial_num,temp->book_name);
         temp=temp->link;

    }

      }


       printf("\n\n\n\t\t\tPress any key to return dashboard....");
       getch();
       if(loggedIn_user==0)
          librarian_menu();

       else
        user_menu();


}

void view_defected_books()
{

    system("cls");
    stack *temp = top;


            printf("\n\n");
            printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BOOK'S LIST \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
            printf("\n\n");
            printf("\t\t\tSerial Number        Name   \n");
            printf("\t\t\t=============      =========\n\n");


    if(temp == NULL)
        {
                printf("\t\t\tThere is no book to show!!!\n\n");
        }

    else
    {
        while(temp != NULL)
        {

          printf("\t\t\t%s  ---------  %s\n",temp->serial_num,temp->book_name);
          temp=temp->link;

        }
    }

       printf("\n\n\n\t\t\tPress any key to return dashboard....");
       getch();
       librarian_menu();



}

void view_all_users()
{

    system("cls");
    int i=1;
    user_node *temp = head1;

            printf("\n\n");
            printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ALL USER'S \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
            printf("\n\n");

     if(temp == NULL)
     {
         printf("\t\t\tThere is no user!!!\n\n");
     }

     else
     {
       //char book1[40],book2[40];

         while(temp != NULL)
         {

           //strcpy(book1,temp->borrowed_book1);
           //strcpy(book2,temp->borrowed_book2);


             printf("\t\t\t User Number = %d\n",i);
             printf("\t\t\t--------------------\n");
             printf("\t\t\tID = %d\n",temp->id);
             printf("\t\t\tName = %s\n",temp->name);
             printf("\t\t\tUsername = %s\n",temp->user_name);
             printf("\t\t\tPassword = %s\n",temp->password);
             printf("\t\t\tMobile Number = %s\n",temp->number);
             printf("\t\t\tBorrowed Books = %s\n",temp->borrowed_book1);


             if(strcmp(temp->borrowed_book2,"none")==0)
                printf("\n\n");

             else
                printf("\t\t\t               = %s\n\n\n",temp->borrowed_book2);

             temp=temp->link;
             i++;

         }

     }

     i=1;


    printf("\n\n\n\t\t==>>Press any key to return dashboard...");
    getch();
    librarian_menu();


}

void search_users()
{
    system("cls");
    fflush(stdin);
    char choice;

    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SEARCH USER MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n");
    printf("\t\t\t[1] Search By Name\n");
    printf("\t\t\t[2] Search By ID\n");
    printf("\t\t\t[3] Search By Number\n");
    printf("\t\t\t[4] Return Library Menu\n");
    printf("\t\t\t\n\nEnter Your Choice :");
    fflush(stdin);
    scanf("%c",&choice);

    while(choice!='1' && choice!='2' && choice!='3' && choice!='4')
    {
        printf("\t\t\tPlease enter a valid option: ");
        fflush(stdin);
        scanf("%c",&choice);

    }

    switch(choice)
    {
    case '1':
        search_by_name();
        break;
    case '2':
        search_by_id();
        break;
    case '3':
        search_by_number();
        break;
    case '4':
        librarian_menu();
        break;

    }


}

void add_book()
{


     system("cls");
     fflush(stdin);
     char serial_num[20],book_name[40];

     books_node *temp = head2, *newNode;
     newNode = (books_node* )malloc(sizeof(books_node));
     newNode->link = NULL;

    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ADD BOOK MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n");
    printf("\t\t\tEnter Serial Number Of The Book :");
    scanf("%s",serial_num);
    printf("\t\t\tEnter Name Of The Book :");
    fflush(stdin);
    gets(book_name);

    strcpy(newNode->serial_num,serial_num);
    strcpy(newNode->book_name,book_name);

    if(temp==NULL)
    {
        head2 = newNode;
    }
    else
        {
    newNode->link = temp;
    head2 = newNode;

        }
    save_book();

    printf("\n\n\t\t\t\tBook Added Successfully!!!!\n\n");
    printf("\t\t\tPress Any Key To Back Librarian Menu....");
    getch();
    librarian_menu();



}

void add_user()
{

     system("cls");
     fflush(stdin);
     int id;
     char name[40],user_name[40],password[40],number[12],book1[40]="none",book2[40]="none";

     user_node *temp = head1, *newNode;
     newNode = (user_node* )malloc(sizeof(user_node));
     newNode->link = NULL;

    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ADD USER MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n");
    printf("\t\t\tID :");
    scanf("%d",&id);
    printf("\t\t\tEnter Name :");
    fflush(stdin);
    gets(name);
    printf("\t\t\tEnter User Name :");
    fflush(stdin);
    scanf("%s",user_name);
    printf("\t\t\tEnter Password :");
    fflush(stdin);
    scanf("%s",password);
    printf("\t\t\tEnter Number :");
    fflush(stdin);
    scanf("%s",number);

    newNode->id=id;
    strcpy(newNode->name,name);
    strcpy(newNode->user_name,user_name);
    strcpy(newNode->password,password);
    strcpy(newNode->number,number);
    strcpy(newNode->borrowed_book1,book1);
    strcpy(newNode->borrowed_book2,book2);



    if(temp==NULL)
    {
        head1 = newNode;
    }
    else
        {
    newNode->link = temp;
    head1 = newNode;

        }
    save_user();

    printf("\n\n\t\t\t\tUser Added Successfully!!!!\n\n");
    printf("\t\t\tPress Any Key To Back Librarian Menu....");
    getch();
    librarian_menu();


}

int users_node_delete(char Username[],int id)
{

      int count = 0;
     user_node *temp = head1,*previous=NULL;

     if((strcmp(temp->user_name,Username)==0)||(temp->id==id))
        {
            count=1;
            head1 = temp->link;
            temp->link = NULL;
            free(temp);
        }

        else{

        while(temp->link != NULL)
        {
            if((strcmp(temp->user_name,Username)==0)||(temp->id==id))
            {
                count=1;
                break;
            }
            previous=temp;
            temp=temp->link;

        }

        if( temp->link == NULL  && ((strcmp(temp->user_name,Username)==0)||(temp->id==id)))
        {
            count=1;
            previous->link=NULL;
            free( temp );

        }
        else if(count == 1 && temp->link != NULL)
        {

            previous->link = temp->link;
            free( temp );

        }

        }

        return count;

}

int books_node_delete(char type[])
{

     int count = 0;
     books_node *temp = head2,*previous=NULL;

     if((strcmp(temp->book_name,type)==0)||(strcmp(temp->serial_num,type)==0))
        {
            count=1;
            head2 = temp->link;
            temp->link = NULL;
            free(temp);
        }

        else{

        while(temp->link != NULL)
        {
            if((strcmp(temp->book_name,type)==0)||(strcmp(temp->serial_num,type)==0))
            {
                count=1;
                break;
            }
            previous=temp;
            temp=temp->link;

        }

        if( temp->link == NULL  && ((strcmp(temp->book_name,type)==0)||(strcmp(temp->serial_num,type)==0)) )
        {
            count=1;
            previous->link=NULL;
            free( temp );

        }
        else if(count == 1 && temp->link != NULL)
        {

            previous->link = temp->link;
            free( temp );

        }

        }

        return count;


}

void delete_book()
{
    system("cls");

    int choice,count;
    char serial[20],book_name[40];

    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DELETE BOOK MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n");
    printf("\t\t\t[1] Search By Name\n");
    printf("\t\t\t[2] Search By Serial\n");
    printf("\t\t\t[3] To Return Dashboard\n\n");
    printf("\t\t\t***Enter Your Choice:");
    scanf("%d",&choice);

    if(choice<1 || choice >3)
       {
         printf("\t\t\tPlease , Enter a Valid Option!!!!\n\n");
         printf("\t\t\tPress any key to search again....");
         getch();
         delete_book();
       }




    switch(choice)
     {

       case 1 :
         fflush(stdin);
         printf("\n\n\t\t  Enter Book Name :");
         gets(book_name);
         count = books_node_delete(book_name);
         break;


       case 2 :
         fflush(stdin);
         printf("\n\n\t\t  Enter Serial Number :");
         scanf("%s",serial);
         count = books_node_delete(serial);
         break;

       case 3:
         librarian_menu();

       }



        if(count==1)
        {
            printf("\n\n\t\t  Delete Successful!!!\n\n\n");
            printf("\t\t\t***Enter any key to Return Dashboard!!!");
            getch();
            save_book();
            librarian_menu();
        }
        else{

            printf("\n\n\t\t  Delete Failed!!!\n\n\n");
            printf("\t\t\tEnter any key to Return Book Delete Menu!!!");
            getch();
            delete_book();

        }



}

void remove_user()
{
    system("cls");

    int choice,count,id=0;
    char username[40];

    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 REMOVE USER MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n");
    printf("\t\t\t[1] Search By Username\n");
    printf("\t\t\t[2] Search By ID\n");
    printf("\t\t\t[3] To Return Dashboard\n\n");
    printf("\t\t\t***Enter Your Choice:");
    scanf("%d",&choice);

    if(choice<1 || choice >3)
       {
         printf("\t\t\tPlease , Enter a Valid Option!!!!\n\n");
         printf("\t\t\tPress any key to search again....");
         getch();
         remove_user();
       }




    switch(choice)
     {

       case 1 :
         fflush(stdin);
         printf("\n\n\t\t  Enter Username :");
         gets(username);
         count = users_node_delete(username,id);
         break;


       case 2 :
         fflush(stdin);
         printf("\n\n\t\t  Enter Serial Number :");
         scanf("%d",&id);
         count = users_node_delete(username,id);
         break;

       case 3:
         librarian_menu();

       }



        if(count==1)
        {
            printf("\n\n\t\t  Remove Successful!!!\n\n\n");
            printf("\t\t\t***Enter any key to Return Dashboard!!!");
            getch();
            save_user();
            librarian_menu();
        }
        else{

            printf("\n\n\t\t  Remove Failed!!!\n\n\n");
            printf("\t\t\tEnter any key to Return Book Delete Menu!!!");
            getch();
            remove_user();

        }



}

void remove_deflected_book()
{
    system("cls");

    char removedBook[40];
    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 REMOVE DEFECTED BOOK MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n");

    pop();
    printf("\t\t   Top Defected Book Removed Successfully!!!\n");
    printf("\t\t   Name of that Book is %s!!!\n",top->book_name);
    save_to_defected_database();
    printf("\t\t   Enter any key to return Dashboard....");
    getch( );
    librarian_menu();

}
void add_defected_book()
{
    system("cls");

    books_node *temp = head2;
    char name[40];
    int count;

    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ADD DEFECTED BOOK MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n");
    printf("\t\t\tWrite the name of the book that you want to store in the Stack : ");

    fflush(stdin);
    gets(name);

    count = books_node_delete(name);

    if(count == 1)
    {
        save_to_defected_database();
        save_book();
        printf("\n\t\t  Stored in the Stack Successfully!!!");
        printf("\n\n\n\t\t  Press any key to return Dashboard....");
        getch();
        librarian_menu();
    }
    else
    {

        printf("\n\t\t\tThat Book is not Available in Database!!!");
        printf("\n\t\t\tPress any key to return Dashboard....");
        getch();
        librarian_menu();

    }


}

void user_login()
{
    system("cls");
    fflush(stdin);


    user_node *temp = head1;
    char userName[40],password[40];
    int count=0;

    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 USER LOG-IN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n");
    printf("\t\t\t**Enter Username :");
    gets(userName);
    printf("\t\t\t**Enter Password :");
    gets(password);


            while (temp != NULL)
            {
                if (strcmp(userName, temp->user_name) == 0 && strcmp(password, temp->password) == 0)
                {
                    count=1;
                    loggedIn_user=1;

                    loggedIn = temp;
                    printf("\n\t\t\tLogin Successful! Press any key to continue....");
                    getch();

                    user_menu();
                }

                temp=temp->link;
            }

    if(count==0)
        {
            printf("\n\t\t\tLogin Failed!!!  Wrong Username or Password....\n");
            printf("\n\t\t\tPress any key to try again....");
            getch();
            user_login();

        }

}

void user_menu()
{

    int choice;
    fflush(stdin);
    system("cls");

    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 USER DASHBOARD \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n");

    printf("\t\t\t[1] View Profile\n");
    printf("\t\t\t[2] View All Books\n");
    printf("\t\t\t[3] Borrow a Book\n");
    printf("\t\t\t[4] Return a Book\n");
    printf("\t\t\t[5] logout\n");

    printf("\t\t\tEnter your choice: ");

    scanf("%d", &choice);

    while (choice < 1 || choice > 5)
    {
        printf("\t\t\tPlease enter a valid choice: ");
        //fflush(stdin);
        scanf("%d", &choice);
    }

    switch (choice)
    {
    case 1:
        view_profile();
        break;
    case 2:
        View_All_Books();
        break;
    case 3:
        borrow_book();
        break;
    case 4:
         return_book();
        break;
    case 5:
        loggedIn=NULL;
        loggedIn_user=0;
        break;

    }

}

void view_profile()
{
    system("cls");

    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 VIEW PROFILE \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n");



             printf("\t\t\tID = %d\n",loggedIn->id);
             printf("\t\t\tName = %s\n",loggedIn->name);
             printf("\t\t\tUsername = %s\n",loggedIn->user_name);
             printf("\t\t\tPassword = %s\n",loggedIn->password);
             printf("\t\t\tMobile Number = %s\n",loggedIn->number);
             printf("\t\t\tBorrowed Books = %s\n",loggedIn->borrowed_book1);


             if(strcmp(loggedIn->borrowed_book2,"none")==0)
                printf("\n\n");

             else
                printf("\t\t\t               = %s\n\n\n",loggedIn->borrowed_book2);


    printf("\t\t\tEnter any key to back Dashboard....");
    getch();
    user_menu();

}

void borrow_book()
{
    system("cls");



    int choice,count;
    char book_name[40],serial[20];

    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BORROW BOOK MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n");

    if((strcmp(loggedIn->borrowed_book1,"none")!=0)  && (strcmp(loggedIn->borrowed_book2,"none")!=0))
    {
        printf("\t\t\tYou Have already borrowed maximum amount of books\n\n");
        printf("\t\t\tEnter any key to return Dashboard....");
        getch();
        user_menu();
    }


    printf("\t\t\t[1] Search By Name\n");
    printf("\t\t\t[2] To Return Dashboard\n\n");
    printf("\t\t\t***Enter Your Choice:");
    fflush(stdin);
    scanf("%d",&choice);

    if(choice<1 || choice >2)
       {
         printf("\t\t\tPlease , Enter a Valid Option!!!!\n\n");
         printf("\t\t\tPress any key to search again....");
         getch();
         borrow_book();
       }




    switch(choice)
     {

       case 1 :
         fflush(stdin);
         printf("\n\n\t\t  Enter Book Name :");
         gets(book_name);
         count = books_node_delete(book_name);
         break;

       case 2:
           user_menu();
           break;



       }



        if(count==1)
        {


            if(strcmp(loggedIn->borrowed_book1,"none")==0)
            {
                strcpy(loggedIn->borrowed_book1,book_name);

                save_user();
            }

            else
            {
                strcpy(loggedIn->borrowed_book2,book_name);

                save_user();
            }



            printf("\n\n\t\t  Taken Successfully!!!\n\n\n");
            printf("\t\t\t***Enter any key to Return Dashboard!!!");
            getch();
            save_book();
            user_menu();
        }
        else
        {

            printf("\n\n\t\t  Not Available!!!\n\n\n");
            printf("\t\t\tEnter any key to Return Book Borrow Menu!!!");
            getch();

            borrow_book();

        }



}
void return_book()
{
    system("cls");

    char book_name[40],serial[20];
    books_node *newNode;


    printf("\n\n");
    printf("\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 RETURN BOOK MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\n\n");

    if(strcmp(loggedIn->borrowed_book1,"none")==0)
    {
        printf("\t\t   You don't have any book.\n\n");
        printf("\t\t **Enter any key to return dashboard....");
        getch();
        user_menu();
    }

    printf("\t\t\tEnter Book Name:");
    fflush(stdin);
    gets(book_name);

    if(strcmp(loggedIn->borrowed_book1,book_name)==0)
    {
        newNode=(books_node* )malloc(sizeof(books_node));
        newNode->link = NULL;

        printf("\t\t\tEnter serial number of the book :");
        fflush(stdin);
        scanf("%s",serial);

        strcpy(newNode->book_name,book_name);
        strcpy(newNode->serial_num,serial);


        newNode->link = head2;
        head2 = newNode;

        save_book();
        strcpy(loggedIn->borrowed_book1,"none");
        save_user();

    }

   else if(strcmp(loggedIn->borrowed_book2,book_name)==0)
     {
        newNode=(books_node* )malloc(sizeof(books_node));
        newNode->link = NULL;
        strcpy(newNode->book_name,book_name);

        printf("\t\t\tEnter serial number of the book :");
        fflush(stdin);
        scanf("%s",serial);

        strcpy(newNode->book_name,book_name);
        strcpy(newNode->serial_num,serial);

        newNode->link = head2;
        head2 = newNode;

        save_book();
        strcpy(loggedIn->borrowed_book2,"none");
        save_user();


    }
    else
    {

        printf("\t\t\tInvalid name!!!\n\n");
        printf("\t\t\tPress any key to return dashboard....\n");
        getch( );
        user_menu();

    }

    printf("\t\t\tBook returned Successfully!!!\n");
    printf("\t\t\tPress any key to return dashboard....");
    getch();
    user_menu();

}












