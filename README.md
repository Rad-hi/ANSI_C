# The ANSI C programming language: Some of the exercises

This is a repo containing my attempts at some of the exercices present in the "**The ANSI C programming language book**" book.

In fact, I am okay at C and have some good familiarity with it, but decided I would better get back to the roots from now, before I learn more advanced stuff only to find myself *standing on an unbalanced base* ...

Each exercice will have the page it's taken from at the top of it, and each exercice will have two files, the **.c** file and the **.out** file (compiled: ```$ gcc file_name.c -o file_name.out```). Additionally, if the code requires input (which most of the first chapter's ones do), I might add a test file (although I mostly just use the code's file for testing).

## Basic workflow for now:

- Read the assignment and code it
- Compile: ```$ gcc file_name.c -o file_name.out```
- Run (with input file) ```$ cat test_file | ./file_name.out```

I moved to using a **Makefile** as the projects got bigger and more complex.

I followed a semi-generic template from this website: [https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html#creating](https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html#creating)

