//########## ヘッダーファイル読み込み ##########
#include "DxLib.h"

//########## マクロ定義 ##########
#define GAME_WIDTH			608	//画面の横の大きさ
#define GAME_HEIGHT			480	//画面の縦の大きさ
#define GAME_COLOR			32	//画面のカラービット

#define GAME_WINDOW_BAR		0					//タイトルバーはデフォルトにする
#define GAME_WINDOW_NAME	"Two for One"		//ウィンドウのタイトル

//#define FONT_PATH_MAX      255//255文字まで
//
//#define FONT_PIX_PATH     TEXT(".\\FONT\\PixelMplus10-Bold.ttf")
//#define FONT_PIX_NAME     TEXT("PixelMplus10")
//
//#define FONT_INSTALL_ERR_TITLE    TEXT("フォントインストールエラー")
//#define FONT_CREATE_ERR_TITLE     TEXT("フォント作成エラー")

//キーボードの種類
#define KEY_CODE_KIND		256	//256種類

//パスの長さ
#define PATH_MAX			255	//255文字まで
#define NAME_MAX			255	//255文字まで

//エラーメッセージ
#define IMAGE_LOAD_ERR_TITLE	TEXT("画像読み込みエラー")
#define IMAGE_LOAD_ERR_END	    TEXT("画像読み込みエラー")

//画像のパス
#define IMAGE_player_A_PATH		    TEXT(".\\IMAGE\\player_A.png")	    //プレイヤーAの画像
#define IMAGE_player_B_PATH		    TEXT(".\\IMAGE\\player_B.png")	    //プレイヤーBの画像
#define IMAGE_TITLE_BK_PATH			TEXT(".\\IMAGE\\titleBK.png")		//タイトル背景の画像
#define IMAGE_TITLE_ROGO_PATH		TEXT(".\\IMAGE\\title_rogo.png")	//タイトルロゴの画像
#define IMAGE_TITLE_START_PATH		TEXT(".\\IMAGE\\title_button.png")	//タイトルスタートの画像

//マップの情報
#define GAME_MAP_TATE_MAX	15	//マップの縦の数
#define GAME_MAP_YOKO_MAX	19	//マップの横の数
#define GAME_MAP_KIND_MAX	1	//マップの種類の数
#define GAME_MAP_PATH			TEXT(".\\IMAGE\\MAP\\mapchip.png")		//マップの画像
#define MAP_DIV_WIDTH		32	//画像を分割する幅サイズ
#define MAP_DIV_HEIGHT		32	//画像を分割する高さサイズ
#define MAP_DIV_TATE		16	//画像を縦に分割する数
#define MAP_DIV_YOKO		2	//画像を横に分割する数
#define MAP_DIV_NUM	MAP_DIV_TATE * MAP_DIV_YOKO	//画像を分割する総数

//エラーメッセージ
#define START_ERR_TITLE		TEXT("スタート位置エラー")
#define START_ERR_CAPTION_A	TEXT("Aのスタート位置が決まっていません")
#define START_ERR_CAPTION_B	TEXT("Bのスタート位置が決まっていません")

#define GOAL_ERR_TITLE      TEXT("ゴール位置エラー")
#define GOAL_ERR_CAPTION_A  TEXT("Aのゴール位置が決まっていません")
#define GOAL_ERR_CAPTION_B  TEXT("Bのゴール位置が決まっていません")

//ロゴ画像動作用
#define IMAGE_TITLE_ROGO_ROTA		0.01		//拡大率
#define IMAGE_TITLE_ROGO_ROTA_MAX	1.0			//拡大率MAX
#define IMAGE_TITLE_ROGO_X_SPEED	1			//X移動速度
#define IMAGE_TITLE_START_CNT		1			//点滅カウンタ
#define IMAGE_TITLE_START_CNT_MAX	80			//点滅カウンタMAX

//エンドコンプ画面用
#define IMAGE_END_COMP_PATH        TEXT(".\\IMAGE\\mission_complete.png") //エンドコンプロゴ画像
#define IMAGE_TITLE_END_PATH		TEXT(".\\IMAGE\\end_button.png")	//エンドボタンの画像
#define IMAGE_END_COMP_CNT         1       //点滅カウンタ
#define IMAGE_END_COMP_CNT_MAX     80      //点滅カウンタMAX(点滅の速さ)

//キャラ画像動作用
#define IMAGE_DIV_WIDTH    32
#define IMAGE_DIV_HEIGHT   32

#define IMAGE_DIV_TATE     2
#define IMAGE_DIV_YOKO     4

#define IMAGE_DIV_NUM      IMAGE_DIV_TATE * IMAGE_DIV_YOKO

//エラーメッセージ
#define MUSIC_LOAD_ERR_TITLE	   TEXT("音楽読み込みエラー")

//BGMパス指定
#define MUSIC_BGM_PATH              TEXT(".\\MUSIC\\play_BGM.mp3")                  //プレイ画面のBGM
#define MUSIC_BGM_TITLE_PATH		TEXT(".\\MUSIC\\title_BGM.mp3")	                //タイトルのBGM
#define MUSIC_BGM_COMP_PATH			TEXT(".\\MUSIC\\end_BGM.mp3")				    //コンプリートBGM
#define MUSIC_BGM_FAIL_PATH			TEXT(".\\MUSIC\\衛星の夜.mp3")					//フォールトBGM

//BGM音量
#define MUSIC_VOLUME             50   //BGMの音量（0~100）
//閉じるボタンを押したとき
#define MSG_CLOSE_TITLE			TEXT("終了メッセージ")
#define MSG_CLOSE_CAPTION		TEXT("ゲームを終了しますか？")

//デバッグモードのオンオフ（ON:オン　OFF:オフ）
#define DEBUG   TEXT("OFF")

//当たり判定の対象の識別
#define TRUE_k     1
#define TRUE_s1    6
#define TRUE_m1    7
#define TRUE_s2    8
#define TRUE_m2    9
#define TRUE_ag    3
#define TRUE_bg    5
#define TRUE_s3    10
#define TRUE_m3    11
#define TRUE_s4    12
#define TRUE_m4    13
#define TRUE_ki    14
#define TRUE_kl    15

//スイッチが押されたかどうかの識別（1:押された　0:押されてない）
int s1_check = 0;  //スイッチ1用
int s2_check = 0;  //スイッチ2用
int s3_check = 0;  //スイッチ3用
int s4_check = 0;  //スイッチ4用

