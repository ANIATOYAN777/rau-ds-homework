#ifndef STACK_H
#define STACK_H

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
        return _data[_size-1];
    }

    /// 8. size() - количество элементов
    int size() const
    {
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
        return _data[_size-1];
    }
    const T& peek() const
    {
        return _data[_size-1];
    }
};

#endif // STACK_H
