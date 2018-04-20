/* project.c  -- simple app
*
* prompt: "say 'apple' or 'banana'."
* report: "You said <the utterance recognized>."
*/
#include <stdlib.h>	/* exit() */
#include <string.h>
#include <app.h>
#include <nl.h>
#include <recresult.h>
#include <time.h>
#include <stdio.h>
#include <mysql.h>
#include <my_global.h>

//#include <tom.h>
char* sql_food(char* food);
char* sql_country(char* country);
void printDate(void);
char* concat(const char *s1, const char *s2);
char* intToStr(int num);
const char* returnDate(void);
char* returnTime(void);
char* integer_to_string(int x);
char* returnMySQLVersion(void);
void finish_with_error(MYSQL *con);
char* sql_medic(char* condition);
void goDoSQL(App *app, char* purpose, char* specific);
char* sql_general(char* type, char* query);
void goDoAllTheSQL(App *app, char* purpose, char* specific);

void RootEntryFn(App *app)
{
	AppSetBeginSpeechTimeout(app, (float)30.0);
	AppSetEndSpeechTimeout(app, (float)30.0);
	AppSetEndRecognitionTimeout(app, (float)30.0);
	AppSetRejectionThreshold(app, 35);
}

void RootPostRecFn(App *app)
{
	UttStatus status = AppGetUttStatus(app);
	switch (status) {
	case UTT_NORMAL:
	case UTT_SESSION_ABORTED:
		break;
	case UTT_REJECT:
	case UTT_BEGIN_SPEECH_TIMEOUT:
	case UTT_END_SPEECH_TIMEOUT:
	case UTT_END_RECOGNITION_TIMEOUT:
		AppAppendPrompt(app, "try_again.wav");
		AppGotoSelf(app);
		break;
	default:
		fprintf(stderr, "Unexpected utterance status\n");
		AppAppendTTSPrompt(app, "Try Again");
		//AppAppendPrompt(app, "try_again.wav");
		AppGotoSelf(app);
		break;
	}
}

void startfn(App *app) {
	AppCreateState(app, "start", "root", startfn); 
	AppSetGrammar(app, ".Start");
	char buf[100];
	printf("\nHello. Have you used this service before?\n");
	AppAppendTTSPrompt(app, "Hello. Have you used this service before?");

	NLGetStringSlotValue(AppGetNLResult(app), "binary_response_said", buf, 100);
	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}
	if (!strcmp(buf, "yes_said")) {
		printf("Welcome back!\n");
		//AppAppendTTSPrompt(app, "You said egg egg egg egg.");
		AppGoto(app, "greeting");
	}
	else if (!strcmp(buf, "no_said")) {
		printf("Loading introduction...\n");
		//AppAppendTTSPrompt(app, "You said egg egg egg egg.");
		AppAppendTTSPrompt(app, "I am here to help you in finding the perfect plant. I have access to a database of over 7500 plants. I can help you find plants that grow in various soil types or locations, or I can help you find a plant to help treat a medical problem or to replace a foodstuff.");
		printf("I am here to help you in finding the perfect plant.I have access to a database of over 7500 plants.I can help you find plants that grow in various soil types or locations, or I can help you find a plant to help treat a medical problem or to replace a foodstuff.");
		AppGoto(app, "greeting");
	} else {
		AppAppendTTSPrompt(app, "try again");
		//AppAppendPrompt(app, "try_again.wav");
	}

	AppGotoSelf(app);


}

void firstQfn(App *app) {

}

