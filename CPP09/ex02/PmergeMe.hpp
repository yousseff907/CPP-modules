/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:40:43 by yitani            #+#    #+#             */
/*   Updated: 2026/01/23 22:09:21 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <stdexcept>
# include <limits.h>
# include <sys/time.h>
# include <cstdlib>

class PmergeMe
{
	private:
		std::vector<int>	inputNumbers;
		std::vector<int>	vect;
		std::deque<int>		deq;
		double vectorTime;
		double dequeTime;
		size_t	comparisons;
		double	getCurrTime();

	private:
		template<typename Container>
		void	binaryInsert(Container& container, int value, size_t maxPos);

		void	fordJohnsonSort(std::vector<int> &container);
		void	fordJohnsonSort(std::deque<int>	&container);

		std::vector<size_t>		generateJacobsthal(size_t n);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe	&operator=(const PmergeMe &other);
		~PmergeMe();

		void	parseInput(int argc, char **argv);
		void	sort(void);
		void	displayResults(void);
};

#endif