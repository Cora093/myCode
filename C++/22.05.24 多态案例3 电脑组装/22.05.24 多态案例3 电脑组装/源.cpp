#include<iostream>
using namespace std;

class CPU {
public:
	virtual void calculate() = 0;
};

class VirtualCard {
public:
	virtual void display() = 0;
};

class Memory {
public:
	virtual void storage() = 0;
};

class Computer {
public:
	Computer(CPU* cpu, VirtualCard* vc, Memory* mem) {
		m_CPU = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	~Computer() {
		if (m_CPU != NULL) {
			delete m_CPU;
			m_CPU = NULL;
			cout << "CPU停止工作了" << endl;
		}
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
			cout << "显卡停止工作了" << endl;

		}	
		if (m_mem != NULL) {
			delete m_mem;
			m_mem = NULL;
			cout << "内存停止工作了" << endl;

		}
	}
	void work() {
		cout << "电脑开始工作了" << endl;
		m_CPU->calculate();
		m_vc->display();
		m_mem->storage();
	}

private:
	CPU* m_CPU;
	VirtualCard* m_vc;
	Memory* m_mem;
};

class ICPU :public CPU {
public:
	virtual void calculate() {
		cout << "I的CPU开始工作了" << endl;
	}
};

class IVirtualCard :public VirtualCard {
public:
	virtual void display() {
		cout << "I的显卡开始工作了" << endl;
	}
};

class IMemory :public Memory {
public:
	virtual void storage() {
		cout << "I的内存开始工作了" << endl;
	}
};

class ACPU :public CPU {
public:
	virtual void calculate() {
		cout << "A的CPU开始工作了" << endl;
	}
};

class AVirtualCard :public VirtualCard {
public:
	virtual void display() {
		cout << "A的显卡开始工作了" << endl;
	}
};

class AMemory :public Memory {
public:
	virtual void storage() {
		cout << "A的内存开始工作了" << endl;
	}
};



void test01(){
	Computer* c1=new Computer(new ICPU, new AVirtualCard, new IMemory);
	c1->work();
	delete c1;
	cout << "c1停止工作了" << endl << endl;

	Computer* c2 = new Computer(new ACPU, new AVirtualCard, new AMemory);
	c2->work();
	delete c2;
	cout << "c2停止工作了" << endl << endl;

}

int main() {
	test01();
	system("pause");
	return 0;
}
