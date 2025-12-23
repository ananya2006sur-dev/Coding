#include <stdio.h>

struct employee
{
	int id;
	char name[20];
	long contact;
	float salary;
};

int main()
{
	int i, ch, EId, n;
	int flag = 0; 
	long new_contact;
	printf("Enter the number of employees: ");
	scanf("%d", &n);
	struct employee emp[n];
	for (i = 0; i < n; i++)
	{
		printf("Enter the %dth employee details\n", i + 1);
		printf("Enter the employee id: ");
		scanf("%d", &emp[i].id);
		printf("Enter the employee name: ");
		scanf("%s", emp[i].name);
		printf("Enter the employee contact: ");
		scanf("%ld", &emp[i].contact);
		printf("Enter the employee salary: ");
		scanf("%f", &emp[i].salary);
	}
	printf("Enter the options \n 1) Display all record \n 2) Search id \n 3) Display employees with salary more than Rs. 10000 \n 4) To update phone number of an employee \n");
	scanf("%d", &ch);
	switch (ch)
	{
		case 1:
		printf("EId\tEName\tEContact\tESalary\n");
		for (i = 0; i < n; i++)
		{
			printf("%d\t%s\t%ld\t%f", emp[i].id, emp[i].name, emp[i].contact, emp[i].salary);
			printf("\n");
		}
		break;

   		case 2:
		printf("Enter the employee id of the employee whose name you want: ");
		scanf("%d", &EId);
		for (i = 0; i < n; i++)
		{
			if (emp[i].id == EId)
			{
					printf("%d\t%s\t%ld\t%f", emp[i].id, emp[i].name, emp[i].contact, emp[i].salary);
			printf("\n");

				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("No such employee id found\n");
		}
		break;

		case 3:
		for (i = 0; i < n; i++)
		{
			if (emp[i].salary > 10000)
			{
				printf("%d\t%s\t%ld\t%f", emp[i].id, emp[i].name, emp[i].contact, emp[i].salary);
			        printf("\n");
				flag++;
			}
		}
		if (flag == 0)
		{
			printf("No employee with more than Rs.10000 salary \n");
		}
		break;

		case 4:
		printf("Enter the employee id whose contact you want to update: ");
		scanf("%d", &EId);
		printf("Enter the new contact: ");
		scanf("%ld", &new_contact);
		for (i = 0; i < n; i++)
		{
			if (emp[i].id == EId)
			{
				emp[i].contact = new_contact;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			printf("No such employee id found\n");
		}
		break;

		default:
		printf("Invalid choice\n");
		break;
	}
	return 0; 
}
