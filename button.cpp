#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

/* 	[2015-04-06] Challenge #209 [Easy] The Button can be pressed but once...
   	http://www.reddit.com/r/dailyprogrammer/comments/31ls3h/20150406_challenge_209_easy_the_button_can_be/
   	Input: 
		7
		UserA: 41.04
		UserB: 7.06
		UserC: 20.63
		UserD: 54.28
		UserE: 12.59
		UserF: 31.17
		UserG: 63.04
	Output:
		UserB: 52
		UserE: 54
		UserC: 51
		UserF: 49
		UserA: 50
		UserD: 46
		UserG: 51
*/

using namespace std;

struct User {
	string name;
	double time;
	User(string n, double t) : name(n), time(t) {}
};

bool compareUser(User a, User b) {
	return a.time < b.time; 
}

vector<string> findFlairs(vector<User> users) {
	vector<string> results;
	int last = 0;
	for (int i = 0; i < users.size(); i++) {
		string s = users[i].name + " " + to_string(60-ceil(users[i].time)+last);
		last = ceil(users[i].time);
		results.push_back(s);
	}
	return results;
}

void displayResult(vector<string>result) {
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
}

int main() {
	int count;
	cin >> count;
	vector<User> users;
	string n;
	double t;
	while (count--) {
		cin >> n >> t;
		users.push_back(User(n, t));
	}
	sort(users.begin(), users.end(), compareUser);
	displayResult(findFlairs(users));
	return 0;
}