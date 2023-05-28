//
// Created by Mystic Alien on 5/27/23.
//

#include "students.h"

bool is_unique(const char *id, group *my_group) {
	for (size_t i = 0; i < my_group->num_students; i++) {
		if (strcmp(id, my_group->students[i].id) == 0) {
			return false;
		}
	}
	return true;
}

void write_json_to_file(group* my_group) {

	json_t* group_json = json_object();
	json_object_set_new(group_json, "group_name", json_string(my_group->group_name));

	json_t* students_array = json_array();
	for (size_t i = 0; i < my_group->num_students; i++) {
		json_t* student_json = json_object();
		json_object_set_new(student_json, "id", json_string(my_group->students[i].id));
		json_object_set_new(student_json, "surname", json_string(my_group->students[i].surname));
		json_object_set_new(student_json, "name", json_string(my_group->students[i].name));
		json_object_set_new(student_json, "patronymic", json_string(my_group->students[i].patronymic));
		json_object_set_new(student_json, "date_of_birth", json_string(my_group->students[i].date_of_birth));
		json_array_append_new(students_array, student_json);
		json_t* credits_array = json_array();
		for (size_t j = 0; j < my_group->students[i].num_credits; j++) {
			json_t *credits_json = json_object();
			json_object_set_new(credits_json, "name", json_string(my_group->students[i].student_credits[j].name));
			json_object_set_new(credits_json, "mark", json_string(my_group->students[i].student_credits[j].mark));
			json_object_set_new(credits_json, "date_taken", json_string(my_group->students[i].student_credits[j].date_taken));
			json_array_append_new(credits_array, credits_json);
		}
		json_object_set_new(student_json, "credits", credits_array);
		json_t* exams_array = json_array();
		for (size_t j = 0; j < my_group->students[i].num_exams; j++) {
			json_t *exams_json = json_object();
			json_object_set_new(exams_json, "name", json_string(my_group->students[i].student_exams[j].name));
			json_object_set_new(exams_json, "mark", json_string(my_group->students[i].student_exams[j].mark));
			json_object_set_new(exams_json, "date_taken", json_string(my_group->students[i].student_exams[j].date_taken));
			json_array_append_new(exams_array, exams_json);
		}
		json_object_set_new(student_json, "exams", exams_array);
	}
	json_object_set_new(group_json, "students", students_array);

	json_dump_file(group_json, filename, JSON_INDENT(4));

	json_decref(group_json);
}

void edit_exams(student *my_student)
{
	char name[1024];
	char first_name[1024];
	char second_name[1024];
	char mark[1024];
	char date_taken[1024];
	printf("\nВведите \033[32mназвание\033[0m предмета, по которому хотите изменить информацию:\n");
	scanf("%s", name);
	if (my_student->num_exams < 5) {
		if (my_student->num_exams == 0)
		{
			my_student->num_exams++;
			my_student->student_exams = malloc(sizeof(exams));
			if (my_student->student_exams == NULL)
				error_handling("Failed to allocate memory for student_exams");
			my_student->student_exams[my_student->num_exams - 1].name = strdup(name);
			printf("\nВведите \033[32mоценку\033[0m по экзамену:\n");
			scanf("%s", mark);
			printf("\nВведите \033[32mдату сдачи экзамена\033[0m в формате \033[32mdd.mm.yyyy\033[0m по предмету:\n");
			scanf("%s", date_taken);
			my_student->student_exams[my_student->num_exams - 1].mark = strdup(mark);
			my_student->student_exams[my_student->num_exams - 1].date_taken = strdup(date_taken);
		}
		else {
			int check = 0;
			for (size_t i = 0; i < my_student->num_exams; i++) {
				if (strcmp(name, my_student->student_exams[i].name) == 0) {
					check = 1;
					printf("\nВведите \033[32mновую оценку\033[0m по экзамену:\n");
					scanf("%s", mark);
					printf("\nВведите \033[32mновую дату сдачи экзамена\033[0m в формате \033[32mdd.mm.yyyy\033[0m по предмету:\n");
					scanf("%s", date_taken);
					free(my_student->student_exams[i].mark);
					free(my_student->student_exams[i].date_taken);
					my_student->student_exams[i].mark = strdup(mark);
					my_student->student_exams[i].date_taken = strdup(date_taken);
				}
			}
			if (check == 0) {
				my_student->num_exams++;
				my_student->student_exams = realloc(my_student->student_exams, my_student->num_exams * sizeof(exams));
				my_student->student_exams[my_student->num_exams - 1].name = strdup(name);
				printf("\nВведите \033[32mоценку\033[0m по экзамену:\n");
				scanf("%s", mark);
				printf("\nВведите \033[32mдату сдачи экзамена\033[0m в формате \033[32mdd.mm.yyyy\033[0m по предмету:\n");
				scanf("%s", date_taken);
				my_student->student_exams[my_student->num_exams - 1].mark = strdup(mark);
				my_student->student_exams[my_student->num_exams - 1].date_taken = strdup(date_taken);
			}
		}
	}
	else
		printf("У студента не может быть больше 5 экзаменов!\n");
}

