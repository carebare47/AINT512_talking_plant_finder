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



char plantLocationStringArray[8][36];
char plantHabitStringArray[8][36];
char errorFixArray[8][24];
char errorStoreArray[8][24];
char errorEnvStringArray[8][24];

int numberStringArray[8];

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
int recognitionFlag = 0;
int firstFreeSpeak = 0;
void freeSpeakfn(App *app) {
	
	AppSetGrammar(app, ".Speak");
	char buf[100];
	
	if (firstFreeSpeak == 0) {
		AppAppendTTSPrompt(app, "How can I help?");
		firstFreeSpeak = 1;
	}
	else {
		AppAppendTTSPrompt(app, "What term would you like to add?");
	}

	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}

	int canopy_said = 2;
	int common_name_said = 2;
	int cultivar_said = 2;
	int cultivatedbeds_said = 2;
	int dappledshade_said = 2;
	int deepshade_said = 2;
	int eastwall_said = 2;
	int groundcover_said = 2;
	int habit_said = 2;
	int habitat_said = 2;
	int hardyness_said = 2;
	int hedge_said = 2;
	int hedgerow_said = 2;
	int height_said = 2;
	int latin_name_said = 2;
	int lawn_said = 2;
	int meadow_said = 2;
	int northwall_said = 2;
	int otherhabitats_said = 2;
	int pond_said = 2;
	int secondary_said = 2;
	int shade_said = 2;
	int shadyedge_said = 2;
	int southwall_said = 2;
	int sunnyedge_said = 2;
	int walls_said = 2;
	int westwall_said = 2;
	int width_said = 2;
	int woodlandgarden_said = 2;
	int shrub = 2;
	int annual = 2;
	int perennial = 2;
	int tree = 2;
	int perennial_climber = 2;
	int annual_slash_perennial = 2;
	int climber = 2;
	int fern = 2;
	int bulb = 2;
	int biennial = 2;
	int annual_slash_biennial = 2;
	int biennial_slash_perennial = 2;
	int bamboo = 2;
	int corm = 2;
	int lichen = 2;
	int annual_climber = 2;


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////// PLANTLOCATION SLOTS    PLANTLOCATION SLOTS    PLANTLOCATION SLOTS    ///////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	NLGetIntSlotValue(AppGetNLResult(app), "canopy_said", &canopy_said);
	if (canopy_said == 1) {
		printf("%s\n", "You said canopy.");
		strcpy(plantLocationStringArray[envCounter], "Canopy");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "common_name_said", &common_name_said);
	if (common_name_said == 1) {
		printf("%s\n", "You said common name.");
		strcpy(plantLocationStringArray[envCounter], "Common name");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "cultivar_said", &cultivar_said);
	if (cultivar_said == 1) {
		printf("%s\n", "You said cultivar.");
		strcpy(plantLocationStringArray[envCounter], "Cultivar");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "cultivatedbeds_said", &cultivatedbeds_said);
	if (cultivatedbeds_said == 1) {
		printf("%s\n", "You said cultivated beds.");
		strcpy(plantLocationStringArray[envCounter], "CultivatedBeds");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "dappledshade_said", &dappledshade_said);
	if (dappledshade_said == 1) {
		printf("%s\n", "You said dappled shade.");
		strcpy(plantLocationStringArray[envCounter], "DappledShade");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "deepshade_said", &deepshade_said);
	if (deepshade_said == 1) {
		printf("%s\n", "You said deep shade.");
		strcpy(plantLocationStringArray[envCounter], "DeepShade");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "eastwall_said", &eastwall_said);
	if (eastwall_said == 1) {
		printf("%s\n", "You said east wall.");
		strcpy(plantLocationStringArray[envCounter], "EastWall");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "groundcover_said", &groundcover_said);
	if (groundcover_said == 1) {
		printf("%s\n", "You said ground cover.");
		strcpy(plantLocationStringArray[envCounter], "GroundCover");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "habit_said", &habit_said);
	if (habit_said == 1) {
		printf("%s\n", "You said habit.");
		strcpy(plantLocationStringArray[envCounter], "Habit");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "habitat_said", &habitat_said);
	if (habitat_said == 1) {
		printf("%s\n", "You said habitat.");
		strcpy(plantLocationStringArray[envCounter], "Habitat");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "hardyness_said", &hardyness_said);
	if (hardyness_said == 1) {
		printf("%s\n", "You said hardiness.");
		strcpy(plantLocationStringArray[envCounter], "Hardyness");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "hedge_said", &hedge_said);
	if (hedge_said == 1) {
		printf("%s\n", "You said hedge.");
		strcpy(plantLocationStringArray[envCounter], "Hedge");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "hedgerow_said", &hedgerow_said);
	if (hedgerow_said == 1) {
		printf("%s\n", "You said hedgerow.");
		strcpy(plantLocationStringArray[envCounter], "Hedgerow");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "height_said", &height_said);
	if (height_said == 1) {
		printf("%s\n", "You said height.");
		strcpy(plantLocationStringArray[envCounter], "Height");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "latin_name_said", &latin_name_said);
	if (latin_name_said == 1) {
		printf("%s\n", "You said latin name.");
		strcpy(plantLocationStringArray[envCounter], "Latin name");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "lawn_said", &lawn_said);
	if (lawn_said == 1) {
		printf("%s\n", "You said lawn.");
		strcpy(plantLocationStringArray[envCounter], "Lawn");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "meadow_said", &meadow_said);
	if (meadow_said == 1) {
		printf("%s\n", "You said meadow.");
		strcpy(plantLocationStringArray[envCounter], "Meadow");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "northwall_said", &northwall_said);
	if (northwall_said == 1) {
		printf("%s\n", "You said north wall.");
		strcpy(plantLocationStringArray[envCounter], "NorthWall");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "otherhabitats_said", &otherhabitats_said);
	if (otherhabitats_said == 1) {
		printf("%s\n", "You said other habitats.");
		strcpy(plantLocationStringArray[envCounter], "OtherHabitats");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "pond_said", &pond_said);
	if (pond_said == 1) {
		printf("%s\n", "You said pond.");
		strcpy(plantLocationStringArray[envCounter], "Pond");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "secondary_said", &secondary_said);
	if (secondary_said == 1) {
		printf("%s\n", "You said secondary.");
		strcpy(plantLocationStringArray[envCounter], "Secondary");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "shade_said", &shade_said);
	if (shade_said == 1) {
		printf("%s\n", "You said shade.");
		strcpy(plantLocationStringArray[envCounter], "Shade");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "shadyedge_said", &shadyedge_said);
	if (shadyedge_said == 1) {
		printf("%s\n", "You said shady edge.");
		strcpy(plantLocationStringArray[envCounter], "ShadyEdge");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "southwall_said", &southwall_said);
	if (southwall_said == 1) {
		printf("%s\n", "You said south wall.");
		strcpy(plantLocationStringArray[envCounter], "SouthWall");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "sunnyedge_said", &sunnyedge_said);
	if (sunnyedge_said == 1) {
		printf("%s\n", "You said sunny edge.");
		strcpy(plantLocationStringArray[envCounter], "SunnyEdge");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "walls_said", &walls_said);
	if (walls_said == 1) {
		printf("%s\n", "You said walls.");
		strcpy(plantLocationStringArray[envCounter], "Walls");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "westwall_said", &westwall_said);
	if (westwall_said == 1) {
		printf("%s\n", "You said west wall.");
		strcpy(plantLocationStringArray[envCounter], "WestWall");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "width_said", &width_said);
	if (width_said == 1) {
		printf("%s\n", "You said width.");
		strcpy(plantLocationStringArray[envCounter], "Width");
		envCounter = envCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "woodlandgarden_said", &woodlandgarden_said);
	if (woodlandgarden_said == 1) {
		printf("%s\n", "You said woodland garden.");
		strcpy(plantLocationStringArray[envCounter], "WoodlandGarden");
		envCounter = envCounter + 1;
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////// HABIT SLOTS    HABIT SLOTS    HABIT SLOTS    //////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



	NLGetIntSlotValue(AppGetNLResult(app), "shrub_said", &shrub);
	if (shrub == 1) {
		printf("%s\n", "You said Shrub.");
		strcpy(plantHabitStringArray[habitCounter], "Shrub");
		habitCounter = habitCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "annual_said", &annual);
	if (annual == 1) {
		printf("%s\n", "You said Annual.");
		strcpy(plantHabitStringArray[habitCounter], "Annual");
		habitCounter = habitCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "perennial_said", &perennial);
	if (perennial == 1) {
		printf("%s\n", "You said Perennial.");
		strcpy(plantHabitStringArray[habitCounter], "Perennial");
		habitCounter = habitCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "tree_said", &tree);
	if (tree == 1) {
		printf("%s\n", "You said Tree.");
		strcpy(plantHabitStringArray[habitCounter], "Tree");
		habitCounter = habitCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "perennial_climber_said", &perennial_climber);
	if (perennial_climber == 1) {
		printf("%s\n", "You said Perennial Climber.");
		strcpy(plantHabitStringArray[habitCounter], "Perennial Climber");
		habitCounter = habitCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "annual_slash_perennial_said", &annual_slash_perennial);
	if (annual_slash_perennial == 1) {
		printf("%s\n", "You said Annual_slash_Perennial.");
		strcpy(plantHabitStringArray[habitCounter], "Annual_slash_Perennial");
		habitCounter = habitCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "climber_said", &climber);
	if (climber == 1) {
		printf("%s\n", "You said Climber.");
		strcpy(plantHabitStringArray[habitCounter], "Climber");
		habitCounter = habitCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "fern_said", &fern);
	if (fern == 1) {
		printf("%s\n", "You said Fern.");
		strcpy(plantHabitStringArray[habitCounter], "Fern");
		habitCounter = habitCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "bulb_said", &bulb);
	if (bulb == 1) {
		printf("%s\n", "You said Bulb.");
		strcpy(plantHabitStringArray[habitCounter], "Bulb");
		habitCounter = habitCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "biennial_said", &biennial);
	if (biennial == 1) {
		printf("%s\n", "You said Biennial.");
		strcpy(plantHabitStringArray[habitCounter], "Biennial");
		habitCounter = habitCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "annual_slash_biennial_said", &annual_slash_biennial);
	if (annual_slash_biennial == 1) {
		printf("%s\n", "You said Annual_slash_Biennial.");
		strcpy(plantHabitStringArray[habitCounter], "Annual_slash_Biennial");
		habitCounter = habitCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "biennial_slash_perennial_said", &biennial_slash_perennial);
	if (biennial_slash_perennial == 1) {
		printf("%s\n", "You said Biennial_slash_Perennial.");
		strcpy(plantHabitStringArray[habitCounter], "Biennial_slash_Perennial");
		habitCounter = habitCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "bamboo_said", &bamboo);
	if (bamboo == 1) {
		printf("%s\n", "You said Bamboo.");
		strcpy(plantHabitStringArray[habitCounter], "Bamboo");
		habitCounter = habitCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "corm_said", &corm);
	if (corm == 1) {
		printf("%s\n", "You said Corm.");
		strcpy(plantHabitStringArray[habitCounter], "Corm");
		habitCounter = habitCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "lichen_said", &lichen);
	if (lichen == 1) {
		printf("%s\n", "You said Lichen.");
		strcpy(plantHabitStringArray[habitCounter], "Lichen");
		habitCounter = habitCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "annual_climber_said", &annual_climber);
	if (annual_climber == 1) {
		printf("%s\n", "You said Annual Climber.");
		strcpy(plantHabitStringArray[habitCounter], "Annual Climber");
		habitCounter = habitCounter + 1;
	}





	if ((AppGetRecognitionStage(app) == 4)){//&& (recognitionFlag == 1)) {
		AppGoto(app, "envCheck");
	}

/*
	if (!strcmp(buf, "canopy_said")) {
		AppAppendTTSPrompt(app, "You said canopy.");
		printf("You said canopy.\n");
		plantLocationStringArray[envCounter] = "Canopy";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "common_name_said")) {
		AppAppendTTSPrompt(app, "You said common name.");
		printf("You said common_name_said.\n");
		plantLocationStringArray[envCounter] = "Common name";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "cultivar_said")) {
		AppAppendTTSPrompt(app, "You said cultivar.");
		printf("You said cultivar_said.\n");
		plantLocationStringArray[envCounter] = "Cultivar";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "cultivatedbeds_said")) {
		AppAppendTTSPrompt(app, "You said cultivated beds.");
		printf("You said cultivatedbeds_said.\n");
		plantLocationStringArray[envCounter] = "CultivatedBeds";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "dappledshade_said")) {
		AppAppendTTSPrompt(app, "You said dappled shade.");
		printf("You said dappledshade_said.\n");
		plantLocationStringArray[envCounter] = "DappledShade";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "deepshade_said")) {
		AppAppendTTSPrompt(app, "You said deep shade.");
		printf("You said deepshade_said.\n");
		plantLocationStringArray[envCounter] = "DeepShade";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "eastwall_said")) {
		AppAppendTTSPrompt(app, "You said east wall.");
		printf("You said eastwall_said.\n");
		plantLocationStringArray[envCounter] = "EastWall";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "groundcover_said")) {
		AppAppendTTSPrompt(app, "You said ground cover.");
		printf("You said groundcover_said.\n");
		plantLocationStringArray[envCounter] = "GroundCover";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "habit_said")) {
		AppAppendTTSPrompt(app, "You said habit.");
		printf("You said habit_said.\n");
		plantLocationStringArray[envCounter] = "Habit";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "habitat_said")) {
		AppAppendTTSPrompt(app, "You said habitat.");
		printf("You said habitat_said.\n");
		plantLocationStringArray[envCounter] = "Habitat";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "hardyness_said")) {
		AppAppendTTSPrompt(app, "You said hardiness.");
		printf("You said hardyness_said.\n");
		plantLocationStringArray[envCounter] = "Hardyness";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "hedge_said")) {
		AppAppendTTSPrompt(app, "You said hedge.");
		printf("You said hedge_said.\n");
		plantLocationStringArray[envCounter] = "Hedge";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "hedgerow_said")) {
		AppAppendTTSPrompt(app, "You said hedgerow.");
		printf("You said hedgerow_said.\n");
		plantLocationStringArray[envCounter] = "Hedgerow";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "height_said")) {
		AppAppendTTSPrompt(app, "You said height.");
		printf("You said height_said.\n");
		plantLocationStringArray[envCounter] = "Height";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "latin_name_said")) {
		AppAppendTTSPrompt(app, "You said latin name.");
		printf("You said latin_name_said.\n");
		plantLocationStringArray[envCounter] = "Latin name";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "lawn_said")) {
		AppAppendTTSPrompt(app, "You said lawn.");
		printf("You said lawn_said.\n");
		plantLocationStringArray[envCounter] = "Lawn";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "meadow_said")) {
		AppAppendTTSPrompt(app, "You said meadow.");
		printf("You said meadow_said.\n");
		plantLocationStringArray[envCounter] = "Meadow";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "northwall_said")) {
		AppAppendTTSPrompt(app, "You said north wall.");
		printf("You said northwall_said.\n");
		plantLocationStringArray[envCounter] = "NorthWall";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "otherhabitats_said")) {
		AppAppendTTSPrompt(app, "You said other habitats.");
		printf("You said otherhabitats_said.\n");
		plantLocationStringArray[envCounter] = "OtherHabitats";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "pond_said")) {
		AppAppendTTSPrompt(app, "You said pond.");
		printf("You said pond_said.\n");
		plantLocationStringArray[envCounter] = "Pond";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "secondary_said")) {
		AppAppendTTSPrompt(app, "You said secondary.");
		printf("You said secondary_said.\n");
		plantLocationStringArray[envCounter] = "Secondary";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "shade_said")) {
		AppAppendTTSPrompt(app, "You said shade.");
		printf("You said shade_said.\n");
		plantLocationStringArray[envCounter] = "Shade";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "shadyedge_said")) {
		AppAppendTTSPrompt(app, "You said shady edge.");
		printf("You said shadyedge_said.\n");
		plantLocationStringArray[envCounter] = "ShadyEdge";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "southwall_said")) {
		AppAppendTTSPrompt(app, "You said south wall.");
		printf("You said southwall_said.\n");
		plantLocationStringArray[envCounter] = "SouthWall";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "sunnyedge_said")) {
		AppAppendTTSPrompt(app, "You said sunny edge.");
		printf("You said sunnyedge_said.\n");
		plantLocationStringArray[envCounter] = "SunnyEdge";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "walls_said")) {
		AppAppendTTSPrompt(app, "You said walls.");
		printf("You said walls_said.\n");
		plantLocationStringArray[envCounter] = "Walls";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "westwall_said")) {
		AppAppendTTSPrompt(app, "You said west wall.");
		printf("You said westwall_said.\n");
		plantLocationStringArray[envCounter] = "WestWall";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "width_said")) {
		AppAppendTTSPrompt(app, "You said width.");
		printf("You said width_said.\n");
		plantLocationStringArray[envCounter] = "Width";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "woodlandgarden_said")) {
		AppAppendTTSPrompt(app, "You said woodland garden.");
		printf("You said woodlandgarden_said.\n");
		plantLocationStringArray[envCounter] = "WoodlandGarden";
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else {
		AppAppendTTSPrompt(app, "Try again.");
	}*/
	
	AppGotoSelf(app);
}



int main(int argc, char *argv[])
{
	printf("test");
	//NuanceStatus statusP;
	//NuanceConfigBuildFromCommandLine(&argc, argv, 1, *statusP);

	App *app;
	
	app = AppNew(&argc, argv);
	
	
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
	AppCreateState(app, "env2PandH", "root", envPandHfn);
	
	AppCreateState(app, "test", "root", testfn);
	AppCreateState(app, "zeroMatchesEnv", "root", envZeroMatches);
	AppCreateState(app, "envResultsBuf", "root", envResultsBufFn);
	AppCreateState(app, "envResults", "root", envResultsFn);

	AppCreateState(app, "freeSpeak", "root", freeSpeakfn);
	AppCreateState(app, "envErrorFix", "root", envErrorFixfn);
	AppCreateState(app, "envCheck", "root", envCheckfn);

	//AppGo(app, "environment");
	AppGo(app, "freeSpeak");
	//AppGo(app, "test");
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

