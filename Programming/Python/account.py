class account:
    def __init__(self, balance):
        self.balance = balance

    def __str__(self):
        return f"This is your account and it's current balance is {self.balance}."

    def get_amount(self):
        return self._amount

        # setter method

    def set_amount(self, x):
        self._amount = x

    def deposit(self):
        self.balance = self.balance + self._amount;
        return self.balance

    def withdraw(self):
        if (self._amount > self.balance):
            return f"operation can not be performed because withdrawal amount is greater than current balance."
        else:
            self.balance = self.balance - self._amount;
            return self.balance

    def transfer(self, target):
        if self.balance >= self._amount:
            self.balance = self.balance - self._amount
            target.balance = target.balance + self._amount
            return f"After transfer the balance in present account is {self.balance} and in target account is {target.balance}."
        else:
            return f"peration can not be performed because transfer amount is greater than current balance."


def main():
    b1 = account(20000)
    b2 = account(40000)

    while True:
        print("\nMenu")
        print("1. Show balance")
        print("2. Withdraw")
        print("3. Deposit")
        print("4. Transfer")
        print("5. Exit")
        ch = input("Enter your choice: ")

        if ch == '5':
            break
        elif ch not in ['1', '2', '3', '4', '5']:
            print("Invalid choice enter correct choice.")
            continue
        acc_ch = input("Choose the account you want to perform operations (1 or 2): ")
        if acc_ch not in ['1', '2']:
            print("Account does not exist choose between 1 or 2")
            continue

        amt = int(input("Enter the amount to perform operation of your account: "))
        if acc_ch == '1':
            curr_ac = b1
            tar_ac = b2
        elif acc_ch == '2':
            curr_ac = b2
            tar_ac = b1

        curr_ac.set_amount(amt)

        if ch == '1':
            print(curr_ac)
        elif ch == '2':
            new_bal = curr_ac.withdraw()
            print(f"Your current balance after withdrawing {curr_ac.get_amount()} in account {acc_ch} is {new_bal}.")
        elif ch == '3':
            new2_bal = curr_ac.deposit()
            print(f"Your current balance after depositing {curr_ac.get_amount()} in account {acc_ch} is {new2_bal}.")
        elif ch == '4':
            result = curr_ac.transfer(tar_ac)
            print(result)
  

if __name__ == "__main__":
    main()
