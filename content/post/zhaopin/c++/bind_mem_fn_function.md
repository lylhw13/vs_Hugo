
## std::bind
The function template bind generates a forwarding call wrapper for f. Calling this wrapper is equivalent to invoking f with some of its arguments bound to args.

## std::mem_fn
Function template std::mem_fn generates wrapper objects for pointers to members, which can store, copy, and invoke a pointer to member. Both references and pointers (including smart pointers) to an object can be used when invoking a std::mem_fn.

## std::function
Class template std::function is a general-purpose polymorphic function wrapper. Instances of std::function can store, copy, and invoke any CopyConstructible Callable target -- functions, lambda expressions, bind expressions, or other function objects, as well as pointers to member functions and pointers to data members.

The stored callable object is called the target of std::function. If a std::function contains no target, it is called empty. Invoking the target of an empty std::function results in std::bad_function_call exception being thrown.

std::function satisfies the requirements of CopyConstructible and CopyAssignable.


p779
f = bind(g,args)    f(x) means g(x, args) where args can be one or more arguments
f = mem_fn(mf)      f(p, args) means p->mf(args).
function<F> f(g)    f(args) means g(args). F is the type of g.