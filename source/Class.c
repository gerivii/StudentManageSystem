//
// Created by HPP on 2021/12/28.
//

#include "../head/Class.h"
#include "../head/SQL.h"

#include <string.h>


__attribute__((unused)) int ClassAdd(char *id, char *name, char *size) {
    return SqlAdd("class", id, name, size);
}

__attribute__((unused)) int ClassDel(char *id) {
    return SqlDel("class", "class_id", id);
}

__attribute__((unused)) int ClassEdit(char *id, char *name, char *size) {
    return SqlChangeRow("class", "class_id", id, name, size);
}

__attribute__((unused)) int ClassEditName(char *id, char *name) {
    return SqlChangeRow("class", "class_id", id, name);
}

__attribute__((unused)) int ClassEditSize(char *id, char *size) {
    return SqlChangeRow("class", "class_id", id, size);
}

__attribute__((unused)) int ClassFind(char *id, char *name, char *size) {
    char values[20][128];
    if (!SqlFindRow("class", "class_id", id, values))
        return 0;
    strcpy(name, values[1]);
    strcpy(size, values[2]);
    return 1;
}