void edit_credits(student *my_student)
{
	char name[1024];
	char first_name[1024];
	char second_name[1024];
	char mark[1024];
	char date_taken[1024];
	printf("\nВведите \033[32mназвание\033[0m предмета, по которому хотите изменить информацию:\n");
	scanf("%s", name);
	if (my_student->num_credits < 10) {
		if (my_student->num_credits == 0)
		{
			my_student->num_credits++;
			my_student->student_credits = malloc(sizeof(credits));
			if (my_student->student_credits == NULL)
				error_handling("Failed to allocate memory for student_credits");
			my_student->student_credits[my_student->num_credits - 1].name = strdup(name);
			printf("\nВведите \033[32mоценку\033[0m по зачету:\n");
			scanf("%s", mark);
			printf("\nВведите \033[32mдату сдачи зачета\033[0m в формате \033[32mdd.mm.yyyy\033[0m по предмету:\n");
			scanf("%s", date_taken);
			my_student->student_credits[my_student->num_credits - 1].mark = strdup(mark);
			my_student->student_credits[my_student->num_credits - 1].date_taken = strdup(date_taken);
		}
		else {
			int check = 0;
			for (size_t i = 0; i < my_student->num_credits; i++) {
				if (strcmp(name, my_student->student_credits[i].name) == 0) {
					check = 1;
					printf("\nВведите \033[32mновую оценку\033[0m по зачету:\n");
					scanf("%s", mark);
					printf("\nВведите \033[32mновую дату сдачи зачета\033[0m в формате \033[32mdd.mm.yyyy\033[0m по предмету:\n");
					scanf("%s", date_taken);
					free(my_student->student_credits[i].mark);
					free(my_student->student_credits[i].date_taken);
					my_student->student_credits[i].mark = strdup(mark);
					my_student->student_credits[i].date_taken = strdup(date_taken);
				}
			}
			if (check == 0) {
				my_student->num_credits++;
				my_student->student_credits = realloc(my_student->student_credits, my_student->num_credits * sizeof(credits));
				my_student->student_credits[my_student->num_credits - 1].name = strdup(name);
				printf("\nВведите \033[32mоценку\033[0m по зачету:\n");
				scanf("%s", mark);
				printf("\nВведите \033[32mдату сдачи зачета\033[0m в формате \033[32mdd.mm.yyyy\033[0m по предмету:\n");
				scanf("%s", date_taken);
				my_student->student_credits[my_student->num_credits - 1].mark = strdup(mark);
				my_student->student_credits[my_student->num_credits - 1].date_taken = strdup(date_taken);
			}
		}
	}
	else
		printf("У студента не может быть больше 10 зачетов!\n");
}

void edit_full_name(student *my_student)
{
	char answer[1024];
	char name[1024];
	char surname[1024];
	char patronymic[1024];
	printf("\nЧтобы изменить имя студента, введите \033[32mимя\033[0m:\n");
	printf("\nЧтобы изменить фамилию студента, введите \033[32mфамилия\033[0m:\n");
	printf("\nЧтобы изменить отчество студента, введите \033[32mотчество\033[0m:\n\n\n");
	scanf("%s", answer);
	if (strcmp(answer, "имя") == 0)
	{
		printf("\nВведите новое \033[32mимя\033[0m студента:\n\n\n");
		scanf("%s", name);
		free(my_student->name);
		my_student->name = strdup(name);
	}
	if (strcmp(answer, "фамилия") == 0)
	{
		printf("\nВведите новую \033[32mфамилию\033[0m студента:\n");
		scanf("%s", surname);
		free(my_student->surname);
		my_student->surname = strdup(surname);
	}
	if (strcmp(answer, "отчество") == 0)
	{
		printf("\nВведите новое \033[32mотчество\033[0m студента:\n");
		scanf("%s", patronymic);
		free(my_student->patronymic);
		my_student->patronymic = strdup(patronymic);
	}
}


