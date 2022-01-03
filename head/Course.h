/**
 * @file Course.h
 * @brief 课程相关头文件
 * @details 包含课程相关头文件
 * @author gerivii
 * @date 2021-12-16
 * @version 1.0
 */

#ifndef STUDENTMANAGESYSTEM_COURSE_H
#define STUDENTMANAGESYSTEM_COURSE_H

/**
 * @brief 向课程表中添加课程
 * @details 若当前部分属性为空，则用NULL代替
 * @param[in] course_id 课程号，该数据不允许为空
 * @param[in] course_name 课程名
 * @param[in] classroom 所使用教室
 * @param[in] teacher_id 上课教师id，该数据不允许为空
 * @return 是否添加成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int CourseAdd(char *course_id, char *course_name, char *classroom, char *teacher_id);

/**
 * @brief 根据课程id删除课程
 * @param[in] course_id 需要删除的课程id
 * @return 是否删除成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int CourseDel(char *course_id);

/**
 * @brief 根据课程号修改课程的全部信息
 * @details 若当前部分属性为空，则用NULL代替
 * @param[in] course_id 课程id，该数据不允许为空
 * @param[in] course_name 课程名
 * @param[in] classroom 课程所在教室
 * @param[in] teacher_id 上课老师id，该数据不允许为空
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int CourseEdit(char *course_id, char *course_name, char *classroom, char *teacher_id);

/**
 * @brief 根据课程号修改课程的名字
 * @param[in] course_id 课程id
 * @param[in] course_name 课程名
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int CourseEditName(char *course_id, char *course_name);

/**
 * @brief 根据课程号修改课程所在的上课教室
 * @param[in] course_id 课程id
 * @param[in] classroom 课程所在教室
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int CourseEditClassroom(char *course_id, char *classroom);

/**
 * @brief 根据课程号修改课程的教师id
 * @param[in] course_id 课程id
 * @param[in] teacher_id 上课老师id
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int CourseEditTeacherId(char *course_id, char *teacher_id);


/**
 * 根据课程号查找课程相关信息
 * @details 若查询的某一属性为空则该属性会返回NULL
 * @param[in] course_id 课程号
 * @param[out] course_name 课程名
 * @param[out] classroom 所使用教室
 * @param[out] teacher_id 上课教师id
 * @return 是否查找成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int CourseFind(char* course_id, char* course_name, char* classroom, char* teacher_id);


#endif //STUDENTMANAGESYSTEM_COURSE_H
