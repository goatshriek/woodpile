# Woodpile

Woodpile is a collection of containers, aimed to provide functionality available
in the standard libraries of other languages.

__The base functionality of Woodpile has not been finished yet. Version 1.0 will
mark the first release that is considered complete.__

+ [Documentation](#documentation)
+ [Memory Allocation](#memory-allocation)
+ [Parameter Validation](#parameter-validation)

## Documentation

Woodpile is documented using Doxygen. Documentation can be generated by running
Doxygen with the Doxyfile avaliable in the doc directory.

## Memory Allocation

Memory allocation is a critical consideration when choosing a data structure.
Woodpile provides static and dynamic implementations of each structure, allowing
the user to choose whichever suites them best for any given situation, and even
combining different styles together if needed. Be sure to choose the appropriate
allocation scheme to best meet your needs.

A structure using dynamic allocation grows and shrinks as elements are added and
removed from it. No memory will be allocated for the structure that is not
being used. However, memory must be allocated or deallocated upon insertion or
deletion, and memory is not guaranteed to be contiguous which may reduce cache
effectiveness. Functions are available to defragment these structures, but they
are expensive and must be manually called.

A static memory allocation scheme removes these constraints. Such a structure is
implemented using a single block of memory, meaning that they avoid the need for
pointers to connect separate blocks of memory and can use the underyling cache
more effectively. However, this comes at an increased cost in size changes. If a
structure is not given a large enough size at creation it will be re-sized in
the event that too much data is pushed into it, which is an expensive operation.
Conversely if the size of the structure is over-estimated then the extra memory,
though unused by the structure itself, will be unavailable to other
applications.

##### tl;dr
Will the size of your structure be relatively static? Choose static allocation
and set the size of the structure as closely as possible to this size with a
little extra to avoid forced re-sizes. Will your structure grow/shrink often
or spend a lot of time empty? Choose a dynamic allocation scheme to avoid large
allocation costs.

## Parameter and Allocation Validation

Parameter validation in Woodpile function calls is done one of two ways. The
default way for parameters to be validated is via the standard `assert` macro
defined in the C standard library. This means that defining `NDEBUG` will
remove these assertions from the compiled source, decreasing the size of the
final library. This is the recommended method of use, as it leads to not only
a smaller library but also reduces the number of checks on parameters (such
as `NULL` checks) which leads to slightly faster performance.

If `NULL` arguments must be handled in all cases rather than just those
supported by the library, you can define `__WOODPILE_PARAMETER_VALIDATION`
during compilation to cause `NULL` to be returned for invalid parameters rather
than a system abort. This may be done when library size and performance can be
traded for less complex calling code, since `NULL` checks can be reduced.

##### tl;dr
`assert` calls are used by default and can be removed using `NDEBUG`, but if
you need invalid parameters to be handled gracefully by the library define
`__WOODPILE_PARAMETER_VALIDATION` during compilation instead.
