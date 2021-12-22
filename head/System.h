/**
 * @file System.h
 * @brief 系统头文件
 * @details 包含与系统设置、安全相关的头文件
 * @author gerivii
 * @date 2021-12-16
 * @version 1.0
 */

#ifndef STUDENTMANAGESYSTEM_SYSTEM_H
#define STUDENTMANAGESYSTEM_SYSTEM_H

/**
 * @brief 用户登录函数
 * @param[in] account 用户账号
 * @param[in] password 用户密码
 * @return 用户类型
 * @retval 0 登录失败
 * @retval 1 普通用户
 * @retval 2 管理员
 */
int Login(char *account, char *password);

/**
 * @brief 注册用户
 * @param[in] account
 * @param[out] password
 * @return 是否成功注册
 * @retval 0 失败
 * @retval 1 成功
 */
int Register(char *account, char *password);

/**
 * @brief 删除用户
 * @param[in] account 要删除的用户id
 * @return 是否删除成功
 * @retval 0 失败
 * @retval 1 成功
 */
int DelAccount(char *account);

/**
 * @brief 修改用户权限
 * @param[in] account 该用户账号
 * @param[in] root 修改后的用户权限，0为普通用户，1为管理员用户
 * @return  是否修改成功
 * @retval 0 失败
 * @retval 1 成功
 */
int ChangePermission(char *account, int root);


#endif //STUDENTMANAGESYSTEM_SYSTEM_H
