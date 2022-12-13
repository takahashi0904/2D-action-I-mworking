#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include <math.h>

static int mImageHandle;    //画像ハンドル格納用変数
static int Player;
//プレイヤー
static int mx = 0;
static int my = 0;
int HP = 0;
//エネミー
static int ex;
static int ey;
static int eHP;

//当たり判定
static float lenght = 0;
static float lenght_x = 0;
static float lenght_y = 0;


//初期化
void Game_Initialize() {
    mImageHandle = LoadGraph("images/Scene_Game.png");    //画像のロード
    Player = LoadGraph("画像/Player.png");
    //自分の位置初期化
    mx = 320;
    my = 400;
    HP = 2000;
  
    //敵の位置を初期化
    ex = 300;
    ey = 200;
    eHP = 1000;
}


//更新
void Game_Update() {

    //移動フェーズ
    if (CheckHitKey(KEY_INPUT_W) == 1) {//上
        my -= 3;
    }
    if (CheckHitKey(KEY_INPUT_S) == 1) {//下
        my += 3;
    }
    if (CheckHitKey(KEY_INPUT_D) == 1) {//右
        mx += 3;
    }
    if (CheckHitKey(KEY_INPUT_A) == 1) {//左
        mx -= 3;
    }
    //

    if (mx <= ex) {
        ex--;
    }
    if (mx >= ex) {
        ex++;
    }
    if (my >= ey) {
        ey++;
    }
    if (my <= ey) {
        ey--;
    }



    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_title);//シーンをメニューに変更
    }

    //当たり判定の計算プログラムを打ち込めえええええ
    //Palayerと敵の当たり判定
    lenght_x = pow(mx - ex, 2);
    lenght_y = pow(my - ey, 2);
    lenght = sqrt(lenght_x + lenght_y);

    if ((20 + 20) >= lenght) {
        HP -= 1;
        eHP -= 1;
    }


    if (HP <= 0) {
        SceneMgr_ChangeScene(eScene_Over);
    }


}

//描画
void Game_Draw() {
    DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), TRUE);   // 四角形を描画(塗りつぶし)
    DrawString(0, 0, "ゲーム画面です。", GetColor(0, 0, 0));
    DrawString(0, 20, "Escキーを押すとメニュー画面に戻ります。", GetColor(0, 0, 0));
    DrawRotaGraph(mx, my, 3, 0, Player, TRUE);//背景の描画
    DrawCircle(mx, my, 20, GetColor(255, 0, 0), TRUE);
    DrawCircle(ex, ey, 20, GetColor(0, 0, 255), TRUE);
    DrawFormatString(400, 280, GetColor(0, 0, 0), "PlayerのHP%d",HP);//文字列表示
    DrawFormatString(400, 300, GetColor(0, 0, 0), "EnemyのHP % d", eHP);//文字列表示
    DrawFormatString(mx, my, GetColor(0, 0, 0), "Player");//文字列表示
    DrawFormatString(ex, ey, GetColor(0, 0, 0), "Enemy");//文字列表示

}

//終了処理
void Game_Finalize() {
    DeleteGraph(mImageHandle);    //画像の解放
}
