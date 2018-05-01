#pragma once
#ifndef SQL_FUNCTIONS_H
#define SQL_FUNCTIONS_H
#include <app.h>
#include <mysql.h>
#include <my_global.h>

void finish_with_error(MYSQL *con);
char* sql_food(char* food);
char* sql_country(char* country);
char* returnMySQLVersion(void);
char* sql_medic(char* condition);
void SQLspeakQuery(App *app, char* str);
void SQLspeakQueryResultsOnly(App *app, char* str);
void goDoSQL(App *app, char* purpose, char* specific);
char* sql_general(char* type, char* query);
void goDoAllTheSQL(App *app, char* purpose, char* specific);
void speakComposition(App *app, char* type, char* str, int speak);
int returnSQLnumberOfMatches(App *app, char* str);
int returnSQLCount(App *app, char* str);
void SQLReverseSearch(App *app, char* str);

#endif
#pragma once
