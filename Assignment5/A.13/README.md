ALGORITHM ComputeDailyBillTotal(bills, count)
INPUT: bills (array of base-class pointers to Bill objects), count (integer number of bills)
OUTPUT: grandTotal (real number representing sum of all bills)

BEGIN
    grandTotal <- 0.0
    FOR i <- 0 TO count - 1 DO
        IF bills[i] != NULL THEN
            CALL bills[i]->print()
            grandTotal <- grandTotal + bills[i]->total()
        END IF
    END FOR
    RETURN grandTotal
END
