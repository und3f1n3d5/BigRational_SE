//
// Created by dmitrij on 4/23/22.
//

#include "bigInt.h"

BigInteger operator+(const BigInteger &left, const BigInteger &r) {
    BigInteger result = left;
    result += r;
    return result;
}


istream& operator >> (std::istream &in, BigInteger &a)
{
    string s;
    in >> s;
    a = BigInteger(s);
    return in;
}

ostream& operator << (std::ostream &os, const BigInteger &a)
{
    return os << a.toString();
}


BigInteger BigInteger::operator+() const{
    return *this;
}


BigInteger operator-(const BigInteger &left, const BigInteger &r) {
    BigInteger result = left;
    result -= r;
    return result;
}

BigInteger &BigInteger::operator+=(const BigInteger &right) {
    BigInteger a = *this, b = right;
    a.is_positive = true;
    b.is_positive = true;
    if (this->is_positive && right.is_positive) {
        *this = Plus(a, b);
        this->is_positive = true;
    }
    else if (!this->is_positive && !right.is_positive){
        *this = Plus(a, b);
        this->is_positive = false;
    }
    else if (this->is_positive && !right.is_positive){
        *this = Minus(a, b);
        this->is_positive = (b <= a);
    }
    else if (!this->is_positive && right.is_positive){
        *this = Minus(a, b);
        this->is_positive = (a <= b);
    }
    this->zeroCheck();
    return *this;
}

BigInteger &BigInteger::operator-=(const BigInteger &right) {
    BigInteger a = *this, b = right;
    a.is_positive = true;
    b.is_positive = true;
    if (this->is_positive == right.is_positive) {
        bool k = (*this > right);
        *this = Minus(abs1(*this), abs1(right));
        this->is_positive = k;
    }
    else if (this->is_positive && !right.is_positive){
        *this = Plus(a, b);
        this->is_positive = true;
    }
    else if (!this->is_positive && right.is_positive){
        *this = Plus(a, b);
        this->is_positive = false;
    }
    this->zeroCheck();
    return *this;
}

BigInteger &BigInteger::operator=(const BigInteger &right) {
    if (this == &right) {
        return *this;
    }
    this->data = right.data;
    this->is_positive = right.is_positive;
    this->zeroCheck();
    return *this;
}

BigInteger BigInteger::operator-() {
    BigInteger res = *this;
    res.is_positive = !this->is_positive;
    res.zeroCheck();
    return res;
}

bool operator==(const BigInteger &left, const BigInteger &right) {
    return !(left > right) && !(left < right);
}

bool operator>(const BigInteger &left, const BigInteger &right) {
    if (left.is_positive){
        if (!right.is_positive) return true;
        if (right.data.size() > left.data.size()) return false;
        if (left.data.size() > right.data.size()) return true;
        for (size_t i = 0; i < left.data.size(); ++i){
            if (left.data[i] < right.data[i]) return false;
            if (left.data[i] > right.data[i]) return true;
        }
        return false;
    }
    else{
        if (right.is_positive) return false;
        if (right.data.size() < left.data.size()) return false;
        if (left.data.size() < right.data.size()) return true;
        for (size_t i = 0; i < left.data.size(); ++i){
            if (left.data[i] > right.data[i]) return false;
            if (left.data[i] < right.data[i]) return true;
        }
        return false;
    }
}

bool operator<(const BigInteger &left, const BigInteger &right) {
    return right > left;
}

bool operator<=(const BigInteger &left, const BigInteger &right) {
    return left < right || left == right;
}

bool operator>=(const BigInteger &left, const BigInteger &right) {
    return left == right || left > right;
}

BigInteger& BigInteger::operator++() {
    return *this += 1;
}

BigInteger BigInteger::operator++(int) {
    BigInteger old_value = *this;
    *this += 1;
    this->zeroCheck();
    return old_value;
}

BigInteger& BigInteger::operator--() {
    return *this -= 1;
}

BigInteger BigInteger::operator--(int) {
    BigInteger old_value = *this;
    *this -= 1;
    this->zeroCheck();
    return old_value;
}

BigInteger operator/(const BigInteger &left, const BigInteger &right) {
    BigInteger res = left;
    res /= right;
    return res;
}

