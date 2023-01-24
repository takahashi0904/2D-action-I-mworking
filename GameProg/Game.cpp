#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include <math.h>
//#define OPLAYER 5
//#define TPLAYER 5


//弾の配列
//class Tama{
//public:
//  
//    int omax = OPLAYER;
//    float ox[OPLAYER];
//    float oy[OPLAYER];
//    bool of;
//
//    int tmax = TPLAYER;
//    float tx[TPLAYER];
//    float ty[TPLAYER];
//    bool tf;
//};
//Tama tama;


class Player {
public:
    //Playerの座標
    float x = 0;
    float y = 0;
    //HP
    int HP = 0;
    //弾の座標
    float bx = 0;
    float by = 0;
    //フラッグ
    bool f = 0;
    //当たり判定
    float l = 0;
    float lx = 0;
    float ly = 0;
    //画像
    int p;
};
Player Player1;
Player Player2;

//時間
static int time = 0;
static int count = 0;

static int mImageHandle;    //画像ハンドル格納用変数
static int py;

//画像
int bg;
int bullet;

//初期化
void Game_Initialize() {
    mImageHandle = LoadGraph("images/Scene_Game.png");    //画像のロード
    bg = LoadGraph("画像/sea.png");
    bullet = LoadGraph("画像/bullet.png");

    //Playerの値を初期化
    Player1.x = 320;
    Player1.y = 40;
    Player1.HP = 100;
    Player1.bx = Player1.x;
    Player1.by = Player1.y;
    Player1.f = false;
    Player1.p = LoadGraph("画像/1P.png");

    Player2.x = 320;
    Player2.y = 440;
    Player2.HP = 100;
    Player2.bx = Player2.x;
    Player2.by = Player2.y;
    Player2.f = false;
    Player2.p = LoadGraph("画像/2P.png");

}

//更新
void Game_Update() {

    count++;
    time = count / 100;

    if (Player1.y < 180) {
        Player1.y += 0.05;
        Player1.by += 0.05;
    }
    if (Player2.y > 300) {
        Player2.y -= 0.05;
        Player2.by -= 0.05;
    }

    //1Pの移動と攻撃
    if (CheckHitKey(KEY_INPUT_D) == 1) {//右
        if (Player1.x != 620) {
            Player1.x += 2;
            if (Player1.f == false)
                Player1.bx += 2;
        }
    }
    if (CheckHitKey(KEY_INPUT_A) == 1) {//左
        if (Player1.x != 20) {
            Player1.x -= 2;
            if (Player1.f == false)
                Player1.bx -= 2;
        }
    }
    if (CheckHitKey(KEY_INPUT_S) == 1) {//下
        Player1.f = true;
    }

    //2Pの移動と攻撃
    if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {//右
        if (Player2.x!= 620) {
            Player2.x+=2;
            if (Player2.f == false)
                Player2.bx += 2;
        }
    }
    if (CheckHitKey(KEY_INPUT_LEFT) == 1) {//左
        if (Player2.x != 20) {
            Player2.x-=2;
            if (Player2.f == false)
            Player2.bx -= 2;
        }
    }
    if (CheckHitKey(KEY_INPUT_DOWN) == 1) {
        Player2.f = true;
    }

    //1p の弾フラッグ
    if (Player1.f == true) {
        Player1.by += 5;
        if (Player1.by > 480) {
            Player1.f = false;
            Player1.bx = Player1.x;
            Player1.by = Player1.y;
        }
    }
    //2p の弾フラッグ
    if (Player2.f == true) {
        Player2.by -= 5;
        if (Player2.by < 0) {
            Player2.f = false;
            Player2.bx = Player2.x;
            Player2.by = Player2.y;
        }     
    }

    //1pの当たり判定
    Player1.lx = pow(Player2.bx - Player1.x, 2);
    Player1.ly = pow(Player2.by - Player1.y, 2);
    Player1.l = sqrt(Player1.lx + Player1.ly);
    if ((10 + 20) >= Player1.l) {
        Player1.HP -= 1;
    }

    //2pの当たり判定
    Player2.lx = pow(Player1.bx - Player2.x, 2);
    Player2.ly = pow(Player1.by - Player2.y, 2);
    Player2.l = sqrt(Player2.lx + Player2.ly);
    if ((10 + 20) >= Player2.l) {
        Player2.HP -= 1;
    }

    //１ｐの勝ち
    if (Player2.HP <= 0) {
        SceneMgr_ChangeScene(eScene_oP);
    }
    //２ｐの勝ち
    if (Player1.HP <= 0) {
        SceneMgr_ChangeScene(eScene_tP);
    }
    //ESCでタイトル画面
    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_title);//シーンをメニューに変更
    }
}
    

//描画フェーズ
void Game_Draw() {
    //背景
    DrawRotaGraph(320, 240, 6.4, 0, bg, TRUE);

    //１Pの当たり判定を描画
    DrawRotaGraph(Player1.bx, Player1.by, 1, 0, bullet, TRUE);//1p bullet
    DrawRotaGraph(Player1.x, Player1.y, 2, 0, Player1.p, TRUE);//プレイヤーの描画
   // DrawCircle(ox, oy, 20, GetColor(255, 0, 0), TRUE);
    DrawFormatString(Player1.x - 45, Player1.y - 45, GetColor(0, 0, 0), "1P");//プレイヤー名
    DrawFormatString(Player1.x - 45, Player1.y - 30, GetColor(0, 0, 0), "HP%d", Player1.HP);//HP


     //2Pの当たり判定を描画
    DrawRotaGraph(Player2.bx, Player2.by, 1, 0, bullet, TRUE);//1p bullet
    DrawRotaGraph(Player2.x, Player2.y, 2, 0, Player2.p, TRUE);//プレイヤーの描画
   // DrawCircle(ox, oy, 20, GetColor(255, 0, 0), TRUE);
    DrawFormatString(Player2.x + 45, Player2.y + 45, GetColor(0, 0, 0), "2P");//プレイヤー名
    DrawFormatString(Player2.x + 45, Player2.y + 30, GetColor(0, 0, 0), "HP%d", Player2.HP);//HP


    //DrawFormatString(0, 100, GetColor(0, 0, 0), "計算時間%dミリ秒", count);//文字列表示
    //DrawFormatString(30, 120, GetColor(0, 0, 0), "%d秒", time);//文字列表示

}

//終了処理
void Game_Finalize() {
    DeleteGraph(mImageHandle);    //画像の解放
}
