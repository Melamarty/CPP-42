#pragma once

#include <iostream>

template <typename T>
int f(T t)
{
	std::cout << "displaying: ";
	std::cout << t << std::endl;
	return (0);
}

template <typename Arr, typename Len, typename Fun>

void iter(Arr a, Len l, Fun f)
{
	for (int i = 0; i < l ; i++)
	{
		f(a[i]);
	}
}