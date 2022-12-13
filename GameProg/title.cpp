#include "title.h"
#include "SceneMgr.h"
#include "DxLib.h"



//初期化
void title_Initialize() {
}

//終了処理
void title_Finalize() {

}

//更新
void title_Update() {
    if (CheckHitKey(KEY_INPUT_G) != 0) {//Gキーが押されていたら
        SceneMgr_ChangeScene(eScene_Game);//シーンをゲーム画面に変更
    }
    if (CheckHitKey(KEY_INPUT_C) != 0) {//Cキーが押されていたら
        SceneMgr_ChangeScene(eScene_Clear);//シーンを設定画面に変更
    }
    if (CheckHitKey(KEY_INPUT_O) != 0) {//Cキーが押されていたら
        SceneMgr_ChangeScene(eScene_Over);//シーンを設定画面に変更
    }
    if (CheckHitKey(KEY_INPUT_M) != 0) {//Cキーが押されていたら
        SceneMgr_ChangeScene(eScene_Menu);//シーンを設定画面に変更
    }

}

//描画
void title_Draw() {

    DrawString(0, 0, "タイトル画面です。", GetColor(255, 255, 255));
    DrawString(0, 30, "G ゲーム。", GetColor(255, 255, 255));
    DrawString(0, 60, "C　クリア。", GetColor(255, 255,255));
    DrawString(0, 90, "O オーバー。", GetColor(255, 255, 255));
    DrawString(0, 120, "M でメニュー。", GetColor(255, 255, 255));

}