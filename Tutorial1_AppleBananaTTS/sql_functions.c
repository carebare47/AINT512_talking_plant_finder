#include "sql_functions.h"




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
void SQLcolumnReturn(App *app, char* str) {

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

	//Create search query
	//SELECT DISTINCT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = 'plantlocations'
	char* s1 = concat("SELECT DISTINCT COLUMN_NAME FROM INFORMATION_SCHEMA.COLUMNS WHERE TABLE_NAME = '", str);
	char* s2 = concat(s1, "' ORDER BY `");
	char* s3 = concat(s2, "COLUMN_NAME");
	char* s4 = concat(s3, "` ASC;");
	//printf("Query = %s\n\n\n", s4);

	if (mysql_query(con, s4))
	{
		finish_with_error(con);
	}

	MYSQL_RES *result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error(con);
	}

	int num_fields = mysql_num_fields(result);
	//int num_rows = mysql_num_rows(result);

	MYSQL_ROW row;
	int length = 0;

	while ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			if (row[i]) {
				if (length < strlen(row[i])) {
					length = strlen(row[i]);
				}
			}
		}
	}
	//printf("First query executed, max string length = %d\n\n\n", length);

	if (mysql_query(con, s4))
	{
		finish_with_error(con);
	}

	result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error(con);
	}

	int oscillator = 0;
	while ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			printf("\t%-*s\t", (length + 1), row[i] ? row[i] : "NULL");
			oscillator = oscillator + 1;
			if (oscillator == 2) {
				printf("\n");
				oscillator = 0;
			}
		}
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

void speakComposition(App *app, char* type, char* str, int speak) {

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
	char* s0 = concat("SELECT * FROM composition WHERE `", type); //Common Name`='", str);
	char* s1 = concat(s0, " Name`='");
	char* s2 = concat(s1, str);
	char* s3 = concat(s2, "'");
	//char* s1 = concat("SELECT * FROM composition WHERE `Common Name`='", str);
	//char* s2 = concat(s1, "'");
	char buf[100];
	sprintf(buf, "SELECT * FROM composition WHERE `%s Name`='%s'", type, str);
	printf("\nQuery being sent: %s\n\n", buf);
	if (mysql_query(con, buf))
	{
		finish_with_error(con);
	}

	MYSQL_RES *result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error(con);
	}

	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
	MYSQL_FIELD *field;
	printf("\n");
	char buf2[100];
	char buf3[100];
	while ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			field = mysql_fetch_field(result);
			if (row[i]) {
				if (!strcmp(field->name, "Dry or Fresh weight")) {
					if (!strcmp(row[i], "F")) {
						sprintf(buf2, "The following weights are per 100 grams when the plant is fresh\n");
						printf("%s", buf2);
						if (speak == 1) {
							AppAppendTTSPrompt(app, buf2);
						}
					}
					else if (!strcmp(row[i], "D")) {
						sprintf(buf2, "The following weights are per 100 grams when the plant is dry\n");
						printf("%s", buf2);
						if (speak == 1) {
							AppAppendTTSPrompt(app, buf2);
						}
					}
					else {
						sprintf(buf2, "NULL");
					}
				}
				else if (!strcmp(field->name, "VitaminC")) {
					sprintf(buf2, "%s %s \n", "Vitamin C", row[i]);
					printf("%s", buf2);
					if (speak == 1) {
						AppAppendTTSPrompt(app, buf2);
					}
				}
				else if (!strcmp(field->name, "VitaminA")) {
					sprintf(buf2, "%s %s \n", "Vitamin A", row[i]);
					printf("%s", buf2);
					if (speak == 1) {
						AppAppendTTSPrompt(app, buf2);
					}
				}
				else {
					//printf("%s %s \n", field->name, row[i]);
					sprintf(buf3, "%s %s \n", field->name, row[i]);
					printf("%s", buf3);
					if (speak == 1) {
						AppAppendTTSPrompt(app, buf3);
					}
				}

			}

		}
	}
	printf("\n");


	mysql_free_result(result);
	mysql_close(con);
}



