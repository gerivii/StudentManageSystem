/**
 * @file SQL.h
 * @brief 数据库文件
 * @details 包含数据库基本操作
 * @author ren
 * @date 2021-1-2
 * @version 1.2
 */


#include "../head/SQL.h"

#include <Windows.h>
#include <stdio.h>
#include <sqlext.h>
#include <string.h>
#include <stdarg.h>

char szDSN[256] = "Driver={Microsoft Access Driver (*.mdb, *.accdb)};DSN='';DBQ=C:\\Users\\wzt13\\OneDrive - email.ncu.edu.cn\\桌面\\Student(1).accdb;";

HENV hEnv;//环境句柄
HDBC hDbc;//连接句柄
RETCODE rc;//
HSTMT hstmt;//语句句柄

int SqlConn();//数据库连接函数
void SqlDisConn();//数据库断开连接函数
int SqlExecute(char *query);//SQL语句执行函数
char *link(char *str, va_list list);//字符串连接函数
int TableConn(char *table);//表连接函数

/**
 * @brief 连接至Access数据库
 * @return 是否连接成功
 * @retval 0 失败
 * @retval 1 成功
 */
int SqlConn() {
    int iConnStrLength2Ptr;
    char szConnStrOut[256];
    rc = SQLAllocEnv(&hEnv);
    rc = SQLAllocConnect(hEnv, &hDbc);
    rc = SQLDriverConnect(hDbc, NULL, (unsigned char *) szDSN,
                          SQL_NTS, (unsigned char *) szConnStrOut,
                          255, (SQLSMALLINT *) &iConnStrLength2Ptr, SQL_DRIVER_NOPROMPT);
    if (SQL_SUCCEEDED(rc)) {
        //printf("Access Connect Succeeded!\n");
        return 1;
    } else {
        //printf("Access Connect Failed!\n");
        return 0;
    }
}

/**
 * @brief 断开Access数据库连接
 * @return 是否断连成功
 * @retval 0 失败
 * @retval 1 成功
 */
void SqlDisConn() {
    SQLDisconnect(hDbc);
    SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
    SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
    //printf("Access DisConnect Succeed!\n");
}

/**
 * @brief 执行SQL语句
 * @param[in] table 表名
 * @return 是否成功
 * @retval 0    失败
 * @retval 1    成功
 */
int SqlExecute(char *query) {
    rc = SQLAllocStmt(hDbc, &hstmt);
    rc = SQLPrepare(hstmt, (SQLCHAR *) query, SQL_NTS);
    rc = SQLExecute(hstmt);
    if (SQL_SUCCEEDED(rc)) {
        //printf("SQL Execute Succeeded!\n");
        return 1;
    } else {
        //printf("SQL Execute Failed!\n");
        return 0;
    }
}

/**
 * @brief 字符串连接
 * @param[in] str 原字符串
 * @param[in] list 原字符串
 * @return temp 目的字符串
 */
char *link(char *str, va_list list) {
    char *temp;//目的字符串
    int len1;//原字符串
    int len2;//原字符串
    temp = (char *) malloc(128);
    memset(temp, 0, sizeof(temp));
    len1 = strlen(str) + 1;
    strcat_s(temp, len1, str);
    len2 = strlen(temp) + strlen(list) + 1;
    strcat_s(temp, len2, list);
    return temp;
}

/**
 * @brief 连接至数据库中某一个表
 * @return 是否连接成功
 * @retval 0 失败
 * @retval 1 成功
 */
int TableConn(char *table) {
    char *query = link("select * from ", table);
    if (SqlExecute(query)) {
        //printf("Table %s Connect Succeeded!\n",table);
        return 1;
    } else {
        //printf("Table %s Connect Failed!\n",table);
        return 0;
    }
}

/**
 * @brief 向数据库指定表内添加信息
 * @param[in] table 表名
 * @param[in] ... 表中所需值，若某条信息不输入则用对应的默认值填充
 * @return 是否成功
 * @retval 0    失败
 * @retval 1    成功
 */
__attribute__((unused)) int SqlAdd(char *table, ...) {
    SQLSMALLINT colNum = 0;//列数
    SQLSMALLINT colCount = 0;//当前列
    va_list list;
    char *str2;
    char *str1;
    char *query;//SQL语句
    if (SqlConn()) {
        va_start(list, table);
        str2 = link("(\'", va_arg(list, char*));
        if (TableConn(table)) {
            SQLNumResultCols(hstmt, &colNum);
            for (colCount = 1; colCount < colNum; colCount++) {
                str2 = link(str2, link("\'\,\'", va_arg(list, char*)));
            }
        }
        str2 = link(str2, "\')");
        va_end(list);
        str1 = link(link("insert into ", table), " values ");
        query = link(str1, str2);
        //printf("SQL:%s\n",query);
        if (SqlExecute(query)) {
            SqlDisConn();
            printf("Add Succeeded!\n");
            return 1;
        } else {
            SqlDisConn();
            printf("Add Failed!\n");
            return 0;
        }
    } else {
        printf("Couldn't connect to %s.\n", szDSN);
        return 0;
    }
}

