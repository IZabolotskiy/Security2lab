#include <string>
#include "Decryptor.h"
#include "RSA.h"
#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
using namespace boost::multiprecision;
using namespace Crypto;
using std::string;

Decryptor::Decryptor(const PrivateKey *key) : text(""), private_key(key)
{
};


string Decryptor::decryptString(CryptoString input)
{
  string cypher;

  int256_t tmp;
  int it;
  for (it = 0; it < input.size(); it++)
  {
    tmp = powm(input[it], private_key->s, private_key->q * private_key->p);
    cypher.push_back(tmp.convert_to<char>());
  }
  std::cout << private_key->p << " " << private_key->q<<std::endl;
  return cypher;
}

