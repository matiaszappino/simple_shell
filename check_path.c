#include "shell.h"

int check_path(char ** args)
{
	struct stat fileStat;

    if (stat(args[0], &fileStat) == 0)
    {
        return (0);
    }
    else
    {
        return (1);
    } 
}