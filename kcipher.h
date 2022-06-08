#ifndef KCIPHER_H_
#define KCIPHER_H_
#include "cipher.h"
#include "ccipher.h"

using namespace std;

const unsigned int MAX_LENGTH = 100;

/* A class that implements a
   Running key cipher class. It 
   inherts class Cipher */
class KCipher : public Cipher {
protected:
    int id = 0;
    int pages = 0;
    string book[MAX_LENGTH];
public:
    KCipher();
    KCipher(string key);
    ~KCipher();
    virtual int add_key(string key);
    virtual int set_id(int page);
    virtual string encrypt(string raw);
    virtual string decrypt(string enc);
};
#endif

