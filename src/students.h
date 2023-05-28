//
// Created by Mystic Alien on 5/5/23.
//

#ifndef STUDENTS_H
#define STUDENTS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <jansson.h>
#include <stdbool.h>
#include <sys/statvfs.h>

char filename[1024];
char input_file[1024];

typedef struct {
	char *name;
	char *mark;
	char *date_taken;
} credits;

typedef struct {
	char *name;
	char *mark;
	char *date_taken;
} exams;

typedef struct {
	char	*id;
	char	*surname;
	char	*name;
	char	*patronymic;
	char	*date_of_birth;
	size_t	num_credits;
	size_t	num_exams;
	credits	*student_credits;
	exams	*student_exams;
} student;

typedef struct {
	char	*group_name;
	size_t	num_students;
	student	*students;
} group;

void	error_handling(char *strerror);
char	*read_file(char *file);
void	check_validity();
group	*parse_data(char *json_data);
void	free_group(group *my_group);
void	add_student(group *my_group);
void	edit_student(group *my_group);
void	find_student(char* input_id, group* my_group);
void	display_student_info(student my_student);
void	delete_student(group *my_group);
void	free_students(student *my_student);
void	answer_loop(group *my_group);
void	print_info(group *my_group);

#endif //STUDENTS_H
