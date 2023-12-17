// human12-18の授業.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
/*
Version1

*/

#include <iostream>
/*
ファイル操作
STL
(1)list
(2)map
(3)vector
(4)テンプレート
(5)演算子のオーバーロード

*/
#include<fstream>
using namespace std;
int rei1() {

	char str[] = "text.txt";
	ofstream ofs;
	ofs.open(str);
	if (ofs) // オープン成功時
	{
		ofs << "ファイル書き込み";
		ofs.close();
	}
	return 0;

}
int rei2() {
	ifstream ifs;
	ifs.open("text.txt");
	if (!ifs) // オープン失敗時
		return -1; // エラー終了
	char str[64];
	ifs >> str;
	cout << str;
	ifs.close();
	return 0;

}
int rei3() {
	ofstream ofs;
	ofs.open("text.txt");
	if (ofs) // オープン成功時
	{
		ofs << "ファイル書き込み";
		ofs << 12;
		ofs.close();
	}
	return 0;



}
int rei4() {
	ofstream ofs;
	ofs.open("text.txt");
	if (ofs) // オープン成功時
	{
		ofs << 12 << " "<< 34 << " " << 56;
		ofs.close();
	}
	return 0;






}

int rei5() {
	ifstream ifs;
	ifs.open("text.txt");
	if (!ifs) // オープン失敗時
		return -1; // エラー終了
	int num, num2,num3;
	ifs >> num;
	ifs >> num2;
	ifs >> num3;

	cout << num << "/" << num2 << "/" <<num3;
	ifs.close();
	return 0;



}
#include<vector>
int rei6() {
	//標準入力から整数を５つ入力させ、std::vector に格納するプログラムを作成してください。
	constexpr auto element_count = 5;
	std::vector<int> v(element_count);

	for (int i = 0; i < element_count; ++i) {
		std::cout << "Please enter the integer.\n";
		std::cin >> v.at(i);
	}

	for (int e : v) {
		std::cout << e << "\n";
	}

	return 0;
}

void rei7() {

//	問題２のプログラムを改造して、各要素が奇数か偶数かに応じて、“odd”、“even” のいずれかを標準出力へ出力するようにしてください。
//
//		たとえば、{ 7, -2, 5, 2, 3 } という要素が入っているなら、odd、even、odd、even、odd を出力します。

	constexpr auto element_count = 5;
	std::vector<int> v(element_count);

	for (int i = 0; i < element_count; ++i) {
		std::cout << "Please enter the integer.\n";
		std::cin >> v.at(i);
	}

	for (int e : v) {
		if (e % 2 == 0) {
			std::cout << "even\n";
		}
		else {
			std::cout << "odd\n";
		}
	}
}/*
 map
 */
#include<map>
void rei8() {
	map<string, int> m;
	m["RED"] = 1;
	m["YELLO"] = 2;
	m["BLUE"] = 3;

	map<string, int> m1 = {
		{"RED",1},
		{"BLUE",2},
		{"YELLOW",3}
	
	};

	cout << "m=" <<m.size();
	cout << m1["RED"];
	/*
	* イテレーターを使い
	* first second
	*/
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		std::cout << "key = " << itr->first           // キーを表示
			<< ", val = " << itr->second << "\n";    // 値を表示
	}

	/*
	
	キー、値ともに int 型の連想配列 mp を宣言し、キー・値をランダムに生成し100個のペアを mp に追加しなさい。 その後、mp に格納されている要素を begin() から end() まで表示し、キーが昇順に並んでいることを確認しなさい。 hide
    std::map<int, int> mp;
    const int N = 100;
    for(int i = 0; i < N; ++i) {
        mp[rand()] = rand();
    }
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        std::cout << itr->first << ": " << itr->second << "\n";
    }
	
	
	
	*/



}

#include<list>
void rei9() {

	std::list<int> m{ 4, 6, 5 };//=がない
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		cout << "m=" << *itr << endl;
	}
	/*挿入*/
	m.push_front(987);     // 先頭に 987 を追加
	m.push_back(999);
	/*  987,4, 6, 5,999 */
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		cout << "m=" << *itr << endl;
	}

	auto itr = m.begin();
	++itr;
	++itr;               // 3番目の要素に移動
	m.erase(itr);       //  3番目の要素（9）を削除
	/*  987,4,  5,999 */
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		cout << "m=" << *itr << "  ";
	}
	cout << endl;

	/*
	
	
	*/
	/*  987,4,0 , 5,999 */
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		if (*itr == 5) {
			itr = m.insert(itr, 0);       // 5 の前に 0 を挿入、itr は 0 を指す
			++itr;                           // itr を 5 の位置に進める
		}
	}


	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		cout << "m=" << *itr << "  ";
	}
	cout << endl;



}
/*















*/
int main()
{
	rei9();
	




}

