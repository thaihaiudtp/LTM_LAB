#include <stdio.h>
#include <string.h>
#include "auth_service.h"
int login(Account accounts[], int count, const char *username, int *loggedIn) {
    if (*loggedIn) return -2; // đã đăng nhập rồi
    for (int i = 0; i < count; i++) {
        if (strcmp(accounts[i].username, username) == 0) {
            if (accounts[i].status == 0) return -1; // bị khóa
            *loggedIn = 1;
            return 0; // thành công
        }
    }
    return -3; // không tồn tại
}

int logout(int *loggedIn) {
    if (!*loggedIn) return -1;
    *loggedIn = 0;
    return 0;
}

int postMessage(int loggedIn, const char *message) {
    if (!loggedIn) return -1;
    printf("Post successful: %s\n", message);
    return 0;
}