//鍵をとっているかどうかの識別（1:取っている　0:取っていない）
int ki_check = 0;

//武器をとっているかどうかの識別（1:取っている　0:取っていない）
int brade_check = 0;
int spear_check = 0;
int cane_check = 0;

enum GAME_MAP_KIND
{
	n = -1,	//(NONE)未定
	k = 1,	 //壁
	t = 0,	 //通路
	as = 2,	 //プレイヤーAスタート
    ag = 3,	 //プレイヤーAゴール
	bs = 4,  //プレイヤーBスタート
	bg = 5,  //プレイヤーBゴール
	s1 = 6,  //スイッチ1
	m1 = 7,  //ギミック1
	s2 = 8,  //スイッチ2
	m2 = 9,  //ギミック2
	s3 = 10, //スイッチ3
	m3 = 11, //ギミック3
	s4 = 12, //スイッチ4
	m4 = 13, //ギミック4
	ki = 14, //鍵アイテム
	kl = 15, //鍵扉
	br = 16, //剣
	sp = 17, //槍
	ca = 18  //杖
};	//マップの種類

enum GAME_SCENE {
	GAME_SCENE_START,
	GAME_SCENE_PLAY,
	GAME_SCENE_END,
};	//ゲームのシーン

enum CHARA_SPEED {
	CHARA_SPEED_LOW = 1,
	CHARA_SPEED_MIDI = 2,
	CHARA_SPEED_HIGH = 3
};	//プレイヤーのスピード

//int型のPOINT構造体
typedef struct STRUCT_I_POINT
{
	int x = 0;	//座標を初期化
	int y = 0;	//座標を初期化
}iPOINT;

typedef struct STRUCT_IMAGE
{
	char path[PATH_MAX];		//パス
	int handle;					//ハンドル
	int x;				    //X位置
	int y;					//Y位置
	int width;					//幅
	int height;					//高さ
	BOOL IsDraw = FALSE;		//描画できるか
}IMAGE;	//画像構造体

typedef struct STRUCT_CHARA
{
	IMAGE image;				//IMAGE構造体
	int speed;					//速さ
	RECT coll;
	iPOINT collBeforePt;

}CHARA;	//プレイヤー構造体

typedef struct STRUCT_MAP_IMAGE
{
	char path[PATH_MAX];				//パス
	int handle[MAP_DIV_NUM];			//分割したマップの画像ハンドルを取得
	int kind[MAP_DIV_NUM];				//マップの種類
	int width;							//幅
	int height;							//高さ
}MAPCHIP;	//MAP_IMAGE構造体

typedef struct STRUCT_MAP
{
	GAME_MAP_KIND kind;			//マップの種類
	int x;						//X位置
	int y;						//Y位置
	int width;					//幅
	int height;					//高さ
}MAP;	//MAP構造体

typedef struct STRUCT_IMAGE_ROTA
{
	IMAGE image;		//IMAGE構造体
	double angle;		//回転率
	double angleMAX;	//回転率MAX
	double rate;		//拡大率
	double rateMAX;		//拡大率MAX
}IMAGE_ROTA;	//回転拡大する画像の構造体

typedef struct STRUCT_IMAGE_BLINK
{
	IMAGE image;		//IMAGE構造体
	int Cnt;			//点滅カウンタ
	int CntMAX;			//点滅する時間MAX
	BOOL IsDraw;		//描画できるか？
}IMAGE_BLINK;  //点滅する画像の構造体

typedef struct STRUCT_MUSIC
{
	char path[PATH_MAX];		//パス
	int handle;					//ハンドル
}MUSIC;//音楽構造体

//ゲーム関連
int GameScene;		//ゲームシーンを管理

IMAGE       ImageTitleBK;               //タイトル背景の画像
IMAGE_ROTA  ImageTitleROGO;             //タイトルロゴの画像
IMAGE_BLINK ImageTitleSTART;            //タイトルスタートの画像

IMAGE_BLINK ImageEndCOMP;              //エンドコンプの画像
IMAGE_BLINK ImageTitleEND;             //エンドボタンの画像

//音楽関連
MUSIC BGM;  //ゲームのBGM
MUSIC BGM_TITLE;	//タイトルのBGM
MUSIC BGM_COMP;		//コンプリートのBGM
MUSIC BGM_FAIL;		//フォールトのBGM

//画像関連
IMAGE ImageBack;
CHARA player_A;		//ゲームのキャラA
CHARA player_B;		//ゲームのキャラB

GAME_MAP_KIND mapData[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX]
{   //  0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0 ,1 ,2 ,3 ,4 ,5 ,6 ,7 ,8

		k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k,	//0

		k ,t ,k ,k ,k ,k ,k ,t ,s3,k ,s4,k ,t ,t ,t ,t ,t ,t ,k,	//1

		k ,t ,t ,t ,t ,t ,t ,t ,k ,k ,t ,kl,t ,k ,k ,k ,k ,t ,k,	//2

		k ,k ,k ,m2,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,t ,t ,k ,t ,k,	//3

		k ,t ,t ,t ,t ,t ,t ,t ,k ,k ,t ,k ,t ,t ,t ,t ,t ,t ,k,	//4

		k ,t ,k ,k ,k ,k ,k ,t ,k ,k ,t ,t ,t ,k ,k ,k ,k ,k ,k,	//5

		k ,t ,k ,t ,t ,t ,t ,t ,t ,k ,t ,k ,t ,m1,t ,t ,t ,k ,k,	//6

		k ,s1,k ,t ,k ,k ,k ,k ,k ,k ,t ,k ,k ,k ,k ,k ,t ,k ,k,	//7

		k ,k ,k ,t ,k ,k ,t ,t ,t ,k ,s2,k ,t ,t ,t ,k ,t ,k ,k,	//8

		k ,t ,t ,t ,t ,t ,t ,k ,t ,k ,k ,k ,ca,k ,t ,k ,t ,k ,k,	//9

		k ,k ,k ,k ,k ,k ,k ,k ,t ,k ,t ,m3,sp,k ,t ,k ,t ,k ,k,	//10

		k ,t ,t ,t ,t ,t ,t ,t ,t ,k ,t ,k ,br,k ,t ,t ,t ,t ,k,	//11

		k ,t ,k ,m4,k ,k ,k ,k ,k ,k ,t ,k ,t ,k ,k ,k ,k ,k ,k,	//12

		k ,as,k ,t ,t ,t ,t ,t ,ag,k ,bg,k ,ki,t ,t ,t ,t ,bs,k,	//13

		k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k ,k		//14
};	//ゲームのマップ

