#include "../head/Statist.h"
#include "../head/Score.h"
#include "../head/SQL.h"

#include <string.h>

__attribute__((unused)) int StuInfo(char* student_id, char* student_name, char* sex, int age, char* class_id) {
    char values[20][128];
    if (!SqlFindRow("student", "student_id", student_id, values))
        return 0;
    strcpy(name, values[1]);
    strcpy(sex, values[2]);
    strcpy(age, values[3]);
    strcpy(class_id, values[4]);
    return 1;
}

__attribute__((unused)) int StuName(char* student_id, char* student_name) {
    if (!SqlFind("student", "student_id", student_id, student_id))
        return 0;
    return 1;
}

__attribute__((unused)) int StuSex(char* student_id, char* sex) {
    if (!SqlFind("student", "student_id", student_id, sex))
        return 0;
    return 1;
}

__attribute__((unused)) int StuAge(char* student_id, int age) {
    if (!SqlFind("student", "student_id", student_id, age))
        return 0;
    return 1;
}

__attribute__((unused)) int StuClassId(char* student_id, char* class_id) {
    if (!SqlFind("student", "student_id", student_id, class_id))
        return 0;
    return 1;
}

__attribute__((unused)) int Ave(char* course_id, float ave) {
    char values[128];
    float k;

    int i, j = 0;

    if (!SqlFindRow("Course", "course_id", course_id, values))
        return 0;

    for (i = 0; i < 128; i++) {
        if (values[i] != "-1") {
            k += atof(values[i]);
            j++;
        }
    }

    ave = (k / j);
    return 1;
}

__attribute__((unused)) int Max(char* course_id, float max) {
    char values[128];
    float num1 = 0, num2;

    int i;

    if (!SqlFindRow("Course", "course_id", course_id, values))
        return 0;

    for (i = 0; i < 128; i++) {
        if (values[i] != "-1") {
            num2 = atof(values[i]);
            if (strcmp(num1, num2) < 0)
                num1 = num2;
        }
    }

    max = num1;
    return 1;
}

__attribute__((unused)) int Min(char* course_id, float min) {
    char values[128];
    float num1 = 150, num2;

    int i;

    if (!SqlFindRow("Course", "course_id", course_id, values))
        return 0;

    for (i = 0; i < 128; i++) {
        if (values[i] != "-1") {
            num2 = atof(values[i]);
            if (strcmp(num1, num2) > 0)
                num1 = num2;
        }
    }

    min = num1;
    return 1;
}
