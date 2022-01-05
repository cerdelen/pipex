/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:29:20 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/23 20:29:20 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Cerdelen < cerdelen@student.42wolfsburg.de +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 21:03:49 by Cerdelen          #+#    #+#             */
/*   Updated: 2021/11/21 21:03:49 by Cerdelen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

# include <stdlib.h>

# include <unistd.h>
/*
* Description
*	Copies n bytes from memory area src to memory area dst.
*	If dst and src overlap, behavior is undefined.  Applications in which dst
*	and src might overlap should use memmove(3) instead.
*
* Return Values
*	The original value of dst.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*a1;
	const char	*a2;

	a1 = (char *) dest;
	a2 = (const char *) src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	while (i < n)
	{
		a1[i] = a2[i];
		i++;
	}
	return (dest);
}


/*
* Description
*	Allocates (with malloc(3)) and returns an array of strings obtained by
*	splitting ’s’ using the character ’c’ as a delimiter. The array is ended
*	by a NULL pointer.
*
* Parameters
*	#1. The string to be split.
*	#2. The delimiter character.
*
* Return Values
*	The array of new strings resulting from the split.
*	NULL if the allocation fails.
*/

int	wordamount(char const *s, char c)
{
	int	amount;
	int	i;

	i = 0;
	amount = 1;
	while (s[i] != 0)
	{
		if (s[i] == c)
		amount++;
	i++;
	}
	return (amount);
}

char	*initstring(char const *s, char c)
{
	char	*str;
	int		len;

	len = 0;
	while (s[len] != c && s[len] != 0)
		len++;
	if (len == 0)
		return (NULL);
	str = calloc(len + 1, sizeof(char));
	str = ft_memcpy(str, s, len);
	return (str);
}
void printargarr(char **knoodle)
{
	int ind;

	ind = 0;
	while (knoodle[ind] != NULL)
	{
		printf("this is argument nr %d = %s\n", ind +1, knoodle[ind]);
		ind++;
	}
}


char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (!s)
		return (NULL);
	ptr = malloc((wordamount(s, c) + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] == 0)
			break ;
		if (count == 0 || s[i - 1] == c)
			ptr[count++] = initstring(s + i, c);
		i++;
	}
	ptr[count] = NULL;
	return (ptr);
}

int main()
{
	char **test1;
	char **test2;
	
	test1 = ft_split("ls", ' ');
	test2 =  ft_split("wc -l", ' ');
	printargarr(test1);
	printargarr(test2);

}