//ゲームマップの初期化
GAME_MAP_KIND mapDataInit[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//マップチップの画像を管理
MAPCHIP mapChip;

//マップの場所と表示する画像を管理
MAP map[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//スタートの位置(プレイヤーそれぞれの座標）
iPOINT startPt_A;
iPOINT startPt_B;

//マップの当たり判定
RECT mapColl[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];
//マップの当たり判定初期化用
RECT mapCollInit[GAME_MAP_TATE_MAX][GAME_MAP_YOKO_MAX];

//ゴールしたかの判定
RECT GoalRect_A = { -1,-1,-1,-1 };  //プレイヤーA用
RECT GoalRect_B = { -1,-1,-1,-1 };  //プレイヤーB用

//フォント用
//FONT FontPixel;

//########## プロトタイプ宣言 ##########
VOID MY_START(VOID);		//スタート画面
VOID MY_START_PROC(VOID);	//スタート画面の処理
VOID MY_START_DRAW(VOID);	//スタート画面の描画

VOID MY_PLAY_INIT(VOID);	//プレイ画面初期化
VOID MY_PLAY(VOID);			//プレイ画面
VOID MY_PLAY_PROC(VOID);	//プレイ画面の処理
VOID MY_PLAY_DRAW(VOID);	//プレイ画面の描画

VOID MY_END(VOID);			//エンド画面
VOID MY_END_PROC(VOID);		//エンド画面の処理
VOID MY_END_DRAW(VOID);		//エンド画面の描画

BOOL MY_LOAD_IMAGE(VOID);		//画像をまとめて読み込む関数
VOID MY_DELETE_IMAGE(VOID);		//画像をまとめて削除する関数

BOOL MY_LOAD_MUSIC(VOID);		//音楽をまとめて読み込む関数
VOID MY_DELETE_MUSIC(VOID);		//音楽をまとめて削除する関数

int MY_CHECK_MAP1_PLAYER_COLL(RECT);   //マップとプレイヤーの当たり判定をする関数
BOOL MY_CHECK_RECT_COLL(RECT, RECT);    //領域の当たり判定をする関数

//BOOL MY_FONT_INSTALL_ONCE(VOID);
//VOID MY_FONT_UNINSTALL_ONCE(VOID);
//BOOL MY_FONT_CREATE(VOID);
//VOID MY_FONT_DELETE(VOID);

//########## プログラムで最初に実行される関数 ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	SetOutApplicationLogValidFlag(FALSE);				//Log.txtを出力しない
	ChangeWindowMode(TRUE);								//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);	//指定の数値でウィンドウを表示する
	SetWindowStyleMode(GAME_WINDOW_BAR);				//タイトルバーはデフォルトにする
	SetMainWindowText(TEXT(GAME_WINDOW_NAME));			//ウィンドウのタイトルの文字
	SetAlwaysRunFlag(TRUE);								//非アクティブでも実行する
	SetWindowUserCloseEnableFlag(FALSE);				//閉じるボタンで、勝手にウィンドウが閉じないようにする

	if (DxLib_Init() == -1) { return -1; }	//ＤＸライブラリ初期化処理

	//フォントを一時的にインストール
	//if (MY_FONT_INSTALL_ONCE() == FALSE) { return -1; }

	//フォントハンドルを作成
	//if (MY_FONT_CREATE() == FALSE) { return -1; }

	//画像を読み込む
	if (MY_LOAD_IMAGE() == FALSE) { return -1; }

	//音楽を読み込む
	if (MY_LOAD_MUSIC() == FALSE) { return -1; }

	GameScene = GAME_SCENE_START;	//ゲームシーンはスタート画面から
	SetDrawScreen(DX_SCREEN_BACK);	//Draw系関数は裏画面に描画

	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//プレイヤーAのスタート位置を探す
			if (mapData[tate][yoko] == as)
			{
				//プレイヤーAのスタート位置を計算
				startPt_A.y = mapChip.height * tate;	//Y座標を取得
				startPt_A.x = mapChip.width * yoko;	//X座標を取得
				
			}

			//プレイヤーBのスタート位置を探す
			if (mapData[tate][yoko] == bs)
			{
				//プレイヤーBのスタート位置を計算
				startPt_B.x = mapChip.width * yoko;	//X座標を取得
				startPt_B.y = mapChip.height * tate;	//Y座標を取得
			}

			//プレイヤーAのゴール位置を探す
			if (mapData[tate][yoko] == ag) 
			{
				GoalRect_A.left = mapChip.width * yoko;
				GoalRect_A.top = mapChip.height * tate;
				GoalRect_A.right = mapChip.width * (yoko + 1);
				GoalRect_A.bottom = mapChip.height * (tate + 1);
			}

			//プレイヤーBのゴール位置を探す
			if (mapData[tate][yoko] == bg)
			{
				GoalRect_B.left = mapChip.width * yoko;
				GoalRect_B.top = mapChip.height * tate;
				GoalRect_B.right = mapChip.width * (yoko + 1);
				GoalRect_B.bottom = mapChip.height * (tate + 1);
			}

		}

		//スタートが決まっていれば、ループ終了
		if (startPt_A.x != 0 && startPt_A.y != 0 && startPt_B.x != 0 && startPt_B.y != 0) { break; }
	}

	//Aのスタートが決まっていなければ
	if (startPt_A.x == 0 && startPt_A.y == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_A, START_ERR_TITLE, MB_OK);	return -1;
	}
	//Bのスタートが決まっていなければ
	if (startPt_B.x == 0 && startPt_B.y == 0)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), START_ERR_CAPTION_B, START_ERR_TITLE, MB_OK);	return -1;
	}

	//Aのゴールが決まっていなければ
	if (GoalRect_A.left == -1)
	{
		MessageBox(GetMainWindowHandle(), GOAL_ERR_CAPTION_A, GOAL_ERR_TITLE, MB_OK);	return -1;
	}

	//Bのゴールが決まっていなければ
	if (GoalRect_B.left == -1)
	{
		MessageBox(GetMainWindowHandle(), GOAL_ERR_CAPTION_B, GOAL_ERR_TITLE, MB_OK);	return -1;
	}

	//プレイヤーAの画像座標を初期位置に設定
	player_A.image.x = startPt_A.x;
	player_A.image.y = startPt_A.y;

	//プレイヤーAの画像座標を初期位置に設定
	player_B.image.x = startPt_B.x;
	player_B.image.y = startPt_B.y;

	//無限ループ
	while (TRUE)
	{
		if (ProcessMessage() != 0) { break; }	//メッセージ処理の結果がエラーのとき、強制終了
		if (ClearDrawScreen() != 0) { break; }	//画面を消去できなかったとき、強制終了

		//画面の閉じるボタンを押されたとき
		if (GetWindowUserCloseFlag(TRUE))
		{
			//終了ダイアログを表示
			int Ret = MessageBox(GetMainWindowHandle(), MSG_CLOSE_CAPTION, MSG_CLOSE_TITLE, MB_YESNO | MB_ICONASTERISK);
			if (Ret == IDYES) { break; }	//YESなら、ゲームを中断する
		}

		//シーンごとに処理を行う
		switch (GameScene)
		{
		case GAME_SCENE_START:
			MY_START();	//スタート画面
			break;
		case GAME_SCENE_PLAY:
			MY_PLAY();	//プレイ画面
			break;
		case GAME_SCENE_END:
			MY_END();	//エンド画面
			break;
		}
		ScreenFlip();		//モニタのリフレッシュレートの速さで裏画面を再描画
	}

	//画像ハンドルを破棄
	MY_DELETE_IMAGE();

	//音楽ハンドルを破棄
	MY_DELETE_MUSIC();

	DxLib_End();	//ＤＸライブラリ使用の終了処理

	return 0;
}

