#include <stdio.h>
#include "stdlib.h"
#include "main.h"

char *app_cmds[CMDS][CMDFIELDS] = {
        { "n", "Generate all the strings of 'n' bits" },
        { "n k ", "Generate all the strings of length 'n' from 0..k -1" },
	{ }
};

char array[100];

void f0_binary(int n)
{
	if (n < 1) {
		printf("%s\n", array);
	} else {
		int i = n - 1;

		array[i] = '0';
		f0_binary(i);
		array[i] = '1';
		f0_binary(i);
	}
}

void f1_k_string(int n, int k)
{
	if (n < 1) {
		printf("%s\n", array);
	} else {
		int i = n - 1;

		for (int j = 0; j < k; ++j) {
			array[i] = j + 'a';
			f1_k_string(i, k);
		}
	}
}

int main(int argc, char *argv[])
{
	app_name = argv[0];

	if (argc < 3) {
		print_usage();
		return 0;
	}

	switch (atoi(argv[1])) {
	case 0:
		f0_binary(atoi(argv[2]));
		break;
	case 1:
		if (argc > 3)
			f1_k_string(atoi(argv[2]), atoi(argv[3]));
		else
			print_usage();
		break;
	default:
		print_usage();
		break;
	}

	return 0;
}