void foodfn(App *app) {
	AppSetGrammar(app, ".Choice");
	char buf[100];
	printf("\n I can help you find plants that can be used as substitutes for other foods. What foodstuff would you like to replace ? \n");
	AppAppendTTSPrompt(app, "I can help you find plants that can be used as substitutes for other foods. What foodstuff would you like to replace ?");
	NLGetStringSlotValue(AppGetNLResult(app), "fruit_said", buf, 100);

	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}
	if (!strcmp(buf, "egg_said")) {
		printf("You said egg egg egg egg.\n");
		AppAppendTTSPrompt(app, "You said egg egg egg egg.");
		goDoSQL(app, "food", "Egg");
	}
		/*MYSQL *con = mysql_init(NULL);

		if (con == NULL)
		{
			fprintf(stderr, "mysql_init() failed\n");
			exit(1);
		}

		if (mysql_real_connect(con, "localhost", "root", "Ms-dos333",
			"pfaf2innodb", 0, NULL, 0) == NULL)
		{
			finish_with_error(con);
		}

		if (mysql_query(con, sql_food("Egg")))
		{
			finish_with_error(con);
		}


		MYSQL_RES *result = mysql_store_result(con);

		if (result == NULL)
		{
			finish_with_error(con);
		}

		int num_fields = mysql_num_fields(result);
		printf("num_fields: %d", num_fields);
		MYSQL_ROW row;
		AppAppendTTSPrompt(app, "Here are your results: ");
		while ((row = mysql_fetch_row(result)))
		{
			for (int i = 0; i < num_fields; i++)
			{
				printf("%s ", row[i] ? row[i] : "NULL");
				printf("%s ", row[i]);
				AppAppendTTSPrompt(app, row[i]);
			}
			printf("\n");
		}

		mysql_free_result(result);
		mysql_close(con);
	}*/
	AppGotoSelf(app);
}

void goDoAllTheSQL(App *app, char* purpose, char* specific) {


	MYSQL *con = mysql_init(NULL);

	if (con == NULL)
	{
		fprintf(stderr, "mysql_init() failed\n");
		exit(1);
	}

	if (mysql_real_connect(con, "localhost", "root", "Ms-dos333",
		"pfaf2innodb", 0, NULL, 0) == NULL)
	{
		finish_with_error(con);
	}

	if (mysql_query(con, sql_general(purpose, specific)))
	{
		finish_with_error(con);
	}


	//if (strcmp(purpose, "medical") == 0) {

	//	if (mysql_query(con, sql_medic(specific)))
	//	{
	//		finish_with_error(con);
	//	}
	//}
	//else if (strcmp(purpose, "food") == 0) {
	//	if (mysql_query(con, sql_food(specific)))
	//	{
	//		finish_with_error(con);
	//	}
	//}
	//else {
	//	printf("Something's gone wrong");
	//	finish_with_error(con);
	//}




	MYSQL_RES *result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error(con);
	}

	int num_fields = mysql_num_fields(result);
	printf("num_fields: %d", num_fields);
	MYSQL_ROW row;
	AppAppendTTSPrompt(app, "Here are your results: ");
	while ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			printf("%s ", row[i] ? row[i] : "NULL");
			printf("%s ", row[i]);
			AppAppendTTSPrompt(app, row[i]);
		}
		printf("\n");
	}

	mysql_free_result(result);
	mysql_close(con);

}


void goDoSQL(App *app, char* purpose, char* specific) {


	MYSQL *con = mysql_init(NULL);

	if (con == NULL)
	{
		fprintf(stderr, "mysql_init() failed\n");
		exit(1);
	}

	if (mysql_real_connect(con, "localhost", "root", "Ms-dos333",
		"pfaf2innodb", 0, NULL, 0) == NULL)
	{
		finish_with_error(con);
	}

	if (strcmp(purpose, "medical") == 0) {

		if (mysql_query(con, sql_medic(specific)))
		{
			finish_with_error(con);
		}
	}
	else if (strcmp(purpose, "food") == 0) {
		if (mysql_query(con, sql_food(specific)))
		{
			finish_with_error(con);
		}
	}
	else {
		printf("Something's gone wrong");
		finish_with_error(con);
	}




	MYSQL_RES *result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error(con);
	}

	int num_fields = mysql_num_fields(result);
	printf("num_fields: %d", num_fields);
	MYSQL_ROW row;
	AppAppendTTSPrompt(app, "Here are your results: ");
	while ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			printf("%s ", row[i] ? row[i] : "NULL");
			printf("%s ", row[i]);
			AppAppendTTSPrompt(app, row[i]);
		}
		printf("\n");
	}

	mysql_free_result(result);
	mysql_close(con);

}


