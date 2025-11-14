/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Workshop.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mteerlin <mteerlin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/03 13:16:55 by mteerlin      #+#    #+#                 */
/*   Updated: 2025/10/03 16:29:29 by mteerlin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORKSHOP_HPP
# define WORKSHOP_HPP

# include <set>
# include "Worker.hpp"

class Worker;

typedef enum eShopRequirements
{
	SR_NONE,
	SR_SHOVEL,
	SR_HAMMER,
	SR_BOTH
} tShopRequirements;

class Workshop
{
	private:
		std::set<Worker*> _workers;
		tShopRequirements _requirement;

		bool has_required_tools(Worker &worker);

	public:
		Workshop();
		Workshop(tShopRequirements requirement);
		~Workshop();

		void register_worker(Worker &worker);
		void ungegister_worker(Worker &worker);
};

#endif
