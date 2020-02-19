/**
  Lukas Leibfried
  Sunrise event food calculator
  Calculates the necessary amount of each food item in order to feed everyone at
  a Sunrise event. Great for trainings.
*/

#include "Meal.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
  Meal test;

  std::cout << test.get_meal_type() << ' ' << test.get_calories_needed() << std::endl;
  return 0;
}
