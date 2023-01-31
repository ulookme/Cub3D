/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstupdate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chajjar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:53:22 by chajjar           #+#    #+#             */
/*   Updated: 2022/06/07 17:57:23 by chajjar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstupdate(t_list *lst, void (*del)(void *), void *new)
{
	if (!lst)
		return ;
	if (del && lst->content)
		del(lst->content);
	lst->content = new;
}