//スタート画面
VOID MY_START(VOID)
{
	MY_START_PROC();	//スタート画面の処理
	MY_START_DRAW();	//スタート画面の描画

	return;
}

//スタート画面の処理
VOID MY_START_PROC(VOID)
{
	//BGMが流れていないなら
	if (CheckSoundMem(BGM_TITLE.handle) == 0)
	{
		//BGMの音量を下げる
		ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, BGM_TITLE.handle);	//MUSIC_VOLUMEで音量調節
		PlaySoundMem(BGM_TITLE.handle, DX_PLAYTYPE_LOOP);
	}

	//エンターキーを押したら、プレイシーンへ移動する
	if (CheckHitKey(KEY_INPUT_RETURN) == TRUE)
	{
		//BGMが流れているなら
		if (CheckSoundMem(BGM_TITLE.handle) != 0)
		{
			StopSoundMem(BGM_TITLE.handle);	//BGMを止める
		}

		//ゲームのシーンをプレイ画面にする
		GameScene = GAME_SCENE_PLAY;

		return;  //強制的にプレイ画面へ
	}

	//タイトルロゴを拡大
	if (ImageTitleROGO.rate < ImageTitleROGO.rateMAX)
	{
		ImageTitleROGO.rate += IMAGE_TITLE_ROGO_ROTA;
	}

	//タイトルロゴを移動
	if (ImageTitleROGO.image.x < GAME_WIDTH / 2)
	{
		ImageTitleROGO.image.x += IMAGE_TITLE_ROGO_X_SPEED;
	}
	else
	{
		//タイトルロゴが移動しきったら

		//スタートを点滅
		if (ImageTitleSTART.Cnt < ImageTitleSTART.CntMAX)
		{
			ImageTitleSTART.Cnt += IMAGE_TITLE_START_CNT;
		}
		else
		{
			//描画する/しないを決める
			if (ImageTitleSTART.IsDraw == FALSE)
			{
				ImageTitleSTART.IsDraw = TRUE;
			}
			else if (ImageTitleSTART.IsDraw == TRUE)
			{
				ImageTitleSTART.IsDraw = FALSE;
			}
			ImageTitleSTART.Cnt = 0;
		}
	}

	return;
}

//スタート画面の描画
VOID MY_START_DRAW(VOID)
{
	DrawGraph(ImageTitleBK.x, ImageTitleBK.y, ImageTitleBK.handle, TRUE);	//タイトル背景の描画

	//タイトルロゴを回転しながら描画
	DrawRotaGraph(
		ImageTitleROGO.image.x, ImageTitleROGO.image.y,	//画像の座標
		ImageTitleROGO.rate,							//画像の拡大率
		ImageTitleROGO.angle,							//画像の回転率
		ImageTitleROGO.image.handle, TRUE);				//画像のハンドル

	//点滅
	if (ImageTitleSTART.IsDraw == TRUE)
	{
		//タイトルスタートの描画
		DrawGraph(ImageTitleSTART.image.x, ImageTitleSTART.image.y, ImageTitleSTART.image.handle, TRUE);
	}

	//デバッグ判定がONならデバッグ用表示をする
	if (DEBUG == "ON") {
		DrawString(0, 0, "スタート画面(エンターキーを押して下さい)", GetColor(255, 255, 255));
	}

	return;
}

//プレイ画面初期化
VOID MY_PLAY_INIT(VOID)
{
	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//マップを初期化
			map[tate][yoko].kind = mapDataInit[tate][yoko];

			//マップの当たり判定の初期化
			mapColl[tate][yoko].left = mapCollInit[tate][yoko].left;
			mapColl[tate][yoko].top = mapCollInit[tate][yoko].top;
			mapColl[tate][yoko].right = mapCollInit[tate][yoko].right;
			mapColl[tate][yoko].bottom = mapCollInit[tate][yoko].bottom;
		}
	}

	player_A.image.x = startPt_A.x;
	player_A.image.y = startPt_A.y;

	player_B.image.x = startPt_B.x;
	player_B.image.y = startPt_B.y;

	s1_check = 0;
	s2_check = 0;
	s3_check = 0;
	s4_check = 0;

	return;
}

//プレイ画面
VOID MY_PLAY(VOID)
{
	MY_PLAY_PROC();	//プレイ画面の処理
	MY_PLAY_DRAW();	//プレイ画面の描画

	return;
}

