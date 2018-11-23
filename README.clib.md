at this point, I can't help to do this:
from c++11, we only have 21 c header files

## table of content
- math.h: numerics library

- stdarg.h: variable arguments handling ?: va_list, va_start, va_arg, va_end, see the document

- stdio.h
- stdlib.h: many useful idea start here

- time.h
- assert.h
- errno.h
- signal.h: C library to handle signals ?: handle signal youself
- setjmp.h: Non local jumps

- ctype.h: character handling functions
- stdint.h: integral type aliases with specific width requirements and others. e.g. int32_t
- limits.h: sizes of integral types
- float.h: charateristics of floating functions
- stdbool.h: c++ support bool type directly
- string.h
- stddef.h: This header defines several types implicitly generated or used by certain language expressions. e.g. size_t and nullptr_t

- uchar.h: unicode characters X
- wchar.h: wide characters X
- wtype.h: wide character type X
- locale.h: C localization library ?: X not insterested

- iso646.h: ISO 646 alternative operator spellings ?:X not insterested

## string.h
Copying:
    memcpy: Copy block of memory (function )
    memmove: Move block of memory (function )
    strcpy: Copy string (function )
    strncpy: Copy characters from string (function )

Concatenation:
    strcat: Concatenate strings (function )
    strncat: Append characters from string (function )

Comparison:
    memcmp: Compare two blocks of memory (function )
    strcmp: Compare two strings (function )
    strcoll: Compare two strings using locale (function )
    strncmp: Compare characters of two strings (function )
    strxfrm: Transform string using locale (function )

Searching:
    memchr: Locate character in block of memory (function )
    strchr: Locate first occurrence of character in string (function )
    strcspn: Get span until character in string (function )
    strpbrk: Locate characters in string (function )
    strrchr: Locate last occurrence of character in string (function )
    strspn: Get span of character set in string (function )
    strstr: Locate substring (function )
    strtok: Split string into tokens (function )

Other:
    memset: Fill block of memory (function )
    strerror: Get pointer to error message string (function )
    strlen: Get string length (function )

## stdlib.h
Functions
String conversion
    atof: Convert string to double (function )
    atoi: Convert string to integer (function )
    atol: Convert string to long integer (function )
    atoll: Convert string to long long integer (function )
    strtod: Convert string to double (function )
    strtof: Convert string to float (function )
    strtol: Convert string to long integer (function )
    strtold: Convert string to long double (function )
    strtoll: Convert string to long long integer (function )
    strtoul: Convert string to unsigned long integer (function )
    strtoull: Convert string to unsigned long long integer (function )

Pseudo-random sequence generation
    rand: Generate random number (function )
    srand: Initialize random number generator (function )

Dynamic memory management
    calloc: Allocate and zero-initialize array (function )
    free: Deallocate memory block (function )
    malloc: Allocate memory block (function )
    realloc: Reallocate memory block (function )

Environment
    abort: Abort current process (function )
    atexit: Set function to be executed on exit (function )
    at_quick_exit: Set function to be executed on quick exit (function )
    exit: Terminate calling process (function )
    getenv: Get environment string (function )
    quick_exit: Terminate calling process quick (function )
    system: Execute system command (function )
    _Exit: Terminate calling process (function )

Searching and sorting
    bsearch: Binary search in array (function )
    qsort: Sort elements of array (function )

Integer arithmetics
    abs: Absolute value (function )
    div: Integral division (function )
    labs: Absolute value (function )
    ldiv: Integral division (function )
    llabs: Absolute value (function )
    lldiv: Integral division (function )

Multibyte characters
    mblen: Get length of multibyte character (function )
    mbtowc: Convert multibyte sequence to wide character (function )
    wctomb: Convert wide character to multibyte sequence (function )

Multibyte strings
    mbstowcs: Convert multibyte string to wide-character string (function )
    wcstombs: Convert wide-character string to multibyte string (function )
