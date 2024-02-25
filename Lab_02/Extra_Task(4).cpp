#include <iostream>
using namespace std;

class Plant
{
    public:
        virtual void grow() = 0; // Pure virtual function
        virtual void display_height() const = 0;
};

class Flower : public Plant
{
    private:
        double height, growth_rate; // in centimeters and growth_rate is cm per day
    public:
        Flower(double initial_height) : height(initial_height), growth_rate(0.5) {}
        void grow() override
        {
            height += growth_rate;
        }
        void display_height() const override
        {
            cout << "Flower height: " << height << " cm" << endl;
        }
};

class Tree : public Plant
{
    private:
        double height, growth_rate;
    public:
        Tree(double initial_height) : height(initial_height), growth_rate(0.2) {}
        void grow() override
        {
            height += growth_rate;
        }
        void display_height() const override
        {
            cout << "Tree height: " << height << " cm" << endl;
        }
};

class Bush : public Plant
{
    private:
        double height, growth_rate;
    public:
        Bush(double initial_height) : height(initial_height), growth_rate(0.7) {}
        void grow() override
        {
            height += growth_rate;
        }
        void display_height() const override
        {
            cout << "Bush height: " << height << " cm" << endl;
        }
};

int main()
{
    Flower flower(10);
    Tree tree(20);
    Bush bush(15);

    for (int i = 0; i < 30; ++i)
    {
        flower.grow();
        tree.grow();
        bush.grow();
    }

    flower.display_height();
    tree.display_height();
    bush.display_height();

    return 0;
}
