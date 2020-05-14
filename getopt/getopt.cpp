#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
	printf("Unregistered option:\n");
	{
		char *dummyArgv[2];
		dummyArgv[0] = "getopt";
		dummyArgv[1] = "-w";

		int opt = 0;
		while ((opt = getopt(2, dummyArgv, "i:")) != -1) {
			switch (opt) {
			case '?':
				printf("Unregistered option received\n");
				break;
			default:
				break;
			}
		}
	}
	printf("\n\n");

	optind = 1;

	printf("Argument when not expected:\n");	// Premature exit
	{
		char *dummyArgv[5];
		dummyArgv[0] = "getopt";
		dummyArgv[1] = "-k";
		dummyArgv[2] = "-t";
		dummyArgv[3] = "value";
		dummyArgv[4] = "-i";

		int opt = 0;
		while ((opt = getopt(5, dummyArgv, "ikt")) != -1) {
			switch (opt) {
			case 'i':
				printf("Received '-i'\n");
				break;
			case 'k':
				printf("Received '-k'\n");
				break;
			case 't':
				printf("Received '-t' with value '%s'\n", optarg);
				break;
			case '?':
				printf("Unknown option received\n");
				break;
			default:
				printf("Error %c\n", opt);
				break;
			}
		}
	}
	printf("\n\n");

	optind = 1;

	printf("No argument when expected:\n");	// Next options return as value!
	{
		char *dummyArgv[3];
		dummyArgv[0] = "getopt";
		dummyArgv[1] = "-t";
		dummyArgv[2] = "-i";

		int opt = 0;
		while ((opt = getopt(3, dummyArgv, "it:")) != -1) {
			switch (opt) {
			case 'i':
				printf("Received '-i'\n");
				break;
			case 't':
				printf("Received '-t' with value '%s'\n", optarg);
				break;
			case '?':
				printf("Unknown option received\n");
				break;
			default:
				printf("Error %c\n", opt);
				break;
			}
		}
	}
	printf("\n\n");

	optind = 1;

	printf("Junk:\n");	// Premature exit!
	{
		char *dummyArgv[3];
		dummyArgv[0] = "getopt";
		dummyArgv[1] = "woo";
		dummyArgv[2] = "-i";

		int opt = 0;
		while ((opt = getopt(3, dummyArgv, "i")) != -1) {
			switch (opt) {
			case 'i':
				printf("Received '-i'\n");
				break;
			case '?':
				printf("Unknown option received\n");
				break;
			default:
				printf("Error %c\n", opt);
				break;
			}
		}
	}
	printf("\n\n");

	return 0;
}
