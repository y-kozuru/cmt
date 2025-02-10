# cmt - C language Minimum Test library
A small unit test library for C language.

It is a header-only library. There is no need to define the `*_IMPLEMENTATION` macro.

You can perform checks of various values using macros that start with `assert`. When the test succeeds, display nothing. When it fails, display function name, the line number, and the expected expression.

# Example
```c
#include "cmt.h"

void testInt(void) {
	int x = 3;
	int y = 6;
	assertIntEquals(x, 3);
	assertIntEquals(x, y);
}

void testString(void) {
	const char *s1 = "hello";
	const char *s2 = "hello";
	assertStringEquals(s1, "hi");
	assertStringEquals(s1, s2);
}

int main(void) {
	testInt();
	testString();
	return 0;
}

```

When you run the above source code, the following output will be generated:

```
Failed: testInt L318: expected "x == y"
Failed: testString L324: expected "hello == hi"
```

Please do not use functions that start with `inner_`.
