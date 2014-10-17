#!/usr/bin/python

charge = [1,5,10,25,50]
def change_charge(amount, kind):
    if amount == 0:
        return 1
    elif amount < 0 or kind == 0:
        return 0
    else:
# means 2 catagories: one means do not contain biggest unit, the other means at least contain 1 biggest unit, then recurive
        return change_charge(amount, kind-1) + change_charge(amount-charge[kind-1], kind)


if __name__ == "__main__":
    print change_charge(100,5)
