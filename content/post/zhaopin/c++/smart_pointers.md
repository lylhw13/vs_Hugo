---
title: "Smart_pointers"
date: 2020-09-25T21:16:34+08:00
draft: true
---

# unique_ptr
只能移动，不能复制
不再使用，保证析构

```c++
namespace std {
    template <typename T, typename D = default_delete<T>>
    class unique_ptr
    {
    public:
        explicit unique_ptr(pointer p) noexcept;
        ~unique_ptr() noexcept;    
	T& operator*() const;
    T* operator->() const noexcept;

	unique_ptr(const unique_ptr &) = delete;
    unique_ptr& operator=(const unique_ptr &) = delete;

	unique_ptr(unique_ptr &&) noexcept;
	unique_ptr& operator=(unique_ptr &&) noexcept;
	// ...
    private:
        pointer __ptr;
    };
}
```

- unique_ptr内部存储一个 raw pointer，当unique_ptr析构时，它的析构函数将会负责析构它持有的对象。
- unique_ptr提供了operator*()和operator->()成员函数，像 raw pointer 一样，我们可以使用*解引用unique_ptr，使用->来访问unique_ptr所持有对象的成员。
- unique_ptr并不提供 copy 操作，这是为了防止多个unique_ptr指向同一对象。
- 但unique_ptr提供了 move 操作，因此我们可以用std::move()来转移unique_ptr。

default_delete, used by unique_ptr for single objects