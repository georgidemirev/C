// SDA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_map> 
#include <string>
//#include <bits/stdc++.h>
using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int n; cin >> n;
	int m; cin >> m;

	unordered_map<string, int> words;

	for (int q = 0; q < n; q++) {
		string p; cin >> p;
		int wordLength = p.length();

		while (wordLength >= 1) {
			string i = p.substr(0, wordLength);
			words[i] += 1;
			wordLength--;
		}
	}

	for (int i = 0; i < m; i++) {
		string prefix; cin >> prefix;
		if (words.find(prefix) != words.end()) {
			cout << (words.at(prefix)) << endl;
		}
		else {
			cout << 0 << endl;
		}
	}

	return 0;
}