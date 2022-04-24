//
// Created by dmitrij on 4/23/22.
//

#ifndef BIGRATIONAL_BIGINT_H
#define BIGRATIONAL_BIGINT_H

#include <iostream>
#include <vector>
#include <string>

//+ - * / % OK
// * slow((

using namespace std;

const int Base = 10;

class BigInteger {
private:
    vector<int> data;

    bool is_positive = true;

    class DivideByZero: exception {};

    void zeroCheck();

    static BigInteger Plus(const BigInteger& a, const BigInteger& b);

    static BigInteger Minus(const BigInteger& a, const BigInteger& b);

    static BigInteger& Multiply(BigInteger &a, const BigInteger& b);

public:
    BigInteger() = default;

    BigInteger &operator=(const BigInteger &right);

    explicit BigInteger(const string &s);

    BigInteger(const int &j);


    static BigInteger abs1(const BigInteger& a);

    explicit operator bool () const;

    string toString() const;


    BigInteger &operator+=(const BigInteger &right);
    BigInteger &operator-=(const BigInteger &right);
    BigInteger &operator*=(const BigInteger &right);
    BigInteger &operator/=(const BigInteger &right);
    BigInteger &operator%=(const BigInteger &right);

    BigInteger operator--(int);
    BigInteger& operator--();
    BigInteger operator++(int);
    BigInteger& operator++();

    BigInteger operator-();
    BigInteger operator+() const;

    friend bool operator>(const BigInteger &left, const BigInteger &right);
};

BigInteger operator+(const BigInteger &left, const BigInteger &right);
BigInteger operator-(const BigInteger &left, const BigInteger &right);
BigInteger operator*(const BigInteger &left, const BigInteger &right);
BigInteger operator/(const BigInteger &left, const BigInteger &right);
BigInteger operator%(const BigInteger &left, const BigInteger &right);

bool operator==(const BigInteger &left, const BigInteger &right);
bool operator>=(const BigInteger &left, const BigInteger &right);
bool operator<=(const BigInteger &left, const BigInteger &right);
bool operator<(const BigInteger &left, const BigInteger &right);
bool operator!=(const BigInteger &left, const BigInteger &right);


#endif //BIGRATIONAL_BIGINT_H