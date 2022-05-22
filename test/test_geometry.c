#include "ctest.h"
#include <stdbool.h>
#include <stdio.h>

#include "lib/libmainchek.h"

// start of the correct input tests
CTEST(input, word_chek_true)
{
    char* str = "circle(1 2,3)";
    char* mark = str;
    char* wr = "circle";
    bool result = word_chek(wr, mark);
    ASSERT_TRUE(result);
}
CTEST(input, search_comma_true)
{
    char* str = "circle(1 2,3)";
    char* mark = str;
    bool result = search_comma(mark);
    ASSERT_TRUE(result);
}
CTEST(input, search_breckets_true)
{
    char* str = "circle(1 2,3)";
    char* mark = str;
    bool result = search_breckets(mark);
    ASSERT_TRUE(result);
}
// end of the correct input tests
// start of invalid input tests
CTEST(input, word_chek_false)
{
    char* str = "cirle123";
    char* mark = str;
    char* wr = "circle";
    bool result = word_chek(wr, mark);
    ASSERT_FALSE(result);
}
CTEST(input, search_comma_false)
{
    char* str = "cirle123";
    char* mark = str;
    bool result = search_comma(mark);
    ASSERT_TRUE(result);
}
CTEST(input, search_breckets_false)
{
    char* str = "cirle123";
    char* mark = str;
    bool result = search_breckets(mark);
    ASSERT_TRUE(result);
}
