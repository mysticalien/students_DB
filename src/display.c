//
// Created by Mystic Alien on 5/26/23.
//

#include "students.h"

void display_students_info(student my_student) {
	int column_id = 13;
	int column_name = 22;
	int column_surname = 28;
	int column_patronymic = 23;
	int id_size = column_id - (strlen(my_student.id)/2);
	int name_size = column_name - (strlen(my_student.name)/2);
	int surname_size = column_surname - (strlen(my_student.surname)/2);
	int patronymic_size = column_patronymic - (strlen(my_student.patronymic)/2);

	printf("|   %s", my_student.id);
	for (int i = 0; i < id_size; i++)
		printf(" ");
	printf("%s", my_student.name);
	for (int i = 0; i < name_size; i++)
		printf(" ");
	printf("%s", my_student.surname);
	for (int i = 0; i < surname_size; i++)
		printf(" ");
	printf("%s", my_student.patronymic);
	for (int i = 0; i < patronymic_size; i++)
		printf(" ");
	printf("%s        |\n", my_student.date_of_birth);
}

void display_credits_exams(student my_student)
{
	int column_name = 21;
	int column_mark = 16;
	size_t check = 0;
	if (my_student.num_credits < my_student.num_exams)
		check = my_student.num_exams;
	else
		check = my_student.num_credits;
	for (size_t i = 0; i < check; i++)
	{
		if (my_student.num_credits != 0 && my_student.student_credits[i].name != NULL) {
			int credits_size = column_name - (strlen(my_student.student_credits[i].name)/2);
			if (strchr(my_student.student_credits[i].name, ' ') != NULL)
				credits_size--;
			int credits_mark_size = column_mark - (strlen(my_student.student_credits[i].mark)/2);
			printf("|  %s", my_student.student_credits[i].name);
			for (int j = 0; j < credits_size; j++)
				printf(" ");
			printf(" %s", my_student.student_credits[i].mark);
			for (int j = 0; j < credits_mark_size; j++)
				printf(" ");
			printf("%s", my_student.student_credits[i].date_taken);
		}
		else
		{
			printf("|");
			for (int j = 0; j < 50; j++)
				printf(" ");
		}
		if (my_student.num_exams != 0 && my_student.student_exams[i].name != NULL) {
			printf("       %s", my_student.student_exams[i].name);
			int exams_size = column_name - (strlen(my_student.student_exams[i].name) / 2);
			if (strchr(my_student.student_exams[i].name, ' ') != NULL)
				exams_size--;
			for (int j = 0; j < exams_size; j++)
				printf(" ");
			printf("   %s", my_student.student_exams[i].mark);
			printf("             %s", my_student.student_exams[i].date_taken);
		}
		else
		{
			for (int j = 0; j < 55; j++)
				printf(" ");
		}
		printf("   |\n");
	}
}

void display_student_info(student my_student) {
	char result[1024];
	int column_name = 65;
	sprintf(result, "%s %s %s", my_student.surname, my_student.name, my_student.patronymic);
	int title_size = column_name - (strlen(result)/2);
	printf("\n\n");
	printf("|************************************************************************************************************|\n");
	printf("|");
	for (int i = 0; i < title_size; i++)
		printf(" ");
	printf("%s", result);
	for (int i = 0; i < (107 - column_name); i++)
		printf(" ");
	printf("|\n");
	printf("|************************************************************************************************************|\n");
	printf("|                        Зачеты                        |                        Экзамены                     |\n");
	printf("|************************************************************************************************************|\n");
	printf("|  Название предмета     Оценка          Дата сдачи    |  Название предмета       Оценка        Дата сдачи   |\n");
	printf("|************************************************************************************************************|\n");
	display_credits_exams(my_student);
	printf("|____________________________________________________________________________________________________________|\n\n\n");
}

void find_student(char* input_id, group* my_group) {
	int found = 1;
	for (size_t i = 0; i < my_group->num_students; i++) {
		if (strcmp(input_id, my_group->students[i].id) == 0) {
			display_student_info(my_group->students[i]);
			found = 0;
		}
	}
	if (found == 1)
		printf("\nТакого студента не существует\n\n\n");
	answer_loop(my_group);
}

void display_fails_exams(student *my_student, exams *student_exam)
{
	int column_name = 15;
	int column_surname = 20;
	int column_patronymic = 20;
	int credit_name = 23;
	int name_size = column_name - (strlen(my_student->name)/2);
	int surname_size = column_surname - (strlen(my_student->surname)/2);
	int patronymic_size = column_patronymic - (strlen(my_student->patronymic)/2);
	int credit_name_size = credit_name - (strlen(student_exam->name)/2);
	if (strchr(student_exam->name, ' ') != NULL)
		credit_name_size--;

	printf("|     %s", my_student->name);
	for (int i = 0; i < name_size; i++)
		printf(" ");
	printf("%s", my_student->surname);
	for (int i = 0; i < surname_size; i++)
		printf(" ");
	printf("%s", my_student->patronymic);
	for (int i = 0; i < patronymic_size; i++)
		printf(" ");
	printf("%s", student_exam->name);
	for (int i = 0; i < credit_name_size; i++)
		printf(" ");
	printf("%s", student_exam->mark);
	printf("           %s", student_exam->date_taken);
	printf("   |\n");
}

