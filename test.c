#include "cmt.h"

void test_assert_true(void) {
	cmt_assert_true(3 == 3);
	cmt_assert_true(false); // fail
}

void test_assert_false(void) {
	cmt_assert_false(3 == 3); // fail
	cmt_assert_false(false);
}

void test_assert_string_eq(void) {
	const char str[] = "abc";
	cmt_assert_str_eq("abc", str);
	cmt_assert_str_eq("def", str); // fail
}

void test_assert_int(void) {
	int x = 3;
	int y = 4;
	cmt_assert_int_eq(3, x);
	cmt_assert_int_eq(y, x); // fail
	cmt_assert_int_gt(2, x);
	cmt_assert_int_gt(3, x); // fail
	cmt_assert_int_ge(3, x);
	cmt_assert_int_ge(4, x); // fail
	cmt_assert_int_lt(3, x); // fail
	cmt_assert_int_lt(4, x);
	cmt_assert_int_le(2, x); // fail
	cmt_assert_int_le(3, x);
}

int main(void) {
	test_assert_true();
	test_assert_false();
	test_assert_string_eq();
	test_assert_int();
	return 0;
}
