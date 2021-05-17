#include <stdio.h>
#include <string.h>   //字符串比较函数strcmp(,)如果相同返回0，
#include <windows.h>  //system("cls")：清屏       sleep(毫秒)：将执行挂起一段时间  fflush(stdin);清空缓冲区
#include <conio.h>    //getch（）从控制台读取一个字符，但不显示在屏幕上，用于密码加密
#include <stdlib.h>
#include <ctype.h>

//学生个人信息
typedef struct Student {
    char name[20];                  //名字
    char number[10];                //学号
    char class[20];                 //班级
    int c;                          //c语言成绩
    int python;                     //python成绩
    int java;                       //java成绩
    struct Student *next;           //用链表储存
}Stu;

//账号和密码
typedef struct Account {
    char number[20];            //账号
    char account[20];           //学号
    char password[20];          //密码
    char identity[10];          //判断是学生还是老师
    struct Account *next;
}Acc;

Stu *class1 = NULL;
Stu *class2 = NULL;
Stu *class3 = NULL;
Stu *class4 = NULL;
Stu *class5 = NULL;
Acc *student = NULL;
Acc *teacher = NULL;
Acc *admin = NULL;

void Student_management_system(void);            //学生管理系统首页 
void Login_interface(void);                      //登陆界面
void Registration_interface(void);               //注册界面
void Find_password(void);                        //找回密码
int exitSys(void);                               //退出确认 是：返回0  否：返回1
Stu *search(char *);                             //按学号查找学生,返回该学生的结点
void Student_login(void);                        //学生登陆
void Teacher_login(void);                        //教师登陆
void Administrator_login(void);                  //管理员登陆
Stu *create_list1(void);                         //将一班信息录入链表class1
Stu *create_list2(void);                         //将二班信息录入链表class2
Stu *create_list3(void);                         //将三班信息录入链表class3
Stu *create_list4(void);                         //将四班信息录入链表class4
Stu *create_list5(void);                         //将五班信息录入链表class5
void traverse_list(Stu *);                       //遍历学生成绩信息链表
void Change_Password1(char *);                   //修改密码，接收学号便于查找
void Change_Password2(char *);
void Change_Password3(char *);
void Student_main_interface(char *);             //学生主界面，传入学号，便于判断班级
void Teacher_main_interface(char *);             //教师主界面，传入账号判断是那个班教师
void Administrator_main_interface(void);         //管理员主界面，你只要进来你就是管理员
Acc *Student_account(void);                      //将学生的账号录入链表student
Acc *Teacher_account(void);                      //将老师的账号录入链表teacher    
Acc *Admin_account(void);                        //将管理员的账号录入链表admin
void secretword(char *);                         //密码加密
void Student_registration(void);                 //学生注册
void Teacher_registration(void);                 //教师注册
void Score_inquiry(Stu *, char *);               //成绩查询
void Query_class_grades(Stu *);                  //查询班级成绩
void Performance_analysis(Stu *);                //成绩分析
void Performance_appeal(Stu *);                  //成绩申诉
void Increase_students(char *);                  //增加学生信息
void Delete_students(char *);                    //删除学生
void Modify_information(char *);                 //修改信息
void Modify(Stu *);                              //修改
void Inquire_students(char *, char *);           //查询学生信息
void Query_class_grades1(char *);                //查询班级成绩
void Query_class_grades0(Acc *, char *);
void Reminder_update(char *);                    //提醒管理员进行成绩的更新
void Teacher_reminder(void);                     //弹出老师提醒
void Analysis_class_performance(char *);         //班级成绩分析
void Student_reminder(void);                     //学生提醒
void View_agent(void);                           //查看代办
void Teacher_interface(char *);                  //进入教师界面
void Add_account_number(void);                   //增加账号和密码
void Student_registration1(void);                //管理员增加学生账号
void Teacher_registration1(void);                //管理员增加教师账号
void Delete_account(void);                       //删除账号及其密码
void Change_account_number_and_password(void);   //修改账号及密码
void Change(Acc *, Acc *);                       //修改
void Find_account_number_and_password(void);     //查找账号及密码
void rangnian(int, Acc *);                       //别乱按
void Output_all_accounts_and_passwords(void);    //输出所有的账号及密码
void Enter_all_accounts_and_passwords(void);     //录入所有账号及密码
void Manually_re_input_student_information(void);//手动重新录入学生信息
void xuehao(Stu *);                              //判断学号
void bubblesort1(Stu* Head);                      //C排序
void bubblesort2(Stu* Head);                      //Python排序
void bubblesort3(Stu* Head);                      //Java排序
void haogege(int, Stu *, Stu *);
Acc *chazhao(char *);                             //老师查找

int main(void) {
    student = Student_account();
    teacher = Teacher_account();
    admin = Admin_account();
    class1 = create_list1();
    class2 = create_list2();
    class3 = create_list3();
    class4 = create_list4();
    class5 = create_list5();
    Student_management_system();
    system("pause");   
    return 0;
}

//学生管理系统首页
void Student_management_system(void) {
    system("cls");
    printf("|--------------------------|\n");
    printf("|     学生信息管理系统     |\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|          1.登陆          |\n");
    printf("|                          |\n");
    printf("|          2.注册          |\n");
    printf("|                          |\n");
    printf("|        3.密码找回        |\n");
    printf("|                          |\n");
    printf("|        4.退出程序        |\n");
    printf("|                          |\n");
    printf("|--------------------------|\n");
    printf("\n");
    char ch;
    ch = getch();
    switch (ch) {
        case '1': {
            Login_interface();
            break;
        } 
        case '2': {
            Registration_interface();
            break;
        }
        case '3': {
            Find_password();
            break;
        }
        case '4': {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                Student_management_system();
            }
            break;
        }
        default : {
            Student_management_system();
            break;
        }
    }
    return;
}

//登录界面
void Login_interface(void) {
    system("cls");
    printf("|--------------------------|\n");
    printf("|         登陆界面         |\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|        1.学生登陆        |\n");
    printf("|                          |\n");
    printf("|        2.教师登陆        |\n");
    printf("|                          |\n");
    printf("|       3.管理员登陆       |\n");
    printf("|                          |\n");
    printf("|          4.返回          |\n");
    printf("|                          |\n");
    printf("|        5.退出程序        |\n");
    printf("|--------------------------|\n");
    printf("\n");
    char ch;
    ch = getch();
    switch (ch) {
        case '1' : {
            Student_login();
            break;
        }
        case '2' : {
            Teacher_login();
            break;
        }
        case '3' : {
            Administrator_login();
            break;
        }
        case '4' : {
            system("cls");
            printf("返回中，请稍等...");
            Sleep(1000);
            system("cls");
            Student_management_system();
            break;
        }
        case '5' : {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                Login_interface();
            }
            break;
        }
        default : {
            Login_interface();
            break;
        }
    }
    return;
}

//注册界面
void Registration_interface(void) {
    system("cls");
    printf("|--------------------------|\n");
    printf("|         注册界面         |\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|        1.学生注册        |\n");
    printf("|                          |\n");
    printf("|        2.教师注册        |\n");
    printf("|                          |\n");
    printf("|        3.返回首页        |\n");
    printf("|                          |\n");
    printf("|        4.退出程序        |\n");
    printf("|                          |\n");        
    printf("|--------------------------|\n");
    char ch;
    ch = getch();
    switch (ch) {
        case '1' : {
            Student_registration();
            break;
        }
        case '2' : {
            Teacher_registration();
            break;
        }
        case '3' : {
            Student_management_system();
            break;
        }
        case '4' : {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                Registration_interface();
            }            
            break;
        }
        default : {
            Registration_interface();
            break;
        }
    }
    return;
}

//找回密码
void Find_password(void) {
    system("cls");
    char account[20];
    printf("请输入您的账号：");
    gets(account);
    Acc *m = student;
    Acc *n = teacher;
    while (m) {
        if (strcmp(m -> account, account) == 0) {
            Change_Password1(account);
            return;
        }
        m = m -> next;
    }
    while (n) {
        if (strcmp(n -> account, account) == 0) {
            Change_Password2(account);
            return;
        }
        n = n -> next;
    }
    system("cls");
    printf("您输入的账号不存在，请重新输入...");
    Sleep(1000);
    system("cls");
    Student_management_system();
    return;
}

//退出确认 
int exitSys(void) {
    system("cls");
    printf(" 1.是\n");
    printf(" 2.否\n");
    char ch;
    while(ch = getch()) {  //使用循环防止输入其他的情况
        if(ch == '1') {
          return 0;
        }
        if(ch == '2') {
          return 1;
        }    
    }
}

//按学号查找学生，返回该学生的结点
Stu *search(char *number) {
    Stu *p = NULL;
    if (number[1] == '1') {
        p = class1;
    } else if (number[1] == '2') {
        p = class2;
    } else if (number[1] == '3') {
        p = class3;
    } else if (number[1] == '4') {
        p = class4;
    } else if (number[1] == '5') {
        p = class5;
    }
    while (p) {
        if (strcmp(number, p -> number) == 0) {
            break;
        } 
        p = p -> next;
    }
    if (!p) {
        system("cls");
        printf("没有找到该学号，请重新登陆输入...");
        Sleep(1000);
        system("cls");
        Login_interface();
    }
    return p;
}

//学生登陆
void Student_login(void) {
    system("cls");
    printf("欢迎来到学生登陆界面!\n\n");
    char account[20];
    char password[20];
    Acc *p = student;
    int flag = 0;
    memset(account, 0, sizeof(char) * 20);
    memset(password, 0, sizeof(char) * 20);
    printf("账号：");
    gets(account);
    while (p) {
        if (strcmp(account, p -> number) == 0) {
            flag = 1;
            break;
        }
        p = p -> next;
    }
    if (flag == 1) {
        printf("密码：");
        secretword(password);
        if (strcmp(password, p -> password) == 0) {
            system("cls");
            printf("登陆成功，正在进入学生主界面...");
            Sleep(1000);
            system("cls");
            Student_main_interface(p -> account);
        } else {
            system("cls");
            printf("密码错误，请重新输入...");
            Sleep(1000);
            system("cls");
            Student_login();
        }
    } else {
        system("cls");
        printf("该账号还未注册，请先注册...");
        Sleep(1000);
        system("cls");
        Student_management_system();
    }
    return;
}

