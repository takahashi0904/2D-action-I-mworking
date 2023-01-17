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

//�G�l�~�[�̔z��
class Enemy {
public:
    //�G�l�~�[
    
    int ex[5];
    int ey[5];
    int eHP[5];
    int ed[5];
 /*   double ex;
    double ey;
    int eHP;*/
};
Enemy enemy;


//�e�̔z��
class Tama{
public:
  
    const int max = 10;
    int x[10];
    int y[10];
    int f;

};
Tama tama;


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

//�e�̓����蔻��
float bullet = 0;
float bullet_x = 0;
float bullet_y = 0;

//�G�ƓG�̓����蔻��
float enemyl = 0;
float enemyl_x = 0;
float enemyl_y = 0;


//�G�l�~�[
//int E[10];
//int EnemyNum = 1;
//int ex;
//int ey;
//int eHP;

int e = 0;
bool A = false;


//������
void Game_Initialize() {
    mImageHandle = LoadGraph("images/Scene_Game.png");    //�摜�̃��[�h
    py = LoadGraph("�摜/Player.png");
    bg = LoadGraph("�摜/�w�i1.png");
   

    //�����̈ʒu������

    SRand(123456); // �����̏����l��123456�ɐݒ肷��

   
    mx = 320;
    my = 240;

    HP = 300;
  
    bgx = 320;
    bgy = 240;

    for (int i = 0; i < 5; i++) {
        tama.x[i] = mx;
        tama.y[i] = my;
        tama.f = 0;
    }

    for (int i = 0; i < 5; i++) {
        enemy.ex[i] = GetRand(640);
        enemy.ey[i] = GetRand(480);
        enemy.eHP[i] = 700;
        enemy.ed[i] = LoadGraph("�摜/enemy.png");
    }

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

   
    for (int i = 0; i < 5; i++) {
        //�ړ�
        if (CheckHitKey(KEY_INPUT_W) == 1) {//��
            bgy += 1;
            enemy.ey[i] += 3;
        }
        if (CheckHitKey(KEY_INPUT_S) == 1) {//��
            bgy -= 1;
            enemy.ey[i] -= 3;
        }
        if (CheckHitKey(KEY_INPUT_D) == 1) {//�E
            bgx -= 1;
            enemy.ex[i] -= 3;
        }
        if (CheckHitKey(KEY_INPUT_A) == 1) {//��
            bgx += 1;
            enemy.ex[i] += 3;
        }
    }

    //�e�̃t���b�O��on�ɂ���
    if (CheckHitKey(KEY_INPUT_RIGHT) == 1) {//�E
        tama.f = 1;
    }

    //�e�̃t���b�O���P�ɂȂ�����
    if (tama.f==1) {
        tama.x[0]+=20;
        tama.f = 0;
    }


    //�G�l�~�[�̌v�Z
    for (int i = 0; i < 5; i++) {
        //��̖ڂ�HP���P�ȏゾ������
        if (enemy.eHP[i] > 0) {

            //�G������Ă���
            if (mx <= enemy.ex[i]) {
                enemy.ex[i]--;
            }
            if (mx >= enemy.ex[i]) {
                enemy.ex[i]++;
            }
            if (my >= enemy.ey[i]) {
                enemy.ey[i]++;
            }
            if (my <= enemy.ey[i]) {
                enemy.ey[i]--;
            }

            //Player��Enemy�̓����蔻��
            lenght_x = pow(mx - enemy.ex[i], 2);
            lenght_y = pow(my - enemy.ey[i], 2);
            lenght = sqrt(lenght_x + lenght_y);
            if ((20 + 20) >= lenght) {
                HP -= 1;
                enemy.eHP[i] -= 1;
            }

            
            enemyl_x = pow(enemy.ex[i] - enemy.ex[i], 2);
            enemyl_y = pow(enemy.ey[i] - enemy.ey[i], 2);
            enemyl = sqrt(enemyl_x + enemyl_y);
            if ((20 + 20) >= enemyl) {
                //enemy.ex[i]--;
                enemy.ex[i]++;
                //enemy.ey[i]++;
                enemy.ey[i]--;
                       
            }


            //�e�ƓG�̓����蔻��
            bullet_x = pow(tama.x[i] - enemy.ex[i], 2);
            bullet_y = pow(tama.y[i] - enemy.ey[i], 2);
            bullet = sqrt(bullet_x + bullet_y);
            if ((10 + 20) >= bullet) {
                enemy.eHP[i] -= 1;
            }
        }
    }
  

    /*for (int i = 0; i < GetRand(4); i++) {
        enemy.ex[i + 1] = GetRand(640);
        enemy.ey[i + 1] = GetRand(480);
        DrawCircle(enemy.ex[i], enemy.ey[i], 20, GetColor(0, 0, 255), TRUE);
        break;
    }*/

    if(CheckHitKey(KEY_INPUT_ESCAPE) != 0) { //Esc�L�[��������Ă�����
        SceneMgr_ChangeScene(eScene_title);//�V�[�������j���[�ɕύX
    }

    //�����蔻��̌v�Z�v���O������ł����߂���������
    //Palayer�ƓG�̓����蔻��

    //�̗͂��O�ɂȂ�����Q�[���I�[�o�[
    if (HP <= 0) {
        SceneMgr_ChangeScene(eScene_Over);
    }

    //�Q�[���N���A
   /* if (enemy.eHP[0] <= 0) {
        SceneMgr_ChangeScene(eScene_Clear);
    }*/
}

