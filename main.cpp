
/*
 :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
 
C++ GPA Calculator
 : This is my first side project with C++ as well as my first experience with arrays of pointers. The program prints a prompt requesting a
 : number of classes to be graded by the user. The program then asks the user for a number of grades and credits per class which are
 : stored in corresponding arrays. Once the gives the input for all the classes, the program calculates and prints the user's
 : GPA using the following formula on line 138.   ::   finalGPA = totalCreditsEarned  / totalPossibleCredits;
 
 :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
*/



#include <iostream>
#include <iomanip>
#include <string>



void getClassData(int, char[], float[], std::string[]);
float calculateGPA(int, char[], float[], std::string[]);
void printInstructions();
int getNumClasses();
void printGPA(float);
void getGPA();



int main() {
    
    printInstructions();
    getGPA();

    return 0;
}




void printInstructions()
{
    std::cout << "\n---------------------------------------------\n" << std::endl;
    std::cout<< "COLLEGIATE GPA CALCULATOR\n" << std::endl;
    std::cout<< "---------------------------------------------" << std::endl;
    std::cout << "\nInstructions:\n1. Enter the number of classes to be graded." << std::endl;
    std::cout << "2. Following the prompt, enter the credits per class and the grade received (A,B,C,D,F)." << std::endl;
    std::cout << "3. Your GPA will be printed to the window. You may then exit or add additional courses" << std::endl;
    std::cout << "\nNote : You may exit the program at anytime by typing \"exit\" or -1 into the prompt." << std::endl;
    std::cout << "______________________________________________________________________________________" << std::endl;
}




void getGPA ()
{
    int classAmount = getNumClasses(); // Defines the number of classses to be graded.
    
    char* letterGrade = new char[classAmount];
    float* creditHours = new float[classAmount];
    std::string* courseName = new std::string[classAmount];
    
    getClassData(classAmount, letterGrade, creditHours, courseName);
    printGPA(calculateGPA(classAmount, letterGrade, creditHours, courseName));
}




int getNumClasses()
{
    int amountInput;
    
    std::cout << "\nEnter the number of coures to be graded : ";
    std::cin >> amountInput;
    
    std::cin.ignore(); // Clears Buffer
    
    return amountInput;
}




void getClassData(int classAmount, char letterGrade[], float creditHours[], std::string courseName[])
{
     for (int i = 0; i < classAmount; i++)
    {
        std::cout << "\nEnter Course Name : ";
        std::getline(std::cin,courseName[i]);
        std::cout << "Enter Course Grade : ";
        std::cin >> letterGrade[i];
        std::cout << "Enter Course Credits : ";
        std::cin >> creditHours[i];
        
        std::cin.ignore(); // Clears Buffer
    }
}




float calculateGPA(int classAmount, char letterGrade[], float creditHours[], std::string courseName[])
{
    float totalPossibleCredits = 0.0,
            totalCreditsEarned = 0.0,
            finalGPA = 0.0;
    
    for (int i = 0; i < classAmount; i++)
    {
        totalPossibleCredits += creditHours[i]; // Calculates total possible credits
        
        // Switch statement calculates how many credits are earned depending on the letter grade recieved.
        switch (letterGrade[i])
        {
            case 'A':
                totalCreditsEarned += creditHours[i] * 4.0;
                break;
            case 'B':
                totalCreditsEarned += creditHours[i] * 3.0;
                break;
            case 'C':
                totalCreditsEarned += creditHours[i] * 2.0;
                break;
            case 'D':
                totalCreditsEarned += creditHours[i] * 1.0;
                break;
            case 'F':
                totalCreditsEarned += creditHours[i] * 0.0;
                break;
            default: std::cout << "Error in Switch" << std::endl;
                break;
        }
    }
    
    finalGPA = totalCreditsEarned  / totalPossibleCredits; // GPA Formula
    
    return finalGPA;
}




void printGPA(float GPA)
{
    std::cout << "\n---------------------" << std::endl;
    std::cout << "Final GPA : " << std::setprecision(3)<< GPA << std::endl;
    std::cout << "---------------------\n" << std::endl;
}



