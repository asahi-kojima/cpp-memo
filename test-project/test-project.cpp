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

	std::cout << "===========================\n";
	B b{};
	b.f();
	b.f_overload();
	b.vf();
	b.wrap();
	b.wrap_overload();
	b.wrap_virtual();
	b.wrap_virtual_overload();


	std::cout << "===========================\n";
	D d{};
	d.f();
	d.f_overload();
	d.vf();
	d.wrap();
	d.wrap_overload();
	d.wrap_virtual();
	d.wrap_virtual_overload();


	std::cout << "===========================\n";
	B* pb = new D{};
	pb->f();
	pb->f_overload();
	pb->vf();
	pb->wrap();
	pb->wrap_overload();
	pb->wrap_virtual();
	pb->wrap_virtual_overload();


	std::cout << "===========================\n";
	B& refB = b;
	refB.f();
	refB.f_overload();
	refB.vf();
	refB.wrap();
	refB.wrap_overload();
	refB.wrap_virtual();
	refB.wrap_virtual_overload();

	std::cout << "===========================\n"; 
	B& refD = *pb;
	refD.f();
	refD.f_overload();
	refD.vf();
	refD.wrap();
	refD.wrap_overload();
	refD.wrap_virtual();
	refD.wrap_virtual_overload();
}
