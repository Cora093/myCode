#include "workerManager.h"


//���캯��
WorkerManager::WorkerManager() {

	//1.���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//���ļ�
	if (!ifs.is_open()) {			//δ�򿪳ɹ���˵���ļ�������
		this->m_EmpNum = 0;			//��ʼ������
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	} 

	//2.���ļ����� ������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {				//�ж��ļ��Ѿ�������

		this->m_EmpNum = 0;			//��ʼ������
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.�ļ������Ҳ�Ϊ��
	this->m_EmpNum = this->getEmpNum();

	//���ٿռ�
	this->m_EmpArray = new Worker* [m_EmpNum];

	//���ļ��е����ݶ���������
	this->initEmp();


}

//��������
WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		delete[] m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

//�˳�ϵͳ
void WorkerManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0); //�˳�����
}

//���ְ��
void WorkerManager::addEmp() {
	cout << "���������������" << endl;
	int addNum = 0;				//�������
	cin >> addNum;
	if (addNum > 0) {			//������������ȷ
		//���
		//������Ӻ�Ŀռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//����ԭ������
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < newSize; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int depID;
			cout << "�������" << i + 1 << "����ְ�����:" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����ְ������:" << endl;
			cin >> name;

			cout << "��ѡ���" << i + 1 << "����ְ����λ:" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> depID;

			Worker* worker = NULL;//��������ָ��

			if (depID == 1) {
				worker = new Employee(id, name, 1);
			}
			else if (depID == 2) {
				worker = new Manager(id, name, 2);
			}
			else if (depID == 3) {
				worker = new Boss(id, name, 3);
			}

			//���浽������
			newSpace[this->m_EmpNum + i] = worker;


		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//����ָ��ָ���¿ռ�
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		this->save();

		//����״̬��ְ���ļ���Ϊ��
		this->m_FileIsEmpty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "����ְ��!" << endl;

	}
	else {//�������������
		cout << "������������" << endl;
	}

	//����������� ����
	system("pause");
	system("cls");
}

//��ʾְ��
void WorkerManager::showEmp() {
	//�ж������Ƿ�Ϊ��
	if (this->m_FileIsEmpty) {
		cout << "����Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			//��̬���ýӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}

	//����������� ����
	system("pause");
	system("cls");
}

//ɾ��ְ��
void WorkerManager::delEmp() {
	//�ж������Ƿ�Ϊ��
	if (this->m_FileIsEmpty) {
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
				for (int i = this->isExist(id); i < this->m_EmpNum - 1; i++) {
					this->m_EmpArray[i] = this->m_EmpArray[i + 1];
				}
				//�����Ա����--
				this->m_EmpNum--;
				//����ͬ�����µ��ļ���
				this->save();

				cout << "ɾ���ɹ�!" << endl;
			}
			else {
				cout << "ȡ������" << endl;
			}
		}
	}

	//����������� ����
	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkerManager::modEmp() {
	//�ж������Ƿ�Ϊ��
	if (this->m_FileIsEmpty) {
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
				string newName;
				int newDepID;
				//������Ϣ
				cout << "��������ĺ��Ա�����:" << endl;
				cin >> newID;
				cout << "��������ĺ��Ա������:" << endl;
				cin >> newName;
				cout << "��������ĺ��Ա�����ű��:" << endl;
				cout << "1.��ְͨ��" << endl;
				cout << "2.����" << endl;
				cout << "3.�ϰ�" << endl;
				cin >> newDepID;

				//��������ָ��
				Worker* worker = NULL;

				//�����������
				if (newDepID == 1) {
					worker = new Employee(newID, newName, 1);
				}
				else if (newDepID == 2) {
					worker = new Manager(newID, newName, 2);
				}
				else if (newDepID == 3) {
					worker = new Boss(newID, newName, 3);
				}


				//д������
				this->m_EmpArray[this->isExist(id)]= worker;

				//����ͬ�����µ��ļ���
				this->save();

				cout << "���ĳɹ�!" << endl;
			}
			else {
				cout << "ȡ������" << endl;
			}
		}
	}

	//����������� ����
	system("pause");
	system("cls");
}


