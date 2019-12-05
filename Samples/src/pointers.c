#include "pointers.h"
struct point
{
	int x;
	int y;

} testing;
int showFunctions()
{
	/*
	Passing fuctions as pointers
	functionSwitch(true);
	functionSwitch(false);
	*/

	/* manipulating structs */
	struct point myPoint = { 2, 4 };
	printf("myPoint\nx: %d\ty: %d\n", myPoint.x, myPoint.y);
	testing.x = 3, testing.y = 5;
	printf("testing\nx: %d\ty: %d\n", testing.x, testing.y);
	struct point *holding = &myPoint;
	printf("mpPoint by ref\nx: %d\ty: %d\n", holding->x, (*holding).y); /* showing two different version of access */
	holding = &testing;
	printf("testing by ref\nx: %d\ty: %d\n", holding->x, (*holding).y); /* showing two different version of access */
	testing.x = 10;
	printf("testing by ref after changing x value\nx: %d\ty: %d\n", holding->x, (*holding).y); /* showing two different version of access */

	return 1;
}
void functionSwitch(bool test)
{
	/* passing the funciton as a pointer */
	someonesHello((int (*) ()) (test ? myHello : stevesHello));
	/* calling the fucntion directly */
	test ? myHello() : stevesHello();
}
void someonesHello(int (*comp)())
{
	(*comp)();
}
int myHello()
{
	printf("My Hello\n");
	return 1;

}
int stevesHello()
{
	printf("Steve's Hello\n");
	return 1;
}