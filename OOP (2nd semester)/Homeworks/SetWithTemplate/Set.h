#pragma once
#include <iostream>

template<class T>
class Set {
public:

	T* set = nullptr;

	int capacity = 0;
	int size = 0;

	void setSet(const T* set, const int len) {
		if (this->set != nullptr) delete[] this->set;
		
		this->set = new T[len];
		for (int i = 0; i < len; i++) {
			this->set[i] = set[i];
		}
		capacity = len;
		size = len;
	}

	const T* getSet() const { return this->set; };

	void deleteSet() {
		delete[] set;
		set = nullptr; // tuk vqrno li e ???
	}

	void resize() {
		T* copy = new T[capacity];
		for (int i = 0; i < size; i++) {
			copy[i] = this->set[i];
		}
		delete[] set;
		set = new T[capacity * 2];
		for (int i = 0; i < size; i++) {
			this->set[i] = copy[i];
		}
		delete[] copy;
	}

public:

	Set() {};
	Set(T* set , int len) {
		setSet(set, len);
		capacity = len;
		size = len;
	}
	Set(const Set<T>& p) {
		setSet(p.getSet(), p.size);
		capacity = p.capacity;
		size = p.size;
	}
	Set& operator= (const Set<T>& p) {
		setSet(p.getSet(),p.size);
		capacity = p.capacity;
		size = p.size;
	}
	~Set() { deleteSet(); };

	void insert(const T p) {
		if (size == capacity) resize();
		set[size] = p;
		size++;
	};

	void erase(const T p) {};

	bool contains(const T p) { return false; };

	const int getSize() const { return size; };

	T& operator[](const int p) {
		return set[p];
	};

	Set& Union(const Set<T>& a, const Set<T>& b) {

		deleteSet();

		T* newT = new T[a.getSize() + b.getSize()];
		int i = 0;
		for (i; i < a.getSize(); i++) {
			newT[i] = a.getSet()[i];
		}
		for (i; i < a.getSize() + b.getSize(); i++) {
			newT[i] = b.getSet()[i - a.getSize()];
		}

		setSet(newT, a.getSize() + b.getSize());
		delete[] newT;

		return *this;
	};

	Set& intersection(const Set<T>& a, const Set<T>& b) { return *this; };//ne e gotovo

		
};