#include <iostream>
typedef long long ll;
using namespace std;


ll divide(ll a, ll k, ll d) {
	if (k == 1) {
		return a % d;
	}
	else if (k % 2 == 0) {
		ll temp = divide(a, ll(k / ll(2)), d);
		return (temp * temp) % d;
	}
	else {
		ll temp = divide(a, ll(k / ll(2)), d);
		return (((temp * temp) % d) * a) % d;
	}
}

int main() {
	ll a, b, d;
	cin >> a >> b >> d;

	ll result = divide(a, b, d);
	cout << result;
}