//教师登陆
void Teacher_login(void) {
    system("cls");
    printf("欢迎来到教师登陆界面!\n\n");
    char account[20];
    char password[20];
    Acc *p = teacher;
    int flag = 0;
    memset(account, 0, sizeof(char) * 20);
    memset(password, 0, sizeof(char) * 20);
    printf("账号：");
    gets(account);
    while (p) {
        if (strcmp(account, p -> account) == 0) {
            flag = 1;
            break;
        }
        p = p -> next;
    }
    if (flag == 1) {
        printf("密码：");
        secretword(password);
        if (strcmp(password, p -> password) == 0) {
            system("cls");
            printf("登陆成功，正在进入教师主界面...");
            Sleep(1000);
            system("cls");
            Teacher_main_interface(account);
        } else {
            system("cls");
            printf("密码错误，请重新输入...");
            Sleep(1000);
            system("cls");
            Teacher_login();
        }
    } else {
        system("cls");
        printf("该账号还未注册，请先注册...");
        Sleep(1000);
        system("cls");
        Student_management_system();
    }
    return;
}

//管理员登陆
void Administrator_login(void) {
    system("cls");
    printf("欢迎来到管理员登陆界面!\n\n");
    char account[20];
    char password[20];
    char ch[20];               //临时存放
    Acc *p = admin;
    int flag = 0;
    memset(account, 0, sizeof(char) * 20);
    memset(password, 0, sizeof(char) * 20);
    memset(ch, 0, sizeof(char) * 20);
    printf("账号：");
    gets(account);
    while (p) {
        strcpy(ch, p -> account);
        if (strcmp(ch, account) == 0) {
            flag = 1;
            break;
        }
        p = p -> next;
    }
    if (flag == 1) {
        memset(ch, 0, sizeof(char) * 20);
        strcpy(ch, p -> password);
        printf("密码：");
        secretword(password);
        if (strcmp(ch, password) == 0) {
            system("cls");
            printf("登陆成功，请稍等...");
            Sleep(1000);
            system("cls");
            Administrator_main_interface();
        } else {
            system("cls");
            printf("密码错误，请重新登陆！！！");
            Sleep(1000);
            system("cls");
            Administrator_login();
        }
    } else {
        system("cls");
        printf("账号输入有误，请重新输入！！！");
        Sleep(1000);
        system("cls");
        Administrator_login();
    }
    return;
}

//将某班信息录入链表class某
Stu *create_list1(void) {
    FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class1.txt", "r");
    if (fp == NULL) {
       printf("文件打开失败！");
       return 0;
    }
    Stu *class1 = (Stu *)malloc(sizeof(Stu));
    if (NULL == class1) {
		printf("分配失败！程序终止！\n");
		exit(-1);
	}
    Stu *p = class1;
    p -> next = NULL;
    while (!feof(fp)) {
        Stu *m = (Stu *)malloc(sizeof(Stu));
        if (NULL == m) {
		   printf("分配失败！程序终止！\n");
		   exit(-1);            
        }
        fscanf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, &m -> c, &m -> python, &m -> java);
        p -> next = m;
        m -> next = NULL;
        p = p -> next;
    }    
    fclose(fp);
	return class1;
}
Stu *create_list2(void) {
    FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class2.txt", "r");
    if (fp == NULL) {
       printf("文件打开失败！");
       return 0;
    }
    Stu *class2 = (Stu *)malloc(sizeof(Stu));
    if (NULL == class2) {
		printf("分配失败！程序终止！\n");
		exit(-1);
	}
    Stu *p = class2;
    p -> next = NULL;
    while (!feof(fp)) {
        Stu *m = (Stu *)malloc(sizeof(Stu));
        if (NULL == m) {
		   printf("分配失败！程序终止！\n");
		   exit(-1);            
        }
        fscanf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, &m -> c, &m -> python, &m -> java);
        p -> next = m;
        m -> next = NULL;
        p = p -> next;
    }    
    fclose(fp);
	return class2;
}
Stu *create_list3(void) {
    FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class3.txt", "r");
    if (fp == NULL) {
       printf("文件打开失败！");
       return 0;
    }
    Stu *class3 = (Stu *)malloc(sizeof(Stu));
    if (NULL == class3) {
		printf("分配失败！程序终止！\n");
		exit(-1);
	}
    Stu *p = class3;
    p -> next = NULL;
    while (!feof(fp)) {
        Stu *m = (Stu *)malloc(sizeof(Stu));
        if (NULL == m) {
		   printf("分配失败！程序终止！\n");
		   exit(-1);            
        }
        fscanf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, &m -> c, &m -> python, &m -> java);
        p -> next = m;
        m -> next = NULL;
        p = p -> next;
    }    
    fclose(fp);
	return class3;
}
Stu *create_list4(void) {
    FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class4.txt", "r");
    if (fp == NULL) {
       printf("文件打开失败！");
       return 0;
    }
    Stu *class4 = (Stu *)malloc(sizeof(Stu));
    if (NULL == class4) {
		printf("分配失败！程序终止！\n");
		exit(-1);
	}
    Stu *p = class4;
    p -> next = NULL;
    while (!feof(fp)) {
        Stu *m = (Stu *)malloc(sizeof(Stu));
        if (NULL == m) {
		   printf("分配失败！程序终止！\n");
		   exit(-1);            
        }
        fscanf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, &m -> c, &m -> python, &m -> java);
        p -> next = m;
        m -> next = NULL;
        p = p -> next;
    }    
    fclose(fp);
	return class4;
}
Stu *create_list5(void) {
    FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class5.txt", "r");
    if (fp == NULL) {
       printf("文件打开失败！");
       return 0;
    }
    Stu *class5 = (Stu *)malloc(sizeof(Stu));
    if (NULL == class5) {
		printf("分配失败！程序终止！\n");
		exit(-1);
	}
    Stu *p = class5;
    p -> next = NULL;
    while (!feof(fp)) {
        Stu *m = (Stu *)malloc(sizeof(Stu));
        if (NULL == m) {
		   printf("分配失败！程序终止！\n");
		   exit(-1);            
        }
        fscanf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, &m -> c, &m -> python, &m -> java);
        p -> next = m;
        m -> next = NULL;
        p = p -> next;
    }    
    fclose(fp);
	return class5;
}

//录入账号
Acc *Student_account(void) {
    FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\学生账号和密码.txt", "r");
    if (fp == NULL) {
       printf("文件打开失败！");
       return 0;
    }
    Acc *student = (Acc *)malloc(sizeof(Acc));
    if (NULL == student) {
		printf("分配失败！程序终止！\n");
		exit(-1);
	}
    Acc *p = student;
    p -> next = NULL;
    while (!feof(fp)) {
        Acc *m = (Acc *)malloc(sizeof(Acc));
        if (NULL == m) {
		   printf("分配失败！程序终止！\n");
		   exit(-1);            
        }
        fscanf(fp, "%s %s %s %s\n", m -> number, m -> account, m -> password, m -> identity);
        p -> next = m;
        m -> next = NULL;
        p = p -> next;
    }    
    fclose(fp);
    return student;
} 
Acc *Teacher_account(void) {
    FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\教师账号和密码.txt", "r");
    if (fp == NULL) {
       printf("文件打开失败！");
       return 0;
    }
    Acc *teacher = (Acc *)malloc(sizeof(Acc));
    if (NULL == teacher) {
		printf("分配失败！程序终止！\n");
		exit(-1);
	}
    Acc *p = teacher;
    p -> next = NULL;
    while (!feof(fp)) {
        Acc *m = (Acc *)malloc(sizeof(Acc));
        if (NULL == m) {
		   printf("分配失败！程序终止！\n");
		   exit(-1);            
        }
        fscanf(fp, "%s %s %s %s\n", m -> number, m -> account, m -> password, m -> identity);
        p -> next = m;
        m -> next = NULL;
        p = p -> next;
    }    
    fclose(fp);    
    return teacher;
} 
Acc *Admin_account(void) {
    FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\管理员账号和密码.txt", "r");
    if (fp == NULL) {
       printf("文件打开失败！");
       return 0;
    }
    Acc *admin = (Acc *)malloc(sizeof(Acc));
    if (NULL == admin) {
		printf("分配失败！程序终止！\n");
		exit(-1);
	}
    Acc *p = admin;
    p -> next = NULL;
    while (!feof(fp)) {
        Acc *m = (Acc *)malloc(sizeof(Acc));
        if (NULL == m) {
		   printf("分配失败！程序终止！\n");
		   exit(-1);            
        }
        fscanf(fp, "%s %s %s\n", m -> account, m -> password, m -> identity);
        p -> next = m;
        m -> next = NULL;
        p = p -> next;
    }    
    fclose(fp);    
    return admin;
}

//遍历整个学生信息链表
void traverse_list(Stu *head) {
    Stu *p = head -> next;
    printf("\t姓名\t学号\t班级\tC语言\tPython\tJava\n\n");
    while (p != NULL) {
        printf("\t%s\t%s\t%s\t%d\t%d\t%d\n", p -> name, p -> number, p -> class, p -> c, p -> python, p -> java);
        p = p -> next;
    } 
    return;
}

