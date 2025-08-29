/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Tool.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/08/29 15:25:46 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/08/29 16:21:11 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOL_HPP
# define TOOL_HPP
# include "Worker.hpp"

class Worker;

class Tool
{
	protected:
		Worker*		_heldBy;
		std::string	_type;
		int			_numberOfUses;
		
		public:
		Tool();
		virtual ~Tool();

		std::string get_type();

		void picked_up(Worker &worker);
		virtual int use() = 0;
};

#endif
