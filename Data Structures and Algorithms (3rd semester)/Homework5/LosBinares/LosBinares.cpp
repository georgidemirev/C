// DIS3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
	}
};

Node* add(Node* root, int data) {
	if (root == NULL) {
		return new Node(data);
	}
	if (data < root->data)
		root->left = add(root->left, data);
	else if (data > root->data)
		root->right = add(root->right, data);
	return root;
}

int getDistanceFromRootToNumber(Node* root, int& counter, int number) {
	if (root->data == number) {
		return counter;
	}
	if (root->left == NULL && root->right == NULL) {
		return -1;
	}

	if (root->data > number && root->left != NULL) {
		counter++;
		return getDistanceFromRootToNumber(root->left, counter, number);
	}
	else if (root->data < number && root->right != NULL) {
		counter++;
		return getDistanceFromRootToNumber(root->right, counter, number);
	}

	return -1;
}

int main() {
	int n, k;
	cin >> n >> k;
	int t; cin >> t;
	Node* root = new Node(t);
	for (int i = 0; i<n - 1; i++) {
		cin >> t;
		add(root, t);
	}
	int* addresses = new int[k];
	for (int i = 0; i<k; i++) {
		cin >> addresses[i];
	}

	for (int i = 0; i<k; i++) {
		int counter = 0;
		cout << getDistanceFromRootToNumber(root, counter, addresses[i]) << endl;
	}

	return 0;
}

