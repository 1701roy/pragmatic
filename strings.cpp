/*
 * =====================================================================================
 *
 *       Filename:  strings.cpp
 *
 *    Description:  Practice different algortithms in strings 
 *
 *        Version:  1.0
 *        Created:  02/17/2021 10:33:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  PARAG PRATYUSH ROY (), 1701roy@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<iostream>
#include<string>

//Time Complexity: O(n), where n si the length of the string
//Assuming all lower case
void duplicates(std::string x)
{
    int map[26]={0};
    for(int i=0;x[i]!='\0';i++)
    {
        map[x[i]-97] += 1;
    }
    for(int i=0;i<26;i++)
    {
        if(map[i]>1)
        {
            std::cout<<(char)(i+97)<<std::endl;
        }
    }
    return;
}

//Time Complexity: O(n), where n is the length of the string
//Space Complexity: O(1), no additional space
void duplicatesBitWise(std::string x)
{
    int h=0;
    int k=0;
    for(int i=0;x[i]!='\0';i++)
    {
        k=1;
        k=k<<(x[i]-97);
        if((k&h)>0)
        {
            std::cout<<k<<std::endl;
        }
        else
        {
            h=(k|h);
        }
    }
}

int main()
{
    std::string a = "parag";
    duplicatesBitWise(a);
    return 0;
}
