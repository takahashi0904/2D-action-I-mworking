#include "Game.h"
#include "SceneMgr.h"
#include "DxLib.h"
#include <math.h>


//class Player {
//public:
//    int mx, my;
//
//    int HP;
//
//    void show();
//};
//
//void Player::show() {
//    mx = 0;
//    my= 0;
//    HP = 0;
//
//}

class Enemy {
public:
    //エネミー
    
    int ex[5];
    int ey[5];
    int eHP[5];

 /*   double ex;
    double ey;
    int eHP;*/
};

Enemy enemy;


static int time = 0;
static int count = 0;
int enemynum=0;

static int a = 0;

static int mImageHandle;    //画像ハンドル格納用変数
static int py;

//プレイヤー
static int mx = 0;
static int my = 0;
static int HP = 0;

static int bg;
int bgx = 0;
int bgy = 0;


//当たり判定
static float lenght = 0;
static float lenght_x = 0;
static float lenght_y = 0;

//エネミー
//int E[10];
//int EnemyNum = 1;
//int ex;
//int ey;
//int eHP;

int i = 0;
bool A = false;

//初期化
void Game_Initialize() {
    mImageHandle = LoadGraph("images/Scene_Game.png");    //画像のロード
    py = LoadGraph("画像/Player.png");
    bg = LoadGraph("画像/背景1.png");

    //自分の位置初期化

    SRand(123456); // 乱数の初期値を123456に設定する

    for (int i = 0; i < 5; i++) {
        enemy.ex[i] = GetRand(640);
        enemy.ey[i] = GetRand(480);
        enemy.eHP[i] = 700;
    }
   
    mx = 320;
    my = 240;

    HP = 1000;
  
    bgx = 320;
    bgy = 240;

    
    A = false;

    //敵の位置を初期化
    /*ex = 300;
    ey = 200;
    eHP = 1000;*/
}

//更新
void Game_Update() {

    count++;

   /* if (count == 100) {
        enemynum++;
        for (int i = enemynum; i < enemynum+1; i++)
        {
            enemy.ex[i] = 300;
            enemy.ey[i] = 200;
            enemy.eHP[i] = 1000;

        }
        count = 0;

    }*/

    /*while (HP > 0) {

    }*/

    //移動
    if (CheckHitKey(KEY_INPUT_W) == 1) {//上
        bgy += 1;
        enemy.ey[0] += 3;
    }
    if (CheckHitKey(KEY_INPUT_S) == 1) {//下
        bgy -= 1;
        enemy.ey[0] -= 3;
    }
    if (CheckHitKey(KEY_INPUT_D) == 1) {//右
        bgx -= 1;
        enemy.ex[0] -= 3;
    }
    if (CheckHitKey(KEY_INPUT_A) == 1) {//左
        bgx += 1;
        enemy.ex[0] += 3;
    }
    //

    //エネミーの計算
    
    //一体目のHPが１以上だったら
    if (enemy.eHP > 0) {
        //敵が寄ってくる
        if (mx <= enemy.ex[0]) {
            enemy.ex[0]--;
        }
        if (mx >= enemy.ex[0]) {
            enemy.ex[0]++;
        }
        if (my >= enemy.ey[0]) {
            enemy.ey[0]++;
        }
        if (my <= enemy.ey[0]) {
            enemy.ey[0]--;
        }
        //一体目の当たり判定
        lenght_x = pow(mx - enemy.ex[0], 2);
        lenght_y = pow(my - enemy.ey[0], 2);
        lenght = sqrt(lenght_x + lenght_y);
        if ((20 + 20) >= lenght) {
            HP -= 1;
            enemy.eHP[0] -= 1;
        }
    }

    /*for (int i = 0; i < GetRand(4); i++) {
        enemy.ex[i + 1] = GetRand(640);
        enemy.ey[i + 1] = GetRand(480);
        DrawCircle(enemy.ex[i], enemy.ey[i], 20, GetColor(0, 0, 255), TRUE);
    }*/

    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Escキーが押されていたら
        SceneMgr_ChangeScene(eScene_title);//シーンをメニューに変更
    }

    //当たり判定の計算プログラムを打ち込めえええええ
    //Palayerと敵の当たり判定

    if (HP <= 0) {
        SceneMgr_ChangeScene(eScene_Over);
    }

    if (enemy.eHP <= 0) {
        SceneMgr_ChangeScene(eScene_Clear);
    }
}

//描画
void Game_Draw() {
    DrawRotaGraph(bgx, bgy, 10, 0, bg, TRUE);//プレイヤーの描画
    DrawString(0, 0, "ゲーム画面です。", GetColor(0, 0, 0));
    DrawString(0, 20, "Escキーを押すとメニュー画面に戻ります。", GetColor(0, 0, 0));
    DrawRotaGraph(mx, my, 3, 0, py, TRUE);//プレイヤーの描画

    //プレイヤーの当たり判定を描画
    DrawCircle(mx, my, 20, GetColor(255, 0, 0), TRUE);
    DrawFormatString(0, 100, GetColor(0, 0, 0), "計算時間%dミリ秒", count);//文字列表示

    //敵の当たり判定を描画
    
    

   
        if (count % 60 == 0)
        {   
            enemy.ex[i] = GetRand(640);
            enemy.ey[i] = GetRand(480);     
            i++;
        }

        DrawCircle(enemy.ex[0], enemy.ey[0], 20, GetColor(0, 0, 255), TRUE);
        DrawCircle(enemy.ex[1], enemy.ey[1], 20, GetColor(0, 0, 255), TRUE);
        DrawFormatString(400, 380, GetColor(0, 0, 0), "\%d", enemy.ex[0]);
        DrawFormatString(400, 400, GetColor(0, 0, 0), "\%d", enemy.ex[1]);

    

    //for (int i = 0; i < 3; i++) {
    //    DrawCircle(ex + i * 20, ey, 20, GetColor(0, 0, 255), TRUE);//敵

    //}

    DrawFormatString(400, 280, GetColor(0, 0, 0), "PlayerのHP%d",HP);//文字列表示
    DrawFormatString(400, 300, GetColor(0, 0, 0), "EnemyのHP % d", enemy.eHP);//文字列表示
    DrawFormatString(mx, my, GetColor(0, 0, 0), "Player");//文字列表示
    DrawFormatString(enemy.ex[0], enemy.ey[0], GetColor(0, 0, 0), "Enemy");//文字列表示
}

//終了処理
void Game_Finalize() {
    DeleteGraph(mImageHandle);    //画像の解放
}
