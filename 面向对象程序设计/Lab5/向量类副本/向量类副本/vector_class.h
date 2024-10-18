#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <type_traits>
using namespace std;

template <typename T>
class Vector {
private:
	std::vector<T> data;

public:
	// 构造函数
	Vector() = default;
	Vector(size_t size, const T& value = T());
	void print() const;

	// 拷贝构造函数
	Vector(const Vector<T>& other);
	// 移动构造函数
	Vector(Vector<T>&& other) noexcept;
	// 析构函数
	~Vector() = default;

	// 赋值运算符
	Vector<T>& operator=(const Vector<T>& other);
	Vector<T>& operator=(Vector<T>&& other) noexcept;

	// 成员函数
	size_t size() const;
	void resize(size_t newSize, const T& value = T());

	// 重载运算符
	T& operator[](size_t index);
	const T& operator[](size_t index) const;
	Vector<T> operator+(const Vector<T>& other) const;
	Vector<T>& operator+=(const Vector<T>& other);

	friend std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
		for (const auto& elem : vec.data) {
			os << elem << " ";
		}
		return os;
	}

	// 异常处理类
	class SizeMismatchException {};
	class OutOfBoundsException {};
};

void initializeVector(const string& input);
template <typename T>
void testVectorInitialization();
void testCopyAndMove();
void testAssignment();
void testIndexing();
void testArithmeticOperations();
void testExceptions();
void exitsystem();
void show();


// 构造函数
template <typename T>
Vector<T>::Vector(size_t size, const T& value) : data(size, value) {}

template <typename T>
void Vector<T>::print() const {
	cout << "vec:" << endl;
	for (const auto& elem : data) {
		cout << elem << " ";
	}
	cout << endl;
}


// 拷贝构造函数
template <typename T>
Vector<T>::Vector(const Vector<T>& other) : data(other.data) {}

// 移动构造函数
template <typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept : data(std::move(other.data)) {}

// 赋值运算符
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) {
	if (this != &other) {
		data = other.data;
	}
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) noexcept {
	if (this != &other) {
		data = std::move(other.data);
	}
	return *this;
}

// 成员函数
template <typename T>
size_t Vector<T>::size() const {
	return data.size();
}

template <typename T>
void Vector<T>::resize(size_t newSize, const T& value) {
	data.resize(newSize, value);
}

// 重载运算符
template <typename T>
T& Vector<T>::operator[](size_t index) {
	if (index >= data.size()) throw OutOfBoundsException();
	return data[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
	if (index >= data.size()) throw OutOfBoundsException();
	return data[index];
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other) const {
	if (data.size() != other.data.size()) throw SizeMismatchException();
	Vector<T> result(data.size());
	for (size_t i = 0; i < data.size(); ++i) {
		result[i] = data[i] + other[i];
	}
	return result;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector<T>& other) {
	if (data.size() != other.data.size()) throw SizeMismatchException();
	for (size_t i = 0; i < data.size(); ++i) {
		data[i] += other[i];
	}
	return *this;
}

void show()
{
	cout << "0、退出测试" << endl;
	cout << "1、测试初始化" << endl;
	cout << "2、测试拷贝和移动" << endl;
	cout << "3、测试赋值" << endl;
	cout << "4、测试索引" << endl;
	cout << "5、测试算术操作" << endl;
	cout << "6、测试异常处理" << endl;
	cout << endl;
}
void exitsystem()
{
	cout << "退出测试" << endl;
	system("pause");
	exit(0);
}
template <typename T>
void initializeVector(const string& input) {
	T value;
	if constexpr (is_same_v<T, string>) {
		value = input;
	}
	else {
		istringstream(input) >> value;
	}
	int a;
	cout << "输入向量长度：" << endl;
	cin >> a;
	Vector<T> vec(a, value);
	vec.print();
}

void testVectorInitialization() {
	string input;
	cout << "输入向量内容：" << endl;
	cin >> input;

	if (input.find('.') != string::npos) {
		initializeVector<double>(input);
	}
	else {
		try {
			(void)stoi(input);
			initializeVector<int>(input);
		}
		catch (const invalid_argument&) {
			if (input.length() == 1) {
				initializeVector<char>(input);
			}
			else {
				initializeVector<string>(input);
			}
		}
	}
}
void testCopyAndMove()
{
	cout << "测试拷贝和移动:\n" << endl;
	int a, b;
	cout << "输入向量内容：" << endl;
	cin >> b;
	cout << "输入向量长度：" << endl;
	cin >> a;
	Vector<int> vec1(a, b);
	Vector<int> vec2(vec1);
	Vector<int> vec3(move(vec1));
	cout << "拷贝构造:" << "vec2:" << vec2 << "\n" << "移动构造:" << "vec3:" << vec3 << "\n" << endl;
}
void testAssignment()
{
	cout << "测试赋值:\n" << endl;
	int a, b;
	cout << "输入向量内容：" << endl;
	cin >> b;
	cout << "输入向量长度：" << endl;
	cin >> a;
	Vector<int> vec1(a, b);
	Vector<int> vec2;
	vec2 = vec1;
	Vector<int> vec3;
	vec3 = move(vec1);
	cout << "拷贝赋值:" << "vec2 = vec1=" << vec2 << "\n" << "移动赋值:" << "vec3 = move(vec1)=" << vec3 << "\n" << endl;
}
void testIndexing()
{
	cout << "测试索引:\n" << endl;
	int a, b;
	cout << "输入向量内容：" << endl;
	cin >> b;
	cout << "输入向量长度：" << endl;
	cin >> a;
	Vector<int> vec1(a, b);
	vec1.print();
	vec1[0] = 5;
	cout << "索引:\n" << "vec1[0] = " << vec1[0] << "\n" << endl;
}
void testArithmeticOperations()
{
	cout << "测试算术操作:\n" << endl;
	int a, b, c;
	cout << "输入vec1内容：" << endl;
	cin >> b;
	cout << "输入vec2内容：" << endl;
	cin >> c;
	cout << "输入向量长度：" << endl;
	cin >> a;
	Vector<int> vec1(a, b);
	Vector<int> vec2(a, c);
	Vector<int>vec3 = vec2 + vec1;
	vec1 += vec2;
	cout << "vec1+vec2:" << vec3 << "\n" << "vec1+=vec2:" << vec1 << "\n" << endl;
}
void testExceptions()
{
	cout << "测试异常处理:\n" << endl;
	int a, b;
	cout << "输入向量内容：" << endl;
	cin >> b;
	cout << "输入向量长度：" << endl;
	cin >> a;
	Vector<int>vec(a, b);
	int c;
	cout << "输入读取的位置：" << endl;
	cin >> c;
	try {
		vec[c] = 5;
	}
	catch (const Vector<int>::OutOfBoundsException&) {
		cout << "发现越界访问异常\n" << endl;
	}
	int x, y, m, n;
	cout << "输入vec1内容：" << endl;
	cin >> y;
	cout << "输入vec1长度：" << endl;
	cin >> x;
	cout << "输入vec2内容：" << endl;
	cin >> n;
	cout << "输入vec2长度：" << endl;
	cin >> m;
	Vector<int> vec1(x, y);
	Vector<int> vec2(m, n);
	try {
		vec1 + vec2;
	}
	catch (const Vector<int>::SizeMismatchException&) {
		cout << "发现大小不匹配异常\n" << endl;
	}
	cout << "\n" << endl;
}
