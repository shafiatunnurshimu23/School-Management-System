/*PROJECT ON TEACHER & STUDENT MANAGEMENT SYSTEM


Admin Panel:
     1.	Login using Function + File
     2.	Create Teacher and student account using Function + File
     3.	Updating Teachers & students Information using Function +  Pointer + File
     4.	Assigning courses to teacher using Function + File
Teacher�s Panel:
     1.	Login using Function + File
     2.	Provide class test marks using Function+ File
     3.	Find the student by the given first name using Function+ File + pointer
     4.	Count of Students using Function+ File
Student�s Panel:
     1.	Login using Function+ File
     2.	Check the class test marks using Function+ File

*/




#include<stdio.h>        //header file for input output function.... standard input output
#include<stdlib.h>       // header file of general purpose standard library
#include<string.h>         //as i have used various functions for manipulating arrays of characters,structure
#define NULL 0         //Definition of a constant Null=0

typedef struct ADMIN//declared a user defined data type admin where structure is used because it a collection of variables User_ID,Password under one name "admin"
{
    char User_ID[100];
    char Password[20];
} admin;
typedef struct TEACHER//declared a user defined data type teacher where structure is used because it a collection of variables User_ID,Password,course1,course2 under one name "teacher"
{
    char User_ID[100];
    char Password[20];
    char course1[101];
    char course2[101];

} teacher;
typedef struct STUDENT//declared a user defined data type student where I structure is used because it a collection of variables User_ID,Password,roll,course1,course2,marks1,marks2 under one name "student"
{
    char User_ID[100];
    char Password[20];
    char roll[100];
    char course1[101];
    char marks1[101];
    char course2[101];
    char marks2[101];


} student;
typedef struct marks//declared a user defined data type std where I struct is used because it a collection of variables User_ID,roll,course1,course2,marks1,marks2 under one name "std"
{
    char User_ID[100];
    char roll[100];
    char course1[101];
    char course2[101];
    char marks1[101];
    char marks2[101];
} std;
int countS=0;//global variable coutS which is initialized with countS=0 and can be used anywhere in this program


int Verify_info_of_admin();//Prototype
int Verify_info_of_teacher();//Prototype

/*Prototype for void function is not needed as it has no return value as well as return type*/

int main()//when the code will be run operating system will call this function at first
{
    int num1;


    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    /*formating and showing the panels*/
    printf("\n###<===TEACHER & STUDENT MANAGEMENT SYSTEM===>###\n");
    printf("\n           ***  Welcome  ***\n\n\n");
    printf("You can log in as\n");
    printf("1.Admin\n2.Teacher\n3.Student\n0.Exit\n\n\n");
    printf("Enter your choice as (1/2/3/0):");
    scanf("%d",&num1);
    if(num1>3)
    {
        printf("ERROR!!! Make a right choice.\n");
        printf("\nYou can--\n1.Go to main menu or\n0.exit\n");
        int num2;
        printf("Enter your choice:");
        scanf("%d",&num2);
        switch(num2)/*to test the variable num2 for equality against a list of values of num3.Same as if...else if.. but syntax easier*/
        {
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            main();

        }
        }

    }

    switch(num1)/*to test the variable num1 for equality against a list of values of num1.Same as if...else if.. but syntax easier*/
    {
    case 0:
    {
        exit(0);
    }
    case 1:
    {
        ADMIN_panel();//calling a void function whose prototype hasn't declared before.After finishing that function's work it will not return any value
        break;
    }
    case 2:
    {
        TEACHER_panel();//calling a void function whose prototype hasn't declared before.After finishing that function's work it will not return any value
        break;
    }
    case 3:
    {
        STUDENT_panel();//calling a void function whose prototype hasn't declared before.After finishing that function's work it will not return any value
        break;
    }
    }


    getch();//pauses the Output Console untill a key is pressed
}
void ADMIN_panel()
{
    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    if(!Verify_info_of_admin())//the return value of Verify_info_Of_admin() will be 0 or 1.if 0 that means password or user id is wrong
    {
        printf("\n!!!SORRY!!! YOUR INFORMATION IS NOT CORRECT!!!\n\n");

        printf("\nYou can--\n1.Go to main menu or\n0.exit\n");
        int num3;
        printf("Enter your choice:");
        scanf("%d",&num3);
        switch(num3)//noted before
        {
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            main();

        }
        }

    }
    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    printf("\n***   Welcome to ADMIN panel   ***\n\n");
    while(1)//This loop will be run for infinity
    {
        printf("Your services are to...\n\n1.Add Teacher\n2.Add Student\n3.Update Teacher's info\n4.Update Student's info\n5.Go to the main menu\n0.Exit\n\n");
        printf("Make your choice among (1/2/3/4/0):");
        int num2;
        scanf("%d",&num2);
        switch(num2)//noted before..
        {
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            ADD_teacher_and_provide_course();//calling this function to add teacher

            return;    //returns control to the calling function
        }
        case 2:
        {
            ADD_student();//calling this function to to add student


            return;
        }
        case 3:
        {
            UPDATE_teachers_info();// to update info of teacher
            return;
        }
        case 4:
        {
            UPDATE_students_info();// to update info of student
            return;
        }
        case 5:
        {
            main();
            return;
        }
        }

    }
}


