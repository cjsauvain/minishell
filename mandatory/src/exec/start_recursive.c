/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_recursive.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbrousse <kbrousse@student.42angoulem      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:43:20 by kbrousse          #+#    #+#             */
/*   Updated: 2023/01/18 23:45:28 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	transfer_pipe_content(int *pipe_before, int *pipe_after)
{
	close(pipe_before[0]);
	close(pipe_before[1]);
	pipe_before[0] = dup(pipe_after[0]);
	pipe_before[1] = dup(pipe_after[1]);
	close(pipe_after[0]);
	close(pipe_after[1]);
	if (pipe(pipe_after) == -1)
	{
		ft_putstr_fd("Pipe_after's creation failed\n", 2);
		return (-1);
	}
	return (0);
}

/****************************************************************/
/*																*/
/*	Travels through the binary tree and do different things		*/
/*		depending on the type of node it meets					*/
/*																*/
/*	Parameters:													*/
/*		pipes		-	structure containing the two pipes		*/
/*		children	-	structure containing the fork-linked	*/
/*						variables								*/
/*		root		-	root of the binary tree					*/
/*		env_ll		-	linked list of the env_variables		*/
/*																*/
/*	Return:														*/
/*		 0	-	accomplished its duty							*/
/*		-2	-	the execution must stop but not close the		*/
/*				program											*/
/*																*/
/****************************************************************/

int	start_recursive(t_pipes_ms *pipes, t_children_ms *children,
	t_node_ms *root, t_env_ms *env_ll)
{
	int	ret;

	ret = 0;
	if (root && root->left != NULL)
		start_recursive(pipes, children, root->left, env_ll);
	if (root->operator == TOK_PIPE)
		transfer_pipe_content(pipes->before, pipes->after);
	else
	{
		ret = execute_cmd(pipes, children, root, &env_ll);
		if (ret == -1 || ret == 130)
			return (ret);
	}
	if (root && root->right != NULL)
		start_recursive(pipes, children, root->right, env_ll);
	return (0);
}