#define NO_UEFI

#include "contract_testing.h"

class ContractTestingMyTest : protected ContractTesting
{
public:
    ContractTestingMyTest()
    {
        initEmptySpectrum();
        initEmptyUniverse();
        INIT_CONTRACT(MYTEST);
    }

    MYTEST::add_output add(sint64 a, sint64 b)
    {
        MYTEST::add_input input;
        MYTEST::add_output output;
        input.a = a;
        input.b = b;
        callFunction(MYTEST_CONTRACT_INDEX, 1, input, output);
        return output;
    }
};

TEST(MyTest, TestAdd) {
    ContractTestingMyTest test;
    MYTEST::add_output output = test.add(1, 2);
    EXPECT_EQ(output.out, 3);
}
