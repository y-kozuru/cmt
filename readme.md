# cmt - C language Minimum Test library
A small unit test library for C language.

It is a header-only library. There is no need to define the `*_IMPLEMENTATION` macro.

You can perform checks of various values using macros that start with `assert`. When the test succeeds, display nothing. When it fails, display function name, the line number, and the expected expression.

# Example
```c
#include "cmt.h"

void test_int(void) {
	int x = 3;
	int y = 6;
	assert_int_eq(3, x);
	assert_int_eq(y, x);
}

void test_str(void) {
	const char *s = "hello";
	assert_string_eq("hello", s);
	assert_string_eq("hi", s);
}

int main(void) {
	test_int();
	test_str();
	return 0;
}

```

When you run the above source code, the following output will be generated:

```
Failed: test_int L317: expected x == y
Failed: test_str L323: expected s1 == "hi"
```

Please do not use functions that start with `inner_`.