int Verify_info_of_admin()    //will return an integer value (f) to teacher's panel which will make sure wheather it was the admin or not
{
    admin A1;
    printf("\nEnter your User ID :");
    fflush(stdin);               //It is used to clean/flush the output buffer of the stream so that any click to "enter" or other problem it will clear the output buffer to get input string properly
    gets(A1.User_ID);
    printf("\nEnter your password (less than 25 characters):");
    fflush(stdin);
    gets(A1.Password);


    FILE *file;
    admin A2;

    file=fopen("Admin.txt","rb");           //Open the file to compare the input with the information which is stored in the file in read in binary mode
    if(file==NULL)                  //no data has entered before
    {
        fclose(file);
        file=fopen("Admin.txt","wb");          //will open the file to write the information of the admin for the very 1st time
        fwrite(&A1,sizeof(admin),1,file);    //syntax of fwrite() function  fwrite(pointer which point to the memory block containg the data which will be written,size of that memory block,how manay times to be written,file pointer)
        fclose(file);
        file=fopen("Admin.txt","rb");
    }
    int f=0;
    while(fread(&A2,sizeof(admin),1,file))//when the file can be read that means true.
    {
        if(!strcmp(A2.User_ID,A1.User_ID) && !strcmp(A2.Password,A1.Password))//if string1=string2 strcmp() returns 0 so !0 && !0=1/true
        {
            f=1;
        }
    }
    fclose(file);


    return f;
}
void ADD_teacher_and_provide_course()//after getting information by admin ,will store data in teacher's file
{
    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    FILE *file2;
    teacher t;
    printf("\nEnter User ID  :");
    fflush(stdin);
    gets(t.User_ID);
    printf("\nEnter password :");
    fflush(stdin);
    gets(t.Password);
    printf("\nEnter his/her course no.1 :");//providing courses1
    fflush(stdin);
    gets(t.course1);
    printf("\nEnter his/her course no.2 :");//providing courses2
    fflush(stdin);
    gets(t.course2);
    file2=fopen("Teacher.txt","ab");
    fwrite(&t,sizeof(teacher),1,file2);
    fclose(file2);
    printf("\n\n\n  *** Record has been added successfully ***\n");
    printf("\n====>Do you want to see the record?\n");
    int n;
    printf("1.YES\n2.NO.\n");
    printf("\nEnter your choice :");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
    {
        display();
    }
    case 2:
    {
        exit(0);
    }

    }

}

