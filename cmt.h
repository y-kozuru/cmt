#ifndef cmt_h
#define cmt_h

#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// e = expected, a = actual
#define cmt_assert_true(a) \
inner_assert_true(a, #a, __func__, __LINE__)

#define cmt_assert_false(a) \
inner_assert_false(a, #a, __func__, __LINE__)

// string
#define cmt_assert_str_eq(e, a) \
inner_assert_str_eq(e, a, #e, #a, __func__, __LINE__)

// int
#define cmt_assert_int_eq(e, a) \
inner_assert_int_eq(e, a, #e, #a, __func__, __LINE__)

#define cmt_assert_int_gt(e, a) \
inner_assert_int_gt(e, a, #e, #a, __func__, __LINE__)

#define cmt_assert_int_ge(e, a) \
inner_assert_int_ge(e, a, #e, #a, __func__, __LINE__)

#define cmt_assert_int_lt(e, a) \
inner_assert_int_lt(e, a, #e, #a, __func__, __LINE__)

#define cmt_assert_int_le(e, a) \
inner_assert_int_le(e, a, #e, #a, __func__, __LINE__)

// unsigned int
#define cmt_assert_uint_eq(e, a) \
inner_assert_uint_eq(e, a, #e, #a, __func__, __LINE__)

#define cmt_assert_uint_gt(e, a) \
inner_assert_uint_gt(e, a, #e, #a, __func__, __LINE__)

#define cmt_assert_uint_ge(e, a) \
inner_assert_uint_ge(e, a, #e, #a, __func__, __LINE__)

#define cmt_assert_uint_lt(e, a) \
inner_assert_uint_lt(e, a, #e, #a, __func__, __LINE__)

#define cmt_assert_uint_le(e, a) \
inner_assert_uint_le(e, a, #e, #a, __func__, __LINE__)

// double
#define cmt_assert_double_eq(e, a) \
inner_assert_double_eq(e, a, #e, #a, __func__, __LINE__)

#define cmt_assert_double_gt(e, a) \
inner_assert_double_gt(e, a, #e, #a, __func__, __LINE__)

#define cmt_assert_double_ge(e, a) \
inner_assert_double_ge(e, a, #e, #a, __func__, __LINE__)

#define cmt_assert_double_lt(e, a) \
inner_assert_double_lt(e, a, #e, #a, __func__, __LINE__)

#define cmt_assert_double_le(e, a) \
inner_assert_double_le(e, a, #e, #a, __func__, __LINE__)

#define cmt_assert_eq(e, a) \
inner_assert_eq(e == a, #e, #a, __func__, __LINE__)

void inner_assert_eq(
	bool success,
	const char* e_str,
	const char* a_str,
	const char* func, int line);
void inner_assert_true(bool a, const char* a_str, const char* func, int line);
void inner_assert_false(bool a, const char* a_str, const char* func, int line);
void inner_assert_str_eq(
	const char* e, const char* a,
	const char* e_str, const char* a_str,
	const char* func, int line);

// int
void inner_assert_int_eq(
	int64_t e, int64_t a,
	const char* e_str, const char* a_str,
	const char* func, int line);
void inner_assert_int_gt(
	int64_t e, int64_t a,
	const char* e_str, const char* a_str,
	const char* func, int line);
void inner_assert_int_ge(
	int64_t e, int64_t a,
	const char* e_str, const char* a_str,
	const char* func, int line);
void inner_assert_int_lt(
	int64_t e, int64_t a,
	const char* e_str, const char* a_str,
	const char* func, int line);
void inner_assert_int_le(
	int64_t e, int64_t a,
	const char* e_str, const char* a_str,
	const char* func, int line);

// unsigned int
void inner_assert_uint_eq(
	uint64_t e, uint64_t a,
	const char* e_str, const char* a_str,
	const char* func, int line);
void inner_assert_uint_gt(
	uint64_t e, uint64_t a,
	const char* e_str, const char* a_str,
	const char* func, int line);
void inner_assert_uint_ge(
	uint64_t e, uint64_t a,
	const char* e_str, const char* a_str,
	const char* func, int line);
void inner_assert_uint_lt(
	uint64_t e, uint64_t a,
	const char* e_str, const char* a_str,
	const char* func, int line);
void inner_assert_uint_le(
	uint64_t e, uint64_t a,
	const char* e_str, const char* a_str,
	const char* func, int line);

// double
void inner_assert_double_eq(
	double e, double a,
	const char* e_str, const char* a_str,
	const char* func, int line);

void inner_assert_double_gt(
	double e, double a,
	const char* e_str, const char* a_str,
	const char* func, int line);
void inner_assert_double_ge(
	double e, double a,
	const char* e_str, const char* a_str,
	const char* func, int line);
void inner_assert_double_lt(
	double e, double a,
	const char* e_str, const char* a_str,
	const char* func, int line);
void inner_assert_double_le(
	double e, double a,
	const char* e_str, const char* a_str,
	const char* func, int line);

#endif
