//
//  main.cpp
//  CS-210 | FA25 Final Exam II | Guo An Wang
//  IDE:Xcode
//  Created by Guo An Wang on 12/10/25.
//

#include <iostream>
using namespace std;
const int SIZE = 100, DRINKS = 25, RUNS = 10;

struct customer {
    string name,drink;
    customer *next = nullptr;
};

//function randName gets a random name from string array
//arguments: string array
//return: string
string randName(string name[]);

//function randDrink gets a random drink from string array
//arguments: string array
//return: string
string randDrink(string drink[]);

int main(int argc, const char * argv[]) {
    //used LLM to create data set
    string names[SIZE] = {
        "Oliver", "Charlotte", "Liam", "Ava", "Noah", "Sophia", "Elijah", "Amelia",
        "Mateo", "Isabella", "Lucas", "Mia", "Levi", "Evelyn", "James", "Harper",
        "Benjamin", "Luna", "Henry", "Camila", "William", "Gianna", "Theodore", "Elizabeth",
        "Jack", "Eleanor", "Daniel", "Ella", "Michael", "Abigail", "Mason", "Sofia",
        "Sebastian", "Avery", "Ethan", "Scarlett", "Alexander", "Emily", "Owen", "Aria",
        "Asher", "Penelope", "Samuel", "Chloe", "Leo", "Layla", "Jackson", "Mila",
        "Hudson", "Violet", "Jacob", "Nora", "Grayson", "Hazel", "Aiden", "Zoey",
        "Joseph", "Riley", "Wyatt", "Victoria", "David", "Lily", "John", "Aurora",
        "Matthew", "Nova", "Luke", "Hannah", "Julian", "Emilia", "Isaac", "Zoe",
        "Gabriel", "Stella", "Anthony", "Everly", "Dylan", "Leah", "Carter", "Lillian",
        "Ezekiel", "Addison", "Elijah", "Willow", "Christopher", "Lucy", "Miles", "Paisley",
        "Jayden", "Natalie", "Nathan", "Delilah", "Caleb", "Naomi", "Ryan", "Brooklyn"
    };
    string drinks[DRINKS] = {
        "Espresso",
        "Double Espresso",
        "Americano",
        "Latte",
        "Cappuccino",
        "Mocha",
        "Flat White",
        "Macchiato",
        "Cortado",
        "Iced Coffee",
        "Cold Brew",
        "Nitro Cold Brew",
        "Iced Latte",
        "Iced Mocha",
        "Iced Americano",
        "Chai Latte",
        "Matcha Latte",
        "Hot Chocolate",
        "London Fog",
        "Green Tea",
        "Black Tea",
        "Herbal Tea",
        "Caramel Latte",
        "Vanilla Latte",
        "Pumpkin Spice Latte"
    };
    customer *head = nullptr;
    customer *tail = nullptr;
    
    return 0;
}
