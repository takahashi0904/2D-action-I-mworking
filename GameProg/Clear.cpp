#include "Clear.h"
#include "SceneMgr.h"
#include "DxLib.h"

static int GameClear;    //画像ハンドル格納用変数

//初期化
void Clear_Initialize() {
    GameClear = LoadGraph("画像/GameClear.png");    //画像のロード
}

//終了処理
void Clear_Finalize() {
    DeleteGraph(GameClear);    //画像の解放
}

//更新
void Clear_Update() {
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_title);//シーンをメニューに変更
    }
}

//描画
void Clear_Draw() {
    DrawString(0, 20, "Esc タイトル", GetColor(255, 255, 255));
    DrawString(0, 0, "クリア画面です", GetColor(255, 255, 255));

}