//修改密码
void Change_Password1(char *number) {
    system("cls");
    Acc *new = NULL;
    Acc *sb = NULL;
    new = student;
    sb = new;
    system("cls");
    char password[20];
    char confirm[20];
    while (sb) {
        if (strcmp(sb -> account, number) == 0) {
            memset(sb -> password, 0, sizeof(char) * 20);
            break;
        }
        sb = sb -> next;
    }
    if (!sb) {
        system("cls");
        printf("您的账号有误，请重新选择...");
        Sleep(1000);
        system("cls");
        Change_Password1(number);
    }    
    printf("请输入您的新密码：");
    secretword(password);
    printf("再次输入您的密码:");
    secretword(confirm);
    if (strcmp(confirm, password) != 0) {
        system("cls");
        printf("您两次输入的密码不一致，请重新输入...");
        Sleep(1000);
        system("cls");
        Change_Password1(number);
        return;
    }

    strcpy(sb -> password, password);
    new = new -> next;
    if (strcmp(sb -> identity, "学生") == 0) {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\学生账号和密码.txt", "w");
        while (new) {
            fprintf(fp, "%s %s %s %s\n", new -> number, new -> account, new -> password, new -> identity);
            new = new -> next;
        }
        fclose(fp);
    }  
    system("cls"); 
    printf("密码修改成功，请重新登陆...");   
    Sleep(1000);
    system("cls");
    Login_interface();
    return;
}
void Change_Password2(char *number) {
    system("cls");
    Acc *new = NULL;
    Acc *sb = NULL;
    new = teacher;
    sb = new;
    system("cls");
    char password[20];
    char confirm[20];
    while (sb) {
        if (strcmp(sb -> account, number) == 0) {
            memset(sb -> password, 0, sizeof(char) * 20);
            break;
        }
        sb = sb -> next;
    }
    if (!sb) {
        system("cls");
        printf("您的账号有误，请重新选择...");
        Sleep(1000);
        system("cls");
        Change_Password2(number);
    }    
    printf("请输入您的新密码：");
    secretword(password);
    printf("再次输入您的密码:");
    secretword(confirm);
    if (strcmp(confirm, password) != 0) {
        system("cls");
        printf("您两次输入的密码不一致，请重新输入...");
        Sleep(1000);
        system("cls");
        Change_Password2(number);
        return;
    }
    strcpy(sb -> password, password);
    new = new -> next;
    if (strcmp(sb -> identity, "教师") == 0) {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\教师账号和密码.txt", "w");
        while (new) {
            fprintf(fp, "%s %s %s %s\n", new -> number, new -> account, new -> password, new -> identity);
            new = new -> next;
        }
        fclose(fp);
    }  
    system("cls"); 
    printf("密码修改成功，请重新登陆...");   
    Sleep(1000);
    system("cls");
    Login_interface();
    return;
}
void Change_Password3(char *number) {
    system("cls");
    Acc *new = NULL;
    Acc *sb = NULL;
    new = admin;
    sb = new;
    system("cls");
    char password[20];
    char confirm[20];
    while (sb) {
        if (strcmp(sb -> account, number) == 0) {
            memset(sb -> password, 0, sizeof(char) * 20);
            break;
        }
        sb = sb -> next;
    }
    if (!sb) {
        system("cls");
        printf("您的账号有误，请重新选择...");
        Sleep(1000);
        system("cls");
        Change_Password3(number);
    }    
    printf("请输入您的新密码：");
    secretword(password);
    printf("再次输入您的密码:");
    secretword(confirm);
    if (strcmp(confirm, password) != 0) {
        system("cls");
        printf("您两次输入的密码不一致，请重新输入...");
        Sleep(1000);
        system("cls");
        Change_Password3(number);
        return;
    }
    strcpy(sb -> password, password);
    new = new -> next;
    FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\管理员账号和密码.txt", "w");
    while (new) {
        fprintf(fp, "%s %s %s %s\n", new -> number, new -> account, new -> password, new -> identity);
        new = new -> next;
    }
    fclose(fp);
    system("cls"); 
    printf("密码修改成功，请重新登陆...");   
    Sleep(1000);
    system("cls");
    Login_interface();
    return;
}

//学生主界面
void Student_main_interface(char *number) {
    system("cls");
    Stu *p = search(number);
    printf("       欢迎%s同学！       \n\n", p -> name);
    printf("|--------------------------|\n");
    printf("|        学生主界面        |\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|        1.成绩查询        |\n");
    printf("|                          |\n");
    printf("|      2.查询本班成绩      |\n");
    printf("|                          |\n");
    printf("|        3.成绩分析        |\n");
    printf("|                          |\n");
    printf("|        4.成绩申诉        |\n");
    printf("|                          |\n");
    printf("|        5.修改密码        |\n");
    printf("|                          |\n");
    printf("|      6.返回登陆界面      |\n");
    printf("|                          |\n");    
    printf("|        0.退出程序        |\n");
    printf("|                          |\n");
    printf("|--------------------------|\n");   
    char ch;
    ch = getch();
    switch (ch) {
        case '1' : {
            Score_inquiry(p, number);
            break;
        } 
        case '2' : {
            Query_class_grades(p);
            break;
        }
        case '3' : {
            Performance_analysis(p);
            break;
        } 
        case '4' : {
            Performance_appeal(p);
            break;
        }  
        case '5' : {
            Change_Password1(p -> number);
            break;
        } 
        case '6' : {
            Login_interface();
            break;
        }
        case '0' : {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                Student_main_interface(number);
            }            
            break;
        }
        default : {
            Student_main_interface(number);
            break;
        }
    }       
    return;
}

//教师主界面
void Teacher_main_interface(char *account) {
    system("cls");
    Acc *p = chazhao(account);
    printf("|--------------------------|\n");
    printf("|        教师主界面        |\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|    1.增加新的学生信息    |\n");
    printf("|                          |\n");
    printf("|      2.删除学生信息      |\n");
    printf("|                          |\n");
    printf("|      3.修改学生信息      |\n");
    printf("|                          |\n");
    printf("|      4.查询学生信息      |\n");
    printf("|                          |\n");
    printf("|      5.输出班级成绩      |\n");
    printf("|                          |\n");
    printf("|        6.成绩分析        |\n");
    printf("|                          |\n");
    printf("|7.提醒管理员进行成绩的更新|\n");
    printf("|                          |\n");
    printf("|      8.返回登陆界面      |\n");
    printf("|                          |\n");
    printf("|        9.修改密码        |\n");
    printf("|                          |\n");
    printf("|        0.退出程序        |\n");
    printf("|                          |\n");
    printf("|--------------------------|\n"); 
    char ch;
    fflush(stdin);
    ch = getch();
    switch (ch) {
        case '1' : {
            Increase_students(account);
            break;
        } 
        case '2' : {
            Delete_students(account);
            break;
        }
        case '3' : {
            Modify_information(account);
            break;
        } 
        case '4' : {
            system("cls");
            printf("请输入该学生的学号：");
            char number[20];
            gets(number);
            Inquire_students(number, account);
            break;
        } 
        case '5' : {
            Query_class_grades0(p, account);
            break;
        } 
        case '6' : {
            Analysis_class_performance(account);
            break;
        } 
        case '7' : {
            Reminder_update(account);
            break;
        } 
        case '8' : {
            Login_interface();
            break;
        } 
        case '9' : {
            Change_Password2(account);
            break;
        }
        case '0' : {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                Teacher_main_interface(account);
            }            
            break;
        }
        default : {
            Teacher_main_interface(account);
            break;
        }
    }       
    return;
}

//管理员主界面
void Administrator_main_interface(void) {
    system("cls");
    FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\提醒管理员进行成绩的更新.txt", "r");
    if (fgetc(fp) != EOF) {
        fclose(fp);
        Teacher_reminder();
    }
    fclose(fp);
    system("cls");
    Student_reminder();
    system("cls");
    printf("|--------------------------|\n");
    printf("|       管理员主界面       |\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|      1.查看代办选项      |\n");
    printf("|                          |\n");
    printf("| 2.进入教师端进行信息修改 |\n");
    printf("|                          |\n");
    printf("|     3.增加账号及密码     |\n");
    printf("|                          |\n");
    printf("|     4.删除账号及密码     |\n");
    printf("|                          |\n");
    printf("|     5.修改账号及密码     |\n");
    printf("|                          |\n");
    printf("|     6.查找账号及密码     |\n");
    printf("|                          |\n");
    printf("|   7.录入所有账号及密码   |\n");
    printf("|                          |\n");
    printf("|   8.输出所有账号及密码   |\n");
    printf("|                          |\n");
    printf("|  9.手动重新录入学生信息  |\n");
    printf("|                          |\n");
    printf("|      a.返回登陆界面      |\n");
    printf("|                          |\n");
    printf("|        0.退出程序        |\n");
    printf("|                          |\n");
    printf("|--------------------------|\n");
    char ch;
    fflush(stdin);
    ch = getch();
    switch (ch) {
        case '1' : {
            View_agent();
            break;
        } 
        case '2' : {
            char str[20] = {"admin"};
            Teacher_interface(str);
            break;
        }
        case '3' : {
            Add_account_number();
            break;
        } 
        case '4' : {
            Delete_account();
            break;
        } 
        case '5' : {
            Change_account_number_and_password();
            break;
        } 
        case '6' : {
            Find_account_number_and_password();
            break;
        } 
        case '7' : {
            Enter_all_accounts_and_passwords();
            break;
        } 
        case '8' : {
            Output_all_accounts_and_passwords();
            break;
        } 
        case '9' : {
            Manually_re_input_student_information();
            break;
        } 
        case 'a' : {
            Login_interface();
            break;
        } 
        case '0' : {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                Administrator_main_interface();
            }            
            break;
        }
        default : {
            Administrator_main_interface();
            break;
        }
    }
    return;
}

//密码加密
void secretword(char *key) {
    unsigned char c;
    int i = 0;
    while ((c = getch()) != '\r') {   //当输入不为回车时就继续输入，getch获得的字符不会显示，就和没输入一样
        if (i < 20 && isprint(c)) {
            key[i] = c;
            i++;
            putchar('*');
        } else if (i > 0 && c == '\b') {  //输入为退格键（删除）就进入此条件
            i--;
            putchar('\b');  //将输入的数删掉
            putchar(' ');   //用空格补刚刚删除的那一位
            putchar('\b');  //将光标向前移一位
        } else {
            putchar(7);  //7为响铃符,用来提示报错
        }
    }
    printf("\n");
    key[i] = '\0';
} 

