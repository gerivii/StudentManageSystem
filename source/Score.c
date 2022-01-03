//
// Created by HPP on 2021/12/28.
//
#include "../head/Score.h"
#include "../head/SQL.h"

#include <string.h>

__attribute__((unused)) int ScoreAdd(char *student_id, char scores[10][20]) {
    return SqlAdd("Score", student_id, scores[0], scores[1], scores[2], scores[3], scores[4], scores[5], scores[6],
                  scores[7], scores[8], scores[9]);
}

__attribute__((unused)) int ScoreDel(char *student_id) {
    return SqlDel("Score", "student_id", student_id);
}

__attribute__((unused)) int ScoreEdit(char *student_id, char *course_id, char *score) {
    return SqlChange("Score", "student_id", student_id, course_id, score);
}

__attribute__((unused)) int ScoreFind(char *student_id, char *grades) {
    char values[20][128];
    if (!SqlFindRow("Score", "student_id", student_id, values))
        return 0;
    strcpy(grades, values[1]);
    return 1;
}

__attribute__((unused)) char ScoreFindCourse(char *student_id, char *course_id, char *grade) {
    if (SqlFind("Score", "student_id", student_id, course_id, grade))
        return 0;
    return 1;
}


