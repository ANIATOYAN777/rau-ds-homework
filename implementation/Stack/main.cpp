#include "Stack.h"
#include <cassert>
#include <iostream>

template <typename T>
class Stack {
private:
    T* _data;
    int _capacity;
    int _size;

    void expand()
    {
        int new_capacity = _capacity * 2;

        T* new_data = new T[new_capacity];

        for (int i = 0; i < _size; i++)
        {
            new_data[i] = _data[i];
        }
        delete[] _data;

        _data = new_data;
        _capacity = new_capacity;
    }

public:
    /// 1. Конструктор по умолчанию
    Stack()
    {
        _capacity = 5;
        _size = 0;
        _data = new T[_capacity];
    }

    /// 2. Деструктор
    ~Stack()
    {
        delete[] _data;
    }

    /// 3. Конструктор копирования
    Stack(const Stack& other)
    {
        _capacity = other._capacity;
        _size = other._size;
        _data = new T[_capacity];;
        for (int i = 0; i < other._size; i++)
        {
            _data[i] = other._data[i];
        }
    }

    /// 4. Оператор присваивания
    Stack& operator=(const Stack& other)
    {
        if (this!=&other)
        {
            delete[] _data;

            _capacity = other._capacity;
            _size = other._size;

            _data = new T[_capacity];

            for (int i = 0; i < other._size; i++)
            {
                _data[i] = other._data[i];
            }
        }
        return *this;
    }

    /// 5. push(const T& x) - добавить в стек
    void push(const T& x)
    {
        if (_size == _capacity)
        {
            expand();
        }

        _data[_size] = x;
        _size++;
    }

    /// 6. pop() - удалить с вершины
    void pop()
    {
        if (_size > 0)
        {
            _size--;
        }
    }

    /// 7. top() - вершина стека
    T& top()
    {
        return _data[_size-1];
    }
    const T& top() const
    {
        assert(_size > 0);
        return _data[_size-1];
    }

    /// 8. size() - количество элементов
    int size() const
    {
        assert(_size > 0);
        return _size;
    }

    /// 9. capacity() - вместимость
    int capacity() const
    {
        return _capacity;
    }

    /// 10. is_empty() - пуст ли
    bool is_empty() const
    {
        return _size == 0;
    }

    /// 11. clear() - очистить
    void clear()
    {
        _size = 0;
    }

    /// 12. peek() - посмотреть вершину без удаления
    T& peek()
    {
        assert(_size > 0);
        return _data[_size-1];
    }
    const T& peek() const
    {
        assert(_size > 0);
        return _data[_size-1];
    }
};

void test_push() {
    Stack<int> s;

    s.push(5);
    assert(s.size() == 1);
    assert(s.top() == 5);

    s.push(10);
    s.push(15);
    assert(s.size() == 3);
    assert(s.top() == 15);

    std::cout << "test_push passed" << std::endl;
}

// void test_pop() { ... }
void test_pop()
{
    Stack<int> s;

    s.push(5);
    s.push(5);

    s.pop();

    assert(s.size() == 1);
    assert(s.top() == 5);

    std::cout << "test_pop passed" << std::endl;
}

// void test_top() { ... }
void test_top()
{
    Stack<int> s;

    s.push(5);

    assert(s.top() == 5);

    std::cout << "test_top passed" << std::endl;
}

void test_size()
{
    Stack<int> s;

    assert(s.size() == 0);

    s.push(5);
    assert(s.size() == 1);

    s.pop();
    assert(s.size() == 0);

    std::cout << "test_size passed" << std::endl;
}

void test_capacity()
{
    Stack<int> s;

    assert(s.capacity() == 5);

    s.push(5);

    assert(s.capacity() == 5);

    std::cout << "test_capacity passed" << std::endl;
}

void test_is_empty()
{
    Stack<int> s;

    assert(s.is_empty() == true);

    s.push(5);

    assert(s.is_empty() == false);

    s.pop();

    assert(s.is_empty() == true);

    std::cout << "test_is_empty passed" << std::endl;
}

void test_clear()
{
    Stack<int> s;

    s.push(5);

    s.clear();

    assert(s.size() == 0);
    assert(s.is_empty() == true);

    std::cout << "test_clear passed" << std::endl;
}

void test_peek()
{
    Stack<int> s;

    s.push(5);
    s.push(10);

    assert(s.peek() == 10);
    assert(s.size() == 2);

    s.pop();

    assert(s.peek() == 5);
    assert(s.size() == 1);

    std::cout << "test_peek passed" << std::endl;
}

int main() {
    std::cout << "Running Stack tests" << std::endl;

    test_push();
    test_pop();
    test_top();
    test_size();
    test_capacity();
    test_is_empty();
    test_clear();
    test_peek();

    std::cout << "All tests passed" << std::endl;
    return 0;
}

