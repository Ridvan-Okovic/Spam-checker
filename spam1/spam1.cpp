#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

int countFreq(string text, string subtext)
{
    int subtextLength = subtext.length();
    int textLength = text.length();
    int counter = 0;

    for (int i = 0; i <= textLength - subtextLength; i++)
    {
        int j;
        for (j = 0; j < subtextLength; j++)
        {
            if (text[i+j] != subtext[j])
            {
                break;
            }
        }

        if (j == subtextLength)
        {
           counter++;
        }
    }
    return counter;
}

int calculateSpamGrade(string inputText)
{
    int grade = 0;

    grade+= countFreq(inputText, "$") * 10;
    grade+= countFreq(inputText, "earn per week") * 20;
    grade+= countFreq(inputText, "double your") * 20;
    grade+= countFreq(inputText, "income in one week") * 15;
    grade+= countFreq(inputText, "trial that lasts forever") * 30;
    grade+= countFreq(inputText, "opportunity") * 10;
    grade+= countFreq(inputText, "income") * 10;
    grade+= countFreq(inputText, "cash") * 20;
    grade+= countFreq(inputText, "month free trial") * 15;
    grade+= countFreq(inputText, "your love life") * 25;




    return grade;
    /*std::size_t found = inputText.find("$");
    if (found!=std::string::npos)
    {
        grade += 10;
    }*/

    /*int counter = 0;
    for(int i=0; inputText[i] != '\0'; i++)
    {
        if(inputText[i] == '$')
        {
            counter++;
        }
    }

    grade += counter*10;

    counter = 0;
    for(int i=0; inputText[i] != '\0'; i++)
    {
        if(inputText[i] == 'e')
        {
            if(inputText[i+1] == 'a' && inputText[i+2] == 'r' && inputText[i+3] == 'n'
               && inputText[i+4] == ' ' && inputText[i+5] == 'p' && inputText[i+6] == 'e' && inputText[i+7] == 'r' && inputText[i+8] == ' '
               && inputText[i+9] == 'w' && inputText[i+10] == 'e' && inputText[i+11] == 'e' && inputText[i+12] == 'k')
            {
                counter++;
            }
        }
    }

    grade+= counter*20;*/



    /*found = inputText.find("earn per week");
    if (found!=std::string::npos)
    {
        grade += 20;
    }

    found = inputText.find("double your");
    if (found!=std::string::npos)
    {
        grade += 20;
    }

    found = inputText.find("income in one week");
    if (found!=std::string::npos)
    {
        grade += 15;
    }

    found = inputText.find("trial that lasts forever");
    if (found!=std::string::npos)
    {
        grade += 30;
    }

    found = inputText.find("opportunity");
    if (found!=std::string::npos)
    {
        grade += 10;
    }

    found = inputText.find("income");
    if (found!=std::string::npos)
    {
        grade += 10;
    }

    found = inputText.find("cash");
    if (found!=std::string::npos)
    {
        grade += 10;
    }

    found = inputText.find("month free trial");
    if (found!=std::string::npos)
    {
        grade += 15;
    }

    found = inputText.find("your love life");
    if (found!=std::string::npos)
    {
        grade += 25;
    }*/
}

int number_of_spam_words(string inputText)
{
    int word = 0;
    word+= countFreq(inputText, "$") * 1;
    word+= countFreq(inputText, "earn per week") * 3;
    word+= countFreq(inputText, "double your") * 2;
    word+= countFreq(inputText, "income in one week") * 4;
    word+= countFreq(inputText, "trial that lasts forever") * 4;
    word+= countFreq(inputText, "opportunity") * 1;
    word+= countFreq(inputText, "income") * 1;
    word+= countFreq(inputText, "cash") * 1;
    word+= countFreq(inputText, "month free trial") * 3;
    word+= countFreq(inputText, "your love life") * 3;
    return word;
}

int main()
{
    //string input;
    //getline(cin, input, '\n');
    std::ifstream mail;
    mail.open("mail.txt");
    std::string buffer;
    std::string line;

    while(mail)
        {
        std::getline(mail, line);
        }
    mail.close();



    line.erase(std::remove(line.begin(), line.end(), '.'), line.end());
    line.erase(std::remove(line.begin(), line.end(), ','), line.end());
    line.erase(std::remove(line.begin(), line.end(), '!'), line.end());


    transform(line.begin(), line.end(), line.begin(), ::tolower);
    cout << line << endl;

    int spamGrade = calculateSpamGrade(line);

    int spamWord = number_of_spam_words(line);

    int number_of_words;
    number_of_words = std::count(line.begin(), line.end(), ' ') + 1;

    float spamPercentage;
    spamPercentage = ((spamWord)/(number_of_words * 1.00) * 100);
    //cout << "Percentage of spam words: " << spamPercentage << endl;

    ofstream result;
    result.open("result.txt");

    result << "Number of spam words in the string: " << spamWord << endl;
    result << "There are " << number_of_words << " words in the string." << endl;
    //result << "Percentage of spam words is " << endl;
    result << "The score is: " << spamGrade << " points, " << " ";

    if(spamGrade < 10)
    {
        result << "Not Spam!" << endl;
    }
    else if((spamGrade >= 10 && spamGrade < 50))
    {
        result << "Maybe Spam!" << endl;
    }
    else
    {
        result << "Definitely Spam!" << endl;
    }

    result << "The percentage is: " << spamPercentage << "%, " << " ";
    if(spamPercentage < 15)
    {
        result << "Not Spam!" << endl;
    }
    else if(spamPercentage >= 15 && spamPercentage < 50)
    {
        result << "Maybe Spam!" << endl;
    }
    else
    {
        result << "Definitely Spam!" << endl;
    }

    result.close();

    return 0;
}