//プレイ画面の処理
VOID MY_PLAY_PROC(VOID)
{
	//スペースキーを押したら、エンドシーンへ移動する
	if (CheckHitKey(KEY_INPUT_SPACE) == TRUE)
	{
		if (CheckSoundMem(BGM.handle) != 0)
		{
			StopSoundMem(BGM.handle);	//BGMを止める
		}

		GameScene = GAME_SCENE_END;

		return;	//強制的にエンド画面に飛ぶ
	}

	//BGMが流れていないなら
	if (CheckSoundMem(BGM.handle) == 0)
	{
		//BGMの音量を下げる
		ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, BGM.handle);	//MUSIC_VOLUMEで音量調節

		//BGMを流す
		//DX_PLAYTYPE_NORMAL:　ノーマル再生
		//DX_PLAYTYPE_BACK  : バックグラウンド再生
		//DX_PLAYTYPE_LOOP  : ループ再生
		PlaySoundMem(BGM.handle, DX_PLAYTYPE_LOOP);
	}

	//プレイヤーAを操作する
	if (CheckHitKey(KEY_INPUT_W)) { player_A.image.y -= MAP_DIV_HEIGHT; }
	if (CheckHitKey(KEY_INPUT_S)) { player_A.image.y += MAP_DIV_HEIGHT; }
	if (CheckHitKey(KEY_INPUT_A)) { player_A.image.x -= MAP_DIV_WIDTH; }
	if (CheckHitKey(KEY_INPUT_D)) { player_A.image.x += MAP_DIV_WIDTH; }

	//プレイヤーBを操作する
	if (CheckHitKey(KEY_INPUT_UP)) { player_B.image.y -= MAP_DIV_HEIGHT; }
	if (CheckHitKey(KEY_INPUT_DOWN)) { player_B.image.y += MAP_DIV_HEIGHT; }
	if (CheckHitKey(KEY_INPUT_LEFT)) { player_B.image.x -= MAP_DIV_WIDTH; }
	if (CheckHitKey(KEY_INPUT_RIGHT)) { player_B.image.x += MAP_DIV_WIDTH; }


	//-----------------------当たり判定関係ここから------------------------
	//プレイヤーAの当たり判定の設定
	player_A.coll.left = player_A.image.x;
	player_A.coll.top = player_A.image.y;
	player_A.coll.right = player_A.image.x + mapChip.width;
	player_A.coll.bottom = player_A.image.y + mapChip.height;

	//プレイヤーBの当たり判定の設定
	player_B.coll.left = player_B.image.x;
	player_B.coll.top = player_B.image.y;
	player_B.coll.right = player_B.image.x + mapChip.width;
	player_B.coll.bottom = player_B.image.y + mapChip.height;

	BOOL IsMove_A = TRUE;
	BOOL IsMove_B = TRUE;

	//プレイヤーAと壁が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_k)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//プレイヤーAとギミック1が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_m1)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//プレイヤーAとギミック2が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_m2)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//プレイヤーAとギミック3が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_m3)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}

	//プレイヤーAとギミック4が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_m4)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_A.image.x = player_A.collBeforePt.x;
		player_A.image.y = player_A.collBeforePt.y;

		IsMove_A = FALSE;
	}
	
	//プレイヤーAがスイッチ1に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_s1)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//ギミック1を通路にして消す
				if (map[tate][yoko].kind == m1)
				{
					map[tate][yoko].kind = t;
					s1_check = 1;

				}
			}
		}
	}

	//プレイヤーAがスイッチ2に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_s2)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//ギミック2を通路にして消す
				if (map[tate][yoko].kind == m2)
				{
					map[tate][yoko].kind = t;
					s2_check = 1;

				}
			}
		}
	}

	//プレイヤーAがスイッチ3に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_s3)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//ギミック2を通路にして消す
				if (map[tate][yoko].kind == m3)
				{
					map[tate][yoko].kind = t;
					s3_check = 1;

				}
			}
		}
	}

	//プレイヤーAがスイッチ4に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_s4)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//ギミック2を通路にして消す
				if (map[tate][yoko].kind == m4)
				{
					map[tate][yoko].kind = t;
					s4_check = 1;

				}
			}
		}
	}

	//プレイヤーAと鍵扉が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_kl)
	{
		if (ki_check == 0) {
			//プレイヤーAの座標を１つ前の座標に置き換える
			player_A.image.x = player_A.collBeforePt.x;
			player_A.image.y = player_A.collBeforePt.y;

			IsMove_A = FALSE;
		}
		else if(ki_check == 1) {

			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//鍵扉を通路にして消す
					if (map[tate][yoko].kind == kl)
					{
						map[tate][yoko].kind = t;
					}
				}
			}
		}
	}

	//プレイヤーAが鍵に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_ki)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{

				//鍵を通路にして消す
				if (map[tate][yoko].kind == ki)
				{
					map[tate][yoko].kind = t;
					ki_check = 1;

				}
			}
		}
	}

	//プレイヤーBと壁が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_k)
	{
		//プレイヤーBの座標を１つ前の座標に置き換える
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}
	
	//プレイヤーBとギミック1が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_m1)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//プレイヤーBとギミック2が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_m2)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//プレイヤーBとギミック3が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_m3)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//プレイヤーBとギミック4が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_m4)
	{
		//プレイヤーAの座標を１つ前の座標に置き換える
		player_B.image.x = player_B.collBeforePt.x;
		player_B.image.y = player_B.collBeforePt.y;

		IsMove_B = FALSE;
	}

	//プレイヤーBがスイッチ1に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_s1)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//ギミック1を通路にして消す
				if (map[tate][yoko].kind == m1)
				{
					map[tate][yoko].kind = t;
					s1_check = 1;
				}
			}
		}
	}

	//プレイヤーBがスイッチ2に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_s2)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//ギミック2を通路にして消す
				if (map[tate][yoko].kind == m2)
				{
					map[tate][yoko].kind = t;
					s2_check = 1;

				}
			}
		}
	}

	//プレイヤーBがスイッチ3に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_s3)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//ギミック2を通路にして消す
				if (map[tate][yoko].kind == m3)
				{
					map[tate][yoko].kind = t;
					s3_check = 1;

				}
			}
		}
	}

	//プレイヤーBがスイッチ4に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_s4)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//ギミック2を通路にして消す
				if (map[tate][yoko].kind == m4)
				{
					map[tate][yoko].kind = t;
					s4_check = 1;

				}
			}
		}
	}

	//プレイヤーAと鍵扉が当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_kl)
	{
		if (ki_check == 0) {
			//プレイヤーAの座標を１つ前の座標に置き換える
			player_B.image.x = player_B.collBeforePt.x;
			player_B.image.y = player_B.collBeforePt.y;

			IsMove_B = FALSE;
		}
		else if (ki_check == 1) {

			for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
				{
					//鍵扉を通路にして消す
					if (map[tate][yoko].kind == kl)
					{
						map[tate][yoko].kind = t;
					}
				}
			}
		}
	}

	//プレイヤーBが鍵に当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_ki)
	{
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//鍵を通路にして消す
				if (map[tate][yoko].kind == ki)
				{
					map[tate][yoko].kind = t;
					ki_check = 1;
				}
			}
		}
	}

	//プレイヤーAとBがゴールに当たっていたら
	if (MY_CHECK_MAP1_PLAYER_COLL(player_A.coll) == TRUE_ag) {
		if (MY_CHECK_MAP1_PLAYER_COLL(player_B.coll) == TRUE_bg) {

			//BGMが流れているなら
			if (CheckSoundMem(BGM.handle) != 0)
			{
				StopSoundMem(BGM.handle);	//BGMを止める
			}
			GameScene = GAME_SCENE_END;

			return;
		}
	}

	
	//プレイヤーAが移動先に動けるなら
	if (IsMove_A == TRUE)
	{
		//当たっていない時のプレイヤーAの座標を取得
		player_A.collBeforePt.x = player_A.image.x;
		player_A.collBeforePt.y = player_A.image.y;
	}

	//プレイヤーBが移動先に動けるなら
	if (IsMove_B == TRUE)
	{
		//当たっていない時のプレイヤーBの座標を取得
		player_B.collBeforePt.x = player_B.image.x;
		player_B.collBeforePt.y = player_B.image.y;
	}
	//-----------------------当たり判定関係ここまで------------------------

	return;
}

