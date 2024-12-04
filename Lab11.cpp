#include <iostream>
#include <regex>
#include <string>

struct Report {
private:
    std::string title;
    std::string creationDate;
    std::string reportNumber;
public:
    Report(const std::string& t, const std::string& cd, const std::string& rn)
        : title(t), creationDate(cd), reportNumber(rn) {
    }


    void checkReportNumber() {
        std::regex numbers_only("[^0-9]");
        reportNumber = std::regex_replace(reportNumber, numbers_only, "");
    }

    void displayReport() const {
        std::cout << "Report Info:\n";
        std::cout << "Title: " << title << "\n";
        std::cout << "Creation Date: " << creationDate << "\n";
        std::cout << "Report Number: " << reportNumber << "\n";
    }
};
int main() {
    Report report("Report", "4.12.24", "Aa12345hjk");

    report.checkReportNumber();
    report.displayReport();

    return 0;
}