void greetfn(App *app) {
	AppSetGrammar(app, ".Greet");
	char buf[100];
	//AppAppendTTSPrompt(app, returnMySQLVersion());
	printf("\n%s", returnTime());
	printf("\n%s\n", returnDate());
	//AppAppendTTSPrompt(app, returnTime());
	//AppAppendTTSPrompt(app, "So, you would like to buy a plant? Where abouts do you live?");
	//AppAppendTTSPrompt(app, returnDate());
	AppAppendTTSPrompt(app, "Would you like to find a plant that will grow well in a particular environment, or would you rather search for medicinal or edible plants?");	

	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}
	/*
	* Get the value of the "fruit" slot
	*/
	//AppAppendPrompt(app, "you_said.wav");

	
	NLGetStringSlotValue(AppGetNLResult(app), "fruit_said", buf, 100);

	if (!strcmp(buf, "apple_said")) {
		//AppAppendPrompt(app, "apple.wav");
		AppAppendTTSPrompt(app, "you said food");
		printf("You said you prefer an apple.\n");
		AppGoto(app, "food");
	}
	else if (!strcmp(buf, "medicine_said")) {
		//AppAppendPrompt(app, "apple.wav");
		AppAppendTTSPrompt(app, "you said medicine");
		printf("You said you would like to find a plant to help with a medical problem.\n");
		AppGoto(app, "medicine");
	}
	//else if (!strcmp(buf, "medicine_said")) {
	//	//AppAppendPrompt(app, "apple.wav");
	//	AppAppendTTSPrompt(app, "you said medicine");
	//	printf("You said you would like to find a plant to help with a medical problem.\n");
	//	AppGoto(app, "medicine");
	//}
	else if (!strcmp(buf, "food_said")) {
		//AppAppendPrompt(app, "apple.wav");
		AppAppendTTSPrompt(app, "you said food");
		printf("You said you are interested in food.\n");
		AppGoto(app, "food");
	}
	else if (!strcmp(buf, "banana_said")) {
		//AppAppendPrompt(app, "banana.wav");
		AppAppendTTSPrompt(app, "you said medicine");
		printf("You said you prefer a banana.\n");
		AppGoto(app, "medical");
	}
	else if (!strcmp(buf, "exit_said")) {
		printf("You said exit.\n");
		exit(0);
	}
	else {
		AppAppendTTSPrompt(app, "try again");
		//AppAppendPrompt(app, "try_again.wav");
		printf("You said you prefer a banana.\n");
	}

	AppGotoSelf(app);
}

void environmentfn(App *app) {
	
	
	AppGotoSelf(app);
}

void medicalfn(App *app) {
	AppSetGrammar(app, ".Choice");
	char buf[100];
	
	AppAppendTTSPrompt(app, "Tell me a little more about what you want help with.");



	//Sleep(10000);
	//AppGotoSelf(app);
	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}
	/*
	* Get the value of the "fruit" slot
	*/
	//AppAppendPrompt(app, "you_said.wav");


	NLGetStringSlotValue(AppGetNLResult(app), "condition_said", buf, 100);

	if (!strcmp(buf, "headache_said")) {
		//AppAppendPrompt(app, "apple.wav");
		AppAppendTTSPrompt(app, "I'm sorry to hear about your headache. Can I recommend an analgesic?");
		printf("You said you have a headache.\n");
		goDoAllTheSQL(app, "medicinal", "Analgesic");
	} else if (!strcmp(buf, "cold_said")) {
		//AppAppendPrompt(app, "apple.wav");
		AppAppendTTSPrompt(app, "you said food");
		printf("You said you have a cold. Here, grow a laxative.\n");
		goDoAllTheSQL(app, "medicinal", "Laxative");
	}
	else if (!strcmp(buf, "constipated_said")) {
		AppAppendTTSPrompt(app, "you said you need a massive shit");
		printf("Here, grow a laxative.\n");
		goDoAllTheSQL(app, "medicinal", "Laxative");
	}

	//exit(0);
	
	AppGotoSelf(app);
}

