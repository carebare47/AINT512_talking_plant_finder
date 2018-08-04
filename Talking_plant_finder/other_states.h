#pragma once
#ifndef OTHER_STATES_H
#define OTHER_STATES_H
#include <app.h>
#include <mysql.h>
#include <my_global.h>

extern int firstRunFlag;

void askLocalefn(App *app);
void changeLocalefn(App *app);
void startfn(App *app);
void greetfn(App *app);

#endif


