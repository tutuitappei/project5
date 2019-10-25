#include <Dxlib.h>
#include<Scene\SceneMag.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	/*SceneMag sceneMag;
	sceneMag.Run();*/

	SceneMag::GetInstance().Run();

	return 0;
}