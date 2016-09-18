//
//  main.cpp
//  CS106B-SectionHandout1
//
//  Created by John Pierce on 9/13/16.
//  Copyright © 2016 JohnPierce. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using std::string;


/*
 
 Problem 1: Removing all occurrences of characters
 Write a function CensorString that takes two strings as input and returns the first string with all of the characters that are present in the second removed.
 "Stanford University" with “nt” removed becomes "Saford Uiversiy" "Llamas like to laugh" with “la” removed becomes "Lms ike to ugh" and so on . . .
 Note that the function is case sensitive. This function could be written two ways. One way is to return a completely new string, and the other is to modify the original string. For practice write both of these functions. First write a function that returns a completely new string with the following prototype:
 string CensorString1(string text, string remove);
 and then write a function that modifies the original string with the following prototype:
 void CensorString2(string & text, string remove);
 
 */
/* The following are the first attempts at the function.
 
 I tried to convert a string to a character array, change the character array. It didn't quite work, then I realized the string is an object with object functions and it would be much easier to operate on the string object.
 */

/*
 
 for( unsigned int removeTextArrayLoop = 0; removeTextArrayLoop < sizeof(c_removeText); removeTextArrayLoop = removeTextArrayLoop + 1)
 {
 for( unsigned int origTextArrayLoop = 0; origTextArrayLoop < sizeof(c_origText); origTextArrayLoop = origTextArrayLoop +1)
 {
 if (c_origText[origTextArrayLoop] == c_removeText[removeTextArrayLoop])
 {
 //get rid of the character...
 //I can do this by keeping track of the character elements and rebuilding based on the character elements
 removeChar[a] = origTextArrayLoop;
 a = a + 1;
 
 }
 }
 }
 a = 0;
 */
/* I believe I should be able to avoid the while loop
 while ( removeChar[a] )
 {
 origText.erase( removeChar[a]);
 a=a+1;
 
 }
 */

//let's try a vector?

// std::vector<char> origTextVector(origText.begin(), origText.end());






 string CensorString(string origText, string removeText)
{
 //move both strings into an array format
//create a for loop on the removeText string till end
//modify original string
    string tempString = "";
    
//converting the string to a character array
//problem with the character array is that it is not easy to remove elements
    
    //const char *c_origText = origText.c_str();
   // const char *c_removeText = removeText.c_str();
    
    
    
   // int removeChar[0];
    int a = 0;
    
    std::cout << origText.length() << "\n";

    for (auto origTextChar : origText)   // for every character in origText
    {
        for (auto removeTextChar : removeText) // loop through the remove characters
        {
            if ( origTextChar == removeTextChar)
            {
                origText.erase(a, 1);
            }
        }
        a=a+1;
    }
  

    

    
    
    
    return origText;
    
    
}

void CensorString2 ( string & origText, string removeText)
{
    
    
    int a = 0;
    
    std::cout << origText.length() << "\n";
    
    for (auto origTextChar : origText)   // for every character in origText
    {
        for (auto removeTextChar : removeText) // loop through the remove characters
        {
            if ( origTextChar == removeTextChar)
            {
                origText.erase(a, 1);
            }
        }
        a=a+1;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    std::cout << CensorString("For a while we have trumpets", "Reallym?") << "\n";
    
    string originalText = "For a while we have trumpets";
    
    CensorString2( originalText, "Reallym?");
    std::cout << originalText << "\n";
    
    return 0;
}
