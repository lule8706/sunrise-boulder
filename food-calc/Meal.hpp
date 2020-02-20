#ifndef MEAL_HPP
#define MEAL_HPP

#include <string>
#include <vector>

enum class MealType {Breakfast, Lunch, Dinner, Snack};

struct FoodItem {
  std::string name;
  int cals_per_serv; // later versions of program could take more nutrition facts into account
  double prop; // proportion of meal
};

// Helper functions:
namespace {
  /**
    Converts meal type into string.

    @param meal_type Meal type to be converted to stream.
    @return Meal type converted to string.
  */
  std::string MealStringify (const MealType &meal_type) {
    switch (meal_type) {
      case MealType::Breakfast: {
        return "Breakfast";
      } break;
      case MealType::Lunch: {
        return "Lunch";
      } break;
      case MealType::Dinner: {
        return "Dinner";
      } break;
      default: { // includes Snack meal type
        return "Snack";
      }
    }
  }

  /**
    Outputs meal type to output stream.

    @param os Output stream.
    @param meal_type Meal type to be output as string.
    @return Output stream.
  */
  std::ostream& operator<< (std::ostream& os, const MealType &meal_type) {
    os << MealStringify(meal_type);

    return os;
  }
}

class Meal {
private:
  MealType meal_type_;
  unsigned calories_needed_;
  std::vector<FoodItem> food_;

public:
  // Constructors:

  /**
    Instantiates foodless Meal of type meal_type with calories_needed expected calories.

    @param meal_type Type of meal (breakfast, lunch, dinner, snack).
    @param calories_needed Amount of calories meal should have.
    @return Foodless Meal of type meal_type with calories_needed expected calories.
  */
  Meal (const MealType &meal_type, const unsigned &calories_needed);

  /**
    Instantiates foodless Meal of type meal_type with default number of calories for given meal type.

    @param meal_type Type of meal (breakfast, lunch, dinner, snack).
    @return Foodless Meal of type meal_type with default number of calories for given meal type.
  */
  Meal (const MealType &meal_type);

  /**
    Default constructor, instantiates a zero calorie foodless snack.

    @return Zero calorie foodless snack.
  */
  Meal ();

  // Destructor:

  /**
    Class destructor, clears all dynamically allocated memory of instance of class.
  */
  //virtual ~Meal ();

  // Getters:

  /**
    Returns type of Meal object.

    @return Type of Meal object.
  */
  MealType get_meal_type () { return meal_type_; } const

  /**
    Returns expected calories for meal.

    @return Expected calories for meal.
  */
  unsigned get_calories_needed () { return calories_needed_; } const

  /**
    Returns vector of food items in meal.

    @return Vector of food items in meal.
  */
  std::vector<FoodItem> get_food () { return food_; } const

  // Setters:

  /**
    Sets meal_type_ field to meal_type.

    @param meal_type Meal type to set meal_type_ field to.
  */
  void set_meal_type (const MealType &meal_type) { meal_type_ = meal_type; }

  /**
    Sets calories_needed_ field to calories_needed.

    @param calories_needed Expected calories to set calories_needed_ field to.
  */
  void set_calories_needed (const unsigned &calories_needed) { calories_needed_ = calories_needed; }

  /**
    Sets food_ field to food.

    @param food Vector of food items to set food_ field to.
  */
  void set_food (const std::vector<FoodItem> &food) { food_ = food; }

  // Methods:

  // Operators:

  /**
    Extracts information about meal from CSV format input stream.

    @param is CSV format input stream.
    @param meal Variable that collects information from input stream.
    @return The input stream.
  */
  friend std::istream& operator>> (std::istream& is, Meal &meal);

  /**
    Inserts information about meal in CSV format into output stream.

    @param os Output stream.
    @param meal Variable containing information to be output.
    @return The output stream.
  */
  friend std::ostream& operator<< (std::ostream& os, const Meal &meal);
};

#endif // MEAL_HPP
