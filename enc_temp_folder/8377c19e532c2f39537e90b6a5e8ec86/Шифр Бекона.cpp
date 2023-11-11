
#include <iostream>
#include <string>
#include <cctype>  // для функцій tolower та toupper

class BaconCipher {
private:
    std::string key;

public:
    // Конструктор приймає ключ-ланцюжок
    BaconCipher(const std::string& cipherKey) : key(cipherKey) {}

    // Функція шифрування тексту
    std::string encrypt(const std::string& message) const {
        std::string encryptedMessage;

        for (char ch : message) {
            if (std::isalpha(ch)) {
                // Визначення регістру та позиції літери в алфавіті
                char baseChar = std::islower(ch) ? 'a' : 'A';
                int index = ch - baseChar;

                // Створення ab-групи
                encryptedMessage += key.substr(index * 5, 5);
            }
            else {
                // Збереження символів, які не є літерами
                encryptedMessage += ch;
            }
        }

        return encryptedMessage;
    }

    // Функція дешифрування тексту
    std::string decrypt(const std::string& cipherText) const {
        std::string decryptedMessage;

        for (size_t i = 0; i < cipherText.length(); i += 5) {
            std::string group = cipherText.substr(i, 5);

            // Пошук позиції ab-групи в ключ-ланцюжку
            size_t index = key.find(group);

            if (index != std::string::npos) {
                // Визначення літери та регістру
                char baseChar = (index / 5) + 'a';
                decryptedMessage += baseChar;
            }
            else {
                // Збереження символів, які не є ab-групами
                decryptedMessage += group;
            }
        }

        return decryptedMessage;
    }
};

int main() {
    // Задання ключ-ланцюжка
    std::string cipherKey = "aaaaabbbbbabbbaabbababbaaababaab";

    // Створення об'єкта шифрування
    BaconCipher cipher(cipherKey);

    // Початкове повідомлення
    std::string originalMessage = "Prometheus";

    // Шифрування та виведення результату
    std::string encryptedMessage = cipher.encrypt(originalMessage);
    std::cout << "Encrypted Message: " << encryptedMessage << std::endl;

    // Дешифрування та виведення результату
    std::string decryptedMessage = cipher.decrypt(encryptedMessage);
    std::cout << "Decrypted Message: " << decryptedMessage << std::endl;

    return 0;
}
