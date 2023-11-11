
#include <iostream>
#include <string>
#include <cctype>  

class BaconCipher {
private:
    std::string key;

public:
   
    BaconCipher(const std::string& cipherKey) : key(cipherKey) {}

    
    std::string encrypt(const std::string& message) const {
        std::string encryptedMessage;

        for (char ch : message) {
            if (std::isalpha(ch)) {
                
                char baseChar = std::islower(ch) ? 'a' : 'A';
                int index = ch - baseChar;

                
                encryptedMessage += key.substr(index * 5, 5);
            }
            else {
               
                encryptedMessage += ch;
            }
        }

        return encryptedMessage;
    }

    
    std::string decrypt(const std::string& cipherText) const {
        std::string decryptedMessage;

        for (size_t i = 0; i < cipherText.length(); i += 5) {
            std::string group = cipherText.substr(i, 5);

           
            size_t index = key.find(group);

            if (index != std::string::npos) {
                
                char baseChar = (index / 5) + 'a';
                decryptedMessage += baseChar;
            }
            else {
                
                decryptedMessage += group;
            }
        }

        return decryptedMessage;
    }
};

int main() {
    
    std::string cipherKey = "aaaaabbbbbabbbaabbababbaaababaab";

    BaconCipher cipher(cipherKey);

    
    std::string originalMessage = "Prometheus";

    
    std::string encryptedMessage = cipher.encrypt(originalMessage);
    std::cout << "Encrypted Message: " << encryptedMessage << std::endl;

    
    std::string decryptedMessage = cipher.decrypt(encryptedMessage);
    std::cout << "Decrypted Message: " << decryptedMessage << std::endl;

    return 0;
}