//学生注册
void Student_registration(void) {
    system("cls");
    printf("学生注册界面\n\n");
    printf("请选择你的班级：\n");
    printf("1.网络一班\n");
    printf("2.网络二班\n");
    printf("3.网络三班\n");
    printf("4.网络四班\n");
    printf("5.网络五班\n");
    printf("0.返回\n");
    char account[20] = {0};
    char password[20] = {0};
    Stu *p = NULL;
    int flag = 0;
    char ch;
    char confirm[20] = {0};
    ch = getch();
    switch (ch) {
        case '1' : {
            p = class1;
            break;
        }
        case '2' : {
            p = class2;
            break;
        }
        case '3' : {
            p = class3;
            break;
        }
        case '4' : {
            p = class4;
            break;
        }
        case '5' : {
            p = class5;
            break;
        }
        case '0' : {
            Registration_interface();
            break;
        }
        default : {
            Student_registration();
            break;
        }
    }
    system("cls");
    printf("请输入你的学号：");
    gets(account);
    while (p) {
        if (strcmp(account, p -> number) == 0) {
            flag = 1;
            break;
        }
        p = p -> next;
    }
    if (flag == 1) {
        printf("密码：");
        secretword(password);
        printf("确认密码：");
        secretword(confirm);
        if (strcmp(password, confirm) != 0) {
            system("cls");
            printf("输入的两次密码不一致，请重新输入...");
            Sleep(1000);
            system("cls");
            Student_registration();
            return;
        }
        char number[20] = {0};
        strcpy(number, account);
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\学生账号和密码.txt", "a");
        fprintf(fp, "%s %s %s %s\n", number, account, password, "学生");
        fclose(fp);
        student = Student_account();
        system("cls");
        printf("注册成功，正在返回首页，请稍等...");
        Sleep(1000);
        system("cls");
        Student_management_system();        
    } else {
        system("cls");
        printf("输入的学号有误请重新输入...");
        Sleep(1000);
        system("cls");
        Student_registration();
    }
    return;
}

//教师注册
void Teacher_registration(void) {
    system("cls");
    printf("教师注册界面\n\n");
    printf("0.返回\n");
    printf("任意键继续\n");
    char o;
    o = getch();
    switch (o) {
        case '0' : {
            Registration_interface();
            break;
        }
    }
    system("cls");
    char account[20] = {0};
    char password[20] = {0};
    Acc *p = teacher;
    char ch[20];
    char si[20];
    int flag = 0;
    memset(ch, 0, sizeof(char) * 20);
    printf("请选择你的班级:\n");
    printf("1.网络一班\n");
    printf("2.网络二班\n");
    printf("3.网络三班\n");
    printf("4.网络四班\n");
    printf("5.网络五班\n");
    char l;
    l = getch();
    switch (l) {
        case '1' : {
            strcpy(si, "网络一班");
            break;
        }
        case '2' : {
            strcpy(si, "网络二班");
            break;
        }
        case '3' : {
            strcpy(si, "网络三班");
            break;
        }
        case '4' : {
            strcpy(si, "网络四班");
            break;
        }
        case '5' : {
            strcpy(si, "网络五班");
            break;
        }
    }
    printf("你想注册的账号：");
    gets(account);
    while (p) {
        strcpy(ch, p -> account);
        if (strcmp(ch, account) == 0) {
            flag = 1;
            break;
        }
        p = p -> next;
    }
    if (flag == 1) {
        system("cls");
        printf("该账号已被注册，请重新输入...");
        Sleep(1000);
        system("cls");
        Teacher_registration();
    } else {
        memset(ch, 0, sizeof(char) * 20);
        printf("密码：");
        secretword(password);
        printf("确认密码：");
        secretword(ch);
        if (strcmp(ch, password) != 0) {
            system("cls");
            printf("两次输入密码不一致，请重新输入...");
            Sleep(1000);
            Teacher_registration();
            return;
        }
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\教师账号和密码.txt", "a");
        fprintf(fp, "%s %s %s %s\n", si, account, password, "教师");
        fclose(fp);
        teacher = Teacher_account();
        system("cls");
        printf("注册成功，正在返回首页，请稍等...");
        Sleep(1000);
        system("cls");
        Student_management_system();
    }
    return;
}

//个人成绩查询
void Score_inquiry(Stu *p, char *number) {
    system("cls");
    printf("\n");
    printf("\t==%s==\n", p -> name);
    printf("\n");
    printf("\tC语言：%d        \n", p -> c);
    printf("\n");
    printf("\tPython：%d\n", p -> python);
    printf("\n");
    printf("\tJava：%d\n", p -> java);    
    printf("\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|     1.返回学生主界面     |\n");
    printf("|                          |\n");
    printf("|        2.退出程序        |\n");
    printf("|                          |\n");
    printf("|--------------------------|\n");
    char ch;
    ch = getch();
    switch (ch) {
        case '1' : {
            Student_main_interface(number);
            break;
        }
        case '2' : {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                Score_inquiry(p, number);
            }             
            break; 
        }
        default : {
            Score_inquiry(p, number);
        }
    }
    return;
}

//查询班级成绩
void Query_class_grades(Stu *p) {
    system("cls");
    Stu *m = NULL;
    if (strcmp(p -> class, "网络1班") == 0) {
        m = class1;
    } else if (strcmp(p -> class, "网络2班") == 0) {
        m = class2;
    } else if (strcmp(p -> class, "网络3班") == 0) {
        m = class3;
    } else if (strcmp(p -> class, "网络4班") == 0) {
        m = class4;
    } else if (strcmp(p -> class, "网络5班") == 0) {
        m = class5;
    }
    Stu *n = m;
    traverse_list(m);
    printf("\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|     1.返回学生主界面     |\n");
    printf("|                          |\n");
    printf("|        2.退出程序        |\n");
    printf("|                          |\n");
    printf("|       3.C语言排序        |\n");
    printf("|                          |\n");
    printf("|       4.Python排序       |\n");
    printf("|                          |\n");  
    printf("|        5.Java排序        |\n");
    printf("|                          |\n");              
    printf("|--------------------------|\n");
    char ch;
    ch = getch();
    switch (ch) {
        case '1' : {
            Student_main_interface(p -> number);
            break;
        }
        case '2' : {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                Query_class_grades(p);
            }             
            break; 
        }
        case '3' : {
            haogege(1, n -> next, p);
            break;
        }
        case '4' : {
            haogege(2, n -> next, p);
            break;
        }
        case '5' : {
            haogege(3, n -> next, p);
            break;
        }
        default : {
            Query_class_grades(p);
        }
    }    
    return;
}

//成绩分析
void Performance_analysis(Stu *p) {
    system("cls");
    Stu *m = NULL;
    if (strcmp(p -> class, "网络1班") == 0) {
        m = class1;
    } else if (strcmp(p -> class, "网络2班") == 0) {
        m = class2;
    } else if (strcmp(p -> class, "网络3班") == 0) {
        m = class3;
    } else if (strcmp(p -> class, "网络4班") == 0) {
        m = class4;
    } else if (strcmp(p -> class, "网络5班") == 0) {
        m = class5;
    }
    double c = 0, python = 0, java = 0;
    int sum = 0, cp = 1, pp = 1, jp = 1, ap = 1;
    int add = 0, all = 0;
    all = p -> c + p -> python + p -> java;
    Stu *n = m -> next;
    while (n) {
        add = 0;
        add = n -> c + n -> java + n -> python;
        if (add > all) {
            ap++;
        }
        if (n -> c > p -> c) {
            cp++;
        }
        if (n -> python > p -> python) {
            pp++;
        }
        if (n -> java > p -> java) {
            jp++;
        }
        c += (double)(n -> c);
        python += (double)(n->python);
        java += (double)(n -> java);
        sum++;
        n = n -> next; 
    }
    c = (double)(c / sum);
    python = (double)(python / sum);
    java = (double)(java / sum);
    printf("==%s==\n\n", p -> name);
    printf("C语言在班级排名：%d, 超越了本班%%%2lf的人\n", cp, ((double)(sum - cp + 1) / sum) * 100);
    if (c <= (double)(p -> c)) {
        printf("C语言在班级处于中上游，继续保持！！！\n");
    } else {
        printf("C语言考的有点拉，还得继续努力！！！\n");
    }
    printf("\n");
    printf("Python在班级排名：%d, 超越了本班%%%2lf的人\n", pp, ((double)(sum - pp + 1) / sum) * 100);
    if (python <= (double)(p -> python)) {
        printf("Python在班级处于中上游，继续保持！！！\n");
    } else {
        printf("Python考的有点拉，还得继续努力！！！\n");
    }
    printf("\n");
    printf("Java在班级排名：%d, 超越了本班%%%2lf的人\n", jp, ((double)(sum - jp + 1) / sum) * 100);
    if (java <= (double)(p -> java)) {
        printf("Java在班级处于中上游，继续保持！！！\n");
    } else {
        printf("Java考的有点拉，还得继续努力！！！\n");
    }
    printf("\n");
    printf("班级总排名为：%d", ap);
    printf("\n");
    printf("\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|     1.返回学生主界面     |\n");
    printf("|                          |\n");
    printf("|        2.退出程序        |\n");
    printf("|                          |\n");
    printf("|--------------------------|\n");
    char ch;
    ch = getch();
    switch (ch) {
        case '1' : {
            Student_main_interface(p -> number);
            break;
        }
        case '2' : {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                Performance_analysis(p);
            }             
            break; 
        }
        default : {
            Performance_analysis(p);
        }
    }    
    return;
}

