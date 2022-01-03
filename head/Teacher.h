/**
 * @file Teacher.h
 * @brief 教师相关头文件
 * @details 包含教师操作相关的头文件
 * @author gerivii
 * @date 2021-12-16
 * @version 1.0
 */

#ifndef STUDENTMANAGESYSTEM_TEACHER_H
#define STUDENTMANAGESYSTEM_TEACHER_H


/**
 * @brief 向教师表中添加一名教师信息
 * @details 若当前部分属性为空，则用NULL代替
 * @param[in] teacher_id 教师编号，该数据不允许为空
 * @param[in] teacher_name 姓名
 * @param[in] sex 性别，该数据不允许为空
 * @param[in] age 年龄，该数据为空则用0代替
 * @param[in] college 所属学院，该数据不允许为空
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int TeacherAdd(char *teacher_id, char *teacher_name, char *sex, int age, char* college);

/**
 * @brief 删除教师信息
 * @param teacher_id 删除教师的教师编号
 * @return 是否成功删除
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int TeacherDel(char *teacher_id);

/**
* @brief 修改指定教师编号教师的全部信息
* @param[in] teacher_id 教师编号
* @param[in] teacher_name 姓名
* @param[in] sex 性别
* @param[in] age 年龄
* @param[in] college 所属学院
* @return 是否修改成功
* @retval 0 失败
* @retval 1 成功
*/
__attribute__((unused)) int TeacherEdit(char *teacher_id, char *teacher_name, char *sex, int age, char *college);

/**
 * @brief 修改指定教师编号教师的姓名
 * @param[in] teacher_id 教师编号
 * @param[in] teacher_name 姓名
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int TeacherEditName(char *teacher_id, char *teacher_name);

/**
 * @brief 修改指定教师编号教师的性别
 * @param[in] teacher_id 教师编号
 * @param[in] teacher_name 性别
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int TeacherEditSex(char *teacher_id, char *sex);

/**
 * @brief 查询指定教师编号教师的年龄
 * @param[in] teacher_id 教师编号
 * @param[in] teacher_name 年龄
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int TeacherEditAge(char *teacher_id, int age);

/**
 * @brief 查询指定教师编号教师的所属学院
 * @param[in] teacher_id 教师编号
 * @param[in] teacher_name 姓名
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int TeacherEditClassId(char *teacher_id, char *college);

/**
 * @brief 查询指定教师编号教师的全部信息
 * @param[in] teacher_id 教师编号
 * @param[out] teacher_name 姓名
 * @param[out] sex 性别
 * @param[out] age 年龄
 * @param[out] college 所属学院
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int TeacherFind(char *teacher_id, char *teacher_name, char *sex, int age, char *college);


#endif //STUDENTMANAGESYSTEM_TEACHER_H
