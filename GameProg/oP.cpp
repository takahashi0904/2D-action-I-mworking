#include "oP.h"
#include "SceneMgr.h"
#include "DxLib.h"


static int GameOver;    //画像ハンドル格納用変数


//初期化
void oP_Initialize() {

    GameOver = LoadGraph("画像/GameOver.png");    //画像のロード
}

//終了処理
void oP_Finalize() {

    DeleteGraph(GameOver);    //画像の解放

}

//更新
void oP_Update() {

    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_title);//シーンをメニューに変更
    }
}

//描画
void oP_Draw() {
    DrawBox(0, 0, 640, 480, GetColor(255, 0, 0), TRUE);   // 四角形を描画(塗りつぶし)
    //SetFontSize(30);                             //サイズを64に変更
    //SetFontThickness(8);                         //太さを8に変更
    DrawString(310, 200, "1P", GetColor(255, 255, 255));
    DrawString(305, 250, "WIN", GetColor(255, 255, 255));

}