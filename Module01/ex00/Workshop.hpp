/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Workshop.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/03 13:16:55 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/11/14 16:17:57 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

# include <set>
# include "Worker.hpp"
# include "ToolTypes.h"

class Worker;

class Workshop
{
	private:
		std::set<Worker*> _workers;
		std::set<eToolTypes> _requirement;

		bool has_required_tools(Worker &worker);

	public:
		Workshop();
		Workshop(std::set<eToolTypes> requirement);
		~Workshop();

		void add_requirement(eToolTypes type);
		void remove_requirement(eToolTypes type);

		void register_worker(Worker &worker);
		void ungegister_worker(Worker &worker);

		void executeWorkDay();
};

#endif
