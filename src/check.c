//
// Created by Mystic Alien on 5/5/23.
//

#include "students.h"

void fill_empty_file()
{
	char group[1024];
	char first_group[1024];
	char second_group[1024];
	char id[1024];
	char name[1024];
	char surname[1024];
	char patronymic[1024];
	char date_of_birth[1024];

	printf("Введите \033[32mгруппу\033[0m нового студента:\n");
	scanf("%s %s", first_group, second_group);
	sprintf(group, "%s %s", first_group, second_group);
	printf("\nВведите \033[32mid\033[0m нового студента:\n");
	scanf("%s", id);
	printf("\nВведите \033[32mимя\033[0m нового студента:\n");
	scanf("%s", name);
	printf("\nВведите \033[32mфамилию\033[0m нового студента:\n");
	scanf("%s", surname);
	printf("\nВведите \033[32mотчество\033[0m нового студента:\n");
	scanf("%s", patronymic);
	printf("\nВведите дату рождения нового студента в формате \033[32mdd.mm.yyyy\033[0m:\n");
	scanf("%s", date_of_birth);
	json_t* group_json = json_object();
	json_object_set_new(group_json, "group_name", json_string(group));
	json_t* students_array = json_array();
	json_t* student_json = json_object();
	json_object_set_new(student_json, "id", json_string(id));
	json_object_set_new(student_json, "surname", json_string(surname));
	json_object_set_new(student_json, "name", json_string(name));
	json_object_set_new(student_json, "patronymic", json_string(patronymic));
	json_object_set_new(student_json, "date_of_birth", json_string(date_of_birth));
	json_array_append_new(students_array, student_json);
	json_t* credits_array = json_array();
	json_object_set_new(student_json, "credits", credits_array);
	json_t* exams_array = json_array();
	json_object_set_new(student_json, "exams", exams_array);
	json_object_set_new(group_json, "students", students_array);
	json_dump_file(group_json, filename, JSON_INDENT(4));
	json_decref(group_json);
}

void check_validity() {
	char *ptr;
	char *file_extension;
	int dot_count = 0;
	FILE *fp;

	ptr = input_file;
	file_extension = strrchr(input_file, '.');

	while (*ptr != '\0') {
		if (*ptr == '.')
			dot_count++;
		ptr++;
	}

	if (dot_count != 1 || strcmp(file_extension, ".json") != 0) {
		printf("\033[31m🚫 Error: Invalid file extension, it must be in\033[0m \033[32m.json\033[0m \033[31mformat 🚫\033[0m\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(filename, "r");
	if (!fp) {
		fp = fopen(filename, "w");
		printf("\033[32mFile created!\033[0m\n");
		fill_empty_file();
	}
	fclose(fp);
}