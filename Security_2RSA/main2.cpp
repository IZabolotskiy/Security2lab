#include <iostream>
#include <exception>
#include "RSA.h"
#include "Decryptor.h"
#include "Encryptor.h"

using std::string;

int main()
{
  try
  {
    Crypto::RSA rsa(11, 17, 3);

    // String message to encrypt
    string in_str;
    std::cout << "[INF] Please enter a string message...\n";
    //std::getline(std::cin, in_str);
    in_str =
    Crypto::CryptoString out_str = rsa.encrypt(in_str);  // Encrypt message
    
    string res_str = rsa.decrypt(out_str);               // Decrypt message

    std::cout << "[INF] Result of RSA:\n";
    std::cout << "Input Message:     " << in_str << "\n";
   // std::cout  << "Encrypted message: " << out_str << "\n";
      std::cout        << "Decrypted message: " << res_str << "\n";

    // ------------------------------------------------------------------------

    // Character to encrypt
    char in_ch;
    std::cout << "[INF] Please enter one character...\n";
    std::cin >> in_ch;

    Crypto::CryptoChar out_ch = rsa.encrypt(in_ch);
    char res_ch = rsa.decrypt(out_ch);

    std::cout << "[INF] Result of RSA:\n";
    std::cout << "Input Message:     " << in_ch << "\n"
      //<< "Encrypted message: " << out_str << "\n"
      << "Decrypted message: " << res_ch << "\n";

    // -------------------------
    std::string tmp;
    std::getline(std::cin, tmp);

  }
  catch (std::exception &e)
  {
    std::cout << "[ERR] RSA-exception thrown!\n";
    std::cout << e.what();
  }

  return 0;
}