void AllInOneFn(App *app)
{
	char buf[100];

	AppSetGrammar(app, ".Choice");
	//AppAppendPrompt(app, "ask.wav");

	//AppAppendTTSPrompt(app, "would you prefer an apple or a banana? Ball bags.");


	AppAppendTTSPrompt(app, returnMySQLVersion()); 
	printf("\n%s", returnTime());
	printf("\n%s", returnDate());
	AppAppendTTSPrompt(app, returnTime());
	//AppAppendTTSPrompt(app, "So, you would like to buy a plant? Where abouts do you live?");
	AppAppendTTSPrompt(app, returnDate());
	
	
	//AppAppendTTSPrompt(app, returnTime());


	//Sleep(10000);
	//AppGotoSelf(app);
	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}
	/*
	* Get the value of the "fruit" slot
	*/
	//AppAppendPrompt(app, "you_said.wav");

	NLGetStringSlotValue(AppGetNLResult(app), "fruit_said", buf, 100);

	if (!strcmp(buf, "apple_said")) {
		//AppAppendPrompt(app, "apple.wav");
		AppAppendTTSPrompt(app, "you said apple");
		printf("You said you prefer an apple.\n");
	}
	else if (!strcmp(buf, "banana_said")) {
		//AppAppendPrompt(app, "banana.wav");
		AppAppendTTSPrompt(app, "you said banana");
		printf("You said you prefer a banana.\n");
	}
	else if (!strcmp(buf, "exit_said")) {
		printf("You said exit.\n");
		exit(0);
	}
	else {
		AppAppendTTSPrompt(app, "try again");
		//AppAppendPrompt(app, "try_again.wav");
		printf("You said you prefer a banana.\n");
	}

	AppGotoSelf(app);
}

int main(int argc, char *argv[])
{
	App *app;
	app = AppNew(&argc, argv);
	
	

	MYSQL *con = mysql_init(NULL);

	if (con == NULL)
	{
		fprintf(stderr, "mysql_init() failed\n");
		exit(1);
	}

	if (mysql_real_connect(con, "localhost", "root", "Ms-dos333",
		"pfaf2innodb", 0, NULL, 0) == NULL)
	{
		finish_with_error(con);
	}

		if (mysql_query(con, "SELECT `Use` FROM `medicinal uses`;"))
		{
			finish_with_error(con);
		}


	MYSQL_RES *result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error(con);
	}

	int num_fields = mysql_num_fields(result);
	printf("num_fields: %d", num_fields);
	MYSQL_ROW row;

	while ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			printf("%s    ", row[i] ? row[i] : "NULL");
			printf("%s ", row[i]);
		}
		printf("\n");
	}

	mysql_free_result(result);
	mysql_close(con);

	if (app == NULL)
		exit(-1);

	AppCreateStateClass(app, "root", NULL, RootEntryFn, RootPostRecFn);
	AppCreateState(app, "whole_shot", "root", AllInOneFn);
	AppCreateState(app, "first_q", "root", firstQfn);
	AppCreateState(app, "greeting", "root", greetfn);
	AppCreateState(app, "food", "root", foodfn);
	AppCreateState(app, "medicine", "root", medicalfn);
	AppCreateState(app, "environment", "root", environmentfn);

	AppCreateState(app, "start", "root", startfn);
	
	
	AppGo(app, "start");
	return 0;
}


char* concat(const char *s1, const char *s2)
{
	char *result = malloc(strlen(s1) + strlen(s2) + 1);//+1 for the null-terminator
													   //in real code you would check for errors in malloc here
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}

