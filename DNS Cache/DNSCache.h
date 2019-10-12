#pragma once
#ifndef DNSCACHE_H
#define DNSCACHE_H
#include <iostream>
#include "DNSRecord.h"
using namespace std;

class DNSCache {
public:

	DNSRecord *dnsArr = nullptr;

	int size;

	int element ;

	void resize();

	bool full() const;

	
public:

	DNSCache();

	~DNSCache();

	DNSCache(const DNSCache& copy);

	DNSCache& operator=(const DNSCache &);

	void add(DNSRecord&);

	char* lookup(const char*) const;

	void flush();

	void print() const;
};

#endif // !DNSCACHE_H