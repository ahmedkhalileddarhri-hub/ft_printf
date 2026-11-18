*This project has been created as part of the 42 curriculum by ahed-dar.*

# ft_printf

## Description

`ft_printf` is a re-implementation of the C standard `printf` function.
The goal of the project is to learn how variadic functions work in C
(`<stdarg.h>`), how to split a problem into small reusable helpers, and
how to handle low-level output with `write` and its error cases.

The result is a static library, `libftprintf.a`, that exports one function:

```c
int ft_printf(const char *format, ...);
```

It returns the number of characters written, or `-1` if an error occurred
(for example, a failed `write` or a format ending with a lone `%`).

### Supported conversions

| Specifier | Output                                         |
|-----------|------------------------------------------------|
| `%c`      | a single character                             |
| `%s`      | a string (`(null)` if the pointer is NULL)     |
| `%p`      | a pointer in hexadecimal (`(nil)` if NULL)     |
| `%d`      | a signed decimal integer                       |
| `%i`      | a signed decimal integer                       |
| `%u`      | an unsigned decimal integer                    |
| `%x`      | an unsigned integer in lowercase hexadecimal   |
| `%X`      | an unsigned integer in uppercase hexadecimal   |
| `%%`      | a literal percent sign                         |

## Instructions

### Compilation

```sh
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and the library
make re     # rebuilds everything
```

The library is compiled with `cc -Wall -Wextra -Werror`.

### Usage

Include the header and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s, you are %d years old\n", "world", 42);
	return (0);
}
```

```sh
cc main.c libftprintf.a -I. -o a.out
./a.out
```

### Testing

Compare the output and the return value with the real `printf`:

```c
int a = ft_printf("%c|%s|%p|%d|%i|%u|%x|%X|%%\n",
		'Z', "mix", &a, -1, INT_MIN, UINT_MAX, 255, 255);
int b = printf("%c|%s|%p|%d|%i|%u|%x|%X|%%\n",
		'Z', "mix", &a, -1, INT_MIN, UINT_MAX, 255, 255);
// both lines must be identical and a == b
```

To check write-error handling, redirect the output to a full device:

```sh
./a.out > /dev/full
```

## Project structure

```
.
├── Makefile
├── ft_printf.h        prototypes and includes
├── ft_printf.c        main loop: walks the format string
├── parsers.c          ft_format: dispatches a specifier to its helper
└── src/
    ├── ft_putchar.c   writes one character
    ├── ft_putstr.c    writes a string
    ├── ft_putnbr.c    writes a signed int (handles sign and INT_MIN)
    ├── ft_strlen.c    string length
    ├── putnbr_base.c  writes an unsigned number in any base
    └── print_ptr.c    writes a pointer (0x prefix + hexadecimal)
```

## Algorithm and design choices

1. **Walking the format string.** `ft_printf` reads the format one
   character at a time. A normal character is written directly. When a `%`
   is found, the next character is passed to `ft_format` together with the
   `va_list`.

2. **Dispatching.** `ft_format` selects the helper for the specifier and
   reads the matching type with `va_arg` (`int` for `%c`, `%d`, `%i`;
   `unsigned int` for `%u`, `%x`, `%X`; `void *` for `%p`; `char *` for `%s`).

3. **Printing numbers.** A single recursive function, `putnbr_base`, prints
   any unsigned number in any base. It recurses on `nbr / base_length` to
   print the higher digits first, then writes the digit `nbr % base_length`.
   It takes an `unsigned long` so that a 64-bit pointer is never truncated,
   and `%u`, `%x`, `%X` and `%d` all reuse it with a different base string.

4. **Signed integers.** `ft_putnbr` handles `INT_MIN` as a special case,
   because `-INT_MIN` overflows. Otherwise it writes a `-` for negative
   numbers, negates the value, and passes it to `putnbr_base`.

5. **Error handling.** Every helper returns the number of bytes written or
   `-1`. Each caller checks for `-1` and passes it up unchanged, so a
   failing `write` stops `ft_printf` immediately and the function returns
   `-1`. A format that ends with a lone `%` is also treated as an error.

## Resources

- `man 3 printf`, `man 3 stdarg`, `man 2 write`
- The C standard library documentation for variadic functions
- The 42 Norm (norminette) documentation

### Use of AI

AI was used as a code reviewer and tutor during this project: it
helped find bugs in my helpers (recursion, return-value handling, `INT_MIN`,
pointer truncation),
and helped clean up the code to follow the Norm and write this README. I
reviewed.
