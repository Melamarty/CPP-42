/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-amar <mel-amar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 04:55:03 by mel-amar          #+#    #+#             */
/*   Updated: 2024/07/07 15:20:09 by mel-amar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main (int ac, char **av)
{
	int i = 1;

	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return (0);
	}
	while (i < ac)
	{
		int j= 0;
		std::string str = av[i];
		while (str[j])
		{
			std::cout << (char)std::toupper(str[j]);
			j++;
		}
		i++;
	}
}