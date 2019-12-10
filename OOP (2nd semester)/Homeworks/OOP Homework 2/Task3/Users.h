#pragma once
#include <iostream>
using namespace std;

class Guest {
private:

	char* ip;

public:

	Guest();
	Guest(char*);
	Guest(const Guest&);
	Guest& operator=(const Guest&);
	~Guest();

	char* getIP()const;

	void setIP(char*);
};

class User :public Guest {
private:

	char* username;
	char* password;
	char* title;
	
	char* encrypt();
	char* decrypt()const;

	bool verifyPass(char*);

protected:

	char* getPass()const;

	void setPass(char*);
	void setTit(char*);
	void setUs(char*);
	void setIP(char*);

public:	

	User();
	User(char*,char*,char*,char*);
	User(const User&);
	User& operator=(const User&);
	~User();

	char* getIP() const;
	char* getUs()const;
	char* getTit()const;

	void changePass(char*,char*);

	friend class Admin;
};

class PowerUser :public User {
private:

	int reputation;

protected:
	
	char* getPass()const;

	void setTit(char*);
	void setRep(int);
	void setIP(char*);
	void setUs(char*);

	void setPass(char*);

public:

	PowerUser();
	PowerUser(char*, char*, char*, char*, int);
	PowerUser(const PowerUser&);
	PowerUser& operator=(const PowerUser&);
	~PowerUser();

	char* getIP()const;
	char* getUs()const;
	char* getTit()const;
	int getRep()const;

	void addRep();

	void changePass(char*, char*);

	void giveReputation(PowerUser&);

	friend class Admin;

};

class VIP : public User {
protected:

	char* getPass()const;

	void setPass(char*);
	void setUs(char*);
	void setIP(char*);

public:

	VIP();
	VIP(char*, char*, char*, char*);
	VIP(const VIP&);
	VIP& operator=(const VIP&);
	~VIP();

	char* getIP()const;
	char* getUs()const;
	char* getTit()const;

	void setTit(char*);

	void changePass(char*, char*);

	friend class Admin;

};

class Admin : virtual public VIP,virtual public PowerUser {
protected:

	char* getPass()const;

	void setPass(char*);
	void setIP(char*);
	void setRep(int);

public:

	Admin();
	Admin(char*, char*, char*, char*,int);
	Admin(const Admin&);
	Admin& operator=(const Admin&);
	~Admin();

	char* getIP() const;
	char* getUs()const;
	char* getTit()const;
	int getRep()const;

	void setTit(char*);
	void setUs(char*);

	void changePass(char*, char*);

	void changeOtherUsername(User&, char*);

	void giveReputation(PowerUser&);

};
