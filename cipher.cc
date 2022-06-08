#include "cipher.h"
#include<iostream>
#include<string>

/* Cheshire smile implementation.
   It only contains the cipher alphabet
 */
struct Cipher::CipherCheshire {
    string cipher_alpha;
};

/* This function checks the cipher alphabet
   to make sure it's valid
 */
bool is_valid_alpha(string alpha);


// -------------------------------------------------------
// Cipher implementation
/* Default constructor
   This will actually not encrypt the input text
   because it's using the unscrambled alphabet
 */
Cipher::Cipher()
{
    // Initialize smile pointer
    // smile pointer is pointer to CipherCheshire
    smile = new CipherCheshire;
    smile->cipher_alpha = "abcdefghijklmnopqrstuvwxyz";
}

/* This constructor initiates the object with a
   input cipher key
 */
Cipher::Cipher(string cipher_alpha)
{
    if(!is_valid_alpha(cipher_alpha)){
        cout << "Invalid cipher alphabet/key: " << cipher_alpha << endl;
	exit(EXIT_FAILURE);
    }
    smile = new CipherCheshire {cipher_alpha};
}

/* Destructor
 */
Cipher::~Cipher()
{
    delete smile;
}

string Cipher::getCipherAlpha(){
    return smile->cipher_alpha;
};

/* This member function encrypts the input text 
   using the intialized cipher key
 */
string Cipher::encrypt(string raw)
{
    string cipher_alpha = getCipherAlpha();
    cout << "Encrypting...";
    string retStr;
    char curr;
    for(unsigned int i = 0; i < raw.length(); i++){
        curr = raw[i];
	// Space should not be encrypted
	if(curr == ' '){
	    retStr += " ";
	    continue;
	}
	// Find index of current character
	int ind = LOWER_CASE(curr) - 'a';
	
	// Get replacement character
	char replacement = cipher_alpha[ind];
        // Check if current character is upper case
	if(curr == UPPER_CASE(curr)){
            // Upper case letter should be encrypted to an upper case letter
            replacement = UPPER_CASE(replacement);
        }
	retStr += replacement;
    }
    cout << "Done" << endl;

    return retStr;
}


/* This member function decrypts the input text 
   using the intialized cipher key
 */
string Cipher::decrypt(string enc)
{
    string cipher_alpha = getCipherAlpha();
    string retStr;
    cout << "Decrypting...";

    for(unsigned int i = 0; i < enc.length(); i++){
        char curr = enc[i];
	// Retain the space
	if(curr == ' '){
	    retStr += " ";
	    continue;
	}
	// Find index of current character
	int ind = find_pos("abcdefghijklmnopqrstuvwxyz", LOWER_CASE(curr));
        
	// Get replacement character
	char replacement = cipher_alpha[ind];

        // Check if current character is upper case
	if(curr == UPPER_CASE(curr)){
            // Retain the case
            replacement = UPPER_CASE(replacement);
        }
	retStr += replacement;
    }
    cout << "Done" << endl;

    return retStr;

}
// -------------------------------------------------------


//  Helper functions 
/* Find the character c's position in the cipher alphabet/key
 */
unsigned int find_pos(string alpha, char c)
{
    for(long unsigned int i = 0; i < alpha.length(); i++) {
        if(alpha[i] == c){
	    return i;
	}
    }
    return -1;
}

/* Make sure the cipher alphabet is valid - 
   a) it must contain every letter in the alphabet 
   b) it must contain only one of each letter 
   c) it must be all lower case letters 
   ALL of the above conditions must be met for the text to be a valid
   cipher alphabet.
 */
bool Cipher::is_valid_alpha(string alpha)
{
    bool is_valid = true;
    if(alpha.size() != ALPHABET_SIZE) {
        is_valid = false; 
    } else {
        unsigned int letter_exists[ALPHABET_SIZE];
        for(unsigned int i = 0; i < ALPHABET_SIZE; i++) {
            letter_exists[i] = 0;
        }
        for(unsigned int i = 0; i < alpha.size(); i++) {
            char c = alpha[i];
	    if(!((c >= 'a') && (c <= 'z'))) {
		    is_valid = false;
            } else {
                letter_exists[(c - 'a')]++;
            }
        }
        for(unsigned int i = 0; i < ALPHABET_SIZE; i++) {
            if(letter_exists[i] != 1) {
                is_valid = false;
            }
        }
    }

    return is_valid;
}
