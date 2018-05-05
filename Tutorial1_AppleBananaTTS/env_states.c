#include "env_states.h"

int looped = 0;
int envCounter = 0;
int habitCounter = 0;
int firstEnv = 0;
char storeBuf[400];
char storeBuf2[400];
int firstEnvFn2Flag = 0;
int numberCounter = 0;
char storeBufCount[500];
int errorEnvStringCounter = 0;
int global_width = 0;

void resetAllVars(void) {
	looped = 0;
	envCounter = 0;
	habitCounter = 0;
	firstEnv = 0;
	storeBuf[400] = "";
	storeBuf2[400] = "";
	firstEnvFn2Flag = 0;
	numberCounter = 0;
	storeBufCount[500] = "";
	errorEnvStringCounter = 0;
	hardyness = 0;
	global_width = 0;

	for (int n = 0; n < 8; n++) {
		strcpy(plantLocationStringArray[n], "");
		strcpy(plantHabitStringArray[n], "");
		strcpy(errorFixArray[n], "");
		strcpy(errorStoreArray[n], "");
		strcpy(errorEnvStringArray[n], "");
	}
}
void envPreCheckfn(App *app) {
	AppSetGrammar(app, ".Results_or_modify");

	char buf[100];

	AppAppendTTSPrompt(app, "Would you like to see your results, or add or remove a term?");
	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}

	NLGetStringSlotValue(AppGetNLResult(app), "pre_reults_said", buf, 100);
	if (!strcmp("see_results_said", buf)) {
		AppAppendTTSPrompt(app, "You said you would like to see your results.");
		constructAdvancedString("count");
		constructAdvancedString("normal");
		//if (returnSQLCount(app, storeBufCount) <= 7) {
		AppGoto(app, "envResults");
		//}
	}
	else if (!strcmp("add_term_said", buf)) {
		AppAppendTTSPrompt(app, "You said you would like to add a term.");
		AppGoto(app, "freeSpeak");
	}
	else if (!strcmp("remove_term_said", buf)) {
		AppAppendTTSPrompt(app, "You said you would like to remove a term.");
		AppGoto(app, "envCheck");
	}
	else {
		AppAppendTTSPrompt(app, "Try again.");
	}
	AppGotoSelf(app);

}
void envPreFixCheckfn(App *app) {
	AppSetGrammar(app, ".Results_or_modify");

	char buf[100];

	AppAppendTTSPrompt(app, "Would you like to add or remove a term?");
	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}

	NLGetStringSlotValue(AppGetNLResult(app), "pre_reults_said", buf, 100);
	if (!strcmp("add_term_said", buf)) {
		AppAppendTTSPrompt(app, "You said you would like to add a term.");
		AppGoto(app, "freeSpeak");
	}
	else if (!strcmp("remove_term_said", buf)) {
		AppAppendTTSPrompt(app, "You said you would like to remove a term.");
		AppGoto(app, "envCheck");
	}
	else {
		AppAppendTTSPrompt(app, "Try again.");
	}
	AppGotoSelf(app);

}
void envCheckfn1(App *app) {
	AppSetGrammar(app, ".Start");
	char buf[200];
	errorEnvStringCounter = 0;


	char buf2[400];
	constructAdvancedString("count");
	strcpy(buf2, storeBufCount);
	//sprintf(buf2, "SELECT COUNT(*) FROM `plantlocations` WHERE `%s`=1", plantLocationStringArray[0]);

	//for (int i = 1; i < envCounter; i++) {
	//	char buf4[100];
	//	sprintf(buf4, " AND `%s`=1", plantLocationStringArray[i]);
	//	strcpy(buf2, concat(buf2, buf4));
	//}

	//if (habitCounter > 0) {
	//	for (int n = 0; n < habitCounter; n++) {
	//		char buf8[100];
	//		sprintf(buf8, " AND `Habit`='%s'", plantHabitStringArray[n]);
	//		strcpy(buf2, concat(buf2, buf8));
	//	}
	//}

	//char errorArraySpeakStr[400];
	//strcpy(errorArraySpeakStr, "So far you have selected: ");
	AppAppendTTSPrompt(app, "So far you have selected: ");

	printf("Number of plant locations so far: %d\n", envCounter);

	for (int i = 0; i < envCounter; i++) {
		printf("Plant location %d is %s\n", i, plantLocationStringArray[i]);
		AppAppendTTSPrompt(app, plantLocationStringArray[i]);
		AppAppendSilence(app, 400);
		//strcpy(errorArraySpeakStr, concat(errorArraySpeakStr, plantLocationStringArray[i]));
		//strcpy(errorArraySpeakStr, concat(errorArraySpeakStr, " ")); 

	}

	printf("Number of habits so far: %d\n", habitCounter);
	for (int i = 0; i < habitCounter; i++) {
		printf("Plant habit %d is %s\n", (i + envCounter), plantHabitStringArray[i]);
		AppAppendTTSPrompt(app, plantHabitStringArray[i]);
		AppAppendSilence(app, 400);

	}
	if (hardyness > 0) {
		AppAppendTTSPrompt(app, " and a hardyness of ");
		switch (hardyness) {
		case 3:
			AppAppendTTSPrompt(app, " three.");
			break;
		case 5:
			AppAppendTTSPrompt(app, " five.");
			break;
		case 7:
			AppAppendTTSPrompt(app, " seven.");
			break;
		case 10:
			AppAppendTTSPrompt(app, " nine.");
			break;
		}
	}
	AppAppendSilence(app, 100);
	AppAppendTTSPrompt(app, "Is this correct?");
	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}

	NLGetStringSlotValue(AppGetNLResult(app), "binary_response_said", buf, 100);
	if (!strcmp("yes_said", buf)) {
		//AppAppendTTSPrompt(app, "You said yes.");//maybe uncomment?
		//AppGoto(app, "envPreCheck");
		AppGoto(app, "env2");
		//AppGoto(app, "envPandH");
	}
	else if (!strcmp("no_said", buf)) {
		AppAppendTTSPrompt(app, "You said no.");
		//AppGoto(app, "envCheck");
		AppGoto(app, "envPreFixCheck");
	}
	else {
		AppAppendTTSPrompt(app, "Try again.");
	}
	AppGotoSelf(app);
}
void speakCurrentTerms(App *app) {

	for (int i = 0; i < envCounter; i++) {
		printf("Plant location %d is %s\n", i, plantLocationStringArray[i]);
		AppAppendTTSPrompt(app, plantLocationStringArray[i]);
		AppAppendSilence(app, 400);
		//strcpy(errorArraySpeakStr, concat(errorArraySpeakStr, plantLocationStringArray[i]));
		//strcpy(errorArraySpeakStr, concat(errorArraySpeakStr, " ")); 

	}

	printf("Number of habits so far: %d\n", habitCounter);
	for (int i = 0; i < habitCounter; i++) {
		printf("Plant habit %d is %s\n", (i + envCounter), plantHabitStringArray[i]);
		AppAppendTTSPrompt(app, plantHabitStringArray[i]);
		AppAppendSilence(app, 400);

	}
	if (hardyness > 0) {
		AppAppendTTSPrompt(app, " and a hardyness of ");
		switch (hardyness) {
		case 3:
			AppAppendTTSPrompt(app, " three.");
			break;
		case 5:
			AppAppendTTSPrompt(app, " five.");
			break;
		case 7:
			AppAppendTTSPrompt(app, " seven.");
			break;
		case 10:
			AppAppendTTSPrompt(app, " nine.");
			break;
		}
	}
	AppAppendSilence(app, 100);
	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}
	return;
}
void envCheckfn(App *app) {
	char buf2[400];
	constructAdvancedString("count");
	strcpy(buf2, storeBufCount);
	int sqlCount = returnSQLCount(app, buf2);
	char buf3[100];
	printf("\nQuery: %s\n\n", buf2);
	sprintf(buf3, "Currently %d plants match your search criteria.", returnSQLCount(app, buf2));
	printf("%s\n", buf3);

	AppSetGrammar(app, ".ErrorFixNumbers");
	//AppAppendTTSPrompt(app, errorArraySpeakStr);

	//speakCurrentTerms(app);
	AppAppendTTSPrompt(app, "Which terms would you like to remove?");


	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}

	int one = 2;
	int two = 2;
	int three = 2;
	int four = 2;
	int five = 2;
	int six = 2;
	int seven = 2;
	int eight = 2;
	int nine = 2;
	int ten = 2;
	int eleven = 2;
	int twelve = 2;
	int thirteen = 2;
	int fourteen = 2;
	int fifteen = 2;
	int sixteen = 2;
	int seventeen = 2;
	int eighteen = 2;
	int nineteen = 2;
	int twenty = 2;


	NLGetIntSlotValue(AppGetNLResult(app), "one_said", &one);
	if (one == 1) {
		printf("%s\n", "You said one.");
		numberStringArray[numberCounter] = 1;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "two_said", &two);
	if (two == 1) {
		printf("%s\n", "You said two.");
		numberStringArray[numberCounter] = 2;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "three_said", &three);
	if (three == 1) {
		printf("%s\n", "You said three.");
		numberStringArray[numberCounter] = 3;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "four_said", &four);
	if (four == 1) {
		printf("%s\n", "You said four.");
		numberStringArray[numberCounter] = 4;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "five_said", &five);
	if (five == 1) {
		printf("%s\n", "You said five.");
		numberStringArray[numberCounter] = 5;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "six_said", &six);
	if (six == 1) {
		printf("%s\n", "You said six.");
		numberStringArray[numberCounter] = 6;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "seven_said", &seven);
	if (seven == 1) {
		printf("%s\n", "You said seven.");
		numberStringArray[numberCounter] = 7;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "eight_said", &eight);
	if (eight == 1) {
		printf("%s\n", "You said eight.");
		numberStringArray[numberCounter] = 8;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "nine_said", &nine);
	if (nine == 1) {
		printf("%s\n", "You said nine.");
		numberStringArray[numberCounter] = 9;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "ten_said", &ten);
	if (ten == 1) {
		printf("%s\n", "You said ten.");
		numberStringArray[numberCounter] = 10;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "eleven_said", &eleven);
	if (eleven == 1) {
		printf("%s\n", "You said eleven.");
		numberStringArray[numberCounter] = 11;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "twelve_said", &twelve);
	if (twelve == 1) {
		printf("%s\n", "You said twelve.");
		numberStringArray[numberCounter] = 12;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "thirteen_said", &thirteen);
	if (thirteen == 1) {
		printf("%s\n", "You said thirteen.");
		numberStringArray[numberCounter] = 13;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "fourteen_said", &fourteen);
	if (fourteen == 1) {
		printf("%s\n", "You said fourteen.");
		numberStringArray[numberCounter] = 14;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "fifteen_said", &fifteen);
	if (fifteen == 1) {
		printf("%s\n", "You said fifteen.");
		numberStringArray[numberCounter] = 15;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "sixteen_said", &sixteen);
	if (sixteen == 1) {
		printf("%s\n", "You said sixteen.");
		numberStringArray[numberCounter] = 16;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "seventeen_said", &seventeen);
	if (seventeen == 1) {
		printf("%s\n", "You said seventeen.");
		numberStringArray[numberCounter] = 17;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "eighteen_said", &eighteen);
	if (eighteen == 1) {
		printf("%s\n", "You said eighteen.");
		numberStringArray[numberCounter] = 18;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "nineteen_said", &nineteen);
	if (nineteen == 1) {
		printf("%s\n", "You said nineteen.");
		numberStringArray[numberCounter] = 19;
		numberCounter = numberCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "twenty_said", &twenty);
	if (twenty == 1) {
		printf("%s\n", "You said twenty.");
		numberStringArray[numberCounter] = 20;
		numberCounter = numberCounter + 1;
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


	NLGetIntSlotValue(AppGetNLResult(app), "canopy_said", &canopy_said);
	if (canopy_said == 1) {
		printf("%s\n", "You said canopy.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Canopy");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "common_name_said", &common_name_said);
	if (common_name_said == 1) {
		printf("%s\n", "You said common name.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Common name");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "cultivar_said", &cultivar_said);
	if (cultivar_said == 1) {
		printf("%s\n", "You said cultivar.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Cultivar");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "cultivatedbeds_said", &cultivatedbeds_said);
	if (cultivatedbeds_said == 1) {
		printf("%s\n", "You said cultivated beds.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "CultivatedBeds");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "dappledshade_said", &dappledshade_said);
	if (dappledshade_said == 1) {
		printf("%s\n", "You said dappled shade.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "DappledShade");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "deepshade_said", &deepshade_said);
	if (deepshade_said == 1) {
		printf("%s\n", "You said deep shade.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "DeepShade");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "eastwall_said", &eastwall_said);
	if (eastwall_said == 1) {
		printf("%s\n", "You said east wall.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "EastWall");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "groundcover_said", &groundcover_said);
	if (groundcover_said == 1) {
		printf("%s\n", "You said ground cover.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "GroundCover");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "habit_said", &habit_said);
	if (habit_said == 1) {
		printf("%s\n", "You said habit.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Habit");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "habitat_said", &habitat_said);
	if (habitat_said == 1) {
		printf("%s\n", "You said habitat.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Habitat");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "hardyness_said", &hardyness_said);
	if (hardyness_said == 1) {
		printf("%s\n", "You said hardiness.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Hardyness");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "hedge_said", &hedge_said);
	if (hedge_said == 1) {
		printf("%s\n", "You said hedge.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Hedge");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "hedgerow_said", &hedgerow_said);
	if (hedgerow_said == 1) {
		printf("%s\n", "You said hedgerow.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Hedgerow");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "height_said", &height_said);
	if (height_said == 1) {
		printf("%s\n", "You said height.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Height");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "latin_name_said", &latin_name_said);
	if (latin_name_said == 1) {
		printf("%s\n", "You said latin name.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Latin name");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "lawn_said", &lawn_said);
	if (lawn_said == 1) {
		printf("%s\n", "You said lawn.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Lawn");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "meadow_said", &meadow_said);
	if (meadow_said == 1) {
		printf("%s\n", "You said meadow.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Meadow");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "northwall_said", &northwall_said);
	if (northwall_said == 1) {
		printf("%s\n", "You said north wall.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "NorthWall");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "otherhabitats_said", &otherhabitats_said);
	if (otherhabitats_said == 1) {
		printf("%s\n", "You said other habitats.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "OtherHabitats");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "pond_said", &pond_said);
	if (pond_said == 1) {
		printf("%s\n", "You said pond.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Pond");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "secondary_said", &secondary_said);
	if (secondary_said == 1) {
		printf("%s\n", "You said secondary.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Secondary");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "shade_said", &shade_said);
	if (shade_said == 1) {
		printf("%s\n", "You said shade.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Shade");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "shadyedge_said", &shadyedge_said);
	if (shadyedge_said == 1) {
		printf("%s\n", "You said shady edge.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "ShadyEdge");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "southwall_said", &southwall_said);
	if (southwall_said == 1) {
		printf("%s\n", "You said south wall.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "SouthWall");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "sunnyedge_said", &sunnyedge_said);
	if (sunnyedge_said == 1) {
		printf("%s\n", "You said sunny edge.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "SunnyEdge");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "walls_said", &walls_said);
	if (walls_said == 1) {
		printf("%s\n", "You said walls.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Walls");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "westwall_said", &westwall_said);
	if (westwall_said == 1) {
		printf("%s\n", "You said west wall.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "WestWall");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "width_said", &width_said);
	if (width_said == 1) {
		printf("%s\n", "You said width.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "Width");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "woodlandgarden_said", &woodlandgarden_said);
	if (woodlandgarden_said == 1) {
		printf("%s\n", "You said woodland garden.");
		strcpy(errorEnvStringArray[errorEnvStringCounter], "WoodlandGarden");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}

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


	NLGetIntSlotValue(AppGetNLResult(app), "shrub_said", &shrub);
	if (shrub == 1) {
		printf("%s\n", "You said Shrub.");
		strcpy(errorStoreArray[errorEnvStringCounter], "Shrub");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "annual_said", &annual);
	if (annual == 1) {
		printf("%s\n", "You said Annual.");
		strcpy(errorStoreArray[errorEnvStringCounter], "Annual");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "perennial_said", &perennial);
	if (perennial == 1) {
		printf("%s\n", "You said Perennial.");
		strcpy(errorStoreArray[errorEnvStringCounter], "Perennial");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "tree_said", &tree);
	if (tree == 1) {
		printf("%s\n", "You said Tree.");
		strcpy(errorStoreArray[errorEnvStringCounter], "Tree");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "perennial_climber_said", &perennial_climber);
	if (perennial_climber == 1) {
		printf("%s\n", "You said Perennial Climber.");
		strcpy(errorStoreArray[errorEnvStringCounter], "Perennial Climber");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "annual_slash_perennial_said", &annual_slash_perennial);
	if (annual_slash_perennial == 1) {
		printf("%s\n", "You said Annual_slash_Perennial.");
		strcpy(errorStoreArray[errorEnvStringCounter], "Annual_slash_Perennial");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "climber_said", &climber);
	if (climber == 1) {
		printf("%s\n", "You said Climber.");
		strcpy(errorStoreArray[errorEnvStringCounter], "Climber");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "fern_said", &fern);
	if (fern == 1) {
		printf("%s\n", "You said Fern.");
		strcpy(errorStoreArray[errorEnvStringCounter], "Fern");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "bulb_said", &bulb);
	if (bulb == 1) {
		printf("%s\n", "You said Bulb.");
		strcpy(errorStoreArray[errorEnvStringCounter], "Bulb");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "biennial_said", &biennial);
	if (biennial == 1) {
		printf("%s\n", "You said Biennial.");
		strcpy(errorStoreArray[errorEnvStringCounter], "Biennial");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "annual_slash_biennial_said", &annual_slash_biennial);
	if (annual_slash_biennial == 1) {
		printf("%s\n", "You said Annual_slash_Biennial.");
		strcpy(errorStoreArray[errorEnvStringCounter], "Annual_slash_Biennial");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "biennial_slash_perennial_said", &biennial_slash_perennial);
	if (biennial_slash_perennial == 1) {
		printf("%s\n", "You said Biennial_slash_Perennial.");
		strcpy(errorStoreArray[errorEnvStringCounter], "Biennial_slash_Perennial");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "bamboo_said", &bamboo);
	if (bamboo == 1) {
		printf("%s\n", "You said Bamboo.");
		strcpy(errorStoreArray[errorEnvStringCounter], "Bamboo");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "corm_said", &corm);
	if (corm == 1) {
		printf("%s\n", "You said Corm.");
		strcpy(errorStoreArray[errorEnvStringCounter], "Corm");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "lichen_said", &lichen);
	if (lichen == 1) {
		printf("%s\n", "You said Lichen.");
		strcpy(errorStoreArray[errorEnvStringCounter], "Lichen");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}
	NLGetIntSlotValue(AppGetNLResult(app), "annual_climber_said", &annual_climber);
	if (annual_climber == 1) {
		printf("%s\n", "You said Annual Climber.");
		strcpy(errorStoreArray[errorEnvStringCounter], "Annual Climber");
		errorEnvStringCounter = errorEnvStringCounter + 1;
	}




	if ((AppGetRecognitionStage(app) == 4)) {//&& (recognitionFlag == 1)) {
		AppGoto(app, "envErrorFix");
	}


	AppGotoSelf(app);

}


void printAllArrs(char* str) {
	printf("\n\n#####################\n");
	printf("%s\n", str);
	printf("Printing all arrays and counters...\n");

	printf("envCounter = %d:\n", envCounter);
	//printf("Environments said:\n");
	for (int p = 0; p < envCounter; p++) {
		printf("%d - %s\n", p, plantLocationStringArray[p]);
	}
	printf("\n");

	printf("habitCounter = %d:\n", habitCounter);
	//printf("Habits said:\n");
	for (int p = 0; p < habitCounter; p++) {
		printf("%d - %s\n", p, plantHabitStringArray[p]);
	}
	printf("\n");
	printf("All things said in a nice list:\n");
	for (int p = 0; p < (habitCounter + envCounter); p++) {
		printf("%d - %s \n", p, errorFixArray[p]);
	}
	printf("\n");
	printf("Terms to remove:\n");
	for (int p = 0; p <numberCounter; p++) {
		printf("%d - %s \n", p, errorStoreArray[p]);
	}
	printf("\n");
}

void envErrorFixfn(App *app) {

	printf("Number of plant locations so far: %d\n", envCounter);



	for (int i = 0; i < envCounter; i++) {
		printf("Plant location %d is %s\n", i, plantLocationStringArray[i]);
		//printf("errchk1\n");
		strcpy(errorFixArray[i], plantLocationStringArray[i]);
		//errorStoreArray[i] = plantLocationStringArray[i];
		//printf("errchk2\n");

	}

	printf("Number of habits so far: %d\n", habitCounter);
	for (int i = 0; i < habitCounter; i++) {
		printf("Plant habit %d is %s\n", (i + envCounter - 1), plantHabitStringArray[i]);
		strcpy(errorFixArray[i + envCounter], plantHabitStringArray[i]);
		//errorStoreArray[i + envCounter] = plantHabitStringArray[i];
	}

	//if (errorEnvStringCounter > 0) {
	//	for (int n = 0; n < errorEnvStringCounter; n++) {
	//		for (int m = 0; m < (habitCounter + envCounter); m++) {
	//			if (!strcmp(errorEnvStringArray[n], errorFixArray[m]) {
	//				numberCounter += 1;
	//				strcpy(errorEnvStringArray[n], n)
	//			}
	//		}
	//	}
	//}

	//numberStringArray[numberCounter] = 3;
	//numberCounter = numberCounter + 1;
	//printAllArrs("Error array constructed but still full...");

	for (int i = 0; i <= (numberCounter - 1); i++) {
		int elementToRemove = numberStringArray[i] - 1;
		if (elementToRemove >= 0) {
			//errorFixArray[i] = &errorStoreArray[elementToRemove];
			strcpy(errorStoreArray[i], errorFixArray[elementToRemove]);
			printf("\ni = %d, elementToRemove = numberStringArray[i] = %d, errorFixArray[i] = %s, errorStoreArray[elementToRemove] = %s\n", i, elementToRemove, errorFixArray[i], errorStoreArray[elementToRemove]);
		}
	}

	int numberCounterTmp = numberCounter;
	for (int n = 0; n < (numberCounter + errorEnvStringCounter); n++) {
		for (int i = 0; i < errorEnvStringCounter; i++) {
			if (!strcmp(errorEnvStringArray[i], errorFixArray[n])) {
				strcpy(errorStoreArray[numberCounterTmp], errorEnvStringArray[i]);
				numberCounterTmp += 1;
			}
		}
	}
	AppAppendTTSPrompt(app, "Okay, removing");
	for (int i = 0; i < 8; i++) {
		AppAppendTTSPrompt(app, errorStoreArray[i]);
	}

	printAllArrs("Error array now containing terms to remove...");
	int termsRemoved = 0;
	char emptyChar[6] = "hello";
	int envCounter2 = envCounter;
	//printf("%s\n", "About to sort through said items and remove errors....");
	for (int n = 0; n < (envCounter + habitCounter); n++) {
		//	printf("n=%d\n", n);
		for (int m = 0; m < (envCounter); m++) {
			//	printf("m=%d\n", m);
			if (!strcmp(errorStoreArray[n], plantLocationStringArray[m])) {

				//if ((envCounter - numberCounter) > 0) {
				if (envCounter > 0) {
					printf("(location) Error found in %s, removing...\n", plantLocationStringArray[m]);
					//strcpy(plantLocationStringArray[m], "");
					for (int l = m; l < envCounter; l++) {
						//printAllArrs("looping with l; ");
						//printf("l=%d\n", l);
						//strcpy(plantLocationStringArray[m], plantLocationStringArray[m + 1]);
						strcpy(plantLocationStringArray[l], plantLocationStringArray[l + 1]);
						//plantLocationStringArray[l] = plantLocationStringArray[l + 1];
						//if (envCounter == 1) break;
					}

					//plantLocationStringArray[envCounter - 1] = "";
					printf("envCounter = %d, subtracting one...\n", envCounter);
					envCounter = envCounter - 1;
					printf("One subtracted. envCounter = %d\n", envCounter);
					//printAllArrs("After loop1 removal");
					//strcpy(errorStoreArray[n], emptyChar);
					//errorFixArray[n] = emptyChar;
				}
				else {
					AppAppendTTSPrompt(app, "Sorry, but you must have at least one catagory in Plant location.");
					printf("Can't remove, you must have at least one catagory in plantLocation\n");
				}
			}
		}
		for (int m = 0; m < (habitCounter); m++) {
			//printf("m2=%d\n", m);
			//	printAllArrs("Second loop");
			if (!strcmp(errorStoreArray[n], plantHabitStringArray[m])) {
				if ((habitCounter >= 2) || (plantHabitStringArray[0] != "")) {

					printf("(Habit) Error found in %s, removing...\n", plantHabitStringArray[m]);
					//strcpy(plantHabitStringArray[m], "");
					for (int l = m; l < habitCounter; l++) {
						//printf("l2=%d\n", l);
						//strcpy(plantHabitStringArray[m], plantHabitStringArray[m + 1]);
						//plantHabitStringArray[m] = plantHabitStringArray[m + 1];
						strcpy(plantHabitStringArray[m], plantHabitStringArray[m + 1]);
						//printAllArrs("Second loop inner");
					}
					//plantHabitStringArray[habitCounter - 1] = "";
					//printAllArrs("After loop2 removal");

					//errorFixArray[n] = "";
					strcpy(errorStoreArray[n], "");
					strcpy(plantHabitStringArray[habitCounter], "");
					habitCounter = habitCounter - 1;
					//printAllArrs("Second loop removed");
				}
				else { printf("Can't remove, you must have at least one catagory in Habit\n"); }
			}
		}

	}

	for (int n = 0; n < 8; n++) {
		strcpy(errorFixArray[n], "");
		strcpy(errorStoreArray[n], "");
		numberStringArray[n] = 0;
	}
	numberCounter = 0;


	printAllArrs("Finished");
	printf("All errors removed\n");

	/*for (int n = 0; n < numberCounter; n++) {
	strcpy(errorFixArray[numberStringArray[n]], "");
	termsRemoved += 1;
	}

	numberCounter = numberCounter - termsRemoved;

	SQLspeakQuery(app, errorFixArray);

	if (!AppRecognize(app)) {
	printf("!AppRec\n");
	return;
	}*/
	AppGoto(app, "env2");
}
void envPandHfn(App *app) {




	AppSetGrammar(app, ".Start");
	char buf[200];


	printf("Number of plant locations so far: %d\n", envCounter);

	for (int i = 0; i < envCounter; i++) {
		printf("Element %d of plant locations is %s\n", i, plantLocationStringArray[i]);
	}

	printf("Number of habits so far: %d\n", habitCounter);
	for (int i = 0; i < habitCounter; i++) {
		printf("Element %d of habit is %s\n", i, plantHabitStringArray[i]);
	}

	char buf2[400];
	constructAdvancedString("count");
	strcpy(buf2, storeBufCount);
	//sprintf(buf2, "SELECT COUNT(*) FROM `plantlocations` WHERE `%s`=1", plantLocationStringArray[0]);



	char buf3[100];
	printf("\nQuery: %s\n\n", buf2);
	sprintf(buf3, "Currently %d plants match your search criteria.", returnSQLCount(app, buf2));
	printf("%s\n", buf3);


	AppAppendTTSPrompt(app, buf3);
	//AppAppendTTSPrompt(app, buf3);
	if (returnSQLCount(app, buf2) == 0) {
		AppGoto(app, "zeroMatchesEnv");
	}
	else {
		AppAppendTTSPrompt(app, "Would you like to add another term?");
	}

	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}

	NLGetStringSlotValue(AppGetNLResult(app), "binary_response_said", buf, 200);


	if (!strcmp(buf, "yes_said")) {
		AppAppendTTSPrompt(app, "You said yes.");
		printf("You said yes.\n");
		looped = 0;
		//AppGoto(app, "environment");

		AppGoto(app, "freeSpeak");
	}
	else if (!strcmp(buf, "no_said")) {
		AppAppendTTSPrompt(app, "You said no.");
		printf("You said no.\n");
		constructAdvancedString("count");
		AppSetGrammar(app, ".Start");
		//strcpy(buf2, storeBufCount);
		int countCheck = (returnSQLCount(app, storeBufCount));
		while (countCheck > 8) {
			char* buf11;
			sprintf(buf11, "Are you sure you want me to read %d results?", returnSQLCount(app, storeBufCount));
			AppAppendTTSPrompt(app, buf11);
			if (!AppRecognize(app)) {
				printf("!AppRec\n");
				return;
			}
			char buf12[100];
			NLGetStringSlotValue(AppGetNLResult(app), "binary_response_said", buf12, 100);
			if (!strcmp(buf12, "yes_said")) {
				AppAppendTTSPrompt(app, "Okay, if you're sure.");
				AppGoto(app, "envResults");
			}
			else if (!strcmp(buf12, "no_said")) {
				AppAppendTTSPrompt(app, "You said no.");
				AppGoto(app, "envPreCheck");
			}
			else {
				AppAppendTTSPrompt(app, "Try again.");
			}

		}

		//sprintf(storeBuf2, "SELECT `Common name`,`Latin name` FROM `plantlocations` WHERE `%s`=1", plantLocationStringArray[0]);
		//for (int i = 1; i < envCounter; i++) {
		//	char buf6[100];
		//	sprintf(buf6, " AND `%s`=1", plantLocationStringArray[i]);
		//	strcpy(storeBuf2, concat(storeBuf2, buf6));
		//}
		//for (int i = 1; i < habitCounter; i++) {
		//	char buf7[100];
		//	sprintf(buf7, " AND `Habit`='%s'", plantHabitStringArray[i]);
		//	strcpy(storeBuf2, concat(storeBuf2, buf7));
		//}
		AppGoto(app, "envResults");
	}
	AppGotoSelf(app);
}
void environmentfn(App *app) {
	int errorCounter = 0;

	AppSetGrammar(app, ".Environment");

	char buf[200];



	if (envCounter >= 7) {
		AppAppendTTSPrompt(app, "You have already selected eight catagories for searching and so cannot select anymore.");
		AppGoto(app, "envResults");
	}

	if (looped == 0) {
		printf("\n\n\n Here are some search catagories to help you find the plant you want: \n\n");
		SQLcolumnReturn(app, "plantlocations");
		AppAppendTTSPrompt(app, "By which category would you like to search for a plant?");
		//AppAppendTTSPrompt(app, "category");
		//looped = 1;
	}
	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}
	NLGetStringSlotValue(AppGetNLResult(app), "env_catagory_said", buf, 100);


	//const char *plantLocationStringArray[8];


	if (!strcmp(buf, "canopy_said")) {
		AppAppendTTSPrompt(app, "You said canopy.");
		printf("You said canopy.\n");
		strcpy(plantLocationStringArray[envCounter], "Canopy");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "common_name_said")) {
		AppAppendTTSPrompt(app, "You said common name.");
		printf("You said common_name_said.\n");
		strcpy(plantLocationStringArray[envCounter], "Common name");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "cultivar_said")) {
		AppAppendTTSPrompt(app, "You said cultivar.");
		printf("You said cultivar_said.\n");
		strcpy(plantLocationStringArray[envCounter], "Cultivar");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "cultivatedbeds_said")) {
		AppAppendTTSPrompt(app, "You said cultivated beds.");
		printf("You said cultivatedbeds_said.\n");
		strcpy(plantLocationStringArray[envCounter], "CultivatedBeds");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "dappledshade_said")) {
		AppAppendTTSPrompt(app, "You said dappled shade.");
		printf("You said dappledshade_said.\n");
		strcpy(plantLocationStringArray[envCounter], "DappledShade");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "deepshade_said")) {
		AppAppendTTSPrompt(app, "You said deep shade.");
		printf("You said deepshade_said.\n");
		strcpy(plantLocationStringArray[envCounter], "DeepShade");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "eastwall_said")) {
		AppAppendTTSPrompt(app, "You said east wall.");
		printf("You said eastwall_said.\n");
		strcpy(plantLocationStringArray[envCounter], "EastWall");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "groundcover_said")) {
		AppAppendTTSPrompt(app, "You said ground cover.");
		printf("You said groundcover_said.\n");
		strcpy(plantLocationStringArray[envCounter], "GroundCover");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "habit_said")) {
		AppAppendTTSPrompt(app, "You said habit.");
		printf("You said habit_said.\n");
		strcpy(plantLocationStringArray[envCounter], "Habit");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "habitat_said")) {
		AppAppendTTSPrompt(app, "You said habitat.");
		printf("You said habitat_said.\n");
		strcpy(plantLocationStringArray[envCounter], "Habitat");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "hardyness_said")) {
		AppAppendTTSPrompt(app, "You said hardiness.");
		printf("You said hardyness_said.\n");
		strcpy(plantLocationStringArray[envCounter], "Hardyness");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "hedge_said")) {
		AppAppendTTSPrompt(app, "You said hedge.");
		printf("You said hedge_said.\n");
		strcpy(plantLocationStringArray[envCounter], "Hedge");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "hedgerow_said")) {
		AppAppendTTSPrompt(app, "You said hedgerow.");
		printf("You said hedgerow_said.\n");
		strcpy(plantLocationStringArray[envCounter], "Hedgerow");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "height_said")) {
		AppAppendTTSPrompt(app, "You said height.");
		printf("You said height_said.\n");
		strcpy(plantLocationStringArray[envCounter], "Height");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "latin_name_said")) {
		AppAppendTTSPrompt(app, "You said latin name.");
		printf("You said latin_name_said.\n");
		strcpy(plantLocationStringArray[envCounter], "Latin name");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "lawn_said")) {
		AppAppendTTSPrompt(app, "You said lawn.");
		printf("You said lawn_said.\n");
		strcpy(plantLocationStringArray[envCounter], "Lawn");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "meadow_said")) {
		AppAppendTTSPrompt(app, "You said meadow.");
		printf("You said meadow_said.\n");
		strcpy(plantLocationStringArray[envCounter], "Meadow");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "northwall_said")) {
		AppAppendTTSPrompt(app, "You said north wall.");
		printf("You said northwall_said.\n");
		strcpy(plantLocationStringArray[envCounter], "NorthWall");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "otherhabitats_said")) {
		AppAppendTTSPrompt(app, "You said other habitats.");
		printf("You said otherhabitats_said.\n");
		strcpy(plantLocationStringArray[envCounter], "OtherHabitats");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "pond_said")) {
		AppAppendTTSPrompt(app, "You said pond.");
		printf("You said pond_said.\n");
		strcpy(plantLocationStringArray[envCounter], "Pond");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "secondary_said")) {
		AppAppendTTSPrompt(app, "You said secondary.");
		printf("You said secondary_said.\n");
		strcpy(plantLocationStringArray[envCounter], "Secondary");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "shade_said")) {
		AppAppendTTSPrompt(app, "You said shade.");
		printf("You said shade_said.\n");
		strcpy(plantLocationStringArray[envCounter], "Shade");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "shadyedge_said")) {
		AppAppendTTSPrompt(app, "You said shady edge.");
		printf("You said shadyedge_said.\n");
		strcpy(plantLocationStringArray[envCounter], "ShadyEdge");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "southwall_said")) {
		AppAppendTTSPrompt(app, "You said south wall.");
		printf("You said southwall_said.\n");
		strcpy(plantLocationStringArray[envCounter], "SouthWall");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "sunnyedge_said")) {
		AppAppendTTSPrompt(app, "You said sunny edge.");
		printf("You said sunnyedge_said.\n");
		strcpy(plantLocationStringArray[envCounter], "SunnyEdge");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "walls_said")) {
		AppAppendTTSPrompt(app, "You said walls.");
		printf("You said walls_said.\n");
		strcpy(plantLocationStringArray[envCounter], "Walls");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "westwall_said")) {
		AppAppendTTSPrompt(app, "You said west wall.");
		printf("You said westwall_said.\n");
		strcpy(plantLocationStringArray[envCounter], "WestWall");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "width_said")) {
		AppAppendTTSPrompt(app, "You said width.");
		printf("You said width_said.\n");
		strcpy(plantLocationStringArray[envCounter], "Width");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}
	else if (!strcmp(buf, "woodlandgarden_said")) {
		AppAppendTTSPrompt(app, "You said woodland garden.");
		printf("You said woodlandgarden_said.\n");
		strcpy(plantLocationStringArray[envCounter], "WoodlandGarden");
		envCounter = envCounter + 1;
		AppGoto(app, "env2");
	}

	else {
		AppAppendTTSPrompt(app, "Try again.");
	}


	AppGotoSelf(app);
}
void environmentfn2(App *app) {

	AppSetGrammar(app, ".Start");
	char buf[200];
	int errorCounter = 0;



	int n = sizeof(plantLocationStringArray);
	printf("Number of terms so far: %d\n", envCounter);

	for (int i = 0; i < envCounter; i++) {
		printf("Element %d of plant locations is %s\n", i, plantLocationStringArray[i]);

	}

	char buf2[100];
	char buf3[100];

	if (firstEnvFn2Flag == 0) {
		sprintf(buf2, "SELECT COUNT(*) FROM `plantlocations` WHERE `%s`=1", plantLocationStringArray[0]);
		strcpy(storeBuf, buf2);
		firstEnvFn2Flag = 1;
	}
	else {
		strcpy(buf2, storeBuf);
	}




	for (int i = 0; i < envCounter; i++) {
		//printf("\n envCounter: %d\n", envCounter);
		//printf("27error %d\n", errorCounter = errorCounter + 1);
		char buf4[100];
		sprintf(buf4, " AND WHERE `%s`=1", plantLocationStringArray[i]);

		strcpy(buf2, concat(buf2, buf4));

	}


	printf("buf3: %s\n", buf3);
	printf("buf2: %s\n", buf2);

	//returnSQLCount(buf2);
	AppAppendTTSPrompt(app, buf3);

	AppAppendTTSPrompt(app, "Would you like to add another term?");


	if (!AppRecognize(app)) {
		printf("!AppRec\n");

		return;
	}

	NLGetStringSlotValue(AppGetNLResult(app), "binary_response_said", buf, 200);


	if (!strcmp(buf, "yes_said")) {
		AppAppendTTSPrompt(app, "You said yes.");
		printf("You said yes.\n");
		looped = 0;
		AppGoto(app, "environment");
	}
	else if (!strcmp(buf, "no_said")) {
		AppAppendTTSPrompt(app, "You said no.");
		printf("You said no.\n");
		strcpy(storeBuf2, buf2);
		AppGoto(app, "envResultsBuf", buf2);
		//envResultsFn2(app, buf2);
		sleep(1000);
	}
	AppGotoSelf(app);
}
void environmentfn3(App *app) {

	AppSetGrammar(app, ".Start");
	char buf[200];

	//Print number of items in env string
	printf("Number of terms so far: %d\n", envCounter);
	//print items in env string
	for (int i = 0; i < envCounter; i++) {
		printf("Element %d of plant locations is %s\n", i, plantLocationStringArray[i]);
	}
	//print number of items in habit string
	printf("Number of habits so far: %d\n", habitCounter);
	//print items in habit string
	for (int i = 0; i < habitCounter; i++) {
		printf("Element %d of habit is %s\n", i, plantHabitStringArray[i]);
	}

	//buf2 currently holds COUNT(*) query string
	char buf2[400];
	//Construct count and regular strings
	constructAdvancedString("count");
	strcpy(buf2, storeBufCount);
	constructAdvancedString("normal");
	printf("\nQuery: %s\n\n", storeBuf2);
	printf("SQL count string: %s\n", buf2);
	int sqlCount = returnSQLCount(app, buf2);
	if ((sqlCount != 0) && ((plantLocationStringArray[0] != NULL) || (plantHabitStringArray[0] != NULL))) {
		char buf3[100];
		sprintf(buf3, "Currently %d plants match your search criteria.", sqlCount);
		AppAppendTTSPrompt(app, buf3);
		//sprintf(buf3, "Currently %d plants match your search criteria.", returnSQLCount(app, buf2));
	}
	else if ((sqlCount == 0) && (plantLocationStringArray[0] == NULL) && (plantHabitStringArray[0] == NULL)) {
		AppAppendTTSPrompt(app, "Please add some search terms");
		AppGoto(app, "freeSpeak");
	}




	//AppAppendTTSPrompt(app, buf3);
	//if (returnSQLCount(app, buf2) == 0) {
	if ((sqlCount == 0) && (plantLocationStringArray[0] != NULL) && (plantHabitStringArray[0] != NULL)) {
		//AppGoto(app, "zeroMatchesEnv");
		AppAppendTTSPrompt(app, "I can't find any matching results, please remove some search terms.");
		AppGoto(app, "envCheck");
	}
	else if ((sqlCount != 0) && ((plantLocationStringArray[0] != NULL) || (plantHabitStringArray[0] != NULL))) {
		AppAppendTTSPrompt(app, "Would you like to add another term?");
	}

	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}

	NLGetStringSlotValue(AppGetNLResult(app), "binary_response_said", buf, 200);


	if (!strcmp(buf, "yes_said")) {
		AppAppendTTSPrompt(app, "You said yes.");
		printf("You said yes.\n");
		looped = 0;
		AppGoto(app, "freeSpeak");
	}
	else if (!strcmp(buf, "no_said")) {
		AppAppendTTSPrompt(app, "You said no.");
		printf("You said no.\n");
		if ((plantLocationStringArray[0] != NULL) && plantHabitStringArray[0] != NULL) {
			constructAdvancedString("count");
			AppSetGrammar(app, ".Start");
			//strcpy(buf2, storeBufCount);
			int countCheck = (returnSQLCount(app, storeBufCount));
			if (countCheck > 8) {
				char buf11[200];
				sprintf(buf11, "Are you sure you want me to read %d results?", returnSQLCount(app, storeBufCount));
				AppAppendTTSPrompt(app, buf11);
				if (!AppRecognize(app)) {
					printf("!AppRec\n");
					return;
				}
				char buf12[100];
				NLGetStringSlotValue(AppGetNLResult(app), "binary_response_said", buf12, 100);
				if (!strcmp(buf12, "yes_said")) {
					AppAppendTTSPrompt(app, "Okay, if you're sure.");
					constructAdvancedString("normal");
					AppGoto(app, "envResults");
				}
				else if (!strcmp(buf12, "no_said")) {
					AppAppendTTSPrompt(app, "You said no.");
					printf("No said.");
					AppGoto(app, "envPreCheck");
				}
				else {
					AppAppendTTSPrompt(app, "Try again.");
				}

			}
			else {
				constructAdvancedString("normal");
				AppGoto(app, "envResults");
			}

		}
		else {
			AppAppendTTSPrompt(app, "You must have at least one search term.");
			AppGoto(app, "freeSpeak");
		}
		//printf("You said no.\n");
		//if ((plantLocationStringArray[0] != NULL) && plantHabitStringArray[0] !=  NULL) {
		//	constructAdvancedString("normal");
		//	AppGoto(app, "envResults");
		//} else {
		//	AppAppendTTSPrompt(app, "You must have at least one search term.");
		//	AppGoto(app, "freeSpeak");
		//}

	}
	AppGotoSelf(app);
}
void envZeroMatches(App *app) {
	AppSetGrammar(app, ".ZeroMatches");
	char buf[200];
	AppAppendTTSPrompt(app, "Would you like to remove the last term, start searching again by environment, or start searching again via a different category?");


	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}

	NLGetStringSlotValue(AppGetNLResult(app), "env_zero_match_response_said", buf, 200);

	if (!strcmp(buf, "remove_last_said")) {
		AppAppendTTSPrompt(app, "You said you would like to remove the last item you added to the search term.");
		printf("You said you would like to remove the last item you added to the search term.\n");
		envCounter = envCounter - 1;
		AppGoto(app, "env2");
	}
	/*else if (!strcmp(buf, "restart_env_said")) {
	AppAppendTTSPrompt(app, "You said no.");
	printf("You said no.\n");
	AppGoto(app, "env2");
	}*/
	AppGotoSelf(app);

}