//プレイ画面の描画
VOID MY_PLAY_DRAW(VOID)
{
	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//マップを描画
			DrawGraph(
				map[tate][yoko].x,
				map[tate][yoko].y,
				mapChip.handle[map[tate][yoko].kind],
				TRUE);
		}
	}

	if (ki_check == 1) {
		//鍵取得状態を描画
		DrawGraph(
			MAP_DIV_WIDTH * 9,
			MAP_DIV_HEIGHT * 14,
			mapChip.handle[30],
			TRUE);
	}

	//プレイヤーAを描画する
	strcpy_s(ImageBack.path, IMAGE_player_A_PATH);
	LoadGraphScreen(player_A.image.x , player_A.image.y, ImageBack.path, FALSE);

	//プレイヤーBを描画する
	strcpy_s(ImageBack.path, IMAGE_player_B_PATH);
	LoadGraphScreen(player_B.image.x , player_B.image.y, ImageBack.path, FALSE);
	WaitTimer(60);

	//デバッグ判定がONならデバッグ用表示をする
	if (DEBUG == "ON") {
		//当たり判定の描画（デバッグ用）
		for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
		{
			for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
			{
				//壁ならば壁用の当たり判定を描画
				if (mapData[tate][yoko] == k)
				{
					DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 0, 255), FALSE);
				}

				//ギミック1であり、なおかつスイッチ1が押されていない（s1_check=0）ならばギミック用の当たり判定を描画
				if (mapData[tate][yoko] == m1 && s1_check == 0)
				{
					DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
				}

				//ギミック2であり、なおかつスイッチ2が押されていない（s2_check=0）ならばギミック用の当たり判定を描画
				if (mapData[tate][yoko] == m2 && s2_check == 0)
				{
					DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
				}

				//ギミック3であり、なおかつスイッチ3が押されていない（s3_check=0）ならばギミック用の当たり判定を描画
				if (mapData[tate][yoko] == m3 && s3_check == 0)
				{
					DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
				}

				//ギミック4であり、なおかつスイッチ4が押されていない（s4_check=0）ならばギミック用の当たり判定を描画
				if (mapData[tate][yoko] == m4 && s4_check == 0)
				{
					DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 0, 177), FALSE);
				}

				//通路ならば通路用の当たり判定を描画
				if (mapData[tate][yoko] == t)
				{
					DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 255, 255), FALSE);
				}

				//スイッチ1ならばスイッチ1用の当たり判定を描画
				if (mapData[tate][yoko] == s1)
				{
					DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
				}

				//スイッチ2ならばスイッチ2用の当たり判定を描画
				if (mapData[tate][yoko] == s2)
				{
					DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
				}

				//スイッチ3ならばスイッチ3用の当たり判定を描画
				if (mapData[tate][yoko] == s3)
				{
					DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
				}

				//スイッチ4ならばスイッチ4用の当たり判定を描画
				if (mapData[tate][yoko] == s4)
				{
					DrawBox(mapColl[tate][yoko].left, mapColl[tate][yoko].top, mapColl[tate][yoko].right, mapColl[tate][yoko].bottom, GetColor(0, 255, 0), FALSE);
				}

				DrawString(0, 0, "プレイ画面(スペースキーを押して下さい)", GetColor(255, 255, 255));
			}
		}

		//プレイヤーAの当たり判定の描画（デバッグ用）
		DrawBox(player_A.coll.left, player_A.coll.top, player_A.coll.right, player_A.coll.bottom, GetColor(255, 0, 0), FALSE);

		//プレイヤーBの当たり判定の描画（デバッグ用）
		DrawBox(player_B.coll.left, player_B.coll.top, player_B.coll.right, player_B.coll.bottom, GetColor(255, 0, 0), FALSE);

	}

	DrawString(0, 0, "プレイヤーA：WASDで操作\nプレイヤーB：方向キーで操作", GetColor(255, 255, 255));
	return;
}

//エンド画面
VOID MY_END(VOID)
{
	MY_END_PROC();	//エンド画面の処理
	MY_END_DRAW();	//エンド画面の描画

	return;
}

//エンド画面の処理
VOID MY_END_PROC(VOID)
{
	//プレイ画面初期化
	MY_PLAY_INIT();

	//エスケープキーを押したら、スタートシーンへ移動する
	if (CheckHitKey(KEY_INPUT_ESCAPE) == TRUE)
	{
		//BGMが流れているなら
		if (CheckSoundMem(BGM_COMP.handle) != 0)
		{
			StopSoundMem(BGM_COMP.handle);	//BGMを止める
		}
		GameScene = GAME_SCENE_START;
		return;
	}

	//BGMが流れていないなら
	if (CheckSoundMem(BGM_COMP.handle) == 0)
	{
		//BGMの音量を下げる
		ChangeVolumeSoundMem(255 * MUSIC_VOLUME / 100, BGM_COMP.handle); //MUSIC_VOLUMEで音量調節
		PlaySoundMem(BGM_COMP.handle, DX_PLAYTYPE_LOOP);
	}

	//コンプリートの点滅
	if (ImageEndCOMP.Cnt < ImageEndCOMP.CntMAX)
	{
		ImageEndCOMP.Cnt += IMAGE_END_COMP_CNT;
	}
	else
	{
		//描画する/しないを決める
		if (ImageEndCOMP.IsDraw == FALSE)
		{
			ImageEndCOMP.IsDraw = TRUE;
		}
		else if (ImageEndCOMP.IsDraw == TRUE)
		{
			ImageEndCOMP.IsDraw = FALSE;
		}
		ImageEndCOMP.Cnt = 0;
	}

	return;
}