//成绩申诉
void Performance_appeal(Stu *p) {
    system("cls");
    printf("请输入你的申诉内容：\n");
    FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\成绩申诉.txt", "a");
    char content[500] = {0};
    gets(content);
    fprintf(fp, "%s %s %s\n", p -> name, p -> number, content);
    fclose(fp);
    printf("\n\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|     1.返回学生主界面     |\n");
    printf("|                          |\n");
    printf("|        2.退出程序        |\n");
    printf("|                          |\n");
    printf("|--------------------------|\n");
    char ch;
    ch = getch();
    switch (ch) {
        case '1' : {
            Student_main_interface(p -> number);
            break;
        }
        case '2' : {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                Performance_appeal(p);
            }             
            break; 
        }
        default : {
            Performance_appeal(p);
        }
    }     
    return;
}

//增加学生信息
void Increase_students(char *account) {
    system("cls");
    printf("选择该学生的班级：\n");
    printf("1.网络一班\n");
    printf("2.网络二班\n");
    printf("3.网络三班\n");
    printf("4.网络四班\n");
    printf("5.网络五班\n");
    Stu *m = (Stu *)malloc(sizeof(Stu));
    m -> next = NULL;
    Stu *p = NULL;
    char ch;
    fflush(stdin);
    ch = getch();
    switch (ch) {
        case '1' : {
            strcpy(m -> class, "网络1班");
            p = class1;
            break;
        }
        case '2' : {
            strcpy(m -> class, "网络2班");
            p = class2;
            break;
        }
        case '3' : {
            strcpy(m -> class, "网络3班");
            p = class3;
            break;
        }
        case '4' : {
            strcpy(m -> class, "网络4班");
            p = class4;
            break;
        }
        case '5' : {
            strcpy(m -> class, "网络5班");
            p = class5;
            break;
        }
        default : {
            Increase_students(account);
            break;
        }
    }
    Stu *n = p;
    while (n -> next) {
        n = n -> next;
    }
    strcpy(m -> number, n -> number);
    if (m -> number[4] == '9') {
        if (m -> number[3] == '9') {
            m -> number[2]++;
        } else {
            m -> number[3]++;
        }
    } else {
        m -> number[4]++;
    }
    printf("请输入新学生的姓名：");
    gets(m -> name);
    printf("\n");
    printf("请输入新学生的C语言成绩：");
    int c = 0;
    scanf("%d", &c);
    while (c < 0 || c > 100) {
        printf("您输入的C语言成绩有误请重新输入...\n");
        scanf("%d", &c);
    }
    m -> c = c;
    printf("\n");
    printf("请输入新学生的Python成绩：");
    int python = 0;
    scanf("%d", &python);
    while (python < 0 || python > 100) {
        printf("您输入的Python成绩有误请重新输入...\n");
        scanf("%d", &python);
    }
    m -> python = python;
    printf("\n");
    printf("请输入新学生的Java成绩：");
    int java = 0;
    scanf("%d", &java);
    while (java < 0 || java > 100) {
        printf("您输入的Java成绩有误请重新输入...\n");
        scanf("%d", &java);
    }    
    m -> java = java;
    while (p -> next) {
        p = p -> next;           //找最后一个结点
    }
    p -> next = m;
    if (m -> number[1] == '1') {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class1.txt", "a");
        fprintf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, m -> c, m -> python, m -> java);
        fclose(fp);
    } else if (m -> number[1] == '2') {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class2.txt", "a");
        fprintf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, m -> c, m -> python, m -> java);
        fclose(fp);        
    } else if (m -> number[1] == '3') {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class3.txt", "a");
        fprintf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, m -> c, m -> python, m -> java);
        fclose(fp);        
    } else if (m -> number[1] == '4') {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class4.txt", "a");
        fprintf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, m -> c, m -> python, m -> java);
        fclose(fp);        
    } else if (m -> number[1] == '5') {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class5.txt", "a");
        fprintf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, m -> c, m -> python, m -> java);
        fclose(fp);        
    }
    system("cls");
    printf("添加成功！！！");
    Sleep(1000);
    system("cls");
    Teacher_main_interface(account);
    return;
}

//删除学生
void Delete_students(char *account) {
    system("cls");
    printf("请输入您要删除学生的学号：");
    char number[20] = {0};
    fflush(stdin);
    gets(number);
    Stu *m = NULL;
    Stu *n = NULL;
    if (number[1] == '1') {
        m = class1;
    } else if (number[1] == '2') {
        m = class2;
    } else if (number[1] == '3') {
        m = class3;
    } else if (number[1] == '4') {
        m = class4;
    } else if (number[1] == '5') {
        m = class5;
    }
    n = m;
    Stu *p = search(number);
    if (m -> next == p) {
        m -> next = p -> next; 
    } else {
        while (n) {
            if (n -> next == p) {
               n -> next = p -> next;
               break;
            }
        n = n -> next;
        }
    }
    m = m -> next;
    if (number[1] == '1') {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class1.txt", "w");
        while (m) {
            fprintf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, m -> c, m -> python, m -> java);
            m = m -> next;
        }
        fclose(fp);
    } else if (number[1] == '2') {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class2.txt", "w");
        while (m) {
            fprintf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, m -> c, m -> python, m -> java);
            m = m -> next;
        }
        fclose(fp);
    } else if (number[1] == '3') {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class3.txt", "w");
        while (m) {
            fprintf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, m -> c, m -> python, m -> java);
            m = m -> next;
        }
        fclose(fp);
    } else if (number[1] == '4') {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class4.txt", "w");
        while (m) {
            fprintf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, m -> c, m -> python, m -> java);
            m = m -> next;
        }
        fclose(fp);
    } else if (number[1] == '5') {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class5.txt", "w");
        while (m) {
            fprintf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, m -> c, m -> python, m -> java);
            m = m -> next;
        }
        fclose(fp);
    }
    system("cls");
    printf("删除成功！");
    Sleep(1000);
    system("cls");
    Teacher_main_interface(account);
    return;
}

//修改信息
void Modify_information(char *account) {
    system("cls");
    char number[20] = {0};
    printf("请输入您要修改学生的学号：");
    fflush(stdin);
    gets(number);
    Stu *m = NULL;
    if (number[1] == '1') {
        m = class1;
    } else if (number[1] == '2') {
        m = class2;
    } else if (number[1] == '3') {
        m = class3;
    } else if (number[1] == '4') {
        m = class4;
    } else if (number[1] == '5') {
        m = class5;
    }
    Stu *p = search(number); 
    Modify(p);
    m = m -> next;
    if (number[1] == '1') {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class1.txt", "w");
        while (m) {
            fprintf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, m -> c, m -> python, m -> java);
            m = m -> next;
        }
        fclose(fp);
    } else if (number[1] == '2') {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class2.txt", "w");
        while (m) {
            fprintf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, m -> c, m -> python, m -> java);
            m = m -> next;
        }
        fclose(fp);
    } else if (number[1] == '3') {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class3.txt", "w");
        while (m) {
            fprintf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, m -> c, m -> python, m -> java);
            m = m -> next;
        }
        fclose(fp);
    } else if (number[1] == '4') {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class4.txt", "w");
        while (m) {
            fprintf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, m -> c, m -> python, m -> java);
            m = m -> next;
        }
        fclose(fp);
    } else if (number[1] == '5') {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class5.txt", "w");
        while (m) {
            fprintf(fp, "%s %s %s %d %d %d\n", m -> name, m -> number, m -> class, m -> c, m -> python, m -> java);
            m = m -> next;
        }
        fclose(fp);
    }
    system("cls");
    printf("修改成功！");
    Sleep(1000);
    system("cls");
    Teacher_main_interface(account);
    return;
} 

//修改
void Modify(Stu *p) {
    system("cls");
    printf("选择您要修改的内容：\n\n");
    printf("1.C语言\n");
    printf("2.Python\n"); 
    printf("3.Java\n");  
    char ch;
    fflush(stdin);
    ch = getch();
    switch (ch) {
        case '1' : {
            p -> c = 0;
            printf("请输入C语言新成绩：");
            scanf("%d", &p -> c);
            while (p -> c < 0 || p -> c > 100) {
                printf("输入的成绩有误请重新输入...");
                scanf("%d", &p -> c);
            }
            break;
        } 
        case '2' : {
            p -> python = 0;
            printf("请输入Python新成绩：");
            scanf("%d", &p -> python);
            while (p -> python < 0 || p -> python > 100) {
                printf("输入的成绩有误请重新输入...");
                scanf("%d", &p -> python);
            }
            break;
        }
        case '3' : {
            p -> java = 0;
            printf("请输入Java新成绩：");
            scanf("%d", &p -> java);
            while (p -> java < 0 || p -> java > 100) {
                printf("输入的成绩有误请重新输入...");
                scanf("%d", &p -> java);
            }
            break;
        }
        default : {
            Modify(p);
        }
    } 
    return;
}

//查询学生信息
void Inquire_students(char *number, char *account) {
    system("cls");
    Stu *p = NULL;
    p = search(number);
    printf("\n");
    printf("姓名：   %s\n", p -> name);
    printf("学号：   %s\n", p -> number);
    printf("班级：   %s\n", p -> class);
    printf("C语言:   %d\n", p -> c);
    printf("Python： %d\n", p -> python);
    printf("Java：   %d\n", p -> java);
    printf("\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|     1.返回教师主界面     |\n");
    printf("|                          |\n");
    printf("|        2.退出程序        |\n");
    printf("|                          |\n");
    printf("|--------------------------|\n");
    char ch;
    fflush(stdin);
    ch = getch();
    switch (ch) {
        case '1' : {
            Teacher_main_interface(account);
            break;
        }
        case '2' : {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                Inquire_students(number, account);
            }             
            break; 
        }
        default : {
            Inquire_students(number, account);
        }
    }      
    return;
}

