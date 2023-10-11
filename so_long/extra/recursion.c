void story(char **string1, int n)
{
    if ( n > 0 )
    {
        printf("a %s who couldn't sleep,\n", *(string1 + n));
        printf("so the %s's mother told her a story about\n", *(string1 + n));
        story(string1, n - 1);
        printf("then the %s went to sleep.", *(string1 + n));
    }
    else
    {
        printf("a %s who went to sleep.", *string1);
    }
}

int	main(int argc, char **argv)
{
	story(argv, 5);
	return(0);
}
