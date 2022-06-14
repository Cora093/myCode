#include "employee.h"


//职工人数
int Employee::m_EmpNum=0;

//职工数组指针
Employee** Employee::m_EmpArray = NULL;

int main() {


	Employee em;

	while (true) {
		em.showMenu();


		cout << "请输入您的选择" << endl;
		int choice = 0;//存储用户的选项
		cin >> choice;//接受用户的选项

		switch (choice) {
		case 0: //退出系统
			em.exitSys();
			break;
		case 1: //添加职工
			em.addEmp();
			break;
		case 2: //删除职工
			em.delEmp();
			break;
		case 3: //修改职工
			em.modEmp();
			break;
		case 4: //按姓名查找职工
			em.resByName();
			break;
		case 5: //按科室查找职工
			em.resByNum();
			break;
		case 6: //按科室统计职工工资
			em.calSalary();
			break;
		case 7: //查看所有员工信息
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