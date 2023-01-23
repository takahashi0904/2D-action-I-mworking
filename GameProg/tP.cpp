#include "tP.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int GameClear;    //画像ハンドル格納用変数

//初期化
void tP_Initialize() {
    GameClear = LoadGraph("画像/GameClear.png");    //画像のロード
}

//終了処理
void tP_Finalize() {
    DeleteGraph(GameClear);    //画像の解放
}

//更新
void tP_Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_title);//シーンをメニューに変更
    }
}

//描
void tP_Draw() {
    DrawBox(0, 0, 640, 480, GetColor(0, 0, 255), TRUE);   // 四角形を描画(塗りつぶし)
    //SetFontSize(30);                             //サイズを64に変更
    //SetFontThickness(8);                         //太さを8に変更
    DrawString(310, 200, "2P", GetColor(255, 255, 255));
    DrawString(305, 250, "WIN", GetColor(255, 255, 255));

}