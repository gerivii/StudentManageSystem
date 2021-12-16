#include"SQL.h"
#include<Windows.h>
#include<stdio.h>
#include<sqlext.h>
#include<string.h>
#include <stdarg.h>

char szDSN[256] = "Driver={Microsoft Access Driver (*.mdb, *.accdb)};DSN='';DBQ=Student.accdb";
HENV hEnv;
HDBC hDbc;
RETCODE rc;
HSTMT hstmt;

int SqlConn();

void SqlDisConn();

int SqlExecute(char *query);

char *link(char *str, va_list list);

int TableConn(char *table);

int SqlConn() {
    int iConnStrLength2Ptr;
    char szConnStrOut[256];
    rc = SQLAllocEnv(&hEnv);
    rc = SQLAllocConnect(hEnv, &hDbc);
    rc = SQLDriverConnect(hDbc, NULL, (unsigned char *) szDSN,
                          SQL_NTS, (unsigned char *) szConnStrOut,
                          255, (SQLSMALLINT *) &iConnStrLength2Ptr, SQL_DRIVER_NOPROMPT);
    if (SQL_SUCCEEDED(rc))
        return 1;
    else
        return 0;
}

void SqlDisConn() {
    SQLDisconnect(hDbc);
    SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
    SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
}

int SqlExecute(char *query) {
    rc = SQLAllocStmt(hDbc, &hstmt);
    rc = SQLPrepare(hstmt, (SQLCHAR *) query, SQL_NTS);
    rc = SQLExecute(hstmt);
    if (SQL_SUCCEEDED(rc)) {
        printf("SQL Succeeded!\n");
        return 1;
    } else {
        printf("SQL Failed!\n");
        return 0;
    }
}

char *link(char *str, va_list list) {
    char *temp;
    strcpy(temp, str);
    strcat(str, list);
    return temp;
}

int TableConn(char *table) {
    char *query = link("select * from ", table);
    if (SqlExecute(query)) {
        printf("Connect Succeeded!");
        return 1;
    } else {
        printf("Connect Failed!");
        return 0;
    }
}

int SqlAdd(char *table, ...) {
    TableConn(table);
    SQLSMALLINT colNum = 0;
    SQLNumResultCols(hstmt, &colNum);

    va_list list;
    va_start(list, table);

    char *str = link(link("insert into ", table), "values(");
    char *query = link(link(str, list), ")");

    if (SqlConn()) {
        if (SqlExecute(query)) {
            printf("Add Succeeded!\n");
            SqlDisConn();
            return 1;
        } else {
            printf("Add Failed!\n");
            SqlDisConn();
            return 0;
        }
    } else {
        printf("Couldn't connect to %s.\n", szDSN);
        SqlDisConn();
        return 0;
    }

}


int SqlDel(char *table, char *key, char *colName, int mode) {

    TableConn(table);

    char *query;

    if (mode) {
        char *str1 = link(link("delete from ", table), "where ");
        char *str2 = link(link(str1, (char *) colName), "=\"");
        query = link(link(str2, key), "\"");
    } else {
        query = link("delete * from ", table);
    }

    if (SqlConn()) {
        if (SqlExecute(query)) {
            printf("Delete Succeeded!\n");
            SqlDisConn();
            return 1;
        } else {
            printf("Delete Failed!\n");
            SqlDisConn();
            return 0;
        }
    } else {
        printf("Couldn't connect to %s.\n", szDSN);
        SqlDisConn();
        return 0;
    }

}