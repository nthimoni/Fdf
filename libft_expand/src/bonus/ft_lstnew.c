/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:06:56 by nthimoni          #+#    #+#             */
/*   Updated: 2021/11/25 14:14:58 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*frst;

	frst = malloc(sizeof(t_list));
	if (!frst)
		return (NULL);
	frst->content = content;
	frst->next = NULL;
	return (frst);
}
