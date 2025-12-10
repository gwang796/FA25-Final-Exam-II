//
//  main.cpp
//  CS-210 | FA25 Final Exam II | Guo An Wang
//  IDE:Xcode
//  Created by Guo An Wang on 12/10/25.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <deque>
using namespace std;
const int SIZE = 100, DRINKS = 25, RUNS = 10, START = 3, MUFF = 10;

struct customer {
    string name,item;
    customer *next;
    
    customer(string n, string d) {
        name = n;
        item = d;
        next = nullptr;
    }
};

//function randName gets a random name from string array
//arguments: string array
//return: string
string randName(string names[]);

//function randDrink gets a random drink from string array
//arguments: string array
//return: string
string randDrink(string drinks[]);

//function getMuffins gets a random muffin from string array
//arguments: string array
//return: string
string randMuffin(string muffins[]);

//function addCustomer adds a element to the end of linked list
//arguments: head pointer, tail pointer, string name, string drink
//return: none
void addCustomer(customer *&head, customer *&tail, string name, string drink);

//function customerPays has customer at the front of the line(head) get their drink and leave
//arguments: head pointer, tail pointer
//return: none
void customerPays(customer *&head,customer *&tail);

//function printQeue prints the line of customer for linked list
//arguments:head pointer
//return: none
void printQueue(customer *head);

//function printDeque prints the line of customers for deque container
//argument: deque container line
//return: none
void printDeque(const deque<customer> &line);

int main(int argc, const char * argv[]) {
    srand(time(0));
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
    
    string muffins[MUFF] = {
        "Blueberry Muffin",
        "Chocolate Chip Muffin",
        "Banana Nut Muffin",
        "Lemon Poppy Seed Muffin",
        "Pumpkin Muffin",
        "Bran Muffin",
        "Apple Cinnamon Muffin",
        "Double Chocolate Muffin",
        "Raspberry Streusel Muffin",
        "Coffee Cake Muffin"
    };
    
    customer *head = nullptr;
    customer *tail = nullptr;
    deque<customer> muffinLine;
    
    for (int i = 0; i < START; i++) {
        string n = randName(names);
        string d = randDrink(drinks);
        addCustomer(head, tail, n, d);
    }

    for (int i = 0; i < START; i++) {
        string n = randName(names);
        string d = randDrink(drinks);
        muffinLine.push_back({n,d});
    }
    
    cout << "Initial Coffee Line: " << endl;
    printQueue(head);
    cout << "\nInitial Muffin Line: " << endl;
    printDeque(muffinLine);
    
    
    for (int i = 0; i < RUNS; i++) {
        cout << "\nRound " << i + 1 << ": " << endl;
        cout << "Coffe Booth: " << endl;
        int chance = rand() % 100 + 1;
        if (chance <= 50) {
            string n = randName(names);
            string d = randDrink(drinks);
            addCustomer(head, tail, n, d);
        }
        cout << "No customer joins Line" << endl;
        customerPays(head, tail);
        printQueue(head);
        cout << endl;
        
        cout << "Muffin Booth Line: " << endl;
        chance = rand() % 100 + 1;
        if (chance <= 50) {
            string n = randName(names);
            string d = randMuffin(muffins);
            muffinLine.push_back({n,d});
        } else {
            cout << "No customer joins Line" << endl;
        }
        
        if (!muffinLine.empty()) {
            cout << muffinLine.front().name << " gets their muffin and leaves the line" << endl;
            muffinLine.pop_front();
        } else {
            cout << "Line is empty" << endl;
        }
        printDeque(muffinLine);
    }
    return 0;
}

string randName(string names[]){
    int choice = rand() % SIZE;
    return names[choice];
}

string randDrink(string drinks[]){
    int choice = rand() % DRINKS;
    return drinks[choice];
}

string randMuffin(string muffins[]){
    int choice = rand() % MUFF;
    return muffins[choice];
}

void addCustomer(customer *&head, customer *&tail,string name, string drink){
    customer *current = new customer(name,drink);
    if (!head) {
        head = tail = current;
    } else {
        tail->next = current;
        tail = current;
    }
}

void customerPays(customer *&head,customer *&tail){
    if (!head) {
        cout << "Line is empty" << endl;
        return;
    }
    customer *temp = head;
    head = head->next;
    cout << temp->name << " gets their drink " << temp->item << ", and leaves the line" << endl;
    if (!head) {
        tail = nullptr;
    }
    delete temp;
}


void printQueue(customer *head){
    customer *temp = head;
    while (temp) {
        cout << temp->name << " ordered " << temp->item << endl;
        temp = temp->next;
    }
}

void printDeque(const deque<customer> &line){
    for (const customer &c : line) {
        cout << c.name << " ordered " << c.item << endl;
    }
}
