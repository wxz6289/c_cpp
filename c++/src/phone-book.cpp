#include <iostream>
#include <vector>
#include <string>

struct Contact {
    std::string name;
    std::string phone;
};

class PhoneBook {
public:
    void addContact(const std::string& name, const std::string& phone) {
        contacts.push_back({name, phone});
    }
    void listContacts() const {
        std::cout << "通讯录列表：\n";
        for (size_t i = 0; i < contacts.size(); ++i) {
            std::cout << i + 1 << ". " << contacts[i].name << " - " << contacts[i].phone << std::endl;
        }
    }
    void searchContact(const std::string& keyword) const {
        std::cout << "搜索结果：\n";
        for (const auto& c : contacts) {
            if (c.name.find(keyword) != std::string::npos || c.phone.find(keyword) != std::string::npos) {
                std::cout << c.name << " - " << c.phone << std::endl;
            }
        }
    }
    void removeContact(size_t index) {
        if (index > 0 && index <= contacts.size()) {
            contacts.erase(contacts.begin() + index - 1);
            std::cout << "已删除第" << index << "个联系人。" << std::endl;
        } else {
            std::cout << "索引无效。" << std::endl;
        }
    }
    bool editContact(size_t index, const std::string &newName, const std::string &newPhone) {
        if (index == 0 || index > contacts.size()) return false;
        Contact &c = contacts[index - 1];
        if (!newName.empty()) c.name = newName;
        if (!newPhone.empty()) c.phone = newPhone;
        return true;
    }

    void clearContacts() {
        contacts.clear();
        std::cout << "已清空通讯录。" << std::endl;
    }
private:
    std::vector<Contact> contacts;
};

int main() {
    PhoneBook pb;
    std::string line;
    while (true) {
        std::cout << "\n1. 添加联系人\n2. 列出所有联系人\n3. 搜索联系人\n4. 删除联系人\n5. 修改联系人\n6. 清空通讯录\n0. 退出\n请选择：";
        if (!std::getline(std::cin, line)) break;
        if (line.empty()) continue;
        int choice = 0;
        try { choice = std::stoi(line); } catch (...) { std::cout << "输入无效。\n"; continue; }
        if (choice == 0) break;
        if (choice == 1) {
            std::string name, phone;
            std::cout << "姓名：";
            std::getline(std::cin, name);
            std::cout << "电话：";
            std::getline(std::cin, phone);
            pb.addContact(name, phone);
        } else if (choice == 2) {
            pb.listContacts();
        } else if (choice == 3) {
            std::string keyword;
            std::cout << "请输入关键字：";
            std::getline(std::cin, keyword);
            pb.searchContact(keyword);
        } else if (choice == 4) {
            std::string sidx;
            std::cout << "请输入要删除的联系人序号：";
            std::getline(std::cin, sidx);
            size_t idx = 0;
            try { idx = std::stoul(sidx); } catch (...) { std::cout << "索引无效。\n"; continue; }
            pb.removeContact(idx);
        } else if (choice == 5) {
            pb.listContacts();
            std::string sidx;
            std::cout << "请输入要修改的联系人序号：";
            std::getline(std::cin, sidx);
            size_t idx = 0;
            try { idx = std::stoul(sidx); } catch (...) { std::cout << "索引无效。\n"; continue; }
            std::string newName, newPhone;
            std::cout << "新的姓名（回车保持不变）：";
            std::getline(std::cin, newName);
            std::cout << "新的电话（回车保持不变）：";
            std::getline(std::cin, newPhone);
            if (pb.editContact(idx, newName, newPhone)) {
                std::cout << "修改成功。" << std::endl;
            } else {
                std::cout << "索引无效，修改失败。" << std::endl;
            }
        } else if (choice == 6) {
            std::cout << "确定清空通讯录吗？(y/N)：";
            std::string confirm;
            std::getline(std::cin, confirm);
            if (!confirm.empty() && (confirm[0]=='y' || confirm[0]=='Y')) pb.clearContacts();
            else std::cout << "已取消。" << std::endl;
        } else {
            std::cout << "无效选择。" << std::endl;
        }
    }
    std::cout << "已退出。" << std::endl;
    return 0;
}
