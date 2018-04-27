#pragma once
#ifndef ENV_STATES_FUNCTIONS_H
#define ENV_STATES_FUNCTIONS_H
#include <app.h>
#include <mysql.h>
#include <my_global.h>


extern const char *plantLocationStringArray[8];
extern int looped;
extern int envCounter;
extern int firstEnv;
extern char storeBuf[400];
extern char* storeBuf2[400];
extern int firstEnvFn2Flag;


void envResultsFn2(char* str);
void envResultsFn(App app, char* str);

void environmentfn(App *app);
void environmentfn2(App *app);
void environmentfn3(App *app);
void envZeroMatches(App *app);
void envResultsBufFn(App *app, char str);
void envResultsFn(App *app, char str);
#endif
