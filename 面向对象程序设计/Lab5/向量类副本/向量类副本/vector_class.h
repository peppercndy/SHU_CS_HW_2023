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
	// ���캯��
	Vector() = default;
	Vector(size_t size, const T& value = T());
	void print() const;

	// �������캯��
	Vector(const Vector<T>& other);
	// �ƶ����캯��
	Vector(Vector<T>&& other) noexcept;
	// ��������
	~Vector() = default;

	// ��ֵ�����
	Vector<T>& operator=(const Vector<T>& other);
	Vector<T>& operator=(Vector<T>&& other) noexcept;

	// ��Ա����
	size_t size() const;
	void resize(size_t newSize, const T& value = T());

	// ���������
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

	// �쳣������
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


// ���캯��
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


// �������캯��
template <typename T>
Vector<T>::Vector(const Vector<T>& other) : data(other.data) {}

// �ƶ����캯��
template <typename T>
Vector<T>::Vector(Vector<T>&& other) noexcept : data(std::move(other.data)) {}

// ��ֵ�����
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

// ��Ա����
template <typename T>
size_t Vector<T>::size() const {
	return data.size();
}

template <typename T>
void Vector<T>::resize(size_t newSize, const T& value) {
	data.resize(newSize, value);
}

// ���������
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
	cout << "0���˳�����" << endl;
	cout << "1�����Գ�ʼ��" << endl;
	cout << "2�����Կ������ƶ�" << endl;
	cout << "3�����Ը�ֵ" << endl;
	cout << "4����������" << endl;
	cout << "5��������������" << endl;
	cout << "6�������쳣����" << endl;
	cout << endl;
}
void exitsystem()
{
	cout << "�˳�����" << endl;
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
	cout << "�����������ȣ�" << endl;
	cin >> a;
	Vector<T> vec(a, value);
	vec.print();
}

void testVectorInitialization() {
	string input;
	cout << "�����������ݣ�" << endl;
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
	cout << "���Կ������ƶ�:\n" << endl;
	int a, b;
	cout << "�����������ݣ�" << endl;
	cin >> b;
	cout << "�����������ȣ�" << endl;
	cin >> a;
	Vector<int> vec1(a, b);
	Vector<int> vec2(vec1);
	Vector<int> vec3(move(vec1));
	cout << "��������:" << "vec2:" << vec2 << "\n" << "�ƶ�����:" << "vec3:" << vec3 << "\n" << endl;
}
void testAssignment()
{
	cout << "���Ը�ֵ:\n" << endl;
	int a, b;
	cout << "�����������ݣ�" << endl;
	cin >> b;
	cout << "�����������ȣ�" << endl;
	cin >> a;
	Vector<int> vec1(a, b);
	Vector<int> vec2;
	vec2 = vec1;
	Vector<int> vec3;
	vec3 = move(vec1);
	cout << "������ֵ:" << "vec2 = vec1=" << vec2 << "\n" << "�ƶ���ֵ:" << "vec3 = move(vec1)=" << vec3 << "\n" << endl;
}
void testIndexing()
{
	cout << "��������:\n" << endl;
	int a, b;
	cout << "�����������ݣ�" << endl;
	cin >> b;
	cout << "�����������ȣ�" << endl;
	cin >> a;
	Vector<int> vec1(a, b);
	vec1.print();
	vec1[0] = 5;
	cout << "����:\n" << "vec1[0] = " << vec1[0] << "\n" << endl;
}
void testArithmeticOperations()
{
	cout << "������������:\n" << endl;
	int a, b, c;
	cout << "����vec1���ݣ�" << endl;
	cin >> b;
	cout << "����vec2���ݣ�" << endl;
	cin >> c;
	cout << "�����������ȣ�" << endl;
	cin >> a;
	Vector<int> vec1(a, b);
	Vector<int> vec2(a, c);
	Vector<int>vec3 = vec2 + vec1;
	vec1 += vec2;
	cout << "vec1+vec2:" << vec3 << "\n" << "vec1+=vec2:" << vec1 << "\n" << endl;
}
void testExceptions()
{
	cout << "�����쳣����:\n" << endl;
	int a, b;
	cout << "�����������ݣ�" << endl;
	cin >> b;
	cout << "�����������ȣ�" << endl;
	cin >> a;
	Vector<int>vec(a, b);
	int c;
	cout << "�����ȡ��λ�ã�" << endl;
	cin >> c;
	try {
		vec[c] = 5;
	}
	catch (const Vector<int>::OutOfBoundsException&) {
		cout << "����Խ������쳣\n" << endl;
	}
	int x, y, m, n;
	cout << "����vec1���ݣ�" << endl;
	cin >> y;
	cout << "����vec1���ȣ�" << endl;
	cin >> x;
	cout << "����vec2���ݣ�" << endl;
	cin >> n;
	cout << "����vec2���ȣ�" << endl;
	cin >> m;
	Vector<int> vec1(x, y);
	Vector<int> vec2(m, n);
	try {
		vec1 + vec2;
	}
	catch (const Vector<int>::SizeMismatchException&) {
		cout << "���ִ�С��ƥ���쳣\n" << endl;
	}
	cout << "\n" << endl;
}