BigInteger operator*(const BigInteger &left, const BigInteger &right) {
    BigInteger res = left;
    res *= right;
    return res;
}

BigInteger &BigInteger::operator*=(const BigInteger &right) {
    if (this->data.size() == 1 && right.data.size() == 1){
        bool k = (this->is_positive == right.is_positive);
        *this = BigInteger(to_string(this->data[0] * right.data[0]));
        this->is_positive = k;
        this->zeroCheck();
        return *this;
    }
    if (this->data.empty() || right.data.empty() || *this == 0 || right == 0) {
        *this = 0;
        return *this;
    }
    if (right.data.size() == 1){
        return Multiply(*this, right);
    }
    if (this->data.size() == 1){
        BigInteger tmp = right;
        *this = Multiply(tmp, *this);
        return *this;
    }
    bool k = (this->is_positive == right.is_positive);
    BigInteger A0, B0;          // A0 = A[0 : A.size()/2]  B0 = B[0 : B.size()/2]
    for (size_t i = 0; i < this->data.size() / 2; ++i){
        A0.data.push_back(this->data[i]);
    }
    for (size_t i = 0; i < right.data.size() / 2; ++i){
        B0.data.push_back(right.data[i]);
    }
    BigInteger A1, B1;          // A1 = A[A.size()/2 : end_of_A]  B1 = B[B.size()/2 : end_of_B]
    for (size_t i = this->data.size() / 2; i < this->data.size(); ++i){
        A1.data.push_back(this->data[i]);
    }
    for (size_t i = right.data.size() / 2; i < right.data.size(); ++i){
        B1.data.push_back(right.data[i]);
    }
    size_t a = A1.data.size(), b = B1.data.size();
    A0.zeroCheck();
    A1.zeroCheck();
    B0.zeroCheck();
    B1.zeroCheck();
    BigInteger C0 = A0 * B0, C1 = A0 * B1, C2 = A1 * B0;
    for (size_t i = 0; i < b; ++i) {
        C2.data.push_back(0);
        C0.data.push_back(0);
    }
    for (size_t i = 0; i < a; ++i) {
        C1.data.push_back(0);
        C0.data.push_back(0);
    }
    *this = A1 * B1 + C0 + C1 + C2;
    this->is_positive = k;
    this->zeroCheck();
    return *this;
}

BigInteger &BigInteger::operator/=(const BigInteger &right) {
    if (right == 0) {
        throw BigInteger::DivideByZero();
    }
    bool k = (this->is_positive && right.is_positive) or (!this->is_positive && !right.is_positive);
    BigInteger res;
    BigInteger curValue;
    for (int j : this->data) {
        if (curValue < abs1(right)) curValue.data.push_back(j);
        else break;
    }
    size_t i = curValue.data.size();
    do {
        curValue.zeroCheck();
        int mid;
        int l_border = 0;
        int r_border = Base;
        while (l_border < r_border - 1) {
            mid = (l_border + r_border) / 2;
            BigInteger cur = abs1(right) * mid;
            if (cur <= curValue) {
                l_border = mid;
            } else {
                r_border = mid;
            }
        }
        res.data.push_back(l_border);
        curValue -= abs1(right) * l_border;
        if (i < this->data.size())curValue.data.push_back(this->data[i]);
        ++i;
    } while (i <= this->data.size());
    res.zeroCheck();
    *this = res;
    this->is_positive = k;
    this->zeroCheck();
    return *this;
}



BigInteger operator%(const BigInteger &left, const BigInteger &right) {
    BigInteger res = left;
    res %= right;
    return res;
}


BigInteger &BigInteger::operator%=(const BigInteger &right) {
    BigInteger res;
    *this -= (*this / right) * right;
    this->zeroCheck();
    return *this;
}

void BigInteger::zeroCheck() {
    int zeros = 0;
    bool is_zero = true;
    for (size_t i = 0; i < this->data.size(); ++i){
        if (data[i] == 0) ++zeros;
        else {
            is_zero = false;
            break;
        }
    }
    if (is_zero) {
        this->data.resize(1, 0);
        this->is_positive = true;
    }
    else if (zeros){
        vector <int> new_data;
        for (size_t i = zeros; i < this->data.size(); ++i){
            new_data.push_back(this->data[i]);
        }
        this->data = new_data;
    }
}

