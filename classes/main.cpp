#include <iostream>
using namespace std;

class Animal {

protected:
    string name;
    string classes;
    string sound;
    string food;
    string color;
    unsigned short size;

public:
    Animal(string name, string classes, string sound, string food, string color, unsigned short size) {
        this->name = name;
        this->classes = classes;
        this->sound = sound;
        this->food = food;
        this->color = color;
        this->size = size;
    }
    void breathe()                { cout << "inhale" << "  " << " exhale" << endl; }
    void meal()                   { cout << "ate "<<this->food << endl; }
    void meal(string unusualFood) { cout << "ate " << unusualFood << endl; }
    void meal(short time)         { cout << "ate " << this->food <<" " << time << " times" << endl; }
    void makeASound()             { cout << "says: " << this->sound << endl; }
    ~Animal()                     { cout << this->name << " was killed" << endl; }
};

class Elephant : public Animal {
private:
    unsigned short tusksSize;
    const bool wool = false;
public:
    Elephant(string name, string classes, string sound, string food, string color, unsigned short size, unsigned short tusksSize) : Animal(name, classes, sound, food, color, size)
    { this->tusksSize = tusksSize; }
    void breathe()     { cout << this->name << " make it one more time" << endl; }
    void waterInTrunk(){ cout << "filled the trunk with water" << endl; }
    ~Elephant()        { cout << "was killed" << endl; }
};

class Cow : public Animal {
private:
    unsigned short hornsSize;
    unsigned short milkBucketCount;
public:
    Cow(string name, string classes, string sound, string food, string color, unsigned short size, unsigned short hornsSize, unsigned short milkBucketCount) : Animal(name, classes, sound, food, color, size)
    {
        this->hornsSize = hornsSize;
        this->milkBucketCount = milkBucketCount;
    }
    void breathe() { cout << this->name <<"make it two more time" << endl; }
    void milk()    { cout << "give " << this->milkBucketCount << " at noon" << endl; }
    ~Cow()         { cout << "was killed" << endl; }
};

class Cat : public Animal {
private:
    unsigned short  numberOfKittens;
public:
    Cat(string name, string classes, string sound, string food, string color, unsigned short size, unsigned short numberOfKittens) : Animal(name, classes, sound, food, color, size)
    { this->numberOfKittens = numberOfKittens; }
    void kittens() {
        if (this->numberOfKittens > 1) cout << this->name << " have " << this->numberOfKittens << " kittens" << endl;
        else cout << this->name << " have " << this->numberOfKittens << " kitten" << endl;
    }
};

class Chameleon : public Animal {
public:
    Chameleon(string name, string classes, string sound, string food, string color, unsigned short size) : Animal(name, classes, sound, food, color, size) {}
    void changeColor(string newColor) {
        cout << this->name << " changed the color from " << this->color << " to " << newColor << endl;
        this->color = newColor;
    }
};

int main() {
    Cow *cow = new Cow("Burenka", "Mammal", "mooo", "grass", "multi", 4, 6, 2);
    Elephant *eleph = new Elephant("Djambo", "Mammal", "BLOWING", "grass and foliage", "grey", 9, 10);
    /*
    cow->breathe();
    cow->milk();
    cow->meal();
    cow->meal("apple");
    cow->meal(6);
    eleph->makeASound();
    cow->makeASound();
    eleph->breathe();
    eleph->waterInTrunk();
    eleph->meal();
    delete eleph;
    delete cow;
    */

    Cat *cat = new Cat("Mira", "Mammal", "meow", "fish", "white", 2, 3);
    cat->kittens();
    cat->meal();
    cat->meal(2);

    Chameleon *chmln = new Chameleon("Spy", "Reptile", "hisses", "worms", "green", 2);
    chmln->changeColor("yellow");
    chmln->changeColor("red");
    chmln->changeColor("green");

    delete cat;
    delete chmln;
}