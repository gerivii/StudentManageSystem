/**
 * @file SQL.h
 * @brief 数据头文件
 * @details 包含连接管理数据库库相关的头文件
 * @author gerivii
 * @date 2021-1-2
 * @version 1.2
 */


#ifndef STUDENTMANAGESYSTEM_SQL_H
#define STUDENTMANAGESYSTEM_SQL_H


/**
 * @brief 向数据库指定表内添加信息
 * @param[in] table 表名
 * @param[in] ... 表中所需值，若某条信息不输入则用对应的默认值填充
 * @return 是否成功
 * @retval 0    失败
 * @retval 1    成功
 */
__attribute__((unused)) int SqlAdd(char *table, ...);


/**
 * @brief 删除数据库中指定表中的某一条
 * @param[in] table 数据库中指定的表
 * @param[in] keyName 主键名
 * @param[in] key 主键属性
 * @return 是否删除成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int SqlDel(char *table, char *keyName, char *key);

/**
 * @brief 清空数据库中指定表
 * @param[in] table 数据库中指定的表
 * @return 是否清空成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int SqlClear(char *table);

/**
 * @brief 修改指定表下某一条的全部值
 * @param[in] table 表名
 * @param[in] keyName 主键名
 * @param[in] key 主键属性
 * @param ... 修改后的值
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int SqlChangeRow(char *table, char *keyName, char *key,  ...);

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
__attribute__((unused)) int SqlChange(char *table, char *keyName, char *key, char *colName, char *value);

/**
 * @brief 返回某表的全部信息
 * @param[in] table 该表表名
 * @param[in] keyName 主键名
 * @param[in] key 主键属性
 * @param[out] values 每一行的全部信息
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int SqlFindAll(char *table, char values[128][128]);

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
__attribute__((unused)) int SqlFindRow(char *table, char *keyName, char *key, char values[128][128]);

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
__attribute__((unused)) int SqlFindCol(char *table, char *colName, char values[128][128]);

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
__attribute__((unused)) int SqlFind(char *table, char *keyName, char *key, char *colName,char* value);

/**
 * @brief 为指定表添加一列
 * @param[in] table 表名
 * @param[in] colName 列名
 * @return 是否添加成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int SqlAddCol(char *table, char *colName);

/**
 * @brief 为指定表删除某一列
 * @param[in] table 表名
 * @param[in] colName 列名
 * @return 是否删除成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int SqlDelCol(char *table, char *colName);

#endif //STUDENTMANAGESYSTEM_SQL_H