BigInteger BigInteger::Plus(const BigInteger &a, const BigInteger &b) {
    BigInteger result, left, right;
    if (a > b) {
        left = b;
        right = a;
    }
    else {
        left = a;
        right = b;
    }
    result.data.resize(max(left.data.size(), right.data.size()));
    int k = 0;
    size_t i;
    for (i = 0; i < left.data.size(); ++i) {
        result.data[result.data.size() - i - 1] =
                (left.data[left.data.size() - i - 1] + right.data[right.data.size() - i - 1] + k) % Base;
        k = (left.data[left.data.size() - i - 1] + right.data[right.data.size() - i - 1] + k) / Base;
    }
    while (i < result.data.size()) {
        result.data[result.data.size() - i - 1] = (right.data[right.data.size() - i - 1] + k) % Base;
        k = (right.data[right.data.size() - i - 1] + k) / Base;
        i += 1;
    }
    if (k > 0)
        result.data.insert(result.data.begin(), k);
    return result;
}

BigInteger BigInteger::Minus(const BigInteger &a, const BigInteger &b) {
    BigInteger result, left, right;
    if (a > b) {
        left = b;
        right = a;
    }
    else {
        left = a;
        right = b;
    }
    result.data.resize(right.data.size());
    int k = 0;
    size_t i;
    for (i = 0; i < left.data.size(); ++i) {
        result.data[result.data.size() - i - 1] =
                (Base + right.data[right.data.size() - i - 1] - left.data[left.data.size() - i - 1] + k) % Base;
        k = (right.data[right.data.size() - i - 1] - left.data[left.data.size() - i - 1] + k);
        if (k < 0) k = -1;
        else k = 0;
    }
    while (i < result.data.size()) {
        result.data[result.data.size() - i - 1] = (Base + right.data[right.data.size() - i - 1] + k) % Base;
        k = (right.data[right.data.size() - i - 1] + k);
        if (k < 0) k = -1;
        else k = 0;
        i += 1;
    }
    if (k > 0)
        result.data.insert(result.data.begin(), abs(k));
    return result;
}

BigInteger &BigInteger::Multiply(BigInteger &a, const BigInteger &b) {
    a.is_positive = (a.is_positive == b.is_positive);
    int k = 0, m;
    for (size_t i = 0; i < a.data.size(); ++i) {
        m = (a.data[a.data.size() - i - 1] * b.data[0] + k) / Base;
        a.data[a.data.size() - i - 1] = (a.data[a.data.size() - i - 1] * b.data[0] + k) % Base;
        k = m;
    }
    if (k > 0){
        vector <int> tmp;
        tmp.push_back(k);
        for (int i : a.data){
            tmp.push_back(i);
        }
        a.data = tmp;
    }
    a.zeroCheck();
    return a;
}

BigInteger::BigInteger(const string &s) {
    is_positive = (s[0] != '-');
    for (auto i : s) {
        if (i == '-') continue;
        data.push_back((int) i - '0');
    }
    this->zeroCheck();
}

BigInteger::BigInteger(const int &j) {
    is_positive = (j >= 0);
    int res = abs(j);
    while (res > 0){
        data.push_back(res % 10);
        res /= 10;
    }
    if (data.empty()) data.push_back(0);
    for (size_t i = 0; i < data.size()/2; ++i) {
        swap(data[i], data[data.size() - i - 1]);
    }
    this->zeroCheck();
}

BigInteger BigInteger::abs1(const BigInteger &a) {
    BigInteger res = a;
    res.is_positive = true;
    return res;
}

BigInteger::operator bool() const {
    vector <int> z(1, 0);
    return !(this->data == z);
}

string BigInteger::toString() const {
    string s = (this->is_positive ? "" : "-" );
    for(int i : this->data)
        s += (to_string(i));
    if(this->data.empty()) s += '0';
    return s;
}

bool operator!=(const BigInteger &left, const BigInteger &right) {
    return !(left == right);
}