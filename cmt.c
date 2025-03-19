#include "cmt.h"

static void inner_print_common_msg(
	const char* func,
	const int line,
	const char* e_str,
	const char* operator_,
	const char* a_str)
{
	printf("[FAIL] %s Line=%d\n", func, line);
	printf("       expression: %s %s %s\n", e_str, operator_, a_str);
}

void inner_assert_eq(
	const bool success,
	const char* e_str,
	const char* a_str,
	const char* func,
	const int line)
{
	if (!success) {
		inner_print_common_msg(func, line, e_str, "==", a_str);
	}
}

void inner_assert_true(
	const bool a,
	const char* a_str,
	const char* func,
	const int line)
{
	if (!a) {
		inner_print_common_msg(func, line, a_str, "is", "true");
	}
}

void inner_assert_false(
	const bool a,
	const char* a_str,
	const char* func,
	const int line)
{
	if (a) {
		inner_print_common_msg(func, line, a_str, "is", "false");
	}
}

void inner_assert_str_eq(
	const char* e, const char* a,
	const char* e_str, const char* a_str,
	const char* func, const int line)
{
	if (!(strcmp(e, a) == 0)) {
		inner_print_common_msg(func, line, e_str, "==", a_str);
		printf("       expected  : %s\n", e);
		printf("       actual    : %s\n", a);
	}
}

static void print_int_msg(const int64_t e, const int64_t a) {
	printf("       expected  : %lld\n", e);
	printf("       actual    : %lld\n", a);
}

void inner_assert_int_eq(
	const int64_t e, const int64_t a,
	const char* e_str, const char* a_str,
	const char* func, const int line)
{
	if (e != a) {
		inner_print_common_msg(func, line, e_str, "< ", a_str);
		print_int_msg(e, a);
	}
}

void inner_assert_int_gt(
	const int64_t e, const int64_t a,
	const char* e_str, const char* a_str,
	const char* func, const int line)
{
	if (!(e < a)) {
		inner_print_common_msg(func, line, e_str, "< ", a_str);
		print_int_msg(e, a);
	}
}

void inner_assert_int_ge(
	const int64_t e, const int64_t a,
	const char* e_str, const char* a_str,
	const char* func, const int line)
{
	if (!(e <= a)) {
		inner_print_common_msg(func, line, e_str, "<=", a_str);
		print_int_msg(e, a);
	}
}

void inner_assert_int_lt(
	const int64_t e, const int64_t a,
	const char* e_str, const char* a_str,
	const char* func, const int line)
{
	if (!(e > a)) {
		inner_print_common_msg(func, line, e_str, "> ", a_str);
		print_int_msg(e, a);
	}
}

void inner_assert_int_le(
	const int64_t e, const int64_t a,
	const char* e_str, const char* a_str,
	const char* func, const int line)
{
	if (!(e >= a)) {
		inner_print_common_msg(func, line, e_str, "<=", a_str);
		print_int_msg(e, a);
	}
}

// unsigned int
static void print_uint_msg(const uint64_t e, const uint64_t a) {
	printf("       expected  : %llu\n", e);
	printf("       actual    : %llu\n", a);
}


void inner_assert_uint_gt(
	const uint64_t e, const uint64_t a,
	const char* e_str, const char* a_str,
	const char* func, const int line)
{
	if (!(e < a)) {
		inner_print_common_msg(func, line, e_str, "< ", a_str);
		print_uint_msg(e, a);
	}
}

void inner_assert_uint_ge(
	const uint64_t e, const uint64_t a,
	const char* e_str, const char* a_str,
	const char* func, const int line)
{
	if (!(e <= a)) {
		inner_print_common_msg(func, line, e_str, "<=", a_str);
	}
}

void inner_assert_uint_lt(
	const uint64_t e, const uint64_t a,
	const char* e_str, const char* a_str,
	const char* func, const int line)
{
	if (!(e > a)) {
		inner_print_common_msg(func, line, e_str, "> ", a_str);
	}
}

void inner_assert_uint_le(
	const uint64_t e, const uint64_t a,
	const char* e_str, const char* a_str,
	const char* func, const int line)
{
	if (!(e >= a)) {
		inner_print_common_msg(func, line, e_str, ">=", a_str);
	}
}

// double
static void print_double_msg(const double e, const double a) {
	printf("       expected  : %lf\n", e);
	printf("       actual    : %lf\n", a);
}

void inner_assert_double_eq(
	const double e, const double a,
	const char* e_str, const char* a_str,
	const char* func, const int line)
{
	bool r = fabs(e - a) <= DBL_EPSILON * fmax(1, fmax(fabs(e), fabs(a)));
	if (!r) {
		inner_assert_eq(r, e_str, a_str, func, line);
		print_double_msg(e, a);
	}
}

void inner_assert_double_gt(
	const double e, const double a,
	const char* e_str, const char* a_str,
	const char* func, const int line)
{
	if (!isgreater(a, e)) {
		inner_print_common_msg(func, line, e_str, "< ", a_str);
		print_double_msg(e, a);
	}
}

void inner_assert_double_ge(
	const double e, const double a,
	const char* e_str, const char* a_str,
	const char* func, const int line)
{
	if (!isgreaterequal(a, e)) {
		inner_print_common_msg(func, line, e_str, "<=", a_str);
		print_double_msg(e, a);
	}
}

void inner_assert_double_lt(
	const double e, const double a,
	const char* e_str, const char* a_str,
	const char* func, const int line)
{
	if (!isless(a, e)) {
		inner_print_common_msg(func, line, e_str, "> ", a_str);
		print_double_msg(e, a);
	}
}

void inner_assert_double_le(
	const double e, const double a,
	const char* e_str, const char* a_str,
	const char* func, const int line)
{
	if (!islessequal(a, e)) {
		inner_print_common_msg(func, line, e_str, ">=", a_str);
		print_double_msg(e, a);
	}
}
