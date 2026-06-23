#include<stdio.h>

struct Employee
{
    int id;
    char name[20];
    float salary;
};

int main()
{
    FILE *fp;
    struct Employee e;

    fp=fopen("employee.dat","wb+");

    printf("Enter ID: ");
    scanf("%d",&e.id);

    printf("Enter Name: ");
    scanf("%s",e.name);

    printf("Enter Salary: ");
    scanf("%f",&e.salary);

    fwrite(&e,sizeof(e),1,fp);

    rewind(fp);

    fread(&e,sizeof(e),1,fp);

    printf("\nEmployee Details\n");
    printf("%d %s %.2f",e.id,e.name,e.salary);

    fclose(fp);

    return 0;
}