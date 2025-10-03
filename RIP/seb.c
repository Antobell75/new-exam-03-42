/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 16:39:02 by rcini-ha          #+#    #+#             */
/*   Updated: 2025/08/18 14:39:23 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	count(char *str) {
	int bracket_level = 0;
	int jspnsm = 0;

	for (int k = 0; str[k]; ++k) {
		if (str[k] == '(')
			bracket_level++;
		else if (str[k] == ')') {
			if (bracket_level < 1) {
				jspnsm++;
			} else {
				bracket_level--;
			}
		}
	}
	return (jspnsm + bracket_level);
}
int tes(char *str)
 {
	int k = 0 ;
	for(int i = 0;str[i];i++)
	{
		if(str[i] == '_')
			k++;
	}
	return k;
 }
void	riprec(char *str, int i, int left_to_rm) {
	char temp;

	if (!str[i]) {
		if (!count(str) && tes(str) == left_to_rm && !str[i])
			printf("%s\n", str);
		return ;
	}
	temp = str[i];
	riprec(str, i + 1, left_to_rm);
	str[i] = '_';
	riprec(str, i + 1, left_to_rm);
	str[i] = temp;
}

int	main(int argc, char **argv) {

	riprec(argv[1], 0, count(argv[1]));


}