void display()//to see what has stored in the file
{
    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    teacher t2;
    printf("\n***Teachers list and information***\n");
    printf("\n%-20s %-20s %-20s %-20s","User_ID","Password","Course_1","Course_2");
    FILE *file2=fopen("Teacher.txt","rb");//opening "Teacher.txt" file to read in binary mode
    while(fread(&t2,sizeof(teacher),1,file2))// if file can be read
    {
        printf("\n%-20s %-20s %-20s %-20s",t2.User_ID,t2.Password,t2.course1,t2.course2);
    }
    fclose(file2);
    show_option1();
}
void show_option1()//this will show the menu where the user can go from the calling function
{
    printf("\n\n\nYou can--\n1.Go back to main menu\n2.Add more teachers\n3.Go back to Admin panel\n0.exit\n");
    int num3;
    printf("Enter your choice:");
    scanf("%d",&num3);
    switch(num3)
    {
    case 0:
    {
        exit(0);
    }
    case 1:
    {
        main();

    }
    case 2:
    {
        ADD_teacher_and_provide_course();//to add more teachers

    }
    case 3:
    {
        ADMIN_panel();//to do other activities of admin
    }
    }
}
void ADD_student()//after getting information by admin ,will store data in student's file
{
    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    FILE *file3;
    student s;
    printf("\nEnter User ID  :");
    fflush(stdin);
    gets(s.User_ID);
    printf("\nEnter password :");
    fflush(stdin);
    gets(s.Password);
    printf("\nEnter roll     :");
    fflush(stdin);
    gets(s.roll);
    file3=fopen("Student.txt","ab");//"ab" means append .Opening "Student.txt" file to append in binary mode
    fwrite(&s,sizeof(student),1,file3);//syntax of fwrite() function  fwrite(pointer which point to the memory block containg the data which will be written,size of that memory block,how manay times to be written,file pointer)
    fclose(file3);
    printf("\n\n\n  *** Record has been added successfully ***\n");
    printf("\n====>Do you want to see the record?\n");
    int n;
    printf("1.YES\n2.NO.\n");
    printf("\nEnter your choice :");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
    {
        display2();
    }
    case 2:
    {
        exit(0);
    }

    }

}
void display2()//to see what has stored in the student's file
{
    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    student s2;
    printf("\n***Students list and information***\n");
    printf("\n%-30s %-30s %-30s","User_ID","Password","Roll");
    FILE *file3=fopen("Student.txt","rb");// opening file to read in binary mode
    while(fread(&s2,sizeof(student),1,file3))//syntax of fread() ---noted before
    {
        printf("\n%-30s %-30s %-30s",s2.User_ID,s2.Password,s2.roll);
    }
    fclose(file3);
    show_option();

}
void show_option()//this will show the menu where the user can go from the calling function
{
    printf("\n\n\nYou can--\n1.Go back to main menu\n2.Add more students\n3.Go back to the Admin panel\n0.exit\n");
    int num3;
    printf("Enter your choice:");
    scanf("%d",&num3);
    switch(num3)
    {
    case 0:
    {
        exit(0);
    }
    case 1:
    {
        main();

    }
    case 2:
    {
        ADD_student();//to add more students

    }
    case 3:
    {
        ADMIN_panel();//to do other activities of admin
    }
    }
}
void UPDATE_teachers_info()//after getting string as input it will open file & then will update information, will write new information in the file
{
    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    char name[100];
    teacher t;
    printf("\nEnter the User ID to update information :");
    fflush(stdin);
    gets(name);
    int f=0;

    FILE *file2=fopen("Teacher.txt","rb+");//"rb+" =read + write in binary mode

    while(fread(&t,sizeof(teacher),1,file2))//t=pointer which indicate memory block in which expected data is located,teacher=size of total no of bite,file2=in which file data is written
    {
        if(!strcmp(name,t.User_ID) )//if name=t.User_ID strcmp() will return 0
        {
            f=1;
            printf("\nEnter new name     :");
            fflush(stdin);
            gets(t.User_ID);
            printf("\nEnter new password :");
            fflush(stdin);
            gets(t.Password);
            printf("\nEnter new course_1 :");
            fflush(stdin);
            gets(t.course1);
            printf("\nEnter new course_2 :");
            fflush(stdin);
            gets(t.course2);
            fseek(file2,-sizeof(teacher),1);//fseek() is used to move file pointer associated with a given file to a specific position. here the pointer will point the point whwere strcmp(name,t.User_ID)==0
            fwrite(&t,sizeof(teacher),1,file2);//syntax of fwrite() ...noted before
            fclose(file2);
            printf("\n\n\n  *** Record has been Updated successfully ***\n");
            printf("\n====>Do you want to see the record?\n");
            int n;
            printf("1.YES\n2.NO.\n");
            printf("\nEnter your choice :");
            scanf("%d",&n);
            switch(n)//noted before...
            {
            case 1:
            {
                display5();
                break;
            }
            case 2:
            {
                exit(0);
            }

            }

            printf("\n\n\nYou can--\n1.Go to main menu\n2.Update more information\n0.exit\n");
            int num5;
            printf("Enter your choice:");
            scanf("%d",&num5);
            switch(num5)
            {
            case 0:
            {
                exit(0);
            }
            case 1:
            {
                main();

            }
            case 2:
            {
                UPDATE_teachers_info();
                return;
            }
            }
            return;
        }
    }
    if(f==0)
    {
        printf("\n\n!!! Record not found !!!\n\n");
        printf("\n\n\nYou can--\n1.Go to main menu\n2.Try again to update another one\n0.exit\n");
        int num3;
        printf("Enter your choice:");
        scanf("%d",&num3);
        switch(num3)
        {
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            main();

        }
        case 2:
        {
            UPDATE_teachers_info();//to update another one's info
        }
        }

    }


}
void display5()// this function will show the updated record
{
    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    teacher t2;
    printf("\n***Teachers list and information***\n");
    printf("\n%-20s %-20s %-20s %-20s","User_ID","Password","Course_1","Course_2");
    FILE *file2=fopen("Teacher.txt","rb");//opening "Teacher.txt" file to read in binary mode
    while(fread(&t2,sizeof(teacher),1,file2))// if file can be read
    {
        printf("\n%-20s %-20s %-20s %-20s",t2.User_ID,t2.Password,t2.course1,t2.course2);
    }
    fclose(file2);
}

