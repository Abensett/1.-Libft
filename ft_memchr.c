#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*s2;

	if (s == NULL)
		return (NULL);
	i = 0;
	s2 = (void *)s;
	while (i < n)
	{
		if (s2[i] == (char)c)
			return (&s2[i]);
		i++;
	}
	return (NULL);
}
