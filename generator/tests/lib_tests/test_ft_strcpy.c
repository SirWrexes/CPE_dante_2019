/*
** EPITECH PROJECT, 2019
** <Project_name>
** File description:
** [test_ft_strcat.c]--No description
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

char *ft_strcpy(char *src, char *dest);

Test(ft_strcpy, test_ft_strcpy_with_expected_result)
{
    char t1[10];
    cr_expect_str_eq(ft_strcpy("123456789", t1), "123456789", "T3");
    char t2[1];
    cr_expect_str_eq(ft_strcpy("", t2), "", "T2");
    char t3[3];
    cr_expect_str_eq(ft_strcpy("1", t3), "1", "T3");
    char t4[30];
    cr_expect_str_eq(ft_strcpy("12345", t4), "12345", "T4");
    char t5[10];
    cr_expect_null(ft_strcpy(NULL, t5), "T5");
}
