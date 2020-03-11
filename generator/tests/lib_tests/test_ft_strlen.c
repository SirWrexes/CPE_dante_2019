/*
** EPITECH PROJECT, 2019
** <Project_name>
** File description:
** [test_ft_strlen.c]--No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
//#include "libft.h"

size_t ft_strlen(char const *str);

Test(ft_strlen, test_ft_strlen_with_real_strlen)
{
    cr_expect_eq(ft_strlen("1"), strlen("1"), "F1T1");
    cr_expect_eq(ft_strlen("12"), strlen("12"), "F1T2");
    cr_expect_eq(ft_strlen("123"), strlen("123"), "F1T3");
    cr_expect_eq(ft_strlen(""), strlen(""), "F1T4");
    cr_expect_eq(ft_strlen("1234567890"), strlen("1234567890"), "F1T5");
    cr_expect_eq(ft_strlen("0987654321"), strlen("1234567890"), "F1T8");
    cr_expect_eq(ft_strlen("ft_strlen"), strlen("my_strlen"), "F1T9");
    cr_expect_eq(ft_strlen("Luc, je sui"), strlen("s ton pere!"), "F1T10");
}
