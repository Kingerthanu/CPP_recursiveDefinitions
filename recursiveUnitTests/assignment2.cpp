// Benjamin R Spitzauer
// assignment2.cpp
// 1/26/2023

/*
 Purpose: Assesses knowledge of recursive data structures by
 displaying different ways it can arise and be used. This assignment
 calls for 5 functions, each with their own goal; one being calculations
 of a unknown algorithm's sequencing to a n'th position. Secondly,
 having a function which calculates the amount of tennis balls needed to
 make a pyramid of x height. Thirdly is a conversion from base 10 integers
 to base 2. Fourth program checks the divisibility of a integer based
 on a recursive function which refrains from the usage of modulo until 
 certain criterium are satisfied. Finally is the ramunjan calculation,
 which calls for you to represent the algorithm in a recursive function.
 These are finally used with unit test functions which check their outputs
 at varying values.
*/

#include <cmath>
#include <iostream>
#include <random>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~ProtoTypes~~~~~~~~~~~~~~~~~~~~~~~~~~~


/*

 Description: A recursive function which calculates the factorial
 till the toDeg'th index. 

 Pre-Condition: Integer representing number to find factorial of.

 Post-Condition: Returns the factorial integer representation of
 the factorial amount. 

*/
long long int mysterySequence(int toDeg);

/*

 Description: Function which calculates how many tennis balls must be used
 in order to make a pyramid of equal sides at each stage to a certain
 n'th stage.

 Pre-Condition: The height of the pyramid trying to be calculated.

 Post-Condition: Returns a integer representation of the amount of tennis
 balls needed to make a pyramid of stage height with equally sides on 
 each stage. 

*/
long int tennisBalls(int stage);

/*

 Description: Converts a base10 whole number into a base2 (binary value).

 Pre-Condition: Must pass in value wishing to be translated into base2.

 Post-Condition: Returns a std::string representation of the value in
 base2 form. 

*/
std::string decToBase2(int value);

/*

 Description: A function finds if a number is divisible by 7. It does this by
 first checking if its a two-digit integer value and if so it will simply
 use modulo on the integer to see if its divisible or not; but if this 
 number is above two digits it will take the last digit from the number and
 multiply it by 2 and minus it by the remainder given by taking away this
 number from the original value. This process is then done recursively
 until it is two-digits in which then it can use modulus on the integer.

 Pre-Condition: Must take in the value wished to be checked if divisible by 7.

 Post-Condition: Returns boolean representation showing if value is divisible
 by 7 or not (0 or 1). If divisible, return true; if not, return false. 

*/
bool isDivisibleBy7(long int value);

/*

 Description: A function which works with a nested recursive expression
 in order to do the ramanujan sequence calculation. This calculation
 calls for a certain series of calculations to be done at n stages in order
 to calculate the limit this expression converges upon.

 Pre-Condition: The stage of the ramunjan algorithm wished to go till.

 Post-Condition: Returns a calculation for the ramunjan series till the
 given stage. Will print INSIDE the function the calculations made to
 satisfy with pseudocode explanation of the function, which
 evalautes upon printing the value of this expression when carried to 
 an abrituary constant of infinity.

*/
long double ramanujan(int max, int current);

/*

 Description: Works as a interface with the recursive functions being made
 in this assignment. Asks user for number 1-8 in which enacts certain
 recursive functions with the users requested passed data. 

 Pre-Condition: None.

 Post-Condition: Returns true if main loop will keep cycling for user input;
 false otherwise. 

*/
bool request();

/*

 Description: Unit test for each of the recursive functions requested.
 Iterates through each function with a for loop with static arguments
 given in the outline for the assignment. Displays these results to
 the user and requests them to step through each unit test as they present
 themselves to help readability.

 Pre-Condition: None.

 Post-Condition: Prints out the contents of the unit testing at the given
 values using the given recursive function. 

*/
void runTests();

/*

 Description: A random unit test function which calls random values in a
 generators given range to simulate differing values and the recursive
 functions handling of these values. Each function steps through a random
 value three times; and prints its results

 Pre-Condition: None.

 Post-Condition: Prints out the contents of the unit testing at the given
 random intervals using the given recursive function. 

*/
void testSmallCases();

// ~~~~~~~~~~~~~~~~~~~~~~~END ProtoTypes~~~~~~~~~~~~~~~~~~~~~~~~~~~

long long int mysterySequence(int toDeg)
{

    if(toDeg <= 0){
      return 1;
    }

    return toDeg * mysterySequence(toDeg-1);
    
}

