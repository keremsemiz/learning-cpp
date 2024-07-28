#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Ingredient {
private:
    std::string name;
    double quantity; // in grams, liters, etc.

public:
    Ingredient(const std::string& n, double q) : name(n), quantity(q) {}

    std::string getName() const { return name; }
    double getQuantity() const { return quantity; }

    void display() const {
        std::cout << "Ingredient: " << name << ", Quantity: " << quantity << std::endl;
    }
};

class Recipe {
private:
    std::string name;
    std::string description;
    std::vector<Ingredient> ingredients;

public:
    Recipe(const std::string& n, const std::string& d) : name(n), description(d) {}

    void addIngredient(const Ingredient& ingredient) {
        ingredients.push_back(ingredient);
    }

    std::string getName() const { return name; }
    std::string getDescription() const { return description; }

    void display() const {
        std::cout << "Recipe: " << name << "\nDescription: " << description << "\nIngredients:\n";
        for (const auto& ingredient : ingredients) {
            ingredient.display();
        }
    }

    bool containsIngredient(const std::string& ingredientName) const {
        return std::any_of(ingredients.begin(), ingredients.end(), [&](const Ingredient& ingredient) {
            return ingredient.getName() == ingredientName;
        });
    }
};

class RecipeBook {
private:
    std::vector<Recipe> recipes;

public:
    void addRecipe(const Recipe& recipe) {
        recipes.push_back(recipe);
    }

    void removeRecipe(const std::string& recipeName) {
        recipes.erase(std::remove_if(recipes.begin(), recipes.end(), [&](const Recipe& recipe) {
            return recipe.getName() == recipeName;
        }), recipes.end());
    }

    void displayRecipes() const {
        for (const auto& recipe : recipes) {
            recipe.display();
        }
    }

    void searchRecipesByName(const std::string& recipeName) const {
        auto it = std::find_if(recipes.begin(), recipes.end(), [&](const Recipe& recipe) {
            return recipe.getName() == recipeName;
        });

        if (it != recipes.end()) {
            it->display();
        } else {
            std::cout << "Recipe not found." << std::endl;
        }
    }

    void searchRecipesByIngredient(const std::string& ingredientName) const {
        bool found = false;
        for (const auto& recipe : recipes) {
            if (recipe.containsIngredient(ingredientName)) {
                recipe.display();
                found = true;
            }
        }

        if (!found) {
            std::cout << "No recipes contain the ingredient: " << ingredientName << std::endl;
        }
    }
};

int main() {
    RecipeBook book;

    Recipe pasta("Pasta", "A simple pasta recipe.");
    pasta.addIngredient(Ingredient("Pasta", 200));
    pasta.addIngredient(Ingredient("Tomato Sauce", 150));
    pasta.addIngredient(Ingredient("Cheese", 50));
    book.addRecipe(pasta);

    Recipe salad("Salad", "A fresh vegetable salad.");
    salad.addIngredient(Ingredient("Lettuce", 100));
    salad.addIngredient(Ingredient("Tomato", 50));
    salad.addIngredient(Ingredient("Cucumber", 30));
    book.addRecipe(salad);

    std::cout << "All Recipes:\n";
    book.displayRecipes();

    std::cout << "\nSearching for 'Pasta' recipe:\n";
    book.searchRecipesByName("Pasta");

    std::cout << "\nSearching for recipes with 'Cheese':\n";
    book.searchRecipesByIngredient("Cheese");

    std::cout << "\nRemoving 'Salad' recipe...\n";
    book.removeRecipe("Salad");

    std::cout << "\nAll Recipes:\n";
    book.displayRecipes();

    return 0;
}
