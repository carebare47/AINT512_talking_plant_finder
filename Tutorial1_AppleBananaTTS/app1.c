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
#include "nuance-config.h" 


#include <stdio.h>
#include <mysql.h>
#include <my_global.h>

#include "string_functions.h"
#include "sql_functions.h"
#include "date_time_functions.h"
#include "env_states.h"
#include "test_states.h"
#include "other_states.h"
#include "nuance_states.h"




//#include <tom.h>



const char *plantLocationStringArray[8];

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

void AllInOneFn(App *app){
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
//int main(int argc, char *argv[])
//{
//	App *app;
//	app = AppNew(&argc, argv);
//
//	if (app == NULL)
//		exit(-1);
//
//	AppCreateStateClass(app, "root", NULL, RootEntryFn, RootPostRecFn);
//	AppCreateState(app, "whole_shot", "root", AllInOneFn);
//	AppGo(app, "whole_shot");
//	return 0;
//}


int main(int argc, char *argv[])
{
	printf("test");
	//NuanceStatus statusP;
	//NuanceConfigBuildFromCommandLine(&argc, argv, 1, *statusP);

	App *app;
	
	app = AppNew(&argc, argv);
	
	
	AppSetBargeInAllowed(app, 1);
	//goDoAllTheSQL(app, "edible", "egg");

	if (app == NULL) {
		printf("What's going on here then?");
		sleep(2);
		exit(-1);
	}
	AppCreateStateClass(app, "root", NULL, RootEntryFn, RootPostRecFn);
	AppCreateState(app, "start", "root", startfn);
	
	AppCreateState(app, "askLocale", "root", askLocalefn);
	AppCreateState(app, "changeLocale", "root", changeLocalefn);

	AppCreateState(app, "greeting", "root", greetfn);
	


	AppCreateState(app, "whole_shot", "root", AllInOneFn);
	//AppCreateState(app, "first_q", "root", firstQfn);
	
	AppCreateState(app, "food", "root", foodfn);
	AppCreateState(app, "medicine", "root", medicalfn);
	AppCreateState(app, "environment", "root", environmentfn);
	AppCreateState(app, "env2", "root", environmentfn3);
	AppCreateState(app, "test", "root", testfn);
	AppCreateState(app, "zeroMatchesEnv", "root", envZeroMatches);
	AppCreateState(app, "envResultsBuf", "root", envResultsBufFn);
	AppCreateState(app, "envResults", "root", envResultsFn);
	
	printf("AppGetBargeInAllowed = %d\n", AppGetBargeInAllowed(app));
	AppSetBargeInAllowed(app, 1);
	printf("AppGetBargeInAllowed = %d\n", AppGetBargeInAllowed(app));
	//AppGo(app, "environment");
	AppGo(app, "environment");
	return 0;
}



//
//void tamplateFN(App *app) {
//
//	AppSetGrammar(app, ".");
//	char buf[100];
//
//	AppAppendTTSPrompt(app, ".");
//	
//	if (!AppRecognize(app)) {
//		printf("!AppRec\n");
//		return;
//	}
//	NLGetStringSlotValue(AppGetNLResult(app), ".", buf, 100);
//
//	if (!strcmp(buf, "")) {
//		AppAppendTTSPrompt(app, ".");
//		printf("You said  .\n");
//		AppGoto("");
//	}
//	else if (!strcmp(buf, "")) {
//		AppAppendTTSPrompt(app, ".");
//		printf("You said  .\n");
//		AppGoto("");
//	}
//
//	AppGotoSelf(app);
//}

