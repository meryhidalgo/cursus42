/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariacarazohidalgo <mariacarazohidalgo@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:54:47 by mariacarazo       #+#    #+#             */
/*   Updated: 2022/09/25 21:22:43 by mariacarazo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//include

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*fstr;

	i = 0;
	//puntero s vacio?
	fstr = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	while (s[i] != 0)
	{
		fstr[i] = f(i, s[i]);
		i++;
	}
	fstr[i] = 0;
	return (fstr);
}