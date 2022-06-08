#include <string>
#include <iostream>
#include <algorithm>
#include "ccipher.h"

// -------------------------------------------------------
// Caesar Cipher implementation


// -------------------------------------------------------

struct CCipher::CipherCheshire{
    string cipher_alpha;
};

/* Default constructor
   This will actually not encrypt the input text
   because it's using the unscrambled alphabet
 */
CCipher::CCipher() : Cipher()
{
    // Initialize smile pointer
    // smile pointer is pointer to CipherCheshire
    smile->cipher_alpha = "abcdefghijklmnopqrstuvwxyz";
}

/* This constructor initiates the object with a
   input ccipher key
 */
CCipher::CCipher(int rot) : CCipher()
{   
    rotate_string(smile->cipher_alpha, rot);
}

/* Destructor
 */
CCipher::~CCipher()
{
    //delete smile;
}

void reverseStr(string& str, int start, int end)
{
    for (int i = 0; i < (end-start)/2; i++){
         swap(str[i+start], str[end - i - 1]);
    }
}
// Rotates the input string in_str by rot positions
void rotate_string(string& in_str, int rot)
{
    rot = rot % in_str.length();
    //cout << "a " << in_str << endl;
    reverseStr(in_str, 0, rot);
    //cout << "b " << in_str << endl;
    reverseStr(in_str, rot, in_str.length());
    //cout << "c " << in_str << endl;
    reverseStr(in_str, 0, in_str.length());
    //cout << "d " << in_str << endl;
}
