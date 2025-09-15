#include <stdio.h>
#include <stdlib.h>
#include "account.h"
#include "menu.h"

int main() {
    Account *accounts = NULL;
    int count = 0;

    // Đọc file account
    if (loadAccounts("model/account.txt", &accounts, &count) < 0 || count == 0) {
        printf("Cannot load accounts\n");
        return 1;
    }

    printf("Successfully loaded %d accounts\n", count);

    // Chạy menu, trong đó mỗi thao tác đều gọi writeLog
    runMenu(accounts, count);

    // Giải phóng bộ nhớ
    free(accounts);

    return 0;
}
