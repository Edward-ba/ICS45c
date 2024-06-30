#include <gtest/gtest.h>
#include <string.h>

#include <algorithm>

#include "string.hpp"
#include "alloc.hpp"

TEST(StringFunction, strlen) {
    EXPECT_EQ(String::strlen(""), 0);
    EXPECT_EQ(String::strlen("foo"), 3);
}

TEST(StringFunction, strcpy) {
    char result[10];
    EXPECT_EQ(String::strcpy(result, "foo"), result);
    EXPECT_STREQ(result, "foo");

    EXPECT_EQ(String::strcpy(result, "a"), result);
    EXPECT_STREQ(result, "a");

    EXPECT_EQ(String::strcpy(result, ""), result);
    EXPECT_STREQ(result, "");
}

TEST(StringFunction, strncpy) {
	char result[10];
	EXPECT_EQ(String::strncpy(result, "foo", 9), result);
	EXPECT_STREQ(result, "foo");
	EXPECT_EQ(String::strncpy(result, "asdfasdfasdf", 9), result);
	EXPECT_STREQ(result, "asdfasdfa");
}

TEST(StringFunction, strdup) {
	char original[] = "asdf";
	char* test1 = String::strdup(original);
	EXPECT_STREQ(test1, "asdf");
	delete[] test1;
}

TEST(StringFunction, strcat) {
	char start[10] = "start";
	char* result = String::strcat(start, "end");
	EXPECT_STREQ(result, "startend");
}

TEST(StringFunction, strncat) {
	char start[30] = "start";
	char* result = String::strncat(start, "endplusextra", 4);
	EXPECT_STREQ(result, "startendp");
}

TEST(StringFunction, strcmp) {
	char small[5] = "asdf";
	char big[5] = "zsdf";
	char small_same[5] = "asdf";
	char small_bigger[6] = "asdfa";
	EXPECT_TRUE(String::strcmp(small, small_same) == 0);
	EXPECT_TRUE(String::strcmp(small, big) < 0);
	EXPECT_TRUE(String::strcmp(big, small) > 0);
	EXPECT_TRUE(String::strcmp(small, small_bigger) != 0);
	EXPECT_TRUE(String::strcmp(small, small_bigger) < 0);
}

TEST(StringFunction, strncmp) {
	char small[5] = "asdf";
	char big[5] = "zsdf";
	char small_same[5] = "asdf";
	char small_bigger[7] = "asdfas";
	EXPECT_TRUE(String::strncmp(small, small_same, 5) == 0);
	EXPECT_TRUE(String::strncmp(small, big, 5) < 0);
	EXPECT_TRUE(String::strncmp(big, small, 5) > 0);
	EXPECT_TRUE(String::strncmp(small, small_bigger, 5) != 0);
	EXPECT_TRUE(String::strncmp(small, small_bigger, 5) < 0);
	EXPECT_TRUE(String::strncmp("foo", "foobar", 3) == 0);
	EXPECT_TRUE(String::strncmp("footest", "foobar", 3) == 0);
	EXPECT_TRUE(String::strncmp("asdf", "hello", 0) == 0);
}

TEST(StringFunction, reverse_cpy) {
	char normal[5] = "asdf";
	char reverse[5];
	char blank[1] = "";
	char reverse_blank[1];
	String::reverse_cpy(reverse, normal);
	EXPECT_STREQ(reverse, "fdsa");
	String::reverse_cpy(normal, reverse);
	EXPECT_STREQ(normal, "asdf");
	String::reverse_cpy(reverse_blank, blank);
	EXPECT_STREQ(reverse_blank, "");
}

TEST(StringFunction, strchr) {
	char first[5] = "asdf";
	char empty[1] = "";
	EXPECT_EQ(String::strchr(first, 'a'), &first[0]);
	EXPECT_EQ(String::strchr(first, 'f'), &first[3]);
	EXPECT_EQ(String::strchr(first, 'q'), nullptr);
	EXPECT_EQ(String::strchr(empty, 'a'), nullptr);
	EXPECT_EQ(String::strchr(first, '\0'), &first[4]);
}

TEST(StringFunction, strstr) {
	char first[15] = "Hello World";
	char empty[1] = "";
	EXPECT_EQ(String::strstr(first, "Hello"), &first[0]);
	EXPECT_EQ(String::strstr(first, "World"), &first[6]);
	EXPECT_EQ(String::strstr(first, "NotInIt"), nullptr);
	EXPECT_EQ(String::strstr(empty, "NotInIt"), nullptr);
	EXPECT_EQ(String::strstr(first, ""), &first[0]);
}