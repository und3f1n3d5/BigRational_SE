//
// Created by dmitrij on 4/23/22.
//

#include "bigRational.h"


Rational operator+(const Rational &left, const Rational &r) {
    Rational result = left;
    result += r;
    return result;
}


istream& operator >> (std::istream &in, Rational &a) {
    string s;
    in >> s;
    BigInteger p = 0, q = 0;
    size_t i;
    for (i = (s[0] == '-'); i < s.size() && s[i] != '/'; ++i){
        if ((int) s[i] - '0' > 9 || (int) s[i] - '0' < 0) {
            throw std::runtime_error("Invalid input");
        }
        p = p*10 + (int) s[i] - '0';
    }
    if (s[0] == '-')
        p = -p;
    if (i == s.size())
        q = 1;
    ++i;
    int j = i;
    for (i = i + (s[i] == '-'); i < s.size(); ++i) {
        if ((int) s[i] - '0' > 9 || (int) s[i] - '0' < 0) {
            throw std::runtime_error("Invalid input");
        }
        q = q*10 + (int) s[i] - '0';
    }
    if (s[j] == '-') p = -p;
    a = Rational(p, q);
    return in;
}

ostream& operator << (std::ostream &os, const Rational &a) {
    return os << a.toString();
}

Rational Rational::operator+() const{
    return *this;
}


Rational operator-(const Rational &left, const Rational &r) {
    Rational result = left;
    result -= r;
    return result;
}

Rational &Rational::operator+=(const Rational &right) {
    *this = Rational(this->nominator * right.denominator + this->denominator * right.nominator,
                     this->denominator * right.denominator);
    Check(*this);
    return *this;
}

Rational &Rational::operator-=(const Rational &right) {
    *this = Rational(this->nominator * right.denominator - this->denominator * right.nominator,
                     this->denominator * right.denominator);
    Check(*this);
    return *this;
}

Rational &Rational::operator=(const Rational &right) {
    if (this == &right) {
        return *this;
    }
    this->nominator = right.nominator;
    this->denominator = right.denominator;
    Check(*this);
    return *this;
}

Rational Rational::operator-() {
    Rational res = *this;
    res.nominator = -this->nominator;
    Check(res);
    return res;
}

bool operator==(const Rational &left, const Rational &right) {
    return !(left > right) && !(left < right);
}

bool operator>(const Rational &left, const Rational &right) {
    return left.nominator * right.denominator > left.denominator * right.nominator;
}

bool operator<(const Rational &left, const Rational &right) {
    return right > left;
}

bool operator<=(const Rational &left, const Rational &right) {
    return left < right || left == right;
}

bool operator>=(const Rational &left, const Rational &right) {
    return left == right || left > right;
}

Rational& Rational::operator++() {
    return *this += 1;
}

Rational Rational::operator++(int){
    Rational old_value = *this;
    *this += 1;
    Check(*this);
    return old_value;
}

Rational& Rational::operator--() {
    return *this -= 1;
}

Rational Rational::operator--(int) {
    Rational old_value = *this;
    *this -= 1;
    Check(*this);
    return old_value;
}

Rational operator/(const Rational &left, const Rational &right) {
    Rational res = left;
    res /= right;
    return res;
}

Rational operator*(const Rational &left, const Rational &right) {
    Rational res = left;
    res *= right;
    return res;
}

Rational &Rational::operator*=(const Rational &right) {
    *this = Rational(this->nominator * right.nominator, this->denominator * right.denominator);
    Check(*this);
    return *this;
}

Rational &Rational::operator/=(const Rational &right) {
    if (right == 0) {
        throw Rational::DivideByZero();
    }
    *this = Rational(this->nominator * right.denominator, this->denominator * right.nominator);
    Check(*this);
    return *this;
}

void Rational::reduce(Rational &r) {
    if (r.nominator != 0) {
        BigInteger num_first;
        num_first = BigInteger::abs1(r.nominator);
        BigInteger num_second = r.denominator;
        if (num_second > num_first) {
            swap(num_first, num_second);
        }
        while (num_first % num_second) {
            num_first = num_first % num_second;
            swap(num_first, num_second);
        }
        r.nominator = r.nominator / num_second;
        r.denominator = r.denominator / num_second;
    } else {
        r.denominator = 1;
    }
}

void Rational::Check(Rational &r) {
    if (r.denominator < 0){
        r.nominator *= -1;
        r.denominator *= -1;
    }
    if (r.nominator == 0) r.denominator = 1;
    reduce(r);
}

Rational::Rational(const BigInteger &p, const BigInteger &q) {
    nominator = p;
    denominator = q;
    if (q == 0)
        throw DivideByZero();
    Check(*this);
}

Rational::Rational(const BigInteger &i) {
    nominator = i;
    denominator = 1;
}

Rational::Rational(const int &i) {
    nominator = i;
    denominator = 1;
}

Rational::operator bool() const {
    return this->nominator != 0;
}

string Rational::toString() const {
    if (this->denominator == 1)
        return this->nominator.toString();
    string s =  this->nominator.toString() + '/' + this->denominator.toString();
    return s;
}

BigInteger Rational::num() {
    return nominator;
}

BigInteger Rational::denum() {
    return denominator;
}

string Rational::asDecimal(size_t precision) const {
    std::string s;
    BigInteger q = 10;
    for (size_t i = 0; i < precision; ++i){
        q *= 10;
    }
    Rational r(5, q);
    if (0 > *this) r = -r;
    r += *this;
    s = (r.nominator / r.denominator).toString() + '.';
    BigInteger left = BigInteger::abs1(r.nominator) % r.denominator;
    for (size_t i = 0; i <= precision; ++i){
        s += ((left * 10) / r.denominator).toString();
        left *= 10;
        left %= r.denominator;
    }
    s.erase(s.size() - 1, 1);
    if (s[s.size() - 1] == '.') {
        s.erase(s.size() - 1, 1);
    }
    if (this->nominator < 0 && s[0] != '-') s = '-' + s;
    return s;
}

Rational::operator double() const {
    string s = this->asDecimal(7);
    double res = 0;
    size_t i = 0;
    if (s[0] == '-') ++i;
    for (; i < s.size() && s[i] != '.'; ++i){
        res = res*10 + (int) s[i] - '0';
    }
    double k = 10;
    if (s[i] == '.') ++i;
    for (; i < s.size(); ++i) {
        res += ((int) s[i] - '0') / k;
        k *= 10;
    }
    if (s[0] == '-') res = -res;
    return res;
}


bool operator!=(const Rational &left, const Rational &right) {
    return !(left == right);
}


