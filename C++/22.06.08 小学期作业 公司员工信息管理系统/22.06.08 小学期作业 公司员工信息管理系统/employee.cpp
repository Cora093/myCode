#include "employee.h"



//���캯��
Employee::Employee() {

	this->m_ID = 0;
	this->m_Salary = 0;

	Employee::m_EmpNum = this->getEmpNum();
	if (Employee::m_EmpNum <= 0) {
		Employee::m_EmpNum = 0;
	}

	if (Employee::m_EmpNum > 0) {		//���ְ������>0
		//��������
		Employee::m_EmpArray = new Employee* [Employee::m_EmpNum];

		//��ȡ����
		ifstream ifs(FILENAME, ios::in);
		//ifstream ifs(FILENAME, ios::in | ios::binary);	//���ļ�

		int ID;
		char name[20];
		char sex[20];
		char phoneNum[20];
		char dept[20];
		int salary;
		Employee* tmp;

		for (int i = 0; i < Employee::m_EmpNum; i++) {

			ifs >> ID >> name >> sex >> phoneNum >> dept >> salary;
			tmp = new Employee(ID, name, sex, phoneNum, dept, salary);
			this->m_EmpArray[i] = tmp;
			 
			 
			//ifs.read((char*)Employee::m_EmpArray, sizeof(Employee));

		}
		
		//�ر��ļ�
		ifs.close();

	}
}

Employee::Employee(int id, char name[20], char sex[20], char phoneNum[20], char dept[20], int salary) {
	this->m_ID = id;
	strcpy(this->m_Name, name);
	strcpy(this->m_Sex, sex);
	strcpy(this->m_PhoneNumber, phoneNum);
	strcpy(this->m_Department, dept);
	this->m_Salary = salary;
}

//��������
Employee::~Employee() {
	cout << "����" << endl;
	if (Employee::m_EmpArray != NULL) {
		Employee::m_EmpArray = NULL;
		Employee::m_EmpNum = 0;
	}

}

//�˳�ϵͳ
void Employee::exitSys() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0); //�˳�����
}

