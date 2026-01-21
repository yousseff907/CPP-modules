/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:40:27 by yitani            #+#    #+#             */
/*   Updated: 2026/01/21 13:04:04 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->inputNumbers = other.inputNumbers;
	this->vect = other.vect;
	this->deq = other.deq;
	this->vectorTime = other.vectorTime;
	this->dequeTime = other.dequeTime;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->inputNumbers = other.inputNumbers;
		this->vectorTime = other.vectorTime;
		this->dequeTime = other.dequeTime;
		this->vect = other.vect;
		this->deq = other.deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{}

double PmergeMe::getCurrTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000.0 + tv.tv_usec);
}

void PmergeMe::parseInput(int argc, char **argv)
{
	if (argc < 2)
		throw std::invalid_argument("Invalid Input");

	for (int i = 1; i < argc; i++)
	{
		std::string arg(argv[i]);

		if (arg.find_first_not_of("0123456789") != std::string::npos)
			throw std::invalid_argument("Invalid Input");
		
		long long num = std::atoi(arg.c_str());
		if (num <= 0 || num > INT_MAX)
			throw std::invalid_argument("Invalid Input");

		this->inputNumbers.push_back((int)num);
		this->vect.push_back((int)num);
		this->deq.push_back((int)num);
	}
}


void	fordJohnsonSort(std::vector<int> vect)
{
	
}
void	fordJohnsonSort(std::deque<int> deq)
{
	
}

void PmergeMe::sort(void)
{
	double start, end;

	start = getCurrTime();
	fordJohnsonSort(vect);
	end = getCurrTime();
	vectorTime = end - start;

	start = getCurrTime();
	fordJohnsonSort(deq);
	end = getCurrTime();
	dequeTime = end - start;
}

void	PmergeMe::displayResults(void)
{
	long long	size = inputNumbers.size();
	std::cout << "Before: ";
	for (size_t i = 0; i < inputNumbers.size(); i++)
	{
		std::cout << " " << inputNumbers[i];
	}
	std::cout << std::endl;

	std::cout << "After: ";
	for (size_t i = 0; i < vect.size(); i++)
	{
		std::cout << " " << vect[i];
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::vector<int> : " << vectorTime << " μs" << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::deque<int> : " << dequeTime << " μs" << std::endl;
}