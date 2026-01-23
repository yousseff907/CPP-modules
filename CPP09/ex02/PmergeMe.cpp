/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:40:27 by yitani            #+#    #+#             */
/*   Updated: 2026/01/23 00:38:42 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	vectorTime = 0;
	dequeTime = 0;
	comparisons = 0;
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->comparisons = other.comparisons;
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
		this->comparisons = other.comparisons;
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

std::vector<size_t>		PmergeMe::generateJacobsthal(size_t n)
{
	std::vector<size_t> jacobsthal;
	size_t	i = 2;
		
	if (n < 3)
		return (jacobsthal);
	
	jacobsthal.push_back(1);
	jacobsthal.push_back(1);
	jacobsthal.push_back(3);
	while (jacobsthal[i] < n)
	{
		size_t	next = jacobsthal[i] + (2 * jacobsthal[i - 1]);

		if (next > n)
			break;

		jacobsthal.push_back(next);
		i++;
	}
	return (jacobsthal);
}

template<typename Container>
void	PmergeMe::binaryInsert(Container& container, int value, size_t maxPos)
{
	size_t	left = 0;
	size_t	right = maxPos;
	
	while (left < right)
	{
		size_t	mid = left + (right - left) / 2;

		comparisons++;
		if (container[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}

	container.insert(container.begin() + left, value);
}

template<typename Container>
size_t	findPositionInContainer(Container &container, int value)
{
	for (size_t i = 0; i < container.size(); i++)
	{
		if (container[i] == value)
			return i;
	}
	return container.size();
}

template<typename Container>
void	PmergeMe::fordJohnsonSort(Container& container)
{
	if (container.size() <= 1)
		return ;

	int straggler = -1;
	bool hasStraggler = false;

	if (container.size() % 2 != 0)
	{
		straggler = container.back();
		hasStraggler = true;
		container.pop_back();
	}

	std::vector<std::pair<int, int> >	pairs;
	for (size_t	i = 0; i < container.size(); i+=2)
	{
		int a = container[i];
		int b = container[i + 1];

		comparisons++;
		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	std::vector<int>	mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
	}

	fordJohnsonSort(mainChain);

	std::vector<int>	sortedLosers;
	for (size_t i = 0; i < mainChain.size(); i++)
	{
		for (size_t j = 0; j < pairs.size(); j++)
		{
			if (mainChain[i] == pairs[j].first)
			{
				sortedLosers.push_back(pairs[j].second);
				break;
			}
		}
	}

	container.clear();
	container.push_back(sortedLosers[0]);
	for (size_t i = 0; i < mainChain.size(); i++)
		container.push_back(mainChain[i]);

	std::vector<size_t> Jacobsthal = generateJacobsthal(pairs.size() - 1);

	size_t	prevJacob = 1;
	for (size_t i = 0; i < Jacobsthal.size(); i++)
	{
		size_t currentJacob = Jacobsthal[i];
		if (currentJacob > pairs.size())
			currentJacob = pairs.size();

		for (int j = currentJacob - 1; j >= (int)prevJacob; j--)
		{
			binaryInsert(container, sortedLosers[j], findPositionInContainer(container, mainChain[j]));
		}

		prevJacob = currentJacob;
	}

	for (size_t j = prevJacob; j < pairs.size(); j++)
	{
		binaryInsert(container, sortedLosers[j], findPositionInContainer(container, mainChain[j]));
	}

	if (hasStraggler)
		binaryInsert(container, straggler, container.size());
}

void PmergeMe::sort(void)
{
	double start, end;

	comparisons = 0;
	start = getCurrTime();
	fordJohnsonSort(vect);
	end = getCurrTime();
	vectorTime = end - start;
	size_t vectorComparisons = comparisons;

	comparisons = 0;
	start = getCurrTime();
	fordJohnsonSort(deq);
	end = getCurrTime();
	dequeTime = end - start;
	size_t dequeComparisons = comparisons;
	std::cout << "Vector comparisons: " << vectorComparisons << std::endl;
	std::cout << "Deque comparisons: " << dequeComparisons << std::endl;
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
