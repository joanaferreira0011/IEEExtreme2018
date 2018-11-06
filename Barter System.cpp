    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    #include <set>

    using namespace std;


uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t m)
{
   uint64_t d = 0, mp2 = m >> 1;
   int i;
   if (a >= m) a %= m;
   if (b >= m) b %= m;
   for (i = 0; i < 64; ++i)
   {
       d = (d > mp2) ? (d << 1) - m : d << 1;
       if (a & 0x8000000000000000ULL)
           d += b;
       if (d >= m) d -= m;
       a <<= 1;
   }
   return d;
}

int modInverse(int a, int m) 
{ 
    int m0 = m; 
    int y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        int q = a / m; 
        int t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
}
        
struct rate {
    string a;
    string b;
    unsigned long rate_val;
    bool operator() ( const rate& r ) const
    {
        return r.a == a && r.b == b && r.rate_val == rate_val;
    }
};

bool operator<(const rate& rate1, const rate& rate2) {
    return (rate1.rate_val < rate2.rate_val);
}

bool operator==(const rate& rate1, const rate& rate2) {
    return (rate1.a == rate2.a && rate1.b == rate2.b && rate1.rate_val == rate2.rate_val);
}

    int main() {
        int N, Q;
        cin >> N;

        set<rate> rates; 
        for (int i = 0; i < N; i++) {
            rate r;
            cin >> r.a >> r.b >> r.rate_val;
            rates.insert(r);

            rate r_inverse;
            r_inverse.a = r.b;
            r_inverse.b = r.a;
            r_inverse.rate_val = modInverse(r.rate_val, 998244353);
            rates.insert(r_inverse);
        }
    
        
        for (auto &first : rates) {
            for (auto &second : rates){
                if (first.b == second.a) {
                    rate r;
                    r.a = first.a;
                    r.b = second.b;
                    r.rate_val = mul_mod(first.rate_val, second.rate_val, 998244353);
                    rates.insert(r);
                }
            }
        }

        cin >> Q;
        for (int i = 0; i < Q; i++) {
            string name1, name2;
            cin >> name1 >> name2;

            if (name1 == name2) {
                cout << 1 << endl;
                continue;
            }        

            bool finish = false;
            for (auto &ele: rates) {
                if (ele.a == name1 && ele.b == name2) {
                    cout << ele.rate_val << endl;
                    finish = true;
                    break;
                }
            }

            if (!finish) cout << "-1"  << endl;
        }
        
        // for (auto &first : rates) {
        //     cout << first.a << " " << first.b << endl;
        // }
    }