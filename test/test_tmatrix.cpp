#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
	TDynamicMatrix<int> m(5);

	ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> src(2);
	int cnt = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src[i][j] = cnt++;
		}
	}

	TDynamicMatrix<int> copy = src;

	EXPECT_EQ(src[0].size(), copy[0].size());

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			EXPECT_EQ(src[i][j], copy[i][j]);
		}
	}
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> src(2);
	int cnt = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src[i][j] = cnt++;
		}
	}

	TDynamicMatrix<int> copy = src;

	for (int i = 0; i < 2; i++) {
		EXPECT_NE(&src[i], &copy[i]);
	}
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> src(2);
	int cnt = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src[i][j] = cnt++;
		}
	}

	EXPECT_EQ(2, src[0].size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> src(2);
	src[0][1] = 2;
	EXPECT_EQ(src[0][1], 2);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> src(2);

	ASSERT_ANY_THROW(src[0].at(-1));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> src(2);

	ASSERT_ANY_THROW(src[0].at(3));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> src(2);
	int cnt = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src[i][j] = cnt++;
		}
	}

	src = src;

	EXPECT_EQ(src[0].size(), 2);

	cnt = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			EXPECT_EQ(src[i][j], cnt++);
		}
	}
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> src(2);
	int cnt = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src[i][j] = cnt++;
		}
	}

	TDynamicMatrix<int> src2(2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src2[i][j] = cnt++;
		}
	}

	src2 = src;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			EXPECT_EQ(src[i][j], src2[i][j]);
		}
	}
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> src(2);
	int cnt = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src[i][j] = cnt++;
		}
	}

	TDynamicMatrix<int> src2(5);

	src2 = src;
	EXPECT_EQ(2, src2[0].size());
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> src(2);
	int cnt = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src[i][j] = cnt++;
		}
	}

	TDynamicMatrix<int> src2(5);

	src2 = src;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			EXPECT_NE(0, src2[i][j]);
		}
	}
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> src(2);
	int cnt = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src[i][j] = cnt++;
		}
	}
	cnt = 1;
	TDynamicMatrix<int> src2(2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src2[i][j] = cnt++;
		}
	}

	EXPECT_EQ(src == src2, true);
}
TEST(TDynamicMatrix, compare_equal_matrices_return_false)
{
	TDynamicMatrix<int> src(2);
	int cnt = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src[i][j] = cnt++;
		}
	}
	cnt = 2;
	TDynamicMatrix<int> src2(2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src2[i][j] = cnt++;
		}
	}

	EXPECT_EQ(src == src2,false);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> src(2);
	int cnt = 1;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			src[i][j] = cnt++;

	EXPECT_EQ(true, src == src);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> src(2);
	int cnt = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src[i][j] = cnt++;
		}
	}
	cnt = 1;
	TDynamicMatrix<int> src2(5);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			src2[i][j] = cnt++;
		}
	}

	EXPECT_EQ(src == src2, false);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> src(2);
	int cnt = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src[i][j] = cnt++;
		}
	}
	TDynamicMatrix<int> src2(2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src2[i][j] = cnt++;
		}
	}
	TDynamicMatrix<int> res = src + src2;
	cnt = 6;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
			EXPECT_EQ(cnt, res[i][j]);
			cnt += 2;
		}
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> src(2);
	int cnt = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src[i][j] = cnt++;
		}
	}
	TDynamicMatrix<int> src2(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			src2[i][j] = cnt++;
		}
	}

	ASSERT_ANY_THROW(src + src2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> src(2);
	int cnt = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src[i][j] = cnt++;
		}
	}
	TDynamicMatrix<int> src2(2);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src2[i][j] = cnt++;
		}
	}
	TDynamicMatrix<int> res = src - src2;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
			EXPECT_EQ(-4, res[i][j]);
		}
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> src(2);
	int cnt = 1;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			src[i][j] = cnt++;
		}
	}
	TDynamicMatrix<int> src2(3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			src2[i][j] = cnt++;
		}
	}

	ASSERT_ANY_THROW(src - src2);
}

