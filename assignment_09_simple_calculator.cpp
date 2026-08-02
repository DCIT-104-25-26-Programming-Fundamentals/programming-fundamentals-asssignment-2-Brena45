// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Function for addition
double add(double num1, double num2)
{
    return num1 + num2;
}

// Function for subtraction
double subtract(double num1, double num2)
{
    return num1 - num2;
}

// Function for multiplication
double multiply(double num1, double num2)
{
    return num1 * num2;
}

// Function for division
double divide(double num1, double num2)
{
    return num1 / num2;
}

// Function for modulus
int modulus(int num1, int num2)
{
    return num1 % num2;
}

// Function for exponentiation
double exponentiate(double num1, double num2)
{
    return pow(num1, num2);
}

int main()
{
    int choice;

    // Keep the calculator running
    while (true)
    {
        // Display the menu
        cout << "\n============================" << endl;
        cout << "       SIMPLE CALCULATOR" << endl;
        cout << "============================" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Modulus" << endl;
        cout << "6. Exponentiation" << endl;
        cout << "7. Quit" << endl;

        cout << "Select an operation (1-7): ";
        cin >> choice;

        // Quit the program
        if (choice == 7)
        {
            cout << "Goodbye!" << endl;
            break;
        }

        // Check for an invalid choice
        if (choice < 1 || choice > 7)
        {
            cout << "Invalid choice. Please enter a number from 1 to 7."
                 << endl;

            continue;
        }

        // Modulus operation
        if (choice == 5)
        {
            int num1;
            int num2;

            cout << "Enter first number : ";
            cin >> num1;

            cout << "Enter second number: ";
            cin >> num2;

            // Check if the second number is zero
            if (num2 == 0)
            {
                cout << "Error: Cannot divide by zero."
                     << endl;
            }
            else
            {
                cout << "Result: "
                     << num1
                     << " % "
                     << num2
                     << " = "
                     << modulus(num1, num2)
                     << endl;
            }

            continue;
        }

        // Variables for the other operations
        double num1;
        double num2;
        double result;

        cout << "Enter first number : ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        // Addition
        if (choice == 1)
        {
            result = add(num1, num2);

            cout << fixed << setprecision(2);

            cout << "Result: "
                 << num1
                 << " + "
                 << num2
                 << " = "
                 << result
                 << endl;
        }

        // Subtraction
        else if (choice == 2)
        {
            result = subtract(num1, num2);

            cout << fixed << setprecision(2);

            cout << "Result: "
                 << num1
                 << " - "
                 << num2
                 << " = "
                 << result
                 << endl;
        }

        // Multiplication
        else if (choice == 3)
        {
            result = multiply(num1, num2);

            cout << fixed << setprecision(2);

            cout << "Result: "
                 << num1
                 << " * "
                 << num2
                 << " = "
                 << result
                 << endl;
        }

        // Division
        else if (choice == 4)
        {
            if (num2 == 0)
            {
                cout << "Error: Cannot divide by zero."
                     << endl;
            }
            else
            {
                result = divide(num1, num2);

                cout << fixed << setprecision(2);

                cout << "Result: "
                     << num1
                     << " / "
                     << num2
                     << " = "
                     << result
                     << endl;
            }
        }

        // Exponentiation
        else if (choice == 6)
        {
            result = exponentiate(num1, num2);

            cout << fixed << setprecision(2);

            cout << "Result: "
                 << num1
                 << " ^ "
                 << num2
                 << " = "
                 << result
                 << endl;
        }
    }

    return 0;
}

