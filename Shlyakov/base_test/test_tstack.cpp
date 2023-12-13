#include "stack.h"
#include <gtest.h>

TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> ts(3));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> m(-5));
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> m(5);

	ASSERT_NO_THROW(TStack<int> m1(m));
}

TEST(TStack, can_set_and_get_element)
{
	TStack<int> m(5);
	ASSERT_NO_THROW(m.Push(1));
	EXPECT_EQ(m.Pop(), 1);
}


TEST(Tstack, new_stack_is_empty)
{
	TStack<int> s(3);

	EXPECT_EQ(1, s.IsEmpty());
}


TEST(Tstack, throws_when_use_pop_for_empty_stack)
{
	TStack<int> s(3);
	ASSERT_ANY_THROW(s.Pop());
}

TEST(Tstack, throws_when_use_push_to_overflow_stack)
{
	TStack<int> s(2);
	s.Push(1);
	s.Push(1);
	ASSERT_ANY_THROW(s.Push(1));
}

TEST(Tstack, throws_when_top_for_empty_stack)
{
	TStack<int> s(3);

	ASSERT_ANY_THROW(s.Check());
}

TEST(Tstack, return_true_when_full_stack)
{
	TStack<int> s(3);
	for (int i = 0; i < 3; i++)
		s.Push(i);

	EXPECT_EQ(1, s.IsFull());
}
TEST(Tstack, return_false_when_not_full_stack)
{
	TStack<int> s(3);
	EXPECT_EQ(0, s.IsFull());
}
TEST(Tstack, return_true_when_empty_stack)
{
	TStack<int> s(3);
	EXPECT_EQ(1, s.IsEmpty());
}
TEST(Tstack, return_false_when_not_empty_stack)
{
	TStack<int> s(3);
	s.Push(1);
	EXPECT_EQ(0, s.IsEmpty());
}
