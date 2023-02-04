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

// #include <boost/asio.hpp>
// #include <boost/asio/deadline_timer.hpp>
// #include <boost/date_time/posix_time>
// #include <boost/thread.hpp>
// #include <boost/function.hpp>
// #include <boost/bind/bind.hpp>
// #include <boost/shared_ptr.hpp>
// #include <boost/thread/mutex.hpp>

using namespace std;

string FILENAME;

#define Print(format, args...) 	\
do { \
    fprintf(stdout, "[%s][%d] " format "\n", __FILE__, __LINE__, ##args); \
} while(0) 

typedef struct N {
	int a;
	int b;
	bool operator< (const N &n) const {
		if (a == n.a) {
			return b < n.b;
		}
		return a < n.a;
	}
}N;

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

class Rule {
public:
	Rule(int num) {
		Print("Rule");
	}
	~Rule() {
		Print("~Rule");
	}
};

class Pencil {

};

class Book {
public:
	Book() {
		Print("Book");
	}
	
	// Book(const Book& b) {
	// 	Print("Book Copy");
	// }
	// Book& operator=(const Book& b) {
	// 	Print("Book =");
	// 	return *this;
	// }
	// ~Book() {
	// 	Print("~Book");		
	// }
	// void show() {
	// 	Print("a[%d]", a);
	// }

	int a;
};

typedef struct Tree {
	Tree() {
		Print("Tree ctor");
	}
}Tree;


typedef struct Tool {
	Tool() {
		Print("Tool ctor");
	}
}Tool;


class ListNode : public Tree {
public:
	// ListNode() : Tree(), t() {
	// 	Print("List ctor");
	// }
	int val;
	Tool t;
};

template<typename T>
struct Stu {
	Stu(T t) : num(t){}
	T num;
};

int main() {
	Pretreatment();

	list<int> l;

	vector<int> v;
	for (int i = 0; i < 50; i++) {
		v.push_back(i);
		// Print("%d\t%zu\t%zu", v[i], v.size(), v.capacity());
	}
	int sz = 0;
	sz = distance(v.begin(), v.end());
	Print("%d", sz);
	// Print("%d", v.capacity());


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





