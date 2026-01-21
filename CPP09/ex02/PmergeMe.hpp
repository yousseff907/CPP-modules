/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:40:43 by yitani            #+#    #+#             */
/*   Updated: 2026/01/21 13:03:27 by yitani           ###   ########.fr       */
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

class PmergeMe
{
	private:
		std::vector<int>	inputNumbers;
		std::vector<int>	vect;
		std::deque<int>		deq;
		double vectorTime;
		double dequeTime;

		void	fordJohnsonSort(std::vector<int> vect);
		void	fordJohnsonSort(std::deque<int> deq);
		double	getCurrTime();

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