void printDate(void) {
	char* arrDayNames[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" }; // Jeez I hope this works, I haven't done this in ages and it's hard without a compiler..
	SYSTEMTIME st;
	SYSTEMTIME sst;
	GetLocalTime(&st); // Alternatively use GetSystemTime for the UTC version of the time
	GetSystemTime(&sst);
	printf("(s)The current date and time are: %d/%d/%d %d:%d:%d:%d", st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	printf("(s)The day is: %s", arrDayNames[st.wDayOfWeek]);
	printf("(ss)The current date and time are: %d/%d/%d %d:%d:%d:%d", sst.wDay, sst.wMonth, sst.wYear, sst.wHour, sst.wMinute, sst.wSecond, sst.wMilliseconds);
	printf("(ss)The day is: %s", arrDayNames[sst.wDayOfWeek]);
}

char* sql_country(char* country) {
	//concat("SELECT `latin name` FROM `range` WHERE `Britain` IS NOT NULL;")
	char* buff[100];
	char* country_query;
	sprintf(buff, "SELECT `latin name` FROM `range` WHERE `%s` IS NOT NULL;", country);
	printf("\n\n%s\n\n", buff);
	return buff;
}

char* sql_medic(char* condition) {
	//concat("SELECT `latin name` FROM `range` WHERE `Britain` IS NOT NULL;")
	char* buff[100];
	sprintf(buff, "SELECT * FROM `medicinal use details` WHERE `Use`='%s';", condition);
	printf("\n\n%s\n\n", buff);
	return buff;
}
char* sql_general(char* type, char* query) {
	//concat("SELECT `latin name` FROM `range` WHERE `Britain` IS NOT NULL;")
	char* buff[100];
	sprintf(buff, "SELECT * FROM `%s use details` WHERE `Use`='%s';", type, query);
	printf("\n\n%s\n\n", buff);
	return buff;
}

char* sql_food(char* condition) {
	//concat("SELECT `latin name` FROM `range` WHERE `Britain` IS NOT NULL;")
	char* buff[100];
	sprintf(buff, "SELECT * FROM `edible use details` WHERE `Use`='%s';", condition);
	printf("\n\n%s\n\n", buff);
	return buff;
}

const char* returnDate(void)
{
	//static char* months[] = { "Jan", "Feb", "Mar" .... };
	//static char badFood[] = "Unknown";
	//if (month<1 || month>12)
	//		return badFood; // choose whatever is appropriate for bad input. Crashing is never appropriate however.
	//	else
	//		return months[month - 1];


	char* arrDayNames[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" }; // Jeez I hope this works, I haven't done this in ages and it's hard without a compiler..
	char* arrMonthNames[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "Decmber" }; // Jeez I hope this works, I haven't done this in ages and it's hard without a compiler..
	SYSTEMTIME st;
	SYSTEMTIME sst;
	GetLocalTime(&st); // Alternatively use GetSystemTime for the UTC version of the time
	GetSystemTime(&sst);
	//printf("(s)The current date and time are: %d/%d/%d %d:%d:%d:%d", st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	//printf("(s)The day is: %s", arrDayNames[st.wDayOfWeek]);
	//printf("(ss)The current date and time are: %d/%d/%d %d:%d:%d:%d", sst.wDay, sst.wMonth, sst.wYear, sst.wHour, sst.wMinute, sst.wSecond, sst.wMilliseconds);
	//printf("(ss)The day is: %s", arrDayNames[sst.wDayOfWeek]);

	char* s0 = concat("The date is ", arrDayNames[st.wDayOfWeek]);
	char* s1 = concat(s0, " the ");
	//char* s2 = concat(s1, "default");
	//if (st.wDay == 1) {
	int day = st.wDay;
	char d[2];
	d[0] = day;
	d[1] = "\n";
	char* s2 = concat(s1, integer_to_string(st.wDay));
	char* s3 = concat(s2, "th");
	//	}	
	if (st.wDay == 1) {
		char* s3 = concat(s2, "st");
	}
	else if (st.wDay == 2) {
		char* s3 = concat(s2, "nd");
	}
	else if (st.wDay == 3) {
		char* s3 = concat(s2, "rd");
	}
	else {
		char* s3 = concat(s2, "th");
	}

	char* s4 = concat(s3, " of ");
	char* s5 = concat(s4, arrMonthNames[st.wMonth]);
	char* s6 = concat(s5, " ");
	char* s7 = concat(s6, integer_to_string(st.wYear));
	//printf("concat s2 & s3");
	//	free(buffer);

	//char* s3 = concat(s2, "st");
	return s7;
}

//	//char* s2 = concat(st.wday, "th");
//	char* s3 = concat(s1, s2);
//	return s3;
//}
//	char* s4 = concat(s3, "of");
//	char* s5 = concat(s4, st.wMonth);
//	char* s6 = concat(s5, st.wYear);
//	printf("%s", s6);
//	return s6;
//}

char* integer_to_string(int x)
{
	char* buffer = malloc(sizeof(char) * sizeof(int) * 4 + 1);
	if (buffer)
	{
		sprintf(buffer, "%d", x);
	}
	return buffer; // caller is expected to invoke free() on this buffer to release memory
}

char* returnTime(void) {

	SYSTEMTIME st;
	SYSTEMTIME sst;
	GetLocalTime(&st); // Alternatively use GetSystemTime for the UTC version of the time
	GetSystemTime(&sst);
	//printf("(s)The current date and time are: %d/%d/%d %d:%d:%d:%d", st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);
	//printf("(s)The day is: %s", arrDayNames[st.wDayOfWeek]);
	//printf("(ss)The current date and time are: %d/%d/%d %d:%d:%d:%d", sst.wDay, sst.wMonth, sst.wYear, sst.wHour, sst.wMinute, sst.wSecond, sst.wMilliseconds);
	//printf("(ss)The day is: %s", arrDayNames[sst.wDayOfWeek]);

	if (st.wMinute < 30) {
		char* s0 = concat("The time is ", integer_to_string(st.wMinute));
		char* s1;
		if (st.wMinute == 1) {
			s1 = concat(s0, " minute past ");
		}
		else {
			s1 = concat(s0, " minutes past ");
		}
		//printf("time in hours is %d", st.wHour);
		if ((st.wHour >= 12) && (st.wHour <= 18)) {
			int time1 = st.wHour - 12;
			char* s2 = concat(s1, integer_to_string(time1));
			char* s3 = concat(s2, " in the afternoon.");
			return s3;
		}

		if ((st.wHour > 18) && (st.wHour >= 24)) {
			int time1 = st.wHour - 12;
			char* s2 = concat(s1, integer_to_string(time1));
			char* s3 = concat(s2, " in the evening.");
			return s3;
		}

		if ((st.wHour < 12)) {
			int time1 = st.wHour;
			char* s2 = concat(s1, integer_to_string(time1));
			char* s3 = concat(s2, " in the morning.");
			return s3;
		}
	}
	else if (st.wMinute > 30) {
		char* s1;
		int minTime = 60 - st.wMinute;
		char* s0 = concat("The time is ", integer_to_string(minTime));
		if (st.wMinute == 1) {
			s1 = concat(s0, " minute to ");
		}
		else {
			s1 = concat(s0, " minutes to ");
		}
		//		printf("time in hours is %d", st.wHour);
		if ((st.wHour >= 12) && (st.wHour <= 18)) {
			int time1 = st.wHour - 11;
			char* s2 = concat(s1, integer_to_string(time1));
			char* s3 = concat(s2, " in the afternoon.");
			return s3;
		}

		if ((st.wHour > 18) && (st.wHour >= 24)) {
			int time1 = st.wHour - 11;
			char* s2 = concat(s1, integer_to_string(time1));
			char* s3 = concat(s2, " in the evening.");
			return s3;
		}

		if ((st.wHour < 12)) {
			int time1 = st.wHour;
			char* s2 = concat(s1, integer_to_string(time1));
			char* s3 = concat(s2, " in the morning.");
			return s3;
		}
	}
	else if (st.wMinute == 30) {

		if ((st.wHour >= 12) && (st.wHour <= 18)) {
			int time1 = st.wHour - 12;
			char* s2 = concat("The time is half past ", integer_to_string(time1));
			char* s3 = concat(s2, " in the afternoon.");
			return s3;
		}

		if ((st.wHour > 18) && (st.wHour >= 24)) {
			int time1 = st.wHour - 12;
			char* s2 = concat("The time is half past ", integer_to_string(time1));
			char* s3 = concat(s2, " in the evening.");
			return s3;
		}

		if ((st.wHour < 12)) {
			int time1 = st.wHour;
			char* s2 = concat("The time is half past ", integer_to_string(time1));
			char* s3 = concat(s2, " in the morning.");
			return s3;
		}
	}


}

char* returnMySQLVersion(void) {
	printf("\nMySQL client version: %s\n", mysql_get_client_info());
	int main_ver = 0;
	int sub_ver = 0;
	int sub_sub_ver = 0;
	sscanf(mysql_get_client_info(), "%d.%d.%d", &main_ver, &sub_ver, &sub_sub_ver);
	char* ver1 = concat(integer_to_string(main_ver), " point ");
	char* ver2 = concat(ver1, integer_to_string(sub_ver));
	char* ver3 = concat(ver2, " point ");
	char* ver4 = concat(ver3, integer_to_string(sub_sub_ver));
	char* ver5 = concat("My SQL client version is ", ver4);
	return ver5;
}

void finish_with_error(MYSQL *con)
{
	fprintf(stderr, "%s\n", mysql_error(con));
	mysql_close(con);
	exit(1);
}