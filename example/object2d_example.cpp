#include <myle.h>

int main()
{
	MYLE::Init();

	{
		std::shared_ptr<MYLE::object2d> myObject = std::make_shared<MYLE::object2d>("Test1", "Description test");
		std::cout << myObject->to_string() << std::endl;
		std::cout << myObject->get_mPID() << std::endl;
	}
}