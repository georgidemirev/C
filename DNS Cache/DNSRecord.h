#pragma once
#ifndef DNSRECOR_H
#define DNSRECOR_H
#include <iostream>
using namespace std;

class DNSRecord {
public:
	char* domainName = nullptr;

	char* ipAddress = nullptr;

	DNSRecord();

	DNSRecord(char* , char*);

	DNSRecord& operator=(const DNSRecord&);

	void setDomain(char*);

	void setIP(char*);

	DNSRecord(const DNSRecord& copy) ;

	~DNSRecord();

	void read();

	bool containsDomain(const char* domain) const;

	void printR() const;
};

#endif // !DNSRECOR_H