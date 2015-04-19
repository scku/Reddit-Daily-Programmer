#include <iostream>

/* [2015-04-13] Challenge #210 [Easy] intHarmony.com
 * http://www.reddit.com/r/dailyprogrammer/comments/32goj8/20150413_challenge_210_easy_intharmonycom/
 */

using namespace std;

double intHarmony (unsigned int a, unsigned int b) {
	int count = 0;
	int c = a ^ ~b;
	for (int i = 0; i < 32; i++) {
		count += c & 1;
		c = c >> 1;
	}
	cout << count*100/32.0 << "% Compability" << endl;
	cout << a << " should avoid " << ~a << endl;
	cout << b << " shoudl avoid " << ~b << endl;
	return cout*100/32.0;
}

int main() {
	intHarmony(100, 42);
	intHarmony(20, 65515);
	intHarmony(999, 999);
	return 0;
}