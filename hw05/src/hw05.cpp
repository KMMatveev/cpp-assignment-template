#include <hw05.h>
#include <string>
#include <vector>
#include <cctype> 
#include <iostream>

VecOfStr hw05(const VecOfStr& strings)
{
    auto result = VecOfStr{};
    auto process_str = [](std::string* str){
        std::string res;
        for (char c : *str)
        {
            if (isalpha(c))  // Если символ является буквой
            {
                res.push_back(tolower(c));  // Добавляем эту букву в нижнем регистре в результат
            }
        }
        return res;
    };
    auto is_palindrom =[&](std::string phrase){
        std::string clean_str=process_str(&phrase);
        size_t str_len=clean_str.length();
        bool is_palindrom=true;
        //std::cout << phrase<<"\n"<<clean_str<<"\n";
        for(int j=0;j<str_len;j++)
        {
            if(clean_str[j]!=clean_str[str_len-j-1])
            {
                is_palindrom=false;
                return is_palindrom;
            }
        }
        return is_palindrom;
    };
    auto res_func = [&](){
        size_t input_len = strings.size();
        for(int i = 0; i<input_len; i++)
        {
            std::string phrase= strings[i];
            if(is_palindrom(phrase)){
                result.push_back(phrase);
            }
        }
    };
    res_func();
    return result;
}
