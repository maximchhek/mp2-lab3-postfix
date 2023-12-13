#include "postfix.h"
#include <gtest.h>

TEST(TPostfix, check_staples_true)
{
    string a = "2+3-(4/5)-1";
    TPostfix p(a);
    ASSERT_NO_THROW(p.isCorrectStaples());
}

TEST(TPostfix, check_correct_infix_true)
{
    string a = "2+3-(4/5)-1";
    TPostfix p(a);
    ASSERT_NO_THROW(p.isCorrect());
}

TEST(TPostfix, can_create_elem_from_true_infix_str)
{
    string a = "2+3-(4/5)-1";

    ASSERT_NO_THROW(TPostfix p(a));
}

TEST(TPostfix, cant_create_elem_from_false_infix_str)
{
    string a = "2+3-*(4/5)-1";

    ASSERT_ANY_THROW(TPostfix p(a));
}

TEST(TPostfix, cant_create_elem_from_false_staples)
{
    string a = "2+3-)(4/5)-1";

    ASSERT_ANY_THROW(TPostfix p(a));
}

TEST(TPostfix, can_create_postfix)
{
  TPostfix p("1+1");
  ASSERT_NO_THROW(p.ToPostfix());
}

TEST(TPostfix, can_get_infix)
{
    string a = "6+(9*5)";
    string b;
    TPostfix post(a);
    b = post.GetInfix();
    EXPECT_EQ(a, b);
}
TEST(TPostfix, can_set_infix)
{
    string a = "6+(9*5)";
    string b;
    TPostfix post(a);
    ASSERT_NO_THROW(post.SetInfix(b));
    EXPECT_EQ(post.GetInfix(), b);
}
TEST(TPostfix, can_get_correct_postfix_form_of_elem_if_the_number_of_staples_is_correct)
{
    string a = "6+(9*5)";
    string b = "695*+";
    string c;
    TPostfix post(a);
    ASSERT_NO_THROW(c = post.ToPostfix());
    EXPECT_EQ(c, b);
}

TEST(TPostfix, check_expression_return_true_when_the_number_of_staples_is_correct)
{
    string a = "2+(3*5)";
    TPostfix post(a);
    bool Check;
    Check = post.isCorrect();
    EXPECT_EQ(1, Check);
}

TEST(TPostfix, can_calculat)
{
    string a = "2+3-(1*2)+6";

    TPostfix post(a);
    post.ToPostfix();
    int Check;
    ASSERT_NO_THROW(Check = post.Calculate());
    EXPECT_EQ(9, Check);
}