#include <stdio.h>
#include <stdlib.h>

/******************************************
 * int exp(int x, int pow) {              *
 * 	int res = 1;                      *
 * 	while (pow > 0) {                 *
 * 		if (pow % 2) res = res*x; *
 * 		pow = pow/2;              *
 * 		if (pow > 0) x = x*x;     *
 * 	}                                 *
 * 	return res;                       *
 * }                                      *
 ******************************************/
 
 #define TRACE(x) printf("\t" #x "\n"); x
 #define HEAD "int exp"
 #define TAIL "(int x) {\n"
 
int body_gen(int x, int pow) {
	TRACE(int res = 1;)
	
	while (pow > 0) {
 		if (pow % 2) {TRACE(res = res*x;)}
 		pow = pow/2;
		if (pow > 0) {TRACE(x = x*x;)}
	}
	
	TRACE(return res;)
}

void function_gen(int pow) {
	printf(HEAD "%d" TAIL, pow);
	body_gen(1, pow); //first param is not important
	printf("}\n");
}

int main(int argc, char *argv[]) {
	char *endp = NULL;
	int pow = 0;
	
	if (argc < 2) {
		fprintf(stderr, "usage: program <pow>\npow - positive integer number\n");
		exit(1);
	}
	
	pow = strtol(argv[1], &endp, 10);
	if (*endp != '\0') {
		fprintf(stderr, "positive integer number expected\n");
		exit(1);
	}
	
	function_gen(pow);
	
	return 0;
}