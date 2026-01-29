//MENNATALLAH AHMED ABDEL SALAM AHMED 25P0276
#include <iostream>
#include <cstring>
using namespace std;
const char letters[] = "ABCDEFGHILMNOPQRSTUVZ";

void cipherfunc(char word[], int key1, int key2, char ciphered[]) {
    int size = strlen(word);// stores the size of sentance input inside variable 'size'
    int n = strlen(letters);/* we must store the length inside a variable / then we must call letters array inside it
	so here we stored the length of alphabet inside variable 'n'*/
    int lowercase;//to store lowercase letters
    int valueCipher;// variable that stores values of index after cipher
    int idx = 0; // index for ciphered array
    for (int i = 0; i < size; i++) {//to move through the inputted sentnece letter by letter
        if (word[i] == ' ') {// check for the space
            ciphered[idx++] = ' ';// We add the space to the 'ciphered' array and increment the index 'idx'
        }
        else {
            for (int j = 0; j < n; j++) {//searches through the 'letters' array to find the position of the current letter
                if (letters[j] == toupper(word[i])) {
                    valueCipher = (key1 * j + key2) % n;//equation to change to cipher / note we multiplied by 'j' not 'i' because we need the number of index in alphabet not the word entered 
                 
                    if (islower(word[i])) {//check if the word has lowercase letters 
                        lowercase = tolower(letters[valueCipher]);//it makes the ciphered new letter remain small and stores it inside 'lowercase' variable
                        ciphered[idx++] = lowercase;// We add the lowercase ciphered letter to the 'ciphered' array and increment 'idx'
                        break;
                    }
                    else {
                        ciphered[idx++] = letters[valueCipher];// We add the uppercase ciphered letter to the 'ciphered' array and increment 'idx'
                        break;
                    }
                }
            }
        }
    }
    ciphered[idx] = '\0'; // we add a null character to the end of the 'ciphered' array to mark the end of the string
    cout << "The ciphered text is: " << ciphered << endl;
}
int find_inverse(int a, int n) {//function that find inverse for a
    for (int i = 0; i < n; i++) {
        if ((a * i) % n == 1) {
            return i;
        }
    }
    return -1; // no inverse found
}
void decipherfunc(char word[], int key1, int key2) {
    int n = strlen(letters);
    int a_inv = find_inverse(key1, n);// We call the 'find_inverse' function to get the  inverse of 'key1'. If it returns -1, no inverse exists
    if (a_inv == -1) {//If no inverse was foundthen sentence invalid for deciphering
        cout << "The deciphered text is:invalid" << endl;
        return;
    }
    int size = strlen(word);//calculate length of ciphered word and store it in variable 'size'
    int lowercase;//to store lowercase letters
    cout << "The deciphered text is: ";
    for (int i = 0; i < size; i++) {//to go through each letter in ciphered 'word'
        if (word[i] == ' ') {
            cout << ' ';
        }
        else {
            for (int j = 0; j < n; j++) {
                if (letters[j] == toupper(word[i])) {
                    int valueofdicipher = (a_inv * ((j - key2 +n ) % n)) % n; //inverse formula to calculate original position
                    if (islower(word[i])) {
                        lowercase = tolower(letters[valueofdicipher]);
                        cout << lowercase;
                        break;
                    }
                    else {
                        cout << letters[valueofdicipher];//output the deciphered uppercase letter
                        break;
                    }
                }
            }
        }
    }
    cout << endl;
}

int main() {
    int a;// variable that stores the first key
    int b;// variable that stores the second key
    char sentence[20000];// array that stores input sentence
    char ciphered[20000];// array that stores CIPHERED sentence
    cout << "Please enter sentence to cipher: ";
    cin.getline(sentence, 20000);// used getline as cin stops during spaces
    cout << "Please enter value of the first key a: ";
    cin >> a; // input first key
    cout << "Please enter value of the second key b: ";
    cin >> b;// input second key
    cipherfunc(sentence, a, b, ciphered);//CIPHER function call
    decipherfunc(ciphered, a, b);//DECIPHER function call
    return 0;
}