//查询班级成绩
void Query_class_grades1(char *account) {
    system("cls");
    printf("请选择您要查询的班级\n");
    printf("1.网络一班\n");
    printf("2.网络二班\n");
    printf("3.网络三班\n");
    printf("4.网络四班\n");
    printf("5.网络五班\n");
    Stu *p = NULL;
    Stu *n = NULL;
    char ch;
    ch = getch();
    switch (ch) {
        case '1' : {
            p = class1;
            break;
        }
        case '2' : {
            p = class2;
            break;
        }
        case '3' : {
            p = class3;
            break;
        }
        case '4' : {
            p = class4;
            break;
        }
        case '5' : {
            p = class5;
            break;
        }
        default : {
            Query_class_grades1(account);
            break;
        }
    }
    n = p;
    system("cls");
    traverse_list(p);
    printf("\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|     1.返回教师主界面     |\n");
    printf("|                          |\n");
    printf("|        2.退出程序        |\n");
    printf("|                          |\n");            
    printf("|--------------------------|\n");
    char w;
    w = getch();
    switch (w) {
        case '1' : {
            Teacher_main_interface(account);
            break;
        }
        case '2' : {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                Query_class_grades1(account);
            }             
            break; 
        }
        default : {
            Query_class_grades1(account);
        }
    }      
    return;
}

//提醒管理员进行成绩的更新
void Reminder_update(char *account) {
    system("cls");
    FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\提醒管理员进行成绩的更新.txt", "a");
    char neirong[100] = {"有老师提醒您进行成绩的更新！！！"};
    fprintf(fp, "%s", neirong);
    fclose(fp);
    system("cls");
    printf("提醒成功！");
    Sleep(1000);
    system("cls");
    Teacher_main_interface(account);
    return;
}

//弹出老师提醒
void Teacher_reminder(void) {
    system("cls");
    FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\提醒管理员进行成绩的更新.txt", "r"); 
    if (!feof(fp)) {
        char neirong[100];
        fscanf(fp, "%s", neirong);
        puts(neirong);
        printf("\n");
        printf("1.我已知晓！");
        char ch;
        ch = getch();
        switch (ch) {
            case '1' : {
                fclose(fp);
                FILE *w = fopen("D:\\VScode\\学生管理系统\\学生信息\\提醒管理员进行成绩的更新.txt", "w"); 
                fclose(w); 
                break;
            }
            default : {
                Teacher_reminder();
                break;
            }
        }        
    } else {
        fclose(fp);
        return;
    }
    fclose(fp);
    return;
}

//班级成绩分析
void Analysis_class_performance(char *account) {
    system("cls");
    Stu *p = NULL;
    printf("请选择班级：\n");
    printf("1.网络一班\n");
    printf("2.网络二班\n");
    printf("3.网络三班\n");
    printf("4.网络四班\n");
    printf("5.网络五班\n");
    char ch;
    ch = getch();
    system("cls");
    switch (ch) {
        case '1' : {
            printf("\t==网络一班==\n\n");
            p = class1;
            break;
        }
        case '2' : {
            printf("\t==网络二班==\n\n");
            p = class2;
            break;
        }
        case '3' : {
            printf("\t==网络三班==\n\n");
            p = class3;
            break;
        }
        case '4' : {
            printf("\t==网络四班==\n\n");
            p = class4;
            break;
        }
        case '5' : {
            printf("\t==网络五班==\n\n");
            p = class5;
            break;
        }
        default : {
            Analysis_class_performance(account);
            break;
        }
    }
    p = p -> next;
    int sum = 0;     //总人数
    int cb = 0, pb = 0, jb = 0;   //不及格人数
    int cm = 0;          //最高成绩
    char cgn[10] = {0};     //最高成绩姓名
    int pm = 0;          //最高成绩
    char pgn[10] = {0};     //最高成绩姓名
    int jm = 0;          //最高成绩
    char jgn[10] = {0};     //最高成绩姓名
    int zong = 0;      //总分
    char zf[10] = {0};    //总分最高名字
    while (p) {
        if (p -> c + p -> python + p -> java > zong) {
            zong = p -> c + p -> python + p -> java;
            strcpy(zf, p -> name);
        }
        if (p -> c < 60) {
            cb++;
        }
        if (p -> python < 60) {
            pb++;
        }
        if (p -> java < 60) {
            jb++;
        }
        if (p -> c > cm) {
            cm = p -> c;
            strcpy(cgn, p -> name);
        }
        if (p -> python > pm) {
            pm = p -> python;
            strcpy(pgn, p -> name);
        }
        if (p -> java > jm) {
            jm = p -> java;
            strcpy(jgn, p -> name);
        }
        sum++;
        p = p -> next;
    }
    printf("C语言不及格人数为：%d 人, 及格率为%%%lf\n", cb, ((double)(sum - cb) / sum) * 100);
    printf("Python不及格人数为：%d 人, 及格率为%%%lf\n", pb, ((double)(sum - pb) / sum) * 100);
    printf("Java不及格人数为：%d 人, 及格率为%%%lf\n\n", jb, ((double)(sum - jb) / sum) * 100);
    printf("C语言 %s 是最高分, 为%d\n", cgn, cm);
    printf("Python %s 是最高分, 为%d\n", pgn, pm);
    printf("Java %s 是最高分, 为%d\n", jgn, jm);
    printf("全班总分最高为 %s, 总分为 %d\n", zf, zong);
    printf("\n\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|     1.返回教师主界面     |\n");
    printf("|                          |\n");
    printf("|        2.退出程序        |\n");
    printf("|                          |\n");
    printf("|--------------------------|\n");
    char o;
    o = getch();
    switch (o) {
        case '1' : {
            Teacher_main_interface(account);
            break;
        }
        case '2' : {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                Analysis_class_performance(account);
            }             
            break; 
        }
        default : {
            Analysis_class_performance(account);
        }
    }     
    return;
}

//学生提醒
void Student_reminder(void) {
    system("cls");
    FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\成绩申诉.txt", "r");
    if (fgetc(fp) != EOF) {
        fclose(fp);
        printf("有同学提交了成绩申诉！\n\n");
        printf("1.我已知晓！\n");
        char ch;
        ch = getch();
        switch (ch) {
            case '1' : {
                return;
                break;
            }
            default : {
                Student_reminder();
            }
        }
    }
    fclose(fp);
    system("cls");
    return;
}

//查看代办
void View_agent(void) {
    system("cls");
    FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\成绩申诉.txt", "r");
    if (fgetc(fp) != EOF) {
        char name[20] = {0};
        char number[10] = {0};
        char content[500] = {0};
        printf("==代办内容==\n\n");
        fseek(fp, 0, SEEK_SET);
        while (!feof(fp)) {
            memset(name, 0, sizeof(char) * 20);
            memset(number, 0, sizeof(char) * 10);
            memset(content, 0, sizeof(char) * 500);
            fscanf(fp, "%s %s %s\n", name, number, content);
            printf("%s %s %s\n", name, number, content);
        }
        fclose(fp);
        FILE *w = fopen("D:\\VScode\\学生管理系统\\学生信息\\成绩申诉.txt", "w"); 
        fclose(w); 
    } else {
        fclose(fp);
        printf("暂无待办项目！");
    }
    

    printf("\n\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|    1.返回管理员主界面    |\n");
    printf("|                          |\n");
    printf("|        2.退出程序        |\n");
    printf("|                          |\n");
    printf("|--------------------------|\n");
    char o;
    o = getch();
    switch (o) {
        case '1' : {
            Administrator_main_interface();
            break;
        }
        case '2' : {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                View_agent();
            }             
            break; 
        }
        default : {
            View_agent();
        }
    } 
    return;
} 

//进入教师界面
void Teacher_interface(char *account) {
    system("cls");
    printf("|--------------------------|\n");
    printf("|        教师主界面        |\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|    1.增加新的学生信息    |\n");
    printf("|                          |\n");
    printf("|      2.删除学生信息      |\n");
    printf("|                          |\n");
    printf("|      3.修改学生信息      |\n");
    printf("|                          |\n");
    printf("|      4.查询学生信息      |\n");
    printf("|                          |\n");
    printf("|      5.输出班级成绩      |\n");
    printf("|                          |\n");
    printf("|        6.成绩分析        |\n");
    printf("|                          |\n");
    printf("|    7.返回管理员主界面    |\n");
    printf("|                          |\n");
    printf("|      8.返回登陆界面      |\n");
    printf("|                          |\n");
    printf("|        9.修改密码        |\n");
    printf("|                          |\n");
    printf("|        0.退出程序        |\n");
    printf("|                          |\n");
    printf("|--------------------------|\n"); 
    char ch;
    ch = getch();
    switch (ch) {
        case '1' : {
            Increase_students(account);
            break;
        } 
        case '2' : {
            Delete_students(account);
            break;
        }
        case '3' : {
            Modify_information(account);
            break;
        } 
        case '4' : {
            system("cls");
            printf("请输入该学生的学号：");
            char number[20];
            gets(number);
            Inquire_students(number, account);
            break;
        } 
        case '5' : {
            Query_class_grades1(account);
            break;
        } 
        case '6' : {
            Analysis_class_performance(account);
            break;
        } 
        case '7' : {
            Administrator_main_interface();
            break;
        } 
        case '8' : {
            Login_interface();
            break;
        } 
        case '9' : {
            Change_Password3(account);
            break;
        }
        case '0' : {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                Teacher_main_interface(account);
            }            
            break;
        }
        default : {
            Teacher_main_interface(account);
            break;
        }
    }     
    return;
}

//增加账号和密码
void Add_account_number(void) {
    system("cls");
    printf("请选择您要增加账号的类型：\n");
    printf("1.学生\n");
    printf("2.教师\n");
    printf("3.返回\n");
    char ch;
    fflush(stdin);
    ch = getch();
    switch (ch) {
        case '1' : {
            Student_registration1();
            break;
        }
        case '2' : {
            Teacher_registration1();
            break;
        }
        case '3' : {
            Administrator_main_interface();
            break;
        }
        default : {
            Add_account_number();
            break;
        }
    }
    return;
}

