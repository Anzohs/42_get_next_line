#include <stdio.h>

char	*ft_test(char *s)
{
	int i = 0;

	while (s[i] != 'a')
		i++;
	return ((s + i));
}

int	main()
{
	char *s = ft_test("testar");
	printf("%s", s);

}