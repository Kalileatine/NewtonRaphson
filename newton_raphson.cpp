#include <iostream>
#include <string>
#include <vector>

int main()
{
 float Xn{}, Fxn{}, Fxn_prime{}, degree{};
 std::string equation = "";

 // step 1: ask user for the equation.
 std::cout << "Please enter the degree of the polynomial: ";
 std::cin >> degree;

 std::vector<int> coefficients(degree + 1); // storage for coefficients

 for (int i = degree; i >= 0; --i)
 {

		std::cout << "Please enter the coefficient for x^" << i << ":"; // i here is the power!
		std::cin >> coefficients[degree - i];																											// assign from reverse  (highest degree) ==> (lowest degree)
 }

 for (int i = degree; i >= 0; --i)
 {
		int coefficient = coefficients[degree - i];
		if (coefficient == 0)
			continue; // skip 0, ex : 0x^2 = 0, not written.

		if (!equation.empty() && coefficient > 0)
		{ // add + sign to positive terms except for the first term
			equation += " + ";
		}
		else if (coefficient < 0)
		{
			equation += '-';
			coefficient = -coefficient; // make it so that the number is + after adding - ex:Please enter the coefficient for x^3: -3 ==> - 3x^3
		}

		if (i == 0)
		{
			equation += std::to_string(coefficient); // remove x when power is 0 ex: 3x^0 ==> 3
		}
		else if (i == 1)
		{
			equation += (coefficient == 1 ? "" : std::to_string(coefficient)) + "x"; // linear term, power = 1 ex: 4x^1 ==> 4x
		}
		else
		{
			equation += (coefficient == 1 ? "" : std::to_string(coefficient)) + "x^" + std::to_string(i);
		}
 }

 std::cout << equation << "= 0" << "\n";
}
g