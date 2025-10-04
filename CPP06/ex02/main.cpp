/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 00:00:00 by yitani            #+#    #+#             */
/*   Updated: 2025/10/02 20:51:43 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

Base	*generate(void)
{
    static int count = 0;
    switch (count++ % 3)
    {
        case 0:
			return (new A());
        case 1:
			return (new B());
        case 2:
			return (new C());
        default:
			return (NULL);
    }
}

void	identify(Base *p)
{
	std::cout << "Object pointed to: ";
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	std::cout << "Object refered to: ";
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch(...)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch(...)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}
			catch(...)
			{
				std::cout << "Unknown type" << std::endl;
			}
		}
	}
}

int main(void)
{
	for (int i = 0; i < 10; i++)
	{
		Base *obj = generate();
		identify(obj);
		identify(*obj);
		delete obj;
		std::cout << std::endl;
	}

	return (0);
}