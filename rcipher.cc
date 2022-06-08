#include <string>
#include <iostream>
#include "rcipher.h"

// -------------------------------------------------------
// ROT13 Cipher implementation
// -------------------------------------------------------

struct RCipher::CipherCheshire {
    string cipher_alpha;
};

/* Default constructor
   This will actually not encrypt the input text
   because it's using the unscrambled alphabet
 */

RCipher::RCipher(): CCipher(13)
{
}
