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
#include <algorithm>
#include "Properties.h"

using namespace std;
using namespace cppproperties;

TEST(TestAddProperty) {
    Properties props;
    props.AddProperty("key1", "value1");
    props.AddProperty("key2", "value2");
    props.AddProperty("key3", "value3");
    ASSERT_EQ("value1", props.GetProperty("key1"));
    ASSERT_EQ("value2", props.GetProperty("key2"));
    ASSERT_EQ("value3", props.GetProperty("key3"));
    ASSERT_EQ("default", props.GetProperty("foo", "default"));
    ASSERT_THROW(props.GetProperty("foo"));

    vector<string> names = props.GetPropertyNames();
    ASSERT_EQ(3, names.size());
    ASSERT_TRUE(find(names.begin(), names.end(), "key1") != names.end());
    ASSERT_TRUE(find(names.begin(), names.end(), "key2") != names.end());
    ASSERT_TRUE(find(names.begin(), names.end(), "key3") != names.end());
}

TEST(TestAddPropertyOvewrite) {
    Properties props;
    props.AddProperty("key1", "value1");
    props.AddProperty("key2", "value2");
    props.AddProperty("key3", "value3");
    props.AddProperty("key3", "value333");
    ASSERT_EQ("value1", props.GetProperty("key1"));
    ASSERT_EQ("value2", props.GetProperty("key2"));
    ASSERT_EQ("value333", props.GetProperty("key3"));
    ASSERT_EQ("default", props.GetProperty("foo", "default"));
    ASSERT_THROW(props.GetProperty("foo"));

    vector<string> names = props.GetPropertyNames();
    ASSERT_EQ(3, names.size());
    ASSERT_TRUE(find(names.begin(), names.end(), "key1") != names.end());
    ASSERT_TRUE(find(names.begin(), names.end(), "key2") != names.end());
    ASSERT_TRUE(find(names.begin(), names.end(), "key3") != names.end());
}

TEST(TestRemoveProperty) {
    Properties props;
    props.AddProperty("key1", "value1");
    props.AddProperty("key2", "value2");
    props.AddProperty("key3", "value3");
    props.RemoveProperty("key3");
    ASSERT_THROW(props.RemoveProperty("foo"));
    ASSERT_EQ("value1", props.GetProperty("key1"));
    ASSERT_EQ("value2", props.GetProperty("key2"));

    vector<string> names = props.GetPropertyNames();
    ASSERT_EQ(2, names.size());
    ASSERT_TRUE(find(names.begin(), names.end(), "key1") != names.end());
    ASSERT_TRUE(find(names.begin(), names.end(), "key2") != names.end());
}
