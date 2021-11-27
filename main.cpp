//Full Name: Students field assistant bot
//Author:
//Email address: eyobzebene3580@gmail.com
//Description: The program gives information for the user about the departments & predict the department based on three semester GPAs of the user
#include <iostream>
#include <string>
#include <cstdlib>


using namespace std;
void welcome_choice();
void sign_up();
void sign_in();
void student_assist();
void department_info();
double cumulative (double&, double&, double&);
void department_selector();





int findPriority(int value){
    return 7 - value;  // changes the users choice index to priority to compare it with the priority table
}

int choose(int priority,int* gegema, int index = 0){
    if( priority >= findPriority(gegema[index])){
        return gegema[index];
    }else{
        choose(priority, gegema, index+1);
    }  // the variable priority is assigned by the user to represent the rule to get the departments.`
}
int main ()
{
    welcome_choice();

    return 0;

}
void welcome_choice()
{
    int user_choice;
    cout << "\nHello, I am baymax. Your personal assistant. Are you a new user? \n"
    << "Then welcome... so, if you are a new user sign up if you are not sign in \n"
    << "press '1' to sign in\n"
    << "press '2' to sign up\n"
    << "press '3' to exit the program\n";
    while (user_choice != 3)
    {
        cout << "Enter your choice: ";
        cin >> user_choice;
        cout << "\n";
        switch (user_choice)
        {
        case 1:
            sign_in();
            break;
        case 2:
            sign_up();
            break;
        case 3:
            exit(1);
            break;
        default:
            cout << "Wrong number! Please, insert correctly." << endl;
            welcome_choice();
            break;
        }
    }
    cout << "\n\n";
}
void sign_up()
{
    string name, user_name, email_address;
    int age;
    char sex;

    cout << "\nTo sign up to the application you need to fulfill the following informations. \n"
    << "Press Enter after you enter the informations in each steps. \n";
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter User name for your account: ";
    cin.ignore();
    getline(cin, user_name);
    cout << "Enter your age: ";
    cin.ignore();
    cin >> age;
    cout << "Enter 'M' for male or 'F' for female: ";
    cin >> sex;
    cout << "Enter your email address: ";
    cin.ignore();
    getline(cin, email_address);
    cout << "you successfully signed up to the application now. You can sign in..." << endl;
    cout << "\n\n";

    sign_in();
}
void sign_in()
{
   string user_name, id_num;
   cout << "User name: ";
   cin.ignore();
   getline(cin, user_name);
   cout << "ID Number: ";
   cin.ignore();
   getline(cin, id_num);
   cout << "\n\n";
   student_assist();
   cout << "\n\n";
}
void student_assist()
{
    int user_choice_1;
    cout << "\nWell come :) \n"
    << "what can I help you? please choose \n"
    << "1. To get information about the departments given in AAiT & their criteria. \n"
    << "2. To choice department & predict your department based on your GPA.  \n"
    << "3. To log out from your account (: \n";
    while (user_choice_1 != 3)
        {
            cout << "\n\n";
            cout << "Your choice: ";
            cin >> user_choice_1;
            switch (user_choice_1)
            {
                case 1:
                    department_info();
                    student_assist();
                    break;
                case 2:
                    department_selector();
                    student_assist();
                    break;
                case 3:
                    welcome_choice();
                    break;
                default:
                    cout << "Wrong number!"  << endl;
                    student_assist();
                    break;
            }
        }
    cout << "\n\n";
}
void department_info()
{
    cout << "\n\n";
    cout << "There are 6 departments in AAiT you can join if you are a fresh man student. \n"
    << "The departments and the cumulative GPA point required is given below: \n"
    << "1. SoftWare Engineering  accepts a total of 80 students each year with a CGPA above 3.7 \n"
    << "2. Electrical Engineering accepts a total of 100 students each year with a CGPA above 3.2 \n"
    << "3. Biomedical Engineering accepts a total of 100 students each year with a CGPA above 2.8 \n"
    << "4. Chemical Engineering accepts a total of 100 students each year with a CGPA above 2.4 \n"
    << "5. Civil Engineering accepts a total of 100 students each year with a CGPA above 2.0 \n"
    << "6. Mechanical Engineering  accepts a total of 100 students each year with a CGPA above 1.6 \n";
    cout << "\n\n";
}
void department_selector()  // the second_choice of the user which selects the department of the user depending on his interest
{
    const string departments[] = {
    "Soft Ware Engineering",
    "Electrical Engineering",
    "Biomedical Engineering",
    "Chemical Engineering",
    "Civil Engineering",
    "Mechanical Engineering"}; // this is the array which is presented for the user to choose from

    int choice_order [6]; // this array accepts the user's input, so it is a collection of integers
    int priority_table[] = {6,5,4,3,2,1}; // this is a priority of the departments from 6 - software to 1 - mechanical
                                          // which is used to compare it with the users input choice order
    for (int i = 0; i < 6; i++)
    {
        cout << "\n";
        cout << departments[i] << endl;
    }
    cout << "\n";
    cout << "Enter your interest of department in descending order from the the above 6 department choices \n"
    << "and then press enter after each choice to insert your choice." << endl;

    for (int i = 0; i < 6; i++) // the loop collects the users department choice order
    {
        cin >> choice_order[i];
    }
    double semester_1, semester_2, semester_3, cumulative_GPA;
    cout << "Enter your three semester GPA below \n";
    cout << "Your First Semester GPA: ";
    cin >> semester_1;
    cout << "Your Second Semester GPA: ";
    cin >> semester_2;
    cout << "Your Third Semester GPA: ";
    cin >> semester_3;
    cumulative_GPA = cumulative(semester_1, semester_2, semester_3);

    if (cumulative_GPA >= 3.7)
        {
            int index = choose(priority_table[0], choice_order, 0) - 1;
            cout << "Congratulation, With a Cumulative GPA of " << cumulative_GPA
            << " You Joined department of " << departments[index] << endl;
        }
    else if ((cumulative_GPA < 3.7) && (cumulative_GPA >= 3.2))
    {
        int index = choose(priority_table[1], choice_order, 0) - 1;
        cout << "Congratulation, With a Cumulative GPA of "<< cumulative_GPA
         << " You Joined department of " << departments[index] << endl;
    }
    else if ((cumulative_GPA < 3.2) && (cumulative_GPA >= 2.8))
    {
        int index = choose(priority_table[2], choice_order, 0) - 1;
        cout << "Congratulation, With a Cumulative GPA of "<< cumulative_GPA
        << " You Joined department of " << departments[index] << endl;
    }
    else if((cumulative_GPA < 2.8) && (cumulative_GPA >= 2.4))
    {
       int index = choose(priority_table[3], choice_order, 0) - 1;
        cout << "Congratulation, With a Cumulative GPA of "<< cumulative_GPA
        << " You Joined department of " <<departments[index] << endl;
    }
    else if ((cumulative_GPA < 2.4) && (cumulative_GPA >= 2.0))
    {
        int index = choose(priority_table[4], choice_order, 0) - 1;
        cout << "Congratulation, With a Cumulative GPA of "<< cumulative_GPA
        << " You Joined department of " << departments[index] << endl;
    }
    else if ((cumulative_GPA < 2.0) && (cumulative_GPA >= 1.6))
    {
        int index = choose(priority_table[5], choice_order, 0) - 1;
        cout << "Congratulation, With a Cumulative GPA of "<< cumulative_GPA
        << " You Joined department of " << departments[index] << endl;
    }
    else if (cumulative_GPA < 1.6)
    {
        cout << "You are Academical dismissal. Come back next year (:" << endl;
    }
}
double cumulative(double& GPA_1,double& GPA_2,double& GPA_3)  // cumulative GPA is calculated by this function
{
    double total, cgpa;
    total = GPA_1 + GPA_2 + GPA_3;
    cgpa = total / 3;
    cout.setf (ios :: fixed);
    cout.setf (ios :: showpoint);
    cout.precision(1);
    return cgpa;
}


