#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

#include <iostream>
#include <thread>
#include <queue>
#include <list>
#include <vector>

#include <string>

#include "list.h"

using namespace std;

string FILENAME;

#ifndef Print
#define Print(format, args...) 	\
do { \
	fprintf(stdout, "[%s][%d] " format "\n", __FILE__, __LINE__, ##args); \
} while(0) 
#endif


void dealSignal(int signum) {
	if (signum == SIGTERM) {
		Print("signum is term!");
	} else if (signum == SIGALRM) {
		Print("signum is alrm!");		
	}
}

void Pretreatment() {
	Print("running...");
	string f = __FILE__;
	if (f.rfind("/") != f.npos) {
		FILENAME = f.substr(f.rfind("/") + 1, f.size() - 1 - f.rfind("/"));
	}
}

class Base {
public:
	Base() {
		Print("Base");
	}
	virtual ~Base() {
		Print("~ Base");
	}
	virtual void show() {
		Print("Base show");
	}
};

class Derive : public Base {
public:
	Derive() : d_m(0){
		Print("Derive");
	}
	virtual ~Derive() {
		Print("~ Derive");
	}
	virtual void show() {
		Print("Derive show");
		Print("d_m %d", d_m);
	}
	virtual void test() {
		Print("Derive test");
	}
	int d_m;
};

class Book {
public:
	Book() : a(0) {
		Print("Book ctor");
	}
	Book(int a) : a(a) {
		Print("Book param ctor");
	}
	Book(const Book& b) : a(b.a) {
		Print("Book copy ctor");
	}
	~Book() {
		Print("~Book %d", a);		
	}

	int a;
};

int main() {
	Pretreatment();

	ds::List<Book> l;
	for (int i = 0; i < 1; i++) {
		l.push_back(Book(i));
	}
	// l.traversal();


	// ds::List<Book> l;
	// for (int i = 4; i < 10; ++i) {
	// 	l.push_front(Book(i));
	// }
	// l.traversal();
	// auto a = l.begin();
	// Print("%d", (*a).a);

	// ds::List l;
	// for (int i = 0; i < 4 ; i++) {
	// 	l.push_back(i);
	// }
	// l.traversal();
	// for (int i = 0; i < 10; i++) {
	// 	l.insert(i, 100);
	// }
	// l.traversal();


	// Derive *d = new Derive();
	// Base *b = new Base();
	// delete d;
	// d = dynamic_cast<Derive *>(b);
	// // d = static_cast<Derive *>(b);
	// if (d != nullptr) {
	// 	Print("not nullptr");
	// 	d->show();
	// 	d->test();
	// 	delete d;
	// } else {
	// 	Print("nullptr");
	// }

	return 0;
}





