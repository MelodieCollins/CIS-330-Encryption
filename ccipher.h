#ifndef CCIPHER_H_
#define CCIPHER_H_
#include "cipher.h"

using namespace std;

/* A class that implements a
   Caesar cipher class. It 
   inherits the Cipher class */
class CCipher : public Cipher {
public:
    CCipher();
    CCipher(int rot);
    ~CCipher();
};
/* Helper function headers 
 */
void rotate_string(string& in_str, int rot);
#endif