//エンド画面の描画
VOID MY_END_DRAW(VOID)
{
	DrawGraph(ImageTitleBK.x, ImageTitleBK.y, ImageTitleBK.handle, TRUE);	//エンド背景の描画

	//点滅
	if (ImageEndCOMP.IsDraw == TRUE)
	{
		//コンプリートロゴの描画
		DrawGraph(ImageEndCOMP.image.x, ImageEndCOMP.image.y, ImageEndCOMP.image.handle, TRUE);

		//エンドタイトルの描画
		DrawGraph(ImageTitleEND.image.x, ImageTitleEND.image.y, ImageTitleEND.image.handle, TRUE);
	}

	//デバッグ判定がONならデバッグ用表示をする
	/*if (DEBUG == "ON") {
		DrawString(0, 0, "エンド画面(エスケープキーを押して下さい)", GetColor(255, 0, 255));
	}*/
	return;
}

//画像をまとめて読み込む関数
BOOL MY_LOAD_IMAGE(VOID)
{
	//プレイヤーAの画像
	strcpy_s(player_A.image.path, IMAGE_player_A_PATH);		//パスの設定
	player_A.image.handle = LoadGraph(player_A.image.path);	//読み込み
	if (player_A.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_player_A_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//プレイヤーBの画像
	strcpy_s(player_B.image.path, IMAGE_player_B_PATH);		//パスの設定
	player_B.image.handle = LoadGraph(player_B.image.path);	//読み込み
	if (player_B.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_player_B_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//タイトル背景
	strcpy_s(ImageTitleBK.path, IMAGE_TITLE_BK_PATH);			//パスの設定
	ImageTitleBK.handle = LoadGraph(ImageTitleBK.path);			//読み込み
	if (ImageTitleBK.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_BK_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleBK.handle, &ImageTitleBK.width, &ImageTitleBK.height);	//画像の幅と高さをf取得
	ImageTitleBK.x = GAME_WIDTH / 2 - ImageTitleBK.width / 2;		//左右中央揃え
	ImageTitleBK.y = GAME_HEIGHT / 2 - ImageTitleBK.height / 2;		//上下中央揃え

	//タイトルロゴ
	strcpy_s(ImageTitleROGO.image.path, IMAGE_TITLE_ROGO_PATH);					//パスの設定
	ImageTitleROGO.image.handle = LoadGraph(ImageTitleROGO.image.path);			//読み込み
	if (ImageTitleROGO.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_ROGO_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleROGO.image.handle, &ImageTitleROGO.image.width, &ImageTitleROGO.image.height);	//画像の幅と高さを取得
	ImageTitleROGO.image.x = 230;							//光っている部分から描画したい
	ImageTitleROGO.image.y = GAME_HEIGHT / 2;				//中央寄せ
	ImageTitleROGO.angle = DX_PI * 2;						//回転率
	ImageTitleROGO.angleMAX = DX_PI * 2;					//回転率MAX
	ImageTitleROGO.rate = 0.0;								//拡大率
	ImageTitleROGO.rateMAX = IMAGE_TITLE_ROGO_ROTA_MAX;		//拡大率MAX

	//タイトルスタート
	strcpy_s(ImageTitleSTART.image.path, IMAGE_TITLE_START_PATH);					//パスの設定
	ImageTitleSTART.image.handle = LoadGraph(ImageTitleSTART.image.path);			//読み込み
	if (ImageTitleSTART.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_START_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleSTART.image.handle, &ImageTitleSTART.image.width, &ImageTitleSTART.image.height);	//画像の幅と高さを取得
	ImageTitleSTART.image.x = GAME_WIDTH / 2 - ImageTitleSTART.image.width / 2;					//左右中央揃え
	ImageTitleSTART.image.y = ImageTitleROGO.image.y + ImageTitleROGO.image.height / 2 + 10;	//ロゴの下に表示
	ImageTitleSTART.Cnt = 0.0;								//カウンタ
	ImageTitleSTART.CntMAX = IMAGE_TITLE_START_CNT_MAX;		//カウンタMAX
	ImageTitleSTART.IsDraw = FALSE;							//描画させない

	//エンドコンプ
	strcpy_s(ImageEndCOMP.image.path, IMAGE_END_COMP_PATH);
	ImageEndCOMP.image.handle = LoadGraph(ImageEndCOMP.image.path);
	if (ImageEndCOMP.image.handle == -1)
	{
		MessageBox(GetMainWindowHandle(), IMAGE_END_COMP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	GetGraphSize(ImageEndCOMP.image.handle, &ImageEndCOMP.image.width, &ImageEndCOMP.image.height);	//画像の幅と高さを取得
	ImageEndCOMP.image.x = GAME_WIDTH / 2 - ImageEndCOMP.image.width / 2;			//左右中央揃え
	ImageEndCOMP.image.y = GAME_HEIGHT / 2 - ImageEndCOMP.image.height / 2;			//上下中央揃え
	ImageEndCOMP.Cnt = 0.0;									//カウンタ
	ImageEndCOMP.CntMAX = IMAGE_END_COMP_CNT_MAX;			//カウンタMAX
	ImageEndCOMP.IsDraw = TRUE;							//描画させない

	//エンドタイトル
	strcpy_s(ImageTitleEND.image.path, IMAGE_TITLE_END_PATH);					//パスの設定
	ImageTitleEND.image.handle = LoadGraph(ImageTitleEND.image.path);			//読み込み
	if (ImageTitleEND.image.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), IMAGE_TITLE_END_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}
	GetGraphSize(ImageTitleEND.image.handle, &ImageTitleEND.image.width, &ImageTitleEND.image.height);	//画像の幅と高さを取得
	ImageTitleEND.image.x = GAME_WIDTH / 2 - ImageTitleEND.image.width / 2 + 10;					//左右中央揃え
	ImageTitleEND.image.y = ImageEndCOMP.image.y + ImageEndCOMP.image.height / 2 + 150;	//ロゴの下に表示
	ImageTitleEND.Cnt = 0.0;								//カウンタ
	ImageTitleEND.CntMAX = IMAGE_END_COMP_CNT_MAX;		    //カウンタMAX
	ImageTitleEND.IsDraw = FALSE;							//描画させない

	//マップの画像を分割する
	int mapRes = LoadDivGraph(
		GAME_MAP_PATH,										//マップのパス
		MAP_DIV_NUM, MAP_DIV_TATE, MAP_DIV_YOKO,			//マップを分割する数
		MAP_DIV_WIDTH, MAP_DIV_HEIGHT,						//画像を分割するの幅と高さ
		&mapChip.handle[0]);								//分割した画像が入るハンドル

	if (mapRes == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), GAME_MAP_PATH, IMAGE_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//幅と高さを取得
	GetGraphSize(mapChip.handle[0], &mapChip.width, &mapChip.height);

	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//マップデータ初期化用に情報をコピー
			mapDataInit[tate][yoko] = mapData[tate][yoko];

			//マップの種類をコピー
			map[tate][yoko].kind = mapData[tate][yoko];

			//マップの幅と高さをコピー
			map[tate][yoko].width = mapChip.width;
			map[tate][yoko].height = mapChip.height;

			//マップの座標を設定
			map[tate][yoko].x = yoko * map[tate][yoko].width;
			map[tate][yoko].y = tate * map[tate][yoko].height;
		}
	}

	//マップの当たり判定を設定する
	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//マップの当たり判定を設定
			mapColl[tate][yoko].left = (yoko + 0) * mapChip.width + 1;
			mapColl[tate][yoko].top = (tate + 0) * mapChip.height + 1;
			mapColl[tate][yoko].right = (yoko + 1) * mapChip.width - 1;
			mapColl[tate][yoko].bottom = (tate + 1) * mapChip.height - 1;

			//マップの初期状態を設定
			mapCollInit[tate][yoko].left = mapColl[tate][yoko].left;
			mapCollInit[tate][yoko].top = mapColl[tate][yoko].top;
			mapCollInit[tate][yoko].right = mapColl[tate][yoko].right;
			mapCollInit[tate][yoko].bottom = mapColl[tate][yoko].bottom;

		}
	}

	return TRUE;
}

