/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_first_token.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:53:37 by kbrousse          #+#    #+#             */
/*   Updated: 2023/01/18 23:28:21 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_syntax_first_token(t_token_ms *tokens, t_env_ms *env_ll)
{
	t_token_ms	*cursor;

	cursor = tokens;
	if (cursor->type == TOK_PIPE)
	{
		print_checking_error_msg(cursor->content);
		set_exit_code(env_ll, 2);
		return (-1);
	}
	return (0);
}
