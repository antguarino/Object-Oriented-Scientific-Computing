/** Implementation file for key encryption
 *
 *  \file imgs/ipcv/key_encryption/KeyEncryption.cpp
 *  \author Carl Salvaggio, Ph.D. (salvaggio@cis.rit.edu)
 *  \date 10 January 2020
 *
 * \author Anthony Guarino (ag4933@rit.edu)
 * \date 28 March 2024
 */
#include <vector>
#include "imgs/ipcv/key_encryption/KeyEncryption.h"

namespace ipcv {

// Encrypts a string based on a given key
std::string KeyEncrypt(const std::string& key, const std::string& str) {
  // Create string
  std::string encrypted_str;
  encrypted_str.reserve(str.size());

  // Adds the encrypted character for each index of the string
  for (size_t i = 0; i < str.size(); i++) {
    encrypted_str.push_back(
        ((str.at(i) - 32) + (key.at(i % key.size()) - 32)) % (127 - 32) + 32);
  }
  return encrypted_str;
}

// Decrypts a string based on a given key
std::string KeyDecrypt(const std::string& key, const std::string& str) {
  std::string decrypted_str;
  decrypted_str.reserve(str.size());

  // Adds the decrypted character for each index of the encrypted string
  for (size_t i = 0; i < str.size(); i++) {
    // If the calculation is negetive, make it a usable character
    if ((str.at(i) - 32) - (key.at(i % key.size()) - 32) < 0) {
      decrypted_str.push_back((str.at(i) - 32) - (key.at(i % key.size()) - 32) +
                              (127 - 32) + 32);
    }

    else {
      decrypted_str.push_back((str.at(i) - 32) - (key.at(i % key.size()) - 32) +
                              32);
    }
  }
  return decrypted_str;
}

// Finds the key based on an encrypted and original string
std::string KeyFinder(const std::string& encrypted_str,
                      const std::string& str) {
  std::string key;
  key.reserve(str.size());

  // Goes through the string and calculates the key value
  for (size_t i = 0; i < str.size(); i++) {
    if (((encrypted_str.at(i) + 32) - (str.at(i) + 32)) < 0) {
      key.push_back((encrypted_str.at(i) + 32) - (str.at(i) + 32) + 127);
    }

    else {
      key.push_back((encrypted_str.at(i) + 32) - (str.at(i) + 32) + 32);
    }

    // Checks if the key has repeated and if it does, return the key
    if (key.substr(0, key.size() / 2) == key.substr(key.size() / 2)) {
      return key.substr(0, key.size() / 2);
    }
  }
  return key;
}
}