long int tennisBalls(int stage)
{

    if(stage <= 0){
      return 0;
    }
    else if (stage == 1){
      return 1;
    }

    return (stage * stage) + tennisBalls(stage - 1);

}

std::string decToBase2(int value)
{

    if(value == 1){
      return "1";
    }
    else if(value == 0){
      return "0";
    }
    
    // Modulo should return remainer (0 or 1)
    return ((decToBase2(value/2)) + std::to_string(value%2));

}

bool isDivisibleBy7(long int value)
{

  if(value == 0 || value < 100){
    return (value % 7 == 0);
  }

  return isDivisibleBy7((value/10) - (2*(value%10)));

}

long double ramanujan(int max, int current = 0)
{
  if(max == 0){

    // Display result before return
    std::cout << "When expanded to stage 0 the approximation is "
    << sqrt(6) << std::endl
    << "When expanded to infinity, Ramanujan's approximation "
    << "approaches the number 4" << std::endl;

    return sqrt(6);

  }
  else if(max == current){

    return sqrt(current+6);

  }

  long double returnValue = sqrt((6+current) + 
  (current+2)*ramanujan(max, current+1));

  // Only do once, at end of function
  if(current == 0){

    // Display result before return
    std::cout << "When expanded to stage " << max << " the approximation is "
    << returnValue << std::endl
    << "When expanded to infinity, Ramanujan's approximation "
    << "approaches the number 4" << std::endl;

  }

  return returnValue;

}

bool request()
{

  int userResponse;

  std::cout << "\nWelcome to the recursion assignment."
  << " What would you like to test?\n"
  << "1.  mysterySequence\n"
  << "2.  tennisBalls\n"
  << "3.  decToBase2\n"
  << "4.  isDivisibleBy7\n"
  << "5.  ramanujan\n"
  << "6.  Run Random Tests\n"
  << "7.  Run Tests\n"
  << "8.  Exit\n"
  << "\nResponse (1-8): ";

  do{
    std::cin >> userResponse;
  } while(1 > userResponse || userResponse > 8);

  std::cout << '\n';

  switch(userResponse){

    case 1:
      std::cout << "What element of the mystery sequence do you want? ";
      std::cin >> userResponse;

      std::cout << "Printing mysterySequence's " << userResponse 
      << "th number which is " << mysterySequence(userResponse) << '\n';

      break;
    case 2:
      std::cout << "What is the height of the tennis ball pyramid? ";
      std::cin >> userResponse;

      std::cout << "Printing Tennis Ball Pyramid with " << userResponse
      << " height which contains " << tennisBalls(userResponse) 
      << " tennis balls.\n";

      break;
    case 3:
      std::cout << "What base10 number do you want to get into base2? ";
      std::cin >> userResponse;

      std::cout << "Printing decToBase2 with value = " << userResponse
      << " which is " << decToBase2(userResponse) << " in base2\n";

      break;
    case 4:
      std::cout << "What number do you want to check the divisibility"
      << " of 7 by? ";
      std::cin >> userResponse;

      std::cout << "isDivisibleBy7 with value " << userResponse << " is "
      << (isDivisibleBy7(userResponse) ? "true\n" : "false\n");

      break;
    case 5:
      std::cout << "What stage of ramunjans sequence do you want to calculate to? ";
      std::cin >> userResponse;

      ramanujan(userResponse);

      break;
    case 6:
      std::cin.ignore(); // Remove \n given during last cin call
      testSmallCases();    

      break;
    case 7:
      std::cin.ignore();
      runTests();   

      break;
    case 8:
      std::cout << "\n\n";
      return false; // Close interface loop

  }

  return true;

}

