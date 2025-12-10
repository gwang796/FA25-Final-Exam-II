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
#include <vector>
using namespace std;
const int SIZE1 = 100, SIZE2 = 10 ,SIZE3 = 25, RUNS = 10, START = 3;

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

//function randBracelet gets random bracelet from string array
//argument: string array
//return: string
string randBracelet(string bracelets[]);

//function addCustomer adds a element to the end of linked list
//arguments: head of linked list, tail of linked list, string name, string drink
//return: none
void addCustomer(customer *&head, customer *&tail, string name, string drink);

//function customerPays has customer at the front of the line(head) get their drink and leave
//arguments: head of linked list, tail of linked list
//return: none
void customerPays(customer *&head,customer *&tail);

//function printQeue prints the line of customer for linked list
//arguments:head of linked list
//return: none
void printQueue(customer *head);

//function printDeque prints the line of customers for deque container
//argument: deque line
//return: none
void printDeque(const deque<customer> &line);

//function printVector prints the line of customers for vector container
//argument: vector line
//return: none
void printVector(const vector<customer> &line);

int main(int argc, const char * argv[]) {
    srand(time(0));
    //used LLM to create data set
    string names[SIZE1] = {
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
    string drinks[SIZE3] = {
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
    
    string muffins[SIZE2] = {
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
    
    string bracelets[SIZE2] = {
        "Red Bracelet",
        "Blue Bracelet",
        "Green Bracelet",
        "Yellow Bracelet",
        "Black Bracelet",
        "White Bracelet",
        "Purple Bracelet",
        "Pink Bracelet",
        "Orange Bracelet",
        "Silver Bracelet"
    };
    
    customer *head = nullptr;
    customer *tail = nullptr;
    deque<customer> muffinLine;
    vector<customer> braceletLine;
    
    //initialize coffee line
    for (int i = 0; i < START; i++) {
        string n = randName(names);
        string d = randDrink(drinks);
        addCustomer(head, tail, n, d);
    }
    
    //initialize muffin line
    for (int i = 0; i < START; i++) {
        string n = randName(names);
        string d = randMuffin(muffins);
        muffinLine.push_back({n,d});
    }
    
    //initialize bracelet line
    for (int i = 0; i < START; i++) {
        string n = randName(names);
        string d = randBracelet(bracelets);
        braceletLine.push_back({n,d});
    }
    
    cout << "Initial Coffee Line: " << endl;
    printQueue(head);
    cout << "\nInitial Muffin Line: " << endl;
    printDeque(muffinLine);
    cout << "\nInitial Bracelet Line: " << endl;
    printVector(braceletLine);
    
    
    for (int i = 0; i < RUNS; i++) {
        cout << "\nRound " << i + 1 << ": " << endl;
        cout << "Coffe Booth: " << endl;
        int chance = rand() % 100 + 1;
        if (chance <= 50) {
            string n = randName(names);
            string d = randDrink(drinks);
            addCustomer(head, tail, n, d);
            cout << n << " joins the line for " << d << endl;
        } else {
            cout << "No customer joins Line" << endl;
        }

        customerPays(head, tail);
        printQueue(head);
        
        cout << "\nMuffin Booth Line: " << endl;
        chance = rand() % 100 + 1;
        if (chance <= 50) {
            string n = randName(names);
            string d = randMuffin(muffins);
            muffinLine.push_back({n,d});
            cout << n << " joins the line for " << d << endl;
        } else {
            cout << "No customer joins line" << endl;
        }
        
        if (!muffinLine.empty()) {
            cout << muffinLine.front().name << " gets their muffin and leaves the line" << endl;
            muffinLine.pop_front();
        }
        
        printDeque(muffinLine);
        
        cout << "\nBracelet Booth Line: " << endl;
        chance = rand() % 100 + 1;
        if (chance <= 50) {
            string n = randName(names);
            string d = randBracelet(bracelets);
            braceletLine.push_back({n,d});
            cout << n << " joins the line for " << d << endl;
        } else {
            cout << "No customer joins line" << endl;
        }
        
        if (!braceletLine.empty()) {
            cout << braceletLine.front().name << " gets their bracelet and leaves the line" << endl;
            braceletLine.erase(braceletLine.begin());
        }
        
        printVector(braceletLine);
    }
    return 0;
}

string randName(string names[]){
    int choice = rand() % SIZE1;
    return names[choice];
}

string randDrink(string drinks[]){
    int choice = rand() % SIZE3;
    return drinks[choice];
}

string randMuffin(string muffins[]){
    int choice = rand() % SIZE2;
    return muffins[choice];
}

string randBracelet(string bracelets[]){
    int choice = rand() % SIZE2;
    return bracelets[choice];
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
    if (line.empty()) {
        cout << "Line is empty" << endl;
    }
    for (const customer &c : line) {
        cout << c.name << " ordered " << c.item << endl;
    }
}

void printVector(const vector<customer> &line){
    if (line.empty()) {
        cout << "Line is empty" << endl;
    }
    for (const customer &c: line) {
        cout << c.name << " ordered " << c.item << endl;
    }
}
