#include "proplist.h"
#include <gtest/gtest.h>
#include <iostream>

TEST(PropList, AddGet)
{
    PropList props;

    try {
        props.add("name", "Nico");
        String s = props.get<String>("name", "Allison");
        EXPECT_EQ("Nico", s);

        props.add("age", 20);
        int a = props.get<int>("age");
        EXPECT_EQ( 20, a );
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

