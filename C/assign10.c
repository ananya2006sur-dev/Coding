#include <stdio.h>
int main()
{
	char ch[50];
	int n, key; 
	printf("Enter a string ");
	scanf("%s", ch);
	printf("Enter key ");
	scanf("%d", &key);
	printf("Enter a case ");
	scanf("%d", &n);
	switch (n)
	{
		case 1:
			for (int i = 0; ch[i] != '\0'; i++)
			{
				if (ch[i] >= 'a' && ch[i] <= 'z')
				{
					ch[i] = (ch[i] - 'a' + key) % 26 + 'a';
				}
				else if (ch[i] >= 'A' && ch[i] <= 'Z')
				{
					ch[i] = (ch[i] - 'A' + key) % 26 + 'A';
				}
				else if (ch[i] >= '0' && ch[i] <= '9')
				{
					ch[i] = (ch[i] - '0' + key) % 10 + '0';
				}
			}
			printf("\nString after encryption is %s", ch);
			break;

		case 2:
			for (int i = 0; ch[i] != '\0'; i++)
			{
				if (ch[i] >= 'a' && ch[i] <= 'z')
				{
					ch[i] = (ch[i] - 'a' - key + 26) % 26 + 'a';
				}
				else if (ch[i] >= 'A' && ch[i] <= 'Z')
				{
					ch[i] = (ch[i] - 'A' - key + 26) % 26 + 'A';
				}
				else if (ch[i] >= '0' && ch[i] <= '9')
				{
					ch[i] = (ch[i] - '0' - key + 10) % 10 + '0';
				}
			}
			printf("\nString after decryption is %s", ch);
			break;

		default:
			printf("\nWrong input");
			break;
	}
	return 0;
}

		
