#include <iostream>
#include <regex>
#include <vector>

//int main() {
//    // �־��� ���� �̸���.
//    std::vector<std::string> file_names = { "db-123-log.txt", "db-124-log.txt",
//                                           "not-db-log.txt", "db-12-log.txt",
//                                           "db-12-log.jpg" };
//    std::regex re("db-\\d*-log\\.txt");
//    for (const auto& file_name : file_names) {
//        // std::boolalpha �� bool �� 0 �� 1 ��ſ� false, true �� ǥ���ϰ� ���ݴϴ�.
//        std::cout << file_name << ": " << std::boolalpha
//            << std::regex_match(file_name, re) << '\n';
//    }
//}

int main() {
    std::vector<std::string> phone_numbers = { "010-1234-5678", "010-123-4567",
                                              "011-1234-5567", "010-12345-6789",
                                              "123-4567-8901", "010-1234-567" };
    std::regex re("[01]{3}-(\\d{3,4})-\\d{4}");
    std::smatch match;  // ��Ī�� ����� string ���� ����
    for (const auto& number : phone_numbers) {
        if (std::regex_match(number, match, re)) {
            for (size_t i = 0; i < match.size(); i++) {
                std::cout << "Match : " << match[i].str() << std::endl;
            }
            std::cout << "-----------------------\n";
        }
    }
}