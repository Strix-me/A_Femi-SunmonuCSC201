#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>  // Include this header for max function
#include <cstdlib>
#include <ctime>
#include <cctype>

using namespace std;

// Structure to represent a question
struct Question {
    string questionText;
    vector<string> options;
    char correctOption;
    char userChoice;
};

// Function to read questions from a file and populate a vector
void readQuestionsFromFile(vector<Question>& questions, const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    Question q;
    while (getline(file, q.questionText)) {
        for (char c = 'A'; c < 'A' + 4; ++c) {
            string option;
            getline(file, option);
            q.options.push_back(option);
        }

        file >> q.correctOption;
        file.ignore(); // Ignore the newline character
        questions.push_back(q);
    }

    file.close();
}

// Function to display a question and get user's choice
void displayQuestion(Question& q) {
    cout << q.questionText << endl;
    for (size_t i = 0; i < q.options.size(); ++i) {
        cout << static_cast<char>('A' + i) << ". " << q.options[i] << endl;
    }
}

// Function to get and validate user input for a choice
char getUserChoice() {
    char choice;
    cout << "Enter your choice (A/B/C/D): ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    // Convert the choice to uppercase
    choice = toupper(choice);

    // Validate the choice
    if (choice < 'A' || choice > 'D') {
        cout << "Invalid choice. Please enter a valid option." << endl;
        return getUserChoice(); // Recursive call to get a valid choice
    }

    return choice;
}

int main() {
    // srand(time(nullptr)); // Removed randomization

    vector<Question> questions;
    readQuestionsFromFile(questions, "C:\\Users\\abdul\\OneDrive\\Documents\\A_Femi-SunmonuCSC201\\CA 1\\questions.txt"); // Replace with your actual file name

    // No random_shuffle, questions are presented in the order they appear in the file

    int score = 0;

    for (Question& q : questions) {
        displayQuestion(q);

        // Get user's choice for the current question
        q.userChoice = getUserChoice();

        // Check if the user's choice is correct
        if (q.userChoice == q.correctOption) {
            cout << "Correct!" << endl;
            ++score;
        } else {
            cout << "Incorrect. The correct answer is " << q.correctOption << "." << endl;
        }
    }

    // Display the final score
    cout << "Your score: " << score << "/" << questions.size() << endl;

    // Optionally, you can implement additional features such as viewing the test script.

    return 0;
}
