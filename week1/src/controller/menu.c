#include <stdio.h>
#include <string.h>
#include <time.h>
#include "account.h"
#include "auth_service.h"
#include "log.h"
void runMenu(Account accounts[], int count) {
    int choice;
    int loggedIn = 0;
    char input[256];
    do {
        printf("1. Log in\n2. Post message\n3. Logout\n4. Exit\n");
        scanf("%d", &choice);
        getchar();
        switch(choice) {
            case 1:
                printf("Username: ");
                scanf("%s", input);
                int r = login(accounts, count, input, &loggedIn);
                if (r==0) printf("Hello %s\n", input);
                else if (r==-1) printf("Account is banned\n");
                else if (r==-2) printf("You have already logged in\n");
                else printf("Account is not exist\n");
                writeLog("20201234", 1, input, r==0?0:-1);
                break;
            case 2:
                printf("Post message: ");
                // getchar(); // clear buffer
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                r = postMessage(loggedIn, input);
                if (r==0) printf("Successful post\n");
                else printf("You have not logged in.\n");
                writeLog("20201234", 2, input, r==0?0:-1);
                break;
            case 3:
                r = logout(&loggedIn);
                if (r==0) printf("Successful log out\n");
                else printf("You have not logged in.\n");
                writeLog("20201234", 3, "", r==0?0:-1);
                break;
            case 4:
                writeLog("20201234", 4, "", 0);
                break;
        }
    } while(choice != 4);
}
