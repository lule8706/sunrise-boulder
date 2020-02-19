#include "Meal.hpp"

Meal::Meal (const MealType &meal_type, const unsigned &calories_needed):
meal_type_ (meal_type),
calories_needed_ (calories_needed) {}

Meal::Meal (const MealType &meal_type):
meal_type_ (meal_type) {
  switch (meal_type) { // assigns default amount of calories for meal based on meal type
    case MealType::Breakfast: {
      calories_needed_ = 600;
    } break;
    case MealType::Lunch: {
      calories_needed_ = 700;
    } break;
    case MealType::Dinner: {
      calories_needed_ = 800;
    } break;
    default: { // includes Snack meal type
      calories_needed_ = 100;
    }
  }
}

Meal::Meal ():
Meal(MealType::Snack, 0) {}
