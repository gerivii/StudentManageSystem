/**
 * @file Score.h
 * @brief 分数头文件
 * @details 包含管理分数相关的头文件
 * @author gerivii
 * @date 2021-12-16
 * @version 1.0
 */

#ifndef STUDENTMANAGESYSTEM_SCORE_H
#define STUDENTMANAGESYSTEM_SCORE_H

/**
 * @brief 向成绩表内添加一条数据
 * @details 没有该门课程成绩则分数记为-1
 * @param[in] student_id 学号
 * @param[in] scores 存放所有的分数
 * @return 是否添加成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int ScoreAdd(char *student_id, char scores[10][20]);

/**
 * @brief   根据学生id删除成绩
 * @param[in] student_id    学生id
 * @return  是否修改成功
 * @retval 0    失败
 * @retval 1    成功
 */
__attribute__((unused)) int ScoreDel(char *student_id);

/**
 * @brief 修改对应学生的课程成绩
 * @param[in] student_id 学生id
 * @param[in] course_id 课程具体编号
 * @return 是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int ScoreEdit(char *student_id, char *course_id, char *score);

/**
 * @brief 查找对应学生id下的全部成绩
 * @details 成绩表中为-1的表明该学生没有该课程成绩
 * @param[in] student_id 学生id
 * @param[out] grades 学生成绩
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) int ScoreFind(char *student_id, char * grades);

/**
 * @brief 查找该学生id下对应课程号的成绩
 * @details 成绩为-1则表明该学生没有该课程成绩
 * @param[in] student_id 学生id
 * @param[in] course_id 课程id
 * @param[out] grade 课程成绩
 * @return 是否查询成功
 * @retval 0 失败
 * @retval 1 成功
 */
__attribute__((unused)) char ScoreFindCourse(char *student_id, char *course_id, char *grade);


#endif //STUDENTMANAGESYSTEM_SCORE_H
