#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
//Prototypes
int count_letters (string text);
int count_words(string text);
int count_sentences (string text);
int main(void)
{
    //get user input
    string userText = get_string("Text: \n");
    //get letters, words and sentences count
    int letters = count_letters(userText);
    int words = count_words(userText);
    int sentences = count_sentences(userText);
    //Calculate grade level index
    float averageofLetters = ((float) letters / words) * 100;
    float averageofSentences = ((float) sentences / words) * 100;
    int gradeLevel = round(0.0588 * averageofLetters - 0.296 * averageofSentences - 15.8);
    // check grade
    if(gradeLevel < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(gradeLevel >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", gradeLevel);
    }
}
//letter counting function
int count_letters (string text)
{
    int letterCount = 0;
    int textLength = strlen(text);
    for(int i = 0; i < textLength; i++)
    {
        //Counting alphabetical letters only
        if(isalpha(text[i]))
        {
            letterCount++;
        }
    }
    return letterCount;
}
//word counting function
int count_words (string text)
{
    int wordCount = 1;
    int textLength = strlen(text);
    for(int i = 0; i < textLength; i++)
    {
        if(text[i] == ' ')
        {
            wordCount++;
        }
    }
    return wordCount;
}
//sentence counting function
int count_sentences (string text)
{
    int sentenceCount = 0;
    int textLength = strlen(text);
    for(int i = 0; i < textLength; i++)
    {
        //check for sentence indicators
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentenceCount++;
        }
    }
    return sentenceCount;
}
