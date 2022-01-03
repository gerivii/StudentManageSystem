//
// Created by HPP on 2021/12/28.
//
#include "../head/Course.h"
#include "../head/SQL.h"

#include <string.h>

__attribute__((unused)) __attribute__((unused)) int CourseAdd(char *course_id, char *course_name, char *classroom, char *teacher_id) {
    return SqlAdd("Course", course_id, course_name, classroom, teacher_id);
}

__attribute__((unused)) __attribute__((unused)) int CourseDel(char *course_id) {
    return SqlDel("Course", "course_id", course_id);
}

__attribute__((unused)) __attribute__((unused)) int CourseEdit(char *course_id, char *course_name, char *classroom, char *teacher_id) {
    return SqlChangeRow("Course", "course_id", course_id, course_name, classroom, teacher_id);
}

__attribute__((unused)) __attribute__((unused)) int CourseEditName(char *course_id, char *course_name) {
    return SqlChange("Course", "course_id", course_id, "course_name", course_name);
}

__attribute__((unused)) int CourseEditClassroom(char *course_id, char *classroom) {
    return SqlChange("Course", "course_id", course_id, "classroom", classroom);
}

__attribute__((unused)) int CourseEditTeacherId(char *course_id, char *teacher_id) {
    return SqlChange("Course", "course_id", course_id, "teacher_id", teacher_id);
}

__attribute__((unused)) int CourseFind(char *course_id, char *course_name, char *classroom, char *teacher_id) {
    char values[20][128];
    if (!SqlFindRow("Course", "course_id", course_id, values))
        return 0;
    strcpy(course_name, values[1]);
    strcpy(classroom, values[2]);
    strcpy(teacher_id, values[2]);
    return 1;
}

