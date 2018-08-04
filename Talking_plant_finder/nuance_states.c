#include "nuance_states.h"

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