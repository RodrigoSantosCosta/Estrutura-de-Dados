#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{

	int t;
	cin >> t;
	string e[t];
	string resultado[t];

	for (int i = 0; i < t; ++i) {
		cin >> e[i];
	}


	for (int i = 0; i < t; ++i) {
		stack<char> s;


		for (string::iterator it = e[i].begin(); it != e[i].end(); ++it) {

			if (*it == '^' || *it == '(') {
				s.push(*it);
			} else
			if (*it == '*' || *it == '/') {
				if (s.top() != '^')
					s.push(*it);
			} else
			if (*it == '+' || *it == '-') {
				if (s.top() != '^' && s.top() != '*' && s.top() != '/')
					s.push(*it);
			} else
			if (*it == ')') {

				while (s.top() != '(') {
					resultado[i] += s.top();
					s.pop();
				}

				s.pop();
			} else {

				resultado[i] += *it;
			}
		}


		while (!s.empty()) {
			resultado[i] += s.top();

			s.pop();
		}
	}


	for (int i = 0; i < t; ++i) {
		cout << resultado[i];

		if (i != t-1) {
			cout << endl;
		}
	}

	return 0;
}