void display_fails_credits(student *my_student, credits *student_credit)
{
	int column_name = 15;
	int column_surname = 20;
	int column_patronymic = 20;
	int credit_name = 23;
	int name_size = column_name - (strlen(my_student->name)/2);
	int surname_size = column_surname - (strlen(my_student->surname)/2);
	int patronymic_size = column_patronymic - (strlen(my_student->patronymic)/2);
	int credit_name_size = credit_name - (strlen(student_credit->name)/2);
	if (strchr(student_credit->name, ' ') != NULL)
		credit_name_size--;

	printf("|     %s", my_student->name);
	for (int i = 0; i < name_size; i++)
		printf(" ");
	printf("%s", my_student->surname);
	for (int i = 0; i < surname_size; i++)
		printf(" ");
	printf("%s", my_student->patronymic);
	for (int i = 0; i < patronymic_size; i++)
		printf(" ");
	printf("%s", student_credit->name);
	for (int i = 0; i < credit_name_size; i++)
		printf(" ");
	printf("%s", student_credit->mark);
	printf("     %s", student_credit->date_taken);
	printf("   |\n");
}

void display_debts(group *my_group) {
	printf("\n\n\n|************************************************************************************************************|\n");
	printf("|                                        Академические задолженности                                         |\n");
	printf("|************************************************************************************************************|\n");
	printf("|     Имя            Фамилия             Отчество            Предмет                Оценка      Дата сдачи   |\n");
	printf("|************************************************************************************************************|\n");
	for (size_t i = 0; i < my_group->num_students; i++) {
		for (size_t j = 0; j < my_group->students[i].num_credits; j++)
		{
			if (strcmp("Незачет", my_group->students[i].student_credits[j].mark) == 0)
				display_fails_credits(&my_group->students[i], &my_group->students[i].student_credits[j]);
		}
		for (size_t j = 0; j < my_group->students[i].num_exams; j++)
		{
			if (strcmp("2", my_group->students[i].student_exams[j].mark) == 0)
				display_fails_exams(&my_group->students[i], &my_group->students[i].student_exams[j]);
		}
	}
	printf("|____________________________________________________________________________________________________________|\n\n\n");
	answer_loop(my_group);
}

void parse_answer(char *input, group* my_group) {
	if (strcmp(input, "добавить") == 0)
		add_student(my_group);
	else if (strcmp(input, "изменить") == 0)
		edit_student(my_group);
	else if (strcmp(input, "удалить") == 0)
		delete_student(my_group);
	else if (strcmp(input, "долги") == 0)
		display_debts(my_group);
	else if (strcmp(input, "печать") == 0)
		print_info(my_group);
	else
		find_student(input, my_group);
}

void display_all_students(group *my_group) {
	printf("\n\n");
	printf("|************************************************************************************************************|\n");
	printf("|                                                  %s                                                  |\n", my_group->group_name);
	printf("|************************************************************************************************************|\n");
	printf("|   ID            Имя                   Фамилия                     Отчество               Дата рождения     |\n");
	printf("|************************************************************************************************************|\n");
	for (size_t i = 0; i < my_group->num_students; i++)
		display_students_info( my_group->students[i]);
	printf("|____________________________________________________________________________________________________________|\n\n\n");
	answer_loop(my_group);
}

void answer_loop(group *my_group) {
	while (1) {
		char answer[1024];
		printf("\n\nЕсли вы хотите вывести информацию о студентах в группе, введите \033[32mгруппа\033[0m\n");
		printf("Чтобы вывести информацию о студенте, введите его \033[32mid\033[0m:\n");
		printf("Чтобы добавить нового студента, введите \033[32mдобавить\033[0m:\n");
		printf("Чтобы изменить информацию об уже существующем студенте, введите \033[32mизменить\033[0m:\n");
		printf("Чтобы удалить студента из базы данных, введите \033[32mудалить\033[0m:\n");
		printf("Чтобы найти студентов с академическими задолженностями, введите \033[32mдолги\033[0m:\n");
		printf("Чтобы выйти из приложения, введите \033[32mвыход\033[0m:\n");
		printf("Чтобы распечатать информацию о группе или студенте, введите \033[32mпечать\033[0m:\n\n\n");
		scanf("%s", answer);
		if (strcmp(answer, "группа") == 0) {
			display_all_students(my_group);
			break;
		} else if (strcmp(answer, "выход") == 0) {
			break;
		} else {
			parse_answer(answer, my_group);
			break;
		}
	}
}