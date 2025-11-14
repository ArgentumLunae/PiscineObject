/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Hammer.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/29 16:17:02 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/10/03 16:09:45 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef HAMMER_HPP
# define HAMMER_HPP

# include "Tool.hpp"

class Hammer : public Tool
{
	public:
		Hammer();
		~Hammer();

		int use();
};

#endif