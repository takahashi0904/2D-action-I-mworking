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
    //�G�l�~�[
    
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

static int mImageHandle;    //�摜�n���h���i�[�p�ϐ�
static int py;

//�v���C���[
static int mx = 0;
static int my = 0;
static int HP = 0;

static int bg;
int bgx = 0;
int bgy = 0;


//�����蔻��
static float lenght = 0;
static float lenght_x = 0;
static float lenght_y = 0;

//�G�l�~�[
//int E[10];
//int EnemyNum = 1;
//int ex;
//int ey;
//int eHP;

int i = 0;
bool A = false;

//������
void Game_Initialize() {
    mImageHandle = LoadGraph("images/Scene_Game.png");    //�摜�̃��[�h
    py = LoadGraph("�摜/Player.png");
    bg = LoadGraph("�摜/�w�i1.png");

    //�����̈ʒu������

    SRand(123456); // �����̏����l��123456�ɐݒ肷��

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

    //�G�̈ʒu��������
    /*ex = 300;
    ey = 200;
    eHP = 1000;*/
}

//�X�V
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

    //�ړ�
    if (CheckHitKey(KEY_INPUT_W) == 1) {//��
        bgy += 1;
        enemy.ey[0] += 3;
    }
    if (CheckHitKey(KEY_INPUT_S) == 1) {//��
        bgy -= 1;
        enemy.ey[0] -= 3;
    }
    if (CheckHitKey(KEY_INPUT_D) == 1) {//�E
        bgx -= 1;
        enemy.ex[0] -= 3;
    }
    if (CheckHitKey(KEY_INPUT_A) == 1) {//��
        bgx += 1;
        enemy.ex[0] += 3;
    }
    //

    //�G�l�~�[�̌v�Z
    
    //��̖ڂ�HP���P�ȏゾ������
    if (enemy.eHP > 0) {
        //�G������Ă���
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
        //��̖ڂ̓����蔻��
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

    if (CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_title);//�V�[�������j���[�ɕύX
    }

    //�����蔻��̌v�Z�v���O������ł����߂���������
    //Palayer�ƓG�̓����蔻��

    if (HP <= 0) {
        SceneMgr_ChangeScene(eScene_Over);
    }

    if (enemy.eHP <= 0) {
        SceneMgr_ChangeScene(eScene_Clear);
    }
}

//�`��
void Game_Draw() {
    DrawRotaGraph(bgx, bgy, 10, 0, bg, TRUE);//�v���C���[�̕`��
    DrawString(0, 0, "�Q�[����ʂł��B", GetColor(0, 0, 0));
    DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(0, 0, 0));
    DrawRotaGraph(mx, my, 3, 0, py, TRUE);//�v���C���[�̕`��

    //�v���C���[�̓����蔻���`��
    DrawCircle(mx, my, 20, GetColor(255, 0, 0), TRUE);
    DrawFormatString(0, 100, GetColor(0, 0, 0), "�v�Z����%d�~���b", count);//������\��

    //�G�̓����蔻���`��
    
    

   
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
    //    DrawCircle(ex + i * 20, ey, 20, GetColor(0, 0, 255), TRUE);//�G

    //}

    DrawFormatString(400, 280, GetColor(0, 0, 0), "Player��HP%d",HP);//������\��
    DrawFormatString(400, 300, GetColor(0, 0, 0), "Enemy��HP % d", enemy.eHP);//������\��
    DrawFormatString(mx, my, GetColor(0, 0, 0), "Player");//������\��
    DrawFormatString(enemy.ex[0], enemy.ey[0], GetColor(0, 0, 0), "Enemy");//������\��
}

//�I������
void Game_Finalize() {
    DeleteGraph(mImageHandle);    //�摜�̉��
}
