#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <cmath>

using namespace std;

class Figure{
	public:
		virtual string Name() const = 0;
		virtual double Perimeter() const = 0;
		virtual double Area() const = 0;
};

class Triangle : public Figure {

	private:
		int a_;
		int b_;
		int c_;

	public:

		Triangle(const int&a, const int& b, const int& c) : a_(a), b_(b), c_(c) {}

		string Name() const override {
			return "TRIANGLE";
		};

		double Area() const override {

			double p2 = (a_ + b_ + c_);

			return sqrt(p2 * (p2 - a_) * (p2 - b_) * (p2 - c_));

		}

		double Perimeter() const override {
			return a_ + b_ + c_;
		}

};


class Rect : public Figure {
	private:
		int a_;
		int b_;
	
	public:
		Rect(const int& a, const int& b) : a_(a), b_(b) {}

		string Name() const override {
			return "RECT";
		};

		double Perimeter() const override {
			return (a_ + b_) * 2;

		};

		double Area() const override {
			return a_ * b_;
		};
};

class Circle : public Figure
{
private:
    double rad = 0;
public:
    Circle(const double& r) : rad(r)
    {

    }

    string Name() const override
    {
        return "CIRCLE";
    }

    double Perimeter() const override
    {
        return (2 * 3.14) * rad;
    }

    double Area() const override
    {
        return 3.14 * rad * rad;
    }
};
shared_ptr<Figure> CreateFigure(istringstream& is)
{
    string type;
    is >> type;

    if (type == "TRIANGLE")
    {
        double a = 0.0;
        is >> a;

        double b = 0.0;
        is >> b;       

        double c = 0.0;
        is >> c;

        return make_shared<Triangle>(a, b, c);
    }
    else
    if (type == "RECT")
    {
        double width = 0.0;
        is >> width;

        double height = 0.0;
        is >> height;

        return make_shared<Rect>(width, height);
    }
	else
	{
		double r = 0.0;
		is >> r;

		return make_shared<Circle>(r);
	}
}





int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