void constructAdvancedString(char *str) {
	strcpy(storeBuf2, "");
	strcpy(storeBufCount, "");




	if (!strcmp(str, "count")) {
		//if ((plantLocationStringArray[0] != "") && plantHabitStringArray[0] != "") {
		//if ((plantLocationStringArray[0] != "") || (envCounter != 0)) {
		if ((envCounter != 0)) {
			sprintf(storeBufCount, "SELECT COUNT(`Latin name`) FROM `plantlocations` WHERE `%s`=1", plantLocationStringArray[0]);
			for (int i = 1; i < envCounter; i++) {
				char buf6[100];
				sprintf(buf6, " AND `%s`=1", plantLocationStringArray[i]);
				strcpy(storeBufCount, concat(storeBufCount, buf6));
			}
			if (habitCounter > 0) {
				for (int n = 0; n < habitCounter; n++) {
					char buf8[100];
					sprintf(buf8, " AND `Habit`='%s'", plantHabitStringArray[n]);
					strcpy(storeBufCount, concat(storeBufCount, buf8));
				}
			}
		}
		//else if ((plantHabitStringArray[0] != "") || (habitCounter != 0)) {
		else if ((habitCounter != 0)) {
			sprintf(storeBufCount, "SELECT COUNT(`Latin name`) FROM `plantlocations` WHERE `Habit`='%s'", plantHabitStringArray[0]);
			for (int i = 1; i < habitCounter; i++) {
				char buf6[100];
				sprintf(buf6, " AND `Habit`='%s'", plantHabitStringArray[i]);
				strcpy(storeBufCount, concat(storeBufCount, buf6));
			}

		}
		if (hardyness != 0) {
			int hardyMax, hardyMin;
			char buf5[100];
			switch (hardyness) {
			case 3:
				hardyMin = 3;
				hardyMax = 10;
				break;
			case 5:
				hardyMin = 5;
				hardyMax = 10;
				break;
			case 7:
				hardyMin = 7;
				hardyMax = 10;
				break;
			case 10:
				hardyMin = 9;
				hardyMax = 10;
				break;

			}
			if ((envCounter == 0) && (habitCounter == 0)) {
				sprintf(buf5, "SELECT COUNT(`Latin name`) FROM `plantlocations` WHERE `Hardyness` BETWEEN %d AND %d", hardyMin, hardyMax);
			}
			else {
				sprintf(buf5, " AND `Hardyness` BETWEEN %d AND %d", hardyMin, hardyMax);
			}
			strcpy(storeBufCount, concat(storeBufCount, buf5));
		}
		/*if (global_width != 0) {
		int widthMin, widthMax;
		char buf6[100];
		switch (global_width) {
		case 1:
		widthMin = 0;
		widthMax = 1;
		break;
		case 2:
		widthMin = 1;
		widthMax = 3;
		break;
		case 3:
		widthMin = 2;
		widthMax = 30;
		break;
		}
		if ((hardyness == 0) && (envCounter == 0) && (habitCounter == 0)) {
		sprintf(buf6, "SELECT COUNT(`Latin name`) FROM `plantlocations` WHERE `Width` BETWEEN %d AND %d", widthMin, widthMin);
		}
		else {
		sprintf(buf6, " AND `Width` BETWEEN %d AND %d", widthMin, widthMin);
		}
		strcpy(storeBufCount, concat(storeBufCount, buf6));
		}*/
	}
	else if (!strcmp(str, "normal")) {
		//if ((plantLocationStringArray[0] != "") && plantHabitStringArray[0] != "") {
		if (envCounter != 0) {
			sprintf(storeBuf2, "SELECT `Common name`,`Latin name` FROM `plantlocations` WHERE `%s`=1", plantLocationStringArray[0]);
			for (int i = 1; i < envCounter; i++) {
				char buf6[100];
				sprintf(buf6, " AND `%s`=1", plantLocationStringArray[i]);
				strcpy(storeBuf2, concat(storeBuf2, buf6));
			}
			if (habitCounter > 0) {
				for (int n = 0; n < habitCounter; n++) {
					char buf8[100];
					sprintf(buf8, " AND `Habit`='%s'", plantHabitStringArray[n]);
					strcpy(storeBuf2, concat(storeBuf2, buf8));
				}
			}
		}
		else if (plantHabitStringArray[0] != "") {
			sprintf(storeBuf2, "SELECT `Common name`,`Latin name` FROM `plantlocations` WHERE `Habit`='%s'", plantHabitStringArray[0]);
			for (int i = 1; i < habitCounter; i++) {
				char buf6[100];
				sprintf(buf6, " AND `Habit`='%s'", plantHabitStringArray[i]);
				strcpy(storeBuf2, concat(storeBuf2, buf6));
			}

		}
		if (hardyness != 0) {
			int hardyMax, hardyMin;
			char buf5[100];
			switch (hardyness) {
			case 3:
				hardyMin = 3;
				hardyMax = 10;
				break;
			case 5:
				hardyMin = 5;
				hardyMax = 10;
				break;
			case 7:
				hardyMin = 7;
				hardyMax = 10;
				break;
			case 10:
				hardyMin = 9;
				hardyMax = 10;
				break;

			}
			if ((envCounter == 0) && (habitCounter == 0)) {
				sprintf(buf5, "SELECT `Common name`,`Latin name` FROM `plantlocations` WHERE `Hardyness` BETWEEN %d AND %d", hardyMin, hardyMax);
			}
			else {
				sprintf(buf5, " AND `Hardyness` BETWEEN %d AND %d", hardyMin, hardyMax);
			}
			strcpy(storeBuf2, concat(storeBuf2, buf5));
		}
		/*if (global_width != 0) {
		int widthMin, widthMax;
		char buf6[100];
		switch (global_width) {
		case 1:
		widthMin = 0;
		widthMax = 1;
		break;
		case 2:
		widthMin = 1;
		widthMax = 3;
		break;
		case 3:
		widthMin = 2;
		widthMax = 30;
		break;
		}
		if ((hardyness == 0) && (envCounter == 0) && (habitCounter == 0)) {
		sprintf(buf6, "SELECT `Latin name`,`Common name` FROM `plantlocations` WHERE `Width` BETWEEN %d AND %d", widthMin, widthMin);
		}
		else {
		sprintf(buf6, " AND `Width` BETWEEN %d AND %d", widthMin, widthMin);
		}
		strcpy(storeBufCount, concat(storeBufCount, buf6));
		}*/
	}
	else {
		printf("Programming error in calling constructAdvancedString, have you used either \"count\" or \"normal\" as arguments?");
	}

}

