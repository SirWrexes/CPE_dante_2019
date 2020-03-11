/*
** EPITECH PROJECT, 2019
** <Project_name>
** File description:
** [test_ft_revstr.c]--No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

char *ft_revstr(char *str);

Test(ft_revstr, test_ft_revstr_with_expected_result)
{
    char *nullstr = NULL;
    char s1[7] = {"543210"};
    char s2[2] = {"1"};
    char s3[2] = {""};

    cr_expect_str_eq(ft_revstr(s1), "012345", "F1T1");
    cr_expect_str_eq(ft_revstr(s2), "1", "F1T2");
    cr_expect_str_eq(ft_revstr(s3), "", "F1T3");
    cr_expect_null(ft_revstr(nullstr), "F1T4");
}
