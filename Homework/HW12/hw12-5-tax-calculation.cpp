/*
    HR ของบริษัทเน็ตเวิร์คทำการกรอกข้อมูลพนักงานลงไปในระบบคำนวณฐานภาษีเพื่อเตรียมส่งยอดภาษีสู่ฝ่ายบัญชี โดยจะหักภาษี ณ ที่จ่าย 7% ของเงินเดือนที่ได้ ให้คุณคำนวณภาษีพนักงานทั้งหมดที่บริษัทของคุณต้องชำระภายในปีนี้ (กรอกเลข -1 ถือเป็นการสิ้นสุดการกรอก และทำการสรุปผลภาษีที่ต้องชำระภายในปีนี้) และสร้างฟังก์ชันที่ระบุคนที่ต้องชำระภาษีเยอะที่สุดในบริษัทมาแสดงในผลสรุปยอดของบริษัทด้วย

    Test case:
        Employee 1's Name : 
            Omar
        Sarary (Bath/Month) : 
            12750
        Employee 2's Name : 
            Alice
        Sarary (Bath/Month) : 
            15900
        Employee 3's Name : 
            Max
        Sarary (Bath/Month) : 
            19860
        Employee 4's Name : 
            -1
    Output:
        All salary per month: 48,510.00 Bath
        All salary per year: 582,120.00 Bath
        Tax (7% per year) : 40,748.40 Bath
        Most tax in company : Max (16,682.40 Bath per year)

    Test case:
        Employee 1's Name : 
            John
        Sarary (Bath/Month) : 
            15780
        Employee 2's Name : 
            Oven
        Sarary (Bath/Month) : 
            16890
        Employee 3's Name : 
            May
        Sarary (Bath/Month) : 
            17870
        Employee 4's Name : 
            Bill
        Sarary (Bath/Month) : 
            22100
        Employee 5's Name : 
            -1
    Output:
        All salary per month: 72,640.00 Bath
        All salary per year: 871,680.00 Bath
        Tax (7% per year) : 61,017.60 Bath
        Most tax in company : Bill (18,564.00 Bath per year)
*/
#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100

// สร้างโครงสร้างข้อมูลสำหรับพนักงาน
struct Employee {
    char name[50];
    double salaryPerMonth;
};

// ฟังก์ชันคำนวณภาษีและคืนค่ายอดเงินภาษีที่ต้องชำระ
double calculateTax(double salaryPerYear) {
    return salaryPerYear * 0.07;
}

int main() {
    struct Employee employees[MAX_EMPLOYEES];
    int employeeCount = 0;
    double totalSalaryPerYear = 0;
    char name[50];

    printf("โปรแกรมคำนวณภาษีพนักงาน\n");

    // รับข้อมูลพนักงานและคำนวณภาษี
    while (1) {
        printf("Employee %d's Name: ", employeeCount + 1);
        scanf("%s", employees[employeeCount].name);

        // ถ้าชื่อพนักงานเป็น -1 ให้สิ้นสุดการกรอกข้อมูล
        if (strcmp(employees[employeeCount].name, "-1") == 0) {
            break;
        }

        printf("Salary (Bath/Month): ");
        scanf("%lf", &employees[employeeCount].salaryPerMonth);

        totalSalaryPerYear += employees[employeeCount].salaryPerMonth * 12;
        employeeCount++;
    }

    // คำนวณภาษีทั้งหมด
    double totalTax = calculateTax(totalSalaryPerYear);

    // หาคนที่ต้องชำระภาษีเยอะที่สุด
    double maxTax = 0;
    char maxTaxEmployee[50];

    for (int i = 0; i < employeeCount; i++) {
        double employeeTax = calculateTax(employees[i].salaryPerMonth * 12);
        if (employeeTax > maxTax) {
            maxTax = employeeTax;
            strcpy(maxTaxEmployee, employees[i].name);
        }
    }

    // แสดงผลลัพธ์
    printf("All salary per month: %.2lf Bath\n", totalSalaryPerYear / 12);
    printf("All salary per year: %.2lf Bath\n", totalSalaryPerYear);
    printf("Tax (7%% per year): %.2lf Bath\n", totalTax);
    printf("Most tax in company: %s (%.2lf Bath per year)\n", maxTaxEmployee, maxTax);

    return 0;
}
