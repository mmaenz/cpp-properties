// Copyright 2014 Fredy Wijaya
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "microtest.h"
#include "PropertiesUtils.h"


using namespace cppproperties;

TEST(TestTrim) {
    ASSERT_STREQ("foo", PropertiesUtils::Trim("foo"));
    ASSERT_STREQ("foo", PropertiesUtils::Trim("    foo     "));
    ASSERT_STREQ("foo", PropertiesUtils::Trim("\n  foo   \r\n"));
    ASSERT_STREQ("", PropertiesUtils::Trim("      \n"));
}

TEST(TestIsProperty) {
    ASSERT_TRUE(PropertiesUtils::IsProperty("key=value"));
    ASSERT_TRUE(PropertiesUtils::IsProperty("    key   =     value   "));
    ASSERT_TRUE(PropertiesUtils::IsProperty("    key   ="));
    ASSERT_FALSE(PropertiesUtils::IsProperty("=value"));
}

TEST(TestParseProperty) {
    std::pair<std::string, std::string> p = PropertiesUtils::ParseProperty("key=value");
    ASSERT_STREQ("key", p.first);
    ASSERT_STREQ("value", p.second);

    p = PropertiesUtils::ParseProperty(" key = value ");
    ASSERT_STREQ("key", p.first);
    ASSERT_STREQ("value ", p.second);

    p = PropertiesUtils::ParseProperty(" key =  ");
    ASSERT_STREQ("key", p.first);
    ASSERT_STREQ("", p.second);
}

TEST(TestIsComment) {
    ASSERT_TRUE(PropertiesUtils::IsComment("# comment"));
    ASSERT_TRUE(PropertiesUtils::IsComment("   # comment"));
}

TEST(TestIsEmptyLine) {
    ASSERT_TRUE(PropertiesUtils::IsEmptyLine("      \r\n"));
}

TEST_MAIN()