#include <string>
#include <iostream>
#include <vector>
#include "kcipher.h"




/* Helper function definitions
 */
string rmSpaces(string str);

// -------------------------------------------------------
// Running Key Cipher implementation
// -------------------------------------------------------

struct KCipher::CipherCheshire{
    //vector<string> cont;
    //unsigned int id;
    string cipher_alpha;
};

/* Default constructor
   This will actually not encrypt the input text
   because it's using the unscrambled alphabet
 */
KCipher::KCipher() : Cipher()
{
    // Initialize smile pointer
    // smile pointer is pointer to CipherCheshire
    //smile->cipher_alpha = "abcdefghijklmnopqrstuvwxyz";
    set_id(0);
    //add_key();
}

/* This constructor initiates the object with a
   input kcipher key
 */
KCipher::KCipher(string key) : Cipher()
{
    string new_key = rmSpaces(key);
    book[0] = new_key;
    smile->cipher_alpha = book[0];
}

/*Destructor
 */
KCipher::~KCipher()
{
}

int KCipher::add_key(string key){
    pages +=1;
    string newKey = rmSpaces(key);
    book[pages] = key;
    return 1;
}

int KCipher::set_id(int page){
    id = page;
    smile->cipher_alpha = book[id];
    return 1;
}

string KCipher::encrypt(string raw){
    //FIXME
    // Each page of the book should be a non-empty str
    // If it is not, exit with EXIT_FAILURE
    /*for(unsigned int i = 0; i < raw[i].size(); i++){
        if(raw[i].size() == 0){
              cout << "Invalid page: " << raw[i] << endl;
              exit(EXIT_FAILURE);
        }
    }*/

    // Make sure key (not counting spaces) is >= to text trying
    // to encrypt (not counting spaces)
    // If it is not, exit with EXIT_FAILURE
    /*if(rmSpaces(raw).length() > smile->cipher_alpha.length()){
        cout << "Invalid key: " << raw << endl;
        exit(EXIT_FAILURE);
    }*/

    cout << "Encrypting...";
    string retStr;
    string new_key = rmSpaces(smile->cipher_alpha);

    int ind = -1;

    for(unsigned int i = 0; i< raw.length(); i++){
        ind++;
	if(raw[i] == ' '){
	   retStr += " ";
	   ind--;
	}
	else{
	    string text = "abcdefghijklmnopqrstuvwxyz";
	    int rot = find_pos(text, LOWER_CASE(raw[i]));
	    int c_ind = find_pos(text, LOWER_CASE(smile->cipher_alpha[ind]));
	    // Rotate text
	    rotate_string(text, rot);
	    if(raw[i] == UPPER_CASE(raw[i])){
	        retStr += UPPER_CASE(text[c_ind]);
	    }
	    else {
	        retStr += text[c_ind];
	    }
	}
    }
    cout << "Done" << endl;
    return retStr;
}

string KCipher::decrypt(string enc){
    //FIXME
    cout << "Decrypting...";
    cout << "Done" << endl;
    return enc;
}

// Function to remove all spaces from a given string
string rmSpaces(string str)
{
    string retStr;
    for(char &i : str)
        // If current char not space, place at index non_space_count++
        if (i != ' ')
        {
	    retStr += i;
	}
    return retStr;
}
