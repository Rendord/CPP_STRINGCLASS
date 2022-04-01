// StringClassProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "String.h"
#include "Fraction.h"



int main()
{
   std::cout << "Hello World!\n";

   String s1; 
   String s2("My String");
   String s3 = s2;
   String s6 = String(s2);
   String s4(s2);
   String s5;
   s5 = s2;

   Fraction f1(4, 5);

   std::cout << f1 << std::endl;
   

   std::cout << s1.toString() << std::endl;
   std::cout << "len=" << s1.length() << std::endl;
   std::cout << s2.toString() << std::endl;
   std::cout << "len=" << s2.length() << std::endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
