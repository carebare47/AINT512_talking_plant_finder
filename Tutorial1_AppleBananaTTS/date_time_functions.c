#include "date_time_functions.h"


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
