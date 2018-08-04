#pragma once
#ifndef TEST_STATES_H
#define TEST_STATES_H
#include <app.h>
#include <mysql.h>
#include <my_global.h>


extern int firstTestFlag;
extern const char* locale;

void testfn(App *app);


#endif