void UPDATE_students_info()//after getting string as input it will open file & then will update information, will write new information in the file
{
    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    char name[100];
    student s;
    printf("\nEnter the User ID to update information :");
    fflush(stdin);
    gets(name);
    int f=0;

    FILE *file3=fopen("Student.txt","rb+");//"rb+"=read+write in binary mode

    while(fread(&s,sizeof(student),1,file3))//if file can be read
    {
        if(!strcmp(name,s.User_ID) )//If name==s,User_ID then strcmp() will return 0
        {
            f=1;
            printf("\nEnter new name     :");
            fflush(stdin);
            gets(s.User_ID);
            printf("\nEnter new password :");
            fflush(stdin);
            gets(s.Password);
            printf("\nEnter new roll     :");
            fflush(stdin);
            gets(s.roll);
            fseek(file3,-sizeof(student),1);//fseek() is used to move file pointer associated with a given file to a specific position. here the pointer will point the point whwere strcmp(name,t.User_ID)==0
            fwrite(&s,sizeof(student),1,file3);
            fclose(file3);
            printf("\n\n\n  *** Record has been Updated successfully ***\n");
            printf("\n====>Do you want to see the record?\n");
            int n;
            printf("1.YES\n2.NO.\n");
            printf("\nEnter your choice :");
            scanf("%d",&n);
            switch(n)
            {
            case 1:
            {
                display4();
                break;
            }
            case 2:
            {
                exit(0);
            }

            }




            printf("\n\n\nYou can--\n1.Go to main menu\n2.Update more information\n0.exit\n");
            int num5;
            printf("Enter your choice:");
            scanf("%d",&num5);
            switch(num5)
            {
            case 0:
            {
                exit(0);
            }
            case 1:
            {
                main();

            }
            case 2:
            {
                UPDATE_students_info();
                return;
            }
            }
            return;
        }
    }
    if(f==0)
    {
        printf("\n\n\t\t!!! Record is not found !!!\n\n");
        printf("\n\n\nYou can--\n1.Go to main menu\n2.Try again to update another one\n0.exit\n");
        int num3;
        printf("\nEnter your choice:");
        scanf("%d",&num3);
        switch(num3)
        {
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            main();

        }
        case 2:
        {
            UPDATE_students_info();//to Update another one's information
        }
        }

    }
}
void display4()//to show updated record of student
{
    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    student s2;
    printf("\n***Students list and information***\n");
    printf("\n%-30s %-30s %-30s","User_ID","Password","Roll");
    FILE *file3=fopen("Student.txt","rb");// opening file to read in binary mode
    while(fread(&s2,sizeof(student),1,file3))//syntax of fread() ---noted before
    {
        printf("\n%-30s %-30s %-30s",s2.User_ID,s2.Password,s2.roll);
    }
    fclose(file3);
}


