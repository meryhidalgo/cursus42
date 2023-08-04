#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void	child_process(int fd1[2], int fd2[2], char *fixed_str, char *concat_str)
{
	close(fd1[1]); // Close writing end of first pipe

	// Read a string using first pipe
	read(fd1[0], concat_str, 100);

	// Concatenate a fixed string with it
	int k = strlen(concat_str);
	int i;
	for (i = 0; i < strlen(fixed_str); i++)
	concat_str[k++] = fixed_str[i];

	concat_str[k] = '\0'; // string ends with '\0'

	// Close both reading ends
	close(fd1[0]);
	close(fd2[0]);

	// Write concatenated string and close writing end
	write(fd2[1], concat_str, strlen(concat_str) + 1);
	close(fd2[1]);

	exit(0);
}

int main()
{
	// We use two pipes
	// First pipe to send input string from parent
	// Second pipe to send concatenated string from child
 
	int		fd1[2]; // Used to store two ends of first pipe
	int		fd2[2]; // Used to store two ends of second pipe
	char	fixed_str[] = "forgeeks.org";
	char	input_str[100];
	char	concat_str[100];
	pid_t	p;
 
	if (pipe(fd1) == -1)
	{
		fprintf(stderr, "Pipe Failed");
		return (1);
	}
	if (pipe(fd2) == -1)
	{
		fprintf(stderr, "Pipe Failed");
		return (1);
	}
	scanf("%s", input_str);
	p = fork();
	if (p < 0)
	{
		fprintf(stderr, "fork Failed");
		return (1);
	}
	// Parent process
	else if (p > 0)
	{
		close(fd1[0]); // Close reading end of first pipe
		// Write input string and close writing end of first
		// pipe.
		write(fd1[1], input_str, strlen(input_str) + 1);
		close(fd1[1]);
		// Wait for child to send a string
		wait(NULL);
		close(fd2[1]); // Close writing end of second pipe
		// Read string from child, print it and close
		// reading end.
		read(fd2[0], concat_str, 100);
		printf("Concatenated string %s\n", concat_str);
		close(fd2[0]);
	}
	else
		child_process(fd1, fd2, fixed_str, concat_str);
}
