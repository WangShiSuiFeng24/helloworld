#include <string>
class BankAccount
{
private:
    std::string fullname;
    std::string accid;
    double balance;
public:
    BankAccount();
    BankAccount(const std::string name, const std::string id, double bal);
    ~BankAccount();

    void init_account(const std::string name, const std::string id, double bal);
    void get_info() const;
    void deposit(double cash);
    void withdraw(double cash);
};

#include <iostream>

BankAccount::BankAccount()
{
    fullname = "";
    accid = "";
    balance = 0.0;
}

BankAccount::BankAccount(const std::string name, const std::string id, double bal)
{
    fullname = name;
    accid = id;
    balance = bal;
}

BankAccount::~BankAccount()
{

}

void BankAccount::init_account(const std::string name, const std::string id, double bal)
{
    fullname = name;
    accid = id;
    balance = bal;
}

void BankAccount::get_info() const
{
    using std::cout;
    using std::endl;
    cout << "The Account info:" << endl;
    cout << "Full Name: " << fullname << endl;
    cout << "Account ID: " << accid << endl;
    cout << "Deposit: " << balance << endl
         << endl;
}

void BankAccount::deposit(double cash)
{
    balance += cash;
}

void BankAccount::withdraw(double cash)
{
    using std::cout;
    using std::endl;
    if (cash <= balance)
        balance -= cash;
    else
        cout << "Your withdraw money is more than your balance!" << endl;
}

int main()
{
    BankAccount ba("Nik", "0001", 1200);
    ba.get_info();
    ba.init_account("Nik Swit", "", 1500);
    ba.get_info();
    ba.deposit(223.5);
    ba.get_info();
    ba.withdraw(30000);
    ba.get_info();
    ba.withdraw(1000);
    ba.get_info();

    return 0;
}