//画像をまとめて削除する関数
VOID MY_DELETE_IMAGE(VOID)
{
	DeleteGraph(ImageTitleBK.handle);           //タイトル背景削除
	DeleteGraph(ImageTitleROGO.image.handle);   //タイトルロゴ削除
	DeleteGraph(ImageTitleSTART.image.handle);  //タイトル文字削除
	DeleteGraph(ImageEndCOMP.image.handle);     //エンドコンプロゴ削除
	DeleteGraph(ImageTitleEND.image.handle);     //エンドタイトル削除
	DeleteGraph(ImageBack.handle);              //プレイ背景削除
	DeleteGraph(player_A.image.handle);           //プレイヤーA画像削除
	DeleteGraph(player_B.image.handle);           //プレイヤーB画像削除

	for (int i_num = 0; i_num < MAP_DIV_NUM; i_num++) { DeleteGraph(mapChip.handle[i_num]); }

	return;
}

//音楽をまとめて読み込む関数
BOOL MY_LOAD_MUSIC(VOID)
{
	//プレイ画面のBGM
	strcpy_s(BGM.path, MUSIC_BGM_PATH);
	BGM.handle = LoadSoundMem(BGM.path);
	if (BGM.handle == -1) {
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//タイトルのBGM
	strcpy_s(BGM_TITLE.path, MUSIC_BGM_TITLE_PATH);				//パスの設定
	BGM_TITLE.handle = LoadSoundMem(BGM_TITLE.path);			//読み込み
	if (BGM_TITLE.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_TITLE_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	//コンプリートBGM
	strcpy_s(BGM_COMP.path, MUSIC_BGM_COMP_PATH);				//パスの設定
	BGM_COMP.handle = LoadSoundMem(BGM_COMP.path);				//読み込み
	if (BGM_COMP.handle == -1)
	{
		//エラーメッセージ表示
		MessageBox(GetMainWindowHandle(), MUSIC_BGM_COMP_PATH, MUSIC_LOAD_ERR_TITLE, MB_OK);
		return FALSE;
	}

	return TRUE;
}

//音楽をまとめて削除する関数
VOID MY_DELETE_MUSIC(VOID)
{
	DeleteSoundMem(BGM.handle);

	return;
}

//マップとプレイヤーの当たり判定をする関数
int MY_CHECK_MAP1_PLAYER_COLL(RECT player)
{
	//マップの当たり判定を設定する
	for (int tate = 0; tate < GAME_MAP_TATE_MAX; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO_MAX; yoko++)
		{
			//プレイヤーとマップが当たっているとき
			if (MY_CHECK_RECT_COLL(player, mapColl[tate][yoko]) == TRUE)
			{
				//壁の時
				if (map[tate][yoko].kind == k) { return TRUE_k; }

				//ギミック1の時
				if (map[tate][yoko].kind == m1) { return TRUE_m1; }

				//ギミック2の時
				if (map[tate][yoko].kind == m2) { return TRUE_m2; }

				//ギミック3の時
				if (map[tate][yoko].kind == m3) { return TRUE_m3; }

				//ギミック4の時
				if (map[tate][yoko].kind == m4) { return TRUE_m4; }

				//スイッチ1の時
				if (map[tate][yoko].kind == s1) { return TRUE_s1; }

				//スイッチ2の時
				if (map[tate][yoko].kind == s2) { return TRUE_s2; }

				//スイッチ3の時
				if (map[tate][yoko].kind == s3) { return TRUE_s3; }

				//スイッチ4の時
				if (map[tate][yoko].kind == s4) { return TRUE_s4; }

				//鍵の時
				if (map[tate][yoko].kind == ki) { return TRUE_ki; }

				//鍵扉の時
				if (map[tate][yoko].kind == kl) { return TRUE_kl; }

				//プレイヤーA用のゴールの時
				if (map[tate][yoko].kind == ag) { return TRUE_ag; }

				//プレイヤーB用のゴールの時
				if (map[tate][yoko].kind == bg) { return TRUE_bg; }


			}
		}
	}

	return FALSE;
}

//領域の当たり判定をする関数
BOOL MY_CHECK_RECT_COLL(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top
		)
	{
		return TRUE;  //当たっている
	}

	return FALSE;     //当たっていない
}