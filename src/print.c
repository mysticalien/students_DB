//
// Created by Mystic Alien on 5/28/23.
//

#include "students.h"

void print_group(group *my_group)
{
	FILE* file = fopen("../print_group.txt", "w");
	fprintf(file, "Студенты:\n\n");
	for (size_t j = 0; j < my_group->num_students; j++)
	{
		fprintf(file, "\n*********************************************\n");
		fprintf(file, "Имя студента: %s\n", my_group->students[j].name);
		fprintf(file, "Фамилия студента: %s\n", my_group->students[j].surname);
		fprintf(file, "Отчество студента: %s\n", my_group->students[j].patronymic);
		fprintf(file, "Дата рождения студента: %s\n\n", my_group->students[j].date_of_birth);
		fprintf(file, "_____________________________________________\n");
		fprintf(file, "\nЗачеты:\n\n");
		for (size_t i = 0; i < my_group->students[j].num_credits; i++)
		{
			fprintf(file, "Название предмета: %s\n", my_group->students[j].student_credits[i].name);
			fprintf(file, "Оценка: %s\n", my_group->students[j].student_credits[i].mark);
			fprintf(file, "Дата сдачи: %s\n\n", my_group->students[j].student_credits[i].date_taken);
		}
		fprintf(file, "_____________________________________________\n");
		fprintf(file, "\nЭкзамены:\n\n");
		for (size_t i = 0; i < my_group->students[j].num_exams; i++)
		{
			fprintf(file, "Название предмета: %s\n", my_group->students[j].student_exams[i].name);
			fprintf(file, "Оценка: %s\n", my_group->students[j].student_exams[i].mark);
			fprintf(file, "Дата сдачи: %s\n\n", my_group->students[j].student_exams[i].date_taken);
		}
	}
	fclose(file);
	printf("\nФайл \033[32mprint_group.txt\033[0m готов к печати!");
}

void print_student(group *my_group)
{
	char answer[1024];
	int check = 0;
	printf("Введите \033[32mid\033[0m студента, информацию о котором надо распечатать:\n\n\n");
	scanf("%s", &answer);
	for (size_t j = 0; j < my_group->num_students; j++) {
		if (strcmp(answer, my_group->students[j].id) == 0) {
			check = 1;
			FILE* file = fopen("../print_student.txt", "w");
			fprintf(file, "Имя студента: %s\n", my_group->students[j].name);
			fprintf(file, "Фамилия студента: %s\n", my_group->students[j].surname);
			fprintf(file, "Отчество студента: %s\n", my_group->students[j].patronymic);
			fprintf(file, "Дата рождения студента: %s\n\n", my_group->students[j].date_of_birth);
			fprintf(file, "_____________________________________________\n");
			fprintf(file, "\nЗачеты:\n\n");
			for (size_t i = 0; i < my_group->students[j].num_credits; i++)
			{
				fprintf(file, "Название предмета: %s\n", my_group->students[j].student_credits[i].name);
				fprintf(file, "Оценка: %s\n", my_group->students[j].student_credits[i].mark);
				fprintf(file, "Дата сдачи: %s\n\n", my_group->students[j].student_credits[i].date_taken);
			}
			fprintf(file, "_____________________________________________\n");
			fprintf(file, "\nЭкзамены:\n\n");
			for (size_t i = 0; i < my_group->students[j].num_exams; i++)
			{
				fprintf(file, "Название предмета: %s\n", my_group->students[j].student_exams[i].name);
				fprintf(file, "Оценка: %s\n", my_group->students[j].student_exams[i].mark);
				fprintf(file, "Дата сдачи: %s\n\n", my_group->students[j].student_exams[i].date_taken);
			}
			fclose(file);
			printf("\nФайл \033[32mprint_student.txt\033[0m готов к печати!");
		}
	}
	if (check == 0)
		printf("\nСтудента с \033[32m%s\033[0m id не существует\n", answer);
}

void print_debts(group *my_group)
{
	FILE* file = fopen("../print_debts.txt", "w");
	fprintf(file, "ДОЛЖНИКИ:\n\n");
	for (size_t j = 0; j < my_group->num_students; j++)
	{
		for (size_t i = 0; i < my_group->students[j].num_credits; i++)
		{
			if (strcmp("Незачет", my_group->students[j].student_credits[i].mark) == 0)
			{
				fprintf(file, "\n*********************************************\n");
				fprintf(file, "Имя студента: %s\n", my_group->students[j].name);
				fprintf(file, "Фамилия студента: %s\n", my_group->students[j].surname);
				fprintf(file, "Отчество студента: %s\n", my_group->students[j].patronymic);
				fprintf(file, "Дата рождения студента: %s\n", my_group->students[j].date_of_birth);
				fprintf(file, "_____________________________________________\n");
				fprintf(file, "Долг по зачету:\n\n");
				fprintf(file, "Название предмета: %s\n", my_group->students[j].student_credits[i].name);
				fprintf(file, "Оценка: %s\n", my_group->students[j].student_credits[i].mark);
				fprintf(file, "Дата сдачи: %s\n", my_group->students[j].student_credits[i].date_taken);
			}
		}
		for (size_t i = 0; i < my_group->students[j].num_exams; i++)
		{
			if (strcmp("2", my_group->students[j].student_exams[i].mark) == 0)
			{
				fprintf(file, "\n*********************************************\n");
				fprintf(file, "Имя студента: %s\n", my_group->students[j].name);
				fprintf(file, "Фамилия студента: %s\n", my_group->students[j].surname);
				fprintf(file, "Отчество студента: %s\n", my_group->students[j].patronymic);
				fprintf(file, "Дата рождения студента: %s\n", my_group->students[j].date_of_birth);
				fprintf(file, "_____________________________________________\n");
				fprintf(file, "Долг по экзамену:\n\n");
				fprintf(file, "Название предмета: %s\n", my_group->students[j].student_exams[i].name);
				fprintf(file, "Оценка: %s\n", my_group->students[j].student_exams[i].mark);
				fprintf(file, "Дата сдачи: %s\n", my_group->students[j].student_exams[i].date_taken);
			}
		}
	}
	fclose(file);
	printf("\nФайл \033[32mprint_debts.txt\033[0m готов к печати!");
}

void print_info(group *my_group)
{
	char answer[1024];
	printf("\nЧтобы распечатать информацию о группе студентов, введите \033[32mгруппа\033[0m:\n");
	printf("Чтобы распечатать информацию о студенте, введите \033[32mстудент\033[0m:\n");
	printf("Чтобы распечатать информацию о должниках, введите \033[32mдолги\033[0m:\n\n\n");
	scanf("%s", answer);
	if (strcmp(answer, "группа") == 0)
		print_group(my_group);
	else if (strcmp(answer, "студент") == 0)
		print_student(my_group);
	else if (strcmp(answer, "долги") == 0)
		print_debts(my_group);
	answer_loop(my_group);
}