void TEACHER_panel()//after getting input 2 by the user this function will be called
{
    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    if(!Verify_info_of_teacher())//the return value of Verify_info_Of_teacher() will be 0 or 1 .if 0 that means he/she doesn't have access!!
    {
        printf("\n!!!SORRY!!! YOUR INFORMATION IS NOT CORRECT!!!\n\n");

        printf("\nYou can--\n1.Go to main menu or\n0.exit\n");
        int num3;
        printf("Enter your choice:");
        scanf("%d",&num3);
        switch(num3)
        {
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            main();

        }
        }

    }
    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    printf("\n     *** Welcome to TEACHER's panel ***\n\n");
    while(1)
    {
        printf("Your services are to...\n\n\n1.Provide class test mark.\n2.Find Student\n3.Count student\n4.Go to the main menu\n0.Exit\n\n");
        printf("Make your choice among (1/2/3/4/0):");
        int num2;
        scanf("%d",&num2);
        switch(num2)
        {
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            provide_class_test_marks();//provide class test marks to the students

            return;
        }
        case 2:
        {
            find_student();// will search a student by his/her name


            return;
        }
        case 3:
        {
            count_student();//count total number of students recorded

            return;
        }
        case 4:
        {
            main();
            return;
        }
        }

    }

}
int Verify_info_of_teacher()//this function will return f(0/1) if 1 , information is correct else information is not correct
{
    teacher t1;
    printf("\nEnter your User ID :");
    fflush(stdin);//It is used to clean/flush the output buffer of the stream
    gets(t1.User_ID);
    printf("\nEnter your password (less than 25 characters):");
    fflush(stdin);
    gets(t1.Password);
    FILE *file2;
    teacher t2;
    file2=fopen("Teacher.txt","rb");//opening teacher's file in read in binary mode
    if(file2==NULL)//NULL is defined as 0
    {
        printf("\n\n!!! Sorry !!! No record has been added yet!!!\n");
        fclose(file2);
        printf("\n\n\nYou can--\n1.Go to main menu or\n0.exit\n");
        int num3;
        printf("Enter your choice:");
        scanf("%d",&num3);
        switch(num3)
        {
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            main();

        }
        }

    }
    int f=0;

    while(fread(&t2,sizeof(teacher),1,file2))//when the file can be read that means true.
    {
        if(!strcmp(t2.User_ID,t1.User_ID) && !strcmp(t2.Password,t1.Password))//if string1=string2 strcmp() returns 0 so !0 && !0=1/true
        {
            f=1;
        }
    }
    fclose(file2);


    return f;//return to teacher's panel
}
void provide_class_test_marks()//will check the input is same as recorded file or not and then will provide ct marks
{
    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    while(1)
    {
        student s;
        char name[100];
        char roll[100];
        int f=0;
        printf("\nEnter the name of the student :");
        fflush(stdin);
        gets(name);
        printf("\nEnter the roll of the student :");
        fflush(stdin);
        gets(roll);

        FILE *file3=fopen("Student.txt","rb");
        while(fread(&s,sizeof(student),1,file3))
        {
            if(!strcmp(name,s.User_ID) && !strcmp(roll,s.roll))
            {
                f=1;
                fclose(file3);
                std st;
                strcpy(st.User_ID,name);
                strcpy(st.roll,roll);
                printf("\nEnter the name of your provided course 1:");
                fflush(stdin);
                gets(st.course1);
                printf("\nEnter the marks of course 1:");
                fflush(stdin);
                gets(st.marks1);
                printf("\nEnter the name of your provided course 2:");
                fflush(stdin);
                gets(st.course2);
                printf("\nEnter the marks of course 2:");
                fflush(stdin);
                gets(st.marks2);
                FILE *file4=fopen("Marks.txt","ab");
                fwrite(&st,sizeof(std),1,file4);
                fclose(file4);
                printf("\n\n   *** Marks has been added successfully *** \n\n");

                printf("\nDo you want to see the record?\n");
                printf("1.YES\n2.NO\n");
                printf("\nEnter your choice :");
                int n;
                scanf("%d",&n);
                switch(n)//noted before
                {
                case 1:
                {
                    display3();
                }
                case 2:
                {
                    exit(0);
                }

                }


                return;




            }
        }
        if(f==0)//input doesn't match with the recorded info
        {
            printf("\n\n\n !!! This name is not listed !!!");
            printf("\n\n\nYou can--\n1.Go back to main menu\n2.Go back to Teacher's panel\n3.Provide class test marks to rest of the students....0.exit\n");
            int num3;
            printf("Enter your choice:");
            scanf("%d",&num3);
            switch(num3)
            {
            case 0:
            {
                exit(0);
            }
            case 1:
            {
                main();

            }
            case 2:
            {
                TEACHER_panel();//to do other activities of teacher's panel
                return;
            }
            case 3:
            {
                provide_class_test_marks();//to another one
                return;

            }
            }

        }


    }
}
void display3()// to show the marks of the students
{
    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    std st;
    printf("\n***Class test marks of students***\n");
    printf("\n%-10s %-10s %-10s %-10s %-10s %-10s","User_ID","Roll","Course1","Marks","Course2","Marks");
    FILE *file4=fopen("Marks.txt","rb");
    while(fread(&st,sizeof(std),1,file4))
    {
        printf("\n%-10s %-10s %-10s %-10s %-10s %-10s",st.User_ID,st.roll,st.course1,st.marks1,st.course2,st.marks2);
    }
    fclose(file4);
    printf("\n\n\nYou can--\n1.Go back to main menu\n2.Go back to Teacher's panel\n3.Provide class test marks to rest of the students....\n0.exit\n");
    int num3;
    printf("Enter your choice:");
    scanf("%d",&num3);
    switch(num3)
    {
    case 0:
    {
        exit(0);
    }
    case 1:
    {
        main();

    }
    case 2:
    {
        TEACHER_panel();//to do other activities of teacher
    }
    case 3:
    {
        provide_class_test_marks();//to another student
        break;

    }
    }

}

