/**
 * @file Class.h
 * @brief 班级头文件
 * @details 包含管理班级相关的头文件
 * @author gerivii
 * @date 2021-12-16
 * @version 1.0
 */


#ifndef STUDENTMANAGESYSTEM_CLASS_H
#define STUDENTMANAGESYSTEM_CLASS_H


/**
 * @brief 向班级数据库增加新内容，未填写部分应用NULL代替
 * @details 若当前部分属性为空，则用NULL代替
 * @param[in] id 班号，该数据不允许为空
 * @param[in] name 班名
 * @param[in] size 班级人数
 * @return 是否添加成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int ClassAdd(char *id, char *name, char *size);

/**
 * @brief 删除其中一个班级
 * @param[in] id 班号
 * @return 是否删除成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int ClassDel(char *id);


/**
 * @brief 编辑选定班级的全部信息
 * @details 若当前部分属性为空，则用NULL代替
 * @param[in] id 班号，该数据不允许为空
 * @param[in] name 班名
 * @param[in] size 班级人数
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int ClassEdit(char *id, char *name, char *size);

/**
 * @brief 编辑选定班级的名称
 * @param[in] id 班号
 * @param[in] name 班级名
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int ClassEditName(char *id, char *name);


/**
 * @brief 编辑选定班级的人数
 * @param[in] id 班号
 * @param[in] size 焊机人数
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int ClassEditSize(char *id, char *size);


/**
 * @brief 根据班号查找班级信息
 * @details 若查询的某一属性为空则该属性会返回NULL
 * @param[in] id 班号
 * @param[out] name 班名
 * @param[out] size 班级人数
 * @return 是否成功
 * @retval 1 成功
 * @retval 0 失败
 */
__attribute__((unused))  int ClassFind(char *id, char *name, char *size);


#endif //STUDENTMANAGESYSTEM_CLASS_H
