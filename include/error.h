/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 04:16:29 by nthimoni          #+#    #+#             */
/*   Updated: 2022/01/13 00:14:40 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

int	error_msg(int code);

# define INV_ARG -1
# define BAD_ALLOC -2
# define MAP_FORMAT -3

#endif
