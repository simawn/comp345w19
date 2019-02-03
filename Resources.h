#pragma once
#ifndef RES_H
class Resource
{
public:
	class Coal
	{
	public:
		Coal(int v);
	private:
		int value;
	};
	class Uranium
	{
	public:
		Uranium(int v);

	private:
		int value;
	};
	class Garbage
	{
	public:
		Garbage(int v);

	private:
		int value;
	};
	class Gas
	{
	public:
		Gas(int v);

	private:
		int value;
	};
};

#endif // !RES_H
