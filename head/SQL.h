//
// Created by wzt13 on 2021/12/16.
//

#ifndef STUDENTMANAGESYSTEM_SQL_H
#define STUDENTMANAGESYSTEM_SQL_H

int SalAdd(char *table, ...);

int SqlDel(char *table, char *key, char *colName, int mode);

int SqlChange(RETCODE &rc, char *query);

int SqlFind(RETCODE &rc, char *query);
//int SqlConn(RETCODE &rc);


#endif //STUDENTMANAGESYSTEM_SQL_H
