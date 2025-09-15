#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"

int loadAccounts(const char *filename, Account **accounts, int *count) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("Error opening account file");
        return -1;
    }

    int capacity = 100;  // ban đầu cấp phát 100
    *accounts = malloc(capacity * sizeof(Account));
    if (!*accounts) {
        perror("Malloc failed");
        fclose(f);
        return -1;
    }

    *count = 0;
    char line[512];
    while (fgets(line, sizeof(line), f)) {
        char username[512];
        int status;
        if (sscanf(line, "%511s %d", username, &status) == 2) {
            if (strlen(username) >= sizeof((*accounts)[*count].username)) {
                printf("Warning: username '%s' too long, skipped.\n", username);
                continue;
            }

            // Nếu đầy thì tăng gấp đôi dung lượng
            if (*count >= capacity) {
                capacity *= 2;
                Account *tmp = realloc(*accounts, capacity * sizeof(Account));
                if (!tmp) {
                    perror("Realloc failed");
                    free(*accounts);
                    fclose(f);
                    return -1;
                }
                *accounts = tmp;
            }

            strcpy((*accounts)[*count].username, username);
            (*accounts)[*count].status = status;
            (*count)++;
        }
    }
    fclose(f);

    printf("Loaded %d accounts\n", *count);
    return 0;
}
