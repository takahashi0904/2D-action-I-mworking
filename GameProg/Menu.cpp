#include "Menu.h"
#include "SceneMgr.h"
#include "DxLib.h"



//初期化
void Menu_Initialize() {

}

//終了処理
void Menu_Finalize() {


}

//更新
void Menu_Update() {

    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_title);//シーンをメニューに変更
    }
    if (CheckHitKey(KEY_INPUT_G) != 0) { //Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_Game);//シーンをメニューに変更
    }

}
//描画
void Menu_Draw() {

    DrawString(0, 0, "メニュー画面です。。", GetColor(255, 255, 255));
    DrawString(400, 460, "G でゲームが始まります。", GetColor(255, 255,255));


}