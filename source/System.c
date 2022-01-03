/**
 * @file System.c
 * @brief 系统源文件
 * @details 包含与系统设置、安全相关的源代码
 * @author gerivii
 * @date 2021-12-16
 * @version 1.0
 */

#include "../head/System.h"
#include "../head/SQL.h"

#include <stdio.h>
#include <string.h>

__attribute__ ((unused)) int Login(char *account, char *password) {
    char *temp = NULL;
    char *flag = "0";

    if (!SqlFind("user", "account", account, "password", temp)) {
        return 0;
    } else {
        if (!strcmp(password, temp)) {
            if (!SqlFind("user", "account", account, "power", flag)) {
                return 0;
            } else {
                return (int) flag[0];
            }
        } else {
            printf("密码错误!\n");
            return 0;
        }
    }
}

__attribute__((unused)) int Register(char *account, char *password) {
    return SqlAdd("user", account, password, '1');
}

__attribute__((unused)) int DelAccount(char *account) {
    return SqlDel("user", "account", account);
}

__attribute__((unused)) int ChangePermission(char *account, char* power) {
    return SqlFind("user", "account", account, "power", power);
}
