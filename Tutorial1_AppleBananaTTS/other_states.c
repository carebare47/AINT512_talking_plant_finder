#pragma once
#include "other_states.h"
const char* locale = "Britain";
int firstRunFlag = 1;
void askLocalefn(App *app) {

	AppSetGrammar(app, ".Start");
	char buf[100];

	AppAppendTTSPrompt(app, concat("You are currently searching for plants that will grow in ", locale));
	//AppAppendTTSPrompt(app, concat("You're locale is currently set to ", locale));
	AppAppendTTSPrompt(app, "Would you like to change that?");

	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}

	NLGetStringSlotValue(AppGetNLResult(app), "binary_response_said", buf, 100);

	if (!strcmp(buf, "yes_said")) {
		//AppAppendPrompt(app, "apple.wav");
		printf("You said you would like to change your locale.\n");
		AppGoto(app, "changeLocale");
	}
	else if (!strcmp(buf, "no_said")) {
		//AppAppendPrompt(app, "apple.wav");
		printf("You're happy to look for plants that will grow well in %s", locale);
		AppGoto(app, "greeting");
	}


	AppGotoSelf(app);
}
void changeLocalefn(App *app) {


	AppSetGrammar(app, ".Locale");
	char buf[100];

	AppAppendTTSPrompt(app, "Which location would you like to search in?");

	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}
	NLGetStringSlotValue(AppGetNLResult(app), "locale_said", buf, 100);



	if (!strcmp(buf, "africa_said")) {
		AppAppendTTSPrompt(app, "You said Africa.");
		printf("You said Africa.\n");
		locale = "Africa";
		AppGoto(app, "greeting");
	}
	else if (!strcmp(buf, "australasia_said")) {
		AppAppendTTSPrompt(app, "You said Australasia.");
		printf("You said Australasia.\n");
		locale = "Australasia";
		AppGoto(app, "greeting");
	}
	else if (!strcmp(buf, "britain_said")) {
		AppAppendTTSPrompt(app, "You said Britain.");
		printf("You said Britain.\n");
		locale = "Britain";
		AppGoto(app, "greeting");
	}
	else if (!strcmp(buf, "asia_said")) {
		AppAppendTTSPrompt(app, "You said Asia.");
		printf("You said Asia.\n");
		locale = "Asia";
		AppGoto(app, "greeting");
	}
	else if (!strcmp(buf, "europe_said")) {
		AppAppendTTSPrompt(app, "You said Europe.");
		printf("You said Europe.\n");
		locale = "Europe";
		AppGoto(app, "greeting");
	}
	else if (!strcmp(buf, "mediterranean_said")) {
		AppAppendTTSPrompt(app, "You said Mediterranean.");
		printf("You said Mediterranean.\n");
		locale = "Mediterranean";
		AppGoto(app, "greeting");
	}
	else if (!strcmp(buf, "north_america_said")) {
		AppAppendTTSPrompt(app, "You said North America.");
		printf("You said North America.\n");
		locale = "N America";
		AppGoto(app, "greeting");
	}
	else if (!strcmp(buf, "south_america_said")) {
		AppAppendTTSPrompt(app, "You said South America.");
		printf("You said South America.\n");
		locale = "S America";
		AppGoto(app, "greeting");
	}
	else if (!strcmp(buf, "other_said")) {
		AppAppendTTSPrompt(app, "You said Other.");
		printf("You said Other.\n");
		locale = "Other";
		AppGoto(app, "greeting");
	}
	else {
		AppAppendTTSPrompt(app, "Try again.");
		printf("Try again. \n");
	}

	/*
	Africa_said
	Australasia_said
	Britain_said
	Asia_said
	Europe_said
	Mediterranean_said
	America_said
	Other_said
	America_said
	Asia_said
	*/
	AppGotoSelf(app);
}

void startfn(App *app) {
	//AppCreateState(app, "start", "root", startfn); 
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
		firstRunFlag = 0;
		printf("Welcome back!\n");
		//AppAppendTTSPrompt(app, "You said egg egg egg egg.");
		AppGoto(app, "askLocale");
	}
	else if (!strcmp(buf, "no_said")) {
		firstRunFlag = 1;
		printf("Loading introduction...\n");
		//AppAppendTTSPrompt(app, "You said egg egg egg egg.");
		AppAppendTTSPrompt(app, "I am here to help you in finding the perfect plant. I have access to a database of over 7500 plants. I can help you find plants that grow in various soil types or locations, or I can help you find a plant to help treat a medical problem or to replace a foodstuff.");
		printf("I am here to help you in finding the perfect plant.I have access to a database of over 7500 plants.I can help you find plants that grow in various soil types or locations, or I can help you find a plant to help treat a medical problem or to replace a foodstuff.");
		AppGoto(app, "askLocale");
	}
	else {
		AppAppendTTSPrompt(app, "try again");
		//AppAppendPrompt(app, "try_again.wav");
	}

	AppGotoSelf(app);


}
void greetfn(App *app) {
	AppSetGrammar(app, ".SearchType");
	char buf[100];
	//AppAppendTTSPrompt(app, returnMySQLVersion());
	printf("\n%s", returnTime());
	printf("\n%s\n", returnDate());
	//AppAppendTTSPrompt(app, returnTime());
	//AppAppendTTSPrompt(app, "So, you would like to buy a plant? Where abouts do you live?");
	//AppAppendTTSPrompt(app, returnDate());
	if (firstRunFlag == 1) {
		AppAppendTTSPrompt(app, "Would you like to find a plant that will grow well in a particular environment, or would you rather search for medicinal or edible plants?");
	}
	else if (firstRunFlag == 0) {
		AppAppendTTSPrompt(app, "How can I help?");
	}
	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}
	/*
	* Get the value of the "fruit" slot
	*/
	//AppAppendPrompt(app, "you_said.wav");


	NLGetStringSlotValue(AppGetNLResult(app), "search_type_said", buf, 100);

	if (!strcmp(buf, "environment_said")) {
		//AppAppendPrompt(app, "apple.wav");
		AppAppendTTSPrompt(app, "you said you want to search by environment");
		printf("you said you want to search by environment.\n");
		AppGoto(app, "environment");
	}
	else if (!strcmp(buf, "medicinal_said")) {
		//AppAppendPrompt(app, "apple.wav");
		AppAppendTTSPrompt(app, "you said medicine");
		printf("You said you would like to find a plant to help with a medical problem.\n");
		AppGoto(app, "medicine");
	}
	else if (!strcmp(buf, "edible_said")) {
		//AppAppendPrompt(app, "apple.wav");
		AppAppendTTSPrompt(app, "you said food");
		printf("You said you are interested in food.\n");
		AppGoto(app, "food");
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