#ifndef AUTH_SERVICE_H
#define AUTH_SERVICE_H

#include "account.h"

int login(Account accounts[], int count, const char *username, int *loggedIn);
int logout(int *loggedIn);
int postMessage(int loggedIn, const char *message);

#endif
