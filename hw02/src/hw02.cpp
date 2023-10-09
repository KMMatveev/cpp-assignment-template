#include <hw02.h>

std::string hw02(std::string input_str)
{
    bool flag=true;
    for(int i=1;i<input_str.length();)
    {
        for(int j=0;j<i;j++)
        {
            if(input_str[i]==input_str[j])
            {
                input_str.erase(i,1);
                flag=false;
                break;
            }
        }
        if (flag)
        {
            i++;
        }
        else 
        {
            flag=true;
        }
    }
    return input_str;
}
