#include <iostream>
#include <string>

using namespace std;
int main()
{
   string raptor_prompt_variable_zzyz;
   ?? userguess;
   ?? count;
   ?? goal;

   goal =floor((random_generator.NextDouble()*50)+1);
   count =0;
   userguess =-1;
   while (!(count==10 || userguess==goal))
   {
      count =count+1;
      raptor_prompt_variable_zzyz ="Enter your guess (between 1 & 50): ";
      cout << raptor_prompt_variable_zzyz << endl;
      cin >> userguess;
      if (userguess>goal)
      {
         cout << "Too high..." << endl;      }
      else
      {
         if (userguess<goal)
         {
            cout << "Too low..." << endl;         }
         else
         {
         }
      }
   }
   if (userguess==goal)
   {
      cout << "Correct, the number was "+goal << endl;   }
   else
   {
      cout << "Sorry, the number was "+goal << endl;   }

   return 0;
}