//����ְ��
void Employee::addEmp() {
	cout << "���������������" << endl;
	int addNum = 0;				//�������
	cin >> addNum;

	if (addNum > 0) {			//������������ȷ
		//ʵ����ӹ���
		//������Ӻ�Ŀռ��С
		int newSize = this->getEmpNum() + addNum;

		//�����¿ռ�
		Employee** newSpace = new Employee* [newSize];

		//����ԭ������
		if (Employee::m_EmpArray != NULL) {
			for (int i = 0; i < newSize; i++) {
				newSpace[i] = Employee::m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++) {
			int ID;
			char name[20];
			char sex[20];
			char phoneNum[20];
			char dept[20];
			int salary;


			cout << "�������" << i + 1 << "����ְ�����:" << endl;
			cin >> ID;
			cout << "�������" << i + 1 << "����ְ������:" << endl;
			cin >> name;
			cout << "�������" << i + 1 << "����ְ���Ա�:" << endl;
			cin >> sex;	
			cout << "�������" << i + 1 << "����ְ���绰����:" << endl;
			cin >> phoneNum;			
			cout << "�������" << i + 1 << "����ְ������:" << endl;
			cin >> dept;
			cout << "�������" << i + 1 << "����ְ������:" << endl;
			cin >> salary;

			newSpace[this->getEmpNum() + i] = new Employee(ID, name, sex, phoneNum, dept, salary);
		}

		//�ͷ�ԭ�пռ�
		delete[] Employee::m_EmpArray;

		//����ָ��ָ���¿ռ�
		Employee::m_EmpArray = newSpace;

		//�����µ�ְ������
		Employee::m_EmpNum = newSize;

		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ����" << endl;


		//���浽�ļ�
		save();
	}
	else {
		cout << "�����������" << endl;
	}

	//����������� ����
	this->cls();
}


//ɾ��ְ��
void Employee::delEmp() {
	//�ж������Ƿ�Ϊ��
	if (this->getEmpNum() == 0) {
		cout << "����Ϊ��" << endl;
	}
	else {
		//������
		cout << "������Ҫɾ����ְ�����:" << endl;
		int id = 0;
		cin >> id;

		//��Ų�����
		if (this->isExist(id) == -1) {
			cout << "�޴˱�ŵ�Ա��" << endl;
		}
		//��Ŵ���
		else {
			//��ʾ��Ϣ
			this->m_EmpArray[this->isExist(id)]->showInfo();

			//�û�ȷ��
			cout << "�Ƿ�Ҫɾ����Ա��:1/0" << endl;
			bool choice = true;
			cin >> choice;

			if (choice) {
				//ɾ����Ա��
				//������Ա������Ϣǰ�Ƹ���
				for (int i = this->isExist(id); i < this->getEmpNum() - 1; i++) {
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}

				//�����Ա����-1
				Employee::m_EmpNum--;

				//����ͬ�����µ��ļ���
				this->save();

				cout << "ɾ���ɹ�!" << endl;
			}
			else {
				cout << "ȡ������" << endl;
			}
		}
	}
	this->cls();
}

//�޸�ְ��
void Employee::modEmp() {

	//�ж������Ƿ�Ϊ��
	if (Employee::m_EmpNum == 0) {
		cout << "����Ϊ��" << endl;
	}
	else {
		//������
		cout << "������Ҫ�޸ĵ�ְ�����:" << endl;
		int id = 0;
		cin >> id;

		//��Ų�����
		if (this->isExist(id) == -1) {
			cout << "�޴˱�ŵ�Ա��" << endl;
		}
		//��Ŵ���
		else {
			//��ʾ��Ϣ
			this->m_EmpArray[this->isExist(id)]->showInfo();

			//�û�ȷ��
			cout << "�Ƿ�Ҫ�޸Ĵ�Ա��:1/0" << endl;
			bool choice = true;
			cin >> choice;

			if (choice) {
				//�޸ĸ�Ա��

				int newID;
				char newName[20];
				char newSex[20];
				char newPhoneNum[20];
				char newDept[20];
				int newSalary;

				//������Ϣ
				cout << "��������ĺ��Ա�����:" << endl;
				cin >> newID;
				cout << "��������ĺ��Ա������:" << endl;
				cin >> newName;
				cout << "��������ĺ��Ա���Ա�:" << endl;
				cin >> newName;
				cout << "��������ĺ��Ա���绰����:" << endl;
				cin >> newPhoneNum;
				cout << "��������ĺ��Ա������:" << endl;
				cin >> newDept;
				cout << "��������ĺ��Ա������:" << endl;
				cin >> newSalary;

				
				Employee* tmp = NULL;
				tmp = new Employee(newID, newName, newSex, newPhoneNum, newDept, newSalary);

				//д������
				this->m_EmpArray[this->isExist(id)] = tmp;

				//delete tmp;

				//����ͬ�����µ��ļ���
				this->save();

				cout << "���ĳɹ�!" << endl;
			}
			else {
				cout << "ȡ������" << endl;
			}
		}
	}

	this->cls();
}


//ͨ����������
void Employee::resByName() {
	//�ж������Ƿ�Ϊ��
	if (Employee::m_EmpNum == 0) {
		cout << "����Ϊ��" << endl;
	}
	else {
		cout << "��������ҵ�ְ��������" << endl;
		char str[20];
		cin >> str;

		bool flag = false;  //���ҵ��ı�־

		//�����������
		for (int i = 0; i < this->getEmpNum(); i++) {
			if (strcmp(str, this->m_EmpArray[i]->m_Name) == 0) {
				cout << "���ҳɹ�,��Ϣ���£�" << endl;
				flag = true;
				this->m_EmpArray[i]->showInfo();
				break;
			}
		}
		if (flag == false) {
			//���޴���
			cout << "����ʧ�ܣ����޴���" << endl;
		}
	}
	this->cls();
}


//ͨ����Ų���
void Employee::resByNum() {
	//�ж������Ƿ�Ϊ��
	if (Employee::m_EmpNum == 0) {
		cout << "����Ϊ��" << endl;
	}
	else {
		cout << "��������ҵ�ְ����ţ�" << endl;
		int tmp = 0;
		cin >> tmp;

		bool flag = false;  //���ҵ��ı�־

		//�����������
		for (int i = 0; i < this->getEmpNum(); i++) {
			if (tmp == this->m_EmpArray[i]->m_ID) {
				cout << "���ҳɹ�,��Ϣ���£�" << endl;
				flag = true;
				this->m_EmpArray[i]->showInfo();
				break;
			}
		}
		if (flag == false) {
			//���޴���
			cout << "����ʧ�ܣ����޴���" << endl;
		}
	}
	this->cls();
}

//���㲿��ƽ������
void Employee::calSalary() {
	//�ж������Ƿ�Ϊ��
	if (Employee::m_EmpNum == 0) {
		cout << "����Ϊ��" << endl;
	}
	else {
		cout << "������Ҫ����ĵĲ������ƣ�" << endl;
		char str[20];
		cin >> str;

		bool flag = false;  //���ҵ��ı�־
		int sum = 0;
		int num = 0;

		//�����������
		for (int i = 0; i < Employee::m_EmpNum; i++) {
			if (strcmp(str, this->m_EmpArray[i]->m_Department) == 0) {

				flag = true;
				sum += this->m_EmpArray[i]->m_Salary;
				num++;
			}
		}
		if (flag == true) {
			cout << "�ò��ŵ�ƽ������Ϊ��" << sum/num << endl;
		}
		else {
			cout << "����ʧ�ܣ����Ų�����" << endl;
		}
	}
	this->cls();
}


//��ʾ����ְ����Ϣ
void Employee::showEmp(){
	if (getEmpNum() > 0) {
		for (int i = 0; i < getEmpNum(); i++) {
			m_EmpArray[i]->showInfo();
		}
	}
	else {
		cout << "��ְ����Ϣ" << endl;
	}


	this->cls();
}




//�ж�ְ���Ƿ����
//�����򷵻����������е�λ�ã����򷵻�-1
int Employee::isExist(int ID) {
	int index = -1;

	for (int i = 0; i < this->getEmpNum(); i++) {
		if (ID == Employee::m_EmpArray[i]->m_ID) {
			//����ҵ�
			index = i;
			break;
		}
	}
	return index;
}








//��ʾ�˵�
void Employee::showMenu(){
	cout << "********************************************" << endl;
	cout << "******  ��ӭʹ�ù�˾Ա����Ϣ����ϵͳ *******" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.ɾ��ְ����Ϣ  *************" << endl;
	cout << "*************  3.�޸�ְ����Ϣ  *************" << endl;
	cout << "**********  4.����������ְ����Ϣ  **********" << endl;
	cout << "**********  5.�����Ҳ���ְ����Ϣ  **********" << endl;
	cout << "********  6.������ͳ��ְ��ƽ������  ********" << endl;
	cout << "***********  7.�鿴����ְ����Ϣ  ***********" << endl;
	cout << "*************  0.�˳�����ϵͳ  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//��ʾĳԱ����Ϣ
void Employee::showInfo() {

	cout << "���ţ� " << this->m_ID
		<< " \t������ " << this->m_Name
		<< " \t�Ա�" << this->m_Sex
		<< " \t�ֻ����룺" << this->m_PhoneNumber
		<< " \t���ң�" << this->m_Department
		<< " \t���ʣ�" << this->m_Salary
		<< endl;

}

//�����ļ�
void Employee::save() {
	//�������ļ�д��
	ofstream ofs;

	//д���Ա����
	ofs.open(FILENAME, ios::out);
	//ofs.open(FILENAME, ios::out | ios::binary);

	for (int i = 0; i < Employee::m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_ID 
			<< this->m_EmpArray[i]->m_Name 
			<< this->m_EmpArray[i]->m_Sex 
			<< this->m_EmpArray[i]->m_PhoneNumber 
			<< this->m_EmpArray[i]->m_Department 
			<< this->m_EmpArray[i]->m_Salary << endl;
		 
		//ofs.write((const char*)m_EmpArray[i], sizeof(Employee));
	}

	ofs.close();

	//д��ְ������
	ofs.open(EMPNUM, ios::binary);
	ofs.write((const char*)&m_EmpNum, sizeof(int));
	ofs.close();

}

//��ȡ�ļ��е�ְ������
int Employee::getEmpNum() {
	ifstream ifs(EMPNUM, ios::binary);
	int tmp;
	ifs.read((char*)&tmp, sizeof(int));
	ifs.close();
	if (tmp < 0) {
		tmp = 0;
	}
	return tmp;
}

//����������� ����
void Employee::cls() {
	system("pause");
	system("cls");
}