//����ְ��
void WorkerManager::findEmp() {
	//�ж������Ƿ�Ϊ��
	if (this->m_FileIsEmpty) {
		cout << "����Ϊ��" << endl;
	}
	else {
		//ѡ����ҷ�ʽ
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;

		int choice = 0;
		cin >> choice;

		if (choice == 1) {		//��ְ���Ų���
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;

			//�ж��Ƿ����
			int ret = isExist(id);
			if (ret != -1) {
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (choice == 2) {	//����������
			string name;
			cout << "��������ҵ�ְ��������" << endl;
			cin >> name;

			bool flag = false;  //���ҵ��ı�־
			//�����������
			for (int i = 0; i < m_EmpNum; i++){
				if (m_EmpArray[i]->m_Name == name){
					cout << "���ҳɹ�,��Ϣ���£�" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false) {
				//���޴���
				cout << "����ʧ�ܣ����޴���" << endl;
			}
			
		}
		else {
			cout << "�������" << endl;
		}
	}

	//����������� ����
	system("pause");
	system("cls");
}

//����ְ��
void WorkerManager::sortEmp() {
	//�ж������Ƿ�Ϊ��
	if (this->m_FileIsEmpty) {
		cout << "����Ϊ��" << endl;

		//����������� ����
		system("pause");
		system("cls");
	}
	else {
		//����ѡ������
		for (int i = 0; i < this->m_EmpNum; i++) {
			int min = i;//��Сֵ�±�
			for (int j = i + 1; j < this->m_EmpNum; j++) {
				if (this->m_EmpArray[j]->m_ID < this->m_EmpArray[min]->m_ID) {
					min = j;
				}
			}
			if (i != min) {
				Worker* tmp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[min];
				this->m_EmpArray[min] = tmp;
			}
		}
		this->save();

		//��ʾ������
		cout << "����ɹ�����ǰ���Ϊ��" << endl;
		this->showEmp();

	}

}


//����ļ�
void WorkerManager::clenFile() {
	if (this->m_FileIsEmpty) {					//�ж������Ƿ�Ϊ��
		cout << "����Ϊ��" << endl;
	}
	else {
		cout << "�Ƿ�ȷ���������1/0" << endl;
		int choice = 0;
		cin >> choice;

		if (choice == 1) {
			//����ļ�����
			ofstream ofs(FILENAME, ios::trunc);	//ɾ���ļ������´���
			ofs.close();

			//�����������
			if (this->m_EmpArray != NULL) {
				//ɾ��������ÿ��ְ������
				for (int i = 0; i < this->m_EmpNum; i++) {
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}

				//ɾ����������ָ��
				delete[] this->m_EmpArray;
				this->m_EmpArray = NULL;
				this->m_EmpNum = 0;
				this->m_FileIsEmpty = true;
			}

			cout << "��ճɹ�" << endl;

		}
		else {
			cout << "ȡ������" << endl;
		}
	}

	//����������� ����
	system("pause");
	system("cls");
}








//�����ļ�
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	//д�ļ�
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();
}

//��ȡ�ļ��е�Ա������
int WorkerManager::getEmpNum() {

	int ID;
	string name;
	int dID;
	int empNum = 0;

	ifstream ifs;
	ifs.open(FILENAME, ios::in);						//���ļ�
	while (ifs >> ID && ifs >> name && ifs >> dID) {	//��ȡ����
		empNum++;
	}
	ifs.close();										//�ر��ļ�
	return empNum;
}

//��ʼ��Ա��
void WorkerManager::initEmp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int ID;
	string name;
	int dID;

	int index = 0;							//����	
	while (ifs >> ID && ifs >> name && ifs >> dID)
	{
		Worker* worker = NULL;
		//���ݲ�ͬ�Ĳ���Id������ͬ����
		if (dID == 1) {						//1 ��ͨԱ��
			worker = new Employee(ID, name, dID);
		}
		else if (dID == 2) {				//2 ����
			worker = new Manager(ID, name, dID);
		}
		else if (dID == 3) {				//3 �ܲ�
			worker = new Boss(ID, name, dID);
		}
		//�����������
		this->m_EmpArray[index] = worker;

		index++;
	}

	ifs.close();
}

//�ж�ְ���Ƿ����
//�����򷵻����������е�λ�ã����򷵻�-1
int WorkerManager::isExist(int ID) {
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++) {
		if (ID == this->m_EmpArray[i]->m_ID) {
			//����ҵ�
			index = i;
			break;
		}
	}
	return index;
}


//չʾ�˵�
void WorkerManager::showMenu() {
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}





