#include <gtest/gtest.h>

#include "bank_account.hpp"

/** Struct: BankAccountTest
 *  -----------------------
 *  Test wrapper for the BankAccount struct. Because we are inheriting from
 *  testing::Test, we can use this struct to create test fixtures (TEST_F)
 *  that will automatically construct and destruct the BankAccount object 
 *  for us.
 */
struct BankAccountTest : testing::Test{
    BankAccount* account;

    BankAccountTest() {
        account = new BankAccount;
    }

    virtual ~BankAccountTest() {
        delete account;
    }
};

/** Struct: account_state
 *  ---------------------
 *  This struct contains state that we will use as the parameters to the
 *  WithdrawAccountTest test fixture (below).
 */ 
struct account_state {
    int initial_balance;
    int withdraw_amount;
    int final_balance;
    bool success;

    // operator overload to print nicer error messages. Try making a WithdrawAccountTest
    // fail with and without this overload to see the difference in error message outputs.
    friend std::ostream& operator<<(std::ostream& os, const account_state& obj) {
        return os
            << "initial_balance: " << obj.initial_balance
            << " withdraw_amount: " << obj.withdraw_amount
            << " final_balance: " << obj.final_balance
            << " success: " << obj.success;
    }
};

/** Struct: WithdrawAccountTest
 *  ---------------------------
 *  This struct will be used for a parameterized test fixture. By inheriting
 *  from testing::WithParamInterface<account_state>, we can instantiate this
 *  test fixture with parameterized inputs. (see below)
 */
struct WithdrawAccountTest : BankAccountTest, testing::WithParamInterface<account_state> {
    WithdrawAccountTest() {
        account->balance = GetParam().initial_balance;
    }
};

/** Test: AccountTest->BankAccountStartsEmpty
 *  -----------------------------------------
 *  Test to ensure bank accounts are initialized with a balance of 0.
 *  Notice how we have to manually create and destroy the BankAccount object.
 *  See below for how we can avoid this using a test fixture!
 */
TEST(AccountTest, BankAccountStartsEmpty) {
    BankAccount* account = new BankAccount;
    EXPECT_EQ(0, account->balance);
    delete account;
}

/** Test Fixture: BankAccountTest->BankAccountStartsEmpty
 *  -----------------------------------------------------
 *  Same as the above test, but notice that we do not have to create and 
 *  destroy the BankAccount object manually. Because we create the BankAccountTest
 *  struct and used a test fixture (TEST_F), the constructor and destructor of the
 *  BankAccountTest will automatically be called for us.
 *  
 *  In this case, it doesn't save us too much work, but imagine if BankAccount had
 *  hundreds of fields that had to be initialized properly. Having the BankAccountTest
 *  wrapper would be super helpful.
 */
TEST_F(BankAccountTest, BankAccountStartsEmpty) {
    EXPECT_EQ(0, account->balance);
}

/** Test Fixture: BankAccountTest->CanDepositMoney
 *  ----------------------------------------------
 *  Test fixture to test depositing works.
 *  Should probably have more tests here (e.g. what if we deposit a negative value?)
 */
TEST_F(BankAccountTest, CanDepositMoney) {
    account->deposit(100);
    EXPECT_EQ(100, account->balance);
}

/** Parameterized Test Fixture: WithdrawAccountTest->FinalBalance
 *  -------------------------------------------------------------
 *  This is a test fixture that expects parameter inputs. This test fixture is kind
 *  of like a template, where it defines a blueprint for how to make the true test
 *  fixture but expects an input (the parameters) to be able to do that.
 * 
 *  GetParam() is how we access these inputs when the test fixture is instantiated.
 */
TEST_P(WithdrawAccountTest, FinalBalance){
    auto as = GetParam();
    auto success = account->withdraw(as.withdraw_amount);
    EXPECT_EQ(as.final_balance, account->balance);
    EXPECT_EQ(as.success, success);
}

/** Instantiation of Parameterized Test Fixture: WithdrawAccountTest->FinalBalance
 *  ------------------------------------------------------------------------------
 *  Instantiates the parameterized test fixture by providing two different input
 *  account_states. The WithdrawAccountTest is defined to be inherited from 
 *  testing::WithParamInterface<account_state> which is why we need to provide the
 *  instantiation with an account_state.
 * 
 *  This will instatiate two separate tests.
 */
INSTANTIATE_TEST_SUITE_P(DEFAULT, WithdrawAccountTest,
    testing::Values(
        account_state{100,50,50,true},
        account_state{100,200,100,false}
    ));

/** Main Function
 *  -------------
 *  Initializes Google Test and runs all tests.
 */
int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
