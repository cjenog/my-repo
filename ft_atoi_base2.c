/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjenog <cjenog@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 20:37:15 by cjenog            #+#    #+#             */
/*   Updated: 2021/03/04 22:26:00 by cjenog           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_exception(char *str)
{
	int i;
	int j;

	while (str[0] == 0 || str[1] == 0)
		return (1);
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] <= 32 || str[i] == 127)
			return (1);
		j = i + 1;
		while (str[j] != 0)
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_numeral(char *str,char *base, int i)
{
	int c_to_o;
	int out;
	int j;

	c_to_o = 0;
	out = 0;
	while (str[i] != 0)
	{
		if (out)
			break;
		j = 0;
		while (base[j] != 0)
		{	
			out = 1;
			if (str[i] == base[j])
			{	c_to_o = (c_to_o * 10) + j;
				out = 0;
				break;
			}
			j++;				
		}
		i++;
	}
	return (c_to_o);
}

int	ft_len(char *ptr)
{
	int i;

	i = 0;
	while (ptr[i] != 0)
		i++;
	return (i);
}

int	ft_octa_to_decimal(int c_to_o, int len)
{
	int o_to_d;
	int weight;

	o_to_d = 0;
	weight = 1;
	while (c_to_o > 0)
	{
		o_to_d = o_to_d + ((c_to_o % 10) * weight);
		c_to_o /= 10;
		weight = weight * len;
	}
	return (o_to_d);
}

int	ft_atoi_base(char *str, char *base)
{
	int i;
	int sign;
	int len;
	int c_to_o;
	int o_to_d;

	if (ft_exception(str))
		return (0);
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >=9 && str[i] <=13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;	
	}
	c_to_o = ft_numeral(str, base, i);
	len = ft_len(base);
	o_to_d = ft_octa_to_decimal(c_to_o, len);
	return (o_to_d * sign);
}
