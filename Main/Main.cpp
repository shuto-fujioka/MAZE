#include "Texture_Lib.h"
#include "GameScene.h"
#include "proto.h"
#include "DirectInput_Lib.h"
#include "DirectX_Lib.h"


/*------------------------あるものとする----------------------------------------*/
#define TITLE  TEXT("MAZE")
#define DISPLAY_WIDTH 1920
#define DISPLAY_HIGHT 1080
/*------------------------------------------------------------------------------*/

//Directx関係----------------------------
LPDIRECT3DTEXTURE9	  g_pTexture[TEXMAX];	        //	画像の情報を入れておく為のポインタ配列
IDirect3DDevice9*	  g_pD3Device;		            //	Direct3Dのデバイス
D3DPRESENT_PARAMETERS  g_D3dPresentParameters;		//	パラメータ
D3DDISPLAYMODE		  g_D3DdisplayMode;
IDirect3D9*			  g_pDirect3D;		            //	Direct3Dのインターフェイス
//---------------------------------------


//メッセージ処理
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)

	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wp, lp);
}


//メインルーチン
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	WNDCLASS Wndclass;
	HWND hWnd;

	//Windows情報の設定
	Wndclass.style = CS_HREDRAW | CS_VREDRAW;
	Wndclass.lpfnWndProc = WndProc;
	Wndclass.cbClsExtra = Wndclass.cbWndExtra = 0;
	Wndclass.hInstance = hInstance;
	Wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	Wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	Wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	Wndclass.lpszMenuName = NULL;
	Wndclass.lpszClassName = TITLE;	//クラス名
									//Windowの登録
	RegisterClass(&Wndclass);
	//Windowの生成
	hWnd = CreateWindow(
		TITLE,								//ウィンドウのクラス名
		TITLE, 							//ウィンドウのタイトル
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,	//ウィンドウスタイル
		CW_USEDEFAULT,						// ウィンドウの横方向の位置x

		CW_USEDEFAULT,						// ウィンドウの縦方向の位置y
		DISPLAY_WIDTH,							// Width（幅）
		DISPLAY_HIGHT,							// Height（高さ）
		NULL,
		NULL,
		hInstance,							// アプリケーションインスタンスのハンドル
		NULL
	);
	if (!hWnd) return 0;

	//DirectX オブジェクトの生成
	g_pDirect3D = Direct3DCreate9(
		D3D_SDK_VERSION);

	//Display Mode の設定
	g_pDirect3D->GetAdapterDisplayMode(
		D3DADAPTER_DEFAULT,
		&g_D3DdisplayMode);

	ZeroMemory(&g_D3dPresentParameters,
		sizeof(D3DPRESENT_PARAMETERS));
	g_D3dPresentParameters.BackBufferFormat = g_D3DdisplayMode.Format;
	g_D3dPresentParameters.BackBufferCount = 2;
	g_D3dPresentParameters.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_D3dPresentParameters.Windowed = TRUE;

	//デバイスを作る
	g_pDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&g_D3dPresentParameters, &g_pD3Device);

	//描画設定
	g_pD3Device->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	g_pD3Device->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);  //SRCの設定
	g_pD3Device->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	g_pD3Device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);

	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3Device->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"kari.jpg",
		&g_pTexture[BACKGROUND_TEX]);
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"stage1.png",
		&g_pTexture[STAGE_TEX]);
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"coin.jpg",
		&g_pTexture[COIN_TEX]);
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"door.png",
		&g_pTexture[DOA_TEX]);
	D3DXCreateTextureFromFile(
		g_pD3Device,
		"door.png",
		&g_pTexture[DOA2_TEX]);

	D3DXCreateTextureFromFile(
		g_pD3Device,
		"anime.png",
		&g_pTexture[PLAYER_TEX]);

	MapLoad("stage.csv");

	DWORD SyncOld = timeGetTime();	//	システム時間を取得
	DWORD SyncNow;

	timeBeginPeriod(1);
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		Sleep(1);
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			SyncNow = timeGetTime();
			if (SyncNow - SyncOld >= 1000 / 60) //	1秒間に60回この中に入るはず
			{
				KeyControl();
				StageControl();
				PlayerControl();
				Render();
				SyncOld = SyncNow;
			}
		}
	}
	timeEndPeriod(1);

	return (int)msg.wParam;
}

