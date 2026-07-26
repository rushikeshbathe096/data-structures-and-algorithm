/*
Problem:
Design a bank system that supports three operations:
1. Transfer money between two accounts.
2. Deposit money into an account.
3. Withdraw money from an account.

A transaction is valid only if the account number(s) exist and the source
account has sufficient balance for withdrawal or transfer.

Example:
Input:
Bank([10,100,20,50,30])

withdraw(3,10)  -> true
transfer(5,1,20)-> true
deposit(5,20)   -> true

Approach:
Store the balance of each account in a vector. Since account numbers are 1-based while the vector is 0-based, convert an account number to its corresponding index by subtracting one. Before performing any operation, validate that the account number(s) are within the valid range. For transfers
and withdrawals, also ensure the source account has enough balance before updating the balances. Each operation directly accesses the required account, making all transactions efficient.

Time Complexity:
- Constructor: O(n)-  The initial balance array is copied into the class member vector.
- Transfer: O(1)-  Only a few validity checks and direct vector accesses are performed.
- Deposit: O(1)-  A single account balance is updated after validation.
- Withdraw: O(1)-  A few checks followed by a direct update of one account balance.

Space Complexity: O(n)
The bank stores a copy of the balances of all n accounts.

Edge Cases:
- Invalid account numbers (less than 1 or greater than n).- Withdrawal or transfer amount greater than the available balance.
- Transfer between valid accounts where the source and destination are the   same account (still a valid operation).
*/
class Bank {
public:
    vector<long long>balance;
    Bank(vector<long long>& balance) {
        this->balance=balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1<1 || account1>balance.size() || account2<1 || account2>balance.size())return false;
        if(balance[account1-1]>=money){
            balance[account1-1]-=money;
            balance[account2-1]+=money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account<1 || account>balance.size())return false;
        balance[account-1]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account<1 || account>balance.size())return false;
        if(balance[account-1]>=money){
            balance[account-1]-=money;
            return true;
        }
        return false;
    }
};
