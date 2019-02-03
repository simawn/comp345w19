#pragma once
#ifndef RES_H
namespace Resources{
	class Coal
	{
	public:
		Coal(int v);
		int getValue();
	private:
		int value;
	};
	class Uranium
	{
	public:
		Uranium(int v);
		int getValue();
	private:
		int value;
	};
	class Garbage
	{
	public:
		Garbage(int v);
		int getValue();
	private:
		int value;
	};
	class Gas
	{
	public:
		Gas(int v);
		int getValue();
	private:
		int value;
	};
}

#endif // !RES_H