int returnSQLnumberOfMatches(App *app, char* str) {

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

	if (mysql_query(con, str))
	{
		finish_with_error(con);
	}

	MYSQL_RES *result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error(con);
	}

	int num_fields = mysql_num_fields(result);
	//printf("num_fields: %d", num_fields);
	MYSQL_ROW row;
	int non_null_counter = 0;
	while ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			//printf("%s ", row[i] ? row[i] : "NULL");
			if (row[i]) {
				non_null_counter += 1;
			}

		}

	}
	//printf("Non_null_counter = %d ", non_null_counter);
	mysql_free_result(result);
	mysql_close(con);
	return num_fields;
}
int returnSQLCount(App *app, char* str) {

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

	if (mysql_query(con, str))
	{
		finish_with_error(con);
	}

	MYSQL_RES *result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error(con);
	}

	int num_fields = mysql_num_fields(result);
	//printf("num_fields: %d", num_fields);
	MYSQL_ROW row;
	int non_null_counter = 0;
	int sqlCount = 0;
	while ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			//printf("row: %d", i);
			//printf("%s ", row[i] ? row[i] : "NULL");
			if (row[i]) {
				sqlCount = atoi(row[i]);
			}

		}

	}
	//printf("Non_null_counter = %d ", non_null_counter);
	mysql_free_result(result);
	mysql_close(con);
	return sqlCount;
}

void SQLspeakQuery(App *app, char* str) {


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

	if (mysql_query(con, str))
	{
		finish_with_error(con);
	}

	MYSQL_RES *result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error(con);
	}

	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
	AppAppendTTSPrompt(app, "Here are your results. Common name and then Latin name : ");
	while ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			printf("%s ", row[i] ? row[i] : "NULL");
			//printf("%s ", row[i]);
			AppAppendTTSPrompt(app, row[i]);
		}
		AppAppendSilence(app, 400);
		printf("\n");
	}

	mysql_free_result(result);
	mysql_close(con);

}


void SQLspeakQueryResultsOnly(App *app, char* str) {


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

	if (mysql_query(con, str))
	{
		finish_with_error(con);
	}

	MYSQL_RES *result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error(con);
	}

	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
	//AppAppendTTSPrompt(app, "Here are your results. Common name and then Latin name : ");
	while ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			printf("%s ", row[i] ? row[i] : "NULL");
			//printf("%s ", row[i]);
			AppAppendTTSPrompt(app, row[i]);
		}
		AppAppendSilence(app, 400);
		printf("\n");
	}

	mysql_free_result(result);
	mysql_close(con);

}

void SQLReverseSearch(App *app, char* str) {


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

	if (mysql_query(con, str))
	{
		finish_with_error(con);
	}

	MYSQL_RES *result = mysql_store_result(con);

	if (result == NULL)
	{
		finish_with_error(con);
	}


	int num_fields = mysql_num_fields(result);
	MYSQL_ROW row;
	MYSQL_FIELD *field;	printf("\n");
	char buf2[100];
	char buf3[100];
	int growWellInFlag = 0;
	while ((row = mysql_fetch_row(result)))
	{
		for (int i = 0; i < num_fields; i++)
		{
			field = mysql_fetch_field(result);
			if (row[i]) {
				//if (row[i] == 1) {
				if ((!strcmp(field->name, "Width")) || (!strcmp(field->name, "Height")) || (!strcmp(field->name, "Hardyness")) || (!strcmp(field->name, "Latin name")) || (!strcmp(field->name, "Habitat")) || (!strcmp(field->name, "Habit"))) {
					if (!strcmp(field->name, "Hardyness")) {
						AppAppendTTSPrompt(app, "With a hardyness rating of");
						AppAppendTTSPrompt(app, row[i]);
						AppAppendTTSPrompt(app, "out of ten.");
						sprintf(buf3, "%s %s \n", field->name, row[i]);
						printf("%s", buf3);
						printf("\n");
					}
					else {
						sprintf(buf3, "%s %s \n", field->name, row[i]);
						printf("%s", buf3);
						//if (speak == 1) {
						AppAppendTTSPrompt(app, buf3);
						printf("\n");
					}
				}
				else {
					
					if (!(strcmp(row[i], "1"))) {
						if (growWellInFlag == 0) {
							AppAppendTTSPrompt(app, "This plant will grow well in ");
							growWellInFlag = 1;
						}
						//printf("%s %s \n", field->name, row[i]);
						sprintf(buf3, "%s \n", field->name);
						printf("%s", buf3);
						//if (speak == 1) {
						AppAppendTTSPrompt(app, buf3);
						printf("\n");

						//}

					}

				}
				
			}
		}
	}
	

	mysql_free_result(result);
	mysql_close(con);
}

