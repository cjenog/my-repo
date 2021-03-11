/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjenog <cjenog@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 13:52:19 by cjenog            #+#    #+#             */
/*   Updated: 2021/03/11 15:55:11 by cjenog           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hex(unsigned char c)
{
	char hex_share;
	char hex_rest;

	hex_share = c / 16;
	hex_rest = c % 16;
	if (hex_share >= 10)
		hex_share = (hex_share - 10) + 'a';
	else
		hex_share += '0';
	if (hex_rest >= 10)
		hex_rest = (hex_rest - 10) + 'a';
	else
		hex_rest += '0';
	ft_putchar(hex_share);
	ft_putchar(hex_rest);
}

void	ft_print_line(unsigned char *addr_c, int size)
{
	int i;
	int print_sp;

	i = 0;
	while (i < size)
	{
		ft_hex(addr_c[i++]);
		if (i % 2 == 0)
			ft_putchar(' ');
	}
	print_sp = ((16 - size) * 2) + ((17 - size) / 2);
	while (print_sp--)
		ft_putchar(' ');
	i = -1;
	while (++i < size)
	{
		if (' ' <= addr_c[i] && addr_c[i] <= '~')
			ft_putchar(addr_c[i]);
		else
			ft_putchar('.');
	}
}

void	ft_print_addr(void *addr)
{
	unsigned char	addr_c[16];
	long			addr_l;
	int				i;

	addr_l = (long)addr;
	i = 0;
	while (addr_l > 0)
	{
		addr_c[i] = addr_l % 16;
		if (addr_c[i] >= 10)
			addr_c[i] = (addr_c[i] - 10) + 'a';
		else if (addr_c[i] < 10)
			addr_c[i] += '0';
		addr_l /= 16;
		i++;
	}
	while (i < 16)
	{
		addr_c[i] = '0';
		i++;
	}
	while (--i >= 0)
		ft_putchar(addr_c[i]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int char_to_print;
	int offset;

	offset = 0;
	while (size > 0)
	{
		if (size >= 16)
		{
			char_to_print = 16;
			size -= 16;
		}
		else
		{
			char_to_print = size;
			size = 0;
		}
		ft_print_addr(addr + offset);
		ft_putchar(':');
		ft_putchar(' ');
		ft_print_line(addr + offset, char_to_print);
		ft_putchar('\n');
		offset += 16;
	}
	return (addr);
}
