/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_nb_of_tokens_left_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:10:16 by kbrousse          #+#    #+#             */
/*   Updated: 2023/01/18 16:10:17 by kbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell_bonus.h"

/****************************************************************/
/*																*/
/*	Counts the number of tokens left in tokens's linked list	*/
/*																*/
/*	Parameters:													*/
/*		content	-	a linked list containing all the tokens		*/
/*																*/
/*	Return:														*/
/*		nb_toknes	-	the count								*/
/*																*/
/****************************************************************/

int	count_nb_of_tokens_left(t_token_ms *tokens)
{
	int	nb_tokens;

	nb_tokens = 0;
	while (tokens)
	{
		if (!tokens->content)
			return (nb_tokens);
		nb_tokens++;
		tokens = tokens->next;
	}
	return (nb_tokens);
}
