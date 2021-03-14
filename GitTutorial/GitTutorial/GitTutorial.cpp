#include "stdafx.h"
<<<<<<< HEAD
#include <string>
#include <iostream>
using namespace System;
bool Guess(int number)
{
     static int target = -1;
     if (target == -1)
     {
          Random r;
          target = r.Next() % 100 + 1;
     }
}
=======
#include <string>
#include <iostream>
using namespace System;
bool Guess(int number)
{
     static int target = -1;
     if (target == -1)
     {
          Random r;
          target = r.Next() % 100 + 1;
     }
     if (number > target)
     {
          std::cout << "Smaller" << std::endl;
          return false;
     }
     else if (number < target)
     {
          std::cout << "Bigger" << std::endl;
          return false;
     }
     return true;
>>>>>>> 054ae1201f619ed7d3113c8b22e3b92b4251f5d9
}
int main(array<System::String ^> ^ args)
{
<<<<<<< HEAD
     if (number == target)
     {
          std::cout << "Correct !!";
          target = -1;
          return true;
     }
     else if (number > target)
          std::cout << "Smaller" << std::endl;
     else if (number < target)
          std::cout << "Bigger" << std::endl;
     return false;
=======
     int guess;
     do
     {
          std::cin >> guess;
     } while (!Guess(guess));
     return 0;
>>>>>>> 054ae1201f619ed7d3113c8b22e3b92b4251f5d9
}