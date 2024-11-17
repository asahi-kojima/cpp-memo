#include <iostream>


class B
{
public:
	void f() { std::cout << "B::f\n"; }
	void f_overload() { std::cout << "B::f\n"; }
	virtual void vf() { std::cout << "B::vf\n"; }

	void wrap()
	{
		f();
		f_overload();
		vf();
	}

	void wrap_overload()
	{
		f();
		f_overload();
		vf();
	}

	virtual void wrap_virtual()
	{
		f();
		f_overload();
		vf();
	}

	virtual void wrap_virtual_overload()
	{
		f();
		f_overload();
		vf();
	}

};

class D : public B
{
public:
	void f_overload() { std::cout << "D::f\n"; }
	virtual void vf() { std::cout << "D::vf\n"; }

	void wrap_overload()
	{
		f();
		f_overload();
		vf();
	}

	virtual void wrap_virtual_overload()
	{
		f();
		f_overload();
		vf();
	}
};


class C
{
public:
	void f()
	{
		std::cout << "C\n";
	}
};

void f() {}

int main()
{
	f();

	C c{};
	c.f();

	B b{};
	b.wrap();
	b.wrap_overload();
	b.wrap_virtual();
	b.wrap_virtual_overload();


	D d{};
	d.wrap();
	d.wrap_overload();
	d.wrap_virtual();
	d.wrap_virtual_overload();


	B* pb = new D{};
	pb->wrap();
	pb->wrap_overload();
	pb->wrap_virtual();
	pb->wrap_virtual_overload();
}
