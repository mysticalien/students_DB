//
// Created by Mystic Alien on 5/12/23.
//

#include "students.h"

void parse_exams(json_t *student_json, student *student_obj)
{
	student_obj->student_exams = malloc(student_obj->num_exams * sizeof(exams));
	if (student_obj->student_exams == NULL)
		error_handling("Failed to allocate memory for student_exams");
	for (size_t i = 0; i < student_obj->num_exams; i++) {
		json_t *exams_json = json_array_get(json_object_get(student_json, "exams"), i);
		student_obj->student_exams[i].name = strdup(json_string_value(json_object_get(exams_json, "name")));
		student_obj->student_exams[i].mark = strdup(json_string_value(json_object_get(exams_json, "mark")));
		student_obj->student_exams[i].date_taken = strdup(json_string_value(json_object_get(exams_json, "date_taken")));
	}
}

void parse_credits(json_t *student_json, student *student_obj)
{
	student_obj->student_credits = malloc(student_obj->num_credits * sizeof(credits));
	if (student_obj->student_credits == NULL)
		error_handling("Failed to allocate memory for student_credits");
	for (size_t i = 0; i < student_obj->num_credits; i++) {
		json_t *credits_json = json_array_get(json_object_get(student_json, "credits"), i);
		student_obj->student_credits[i].name = strdup(json_string_value(json_object_get(credits_json, "name")));
		student_obj->student_credits[i].mark = strdup(json_string_value(json_object_get(credits_json, "mark")));
		student_obj->student_credits[i].date_taken = strdup(json_string_value(json_object_get(credits_json, "date_taken")));
	}
}

void parse_student(json_t *student_json, student *student_obj)
{
	student_obj->id = strdup(json_string_value(json_object_get(student_json, "id")));
	student_obj->surname = strdup(json_string_value(json_object_get(student_json, "surname")));
	student_obj->name = strdup(json_string_value(json_object_get(student_json, "name")));
	student_obj->patronymic = strdup(json_string_value(json_object_get(student_json, "patronymic")));
	student_obj->date_of_birth = strdup(json_string_value(json_object_get(student_json, "date_of_birth")));
	student_obj->num_credits = json_array_size(json_object_get(student_json, "credits"));
	student_obj->num_exams = json_array_size(json_object_get(student_json, "exams"));
	parse_credits(student_json, student_obj);
	parse_exams(student_json, student_obj);
}

group *parse_data(char *json_data) {
	group *my_group = malloc(sizeof(group));
	if (my_group == NULL)
		error_handling("Failed to allocate memory for group");

	json_error_t error;
	json_t *root = json_loads(json_data, 0, &error);
//	root = json_loads(json_data, 0, &error);
	if (!root) {
		free(json_data);
		error_handling("Error parsing JSON data");
	}

	my_group->group_name = strdup(json_string_value(json_object_get(root, "group_name")));

	my_group->num_students = json_array_size(json_object_get(root, "students"));
	my_group->students = malloc(my_group->num_students * sizeof(student));
	if (my_group->students == NULL) {
		free(my_group->group_name);
		free(json_data);
		json_decref(root);
		error_handling("Failed to allocate memory for students");
	}
	for (size_t i = 0; i < my_group->num_students; i++) {
		json_t *student_json = json_array_get(json_object_get(root, "students"), i);
		parse_student(student_json, &(my_group->students[i]));
	}

	json_decref(root);
	free(json_data);

	return my_group;
}