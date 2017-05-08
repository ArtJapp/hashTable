#include <iostream>
#include <cstring>
using namespace std;

bool isItNum(char * stre)                                                        
{                                                                               
    bool ans = false;                                                           
    for (int i = 0; i < strlen(stre); i++)                                      
    { 
        if (stre[i] <= '9' && stre[i] >= '0') 
        { 
            ans = true; 
        } 
        else 
        { 
            return false; 
        } 
    }  
    return ans; 
} 

int changingToInt(char * str)                                                    
{                                                                               //В этой функции проиходят преобразования строки в число
    int answer = 0;                                                             
    for(int i = 0; i < strlen(str); i++) 
    { 
          answer *= 10; 
          answer += str[i] - '0'; 
    }  

    return answer; 
} 
int input()                                                                     //Функция, требующая ввести число, если таковое не введено
{
    char str[100]; 
    bool flag = false; 
    while (!flag) 
        { 
           
            cin  >> str; 
            flag = isItNum(str); 
            if (!flag)
            {
                cout << "Введите корректные данные\n";
            }
        } 
    int ans = changingToInt(str);
    return ans;
}
