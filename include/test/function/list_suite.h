#ifndef __WOODPILE_TEST_FUNCTION_LIST_SUITE_H
#define __WOODPILE_TEST_FUNCTION_LIST_SUITE_H

/**
 * @file
 * Tests for the List container.
 */

/**
 * Tests the AppendAllToList function with an empty List to append.
 *
 * @test Appending an empty List must return the List to append to.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestAppendAllOfEmptyList
( void );

/**
 * Tests the AppendAllToList function with a NULL List to append.
 *
 * @test A NULL List to append must return the List to append to.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestAppendAllOfNullList
( void );

/**
 * Tests the AppendAllToList function with a populated List to append.
 *
 * @test All elements of the appended List must be added to the end of the List
 * in the order they existed in the original List. The List appended to must be
 * returned.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestAppendAllOfPopulatedList
( void );

/**
 * Tests the AppendAllToList function with a NULL List to append to.
 *
 * @test A NULL List to append to must return NULL, regardless of whether the
 * element to append is NULL or non-NULL.
 * 
 * @return NULL on completion or a string describing the failure
 */
const char *
TestAppendAllToNullList
( void );

/**
 * Tests the AppendToList function with a NULL element.
 *
 * @test A NULL element must return the List to append to, regardless of whether
 * the List to append to is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestAppendNullElement
( void );

/**
 * Tests the AppendToList function with an empty List.
 *
 * @test Appending an element to an empty List must result in the element being
 * at the front of the List and the List having a size of 1.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestAppendToEmptyList
( void );

/**
 * Tests the AppendToList function with a NULL list to append to.
 *
 * @test A NULL List to append to must return NULL, regardless of whether the
 * element to append is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestAppendToNullList
( void );

/**
 * Tests the AppendToList function with a populated List.
 *
 * @test Appending an element to the List must result in the element being at
 * the back of the List, and the size of the List increasing by one.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestAppendToPopulatedList
( void );

/**
 * Tests the ListBack function with an empty List.
 *
 * @test Calling the function with an empty List must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestBackOfEmptyList
( void );

/**
 * Tests the ListBack function with a NULL List.
 *
 * @test Calling the function with a NULL List must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestBackOfNullList
( void );

/**
 * Tests the ListBack function with a populated List.
 *
 * @test Calling the function with a populated List must return the last element
 * of the List.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestBackOfPopulatedList
( void );

/**
 * Tests the ListContains function with an element existing multiple times in
 * the List.
 *
 * @test An element existing twice in the List must return 2. An element
 * existing three times in the List must return 3.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsDuplicateElements
( void );

/**
 * Tests the ListContains function with an element that does not exist in the
 * List.
 *
 * @test An element not existing in the List must return 0.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsNonExistentElement
( void );

/**
 * Tests the ListContains function a NULL element supplied.
 *
 * @test A NULL element must return 0, whether the List supplied is NULL or
 * non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsNullElement
( void );

/**
 * Tests the ListContains function with elements that exist in the Queue exactly
 * once.
 *
 * @test An element existing exaclty once in the List must return 1.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsUniqueElement
( void );

/**
 * Tests the ListContains function with a NULL List.
 *
 * @test A NULL List must return 0, whether the element supplied is NULL or
 * non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestContainsWithNullList
( void );

/**
 * Tests the CopyList function.
 *
 * @test A non-NULL List must be returned as the copy of a non-NULL List.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopy
( void );

/**
 * Tests the contents of the List returned by the CopyList function.
 *
 * @test The copied List must point at the same elements as the original.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyContents
( void );

/**
 * Tests the List returned by the CopyList function.
 *
 * @test The copied List must be a different value than the original.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyDistinct
( void );

/**
 * Tests the CopyList function with a NULL List.
 *
 * @test a NULL List must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopyNullList
( void );

/**
 * Tests the size of the List returned by the CopyList function.
 *
 * @test The copy of a populated List must be the same size as the original.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestCopySize
( void );

/**
 * Tests the DestroyList function with a NULL List.
 * 
 * @test A NULL List must not cause an error.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestDestroyNullList
( void );

/**
 * Tests the DestroyList function with a populated List.
 *
 *  @test A populated List must not cause an error.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestDestroyPopulatedList
( void );

/**
 * Tests the ListFront function with an empty List.
 *
 * @test Calling the function with an empty List must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestFrontOfEmptyList
( void );

/**
 * Tests the ListFront function with a NULL List.
 *
 * @test Calling the function with a NULL List must return NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestFrontOfNullList
( void );

/**
 * Tests the ListFront function with a populated List.
 *
 * @test Calling the function with a populated List must return the first
 * element of the List.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestFrontOfPopulatedList
( void );

/**
 * Tests the ListGet function with an empty List.
 *
 * @test Calling the function with an empty List must return NULL, regardless
 * of whether the index is negative, zero, or positive.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestGetFromEmptyList
( void );

/**
 * Tests the ListGet function with a NULL List.
 *
 * @test Calling the function with a NULL List must return NULL, regardless of
 * whether the index is negative, zero, or positive.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestGetFromNullList
( void );

/**
 * Tests the ListGet function with a negative index.
 *
 * @test Calling the function with an index of -1 must return the last element
 * in the List. Calling the function with an index of -2 must return the second
 * to last, -3 the third to last, -4 the fourth to last, -5 the fifth to last,
 * -6 the sixth to last, and -7 the seventh to last.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestGetNegativeIndex
( void );

/**
 * Tests the ListGet function with a negative index of magnitude greater than
 * the size of the List.
 *
 * @test Calling the function with an index equal to two less than the negative
 * of the size of the List must return the second to last element of the List.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestGetNegativeIndexWrap
( void );

/**
 * Tests the ListGet function with a positive index.
 *
 * @test Calling the function with an index of 1 must return the second element
 * in the List. Calling the function with an index of 2 must return the third
 * element in the list, 3 the fourth, 4 the fifth, 5 the sixth, and 6 the
 * seventh.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestGetPositiveIndex
( void );

/**
 * Tests the ListGet function with a positive index greater than the size of the
 * List.
 *
 * @test Calling the function with an index equal to the size of the List plus 2
 * must return the third element of the List.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestGetPositiveIndexWrap
( void );

/**
 * Tests the ListGet function with an index of 0.
 *
 * @test Calling the function with an index of 0 must return the first element
 * of the List.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestGetZeroIndex
( void );

/**
 * Tests the NewList function.
 *
 * @test Calling the function must return a non-NULL value
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestNew
( void );

/** 
 * Tests the ListIsEmpty function with an new List.
 *
 * @test A newly constructed List must return a value that is logically true.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestNewListIsEmpty
( void );

/**
 * Tests the ListIsEmpty function with a NULL List.
 *
 * @test A NULL List must return a value that is logically true.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestNullListIsEmpty
( void );

/**
 * Tests the ListIsEmpty function with a populated List.
 *
 * @test A populated List must return a value that is logically false.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPopulatedListIsNotEmpty
( void );

/**
 * Tests the PrependToList function with a NULL element.
 *
 * @test A NULL element must return the List to prepend to, regardless of whether
 * the List to prepend to is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPrependNullElement
( void );

/**
 * Tests the PrependToList function with an empty List.
 *
 * @test Prepending an element to an empty List must result in the element being
 * at the back of the List and the List having a size of 1.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPrependToEmptyList
( void );

/**
 * Tests the PrependToList function with a NULL list to prepend to.
 *
 * @test A NULL List to prepend to must return NULL, regardless of whether the
 * element to prepend is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPrependToNullList
( void );

/**
 * Tests the PrependToList function with a populated List.
 *
 * @test Prepending an element to the List must result in the element being at
 * the front of the List, and the size of the List increasing by one.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestPrependToPopulatedList
( void );

/**
 * Tests the ListSize function with an empty List.
 *
 * @test An empty List must return 0.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSizeOfEmptyList
( void );

/**
 * Tests the ListSize function with a NULL List.
 *
 * @test A NULL List must return 0.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSizeOfNullList
( void );

/**
 * Tests the ListSize function with a populated List.
 *
 * @test The correct size must be returned for a List containing seven elements.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestSizeOfPopulatedList
( void );

/**
 * Tests the ListToString function with an empty List.
 *
 * @test An empty List must result in an string of "[]".
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestToStringWithEmptyList
( void );

/**
 * Tests the ListToString function with a NULL element_to_string function.
 *
 * @test A NULL element_to_string function must result in each element in the
 * List being present in the string in pointer form.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestToStringWithNullFunction
( void );

/**
 * Tests the ListToString function with a NULL List.
 *
 * @test A NULL List must result in a NULL string, regardless of whether the
 * element_to_string function is NULL or non-NULL.
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestToStringWithNullList
( void );

/**
 * Tests the ListToString function with a populated List.
 *
 * @test A populated list must return the list contents, transformed by the
 * element_to_string function, in the following format:
 * [element_1, element_2, ..., element_n]
 *
 * @return NULL on completion or a string describing the failure
 */
const char *
TestToStringWithPopulatedList
( void );

#endif
