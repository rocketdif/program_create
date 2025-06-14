/*
 * Author: David I Fontes
 * Create the given file argument name
 */
#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>

char *progname = "create";
char *usage = "Usage: %s [OPTION]... FILE...\n";

static int verbose_flag = 0;

int main(int argc, char *argv[]){
	int     opt;

	static struct option long_options[] =
        {
                /* These options set a flag. */
                {"verbose", no_argument,        &verbose_flag, 'v'},
                /* These options don't set a flag
                 * We distinguish them by their indices. */
                {"help",    no_argument,        0, 'h'},
                {"version", no_argument,        0, 'V'},
                {0, 0, 0, 0}
        };
        /* getopt_long stores the option index here */
        int option_index = 0;

	        /*
         * Process command line options
         */
        while( (opt = getopt_long( argc, argv, "vV", long_options, &option_index)) != -1 )
        {
            switch(opt)
            {
                case 'v':
                    verbose_flag = 1;
                    break;
                case 'V':
                    printf("%s (ROCKETDIF coreutils) 1.0.2025\n", progname);
                    printf("Copyright (C) 2025 Rocket Software Inc.\n");
                    printf("Written by David I Fontes\n");
                    return EXIT_SUCCESS;
                case '?':
                    fprintf(stderr, "Try '%s --help' for more information.\n", progname);
                    return EXIT_FAILURE;
                case 'h':
                    printf(usage, progname);
                    printf("Create given filename.\n");
                    printf("  --help\t\tHelp. Display a help screen and quit.\n");
                    printf("  -v --verbose\t\tVerbose. Output more information.\n");
                    printf("  -V --version\t\tVersion. Output version information and exit.\n");
                    printf("\nExamples:\n");
                    printf("%s file.txt\n", progname);
                    return EXIT_SUCCESS;
            }
        }
	if (verbose_flag)
	{
		printf("%s: VERBOSE OUTPUT\n", progname);
		printf("%s: optind %d argc %d\n", progname, optind, argc);
	}
	if (optind < argc )
	{
		FILE *fp = fopen(argv[optind], "w");
    		fclose(fp);
	}
	else
	{
		printf(usage, progname);
		return EXIT_FAILURE;
	}

    	return EXIT_SUCCESS;
}
