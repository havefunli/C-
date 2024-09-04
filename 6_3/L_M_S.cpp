#include "L_M_S.h"

namespace mySpace{
	string path = "./Book_info.txt";
	list<Book> lt;

	void Main_menu() {
		cout << "---------------------" << endl;
		cout << "----- 0 图书管理-----" << endl;
		cout << "----- 1 图书查询-----" << endl;
		cout << "----- 2 图书排序-----" << endl;
		cout << "------3 查看藏书-----" << endl;
		cout << "------4 退出界面-----" << endl;
		cout << "---------------------" << endl;
	}

	void book_menu() {
		cout << "---------------------" << endl;
		cout << "----- 0 增加图书-----" << endl;
		cout << "----- 1 删除图书-----" << endl;
		cout << "----- 2 修改信息-----" << endl;
		cout << "------3 退出界面-----" << endl;
		cout << "---------------------" << endl;
	}

	void sort_menu() {
		cout << "---------------------------" << endl;
		cout << "------- 0 按照书首字母-----" << endl;
		cout << "------- 1 按照购买价格-----" << endl;
		cout << "------- 2 按照购买时间-----" << endl;
		cout << "--------3 退出界面---------" << endl;
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
			cout << "文件打开失败！" << endl;
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
			cout << "文件打开失败！" << endl;
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
		cout << "文件保存成功！！！" << endl;
	}

	void add_book() {
		string book;
		while (1) {
			cout << "请输入书名: ";
			cin >> book;
			cout << endl;
			if (book.size() < 2) {
				cout << "书名不合法请重新输入：" << endl;
			}
			else break;
		}

		string cate;
		cout << "请输入类别: ";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> cate;
		cout << endl;

		string intro;
		while (1) {
			cout << "请输入简介: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, intro);
			cout << endl;
			if (intro.size() < 2) {
				cout << "简介不合法请重新输入：" << endl;
			}
			else break;
		}


		double price;
		while (1) {
			std::cout << "请输入价格： ";
			std::cin >> price;
			std::cout << std::endl;

			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "价格不合法请重新输入：" << std::endl;
			}
			else {
				// 检查价格是否合法（这里假设价格必须大于等于0）
				if (price < 0) {
					std::cout << "价格不合法请重新输入：" << std::endl;
				}
				else {
					break;
				}
			}
		}


		size_t date;
		cout << "请输入日期: ";
		cin >> date;
		cout << endl;

		Book new_book = { book, cate, intro, price, date };
		lt.push_back(new_book);
	}

	void del_book() {
		int flag = 0;
		cout << "请输入你需要删除的书名称：";
		string del_name;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, del_name);
		cout << endl;

		list<Book>::iterator it = lt.begin();
		while (it != lt.end()) {
			if (it->_name == del_name) {
				lt.erase(it);
				flag = 1;

				cout << "删除成功！！！" << endl;
				break;
			}
			it++;
		}

		if (flag == 0) cout << "没有找到你要删除的图书。" << endl;
	}

	void modify_book() {
		int flag = 0;
		string query_name;
		cout << "请输入你需要修改的书名称：";
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

		if (flag == 0) cout << "没有找到你要的图书。" << endl;
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
		cout << "书名：" << book._name << endl;
		cout << "类别：" << book._cate << endl;
		cout << "简介：" << book._intro << endl;
		cout << "价格：" << book._price << endl;
		cout << "购买日期：" << book._date << endl;

		return output;
	}

	bool Book_query() {
		int flag = 0;
		string query_name;
		cout << "请输入你需要查询的书名称：";
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

		if(flag == 0) cout << "没有找到你要的图书。" << endl;
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