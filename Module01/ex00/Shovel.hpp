/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Shovel.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/08 14:58:27 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/08/29 16:17:22 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOVEL_HPP
# define SHOVEL_HPP

# include "Tool.hpp"

class Shovel : public Tool
{
	public:
		Shovel();
		~Shovel();

		int use();
};

#endif
