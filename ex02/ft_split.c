/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:52:29 by hwong             #+#    #+#             */
/*   Updated: 2022/09/07 10:52:29 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
input eg: 	"testing 1 2 3" " "
			"test.ing 1.2 3" " ."
expected output 	["testing", "1", "2", "3"]
					["test", "ing", "1", "2", "3"]

need to know how much memory to alloc, count size of each string 
sandwiched by 2 seperators then malloc that size in one slot of the 2d array
*/

#include <stdlib.h>

int	in_string(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_strings(char *str, char *charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && in_string(str[i], charset))
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && !in_string(str[i], charset))
			i++;
	}
	return (count);
}

int	ft_strlen_sep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !in_string(str[i], charset))
		i++;
	return (i);
}

char	*ft_word(char *str, char *charset)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = ft_strlen_sep(str, charset);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**strings;
	int		i;

	i = 0;
	strings = (char **)malloc(sizeof(char *) * (count_strings(str, charset)
				+ 1));
	while (*str != '\0')
	{
		while (*str != '\0' && in_string(*str, charset))
			str++;
		if (*str != '\0')
		{
			strings[i] = ft_word(str, charset);
			i++;
		}
		while (*str && !in_string(*str, charset))
			str++;
	}
	strings[i] = 0;
	return (strings);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int		index;
	char	**split;

	(void)argc;
	split = ft_split(argv[1], argv[2]);
	index = 0;
	while (split[index])
	{
		printf("%s\n", split[index]);
		index++;
	}
}
*/