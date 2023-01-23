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

}
//描画
void Menu_Draw() {

    DrawString(200, 150, "A　　左", GetColor(255, 255, 255));
    DrawString(200, 200, "D　　右", GetColor(255, 255,255));
    DrawString(200, 250, "S　　攻撃", GetColor(255, 255, 255));

    DrawString(360, 150, "←　　左", GetColor(255, 255, 255));
    DrawString(360, 200, "→　　右", GetColor(255, 255, 255));
    DrawString(360, 250, "↓　　攻撃", GetColor(255, 255, 255));

}