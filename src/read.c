//
// Created by Mystic Alien on 5/5/23.
//

#include "students.h"

char *read_file(char *file) {
	char* json_data;
	FILE *f = fopen(file, "rb");
	if (!f)
		error_handling("Failed to open file");
	fseek(f, 0, SEEK_END);
	long size = ftell(f);
	fseek(f, 0, SEEK_SET);
	json_data = malloc(size + 1);
	if (json_data == NULL)
		error_handling("Failed to allocate memory for json_data");
	fread(json_data, 1, size, f);
	fclose(f);
	json_data[size] = '\0';
	return (json_data);
}