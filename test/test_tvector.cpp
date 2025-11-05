#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
	TDynamicVector<int> v(10);

	ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> src(3);
	for (int i = 0; i < 3; i++)
		src[i] = i + 1;

	TDynamicVector<int> copy(src);

	for (int i = 0; i < 3; i++)
		EXPECT_EQ(src[i], copy[i]);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> src(3);
	for (int i = 0; i < 3; i++)
		src[i] = i + 1;

	TDynamicVector<int> copy(src);

	for (int i = 0; i < 3; i++)
		EXPECT_NE(&src[i], &copy[i]);
}

TEST(TDynamicVector, can_get_size)
{
	TDynamicVector<int> v(4);

	EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
	TDynamicVector<int> v(4);
	v[0] = 4;

	EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(4);

	ASSERT_ANY_THROW(v.at(-1) = 4);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(4);

	ASSERT_ANY_THROW(v.at(100) = 4);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> src(4);
	for (int i = 0; i < 4; i++)
		src[i] = i + 1;

	src = src;

	EXPECT_EQ(src.size(), 4);

	for (int i = 0; i < 4; i++)
		EXPECT_EQ(src[i], i + 1);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> src(4);
	for (int i = 0; i < 4; i++)
		src[i] = i + 1;

	TDynamicVector<int> src2(4);

	src2 = src;

	for (int i = 0; i < 4; i++)
		EXPECT_EQ(src2[i], src[i]);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> src(4);
	for (int i = 0; i < 4; i++)
		src[i] = i + 1;

	TDynamicVector<int> src2(6);

	src2 = src;

	EXPECT_EQ(src2.size(), 4);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> src(4);
	for (int i = 0; i < 4; i++)
		src[i] = i + 1;

	TDynamicVector<int> src2(6);

	src2 = src;

	for (int i = 0; i < 4; i++)
		EXPECT_EQ(src2[i], src[i]);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> src(4);
	for (int i = 0; i < 4; i++)
		src[i] = i + 1;

	TDynamicVector<int> src2(4);
	for (int i = 0; i < 4; i++)
		src2[i] = i + 1;

	for (int i = 0; i < 4; i++)
		EXPECT_EQ(src[i] == src2[i], true);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> src(4);
	for (int i = 0; i < 4; i++)
		src[i] = i + 1;

	for (int i = 0; i < 4; i++)
		EXPECT_EQ(src[i] == src[i], true);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> src(4);
	for (int i = 0; i < 4; i++)
		src[i] = i + 1;

	TDynamicVector<int> src2(6);
	for (int i = 0; i < 6; i++)
		src2[i] = i + 1;

	EXPECT_EQ(src != src2, true);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> src(4);
	for (int i = 0; i < 4; i++)
		src[i] = i + 1;

	TDynamicVector<int> res(4);

	res = src + 2;

	for (int i = 0; i < 4; i++)
		EXPECT_EQ(res[i], i + 3);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> src(4);
	for (int i = 0; i < 4; i++)
		src[i] = i + 1;

	TDynamicVector<int> res(4);

	res = src - 2;

	for (int i = 0; i < 4; i++)
		EXPECT_EQ(res[i], i - 1);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> src(4);
	for (int i = 0; i < 4; i++)
		src[i] = i + 1;

	TDynamicVector<int> res(4);

	res = src * 2;

	for (int i = 0; i < 4; i++)
		EXPECT_EQ(res[i], (i + 1) * 2);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> src(4);
	for (int i = 0; i < 4; i++)
		src[i] = i + 1;

	TDynamicVector<int> src2(4);
	for (int i = 0; i < 4; i++)
		src2[i] = i + 1;

	TDynamicVector<int> res(4);
	res = src + src2;

	for (int i = 0; i < 4; i++)
		EXPECT_EQ(res[i], (i + 1) * 2);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> src(4);
	for (int i = 0; i < 4; i++)
		src[i] = i + 1;

	TDynamicVector<int> src2(5);
	for (int i = 0; i < 5; i++)
		src2[i] = i + 3;

	ASSERT_ANY_THROW(src + src2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> src(4);
	for (int i = 0; i < 4; i++)
		src[i] = i + 1;

	TDynamicVector<int> src2(4);
	for (int i = 0; i < 4; i++)
		src2[i] = i + 2;

	TDynamicVector<int> res(4);
	res = src - src2;

	for (int i = 0; i < 4; i++)
		EXPECT_EQ(res[i], -1);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> src(4);
	for (int i = 0; i < 4; i++)
		src[i] = i + 1;

	TDynamicVector<int> src2(5);
	for (int i = 0; i < 5; i++)
		src2[i] = i + 3;

	ASSERT_ANY_THROW(src - src2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> src(4);
	for (int i = 0; i < 4; i++)
		src[i] = i + 1;

	TDynamicVector<int> src2(4);
	for (int i = 0; i < 4; i++)
		src2[i] = i + 1;

	int res = src * src2;
	EXPECT_EQ(res, 30);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> src(4);
	for (int i = 0; i < 4; i++)
		src[i] = i + 1;

	TDynamicVector<int> src2(5);
	for (int i = 0; i < 5; i++)
		src2[i] = i + 3;

	ASSERT_ANY_THROW(src * src2);
}

