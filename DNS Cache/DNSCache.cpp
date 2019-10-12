
#include "DNSCache.h"
#include "DNSRecord.h"


DNSCache::DNSCache()
{
	size = 0;
	element = -1;
}

DNSCache::~DNSCache()
{
	delete[] dnsArr;
}

DNSCache::DNSCache(const DNSCache & copy)
{
	dnsArr = new DNSRecord[copy.size];
	for (int i = 0; i < element+1; i++)
	{
		dnsArr[i] = copy.dnsArr[i];
	}
	this->size = copy.size;
	this->element = copy.element;
}

DNSCache & DNSCache::operator=(const DNSCache & copy)
{
	if (this != &copy)
	{
		delete[] dnsArr;
		dnsArr = new DNSRecord[copy.size];
		for (int i = 0; i < element + 1; i++)
		{
			dnsArr[i] = copy.dnsArr[i];
		}
		this->size = copy.size;
		this->element = copy.element;
	}
	return *this;
}

bool DNSCache::full()const
{
	return size == (element+1);
}

void DNSCache::resize() 
{
	if (size == 0) 
	{
		dnsArr = new DNSRecord[1];
		size = 1;
	}
	else 
	{
		DNSRecord* newCache = new DNSRecord[size * 2];
		for (int i = 0; i < size; i++)
		{
			newCache[i] = dnsArr[i];
		}
		delete[] dnsArr;
		dnsArr = new DNSRecord[size * 2];
		for (int i = 0; i < size; i++)
		{
			dnsArr[i] = newCache[i];
		}
		delete[] newCache;
		size *= 2;
	}
}

void DNSCache::add(DNSRecord& a)
{
	if (full())	resize();
	dnsArr[++element] = a;
}

char* DNSCache::lookup(const char* domain) const
{
	for (int i = 0; i < size; i++)
	{
		if (this->dnsArr[i].containsDomain(domain)) {
			return dnsArr[i].ipAddress;
		}
		
	}
	return "No such domain name!";
}
void DNSCache::flush() {
	delete[] dnsArr;
	dnsArr = nullptr;      
	size = 0;
	element = -1;
}

void DNSCache::print()const
{
	if (size == 0)cout << "Trying to print empty cache!" << endl;
	for (int i = 0; i < element + 1; i++)
	{
		this->dnsArr[i].printR();
	}
}
