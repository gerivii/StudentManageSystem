/**
 * @file Page.c
 * @brief 页面源文件
 * @details 包含实现项目视觉相关的函数实现
 * @author gerivii
 * @date 2021-12-16
 * @version 1.0
 */

#include <stdio.h>
#include <unistd.h>


#include "../head/System.h"
#include "../head/Page.h"
#include "../head/Statist.h"
#include "../head/Class.h"
#include "../head/Score.h"
#include "../head/Course.h"
#include "../head/Teacher.h"


int n;
char name[20];
char sex[4];
int age = 0;

char account[20];
char password[20];

char student_id[20];


char class_id[20];
char class_name[20];
char class_size[20];

char course_id[20];
char course_name[20];
char classroom[20];

char teacher_id[20];
char college[20];


__attribute__((unused)) void ShowMain() {


    system("cls");
    printf("----------欢迎登录学生管理系统----------\n");
    printf("功能选择:\n");
    printf("1、用户登录\n");
    printf("2、用户注册\n");
    printf("------------------------------------\n");
    printf("输入您要选择的功能序号,输入其他数字以退出系统:");
    scanf("%d", &n);
    switch (n) {
        case 1:
            printf("账号:");
            scanf("%s", account);
            printf("密码:");
            scanf("%s", password);
            switch (Login(account, password)) {
                case 1:
                    printf("登录成功！\n");
                    sleep(2);
                    ShowStu();
                    break;
                case 2:
                    printf("登录成功！\n");
                    sleep(2);
                    ShowTea();
                    break;
                case 3:
                    printf("登录成功！\n");
                    sleep(2);
                    ShowAdmin();
                    break;
                default:
                    printf("账户或密码错误，登录失败！\n");
                    break;
            }
            break;
        case 2:
            printf("账号:");
            scanf("%s", account);
            printf("密码:");
            scanf("%s", password);
            if (Register(account, password)) {
                printf("注册成功\n");
            } else {
                printf("注册失败\n");
            }
            break;
        default:
            printf("感谢使用本系统!\n");
            break;
    }
}

__attribute__((unused)) void ShowStu() {
    char grade[20];

    system("cls");
    printf("----------欢迎登录学生管理系统----------\n");
    printf("功能选择:\n");
    printf("1、个人信息查询\n");
    printf("2、成绩查询\n");
    printf("------------------------------------\n");
    printf("输入您要选择的功能序号,输入其他数字以退出系统:");
    scanf("%d", &n);
    switch (n) {
        case 1:
            printf("学号:");
            scanf("%s", student_id);
            if (StuInfo(student_id, name, sex, age, class_id)) {
                if (!ClassFind(class_id, class_name, class_size)) {
                    printf("查询失败\n");
                }
                printf("姓名:%s\n", name);
                printf("性别:%s\n", sex);
                printf("年龄:%d\n", age);
                printf("班级:%s\n", class_name);
            } else {
                printf("查询失败\n");
            }
            break;
        case 2:
            printf("学号:");
            scanf("%s", student_id);
            printf("课程号:");
            scanf("%s", course_id);
            if (ScoreFindCourse(student_id, course_id, grade)) {
                if (!CourseFind(course_id, course_name, classroom, teacher_id))
                    printf("查询失败\n");
                else {
                    printf("课程:%s ", course_name);
                    printf("成绩:%s\n", grade);
                }
            } else {
                printf("查询失败\n");
            }
            break;
        default:
            printf("感谢使用!\n");
            break;
    }
}

__attribute__((unused)) void ShowTea() {
    char scores[10][20];
    char temp[20];
    int i = 0;
    float max = 0, min = 0, ave = 0;

    system("cls");
    printf("----------欢迎登录学生管理系统----------\n");
    printf("功能选择:\n");
    printf("1、个人信息查询\n");
    printf("2、学生成绩录入\n");
    printf("3、学生成绩修改\n");
    printf("4、课程成绩统计\n");
    printf("------------------------------------\n");
    printf("输入您要选择的功能序号,输入其他数字以退出系统:");
    scanf("%d", &n);
    switch (n) {
        case 1:
            printf("教师编号:");
            scanf("%s", teacher_id);
            if (TeacherFind(teacher_id, name, sex, age, college)) {
                printf("姓名:%s\n", name);
                printf("性别:%s\n", sex);
                printf("年龄:%d\n", age);
                printf("班级:%s\n", college);
            } else {
                printf("查询失败\n");
            }
            break;
        case 2:
            printf("学生学号:");
            scanf("%s", student_id);
            printf("请依次输入该名学生的每一门成绩，输入-1结束输入\n");
            for (i = 0; i < 10; i++) {
                scanf("%s", temp);
                if (!strcmp(temp, "-1"))
                    break;
                strcpy(scores[i], temp);
            }
            if (ScoreAdd(student_id, scores)) {
                printf("录入成功!\n");
            } else {
                printf("录入失败!\n");
            }
            break;
        case 3:
            printf("学生学号:");
            scanf("%s", student_id);
            printf("需要修改的课程的课程号:");
            scanf("%s", course_id);
            printf("成绩:");
            scanf("%s", temp);
            if (ScoreEdit(student_id, course_id, temp)) {
                printf("修改成功！\n");
            } else {
                printf("修改失败!\n");
            }
            break;
        case 4:
            printf("课程号:");
            scanf("%s", course_id);
            if ((Max(course_id, max) && Min(course_id, min) && Ave(course_id, min))) {
                printf("最高分:%.2f\n最低分:%.2f\n平均分:%.2f", max, min, ave);
            } else {
                printf("查询失败!\n");
            }
        default:
            printf("感谢使用本系统!\n");
            break;

    }

}

