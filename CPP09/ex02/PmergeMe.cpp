/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:40:27 by yitani            #+#    #+#             */
/*   Updated: 2026/01/23 12:37:07 by yitani           ###   ########.fr       */
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

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
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
{
}

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

std::vector<size_t> PmergeMe::generateJacobsthal(size_t n)
{
	std::vector<size_t> jacobsthal;
	if (n == 0)
		return jacobsthal;

	jacobsthal.push_back(0);
	if (n == 1)
		return jacobsthal;

	jacobsthal.push_back(1);
	while (jacobsthal.back() < n)
	{
		size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

template <typename Container>
void PmergeMe::binaryInsert(Container &container, int value, size_t maxPos)
{
	size_t left = 0;
	size_t right = maxPos;

	while (left < right)
	{
		size_t mid = left + (right - left) / 2;

		comparisons++;
		if (container[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}

	container.insert(container.begin() + left, value);
}

template <typename Container>
size_t findPositionInContainer(Container &container, int value)
{
	for (size_t i = 0; i < container.size(); i++)
	{
		if (container[i] == value)
			return i;
	}
	return container.size();
}

template <typename Container>
void PmergeMe::fordJohnsonSort(Container &container)
{
	if (container.size() <= 1)
		return;

	int straggler = -1;
	bool hasStraggler = false;

	if (container.size() % 2 != 0)
	{
		straggler = container.back();
		hasStraggler = true;
		container.pop_back();
	}

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < container.size(); i += 2)
	{
		int a = container[i];
		int b = container[i + 1];

		comparisons++;
		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	std::vector<int> mainChain;
	for (size_t i = 0; i < pairs.size(); i++)
	{
		mainChain.push_back(pairs[i].first);
	}

	fordJohnsonSort(mainChain);

	std::vector<int> sortedLosers;
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

	if (hasStraggler)
		sortedLosers.push_back(straggler);

	container.clear();
	container.push_back(sortedLosers[0]);
	for (size_t i = 0; i < mainChain.size(); i++)
		container.push_back(mainChain[i]);
	std::vector<size_t> jacobSequence = generateJacobsthal(sortedLosers.size());
	std::vector<size_t> insertionOrder;
	std::vector<bool> used(sortedLosers.size() + 1, false);

	for (size_t i = 0; i < jacobSequence.size(); i++)
	{
		size_t x = jacobSequence[i];
		while (x > 1 && x <= sortedLosers.size())
		{
			if (!used[x])
			{
				insertionOrder.push_back(x);
				used[x] = true;
			}
			x--;
		}
	}

	for (size_t x = 2; x <= sortedLosers.size(); x++)
	{
		if (!used[x])
			insertionOrder.push_back(x);
	}

	size_t searchLimit = 3;

	for (size_t i = 0; i < insertionOrder.size(); i++)
	{
		if (i > 0 && insertionOrder[i] > insertionOrder[i - 1])
		{
			if (searchLimit <= container.size() / 2)
				searchLimit = 2 * searchLimit + 1;
			else
				searchLimit = container.size();
		}

		if (insertionOrder[i] <= sortedLosers.size() && insertionOrder[i] != 1)
		{
			size_t pendIndex = insertionOrder[i] - 1;
			size_t maxSearchPos = std::min(searchLimit, container.size());
			if (maxSearchPos > container.size())
				maxSearchPos = container.size();
			binaryInsert(container, sortedLosers[pendIndex], maxSearchPos);
		}
	}
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

template <typename Iterator>
bool isSorted(Iterator begin, Iterator end)
{
	if (begin == end)
		return true;

	Iterator next = begin;
	++next;

	while (next != end)
	{
		if (*next < *begin)
			return false;
		++begin;
		++next;
	}
	return true;
}

void PmergeMe::displayResults(void)
{
	long long size = inputNumbers.size();
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
	if (isSorted(vect.begin(), vect.end()))
		std::cout << "Vector is sorted! ✓" << std::endl;
	else
		std::cout << "Vector is NOT sorted! ✗" << std::endl;

	if (isSorted(deq.begin(), deq.end()))
		std::cout << "Deque is sorted! ✓" << std::endl;
	else
		std::cout << "Deque is NOT sorted! ✗" << std::endl;
}
