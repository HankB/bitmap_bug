# bitmap_bug

Track down problem with my bitmap code.

## Problem Statement

Can't access the bitmap storage array.

The intent of the code is to store bools as bits in an array of ints to reduce storage requirements by a factor of 8 at the cost of additional instructions.

## Found it

Bad parameters passed to `calloc()`. Code was allocating zero storage which `calloc()` was happy to do and return a valid pointer (to zero storage). 

I'll just leave this here for the benefit of anyone who likes stuff like this. There may be other bugs in the code but I'll return to the original project (from which this was extracted) and continue there.

## Build requirements

* CUnit test framework
* Electric Fence library

Both available in Debian repos.
