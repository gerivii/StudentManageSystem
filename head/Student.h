/**
 * @file Student.h
 * @brief 学生相关头文件
 * @details 包含学生操作相关的头文件
 * @author gerivii
 * @date 2021-12-16
 * @version 1.0
 */

#ifndef STUDENTMANAGESYSTEM_STUDENT_H
#define STUDENTMANAGESYSTEM_STUDENT_H


/**
 * @brief 向学生表中添加一名学生信息
 * @details 若当前部分属性为空，则用NULL代替
 * @param[in] teacher_id 学号，该数据不允许为空
 * @param[in] student_name 姓名
 * @param[in] sex 性别，该数据不允许为空
 * @param[in] age 年龄，该数据为空则用0代替
 * @param[in] class_id 班号，该数据不允许为空
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int StudentAdd(char *teacher_id, char *student_name, char *sex, int age, char* class_id);

/**
 * @brief 删除学生信息
 * @param student_id 删除学生的学号
 * @return 是否成功删除
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int StudentDel(char *student_id);

/**
* @brief 修改指定学号学生的全部信息
* @param[in] student_id 学号
* @param[in] student_name 姓名
* @param[in] sex 性别
* @param[in] age 年龄
* @param[in] class_id 班号
* @return 是否修改成功
* @retval 0 失败
* @retval 1 成功
*/
__attribute__((unused)) int StudentEdit(char *student_id, char *student_name, char *sex, int age, char *class_id);

/**
 * @brief 修改指定学号学生的姓名
 * @param[in] student_id 学号
 * @param[in] student_name 姓名
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int StudentEditName(char *student_id, char *student_name);

/**
 * @brief 修改指定学号学生的性别
 * @param[in] student_id 学号
 * @param[in] student_name 性别
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int StudentEditSex(char *student_id, char *sex);

/**
 * @brief 查询指定学号学生的年龄
 * @param[in] student_id 学号
 * @param[in] student_name 年龄
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int StudentEditAge(char *student_id, int age);

/**
 * @brief 查询指定学号学生的班号
 * @param[in] student_id 学号
 * @param[in] student_name 姓名
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int StudentEditClassId(char *student_id, char *class_id);

/**
 * @brief 查询指定学号学生的全部信息
 * @param[in] student_id 学号
 * @param[out] student_name 姓名
 * @param[out] sex 性别
 * @param[out] age 年龄
 * @param[out] class_id 班号
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int StudentFind(char *student_id, char *student_name, char *sex, int age, char *class_id);


#endif //STUDENTMANAGESYSTEM_STUDENT_H
