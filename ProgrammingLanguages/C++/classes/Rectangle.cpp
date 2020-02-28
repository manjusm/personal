#include <iostream>

class rectangle {
    public:
	rectangle()
	{
		m_height = 0;
		m_width = 0;
	}

	rectangle(int height, int width)
	{
		m_height = height;
		m_width = width;
	}

	int m_resize(int newHeight, int newWidth)
	{
		m_height = newHeight;
		m_width = newWidth;
	}

	int m_getArea() const;
	int m_getWidth() 
	{ 
		return m_width;
	}
	int m_getHeight() 
	{ 
		return m_height;
	}
    private:	
    	int m_height;
	int m_width;
};

int rectangle::m_getArea() const
{
	return m_width * m_height;
}

int main()
{
	rectangle small{3, 4};
	printf("area : %d width : %d\n", small.m_getArea(), small.m_getWidth());
	small.m_resize(5, 4);
	printf("area : %d width : %d\n", small.m_getArea(), small.m_getWidth());
	return 0;
}
