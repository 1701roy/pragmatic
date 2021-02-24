/*
 * =====================================================================================
 *
 *       Filename:  perms.cpp
 *
 *    Description:  Finding the different permutations of a string
 *
 *        Version:  1.0
 *        Created:  02/22/2021 10:25:50 PM
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

//Time complexity: O(n*n*n! + n!*n), here the first half from saying that at most n*n! recursive calls are possible and at every call we go through the entire string of length n. Second half for printing, priniting takes place only for the n! permutations and it would take n time to print the string
void permBackTrack(std::string a, int level)
{
    static int flag[10] = {0};
    static char res[10];
    if(a[level] == '\0')
    {
        res[level] = '\0';
        for(int i=0;res[i]!='\0';i++)
        {
            std::cout<<res[i];
        }
        std::cout<<std::endl;
    }
    else
    {
        for(int i=0;a[i]!='\0';i++)
        {
            if(flag[i]==0)
            {
                res[level] = a[i];
                flag[i] = 1;
                permBackTrack(a,level+1);
                flag[i] = 0;
            }
        }
    }
}

//Time Complexity:O(n*n!) as there would be atmost n! calls and atmost we will iterate over the string of length n
void permSwap(std::string a, int l, int h)
{
    if(l==h)
    {
        std::cout<<a<<std::endl;
    }
    else
    {
        for(int i=l;i<=h;i++)
        {
            std::swap(a[l],a[i]);
            permSwap(a,l+1,h);
            std::swap(a[l],a[i]);
        }
    }
}

int main()
{
    std::string x = "abc";
    permSwap(x,0,x.length()-1);
    return 0;
}

