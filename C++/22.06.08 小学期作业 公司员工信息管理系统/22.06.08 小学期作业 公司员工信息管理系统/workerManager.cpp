#include "employee.h"

//��ʼ������
int Employee::m_EmpNum = 0;

//��ʼ������ָ��
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
			
			break;
		case 3: //�޸�ְ��
			
			break;
		case 4: //����������ְ��

			break;
		case 5: //�����Ҳ���ְ��

			break;
		case 6: //������ͳ��ְ������

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