# Learning-C

This is a repository containing notes on C syntax, and projects completed using C during the reading of C Programming Language by Brian Kernigan and Dennis Ritchie. Also a great excuse for me to practice my markdown syntax.

### Extensions used in VS Code to run C

- C/C++ by Microsoft
- C/C++ Extension Packy by Microsoft
- Code Runner by Jun Han

## Let's Begin

Our first program: hello.c

```
#include <stdio.h>

int main()
{
    printf("Hello, World\n");
}
```

> Every C program begins executing at the beginning of main. This mean that every program must have a main somewhere.

`#include  <stdio.h>` tells the compiler to include information about the standar input/output library.

`printf("hello, world\n")` is a library function that prints output.

A seuence of characters in double quotes like `"hello, world\n"` is called a _character string_ or _string constant_.

The _escape sequence_ `\n` in the string is C notation for the _newline character_, which when printed advances the output to the left margin on the next line.

### Our Second Program: Conversion of Fahrenheit-Celsius

```
#include <stdio.h>

/* prtint fahrenheit celsiustable */

int main()
{

    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    while (fahr <= upper){
        celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}

```

> In C, all variables must be declared before they are used, usually the at the beginning of the function before any executable statements. A _declaration_ announces the properties of variables; it consists of a name and list of variables.

The type `int` means that the variables are integers.

By constrast with `float`, which means floating point, numbers that may have a fractional part (ie decimal).

> 16 bit `int` has a range between -32768 and +32768

> 32 bit `float` has a range with at least siz sig figs and magnitude generally between 10^-38 and 10^38

> Note: The way celsius is calculated. Why did we first multiply by 5 and then divide by 9 instead of just multiplying by `5/9`? Integer division _truncates_. that is, any fractional part would be discarded. Since 5 and 9 are integers, `5/9` would be truncated to zero and so all the Celsius temps would be reported as zero.

C provides several other data types:
| data type | |
| ---- | ------------------------ |
| char | character - a single byte|
| short| short ingteger|
| long | long integer|
| double | double-precision floating point|

`printf` is not part of the C language; there is no input our output defined in C itself. IT is a useful function from standard library of functions in `stdio.h`
