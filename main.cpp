/**********************************************************
	Cumulative GPA Program
	Version: 1.0.0
	Author: Anro Myburgh 

	Project Desc:
	This calculator is intended to be used by a student to 
    calculate their Cummlative Grade Point Average. The 
    users input is used to compute the CGPA, which inlcudes 
    information like credits, score earned in each course, 
    names of each course, and the total number of courses 
    taken. Based on the inputs, the user can then print out 
    their entered courses, total credits earned over a 
    semester or year, and of course, their CGPA.

	Limitations: 
    The program will not save what the user entered into 
    the program. A total number of 50 courses can be entered 
    at one time. This is based on about 5 to 6 course per 
    semseter for a 4 year program, so it should cover a 
    students entire time at university/college.  

**********************************************************/

/*********************** HEADERS *************************/
#include <iostream>
#include <vector>
#include <string>

/********************* NAMESPACE ************************/
using namespace std;

/********************* CLASSES ************************/
/*** Subject is a class that models a university / college course in terms of
 * 	 associated credits (credit hours) and earned exam grades. ***/
class Subject
{
    private:
        int credits;
        string name;
        int score;
    public:
    /* Set / get */
        int getCredits(void){ return credits; }
        string getName(void){ return name; }
        int getScore(void){ return score; }
        void setValues(string name, int credits, int score)
        {
            this->name = name; 
            this->credits = credits;
            this->score = score;
        }
};
/*** Function get to input from user *****************/
int getUserCommand(void)
{
    int command;

    cout << endl;
    cout << "1. Calculate CGPA" << endl; 
    cout << "2. Print Entered Subjects and Info" << endl; 
    cout << "3. Print Total Credits Earned" << endl; 
    cout << "4. Exit" << endl; 
    cout << endl;
    cout << "Enter number for command" << endl; 
    cin >> command; 

    return command;
}
/*********************** MAIN *************************/
int main(int argc, char *argv[])
{
    int numOfCourses;
    string nameOfCourse;
    int numOfCredits;
    int score;
    int command = 0; 
    int cGPA; 
    int totalCreditsEarned; 

    Subject *ptrCourses;
    Subject *Courses[50];
    
    cout << "Welcome to the CGPA calculator" << endl; 
    cout << "How many courses would you like to add?";
    cin >> numOfCourses;

    for (int i = 0; i < numOfCourses; i++)
    {
        cout << "Enter course number: " << i+1 << endl; 
        cout << "Enter course name:";
        getline(cin >> ws, nameOfCourse);
        cout << "Enter credits:";
        cin >> numOfCredits;
        cout << "Enter score earned:"; 
        cin >> score;

        ptrCourses = new Subject; 
        ptrCourses->setValues(nameOfCourse, numOfCredits, score);
        Courses[i] = ptrCourses;
    }

   while(1)
   {
        command = getUserCommand();
        
        if(command == 1)
        {
            cGPA = 0; 

            for(int i = 0; i < numOfCourses; i++)   
            {
                cGPA += Courses[i]->getScore();
            }
            cGPA /= numOfCourses; 

            cout << "CPGA:" << cGPA << endl;
        }

        else if(command == 2)
        {
            for(int i = 0; i < numOfCourses; i++)  
            {
                cout << "Course Number " << i+1 << endl; 
                cout << "Name:" << Courses[i]->getName() << endl; 
                cout << "Credits:" << Courses[i]->getCredits() << endl;
                cout << "Score:" << Courses[i]->getScore() << endl; 
                cout << endl; 
            } 
        }

        else if(command == 3)
        {
            totalCreditsEarned = 0; 

            for(int i = 0; i < numOfCourses; i++)  
            {
                totalCreditsEarned += Courses[i]->getCredits(); 
            }
            
            cout << "Total Cerdits Earned:" << totalCreditsEarned << endl; 
        }

        else if(command == 4)
        {
            cout << "Exiting program...";

            for(int i = 0; i < numOfCourses; i++)
            {
                delete Courses[i];
            }
            return 0; 
        }
        else
        {
            cout << "Invalid key pressed, Try again.";
        }
    }
}