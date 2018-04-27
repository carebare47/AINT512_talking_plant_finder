#include "test_states.h"

//const char* locale = "Britain";
int firstTestFlag = 0;
void testfn(App *app) {
	//AppCreateState(app, "start", "root", startfn); 
	AppSetGrammar(app, ".Start");
	char buf[100];


	if (firstTestFlag == 0) {
		printf("\nNumber of matches: %d\n\n", returnSQLnumberOfMatches(app, "SELECT * FROM sym"));
		speakComposition(app, "Common", "Shallots", 1);
		firstTestFlag = 1;
	}
	NLGetStringSlotValue(AppGetNLResult(app), "binary_response_said", buf, 100);
	if (!AppRecognize(app)) {
		printf("!AppRec\n");
		return;
	}
	AppGotoSelf(app);
}