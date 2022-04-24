//
// Created by dmitrij on 4/24/22.
//

/*long long j = 0;
    while (j < 1000000){
        ++j;
        srand(time(nullptr) / 2);

        long long int a1, b1;
        string s1, s2;
        bool u;
        BigInteger a, b;
        long double p, q, r, s;
        Rational c, d;
        long double k, m;

        a1 = rand() % 1000000;
        b1 = rand() % 1000000;
        if (rand() % 2 == 0) a1 = -a1;
        if (rand() % 2 == 0) b1 = -b1;
        a = a1;
        b = BigInteger(b1);
        s1 = (a + b).toString();
        s2 = to_string(a1 + b1);
        u = true;
        if (s1.size() != s2.size()) u = false;
        for (int i = 0; i < min(s1.size(), s2.size()); ++i){
            if (s1[i] != s2[i]) u = false;
        }
        if (!u) cout << "BI +" << endl;

        a1 = rand() % 1000000;
        b1 = rand() % 1000000;
        if (rand() % 2 == 0) a1 = -a1;
        if (rand() % 2 == 0) b1 = -b1;
        a = a1;
        b = BigInteger(b1);
        s1 = (a - b).toString();
        s2 = to_string(a1 - b1);
        u = true;
        if (s1.size() != s2.size()) u = false;
        for (int i = 0; i < min(s1.size(), s2.size()); ++i){
            if (s1[i] != s2[i]) u = false;
        }
        if (!u) cout << "BI -" << endl;

        a1 = rand() % 1000000;
        b1 = rand() % 1000000;
        if (rand() % 2 == 0) a1 = -a1;
        if (rand() % 2 == 0) b1 = -b1;
        a = a1;
        b = BigInteger(b1);
        s1 = (a * b).toString();
        s2 = to_string(a1 * b1);
        u = true;
        if (s1.size() != s2.size()) u = false;
        for (int i = 0; i < min(s1.size(), s2.size()); ++i){
            if (s1[i] != s2[i]) u = false;
        }
        if (!u) cout << "BI *" << endl;

        a1 = rand() % 1000000;
        b1 = rand() % 1000000;
        if (rand() % 2 == 0) a1 = -a1;
        if (rand() % 2 == 0) b1 = -b1;
        if (b1 == 0) b1 = 1;
        a = a1;
        b = BigInteger(b1);
        s1 = (a / b).toString();
        s2 = to_string(a1 / b1);
        u = true;
        if (s1.size() != s2.size()) u = false;
        for (int i = 0; i < min(s1.size(), s2.size()); ++i){
            if (s1[i] != s2[i]) u = false;
        }
        if (!u) cout << "BI /" << endl;

        a1 = rand() % 1000000;
        b1 = rand() % 1000000;
        if (rand() % 2 == 0) a1 = -a1;
        if (rand() % 2 == 0) b1 = -b1;
        if (b1 == 0) b1 = 1;
        a = a1;
        b = BigInteger(b1);
        s1 = (a % b).toString();
        s2 = to_string(a1 % b1);
        u = true;
        if (s1.size() != s2.size()) u = false;
        for (int i = 0; i < min(s1.size(), s2.size()); ++i){
            if (s1[i] != s2[i]) u = false;
        }
        if (!u) cout << "BI %" << endl;

        a1 = rand() % 1000000;
        b1 = rand() % 1000000;
        if (rand() % 2 == 0) a1 = -a1;
        if (rand() % 2 == 0) b1 = -b1;
        a = a1;
        b = BigInteger(b1);
        a = b++;
        a1 = b1++;
        s1 = (a).toString();
        s2 = to_string(a1);
        u = true;
        if (s1.size() != s2.size()) u = false;
        for (int i = 0; i < min(s1.size(), s2.size()); ++i){
            if (s1[i] != s2[i]) u = false;
        }
        if (!u) cout << "BI++" << endl;

        a1 = rand() % 1000000;
        b1 = rand() % 1000000;
        if (rand() % 2 == 0) a1 = -a1;
        if (rand() % 2 == 0) b1 = -b1;
        a = a1;
        b = BigInteger(b1);
        a = ++b;
        a1 = ++b1;
        s1 = a.toString();
        s2 = to_string(a1);
        u = true;
        if (s1.size() != s2.size()) u = false;
        for (int i = 0; i < min(s1.size(), s2.size()); ++i){
            if (s1[i] != s2[i]) u = false;
        }
        if (!u) cout << "++BI" << endl;

        a1 = rand() % 1000000;
        b1 = rand() % 1000000;
        if (rand() % 2 == 0) a1 = -a1;
        if (rand() % 2 == 0) b1 = -b1;
        a = a1;
        b = BigInteger(b1);
        a = b--;
        a1 = b1--;
        s1 = a.toString();
        s2 = to_string(a1);
        u = true;
        if (s1.size() != s2.size()) u = false;
        for (int i = 0; i < min(s1.size(), s2.size()); ++i){
            if (s1[i] != s2[i]) u = false;
        }
        if (!u) cout << "BI--" << endl;

        a1 = rand() % 1000000;
        b1 = rand() % 1000000;
        if (rand() % 2 == 0) a1 = -a1;
        if (rand() % 2 == 0) b1 = -b1;
        a = a1;
        b = BigInteger(b1);
        a = --b;
        a1 = --b1;
        s1 = a.toString();
        s2 = to_string(a1);
        u = true;
        if (s1.size() != s2.size()) u = false;
        for (int i = 0; i < min(s1.size(), s2.size()); ++i){
            if (s1[i] != s2[i]) u = false;
        }
        if (!u) cout << "--BI" << endl;

        p = rand() % 10000;
        q = rand() % 10000;
        r = rand() % 10000;
        s = rand() % 10000;
        if (rand() % 2) p = -p;
        if (rand() % 2) r = -r;
        if (q == 0) q = 1;
        if (s == 0) s = 1;
        k = p/q;
        m = r/s;
        c = Rational((int) p, (int) q);
        d = Rational((int) r, (int) s);
        s1 = (c + d).asDecimal(6);
        s2 = to_string(k + m);
        u = true;
        if (s1.size() != s2.size()) u = false;
        for (int i = 0; i < min(s1.size(), s2.size()); ++i){
            if (s1[i] != s2[i]) u = false;
        }
        if (!u) cout << "Ra +" << endl;

        p = rand() % 10000;
        q = rand() % 10000;
        r = rand() % 10000;
        s = rand() % 10000;
        if (rand() % 2) p = -p;
        if (rand() % 2) r = -r;
        if (q == 0) q = 1;
        if (s == 0) s = 1;
        k = p/q;
        m = r/s;
        c = Rational((int) p, (int) q);
        d = Rational((int) r, (int) s);
        s1 = (c - d).asDecimal(6);
        s2 = to_string(k - m);
        u = true;
        if (s1.size() != s2.size()) u = false;
        for (int i = 0; i < min(s1.size(), s2.size()); ++i){
            if (s1[i] != s2[i]) u = false;
        }
        if (!u) cout << "Ra -" << endl;

        p = rand() % 10000;
        q = rand() % 10000;
        r = rand() % 10000;
        s = rand() % 10000;
        if (rand() % 2) p = -p;
        if (rand() % 2) r = -r;
        if (q == 0) q = 1;
        if (s == 0) s = 1;
        k = p/q;
        m = r/s;
        c = Rational((int) p, (int) q);
        d = Rational((int) r, (int) s);
        s1 = (c * d).asDecimal(6);
        s2 = to_string(k * m);
        u = true;
        if (s1.size() != s2.size()) u = false;
        for (int i = 0; i < min(s1.size(), s2.size()); ++i){
            if (s1[i] != s2[i]) u = false;
        }
        if (!u) cout << "Ra *" << endl;

        p = rand() % 10000;
        q = rand() % 10000;
        r = rand() % 10000;
        s = rand() % 10000;
        if (rand() % 2) p = -p;
        if (rand() % 2) r = -r;
        if (q == 0) q = 1;
        if (s == 0) s = 1;
        if (r == 0) r = 1;
        k = p/q;
        m = r/s;
        c = Rational((int) p, (int) q);
        d = Rational((int) r, (int) s);
        s1 = (c / d).asDecimal(6);
        s2 = to_string(k / m);
        u = true;
        if (s1.size() != s2.size()) u = false;
        for (int i = 0; i < min(s1.size(), s2.size()); ++i){
            if (s1[i] != s2[i]) u = false;
        }
        if (!u) cout << "Ra /" << endl << s1 << " " << s2;
    }*/
//-42 72 12 15
