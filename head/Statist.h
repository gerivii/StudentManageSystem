/**
 * @file Statist.h
 * @brief 学生查询和统计头文件
 * @details 包含学生资料查询，信息、成绩统计相关的头文件
 * @author gerivii
 * @date 2021-12-16
 * @version 1.0
 */

#ifndef STUDENTMANAGESYSTEM_STATIST_H
#define STUDENTMANAGESYSTEM_STATIST_H

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
__attribute__((unused)) int StuInfo(char *student_id, char *student_name, char *sex, int age, char *class_id);

/**
 * @brief 查询指定学号学生的姓名
 * @param[in] student_id 学号
 * @param[out] student_name 姓名
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int StuName(char *student_id, char *student_name);

/**
 * @brief 查询指定学号学生的性别
 * @param[in] student_id 学号
 * @param[out] student_name 性别
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int StuSex(char *student_id, char *sex);

/**
 * @brief 查询指定学号学生的年龄
 * @param[in] student_id 学号
 * @param[out] student_name 年龄
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int StuAge(char *student_id, int age);

/**
 * @brief 查询指定学号学生的班号
 * @param[in] student_id 学号
 * @param[out] student_name 姓名
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int StuClassId(char *student_id, char *class_id);

/**
 * @brief 查询某门课程的平均分
 * @param[in] course_id 查询课程的课程号
 * @param[out] ave 该课程的平均分
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int Ave(char *course_id, float ave);

/**
 * @brief 查询课程的最高分
 * @param[in] course_id 课程号
 * @param[out] max 最高分
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int Max(char *course_id, float max);

/**
 * @brief 查询课程的最低分
 * @param[in] course_id 课程号
 * @param[out] max 最低分
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int Min(char *course_id, float min);

#endif //STUDENTMANAGESYSTEM_STATIST_H
