/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 00:00:00 by yitani            #+#    #+#             */
/*   Updated: 2025/09/11 12:34:34 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include <iostream>

struct Data
{
	int			id;
	std::string	name;

	Data();
	Data(int id, const std::string& name);

	void		display(void) const;
};

#endif