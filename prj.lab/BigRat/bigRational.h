//
// Created by dmitrij on 4/23/22.
//

#ifndef BIGRATIONAL_BIGRATIONAL_H
#define BIGRATIONAL_BIGRATIONAL_H

#include <BigInt/bigInt.h>

class Rational {
private:

    BigInteger nominator = 0, denominator = 1;

    class DivideByZero: exception {};

    static void reduce(Rational &r);


    static void Check(Rational &r);

public:
    Rational() = default;

    Rational &operator=(const Rational &right);

    explicit Rational(const BigInteger &p, const BigInteger &q);

    Rational(const BigInteger &i);

    Rational(const int &i);

    BigInteger num();
    BigInteger denum();


    explicit operator bool () const;

    string toString() const;

    Rational &operator+=(const Rational &right);
    Rational &operator-=(const Rational &right);
    Rational &operator*=(const Rational &right);
    Rational &operator/=(const Rational &right);


    Rational operator--(int);
    Rational& operator--();
    Rational operator++(int);
    Rational& operator++();

    Rational operator-();
    Rational operator+() const;

    friend bool operator>(const Rational &left, const Rational &right);

    string asDecimal(size_t precision = 0) const;

    explicit operator double () const;
};

Rational operator+(const Rational &left, const Rational &right);
Rational operator-(const Rational &left, const Rational &right);
Rational operator*(const Rational &left, const Rational &right);
Rational operator/(const Rational &left, const Rational &right);

bool operator==(const Rational &left, const Rational &right);
bool operator>=(const Rational &left, const Rational &right);
bool operator<=(const Rational &left, const Rational &right);
bool operator<(const Rational &left, const Rational &right);
bool operator>(const Rational &left, const Rational &right);
bool operator!=(const Rational &left, const Rational &right);

std::ostream& operator<< (std::ostream& out, const Rational& rational);
std::istream& operator>> (std::istream& in, Rational& rational);

#endif //BIGRATIONAL_BIGRATIONAL_H
