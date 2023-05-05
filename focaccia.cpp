/**
 * focaccia.cpp
 *
 * Katherine Gurgenian
 * gurgenia
 *
 * EECS 183: Project 1
 * Winter 2023
 *
 * Project 1 calculates the total amount of ingredients (flour, yeast, salt, and oil) necessary to cook a certain
 * amount of focaccia bread for a given amount of people
 * 
 * Project UID: d435ced1b1ee1e06372665b53322301c67d2d4a0
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;


/**
 * Returns the singular or plural form of a word, based on number
 *
 * Requires: singular is the singular form of the word.
 *           plural is the plural form of the word.
 *           number determines how many things there are; must be >= 0.
 * Modifies: Nothing.
 * Effects:  Returns return the singular form of the word if number == 1.
 *           Otherwise, returns the plural form.
 * Examples:
 *           // prints "bag"
 *           cout << pluralize("bag", "bags", 1);
 *
 *           // prints "pounds"
 *           string temp = pluralize("pound", "pounds", 3);
 *           cout << temp;
 */
string pluralize(string singular, string plural, int number);

//Define necessary constants for requirements of each loaf of focaccia
const double CUPS_FLOUR_PER_FB = 5;
const double TSP_YEAST_PER_FB = 1.75;
const double TSP_SALT_PER_FB = 1.875;
const double TBSP_OIL_PER_FB = 2;

//Define necessary constants for all conversions
const double CUPS_FLOUR_PER_BAG = 20;
const double TSP_YEAST_PER_BAG = 2.25;
const double G_SALT_PER_CAN = 30;
const double G_SALT_PER_TSP = 5;
const double ML_OIL_PER_BOTTLE = 500;
const double ML_OIL_PER_TBSP = 14.8;

//Define necessary constants for cost of 1 amount of an ingredient
const double COST_FLOUR_BAG = 2.69;
const double COST_YEAST_PACKAGE = 0.40;
const double COST_SALT_CANISTER = 0.49;
const double COST_OIL_BOTTLE = 6.39;


//Calculate bags of flour needed for x amount of loaves
double BagsFlour(double totalFocacciaLoaves) {
    
    double totalCupsNeeded = totalFocacciaLoaves * CUPS_FLOUR_PER_FB;
    double totalFlourBags = totalCupsNeeded / CUPS_FLOUR_PER_BAG;
    
    return ceil(totalFlourBags);
}

//Calculate packages of yeast needed for x amount of loaves
double PackagesYeast(double totalFocacciaLoaves) {
    
    double totalTspYeastNeeded = totalFocacciaLoaves * TSP_YEAST_PER_FB;
    double totalYeastPackages = totalTspYeastNeeded / TSP_YEAST_PER_BAG;
    
    return ceil(totalYeastPackages);
}

//Calculate canisters of salt needed for x amount of loaves
double CanistersSalt (double totalFocacciaLoaves) {
    
    double totalTspSaltNeeded = totalFocacciaLoaves * TSP_SALT_PER_FB;
    double totalGramSaltNeeded = totalTspSaltNeeded * G_SALT_PER_TSP;
    double totalSaltCanisters = totalGramSaltNeeded / G_SALT_PER_CAN;
    
    return ceil(totalSaltCanisters);
}

//Calculate bottles of olive oil needed for x amount of loaves
double BottlesOliveOil (double totalFocacciaLoaves) {
    
    double totalTbspOilNeeded = totalFocacciaLoaves * TBSP_OIL_PER_FB;
    double totalMlOilNeeded = totalTbspOilNeeded * ML_OIL_PER_TBSP;
    double totalOilBottles = totalMlOilNeeded / ML_OIL_PER_BOTTLE;
    
    return ceil(totalOilBottles);
}

//Calculate total expected price for y amount of each ingredient for x amount
//of loaves
double TotalCost(double totalFlourBags, double totalYeastPackages,
                 double totalSaltCanisters, int totalOilBottles) {

    double totalExpectedCost = (totalFlourBags * COST_FLOUR_BAG)
    + (totalYeastPackages * COST_YEAST_PACKAGE)
    + (totalSaltCanisters * COST_SALT_CANISTER)
    + (totalOilBottles * COST_OIL_BOTTLE);
    
    return totalExpectedCost;
}

//Main function of code
int main() {
    int people;
    cout << "How many people do you need to serve? ";
    cin >> people;
    cout << endl << endl;
  
    //Calculation for total number of loaves needed for party
    double totalFocacciaLoaves = ceil(static_cast<double>(people) / 4);
    
    //List of all plurals
    string loaf = pluralize("loaf", "loaves", totalFocacciaLoaves);
    string flour = pluralize("bag", "bags", BagsFlour(totalFocacciaLoaves));
    string yeast = pluralize("package", "packages",
                             PackagesYeast(totalFocacciaLoaves));
    string canister = pluralize("canister", "canisters",
                                CanistersSalt(totalFocacciaLoaves));
    string bottle = pluralize("bottle", "bottles",
                              BottlesOliveOil(totalFocacciaLoaves));
    
    //Output of amount of loaves needed and of "shopping list"
    cout << "You need to make: " << static_cast<int>(totalFocacciaLoaves)
    << " " << loaf << " of focaccia" << endl;
    cout << endl;
    cout << "Shopping List for Focaccia Bread" << endl
    << "--------------------------------" << endl;
    
    //Output of each ingredient and of necessary amounts to cook x loaves
    cout << BagsFlour(totalFocacciaLoaves) << " " << flour << " of flour"
    << endl;
    cout << PackagesYeast(totalFocacciaLoaves) << " " << yeast << " of yeast"
    << endl;
    cout << CanistersSalt(totalFocacciaLoaves) << " " << canister << " of salt"
    << endl;
    cout << BottlesOliveOil(totalFocacciaLoaves) << " " << bottle
    << " of olive oil" << endl;
    cout << endl;
    
    //Total expect cost declerations, assignments, and output
    double totalFlourBags;
    double totalYeastPackages;
    double totalSaltCanisters;
    double totalOilBottles;
    
    totalFlourBags = BagsFlour(totalFocacciaLoaves);
    totalYeastPackages = PackagesYeast(totalFocacciaLoaves);
    totalSaltCanisters = CanistersSalt(totalFocacciaLoaves);
    totalOilBottles = BottlesOliveOil(totalFocacciaLoaves);
    
    cout << "Total expected cost of ingredients: $"
    << TotalCost(totalFlourBags, totalYeastPackages,
                 totalSaltCanisters, totalOilBottles) << endl << endl;
    
    //Goodbye message!
    cout << "Have a great party!";
    
    return 0;
}

// ----------------------------------------------
// *** DO NOT CHANGE ANYTHING BELOW THIS LINE ***

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}
