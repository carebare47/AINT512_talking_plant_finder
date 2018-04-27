#include "env_states.h"

int looped = 0;
int envCounter = 0;
int habitCounter = 0;
int firstEnv = 0;
char storeBuf[400];
char* storeBuf2[400];
int firstEnvFn2Flag = 0;

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

	sprintf(buf2, "SELECT COUNT(*) FROM `plantlocations` WHERE `%s`=1", plantLocationStringArray[0]);

	for (int i = 1; i < envCounter; i++) {
		//printf("\n envCounter: %d\n", envCounter);
		//printf("27error %d\n", errorCounter = errorCounter + 1);
		char buf4[100];
		sprintf(buf4, " AND `%s`=1", plantLocationStringArray[i]);

		strcpy(buf2, concat(buf2, buf4));

	}


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
		AppGoto(app, "environment");
	}
	else if (!strcmp(buf, "no_said")) {
		AppAppendTTSPrompt(app, "You said no.");
		printf("You said no.\n");
		sprintf(storeBuf2, "SELECT `Common name`,`Latin name` FROM `plantlocations` WHERE `%s`=1", plantLocationStringArray[0]);
		for (int i = 1; i < envCounter; i++) {
			char buf6[100];
			sprintf(buf6, " AND `%s`=1", plantLocationStringArray[i]);
			strcpy(storeBuf2, concat(storeBuf2, buf6));
		}
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


	printf("Number of terms so far: %d\n", envCounter);

	for (int i = 0; i < envCounter; i++) {
		printf("Element %d of plant locations is %s\n", i, plantLocationStringArray[i]);
	}

	char buf2[400];

	sprintf(buf2, "SELECT COUNT(*) FROM `plantlocations` WHERE `%s`=1", plantLocationStringArray[0]);

	for (int i = 1; i < envCounter; i++) {
		//printf("\n envCounter: %d\n", envCounter);
		//printf("27error %d\n", errorCounter = errorCounter + 1);
		char buf4[100];
		sprintf(buf4, " AND `%s`=1", plantLocationStringArray[i]);

		strcpy(buf2, concat(buf2, buf4));

	}


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
		AppGoto(app, "environment");
	}
	else if (!strcmp(buf, "no_said")) {
		AppAppendTTSPrompt(app, "You said no.");
		printf("You said no.\n");
		sprintf(storeBuf2, "SELECT `Common name`,`Latin name` FROM `plantlocations` WHERE `%s`=1", plantLocationStringArray[0]);
		for (int i = 1; i < envCounter; i++) {
			char buf6[100];
			sprintf(buf6, " AND `%s`=1", plantLocationStringArray[i]);
			strcpy(storeBuf2, concat(storeBuf2, buf6));
		}
		AppGoto(app, "envResults");
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
void envResultsBufFn(App *app, char str) {
}
void envResultsFn(App *app, char str) {


	AppSetGrammar(app, ".Start");
	char buf[200];
	printf("Query: %s\n", storeBuf2);

	SQLspeakQuery(app, storeBuf2);

	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}

	NLGetStringSlotValue(AppGetNLResult(app), "binary_response_said", buf, 200);

	sleep(1000);
	AppGotoSelf(app);

}

