#include "employee.h"


//ְ������
int Employee::m_EmpNum=0;

//ְ������ָ��
Employee** Employee::m_EmpArray = NULL;

int main() {


	Employee em;

	while (true) {
		em.showMenu();


		cout << "����������ѡ��" << endl;
		int choice = 0;//�洢�û���ѡ��
		cin >> choice;//�����û���ѡ��

		switch (choice) {
		case 0: //�˳�ϵͳ
			em.exitSys();
			break;
		case 1: //���ְ��
			em.addEmp();
			break;
		case 2: //ɾ��ְ��
			em.delEmp();
			break;
		case 3: //�޸�ְ��
			em.modEmp();
			break;
		case 4: //����������ְ��
			em.resByName();
			break;
		case 5: //�����Ҳ���ְ��
			em.resByNum();
			break;
		case 6: //������ͳ��ְ������
			em.calSalary();
			break;
		case 7: //�鿴����Ա����Ϣ
			em.showEmp();
			break;
		default:
			system("cls");
			break;
		}
	}



	system("pause");
	return 0;


}