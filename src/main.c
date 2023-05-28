//
// Created by Mystic Alien on 5/2/23.
//

#include "students.h"

void	error_handling(char *strerror)
{
	printf("\033[31m🚫 %s 🚫\033[0m\n", strerror);
	exit(EXIT_FAILURE);
}

void check_free_space()
{
	struct statvfs stat;

	if (statvfs(filename, &stat) == 0) {
		unsigned long long availableSpace = stat.f_bavail * stat.f_frsize;
		unsigned long long requiredSpace = sizeof(group) +
										   20 * sizeof(student) +
										   20 * sizeof(credits) * 5 +
										   20 * sizeof(exams) * 10;

		if (availableSpace >= requiredSpace)
			printf("\033[32m\n\nThere is enough free space\033[0m\n");
		else
			error_handling("Insufficient free space!");
	} else
		error_handling("Failed to retrieve file system information.\n");
}


int main() {
	group* my_group;
	char* json_data;
	printf("Чтобы загрузить файл в программу, введите его \033[32mназвание\033[0m:\n");
	scanf("%s", input_file);
	sprintf(filename, "../%s", input_file); // this path for CMakeLists, if you want to work with Makefile, edit here
	check_validity();
	check_free_space();
	json_data = read_file(filename);
	my_group = parse_data(json_data);
	answer_loop(my_group);
	if (my_group != NULL)
		free_group(my_group);
	return 0;
}