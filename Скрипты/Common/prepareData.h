#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LOGIN_LENGTH 6
#define PASSWORD_LENGTH 6
#define NAME_LENGTH 5
#define STREET_LENGTH 5
#define ZIP_CODE_LENGTH 6

typedef struct
{
	char login[LOGIN_LENGTH + 1];
	char password[PASSWORD_LENGTH + 1];
	char first_name[NAME_LENGTH + 1];
	char last_name[NAME_LENGTH + 1];
	char street[STREET_LENGTH + 1];
	char zip_code[ZIP_CODE_LENGTH + 1];
} user_data;

void generate_random_string(char *str, int length);
void prepareData(int userCount, char fileName[]);
void generate_user(user_data *result);
void print_to_file(FILE *file, user_data user);

void prepareData(int userCount, char fileName[]){
	user_data data;
	FILE* file;
	int i;
	srand(time(NULL));

	file = fopen(fileName, "w");
	if (file == 0) {
		return;
	}

	fprintf(file,"%s\n", "login,password,first_name,last_name,street,post_code");

	for(i = 0; i < userCount; i++) {
		generate_user(&data);
		print_to_file(file, data);
	}

	fclose(file);
}

void generate_user(user_data *result)
{
	char login[LOGIN_LENGTH + 1];
	char password[PASSWORD_LENGTH + 1];
	char firstName[NAME_LENGTH + 1];
	char lastName[NAME_LENGTH + 1];
	char street[STREET_LENGTH + 1];
	char zip_code[ZIP_CODE_LENGTH + 1];

	generate_random_string(login, LOGIN_LENGTH);
	generate_random_string(password, PASSWORD_LENGTH);
	generate_random_string(firstName, NAME_LENGTH);
	generate_random_string(lastName, NAME_LENGTH);
	generate_random_string(street, STREET_LENGTH);
	snprintf(zip_code, ZIP_CODE_LENGTH + 1, "%06d", rand() % 1000000);

	strcpy((*result).login, login);
	strcpy((*result).password, password);
	strcpy((*result).first_name, firstName);
	strcpy((*result).last_name, lastName);
	strcpy((*result).street, street);
	strcpy((*result).zip_code, zip_code);
}



void generate_random_string(char *str, int length) {
	int i;
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (i = 0; i < length; i++) {
        int key = rand() % (int)(sizeof(charset) - 1);
        str[i] = charset[key];
    }
	str[length] = '\0';
}

void print_to_file(FILE *file, user_data user){
	fprintf(file, "%s,", user.login);
	fprintf(file, "%s,", user.password);
	fprintf(file, "%s,", user.first_name);
	fprintf(file, "%s,", user.last_name);
	fprintf(file, "%s,", user.street);
	fprintf(file, "%s\n", user.zip_code);
}
