#include "DNSCache.h"
#include "DNSRecord.h"

DNSRecord::DNSRecord() :domainName(nullptr), ipAddress(nullptr) {}

DNSRecord::DNSRecord(char* domainName, char* ipAddress):domainName(nullptr),ipAddress(nullptr)
{
	setDomain(domainName);
	setIP(ipAddress);
}

DNSRecord & DNSRecord::operator=(const DNSRecord & other)
{
	if (this != &other)
	{
		setDomain(other.domainName);
		setIP(other.ipAddress);
	}
	return *this;
}

void DNSRecord::setDomain(char* _name)
{
	if (_name == nullptr)_name = "";
	int len = strlen(_name) + 1;
	delete[] this->domainName;
	domainName = new char[len];
	strcpy_s(domainName, len, _name);
}

void DNSRecord::setIP(char* _name)
{
	if (_name == nullptr)_name = "";
	int len = strlen(_name) + 1;
	delete[] this->ipAddress;
	ipAddress = new char[len];
	strcpy_s(ipAddress, len, _name);
}

DNSRecord::DNSRecord(const DNSRecord& copy)
{
	setIP(copy.ipAddress);
	setDomain(copy.domainName);
}

DNSRecord::~DNSRecord()
{
	delete[] domainName;
	domainName = nullptr;
	delete[] ipAddress;
	ipAddress = nullptr;
}

void DNSRecord::read()
{
}

bool DNSRecord::containsDomain(const char * domain) const
{
	return strcmp(domain, this->domainName) == 0;
}

void DNSRecord::printR() const
{
	cout <<endl<< "DNSRecord:\nDomain name: " << domainName << "\nIP address: " << ipAddress << endl ;
}