//管理员增加学生账号
void Student_registration1(void) {
    system("cls");
    printf("学生注册界面\n\n");
    char account[20] = {0};
    char password[20] = {0};
    Acc *p = student;
    int flag = 0;
    char ch;
    char confirm[20] = {0};
    system("cls");
    printf("请输入你的学号：");
    gets(account);
    while (p) {
        if (strcmp(account, p -> account) == 0) {
            flag = 1;
            break;
        }
        p = p -> next;
    }
    if (flag == 0) {
        printf("密码：");
        secretword(password);
        printf("确认密码：");
        secretword(confirm);
        if (strcmp(password, confirm) != 0) {
            system("cls");
            printf("输入的两次密码不一致，请重新输入...");
            Sleep(1000);
            system("cls");
            Student_registration1();
            return;
        }
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\学生账号和密码.txt", "a");
        fprintf(fp, "%s %s %s %s\n", account, account, password, "学生");
        fclose(fp);
        student = Student_account();
        system("cls");
        printf("增加成功，正在返回管理员主界面，请稍等...");
        Sleep(1000);
        system("cls");
        Administrator_main_interface();        
    } else {
        system("cls");
        printf("输入的学号已被注册请重新输入...");
        Sleep(1000);
        system("cls");
        Student_registration1();
    }
    return;    
}

//管理员增加教师账号
void Teacher_registration1(void) {
    system("cls");
    printf("教师注册界面\n\n");
    char account[20] = {0};
    char password[20] = {0};
    Acc *p = teacher;
    char ch[20];
    int flag = 0;
    memset(ch, 0, sizeof(char) * 20);
    printf("你想注册的账号：");
    fflush(stdin);
    gets(account);
    while (p) {
        strcpy(ch, p -> account);
        if (strcmp(ch, account) == 0) {
            flag = 1;
            break;
        }
        p = p -> next;
    }
    if (flag == 1) {
        system("cls");
        printf("该账号已被注册，请重新输入...");
        Sleep(1000);
        system("cls");
        Teacher_registration();
    } else {
        memset(ch, 0, sizeof(char) * 20);
        printf("密码：");
        secretword(password);
        printf("确认密码：");
        secretword(ch);
        if (strcmp(ch, password) != 0) {
            system("cls");
            printf("两次输入密码不一致，请重新输入...");
            Sleep(1000);
            Teacher_registration();
            return;
        }
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\教师账号和密码.txt", "a");
        fprintf(fp, "%s %s %s\n", account, password, "教师");
        fclose(fp);
        teacher = Teacher_account();
        system("cls");
        printf("增加成功，正在返回管理员主界面，请稍等...");
        Sleep(1000);
        system("cls");
        Administrator_main_interface();
    }
    return;    
}

//删除账号及其密码
void Delete_account(void) {
    system("cls");
    printf("请选择你要删除账号的类型：\n");
    printf("1.学生\n");
    printf("2.教师\n");
    printf("3.返回\n");
    int i = 0;
    Acc *p = NULL;
    char ch;
    fflush(stdin);
    ch = getch();
    switch (ch) {
        case '1' : {
            i = 1;
            p = student;
            break;
        }
        case '2' : {
            i = 2;
            p = teacher;
            break;
        }
        case '3' : {
            Administrator_main_interface();
            break;
        }
        default : {
            Delete_account();
            break;
        }
    }
    system("cls");
    Acc *m = NULL;
    Acc *n = NULL;
    m = p;
    n = p;
    char account[20];
    fflush(stdin);
    printf("请输入您要删除的账号：");
    gets(account);
    while (p) {
        if (strcmp(p -> account, account) == 0) {
            break;
        }
        p = p -> next;
    }
    if (!p) {
        system("cls");
        printf("您输入的账号有误，请重新选择输入...");
        Sleep(1000);
        system("cls");
        Delete_account();
        return;
    }
    if (m -> next == p) {
        m = m -> next;
    } else {
        while (n -> next != p) {
            n = n -> next;
        }
        n -> next = p -> next;
    }
    m = m -> next;
    if (i == 1) {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\学生账号和密码.txt", "w");
        while (m) {
            fprintf(fp, "%s %s %s\n", m -> account, m -> password, "学生");
            m = m -> next;
        }
        fclose(fp);
    } else if (i == 2) {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\教师账号和密码.txt", "w");
        while (m) {
            fprintf(fp, "%s %s %s\n", m -> account, m -> password, "学生");
            m = m -> next;
        }
        fclose(fp);
    }
    system("cls");
    printf("删除成功，正在返回管理员主界面...");
    Sleep(1000);
    system("cls");
    Administrator_main_interface();
    return;
}

//修改账号及密码
void Change_account_number_and_password(void) {
    system("cls");
    printf("请选择你要修改账号的类型：\n");
    printf("1.学生\n");
    printf("2.教师\n");
    printf("3.返回\n");
    int i = 0;
    Acc *p = NULL;
    char ch;
    fflush(stdin);
    ch = getch();
    switch (ch) {
        case '1' : {
            i = 1;
            p = student;
            break;
        }
        case '2' : {
            i = 2;
            p = teacher;
            break;
        }
        case '3' : {
            Administrator_main_interface();
            break;
        }
        default : {
            Change_account_number_and_password();
            break;
        }
    }
    system("cls");
    Acc *m = NULL;
    m = p;
    printf("请输入您要修改的账号：");
    char account[20] = {0};
    gets(account);
    while (p) {
        if (strcmp(p -> number, account) == 0) {
            break;
        }
        p = p -> next;
    }
    if (!p) {
        system("cls");
        printf("您输入的账号有误，请重新选择输入...");
        Sleep(1000);
        system("cls");
        Change_account_number_and_password();
        return;
    }
    Change(m, p);
    m = m -> next;
    if (i == 1) {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\学生账号和密码.txt", "w");
        while (m) {
            fprintf(fp, "%s %s %s %s\n", m -> number, m -> account, m -> password, "学生");
            m = m -> next;
        }
        fclose(fp);
    } else if (i == 2) {
        FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\教师账号和密码.txt", "w");
        while (m) {
            fprintf(fp, "%s %s %s\n", m -> account, m -> password, "教师");
            m = m -> next;
        }
        fclose(fp);
    }
    Administrator_main_interface();
    return;
}

//修改
void Change(Acc *m, Acc *p) {
    system("cls");
    printf("请输入您要修改的类型：\n");
    printf("1.账号\n");
    printf("2.密码\n");
    printf("3.返回管理员主界面\n");
    char ch[20] = {0};
    char w;
    fflush(stdin);
    w = getch();
    switch (w) {
        case '1' : {
            system("cls");
            printf("请输入新的账号：");
            gets(ch);
            Acc *q = NULL;
            q = m;
            while (q) {
                if (strcmp(ch, q -> number) == 0) {
                    system("cls");
                    printf("该账号已被使用请重新修改...");
                    Sleep(1000);
                    system("cls");
                    Change(m, p);
                    return;
                }
                q = q -> next;
            }
            memset(p -> number, 0, sizeof(char) * 20);
            printf("确认账号：");
            gets(p -> number);
            if (strcmp(ch, p -> number) == 0) {
                system("cls");
                printf("修改成功，正在返回管理员主界面...");
                Sleep(1000);
                system("cls");
                return;
            } else {
                system("cls");
                printf("两次输入的账号不一致，请重新选择输入...");
                Sleep(1000);
                system("cls");
                Change(m, p);
                return;
            }
            break;
        }
        case '2' : {
            memset(p -> password, 0, sizeof(char) * 20);
            system("cls");
            printf("请输入新的密码：");
            secretword(p -> password);
            printf("确认密码：");
            secretword(ch);
            if (strcmp(ch, p -> password) == 0) {
                system("cls");
                printf("修改成功，正在返回管理员主界面...");
                Sleep(1000);
                system("cls");
                return;
            } else {
                system("cls");
                printf("两次输入的密码不一致，请重新选择输入...");
                Sleep(1000);
                system("cls");
                Change(m, p);
                return;
            }
            break;
        }
        case '3' : {
            Administrator_main_interface();
            break;
        }
        default : {
            Change(m, p);
            break;
        }
    }
    return;
}

//查找账号及密码
void Find_account_number_and_password(void) {
    system("cls");
    printf("请选择您要查找账号的类型：\n");
    printf("1.学生\n");
    printf("2.教师\n");
    printf("3.返回\n");
    char ch;
    int i = 0;
    Acc *p = NULL;
    fflush(stdin);
    ch = getch();
    switch (ch) {
        case '1' : {
            i = 1;
            p = student;
            break;
        }
        case '2' : {
            i = 2;
            p = teacher;
            break;
        }
        case '3' : {
            Administrator_main_interface();
            break;
        }
        default : {
            Find_account_number_and_password();
            break;
        }
    }
    Acc *m = NULL;
    m = p;
    system("cls");
    printf("请输入您要查找的账号：");
    char account[20] = {0};
    gets(account);
    if (i == 1) {
        while (p) {
            if (strcmp(account, p -> number) == 0) {
                break;
            }
            p = p -> next;
        }
        if (!p) {
            system("cls");
            printf("您输入账号还未注册...");
            Sleep(1000);
            system("cls");
            Administrator_main_interface();
            return;
        }
        rangnian(i, p);
        return;
    }
    if (i == 2) {
        while (p) {
            if (strcmp(account, p -> account) == 0) {
                break;
            }
            p = p -> next;
        }
        if (!p) {
            system("cls");
            printf("您输入账号还未注册...");
            Sleep(1000);
            system("cls");
            Administrator_main_interface();
            return;
        }
        rangnian(i, p);
        return;
    }
    return;
}

//让你乱按
void rangnian(int i, Acc *p) {
    system("cls");
    if (i == 1) {
        printf("\n账号：%s\n密码：%s\n", p -> number, p -> password);
    } else {
        printf("\n账号：%s\n密码：%s\n", p -> account, p -> password);
    }
    printf("\n0.返回管理员主界面\n");
    char o;
    o = getch();
    switch (o) {
        case '0' : {
            Administrator_main_interface();
            break;
        }
        default : {
            rangnian(i, p);
            break;
        }
    }
    return;
}

