#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class PasswordAnalyzer
{
private:
    string password;
    int score;

    bool hasUpper;
    bool hasLower;
    bool hasDigit;
    bool hasSpecial;
    bool hasRepeated;

public:

    PasswordAnalyzer()
    {
        score = 0;
        hasUpper = false;
        hasLower = false;
        hasDigit = false;
        hasSpecial = false;
        hasRepeated = false;
    }

    void getPassword()
    {
        cout << "\n====================================";
        cout << "\n   PASSWORD SECURITY ANALYZER";
        cout << "\n====================================";

        cout << "\n\nEnter password: ";
        getline(cin, password);
    }

    void analyzeCharacters()
    {
        for (int i = 0; i < password.length(); i++)
        {
            char ch = password[i];

            if (isupper(ch))
                hasUpper = true;

            else if (islower(ch))
                hasLower = true;

            else if (isdigit(ch))
                hasDigit = true;

            else
                hasSpecial = true;
        }
    }

    void checkRepeatedCharacters()
    {
        for (int i = 0; i < password.length() - 2; i++)
        {
            if (password[i] == password[i + 1] &&
                password[i] == password[i + 2])
            {
                hasRepeated = true;
                return;
            }
        }
    }

    void calculateScore()
    {
        score = 0;

        // Length score
        if (password.length() >= 8)
            score += 20;

        if (password.length() >= 12)
            score += 15;

        if (password.length() >= 16)
            score += 10;

        // Character variety
        if (hasUpper)
            score += 15;

        if (hasLower)
            score += 10;

        if (hasDigit)
            score += 15;

        if (hasSpecial)
            score += 15;

        // Penalty
        if (hasRepeated)
            score -= 15;

        if (password == "password" ||
            password == "12345678" ||
            password == "qwerty123")
        {
            score -= 40;
        }

        if (score < 0)
            score = 0;

        if (score > 100)
            score = 100;
    }

    void displayAnalysis()
    {
        cout << "\n\n========== SECURITY REPORT ==========";

        cout << "\nPassword Length      : "
             << password.length();

        cout << "\nUppercase Letters    : "
             << (hasUpper ? "YES" : "NO");

        cout << "\nLowercase Letters    : "
             << (hasLower ? "YES" : "NO");

        cout << "\nNumbers              : "
             << (hasDigit ? "YES" : "NO");

        cout << "\nSpecial Characters   : "
             << (hasSpecial ? "YES" : "NO");

        cout << "\nRepeated Characters  : "
             << (hasRepeated ? "YES" : "NO");

        cout << "\n-------------------------------------";

        cout << "\nSecurity Score       : "
             << score << "/100";

        cout << "\nSecurity Level       : ";

        if (score >= 85)
            cout << "VERY STRONG";

        else if (score >= 70)
            cout << "STRONG";

        else if (score >= 50)
            cout << "MEDIUM";

        else if (score >= 30)
            cout << "WEAK";

        else
            cout << "VERY WEAK";

        cout << "\n-------------------------------------";

        cout << "\n\nSuggestions:";

        if (password.length() < 12)
            cout << "\n- Use at least 12 characters.";

        if (!hasUpper)
            cout << "\n- Add uppercase letters.";

        if (!hasLower)
            cout << "\n- Add lowercase letters.";

        if (!hasDigit)
            cout << "\n- Add numbers.";

        if (!hasSpecial)
            cout << "\n- Add special characters.";

        if (hasRepeated)
            cout << "\n- Avoid repeating the same character.";

        if (score >= 85)
            cout << "\n- Excellent password structure!";

        cout << "\n\n=====================================\n";
    }

    void run()
    {
        getPassword();
        analyzeCharacters();
        checkRepeatedCharacters();
        calculateScore();
        displayAnalysis();
    }
};

int main()
{
    PasswordAnalyzer analyzer;

    analyzer.run();

    return 0;
}
