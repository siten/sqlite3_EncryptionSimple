﻿// sqlite3_SimpleEncryption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "sqlite3/sqlite3.h"

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int main(int argc, char* argv[]) {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    const char *sql;

    /* Open database */
    rc = sqlite3_open("test.db", &db);

    rc = sqlite3_key(db, "test", 4);
    //rc = sqlite3_rekey(db, "ssssssss", 8);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    }
    else {
        fprintf(stderr, "Opened database successfully\n");
    }

    /* Create SQL statement */
    sql = "CREATE TABLE COMPANY("  \
        "ID INT PRIMARY KEY     NOT NULL," \
        "NAME           TEXT    NOT NULL," \
        "AGE            INT     NOT NULL," \
        "ADDRESS        CHAR(50)," \
        "SALARY         REAL );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "Table created successfully\n");
    }

    /* Create SQL statement */
    sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
        "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
        "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
        "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
        "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
        "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
        "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
        "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "Records created successfully\n");
    }
    sqlite3_close(db);
    return 0;
}