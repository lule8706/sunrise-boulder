#include <string>
#include <vector>

enum class MealType {Breakfast, Lunch, Dinner, Snack};

struct FoodItem {
  std::string name;
  std::string cals; // later versions of program could take more nutrition facts into account
};

class Meal {
private:
  MealType meal_type_;
  unsigned calories_needed_;
  std::vector<FoodItem> food_;

public:
  /**
    Instantiates foodless Meal of type meal_type with calories_needed expected calories.

    @param meal_type Type of meal (breakfast, lunch, dinner, snack).
    @param calories_needed Amount of calories meal should have.
    @return Foodless Meal of type meal_type with calories_needed expected calories.
  */
  Meal (MealType meal_type, unsigned calories_needed);

  /**
    Instantiates foodless Meal of type meal_type with default number of calories for given meal type.

    @param meal_type Type of meal (breakfast, lunch, dinner, snack).
    @return Foodless Meal of type meal_type with default number of calories for given meal type.
  */
  Meal (MealType meal_type);

  /**
    Default constructor, instantiates a zero calorie foodless snack.

    @return Zero calorie foodless snack.
  */
  Meal ();

  /**
    Class destructor, clears all dynamically allocated memory of instance of class.
  */
  virtual ~Meal ();
};
