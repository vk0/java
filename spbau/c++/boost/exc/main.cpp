#include <iostream>

struct BasePtr
{
	BasePtr() { count = 1; }
	virtual ~BasePtr() {}
	void ref() { ++count; }
	void unref() { if ( !(--count) ) delete this; }

	int count;	
};

template <typename T>
class BasePtr_impl : public BasePtr
{
public:
	BasePtr_impl(T * ptr) : ptr(ptr) {}
	virtual ~BasePtr_impl() { delete ptr; }

private:
	T * ptr;
};

template <typename T>
class shared_ptr
{
public:
	template <typename C>
	shared_ptr(C * rptr)
	: ptr(new BasePtr_impl<C>(rptr))
	, data(rptr)
		{}

	shared_ptr(shared_ptr<T> const & sp)
	: ptr( sp.get_base() )
	, data( sp.get() )
	{
		ptr->ref();
	}

	template <typename P>
	shared_ptr(P const & sp)
	: ptr( sp.get_base() )
	, data( sp.get() )
	{
		ptr->ref();
	}

	template <typename P>
	shared_ptr<T> & operator=(P sp)
	{
		release();
		ptr = sp.get_base();
		data = sp.get();
		ptr->ref();

		return *this;
	}

	T * operator->()
	{
		return data;
	}

	T & operator*()
	{
		return *data;
	}

	virtual ~shared_ptr()
	{
		release();
	}

	void release()
	{
		if ( ptr ) ptr->unref();
		ptr = 0;
		data = 0;
	}

	BasePtr * get_base() const { return ptr; }
	T * get() const { return data; }

	shared_ptr(BasePtr * bptr, T * d)
	: ptr(bptr)
	, data(d)
	{
		ptr->ref();
	}

private:
	BasePtr * ptr;
	T * data;

	template <typename S>
	friend shared_ptr<S> s_p_static_cast(shared_ptr<T> sp)
	{
		return shared_ptr<S>( sp.get_base(), static_cast<S *>( sp.get() ) );
	}
};

class B
{
public:
	virtual void what() const { std::cout << "class B" << std::endl; }
};

class C : public B
{
public:
	virtual void what() const { std::cout << "class C" << std::endl; }
};

class D : public B
{
public:
	virtual void what() const { std::cout << "class D" << std::endl; }
};

int main(int argc, char **argv)
{
	shared_ptr<int> ip1 = new int(10);
	shared_ptr<int> ip2 = ip1;

	std::cout << *ip1 << " " << *ip2 << std::endl;

	shared_ptr<D> dp = new D();
	shared_ptr<C> cp = new C();

	shared_ptr<B> bp = dp;
	bp->what();

	bp = cp;
	bp->what();

	shared_ptr<C> cp2 = s_p_static_cast<C>(bp);
	cp2->what();

	return 0;
}
