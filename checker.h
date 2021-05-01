/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmellahi <hmellahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 15:49:21 by hmellahi          #+#    #+#             */
/*   Updated: 2021/05/01 17:36:21 by hmellahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"
#include "stack.h"
#include "double_linked_list.h"
#include <unistd.h>
#define FALSE 0
#define TRUE 1
#define ERROR 1
#define COMPLETED 2
#define NONE 3

int		ft_strlen(char *str);

typedef char* t_string;