/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yongmiki <yongmiki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:21:16 by yongmiki          #+#    #+#             */
/*   Updated: 2022/04/03 18:33:02 by yongmiki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static void	init_vars(t_philo *philo, t_rules *rules)
{
	philo->id = rules->philo_id;
	philo->meals = 0;
	philo->forks = 0;
	philo->dead = false;
	rules->start = get_time();
	rules->created++;
	pthread_mutex_unlock(&rules->mutex);
	while (rules->created != rules->philos)
		continue ;
	pthread_mutex_lock(&rules->mutex);
	philo->start = rules->start;
	philo->last_meal = rules->start;
	pthread_mutex_unlock(&rules->mutex);
}

static void	*philosopher(void *arg)
{
	t_rules			*rules;
	t_philo			*philo;

	rules = (t_rules *)arg;
	pthread_mutex_lock(&rules->mutex);
	philo = malloc(sizeof(t_philo));
	if (philo == NULL)
	{
		ft_exit("allocation error!");
		return (NULL);
	}
	init_vars(philo, rules);
	routine(rules, philo);
	free(philo);
	return (NULL);
}

static bool	create_philos(t_rules *rules, pthread_t *id)
{
	int	i;
	int	error;

	i = 0;
	while (i < rules->philos)
	{
		rules->philo_id = i + 1;
		error = pthread_create(&id[i], NULL, philosopher, rules);
		if (error != 0)
			return (false);
		i++;
		usleep(5000);
	}
	i = 0;
	while (i < rules->philos)
	{
		pthread_join(id[i], NULL);
		i++;
	}
	return (true);
}

static void	free_exit(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->philos)
	{
		if (rules->forks->locked[i] == true)
			pthread_mutex_unlock(&rules->forks->forks[i]);
		pthread_mutex_destroy(&rules->forks->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&rules->mutex);
	free(rules->forks->forks);
	free(rules->forks->locked);
	free(rules->forks);
	free(rules);
}

int	main(int argc, char **argv)
{
	t_rules		*rules;
	pthread_t	*id;

	if (argc != 5 && argc != 6)
		return (print_help());
	if (check(argv, argc) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	rules = read_input(argc, argv);
	if (rules == NULL)
		return (EXIT_FAILURE);
	id = malloc(rules->philos * sizeof(pthread_t));
	if (id == NULL)
		return (ft_exit("allocation error!"));
	if (create_philos(rules, id) == false)
		return (ft_exit("Error while creating a thread\n"));
	free_exit(rules);
	return (EXIT_SUCCESS);
}