void envResultsBufFn(App *app, char str) {
}
void envResultsFn(App *app, char str) {


	AppSetGrammar(app, ".Start");
	char buf[200];
	printf("Query: %s\n", storeBuf2);

	SQLspeakQuery(app, storeBuf2);

	AppGoto(app, "results_s2");

	AppGotoSelf(app);


}

void results_s2_fn(App *app) {
	AppSetGrammar(app, ".Start");
	char buf[200];
	AppAppendTTSPrompt(app, "Would you like more information on any of these plants?");


	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}

	NLGetStringSlotValue(AppGetNLResult(app), "binary_response_said", buf, 200);
	if (!strcmp(buf, "yes_said")) {
		AppGoto(app, "reverseSearchFromResults");
		//AppCall(app, "reverseSearchFromResults", 1);
	//	AppCall(app, "reverseSearchFromResults");
		//AppGoto(app, "results_s3");
	}
	else if (!strcmp(buf, "no_said")) {
		AppGoto(app, "results_s3");
	}
	else {
		AppAppendTTSPrompt(app, "Try again.");
	}

	AppGotoSelf(app);

}

void results_s3_fn(App *app) {
	AppSetGrammar(app, ".Start");
	char buf[200];

	AppAppendTTSPrompt(app, "Would you like to use this service again?");

	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}

	NLGetStringSlotValue(AppGetNLResult(app), "binary_response_said", buf, 200);
	if (!strcmp(buf, "yes_said")) {
		printf("Okay, restarting...\n");
		AppAppendTTSPrompt(app, "Okay, restarting...");
		resetAllVars();
		AppGoto(app, "greeting");
	}
	else if (!strcmp(buf, "no_said")) {
		AppAppendTTSPrompt(app, "Thank you for using this service. Goodbye.");
		printf("Thank you for using this service. Goodbye.");
		if (!AppRecognize(app)) {
			printf("!AppRec\n");
			return;
		}
		sleep(6);
		exit(0);
	}
	else {
		AppAppendTTSPrompt(app, "Sorry, I didn't quite catch that.");
	}

	AppGotoSelf(app);
}