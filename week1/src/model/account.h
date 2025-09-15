#ifndef ACCOUNT_H
#define ACCOUNT_H

typedef struct {
    char username[256];  // đủ dài cho username
    int status;
} Account;

int loadAccounts(const char *filename, Account **accounts, int *count);

#endif
