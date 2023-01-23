#include "title.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int title;    //画像ハンドル格納用変数

//初期化
void title_Initialize() {
    title = LoadGraph("画像/タイトル画面.png"); //画像のロード
}

//終了処理
void title_Finalize() {
    DeleteGraph(title);    //画像の解放
}

const static int GAME_Y = 330;    //「ゲーム」文字のy位置
const static int MENU_Y = 360;    //「設定」文字のy位置
static int Flag = false;

typedef enum {
    eMenu_Game,        //ゲーム
    eMenu_Menu,    //設定

    eMenu_Num,        //本項目の数
} eMenu;

static int NowSelect = eMenu_Game;    //現在の選択状態(初期はゲーム選択中)

//更新
void title_Update() {
    if (CheckHitKey(KEY_INPUT_DOWN) == 1 && Flag == false) {//下キーが押されていたら
        NowSelect = (NowSelect + 1) % eMenu_Num;//選択状態を一つ下げる
        Flag = true;
    }
    if (CheckHitKey(KEY_INPUT_UP) == 1 && Flag == true) {//上キーが押されていたら
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//選択状態を一つ上げる
        Flag = false;
    }
    if (CheckHitKey(KEY_INPUT_S) == 1 && Flag == false) {//下キーが押されていたら
        NowSelect = (NowSelect + 1) % eMenu_Num;//選択状態を一つ下げる
        Flag = true;
    }
    if (CheckHitKey(KEY_INPUT_W) == 1 && Flag == true) {//上キーが押されていたら
        NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//選択状態を一つ上げる
        Flag = false;
    }
    if (CheckHitKey(KEY_INPUT_O) == 1) {//左
        SceneMgr_ChangeScene(eScene_oP);//シーンを設定画面に変更

    }
    if (CheckHitKey(KEY_INPUT_T) == 1) {//左
        SceneMgr_ChangeScene(eScene_tP);//シーンを設定画面に変更

    }
    if (CheckHitKey(KEY_INPUT_RETURN) != 0) {//エンターキーが押されたら
        switch (NowSelect) {//現在選択中の状態によって処理を分岐
        case eMenu_Game://ゲーム選択中なら
            SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
            break;
        case eMenu_Menu://設定選択中なら
            SceneMgr_ChangeScene(eScene_Menu);//シーンを設定画面に変更
            break;
        }
    }
}

//描画
void title_Draw() {
    DrawBox(0, 0, 640, 480, GetColor(0, 0, 128), TRUE);   // 四角形を描画(塗りつぶし)
    DrawBox(0, 300, 640, 480, GetColor(0, 0, 0), TRUE);   // 四角形を描画(塗りつぶし)


    DrawString(310, GAME_Y, "START", GetColor(255, 255, 255));
    DrawString(310, MENU_Y, "MENU", GetColor(255, 255, 255));
    DrawString(290, 440, "＠2022", GetColor(255, 255, 255));
    DrawString(280, 460, "Takahashi", GetColor(255, 255, 255));


    DrawRotaGraph(320, 160, 4, 0, title, TRUE);//背景の描画

    int y = 0;
    switch (NowSelect) {//現在の選択状態に従って処理を分岐
    case eMenu_Game://ゲーム選択中なら
        y = GAME_Y;    //ゲームの座標を格納
        break;
    case eMenu_Menu://設定選択中なら
        y = MENU_Y;    //設定の座標を格納
        break;
    }
    DrawString(290, y, "■", GetColor(255, 255, 255));
}