void edit_student(group *my_group)
{
	char id[1024];
	char answer[1024];
	int check = 0;
	printf("Введите \033[32mid\033[0m студента, информацию о котором хотите изменить:\n");
	scanf("%s", id);
	for (size_t i = 0; i < my_group->num_students; i++) {
		if (strcmp(id, my_group->students[i].id) == 0) {
			check = 1;
			printf("\nЧтобы изменить ФИО студента, введите \033[32mфио\033[0m:\n");
			printf("Чтобы изменить зачеты студента, введите \033[32mзачеты\033[0m:\n");
			printf("Чтобы изменить экзамены студента, введите \033[32mэкзамены\033[0m:\n\n\n");
			scanf("%s", answer);
			if (strcmp(answer, "фио") == 0)
				edit_full_name(&my_group->students[i]);
			else if (strcmp(answer, "зачеты") == 0)
				edit_credits(&my_group->students[i]);
			else if (strcmp(answer, "экзамены") == 0)
				edit_exams(&my_group->students[i]);
			write_json_to_file(my_group);
			answer_loop(my_group);
		}
	}
	if (check == 0) {
		printf("\nТакого студента не существует\n\n\n");
		answer_loop(my_group);
	}
}


void delete_student(group *my_group)
{
	char id[1024];
	int check = 0;
	printf("Введите \033[32mid\033[0m студента, информацию о котором хотите удалить:\n");
	scanf("%s", id);
	for (size_t i = 0; i < my_group->num_students; i++) {
		if (strcmp(id, my_group->students[i].id) == 0) {
			check = 1;
			free_students(&my_group->students[i]);
			for (size_t j = i; j < my_group->num_students - 1; j++)
				my_group->students[j] = my_group->students[j + 1];
			my_group->num_students--;
			my_group->students = realloc(my_group->students, my_group->num_students * sizeof(student));
			write_json_to_file(my_group);
			answer_loop(my_group);
		}
	}
	if (check == 0) {
		printf("\nТакого студента не существует\n\n\n");
		answer_loop(my_group);
	}
}


void add_student(group *my_group)
{
	char id[1024];
	bool unique_id;
	char name[1024];
	char surname[1024];
	char patronymic[1024];
	char date_of_birth[1024];


	printf("Введите \033[32mid\033[0m нового студента:\n");
	scanf("%s", id);
	unique_id = is_unique(id, my_group);
	if (unique_id)
	{
		if (my_group->num_students < 20) {
			my_group->students = realloc(my_group->students, (my_group->num_students + 1) * sizeof(student));
			my_group->students[my_group->num_students].id = strdup(id);
			printf("\nВведите \033[32mимя\033[0m нового студента:\n");
			scanf("%s", name);
			my_group->students[my_group->num_students].name = strdup(name);
			printf("\nВведите \033[32mфамилию\033[0m нового студента:\n");
			scanf("%s", surname);
			my_group->students[my_group->num_students].surname = strdup(surname);
			printf("\nВведите \033[32mотчество\033[0m нового студента:\n");
			scanf("%s", patronymic);
			my_group->students[my_group->num_students].patronymic = strdup(patronymic);
			printf("\nВведите дату рождения нового студента в формате \033[32mdd.mm.yyyy\033[0m:\n");
			scanf("%s", date_of_birth);
			my_group->students[my_group->num_students].date_of_birth = strdup(date_of_birth);
			my_group->students[my_group->num_students].num_credits = 0;
			my_group->students[my_group->num_students].num_exams = 0;
			my_group->num_students++;
			write_json_to_file(my_group);
			answer_loop(my_group);
		}
		else {
			printf("В группе студентов не может быть больше 20 человек!\n");
			answer_loop(my_group);
		}
	}
	else {
		printf("\n\033[32mid\033[0m студента должен быть уникальным!\n\n");
		add_student(my_group);
	}
}