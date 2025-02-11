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

#define assertTrue(actual) \
inner_assertTrue(actual, #actual, __func__, __LINE__)

#define assertFalse(actual) \
inner_assertFalse(actual, #actual, __func__, __LINE__)

#define assertNotNULL(actual) \
inner_assertNotNULL(actual, #actual, __func__, __LINE__)

// string
#define assertStringEquals(actual, expected) \
inner_assertStringEquals(actual, expected, #actual, #expected, __func__, __LINE__)

// int
#define assertIntEquals(actual, expected) assertEquals(actual, expected)
#define assertIntGreaterThan(actual, expected) \
inner_assertIntGraterThan(actual, expected, #actual, #expected, __func__, __LINE__)

#define assertIntGreaterThanOrEquals(actual, expected) \
inner_assertIntGraterThanOrEquals(actual, expected, #actual, #expected, __func__, __LINE__)

#define assertIntLessThan(actual, expected) \
inner_assertIntLessThan(actual, expected, #actual, #expected, __func__, __LINE__)

#define assertIntLessThanOrEquals(actual, expected) \
inner_assertIntLessThanOrEquals(actual, expected, #actual, #expected, __func__, __LINE__)

// uint_t
#define assertUIntEquals(actual, expected) assertEquals(actual, expected)
#define assertUIntGreaterThan(actual, expected) \
inner_assertUIntGraterThan(actual, expected, #actual, #expected, __func__, __LINE__)

#define assertUIntGreaterThanOrEquals(actual, expected) \
inner_assertUIntGraterThanOrEquals(actual, expected, #actual, #expected, __func__, __LINE__)

#define assertUIntLessThan(actual, expected) \
inner_assertUIntLessThan(actual, expected, #actual, #expected, __func__, __LINE__)

#define assertUIntLessThanOrEquals(actual, expected) \
inner_assertUIntLessThanOrEquals(actual, expected, #actual, #expected, __func__, __LINE__)

// double
#define assertDoubleEquals(actual, expected) \
inner_assertDoubleEquals(actual, expected, #expected, #actual, __func__, __LINE__)

#define assertDoubleGreaterThan(actual, expected) \
inner_assertDoubleGraterThan(actual, expected, #actual, #expected, __func__, __LINE__)

#define assertDoubleGreaterThanOrEquals(actual, expected) \
inner_assertDoubleGraterThanOrEquals(actual, expected, #actual, #expected, __func__, __LINE__)

#define assertDoubleLessThan(actual, expected) \
inner_assertDoubleLessThan(actual, expected, #actual, #expected, __func__, __LINE__)

#define assertDoubleLessThanOrEquals(actual, expected) \
inner_assertDoubleLessThanOrEquals(actual, expected, #actual, #expected, __func__, __LINE__)

#define assertEquals(actual, expected) \
inner_assertEquals(actual == expected, #actual, #expected, __func__, __LINE__)

inline void inner_printAssertMessage(
	const char *funcName,
	int lineNo,
	const char *s1,
	const char *s2,
	const char *s3)
{
	printf("Failed: %s L%d: expected %s %s %s\n", funcName, lineNo, s1, s2, s3);
}

inline void inner_assertEquals(
	const bool success,
	const char *actual,
	const char *expected,
	const char *funcName,
	int lineNo)
{
	if (!success) {
		inner_printAssertMessage(funcName, lineNo, actual, "==", expected);
	}
}

inline void inner_assertTrue(
	const bool actual_as_bool,
	const char *actual,
	const char *funcName,
	int lineNo)
{
	if (!actual_as_bool) {
		inner_printAssertMessage(funcName, lineNo, actual, "is true", "");
	}
}

inline void inner_assertFalse(
	const bool actual_as_bool,
	const char *actual,
	const char *funcName,
	int lineNo)
{
	if (actual_as_bool) {
		inner_printAssertMessage(funcName, lineNo, actual, "is false", "");
	}
}

inline void inner_assertNotNULL(
	const bool success,
	const char *actual,
	const char *funcName,
	int lineNo)
{
	if (!success) {
		inner_printAssertMessage(funcName, lineNo, actual, "not NULL", "");
	}
}

inline void inner_assertStringEquals(
	const char *a,
	const char *e,
	const char *actual,
	const char *expected,
	const char *funcName,
	int lineNo)
{
	const bool success = strcmp(a, e) == 0;
	inner_assertEquals(success, actual, expected, funcName, lineNo);
}

inline void inner_assertIntGraterThan(
	const int64_t a,
	const int64_t e,
	const char *actual,
	const char *expected,
	const char *funcName,
	int lineNo)
{
	if (!(a > e)) {
		inner_printAssertMessage(funcName, lineNo, actual, "> ", expected);
	}
}

inline void inner_assertIntGraterThanOrEquals(
	const int64_t a,
	const int64_t e,
	const char *actual,
	const char *expected,
	const char *funcName,
	int lineNo)
{
	if (!(a >= e)) {
		inner_printAssertMessage(funcName, lineNo, actual, ">=", expected);
	}
}

inline void inner_assertIntLessThan(
	const int64_t a,
	const int64_t e,
	const char *actual,
	const char *expected,
	const char *funcName,
	int lineNo)
{
	if (!(a < e)) {
		inner_printAssertMessage(funcName, lineNo, actual, "< ", expected);
	}
}

inline void inner_assertIntLessThanOrEquals(
	const int64_t a,
	const int64_t e,
	const char *actual,
	const char *expected,
	const char *funcName,
	int lineNo)
{
	if (!(a <= e)) {
		inner_printAssertMessage(funcName, lineNo, actual, "<=", expected);
	}
}

// uint
inline void inner_assertUIntGraterThan(
	const uint64_t a,
	const uint64_t e,
	const char *actual,
	const char *expected,
	const char *funcName,
	int lineNo)
{
	if (!(a > e)) {
		inner_printAssertMessage(funcName, lineNo, actual, "> ", expected);
	}
}

inline void inner_assertUIntGraterThanOrEquals(
	const uint64_t a,
	const uint64_t e,
	const char *actual,
	const char *expected,
	const char *funcName,
	int lineNo)
{
	if (!(a >= e)) {
		inner_printAssertMessage(funcName, lineNo, actual, ">=", expected);
	}
}

inline void inner_assertUIntLessThan(
	const uint64_t a,
	const uint64_t e,
	const char *actual,
	const char *expected,
	const char *funcName,
	int lineNo)
{
	if (!(a < e)) {
		inner_printAssertMessage(funcName, lineNo, actual, "< ", expected);
	}
}

inline void inner_assertUIntLessThanOrEquals(
	const uint64_t a,
	const uint64_t e,
	const char *actual,
	const char *expected,
	const char *funcName,
	int lineNo)
{
	if (!(a <= e)) {
		inner_printAssertMessage(funcName, lineNo, actual, "<=", expected);
	}
}

// double
inline void inner_assertDoubleEquals(
	const double a,
	const double e,
	const char *expected,
	const char *actual,
	const char *funcName,
	int lineNo)
{
	const bool success = fabs(e - a) <= DBL_EPSILON * fmax(1, fmax(fabs(e), fabs(a)));
	inner_assertEquals(success, actual, expected, funcName, lineNo);
}

inline void inner_assertDoubleGraterThan(
	const double a,
	const double e,
	const char *actual,
	const char *expected,
	const char *funcName,
	int lineNo)
{
	if (!isgreater(a, e)) {
		inner_printAssertMessage(funcName, lineNo, actual, "> ", expected);
	}
}

inline void inner_assertDoubleGraterThanOrEquals(
	const double a,
	const double e,
	const char *actual,
	const char *expected,
	const char *funcName,
	int lineNo)
{
	if (!isgreaterequal(a, e)) {
		inner_printAssertMessage(funcName, lineNo, actual, ">=", expected);
	}
}

inline void inner_assertDoubleLessThan(
	const double a,
	const double e,
	const char *actual,
	const char *expected,
	const char *funcName,
	int lineNo)
{
	if (!isless(a, e)) {
		inner_printAssertMessage(funcName, lineNo, actual, "< ", expected);
	}
}

inline void inner_assertDoubleLessThanOrEquals(
	const double a,
	const double e,
	const char *actual,
	const char *expected,
	const char *funcName,
	int lineNo)
{
	if (!islessequal(a, e)) {
		inner_printAssertMessage(funcName, lineNo, actual, "<=", expected);
	}
}

#endif // CMT_H

#ifdef COMPILE_AS_TEST

void test_assertTrue(void) {
	assertTrue(3 == 3);
	assertTrue(false);
}

void test_assertFalse(void) {
	assertFalse(3 == 3);
	assertFalse(false);
}

void test_assertStringEquals(void) {
	assertStringEquals("abc", "abc");
	assertStringEquals("abc", "def");
}

void test_assertInt(void) {
	int x = 3;
	int y = 4;
	assertIntEquals(x, 3);
	assertIntEquals(x, y);
	assertIntGreaterThan(x, 2);
	assertIntGreaterThan(x, 3); // fail
	assertIntGreaterThanOrEquals(x, 3);
	assertIntGreaterThanOrEquals(x, 4); // fail
	assertIntLessThan(x, 3); // fail
	assertIntLessThan(x, 4);
	assertIntLessThanOrEquals(x, 2); // fail
	assertIntLessThanOrEquals(x, 3);
}

int main(void) {
	test_assertTrue();
	test_assertFalse();
	test_assertStringEquals();
	test_assertInt();
	return 0;
}

#endif // COMPILE_AS_TEST
