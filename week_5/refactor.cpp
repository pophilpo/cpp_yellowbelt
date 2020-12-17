#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    Person(const string& name, const string& occupation)
        : Name(name), Occupation(occupation)
    {

    }

    string get_name() const
    {
        return Name;
    }

    string get_occupation() const
    {
        return Occupation;
    }

    virtual void Walk(const string& destination) const = 0;
private:
    string Name;
    string Occupation;
};
class Student : public Person
{
public:
    Student(const string& name, const string& favouriteSong)
        : Person(name, "Student"), FavouriteSong(favouriteSong)
    {

    }

    void Learn() const
    {
        cout << "Student: " << get_name() << " learns" << endl;
    }

    void Walk(const string& destination) const override
    {
        cout << "Student: " << get_name() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const
    {
        cout << "Student: " << get_name() << " sings a song: " << FavouriteSong << endl;
    }
public:
    string FavouriteSong;
};
class Teacher : public Person
{
public:
    Teacher(string name, string subject)
        : Person(name, "Teacher"), Subject(subject)
    {

    }

    void Teach() const
    {
        cout << "Teacher: " << get_name() << " teaches: " << Subject << endl;
    }

    void Walk(const string& destination) const override
    {
        cout << "Teacher: " << get_name() << " walks to: " << destination << endl;
    }
public:
    string Subject;
};
class Policeman : public Person
{
public:
    Policeman(const string& name)
        : Person(name, "Policeman")
    {

    }

    void Check(const Person& p) const
    {
        cout << "Policeman: " << get_name() << " checks " << p.get_occupation() << ". "
            << p.get_occupation() << "'s name is: " << p.get_name() << endl;
    }

    void Walk(const string& destination) const override
    {
        cout << "Policeman: " << get_name() << " walks to: " << destination << endl;
    }
};

void VisitPlaces(const Person& pers, const vector<string>& places)
{
    for (const auto& p : places)
    {
        pers.Walk(p);
    }
}
int main()
{
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, { "Moscow", "London" });
    p.Check(s);
    VisitPlaces(s, { "Moscow", "London" });
    return 0;
}