void find_student()//to find a student by his name getting input ... comparing with recorded file then showing other information of that student
{
    system("Cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screenclearing the screen as noted before
    student s;
    char name[100];
    int f=0;
    printf("\nEnter Student's Name: ");
    fflush(stdin);
    gets(name);
    FILE *file3=fopen("Student.txt","rb");//opening in read in binary mode

    while(fread(&s,sizeof(student),1,file3))
    {
        if(!strcmp(s.User_ID,name))//if both are same
        {
            f=1;
            printf("\n%-20s %-20s","User_ID","Roll");
            printf("\n%-20s %-20s\n",s.User_ID,s.roll);
            see_class_test_marks(name);//calling this fuction that shows the list of course and number of that course of a student

        }
    }
    fclose(file3);
    if(f==0)//if input doesn't match the recorded file
    {
        printf("\n\n\n !!! This name is not listed !!!");
    }
    printf("\n\n\nYou can--\n1.Go back to main menu\n2.Go back to Teacher's panel\n3.Search another student\n0.exit\n");
    int num3;
    printf("Enter your choice:");
    scanf("%d",&num3);
    switch(num3)
    {
    case 0:
    {
        exit(0);
    }
    case 1:
    {
        main();

    }
    case 2:
    {
        TEACHER_panel();//to do other activities
    }
    case 3:
    {
        find_student();//find another student

    }
    }



}


void count_student()//for counting student ,opening student's file and for every time it can be read increamented the countS variable
{
    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    FILE *file3=fopen("Student.txt","rb");//opening Studen.txt file for read in binary mode
    student s;
    while(fread(&s,sizeof(student),1,file3))
    {
        countS++;//increment of global variable
    }

    printf("\n***Total number of sutdents is : %d\n\n",countS);
    fclose(file3);
    printf("\n\n\nYou can--\n1.Go back to main menu\n2.Go back to Teacher's panel\n0.exit\n");
    int num3;
    printf("Enter your choice:");
    scanf("%d",&num3);
    switch(num3)
    {
    case 0:
    {
        exit(0);
    }
    case 1:
    {
        main();

    }
    case 2:
    {
        TEACHER_panel();//to do other activities of teacher's panel
    }

    }
}

void STUDENT_panel()//if input of the user and recorded imformation are same then user can login and see his ct marks
{
    system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen
    student s1;
    printf("\nEnter your User ID :");
    fflush(stdin);//It is used to clean/flush the output buffer of the stream
    gets(s1.User_ID);
    printf("\nEnter your password (less than 25 characters):");
    fflush(stdin);
    gets(s1.Password);
    FILE *file3;
    student s2;
    file3=fopen("Student.txt","rb");//opening student's file to read in binary mode
    if(file3==NULL)//no record has been added yet
    {
        printf("\n\n!!! Sorry !!! No record has been added yet!!!\n");
        fclose(file3);
        printf("\n\n\nYou can--\n1.Go to main menu or\n0.exit\n");
        int num3;
        printf("Enter your choice:");
        scanf("%d",&num3);
        switch(num3)
        {
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            main();

        }
        }

    }
    int f=0;

    while(fread(&s2,sizeof(student),1,file3))//when the file can be read that means true.
    {
        if(!strcmp(s2.User_ID,s1.User_ID) && !strcmp(s2.Password,s1.Password))//if string1=string2 strcmp() returns 0 so !0 && !0=1/true
        {
            f=1;
        }
    }

    if(f == 0)//the return value of Verify_info_Of_teacher() will be 0 or 1 .if 0 that means he/she doesn't have access!!
    {
        printf("\n!!!SORRY!!! YOUR INFORMATION IS NOT CORRECT!!!\n\n");

        printf("\nYou can--\n1.Go to main menu or\n0.exit\n");
        int num3;
        printf("Enter your choice:");
        scanf("%d",&num3);
        switch(num3)
        {
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            main();

        }
        }

    }
    else
    {
        printf("\n***Welcome to Student's panel***\n\n");
        student s;
        FILE *file3=fopen("Student.txt","rb");
        while(1)
        {
            printf("You can...\n\n\n1.See class test marks\n2.Go back to main menu\n0.Exit\n\n");
            printf("Make your choice among (1/2/3/4/0):");
            int num2;
            scanf("%d",&num2);
            switch(num2)
            {
            case 0:
            {
                exit(0);
            }
            case 1:
            {
                system("cls");//system() is library function of stdlib.h header file and "cls" is to clear the output screen

                see_class_test_marks(s1.User_ID);//here calling see_class_test_marks() function with the value of s1.User_ID
            }
            case 2:
            {
                main();
            }

            }
        }
    }
    fclose(file3);
}


void see_class_test_marks(char *p)//here p=&s1.User_ID.... this function will show some information of s1.User_ID like course name and their marks
{
    FILE *file4=fopen("Marks.txt","rb");//fopening this file as marks are recorded here
    std st;
    char name[100];
    strcpy(name,p);// copying the value of p in name so that we can compare input with the information of marks.txt file
    int f = 0;
    printf("\n\n   *** The class test marks of %s are ----\n\n",name);
    printf("%-10s %-10s %-10s %-10s\n","Course1","Marks","Course2","Marks");
    while(fread(&st,sizeof(std),1,file4))

    {
        if(!strcmp(name,st.User_ID))
        {
            f=1;
            printf("%-10s %-10s %-10s %-10s\n",st.course1,st.marks1,st.course2,st.marks2);


        }
    }
    if(f==0)
    {
        printf("\n\n   *** Marks has not added yet *** \n");
    }
    fclose(file4);
    printf("\n\n\nYou can--\n1.Go back to main menu\n0.exit\n");
    int num3;
    printf("Enter your choice:");
    scanf("%d",&num3);
    switch(num3)
    {
    case 0:
    {
        exit(0);
    }
    case 1:
    {
        main();

    }
    }
}

