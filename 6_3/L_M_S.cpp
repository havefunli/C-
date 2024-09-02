#include "L_M_S.h"

namespace mySpace{
	string path = "./Book_info.txt";
	list<Book> lt;

	void Main_menu() {
		cout << "---------------------" << endl;
		cout << "----- 0 ͼ�����-----" << endl;
		cout << "----- 1 ͼ���ѯ-----" << endl;
		cout << "----- 2 ͼ������-----" << endl;
		cout << "------3 �鿴����-----" << endl;
		cout << "------4 �˳�����-----" << endl;
		cout << "---------------------" << endl;
	}

	void book_menu() {
		cout << "---------------------" << endl;
		cout << "----- 0 ����ͼ��-----" << endl;
		cout << "----- 1 ɾ��ͼ��-----" << endl;
		cout << "----- 2 �޸���Ϣ-----" << endl;
		cout << "------3 �˳�����-----" << endl;
		cout << "---------------------" << endl;
	}

	void sort_menu() {
		cout << "---------------------------" << endl;
		cout << "------- 0 ����������ĸ-----" << endl;
		cout << "------- 1 ���չ���۸�-----" << endl;
		cout << "------- 2 ���չ���ʱ��-----" << endl;
		cout << "--------3 �˳�����---------" << endl;
		cout << "---------------------------" << endl;
	}

	bool cmp_letter(const Book& left, const Book& right) {
		return left._name > right._name;
	}

	bool cmp_price(const Book& left, const Book& right) {
		return left._price > right._price;
	}

	bool cmp_date(const Book& left, const Book& right) {
		return left._date > right._date;
	}

	void sort_by_letter() {
		lt.sort(cmp_letter);

		view_all_book();
	}

	void sort_by_price() {
		lt.sort(cmp_price);

		view_all_book();
	}

	void sort_by_date() {
		lt.sort(cmp_date);

		view_all_book();
	}

	void read_File() {
		string line;

		ifstream inputFile(path);
		if (!inputFile.is_open()) {
			cout << "�ļ���ʧ�ܣ�" << endl;
			return;
		}

		while (getline(inputFile, line)) {
			char delimiter = ';';
			size_t pos = 0;
			size_t end = 0;

			end = line.find(delimiter, pos);
			string book = line.substr(pos, end - pos); 
			pos = end + 1;

			end = line.find(delimiter, pos);
			string cate = line.substr(pos, end - pos);
			pos = end + 1;

			end = line.find(delimiter, pos);
			string intro = line.substr(pos, end - pos);
			pos = end + 1;

			end = line.find(delimiter, pos);
			double price = stof(line.substr(pos, end - pos));
			pos = end + 1;

			size_t date = stoi(line.substr(pos, line.size() - pos));

			lt.push_back({book, cate,intro,price,date});
		}

		inputFile.close();
	}

	void save_File() {
		ofstream outputFile(path, ios::out);
		if (!outputFile.is_open()) {
			cout << "�ļ���ʧ�ܣ�" << endl;
			return;
		}

		for (auto& book : lt) {
			outputFile << book._name << ';'
				<< book._cate << ';'
				<< book._intro << ';'
				<< book._price << ';'
				<< book._date << std::endl;
		}

		outputFile.close();
		cout << "�ļ�����ɹ�������" << endl;
	}

	void add_book() {
		string book;
		while (1) {
			cout << "����������: ";
			cin >> book;
			cout << endl;
			if (book.size() < 2) {
				cout << "�������Ϸ����������룺" << endl;
			}
			else break;
		}

		string cate;
		cout << "���������: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> cate;
		cout << endl;

		string intro;
		while (1) {
			cout << "��������: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, intro);
			cout << endl;
			if (intro.size() < 2) {
				cout << "��鲻�Ϸ����������룺" << endl;
			}
			else break;
		}


		double price;
		while (1) {
			std::cout << "������۸� ";
			std::cin >> price;
			std::cout << std::endl;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "�۸񲻺Ϸ����������룺" << std::endl;
			}
			else {
				// ���۸��Ƿ�Ϸ����������۸������ڵ���0��
				if (price < 0) {
					std::cout << "�۸񲻺Ϸ����������룺" << std::endl;
				}
				else {
					break;
				}
			}
		}


		size_t date;
		cout << "����������: ";
		cin >> date;
		cout << endl;

		Book new_book = { book, cate, intro, price, date };
		lt.push_back(new_book);
	}

	void del_book() {
		int flag = 0;
		cout << "����������Ҫɾ���������ƣ�";
		string del_name;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, del_name);
		cout << endl;

		list<Book>::iterator it = lt.begin();
		while (it != lt.end()) {
			if (it->_name == del_name) {
				lt.erase(it);
				flag = 1;

				cout << "ɾ���ɹ�������" << endl;
				break;
			}
			it++;
		}

		if (flag == 0) cout << "û���ҵ���Ҫɾ����ͼ�顣" << endl;
	}

	void modify_book() {
		int flag = 0;
		string query_name;
		cout << "����������Ҫ�޸ĵ������ƣ�";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, query_name);
		cout << endl;

		auto it = lt.begin();
		while (it != lt.end()) {
			if (it->_name == query_name) {
				flag = 1;
				cout << *it << endl;
				break;
			}
			it++;
		}

		if (flag == 0) cout << "û���ҵ���Ҫ��ͼ�顣" << endl;
		else {
			lt.erase(it);
			add_book();
		}
	}

	void Library_management() {
		int chioce = 0;
		do {
			book_menu();
			cin >> chioce;
			system("cls");

			switch (chioce) {
			case 0:
				add_book();
				break;
			case 1:
				del_book();
				break;
			case 2:
				modify_book();
				break;
			}
		} while (chioce != 3);
	}

	Book::Book(string name, string cate, string intro, double price, size_t date){
		 _name = name;
		 _cate = cate;
		 _intro = intro;
		 _price = price;
		 _date = date;
	}

	ostream& operator<<(ostream& output, const Book& book) {
		cout << "������" << book._name << endl;
		cout << "���" << book._cate << endl;
		cout << "��飺" << book._intro << endl;
		cout << "�۸�" << book._price << endl;
		cout << "�������ڣ�" << book._date << endl;

		return output;
	}

	bool Book_query() {
		int flag = 0;
		string query_name;
		cout << "����������Ҫ��ѯ�������ƣ�";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, query_name);
		cout << endl;

		for (auto& book : lt) {
			if (book._name == query_name) {
				flag = 1;
				cout << book << endl;
				return true;
			}
		}

		if(flag == 0) cout << "û���ҵ���Ҫ��ͼ�顣" << endl;
		return false;
	}

	void Book_sort() {
		int chioce = 0;
		do {
			sort_menu();
			cin >> chioce;
			system("cls");

			switch (chioce) {
			case 0:
				sort_by_letter();
				break;
			case 1:
				sort_by_price();
				break;
			case 2:
				sort_by_date();
				break;
			}
		} while (chioce != 3);
	}

	void view_all_book() {
		for (auto book : lt) {
			cout << book << endl;
		}
	}
}