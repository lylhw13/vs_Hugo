---
title: "Stl_map"
date: 2020-06-22T23:30:10+08:00
draft: true
---

# map遍历删除元素

如下进行map遍历删除的适合`theMap.erase(iter1)`会直接造成iter1失效。
```c++
map<string,int> theMap;
for(auto iter1 = theMap.begin(); iter1 != theMap.end(); ++iter1)
{
	if(iter1->second == xxx)
	{
		theMap.erase(iter1);
	}
} 
```

解决办法是使用后置++。
```c++
for(auto iter1 = theMap.begin(); iter1 != theMap.end(); )
{
	if(iter1->second == xxx)
	{
		theMap.erase(iter1++);
	}
	else
	{
		++iter1;
	}
}
```

```c++
//前置加加
UPInt& UPInt::operator++(){
    *this += 1;
    return *this;
}

//后置加加
const UPInt UPInt::operator++(int){
    UPInt oldvalue = *this;
    ++(*this);
    return oldvalue;
}
```