void testSmallCases()
{
  std::random_device rand;   // Making seeded gen
  std::mt19937 seed(rand()); // Seeding with quicker gen with seed
  std::uniform_int_distribution<int> randDegree(1, 20); // Range of values
  
  int valueToTest = randDegree(seed); // Get value to pass as argument

  std::cout << "\nPress Enter to Start unit testing of each"
  << " recursive function:\n";
  std::cin.get(); // Wait for user to press enter

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cout << "\nPrinting Mystery Sequence using random stages: \n";
  for(int i = 0; i < 3; i++){
    std::cout << "Mystery Sequence at value " << valueToTest << " is "
    << mysterySequence(valueToTest) << std::endl;

    valueToTest = randDegree(seed);
  }
  std::cin.get();

  // Re-initialize Range of values
  randDegree = std::uniform_int_distribution<int>(1, 700); 
  valueToTest = randDegree(seed);

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cout << "\nPrinting Tennis Ball Pyramid using random heights: \n";
  for(int i = 0; i < 3; i++){
    std::cout << "Tennis Ball Pyramid at stage " << valueToTest << " has "
    << tennisBalls(valueToTest) << " tennis balls\n";

    valueToTest = randDegree(seed);
  }
  std::cin.get();

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cout << "\nPrinting decToBase2 using random values: \n";
  for(int i = 0; i < 3; i++){
    std::cout << "decToBase2 with value " << valueToTest << " is "
    << decToBase2(valueToTest) << " in base2\n";

    valueToTest = randDegree(seed);
  }
  std::cin.get();

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cout << "\nPrinting isDivisibleBy7 using random values: \n";
  for(int i = 0; i < 3; i++){
    std::cout << "isDivisibleBy7 with value " << valueToTest << " is "
    << (isDivisibleBy7(valueToTest) ? "true\n" : "false\n");

    valueToTest = randDegree(seed);
  }
  std::cin.get();

  // Re-initialize Range of values
  randDegree = std::uniform_int_distribution<int>(1, 25);
  valueToTest = randDegree(seed);

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cout << "\nPrinting Ramanujan using random stages: \n";
  for(int i = 0; i < 3; i++){

    ramanujan(valueToTest);

    valueToTest = randDegree(seed);

    std::cout << "\n";
  }
  std::cin.get();

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

}

void runTests()
{

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cout << "\nPress Enter to Start unit testing of mysterySequence:\n";
  std::cin.get();


  std::cout << "Printing mysterySequence's 0th number which is "
  << mysterySequence(0) << '\n';

  std::cout << "Printing mysterySequence's 1st number which is "
  << mysterySequence(1) << '\n';

  std::cout << "Printing mysterySequence's 4th number which is "
  << mysterySequence(4) << '\n';

  std::cout << "Printing mysterySequence's 10th number which is "
  << mysterySequence(10) << '\n';
  
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cout << "\nPress Enter to Start unit testing of Tennis Ball Pyramid:\n";
  std::cin.get();


  std::cout << "Printing Tennis Ball Pyramid with height 0 which contains "
  << tennisBalls(0) << " tennis balls.\n";

  std::cout << "Printing Tennis Ball Pyramid with height 1 which contains "
  << tennisBalls(1) << " tennis ball.\n";

  std::cout << "Printing Tennis Ball Pyramid with height 3 which contains "
  << tennisBalls(3) << " tennis balls.\n";

  std::cout << "Printing Tennis Ball Pyramid with height 10 which contains "
  << tennisBalls(10) << " tennis balls.\n";

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cout << "\nPress Enter to Start unit testing of decToBase2:\n";
  std::cin.get();


  std::cout << "Printing decToBase2 with value of 0 which is "
  << decToBase2(0) << " in base2\n";

  std::cout << "Printing decToBase2 with value of 1 which is "
  << decToBase2(1) << " in base2\n";

  std::cout << "Printing decToBase2 with value of 13 which is "
  << decToBase2(13) << " in base2\n";

  std::cout << "Printing decToBase2 with value of 32 which is "
  << decToBase2(32) << " in base2\n";

  std::cout << "Printing decToBase2 with value of 321 which is "
  << decToBase2(321) << " in base2\n";

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cout << "\nPress Enter to Start unit testing of isDivisibleBy7:\n";
  std::cin.get();


  std::cout << "isDivisibleBy7 with value 1 is "
  << (isDivisibleBy7(1) ? "true\n" : "false\n");

  std::cout << "isDivisibleBy7 with value 7 is "
  << (isDivisibleBy7(7) ? "true\n" : "false\n");

  std::cout << "isDivisibleBy7 with value 31 is "
  << (isDivisibleBy7(31) ? "true\n" : "false\n");

  std::cout << "isDivisibleBy7 with value 1073 is "
  << (isDivisibleBy7(1073) ? "true\n" : "false\n");

  std::cout << "isDivisibleBy7 with value 1729 is "
  << (isDivisibleBy7(1729) ? "true\n" : "false\n");

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cout << "\nPress Enter to Start unit testing of ramanujan:\n";
  std::cin.get();

  
  ramanujan(1);
  std::cout << '\n';

  ramanujan(3);
  std::cout << '\n';

  ramanujan(10);
  std::cout << '\n';

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  std::cin.get();

}

int main()
{

  bool loopFlag = true;

  while(loopFlag){

    loopFlag = request();

  }

}