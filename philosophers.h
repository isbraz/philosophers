/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbraz-d <isbraz-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:50:25 by isbraz-d          #+#    #+#             */
/*   Updated: 2023/12/17 21:06:37 by isbraz-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

struct s_data;

typedef struct s_philo
{
	int				id;
	int				last_meal;
	pthread_t		ph;
	pthread_mutex_t	*own_fork;
	pthread_mutex_t	*next_fork;
	int				status;
	long			meals;
	pthread_mutex_t	meal_lock;
	struct s_data	*data;
}			t_philo;

typedef	struct s_data
{
	int				number_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	long			times_ate;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	mutex;
	int				dead;
	int				full;
	long			init_time;
	
}	t_data;

//init functions
int					ft_init_argvs(int ac,char **argv, t_data *data);
void				init_philo(t_philo *philo, t_data *data, int id);
void				init_forks(t_data *data);
void				init_mutexes(t_data *data);

//utils
long int			ft_atoi(const char *str);
int					ft_usleep(size_t time, t_philo *philo);
void				print_action(t_data *data, int id, char *action);
size_t				ft_get_time(t_data *data);
int					ft_time_without_eat(t_philo *philo);

//actions
void				ft_eat(t_philo *philo);
void				ft_sleep(t_philo *philo);
void				ft_think(t_philo *philo);
int					ft_dead(t_philo *philo);

//manage
int					is_philo_dead(t_philo *philo);
int					is_anyone_dead(t_data *data);
int					is_philo_satisfied(t_philo *philo);
int					is_everyone_satisfied(t_data *data);

//quit
void				destroy_mutex(t_data *data);
void				ft_unlock_forks(t_philo *philo);
void				ft_quit(t_data *data);

# endif