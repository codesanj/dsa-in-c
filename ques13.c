#include <stdio.h>
#include <string.h>

struct Employee {
    int empId;
    char name[50];
    char designation[50];
    float basicSalary;
    float hraPercentage;
    float daPercentage;
};

void calculateGrossSalary(struct Employee *emp) {
    emp->hraPercentage /= 100;
    emp->daPercentage /= 100;
    
    emp->basicSalary += emp->basicSalary * emp->hraPercentage + emp->basicSalary * emp->daPercentage;
}

int main() {
    int n;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    struct Employee employees[n];

    for (int i = 0; i < n; ++i) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        employees[i].empId = i + 1;

        printf("Name: ");
        scanf("%s", employees[i].name);

        printf("Designation: ");
        scanf("%s", employees[i].designation);

        printf("Basic Salary: ");
        scanf("%f", &employees[i].basicSalary);

        printf("HRA Percentage: ");
        scanf("%f", &employees[i].hraPercentage);

        printf("DA Percentage: ");
        scanf("%f", &employees[i].daPercentage);

        calculateGrossSalary(&employees[i]);
    }

    printf("\nEmployee Information with Gross Salary:\n");
    for (int i = 0; i < n; ++i) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Emp ID: %d\n", employees[i].empId);
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Gross Salary: %.2f\n", employees[i].basicSalary);
    }

    return 0;
}
