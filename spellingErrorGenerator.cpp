#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/** Variables */
    int count = 0; //to count number of words in sentence to decide the number of words to be changed
    string vowels = "aeiou";
    string alphabets = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int available = 0; //the variable for checking logical characters
    int x = 0; //the variable for saving the choice of error
    int y = 0; //the variable for the index of a random letter in the sentence
    int z = 0; //the variable for number of errors to be done

/** Functions */
string spellingErrorGenerator(string& sentence){
    srand(time(0));           //initializing the random number generator
    x = (rand() % 3 )+ 1; // saving the random value from range  to 3
    y = (rand() %sentence.length()); //saving random value for a letter in the word to change
    z = 2; //starting from two for limiting the numbers of errors because the shortest sentence has at least 3 words

  //if the string is not empty
  if(sentence.length() != 0){

    for (int i =0; i<sentence.length(); i++){
            for(int j=0; j<alphabets.length(); j++){
                if(sentence[i]==alphabets[j])
                    available++;
            }
             if(sentence[i] == ' '){
                    count++;
             }
    }
    //returning with message saying either string is only of space characters or sentence is illogical
    if(count == sentence.length()-1 || available == 0 || count == 0){ //in case of a string with spaces only
        return "The string is empty! or Sentence is illogical!";
    }

    /**
        There will be three cases of error generating 1. duplication of a letter,
        2. swapping between two letters, 3.inserting vowels in between
    */
    do{
        while (sentence[y] == ' ' || sentence[y] == '.' || sentence[y] == '?' || sentence[y] == '!' || sentence[y] == ',' ||
               sentence[y] == ':' || sentence[y] == ';' || sentence[y] == '-'|| y==0){
            y = (rand() %sentence.length());
        }
        if(x == 1){//duplicate a letter of the word
            string c (1,sentence[y]); //changing the character to string to be able to use the insert method
            sentence.insert(y+1, c);
        }
        else if(x == 2 && y != 0){//switching places of letters
            char temp = sentence[y];
            if(y == sentence.length()-1 || sentence[y+1] == ' '||sentence[y+1] == '.' || sentence[y+1] == '?'
               || sentence[y+1] == '!' || sentence[y+1] == ',' || sentence[y+1] == ':' || sentence[y+1] == ';' ||
                sentence[y+1] == '-'){//to avoid switching with an index out of bound or with spaces,
                                        //swapping the letter with previous one
                    sentence[y] = sentence[y-1];
                    sentence[y-1] = temp;
            }
            else{//swapping the letter with next one
                sentence[y] = sentence[y+1];
                sentence[y+1] = temp;
            }
        }
        else{ //inserting a vowel in the word
            int z = rand()%5;
            string c(1,vowels[z]);
            if(sentence[y-1]!= ' ') //to avoid appending the letter to the beginning of the word
                sentence.insert(y,c);
            else{
                y++;
                sentence.insert(y,c);
            }
        }

        z++;
        x = (rand() % 3 )+ 1;
        y = (rand() %sentence.length());

    }while(z < count - 1);
    count = 0;
    return sentence;
  }
  else //in case of an empty string
    return "The sentence is empty!";
}

/** Main Function*/
int main(){
    string yesNo;
    string input;
    do{

        cout<<"Enter the sentence for error generating: " << endl;
        getline(cin,input);

        cout<<"Sentence after error has been generated: " << endl;
        cout<< spellingErrorGenerator(input) << endl;

        cout<< "Would like to try again? Press n or N to end or press anything else to continue" << endl;
        getline(cin,yesNo);

    }while(yesNo[0] != 'N' && yesNo[0]!= 'n');

    cout<<"Thank you for using the Spelling Error Generator :))"<< endl;
}
