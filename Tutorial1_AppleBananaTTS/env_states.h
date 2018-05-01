#pragma once
#ifndef ENV_STATES_FUNCTIONS_H
#define ENV_STATES_FUNCTIONS_H
#include <app.h>
#include <mysql.h>
#include <my_global.h>


extern char plantLocationStringArray[8][36];
extern char plantHabitStringArray[8][36];
extern char errorEnvStringArray[8][24];

extern int looped;
extern int envCounter;
extern int firstEnv;
extern char storeBuf[400];
extern char storeBuf2[400];
extern int firstEnvFn2Flag;
extern int habitCounter;


//const char *plantLocationStringArray[8];
//const char *plantHabitStringArray[8];


extern char errorFixArray[8][24];
extern char errorStoreArray[8][24];

//char *errorFixArray[16];
//char *errorStoreArray[16];
extern int numberStringArray[8];

void envPandHfn(App *app);
void envResultsFn2(char* str);
void envResultsFn(App app, char* str);

void environmentfn(App *app);
void environmentfn2(App *app);
void environmentfn3(App *app);
void envZeroMatches(App *app);
void envResultsBufFn(App *app, char str);
void envResultsFn(App *app, char str);
void envErrorFixfn(App *app);
void envCheckfn(App *app);
void constructAdvancedString(void);

#endif
