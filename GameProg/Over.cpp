#include "Over.h"
#include "SceneMgr.h"
#include "DxLib.h"


static int GameOver;    //画像ハンドル格納用変数


//初期化
void Over_Initialize() {

    GameOver = LoadGraph("画像/GameOver.png");    //画像のロード
}

//終了処理
void Over_Finalize() {

    DeleteGraph(GameOver);    //画像の解放

}

//更新
void Over_Update() {

    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_title);//シーンをメニューに変更
    }
}

//描画
void Over_Draw() {
    DrawString(0, 20, "ゲームオーバー画面です。", GetColor(255, 255, 255));
    DrawString(0, 40, "Esc タイトル", GetColor(255, 255, 255));

}