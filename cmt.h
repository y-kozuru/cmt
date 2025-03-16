// cmt.h -- C language Minimum Test library
#ifndef CMT_H
#define CMT_H

#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define assert_true(actual) \
inner_assert_true(actual, #actual, __func__, __LINE__)

#define assert_false(actual) \
inner_assert_false(actual, #actual, __func__, __LINE__)

// string
#define assert_string_equals(expected, actual) \
inner_assert_string_equals(expected, actual, #expected, #actual, __func__, __LINE__)

// int
#define assert_int_eq(expected, actual) assert_eq(expected, actual)
#define assert_int_gt(expected, actual) \
inner_assert_int_gt(expected, actual, #expected, #actual, __func__, __LINE__)

#define assert_int_ge(expected, actual) \
inner_assert_int_ge(expected, actual, #expected, #actual, __func__, __LINE__)

#define assert_int_lt(expected, actual) \
inner_assert_int_lt(expected, actual, #expected, #actual, __func__, __LINE__)

#define assert_int_le(expected, actual) \
inner_assert_int_le(expected, actual, #expected, #actual, __func__, __LINE__)

// uint_t
#define assert_uint_eq(expected, actual) assert_eq(expected, actual)
#define assert_uint_gt(expected, actual) \
inner_assert_uint_gt(expected, actual, #expected, #actual, __func__, __LINE__)

#define assert_uint_ge(expected, actual) \
inner_assert_uint_ge(expected, actual, #expected, #actual, __func__, __LINE__)

#define assert_uint_lt(expected, actual) \
inner_assert_uint_lt(expected, actual, #expected, #actual, __func__, __LINE__)

#define assert_uint_le(expected, actual) \
inner_assert_uint_le(expected, actual, #expected, #actual, __func__, __LINE__)

// double
#define assert_double_eq(expected, actual) \
inner_assert_double_eq(expected, actual, #expected, #actual, __func__, __LINE__)

#define assert_double_gt(expected, actual) \
inner_assert_double_gt(expected, actual, #expected, #actual, __func__, __LINE__)

#define assert_double_ge(expected, actual) \
inner_assert_double_ge(expected, actual, #expected, #actual, __func__, __LINE__)

#define assert_double_lt(expected, actual) \
inner_assert_double_lt(expected, actual, #expected, #actual, __func__, __LINE__)

#define assert_double_le(expected, actual) \
inner_assert_double_le(expected, actual, #expected, #actual, __func__, __LINE__)

#define assert_eq(expected, actual) \
inner_assert_eq(actual == expected, #expected, #actual, __func__, __LINE__)

inline void inner_print_assert_message(
	const char *funcname,
	const int line,
	const char *s1,
	const char *s2,
	const char *s3)
{
	printf("Failed: %s L%d: expected %s %s %s\n", funcname, line, s1, s2, s3);
}

inline void inner_assert_eq(
	const bool success,
	const char *expected,
	const char *actual,
	const char *funcname,
	const int line)
{
	if (!success) {
		inner_print_assert_message(funcname, line, actual, "==", expected);
	}
}

inline void inner_assert_true(
	const bool actual_bool,
	const char *actual,
	const char *funcname,
	const int line)
{
	if (!actual_bool) {
		inner_print_assert_message(funcname, line, actual, "is true", "");
	}
}

inline void inner_assert_false(
	const bool actual_bool,
	const char *actual,
	const char *funcname,
	const int line)
{
	if (actual_bool) {
		inner_print_assert_message(funcname, line, actual, "is false", "");
	}
}

inline void inner_assertNotNULL(
	const bool success,
	const char *actual,
	const char *funcname,
	const int line)
{
	if (!success) {
		inner_print_assert_message(funcname, line, actual, "not NULL", "");
	}
}

inline void inner_assert_string_equals(
	const char *e,
	const char *a,
	const char *expected,
	const char *actual,
	const char *funcname,
	const int line)
{
	const bool success = strcmp(a, e) == 0;
	inner_assert_eq(success, expected, actual, funcname, line);
}

inline void inner_assert_int_gt(
	const int64_t e,
	const int64_t a,
	const char *expected,
	const char *actual,
	const char *funcname,
	const int line)
{
	if (!(e < a)) {
		inner_print_assert_message(funcname, line, expected, "< ", actual);
	}
}

inline void inner_assert_int_ge(
	const int64_t e,
	const int64_t a,
	const char *expected,
	const char *actual,
	const char *funcname,
	const int line)
{
	if (!(e <= a)) {
		inner_print_assert_message(funcname, line, expected, "<=", actual);
	}
}

inline void inner_assert_int_lt(
	const int64_t e,
	const int64_t a,
	const char *expected,
	const char *actual,
	const char *funcname,
	const int line)
{
	if (!(e > a)) {
		inner_print_assert_message(funcname, line, expected, "> ", actual);
	}
}

inline void inner_assert_int_le(
	const int64_t e,
	const int64_t a,
	const char *expected,
	const char *actual,
	const char *funcname,
	const int line)
{
	if (!(e >= a)) {
		inner_print_assert_message(funcname, line, expected, "<=", actual);
	}
}

// uint
inline void inner_assert_uint_gt(
	const uint64_t e,
	const uint64_t a,
	const char *expected,
	const char *actual,
	const char *funcname,
	const int line)
{
	if (!(e < a)) {
		inner_print_assert_message(funcname, line, expected, "< ", actual);
	}
}

inline void inner_assert_uint_ge(
	const uint64_t e,
	const uint64_t a,
	const char *expected,
	const char *actual,
	const char *funcname,
	const int line)
{
	if (!(e <= a)) {
		inner_print_assert_message(funcname, line, expected, "<=", actual);
	}
}

inline void inner_assert_uint_lt(
	const uint64_t e,
	const uint64_t a,
	const char *expected,
	const char *actual,
	const char *funcname,
	const int line)
{
	if (!(e > a)) {
		inner_print_assert_message(funcname, line, expected, "> ", actual);
	}
}

inline void inner_assert_uint_le(
	const uint64_t e,
	const uint64_t a,
	const char *expected,
	const char *actual,
	const char *funcname,
	const int line)
{
	if (!(e >= a)) {
		inner_print_assert_message(funcname, line, expected, ">=", actual);
	}
}

// double
inline void inner_assert_double_eq(
	const double e,
	const double a,
	const char *expected,
	const char *actual,
	const char *funcname,
	const int line)
{
	const bool success = fabs(e - a) <= DBL_EPSILON * fmax(1, fmax(fabs(e), fabs(a)));
	inner_assert_eq(success, expected, actual, funcname, line);
}

inline void inner_assert_double_gt(
	const double e,
	const double a,
	const char *expected,
	const char *actual,
	const char *funcname,
	const int line)
{
	if (!isgreater(a, e)) {
		inner_print_assert_message(funcname, line, expected, "< ", actual);
	}
}

inline void inner_assert_double_ge(
	const double e,
	const double a,
	const char *expected,
	const char *actual,
	const char *funcname,
	const int line)
{
	if (!isgreaterequal(a, e)) {
		inner_print_assert_message(funcname, line, expected, "<=", actual);
	}
}

inline void inner_assert_double_lt(
	const double e,
	const double a,
	const char *expected,
	const char *actual,
	const char *funcname,
	const int line)
{
	if (!isless(a, e)) {
		inner_print_assert_message(funcname, line, expected, "> ", actual);
	}
}

inline void inner_assert_double_le(
	const double e,
	const double a,
	const char *expected,
	const char *actual,
	const char *funcname,
	const int line)
{
	if (!islessequal(a, e)) {
		inner_print_assert_message(funcname, line, expected, ">=", actual);
	}
}

#endif // CMT_H

#ifdef COMPILE_AS_TEST

void test_assert_true(void) {
	assert_true(3 == 3);
	assert_true(false); // fail
}

void test_assert_false(void) {
	assert_false(3 == 3); // fail
	assert_false(false);
}

void test_assert_string_equals(void) {
	assert_string_equals("abc", "abc");
	assert_string_equals("abc", "def"); // fail
}

void test_assert_int(void) {
	int x = 3;
	int y = 4;
	assert_int_eq(3, x);
	assert_int_eq(y, x); // fail
	assert_int_gt(2, x);
	assert_int_gt(3, x); // fail
	assert_int_ge(3, x);
	assert_int_ge(4, x); // fail
	assert_int_lt(3, x); // fail
	assert_int_lt(4, x);
	assert_int_le(2, x); // fail
	assert_int_le(3, x);
}

int main(void) {
	test_assert_true();
	test_assert_false();
	test_assert_string_equals();
	test_assert_int();
	return 0;
}

#endif // COMPILE_AS_TEST