//输出所有的账号及密码
void Output_all_accounts_and_passwords(void) {
    system("cls");
    Acc *p = NULL;
    p = student -> next;
    printf("==学生==\n\n");
    printf("账号\t\t密码\n");
    if (!p) {
        printf("没有学生注册账号！！！");
    }
    while (p) {
        printf("%-16s%s\n", p -> number, p -> password);
        p = p -> next;
    }
    printf("\n");
    p = teacher -> next;
    printf("==教师==\n\n");
    printf("账号\t\t密码\n");
    if (!p) {
        printf("没有教师注册账号！！！");
    }
    while (p) {
        printf("%-16s%s\n", p -> account, p -> password);
        p = p -> next;
    }
    printf("\n0.返回\n");
    char ch;
    fflush(stdin);
    ch = getch();
    switch (ch) {
        case '0' : {
            Administrator_main_interface();
            break;
        }
        default : {
            Output_all_accounts_and_passwords();
            break;
        }
    }
    return;
}

//录入所有账号及密码
void Enter_all_accounts_and_passwords(void) {
    system("cls");
    FILE *fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\所有账号及密码.txt", "w");    
    Acc *p = NULL;
    p = student -> next;
    fprintf(fp, "%s\n", "学生账号及密码");
    while (p) {
        fprintf(fp, "%s %s\n", p -> number, p -> password);
        p = p -> next;
    }
    p = teacher -> next;
    fprintf(fp, "%s\n", "教师账号及密码");
    while (p) {
        fprintf(fp, "%s %s\n", p -> account, p -> password);
        p = p -> next;
    }
    fclose(fp);
    printf("录入成功！");
    Sleep(1000);
    Administrator_main_interface();
    return;
}

//手动重新录入学生信息
void Manually_re_input_student_information(void) {
    system("cls");
    fflush(stdin);
    printf("请选择你要重新录的班级：\n\n");
    printf("1.网络一班\n");
    printf("2.网络二班\n");
    printf("3.网络三班\n");
    printf("4.网络四班\n");
    printf("5.网络五班\n");
    printf("6.返回\n");
    FILE *fp = NULL;
    Stu *p = (Stu *)malloc(sizeof(Stu));
    char ch;
    fflush(stdin);
    ch = getch();
    switch (ch) {
        case '1' : {
            strcpy(p -> class, "网络一班");
            fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class1.txt", "w");
            break;
        }
        case '2' : {
            strcpy(p -> class, "网络二班");
            fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class2.txt", "w");
            break;
        }
        case '3' : {
            strcpy(p -> class, "网络三班");
            fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class3.txt", "w");
            break;
        }
        case '4' : {
            strcpy(p -> class, "网络四班");
            fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class4.txt", "w");
            break;
        }
        case '5' : {
            strcpy(p -> class, "网络五班");
            fp = fopen("D:\\VScode\\学生管理系统\\学生信息\\class5.txt", "w");
            break;
        }
        case '6' : {
            fclose(fp);
            Administrator_main_interface();
            break;
        }
        default : {
            fclose(fp);
            Manually_re_input_student_information();
            break;
        }
    }
    char a = '1';
    while (a != '0') {
        system("cls");
        memset(p -> number, 0, sizeof(char) * 10);
        memset(p -> name, 0, sizeof(char) * 20);
        p -> c = 0;
        p -> python = 0;
        p -> java = 0;
        printf("请输入姓名：");
        fflush(stdin);
        gets(p -> name);
        xuehao(p);
        printf("请输入C语言成绩：");
        fflush(stdin);
        scanf("%d", &p -> c);
        while (p -> c < 0 || p -> c > 100) {
            printf("您输入的成绩有误，请重新输入...\n");
            printf("请输入C语言成绩：");
            scanf("%d", &p -> c);
        }
        printf("请输入Python成绩：");
        fflush(stdin);
        scanf("%d", &p -> python);
        while (p -> python < 0 || p -> python > 100) {
            printf("您输入的成绩有误，请重新输入...\n");
            printf("请输入Python成绩：");
            scanf("%d", &p -> python);
        }
        printf("请输入Java成绩：");
        fflush(stdin);
        scanf("%d", &p -> java);
        while (p -> java < 0 || p -> java > 100) {
            printf("您输入的成绩有误，请重新输入...\n");
            printf("请输入Java成绩：");
            scanf("%d", &p -> java);
        }
        fprintf(fp, "%s %s %s %d %d %d\n", p -> name, p -> number, p -> class, p -> c, p -> python, p -> java);
        printf("0.退出录入\n");
        fflush(stdin);
        a = getch();
        if (a == '0') {
            break;
        }
    }
    fclose(fp);
    system("cls");
    printf("正在返回管理员主界面...");
    Sleep(1000);
    system("cls");
    Administrator_main_interface();
    return;
}

//学号
void xuehao(Stu *p) {
    printf("请输入学号：");
    fflush(stdin);
    gets(p -> number);
    char o = 0;
    if (strcmp(p -> class, "网络一班") == 0) {
        o = '1';
    } else if (strcmp(p -> class, "网络二班") == 0) {
        o = '2';
    } else if (strcmp(p -> class, "网络三班") == 0) {
        o = '3';
    } else if (strcmp(p -> class, "网络四班") == 0) {
        o = '4';
    } else if (strcmp(p -> class, "网络五班") == 0) {
        o = '5';
    }
    if (p -> number[1] != o) {
        printf("您输入的学号有误请重新输入...\n");
        xuehao(p);
    }
    return;
}

//c排序
void bubblesort1(Stu* Head) {
    Stu *pre, *cur, *next, *end;//pre前一项 cur当前项 next后一项 end控制循环次数(优化冒泡)
	end = NULL;

	while (Head -> next != end) {
		//初始化三个指针 ; 判断是否到达结束位置 ; 三个指针集体后移
		for (pre = Head, cur = pre -> next, next = cur -> next; next != end; pre = pre -> next, cur = cur -> next, next = next -> next) {
			if (cur -> c > next -> c) {
				pre -> next = next;
				cur -> next = next -> next;
				next -> next = cur;
				Stu *temp = cur; 
                cur = next; 
                next = temp;
			}
		}
		end = cur;
	}
}

//python排序
void bubblesort2(Stu* Head) {
    Stu *pre, *cur, *next, *end;//pre前一项 cur当前项 next后一项 end控制循环次数(优化冒泡)
	end = NULL;

	while (Head -> next != end) {
		//初始化三个指针 ; 判断是否到达结束位置 ; 三个指针集体后移
		for (pre = Head, cur = pre -> next, next = cur -> next; next != end; pre = pre -> next, cur = cur -> next, next = next -> next) {
			if (cur -> python > next -> python) {
				pre -> next = next;
				cur -> next = next -> next;
				next -> next = cur;
				Stu *temp = cur; 
                cur = next; 
                next = temp;
			}
		}
		end = cur;
	}
}

//java排序
void bubblesort3(Stu* Head) {
    Stu *pre, *cur, *next, *end;//pre前一项 cur当前项 next后一项 end控制循环次数(优化冒泡)
	end = NULL;

	while (Head -> next != end) {
		//初始化三个指针 ; 判断是否到达结束位置 ; 三个指针集体后移
		for (pre = Head, cur = pre -> next, next = cur -> next; next != end; pre = pre -> next, cur = cur -> next, next = next -> next) {
			if (cur -> java > next -> java) {
				pre -> next = next;
				cur -> next = next -> next;
				next -> next = cur;
				Stu *temp = cur; 
                cur = next; 
                next = temp;
			}
		}
		end = cur;
	}
} 


void haogege(int i, Stu *n, Stu *p) {
    system("cls");
    if (i == 1) {
        bubblesort1(n);
    } else if (i == 2) {
        bubblesort2(n);
    } else {
        bubblesort3(n);
    }
    traverse_list(n);
    printf("\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|     1.返回学生主界面     |\n");
    printf("|                          |\n");
    printf("|        2.退出程序        |\n");
    printf("|                          |\n");   
    printf("|--------------------------|\n");
    char ch;
    ch = getch();
    switch (ch) {
        case '1' : {
            Student_main_interface(p -> number);
            break;
        }
        case '2' : {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                haogege(i, n, p);
            }             
            break; 
        }
        default : {
            haogege(i, n, p);
        }
    }      
    return;
}

//查找老师
Acc *chazhao(char *account) {
    Acc *p = teacher;
    while (p) {
        if (strcmp(account, p -> account) == 0) {
            return p;
        }
        p = p -> next;
    }
}

//输出本班成绩
void Query_class_grades0(Acc *p, char *account) {
    system("cls");
    if (strcmp(p->number, "网络一班") == 0) {
        traverse_list(class1);
    } else if (strcmp(p->number, "网络二班") == 0) {
        traverse_list(class2);
    } else if (strcmp(p->number, "网络三班") == 0) {
        traverse_list(class3);
    } else if (strcmp(p->number, "网络四班") == 0) {
        traverse_list(class4);
    } else if (strcmp(p->number, "网络五班") == 0) {
        traverse_list(class5);
    }
    printf("\n");
    printf("|--------------------------|\n");
    printf("|                          |\n");
    printf("|     1.返回教师主界面     |\n");
    printf("|                          |\n");
    printf("|        2.退出程序        |\n");
    printf("|                          |\n");
    printf("|--------------------------|\n");
    char ch;
    ch = getch();
    switch (ch) {
        case '1' : {
            Teacher_main_interface(account);
            break;
        }
        case '2' : {
            int flag = exitSys();
            if (flag == 0) {
               system("cls");  //先清屏，再退出
               exit(0);
            } else {
                Query_class_grades0(p, account);
            }             
            break; 
        }
        default : {
            Query_class_grades0(p, account);
        }
    }

}