//�`��
void Game_Draw() {

    DrawRotaGraph(bgx, bgy, 10, 0, bg, TRUE);//�v���C���[�̕`��
    DrawString(0, 0, "�Q�[����ʂł��B", GetColor(0, 0, 0));
    DrawString(0, 20, "Esc�L�[�������ƃ��j���[��ʂɖ߂�܂��B", GetColor(0, 0, 0));
    DrawRotaGraph(mx, my, 3, 0, py, TRUE);//�v���C���[�̕`��

    //�v���C���[�̓����蔻���`��
    DrawCircle(mx, my, 20, GetColor(255, 0, 0), TRUE);
    DrawFormatString(mx, my, GetColor(0, 0, 0), "Player");//������\��
    DrawFormatString(0, 100, GetColor(0, 0, 0), "�v�Z����%d�~���b", count);//������\��


    ////�G�̓����蔻���`��
    //if (count % 60 == 0)
    //{
    //    enemy.ex[e] = GetRand(640);
    //    enemy.ey[e] = GetRand(480);
    //    e++;
    //}

    //�G�̕\��
    //�G�̗̑͂�����Ƃ��`��
    for (int i = 0; i < 5; i++) {
        if (enemy.eHP[i] > 0) {
            DrawCircle(enemy.ex[i], enemy.ey[i], 20, GetColor(0, 0, 255), TRUE);
            DrawFormatString(enemy.ex[i], enemy.ey[i], GetColor(0, 0, 0), "Enemy");//������\��
        }
    }
   
    DrawFormatString(400, 380, GetColor(0, 0, 0), "z\%d", enemy.ex[0]);
    DrawFormatString(400, 400, GetColor(0, 0, 0), "\%d", enemy.ey[0]);

    //�e�̕`��
    DrawCircle(tama.x[0], tama.y[0], 10, GetColor(0, 255, 255), TRUE);


    //for (int i = 0; i < 3; i++) {
    //    DrawCircle(ex + i * 20, ey, 20, GetColor(0, 0, 255), TRUE);//�G
    //}

    DrawFormatString(400, 280, GetColor(0, 0, 0), "Player��HP%d",HP);//������\��
    DrawFormatString(400, 300, GetColor(0, 0, 0), "Enemy��HP % d", enemy.eHP[0]);//������\��
}

//�I������
void Game_Finalize() {
    DeleteGraph(mImageHandle);    //�摜�̉��
}
