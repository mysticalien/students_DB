//
// Created by Mystic Alien on 5/26/23.
//

#include "students.h"

void free_exams(student *my_student)
{
	for (size_t i = 0; i < my_student->num_exams; i++)
	{
		free(my_student->student_exams[i].name);
		free(my_student->student_exams[i].mark);
		free(my_student->student_exams[i].date_taken);
	}
	free(my_student->student_exams);
}

void free_credits(student *my_student)
{
	for (size_t i = 0; i < my_student->num_credits; i++)
	{
		free(my_student->student_credits[i].name);
		free(my_student->student_credits[i].mark);
		free(my_student->student_credits[i].date_taken);
	}
	free(my_student->student_credits);
}

void free_students(student *my_student)
{
	free(my_student->id);
	free(my_student->surname);
	free(my_student->name);
	free(my_student->patronymic);
	free(my_student->date_of_birth);
	if (my_student->student_credits != NULL)
		free_credits(my_student);
	if (my_student->student_exams != NULL)
		free_exams(my_student);
}

void free_group(group *my_group)
{
	for (size_t i = 0; i < my_group->num_students; i++) {
		free_students(&(my_group->students[i]));
	}
	free(my_group->students);
	free(my_group->group_name);
	free(my_group);
}