/**
 * @brief 清空数据库中指定表
 * @param[in] table 数据库中指定的表
 * @return 是否清空成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int SqlClear(char *table) {
    char *query;//SQL语句
    query = link("delete * from ", table);
    if (SqlConn()) {
        if (TableConn(table)) {
            //printf("SQL:%s\n",query);
            if (SqlExecute(query)) {
                SqlDisConn();
                printf("Clear Succeeded!\n");
                return 1;
            } else {
                SqlDisConn();
                printf("Clear Failed!\n");
                return 0;
            }
        } else {
            printf("Clear Failed!\n");
            return 0;
        }
    } else {
        printf("Couldn't connect to %s.\n", szDSN);
        return 0;
    }
}


/**
 * @brief 删除数据库中指定表中的某一条
 * @param[in] table 数据库中指定的表
 * @param[in] keyName 主键名
 * @param[in] key 主键属性
 * @return 是否删除成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int SqlDel(char *table, char *keyName, char *key) {
    char *query;//SQL语句
    char *str1 = link(link("delete from ", table), " where ");
    char *str2 = link(link(str1, keyName), "=\'");
    query = link(link(str2, key), "\'");
    if (SqlConn()) {
        //printf("SQL:%s\n",query);
        if (SqlExecute(query)) {
            SqlDisConn();
            printf("Delete Succeeded!\n");
            return 1;
        } else {
            SqlDisConn();
            printf("Delete Failed!\n");
            return 0;
        }
    } else {
        printf("Couldn't connect to %s.\n", szDSN);
        return 0;
    }
}

/**
 * @brief 修改指定表下某一条的全部值
 * @param[in] table 表名
 * @param[in] keyName 主键名
 * @param[in] key 主键
 * @param ... 修改后的值
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int SqlChangeRow(char *table, char *keyName, char *key, ...) {
    SQLSMALLINT colNum = 0;//列数
    SQLSMALLINT colCount = 0;//当前列
    SQLCHAR colName[128] = {'\0'};//列名
    int n = 1;//布尔值
    char name[20][128];//存放所有列名
    va_list list;
    if (SqlConn()) {
        va_start(list, key);
        if (TableConn(table)) {
            SQLNumResultCols(hstmt, &colNum);
            for (colCount = 1; colCount <= colNum; colCount++) {
                SQLDescribeCol(hstmt, colCount, colName, sizeof(colName), 0, 0, 0, 0, 0);

                strcpy(name[colCount], (char *) colName);

                //printf("colCount=%d name[%d]=%s\n",colCount,colCount,name[colCount]);
            }
            for (colCount = 1; colCount <= colNum; colCount++) {
                //printf("colCount=%d name[%d]=%s\n",colCount,colCount,name[colCount]);
                if (SqlChange(table, keyName, key, name[colCount], va_arg(list, char*))) {}
                else {
                    n = 0;
                }
            }
            va_end(list);
        }
    }
    return n;
}

/**
 * @brief 修改指定表下特定的某一条下的某一列的值
 * @param[in] table 表名
 * @param[in] keyName 主键名
 * @param[in] key 主键属性
 * @param[in] colName 列名
 * @param[in] value 修改后的值
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int SqlChange(char *table, char *keyName, char *key, char *colName, char *value) {
    char *str1 = link(link("update ", table), " set ");
    char *str2 = link(link(str1, colName), " = \'");
    char *str3 = link(link(str2, value), "\' where ");
    char *str4 = link(link(str3, keyName), " = \'");
    char *query = link(link(str4, key), "\'");
    if (SqlConn()) {
        //printf("SQL:%s\n",query);
        if (SqlExecute(query)) {
            SqlDisConn();
            printf("Change Succeeded!\n");
            return 1;
        } else {
            SqlDisConn();
            printf("Change Failed!\n");
            return 0;
        }
    } else {
        printf("Couldn't connect to %s.\n", szDSN);
        return 0;
    }
}

/**
 * @brief 返回某表的全部信息
 * @param[in] table 该表表名
 * @param[out] values 每一行的全部信息
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int SqlFindAll(char *table, char values[128][128]) {
    SQLSMALLINT colNum = 0;//列数
    SQLSMALLINT colCount = 0;//当前列
    int n = 0;//偏移量，每返回一行，增加对应表的列数
    char *query = link("select * from ", table);
    char chval[20][128];//临时变量，存放一行结果
    if (SqlConn()) {
        printf("SQL:%s\n", query);
        if (SqlExecute(query)) {
            SQLNumResultCols(hstmt, &colNum);
            rc = SQLAllocStmt(hDbc, &hstmt);
            rc = SQLPrepare(hstmt, (SQLCHAR *) query, SQL_NTS);
            for (colCount = 1; colCount <= colNum; colCount++) {
                SQLBindCol(hstmt, colCount, SQL_C_CHAR, &chval[colCount], 128, 0);
            }
            rc = SQLExecute(hstmt);
            rc = SQLFetch(hstmt);
            while (SQL_SUCCEEDED(rc)) {
                for (colCount = 1; colCount <= colNum; colCount++) {
                    strcpy(values[colCount - 1 + n], chval[colCount]);
                }
                rc = SQLFetch(hstmt);
                n += colNum;
            };
            rc = SQLFreeStmt(hstmt, SQL_DROP);
            SqlDisConn();
            printf("Find Succeeded!\n");
            return 1;
        } else {
            SqlDisConn();
            printf("Find Failed!\n");
            return 0;
        }
    } else {
        printf("Couldn't connect to %s.\n", szDSN);
        return 0;
    }
}

/**
 * @brief 在指定表下查找某条的全部信息
 * @param[in] table 表名
 * @param[in] keyName 主键名
 * @param[in] key 主键属性
 * @param[out] values 全部信息
 * @attention values内信息全部以char*类型存储，如果想要获取其他类型数据注意相关转换
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int SqlFindRow(char *table, char *keyName, char *key, char values[128][128]) {
    SQLSMALLINT colNum = 0;//列数
    SQLSMALLINT colCount = 0;//当前列
    SQLCHAR colName[128] = {'\0'};//列名
    char *str1 = "", *str2, *str3, *str4, *query;
    char name[20][128];//存放所有列名
    char chval[20][128];//临时变量，存放一行结果
    strcpy(name[0], "select ");
    if (SqlConn()) {
        if (TableConn(table)) {
            SQLNumResultCols(hstmt, &colNum);
            for (colCount = 1; colCount <= colNum; colCount++) {
                SQLDescribeCol(hstmt, colCount, colName, sizeof(colName), 0, 0, 0, 0, 0);
                strcpy(name[colCount], (char *) colName);
                if (colCount == 1) {
                    str1 = link(str1, name[colCount]);
                } else {
                    str1 = link(str1, link("\,", name[colCount]));
                }
            }
            str2 = link(link(name[0], str1), " from ");
            str3 = link(link(str2, table), " where ");
            str4 = link(link(str3, keyName), "=\'");
            query = link(link(str4, key), "\'");
            printf("SQL:%s\n", query);
            if (SqlExecute(query)) {
                for (colCount = 1; colCount <= colNum; colCount++) {
                    SQLBindCol(hstmt, colCount, SQL_C_CHAR, &chval[colCount], 128, 0);
                }
                rc = SQLFetch(hstmt);
                while (SQL_SUCCEEDED(rc)) {
                    for (colCount = 1; colCount <= colNum; colCount++) {
                        strcpy(values[colCount - 1], chval[colCount]);
                    }
                    rc = SQLFetch(hstmt);
                };
                rc = SQLFreeStmt(hstmt, SQL_DROP);
                SqlDisConn();
                printf("Find Succeeded!\n");
                return 1;
            } else {
                SqlDisConn();
                printf("Find Failed!\n");
                return 0;
            }
        }
    } else {
        printf("Couldn't connect to %s.\n", szDSN);
        return 0;
    }
}

/**
 * @brief 在指定表下查找某列的全部信息
 * @param[in] table 表名
 * @param[in] colName 列名
 * @param[out] values 全部信息
 * @attention values内信息全部以char*类型存储，如果想要获取其他类型数据注意相关转换
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int SqlFindCol(char *table, char *colName, char values[128][128]) {
    SQLSMALLINT rowNum = 0;//行数
    SQLSMALLINT rowCount = 0;//当前行
    SQLSMALLINT colNum = 0;//列数
    SQLSMALLINT colCount = 0;//当前列
    //char name[128]={'\0'};
    char chval[128];//临时变量，依次存放每行结果
    char *str = link(link("select ", colName), " from ");
    char *query = link(str, table);
    if (SqlConn()) {
        if (TableConn(table)) {
            SQLNumResultCols(hstmt, &colNum);
            printf("SQL:%s\n", query);
            if (SqlExecute(query)) {
                SQLNumResultCols(hstmt, &colNum);
                rc = SQLAllocStmt(hDbc, &hstmt);
                rc = SQLPrepare(hstmt, (SQLCHAR *) query, SQL_NTS);
                SQLBindCol(hstmt, 1, SQL_C_CHAR, &chval, 128, 0);
                rc = SQLExecute(hstmt);
                rc = SQLFetch(hstmt);
                while (SQL_SUCCEEDED(rc)) {
                    for (colCount = 1; colCount <= colNum; colCount++) {
                        strcpy(values[colCount - 1 + rowCount], chval);
                    }
                    rc = SQLFetch(hstmt);
                    rowCount++;
                };
                rc = SQLFreeStmt(hstmt, SQL_DROP);
                SqlDisConn();
                printf("Find Succeeded!\n");
                return 1;
            } else {
                SqlDisConn();
                printf("Find Failed!\n");
                return 0;
            }
        }
    } else {
        printf("Couldn't connect to %s.\n", szDSN);
        return 0;
    }
}

/**
 * @brief 查询指定表下数据某一条指定列下的数据
 * @param[in] table 表名
 * @param[in] keyName 主键名
 * @param[in] key 主键属性
 * @param[in] colName 列名
 * @param[out] value 查找的信息
 * @attention value内信息以char*类型储存，如果获取的是其他类型数据注意转换
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int SqlFind(char *table, char *keyName, char *key, char *colName, char *value) {
    SQLSMALLINT colNum = 0;//列数
    SQLSMALLINT colCount = 0;//当前列
    char chval[128];//临时存放查询结果
    char *str1 = link(link("select ", colName), " from ");
    char *str2 = link(link(str1, table), " where ");
    char *str3 = link(link(str2, keyName), " =\'");
    char *query = link(link(str3, key), "\'");
    if (SqlConn()) {
        if (TableConn(table)) {
            SQLNumResultCols(hstmt, &colNum);
            printf("SQL:%s\n", query);
            if (SqlExecute(query)) {
                SQLBindCol(hstmt, 1, SQL_C_CHAR, &chval, 128, 0);
                rc = SQLFetch(hstmt);
                if (SQL_SUCCEEDED(rc)) {
                    strcpy(value, chval);
                    //rc = SQLFetch(hstmt);
                };
                rc = SQLFreeStmt(hstmt, SQL_DROP);
                SqlDisConn();
                printf("Find Succeeded!\n");
                return 1;
            } else {
                SqlDisConn();
                printf("Find Failed!\n");
                return 0;
            }
        }
    } else {
        printf("Couldn't connect to %s.\n", szDSN);
        return 0;
    }
}

/**
 * @brief 为指定表添加一列
 * @param[in] table 表名
 * @param[in] colName 列名
 * @return 是否添加成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int SqlAddCol(char *table, char *colName) {
    char *str = link(link("alter table ", table), " add ");
    char *query = link(link(str, colName), " varchar(100) ");
    if (SqlConn()) {
        printf("SQL:%s\n", query);
        if (SqlExecute(query)) {
            SqlDisConn();
            printf("Column Add Succeeded!\n");
            return 1;
        } else {
            SqlDisConn();
            printf("Column Add Failed!\n");
            return 0;
        }
    } else {
        printf("Couldn't connect to %s.\n", szDSN);
        return 0;
    }
}

/**
 * @brief 为指定表删除某一列
 * @param[in] table 表名
 * @param[in] colName 列名
 * @return 是否删除成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int SqlDelCol(char *table, char *colName) {
    char *str = link(link("alter table ", table), " drop column ");
    char *query = link(str, colName);
    if (SqlConn()) {
        printf("SQL:%s\n", query);
        if (SqlExecute(query)) {
            SqlDisConn();
            printf("Column Delete Succeeded!\n");
            return 1;
        } else {
            SqlDisConn();
            printf("Column Delete Failed!\n");
            return 0;
        }
    } else {
        printf("Couldn't connect to %s.\n", szDSN);
        return 0;
    }
}


void main() {
    char value[20];
    char values[20][128];
    int i;

    //SqlAdd("student","S2222","hahfa","男","20","C2222");

    //SqlClear("teacher");

    //SqlDel("student","student_id","S1111");

    //SqlChange("student","student_id","S2222","student_name","avedh");

    //SqlChangeRow("student","student_id","S2222","S2222","svdkjb","男","23","C3333");

    //SqlChangeCol("student","age","99");

    //SqlAddCol("teacher","blbl");

    //SqlDelCol("teacher","blbl");

    /*SqlFindAll("student",values);
    for(i=0;i<20;i++){
        printf("%s ",values[i]);
    }printf("\n");*/

    /*SqlFindRow("student","student_id","S2222",values);
    for(i=0;i<5;i++){
        printf("%s ",values[i]);
    }printf("\n");*/

    /*SqlFindCol("student","student_name",values);
    for(i=0;i<5;i++){
        printf("%s ",values[i]);
    }printf("\n");*/


    /*if(SqlFind("student","student_id","S2222","student_name",value))
        printf("%s ",value);*/
    getchar();
}