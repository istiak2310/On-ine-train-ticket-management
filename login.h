#include <stdio.h>
#include <string.h>

// Function prototype
void login(void);
void registe(void);

// Define a struct called 'login' to hold user information
typedef struct {

    char first_name[50];
    char last_name[50];
    char username[50];
    char password[50];
    }login_l;

// Function to register a new user
void registe(void)
{
    login_l l;
    FILE *log;
    // Open a file called 'login.txt' to store user information
    log = fopen("login.txt","a");
    if (log == NULL) {
    printf("Error opening file.\n");
    return;
    }



    // Prompt the user for their first name, last name, username, and password

    printf("\n\n\n\n\t\t\t\t ==REGISTER DATA==\n\n");
    printf("\t\t\tEnter First name: ");
    scanf("%s", l.first_name);
    printf("\t\t\tEnter Last name: ");
    scanf("%s", l.last_name);

    printf("\n\n");
    printf("\t\t\tEnter Username: ");
    scanf("%s", l.username);
    printf("\t\t\tEnter password: ");
    scanf("%s", l.password);
    printf("\n\n");

    // Write the user information to the file
    fwrite(&l, sizeof(l), 1,log);
    fclose(log);

    // Print the user's first name and last name, and give them their user ID
    printf("\t\t\tFirst name: %s\n", l.first_name);
    printf("\t\t\tLast name: %s", l.last_name);

    printf("\n\n\t\t\t Your User name is yourID\n ");
    printf("\t\t\tNow login with UserID and Password\n");
    printf("\n\t\tPress any key to go to login page.....");
    getchar();
    system("CLS");
    // Call the login function after registering the user
    login();

}

void login(void)
{
    char username[50];
    char password[50];
    FILE *log;
    // Open the 'login.txt' file to read user information
    log = fopen("login.txt","r");
    login_l l;

    printf("\n\n\n\t\t\t\t==Login page==\n\n");

    // Prompt the user for their username and password
    printf("\n\n\n\t\t==>UserID: ");
    scanf("%s", &username);
    printf("\t\t==>Password: ");
    scanf("%s", &password);


    while(fread(&l,sizeof(l),1,log))
    {

        // Check if the entered username and password match the stored user information
        if (strcmp(username, l.username) == 0 && strcmp(password, l.password) == 0)
        {
            printf("Successful login....\n");

        }
        else{
            printf("\n\nPlease Enter correct UserID and Password");
            login();
            break;
        }
    }
    fclose(log);
}
